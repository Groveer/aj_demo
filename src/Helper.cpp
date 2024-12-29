#include "Helper.h"

#include <filesystem>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

bool Helper::fileExists(const CString &filename) {
  // 获取当前执行文件的路径
  WCHAR path[MAX_PATH];
  DWORD length = GetModuleFileName(NULL, path, MAX_PATH);

  if (length == 0) {
    std::wcerr << L"Failed to get current path." << std::endl;
    return false;
  }

  // 获取当前执行文件的目录
  std::filesystem::path currentPath(path);
  std::filesystem::path targetPath =
      currentPath.parent_path() / std::wstring(filename);

  // 检查目标文件是否存在
  return std::filesystem::exists(targetPath);
}

short Helper::countLines(const CString &str) {
  auto countLinesInRange = [](const CString &s, LONG start, LONG end) -> short {
    short lines = 0;
    for (LONG i = start; i < end; ++i) {
      if (s[i] == L'\n') {
        ++lines;
      }
    }
    return lines;
  };

  const int numThreads = std::thread::hardware_concurrency();
  const LONG length = str.GetLength();
  const LONG chunkSize = length / numThreads;

  std::vector<std::future<short>> futures;
  for (int i = 0; i < numThreads; ++i) {
    LONG start = i * chunkSize;
    LONG end = (i == numThreads - 1) ? length : (i + 1) * chunkSize;
    futures.push_back(std::async(std::launch::async, countLinesInRange,
                                 std::ref(str), start, end));
  }

  short totalLines = 0;
  for (auto &f : futures) {
    totalLines += f.get();
  }

  return totalLines;
}
CString Helper::ProgramInfoTip = _T("信息：\n");
CString Helper::ControlInfoTip = _T("设置：\n");
CString Helper::LogTip = _T("日志：\n");
