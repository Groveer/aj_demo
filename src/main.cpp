#include "CAoJia.h"
#include "Helper.h"
#include "Log.h"

using namespace std;

int main() {
  CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
  CString str;
  CAoJia aj(L"ARegJ64.dll", L"AoJia64.dll");
  Log log;
  if (!Helper::fileExists(L"AoJia64.dll") ||
      !Helper::fileExists(L"ARegJ64.dll")) {
    log.error(_T("插件文件丢失，请重新安装或解压！\n"));
    getchar();
    return -1;
  }

  if (aj.hr != S_OK) {
    str.Format(_T("创建对象失败,返回的错误码是: %08X"), aj.hr);
    log.error(str);
    getchar();
    return -1;
  }

  str.AppendFormat(Helper::ProgramInfoTip);
  str.AppendFormat(_T("主程序版本号：%S\n"),  BIN_VERSION);

  CString ajVersion = aj.VerS();
  str.AppendFormat(_T("插件版本号: %s\n"), ajVersion.GetString());

  log.setProgramInfo(str);
  log.debug(_T("开始测试\n"));
  for (int i = 0; i < 30; ++i) {
    log.info(_T("测试信息\n"));
    Sleep(100); // Sleep for 1 second
  }
  CoUninitialize();
  getchar();
  return 0;
}
