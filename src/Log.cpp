#include "Log.h"
#include "Helper.h"
#include <windows.h>
#include <wtypesbase.h>

Log::Log()
    : m_programInfo(L""), m_consoleWidth(0), m_consoleHeight(0),
      m_programHeight(0), m_controlHeight(8), m_logHeight(0) {
  SetConsoleOutputCP(65001);
  m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  updateConsoleSize();
  clearConsole();
}

Log::Log(const CString &prompt) : Log() { setProgramInfo(prompt); }

void Log::setProgramInfo(const CString &info) {
  m_programInfo = info;
  m_programHeight = Helper::countLines(m_programInfo);
  printWithColor(m_programInfo, {0, 0}, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void Log::setControlInfo(const CString &info) {
  clearLogArea(0, m_programHeight, {m_consoleWidth, m_controlHeight});
  const CString prompt(Helper::ControlInfoTip);
  printWithColor(prompt,
                 {0, static_cast<SHORT>(m_programHeight + m_controlHeight)},
                 FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
  printWithColor(info, {0, m_programHeight},
                 FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE |
                     FOREGROUND_INTENSITY);
}

void Log::debug(const CString &log) const {
  printLog(log, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Log::info(const CString &log) const {
  printLog(log, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void Log::warning(const CString &log) const {
  printLog(log, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void Log::error(const CString &log) const {
  printLog(log, FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void Log::printWithColor(const CString &log, const COORD &coord,
                         WORD color) const {
  // 保存当前的文本属性，以便恢复
  CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  GetConsoleScreenBufferInfo(m_hConsole, &consoleInfo);
  WORD originalAttributes = consoleInfo.wAttributes;

  // 设置文本颜色
  SetConsoleTextAttribute(m_hConsole, color);

  DWORD written;
  SetConsoleCursorPosition(m_hConsole, coord);
  WriteConsole(m_hConsole, log.GetString(), log.GetLength(), &written, NULL);

  // 恢复原来的文本属性
  SetConsoleTextAttribute(m_hConsole, originalAttributes);
}

void Log::printLog(const CString &log, WORD color) const {
  if (m_logHeight == 0) {
    clearLogArea(0, m_programHeight + m_controlHeight,
                 {m_consoleWidth, m_consoleHeight});
    const CString prompt(Helper::LogTip);
    printWithColor(prompt,
                   {0, static_cast<SHORT>(m_programHeight + m_controlHeight)},
                   FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    m_logHeight = 1;
  }
  printWithColor(
      log,
      {0, static_cast<SHORT>(m_programHeight + m_controlHeight + m_logHeight)},
      color);
  if (++m_logHeight + m_programHeight + m_controlHeight > m_consoleHeight) {
    m_logHeight = 0;
  }
}

void Log::clearLogArea(SHORT x, SHORT y, const COORD &dwSize) const {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(m_hConsole, &csbi);
  DWORD written;

  // 如果未提供 dwSize，使用默认的控制台缓冲区大小
  COORD clearSize = (dwSize.X == 0 && dwSize.Y == 0) ? csbi.dwSize : dwSize;

  // 计算要清理的区域大小，不超过控制台缓冲区
  SHORT clearWidth = min(clearSize.X, csbi.dwSize.X);
  SHORT clearHeight = min(clearSize.Y, csbi.dwSize.Y - m_logHeight);

  // 确保不会超出控制台缓冲区范围
  if (y + clearHeight > csbi.dwSize.Y) {
    clearHeight = csbi.dwSize.Y - y;
  }

  // 清理字符
  FillConsoleOutputCharacter(m_hConsole, L' ', clearWidth * clearHeight, {x, y},
                             &written);

  // 清理属性
  FillConsoleOutputAttribute(m_hConsole, csbi.wAttributes,
                             clearWidth * clearHeight, {x, y}, &written);
}

void Log::clearConsole() const {
  clearLogArea(0, 0, {m_consoleWidth, m_consoleHeight});
}

void Log::updateConsoleSize() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  if (GetConsoleScreenBufferInfo(m_hConsole, &csbi)) {
    m_consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left;
    m_consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top - 1;
  } else {
    m_consoleWidth = m_consoleHeight = 0;
  }
}
