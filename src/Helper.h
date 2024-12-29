#ifndef HELPER_H
#define HELPER_H

#include <atlstr.h>

class Helper {
public:
  static bool fileExists(const CString &filename);
  static short countLines(const CString &str);

  static CString ProgramInfoTip;
  static CString ControlInfoTip;
  static CString LogTip;
};

#endif // HELPER_H
