#ifndef LOG_H
#define LOG_H

#include <atlstr.h>

class Log {
public:
  Log();
  Log(const CString &prompt);

  void setProgramInfo(const CString &prompt);
  void setControlInfo(const CString &prompt);

  void debug(const CString &log) const;

  void info(const CString &log) const;

  void warning(const CString &log) const;

  void error(const CString &log) const;

private:
  static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam,
                                     LPARAM lParam);
  void printWithColor(const CString &log, const COORD &coord, WORD color) const;
  void printLog(const CString &log, WORD color) const;
  void clearLogArea(SHORT x, SHORT y, const COORD &dwSize = {0, 0}) const;
  void clearConsole() const;
  void updateConsoleSize();

  CString m_programInfo;
  mutable SHORT m_consoleWidth;
  mutable SHORT m_consoleHeight;
  mutable SHORT m_programHeight;
  mutable SHORT m_controlHeight;
  mutable SHORT m_logHeight;

  HANDLE m_hConsole;
};

#endif // LOG_H
