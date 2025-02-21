﻿#pragma once
#ifdef _DLL
#ifndef _AFXDLL
#define _AFXDLL
#endif
#endif
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <oleauto.h>
#include <atlstr.h>
#include <SDKDDKVer.h>

typedef LONG(WINAPI *fnSetDllPathW)(LPCWSTR DllPath, LONG Type);

class CARegJ {
public:
  static fnSetDllPathW pfnSetDllPathW;
  static LONG SetDllPathW(LPCWSTR ARegJPath, LPCWSTR AoJiaPath);
};

class CAoJia {
public:
  CAoJia();
  CAoJia(LPCWSTR ARegJPath, LPCWSTR AoJiaPath);
  ~CAoJia();
  HRESULT hr;
  IDispatch *pIDispatch;
  const CLSID clsid = {0x4f27e588,
                       0x5b1e,
                       0x45b4,
                       {0xad, 0x67, 0xe3, 0x2d, 0x45, 0xc4, 0xe9, 0xca}};
  HRESULT Call(LPCWSTR FunName, DISPID *rgdispid, DISPPARAMS *pDispParams,
               VARIANT *pvarResult);
  CString VerS();
  LONG SetPath(LPCWSTR Path);
  LONG SetErrorMsg(LONG Msg);
  LONG SetThread(LONG TN);
  CString GetModulePath(LONG PID, LONG Hwnd, LPCWSTR MN, LONG Type);
  CString GetMachineCode();
  LONG GetOs(CString &SV, CString &SVN, LONG &LVBN, CString &SDir, LONG Type);
  LONG FindWindow(LONG Parent, LPCWSTR ProName, LONG ProID, LPCWSTR Class,
                  LPCWSTR Title, LONG Type, LONG T);
  LONG CreateWindows(LONG x, LONG y, LONG Width, LONG Height, LONG EWidth,
                     LONG EHeight, LONG Type);
  LONG DeleteFolder(LPCWSTR FN);
  LONGLONG GetRemoteProcAddress(LONG PID, LONG Hwnd, LPCWSTR MN, LPCWSTR Func);
  LONG ClientToScreen(LONG Hwnd, LONG &x, LONG &y);
  LONG ClientOrScreen(LONG Hwnd, LONG xz, LONG yz, LONG &x, LONG &y, LONG Type);
  LONG CompressFile(LPCWSTR SF, LPCWSTR DF, LONG Type, LONG Level);
  LONG UnCompressFile(LPCWSTR SF, LPCWSTR DF, LONG Type);
  LONG SetFont(LONG Hwnd, LPCWSTR Name, LONG Size, LONG Weight, LONG Italic,
               LONG Underline, LONG StrikeOut);
  LONG SetTextD(LONG Hwnd, LONG x1, LONG y1, LONG x2, LONG y2, LONG Row,
                LONG Dir);
  LONG DrawTextD(LONG Hwnd, LPCWSTR Text, LPCWSTR Color, LPCWSTR BkColor);
  LONG CreateFolder(LPCWSTR FN);
  CString FindFile(LPCWSTR FN);
  LONG IsFileOrFolder(LPCWSTR FN);
  LONG IsFileOrFolderE(LPCWSTR FN);
  LONG CopyFile(LPCWSTR SF, LPCWSTR DF, LONG Type);
  LONG CopyFolder(LPCWSTR SF, LPCWSTR DF, LONG Type);
  LONG DeleteFile(LPCWSTR FN);
  LONG SetPCData(LONG Type, LPCWSTR PicName);
  LONG SetGlobalDict(LONG GD);
  LONG GetLastError();
  LONG SetPicCache(LONG PicD);
  CString GetPath();
  LONG GetAoJiaID();
  LONG GetAoJiaNum();
  LONG SetExcludeArea(LONG Type, LPCWSTR AreaD);
  LONG SetPicPw(LPCWSTR Pw);
  LONG SetDictPw(LPCWSTR Pw);
  LONG SetDesktopArea(LONG Hwnd, LONG Dx1, LONG Dy1, LONG Dx2, LONG Dy2,
                      LONG Flag, LONG Type);
  CString EnumProcess(LPCWSTR ProName);
  LONG TerminateProcess(LONG PID, LONG Hwnd, LPCWSTR ProName, LONG Type);
  CString GetProcessInfo(LONG PID, LONG Hwnd);
  LONG DisableIME(LONG TID, LONG Type);
  CString EnumThread(LONG PID, LONG Hwnd);
  LONG GetCurrentThreadId();
  LONG TerminateThread(LONG TID);
  LONG GetCurrentProcessId();
  CString GetProcessPath(LONG PID, LONG Type);
  LONG GetPTNum(LONG &PS, LONG &HC, LONG &TC);
  CString GetCommandLine(LONG PID, LONG Hwnd);
  CString EnumModule(LONG PID, LONG Hwnd);
  LONGLONG GetModuleBaseAddr(LONG PID, LONG Hwnd, LPCWSTR MN);
  ULONG GetModuleSize(LONG PID, LONG Hwnd, LPCWSTR MN);
  LONG Is64Process(LONG PID, LONG Hwnd);
  LONG FindWindowEx(LPCWSTR Scdt1, LONG Flag1, LONG Type1, LPCWSTR Scdt2,
                    LONG Flag2, LONG Type2, LPCWSTR Scdt3, LONG Flag3,
                    LONG Type3, LONG Visible, LONG T);
  CString EnumWindow(LONG Parent, LPCWSTR ProName, LONG ProID, LPCWSTR Class,
                     LPCWSTR Title, LONG Type, LONG Flag, LONG T);
  CString EnumWindowEx(LPCWSTR Scdt1, LONG Flag1, LONG Type1, LPCWSTR Scdt2,
                       LONG Flag2, LONG Type2, LPCWSTR Scdt3, LONG Flag3,
                       LONG Type3, LONG Visible, LONG Sort, LONG T);
  CString GetWindowClass(LONG Hwnd);
  CString GetWindowTitle(LONG Hwnd);
  LONG SetWindowTitle(LONG Hwnd, LPCWSTR Title);
  LONG GetClientRect(LONG Hwnd, LONG &x1, LONG &y1, LONG &x2, LONG &y2);
  LONG GetClientSize(LONG Hwnd, LONG &Width, LONG &Height);
  LONG GetWindowRect(LONG Hwnd, LONG &x1, LONG &y1, LONG &x2, LONG &y2,
                     LONG Type);
  LONG GetWindowSize(LONG Hwnd, LONG &Width, LONG &Height);
  LONG ScreenToClient(LONG Hwnd, LONG &x, LONG &y);
  LONG SetClientSize(LONG Hwnd, LONG Width, LONG Height);
  LONG SetWindowSize(LONG Hwnd, LONG Width, LONG Height);
  LONG MoveWindow(LONG Hwnd, LONG x, LONG y);
  LONG GetWindowState(LONG Hwnd, LONG Type);
  LONG SetWindowState(LONG Hwnd, LONG Type);
  LONG GetWindowThreadProcessId(LONG Hwnd, LONG Type);
  CString GetWindowProcessPath(LONG Hwnd, LONG Type);
  LONG SetWindowTransparent(LONG Hwnd, LPCWSTR Color, LONG Tp, LONG Type);
  LONG GetForegroundWindow();
  LONG GetFocus();
  LONG GetWindowFromPoint(LONG x, LONG y);
  LONG GetWindowFromMouse();
  LONG GetWindow(LONG Hwnd, LONG Type);
  LONG CloseWindow(LONG Hwnd);
  LONG FillRect(LONG Hwnd, LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR Color);
  LONG DrawLine(LONG Hwnd, LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR Color,
                LONG Width, LONG Style);
  LONG DrawPic(LONG Hwnd, LONG x, LONG y, LPCWSTR Color, LPCWSTR PicName);
  LONG SetCHwndSize(LONG Hwnd, LONG Width, LONG Height);
  LONG DrawGif(LONG Hwnd, LONG x, LONG y, LPCWSTR PicName, LONG TD, LONG Num);
  LONG StopGif(LONG Hwnd, LONG x, LONG y, LPCWSTR PicName);
  LONG DrawText(LONG Hwnd, LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR Text,
                LPCWSTR Color, LPCWSTR BkColor, LONG Type);
  LONG ClearTextD(LONG Hwnd);
  LONG SetCreateWindows(LONG Type);
  LONG OpenFolder(LPCWSTR Fd);
  LONG MoveFile(LPCWSTR SF, LPCWSTR DF, LONG Type);
  LONG GetFileAttribute(LPCWSTR FN, LONG &RD, LONG &HD);
  LONG SetFileAttribute(LPCWSTR FN, LONG RD, LONG HD);
  LONG GetFileTime(LPCWSTR FN, CString &CT, CString &WT, CString &AT);
  LONG SetFileTime(LPCWSTR FN, LPCWSTR CT, LPCWSTR WT, LPCWSTR AT);
  DOUBLE GetFileSize(LPCWSTR FN, LONG &FSH, LONG &FSL);
  LONG CompareFileTime(LPCWSTR FN, LPCWSTR FND, LONG &CT, LONG &WT, LONG &AT);
  LONG MoveFolder(LPCWSTR SF, LPCWSTR DF, LONG Type);
  LONG ReNameFile(LPCWSTR SF, LPCWSTR DF);
  CString SelectFileOrFolder();
  LONG WriteIni(LPCWSTR FN, LPCWSTR Section, LPCWSTR Key, LPCWSTR Value,
                LPCWSTR Pw);
  CString ReadIni(LPCWSTR FN, LPCWSTR Section, LPCWSTR Key, LPCWSTR Pw);
  LONG DeleteIni(LPCWSTR FN, LPCWSTR Section, LPCWSTR Key, LPCWSTR Pw);
  CString EnumIni(LPCWSTR FN, LPCWSTR Section, LPCWSTR Pw);
  LONG EncryptFile(LPCWSTR FN, LPCWSTR Pw);
  LONG DecryptFile(LPCWSTR FN, LPCWSTR Pw);
  CString ReadFile(LPCWSTR FN, LONG Pos, LONG Flag, LONG Size, LONG Type,
                   LONG TypeD);
  LONG WriteFile(LPCWSTR FN, LPCWSTR Str, LONG Pos, LONG Flag, LONG Size,
                 LONG Type, LONG TypeD);
  LONG CompareFileData(LPCWSTR SN1, LPCWSTR SN2);
  CString DoubleToData(DOUBLE db);
  CString FloatToData(FLOAT fl);
  CString IntToData(LONG i, LONG Type);
  CString Int64ToData(LONGLONG i64, LONG Type);
  CString StringToData(LPCWSTR Str, LONG Type, LONG Flag);
  LONG FreeProcessMemory(LONG PID, LONG Hwnd);
  LONGLONG VirtualAllocEx(LONG PID, LONG Hwnd, LONGLONG Addr, ULONG Size,
                          LONG Type);
  LONG VirtualFreeEx(LONG PID, LONG Hwnd, LONGLONG Addr);
  CString VirtualQueryEx(LONG PID, LONG Hwnd, LONGLONG Addr, LONG &AProtect,
                         LONG &Protect, LONG &State, LONG &Type);
  ULONG VirtualProtectEx(LONG PID, LONG Hwnd, LONGLONG Addr, ULONG Size,
                         LONG Flag, ULONG Protect, LONG &Type);
  CString ReadDataS(LONG PID, LONG Hwnd, LPCWSTR AddrS, LONG Len);
  CString ReadDataL(LONG PID, LONG Hwnd, LONGLONG AddrL, LONG Len);
  LONG WriteDataS(LONG PID, LONG Hwnd, LPCWSTR AddrS, LPCWSTR Data);
  LONG WriteDataL(LONG PID, LONG Hwnd, LONGLONG AddrL, LPCWSTR Data);
  LONGLONG ReadDataSA(LONG PID, LONG Hwnd, LPCWSTR AddrS, LONG Len);
  LONGLONG ReadDataLA(LONG PID, LONG Hwnd, LONGLONG AddrL, LONG Len);
  LONG WriteDataSA(LONG PID, LONG Hwnd, LPCWSTR AddrS, LONGLONG Data, LONG Len);
  LONG WriteDataLA(LONG PID, LONG Hwnd, LONGLONG AddrL, LONGLONG Data,
                   LONG Len);
  DOUBLE ReadDoubleS(LONG PID, LONG Hwnd, LPCWSTR AddrS, LONG &Type);
  DOUBLE ReadDoubleL(LONG PID, LONG Hwnd, LONGLONG AddrL, LONG &Type);
  LONG WriteDoubleS(LONG PID, LONG Hwnd, LPCWSTR AddrS, DOUBLE Db);
  LONG WriteDoubleL(LONG PID, LONG Hwnd, LONGLONG AddrL, DOUBLE Db);
  FLOAT ReadFloatS(LONG PID, LONG Hwnd, LPCWSTR AddrS, LONG &Type);
  FLOAT ReadFloatL(LONG PID, LONG Hwnd, LONGLONG AddrL, LONG &Type);
  LONG WriteFloatS(LONG PID, LONG Hwnd, LPCWSTR AddrS, FLOAT Fl);
  LONG WriteFloatL(LONG PID, LONG Hwnd, LONGLONG AddrL, FLOAT Fl);
  LONGLONG ReadIntS(LONG PID, LONG Hwnd, LPCWSTR AddrS, LONG Flag, LONG &Type);
  LONGLONG ReadIntL(LONG PID, LONG Hwnd, LONGLONG AddrL, LONG Flag, LONG &Type);
  LONG WriteIntS(LONG PID, LONG Hwnd, LPCWSTR AddrS, LONGLONG Ll, LONG Type);
  LONG WriteIntL(LONG PID, LONG Hwnd, LONGLONG AddrL, LONGLONG Ll, LONG Type);
  CString ReadStringS(LONG PID, LONG Hwnd, LPCWSTR AddrS, LONG Len, LONG Flag,
                      LONG &Type);
  CString ReadStringL(LONG PID, LONG Hwnd, LONGLONG AddrL, LONG Len, LONG Flag,
                      LONG &Type);
  LONG WriteStringS(LONG PID, LONG Hwnd, LPCWSTR AddrS, LPCWSTR Str, LONG Type);
  LONG WriteStringL(LONG PID, LONG Hwnd, LONGLONG AddrL, LPCWSTR Str,
                    LONG Type);
  CString FindData(LONG PID, LONG Hwnd, LPCWSTR AddrS, LPCWSTR Data, LONG Step,
                   LONG Type, LONG PN, LONG TN, LPCWSTR FN);
  CString FindDouble(LONG PID, LONG Hwnd, LPCWSTR AddrS, DOUBLE DbMin,
                     DOUBLE DbMax, LONG Step, LONG Type, LONG PN, LONG TN,
                     LPCWSTR FN);
  CString FindFloat(LONG PID, LONG Hwnd, LPCWSTR AddrS, FLOAT FlMin,
                    FLOAT FlMax, LONG Step, LONG Type, LONG PN, LONG TN,
                    LPCWSTR FN);
  CString FindInt(LONG PID, LONG Hwnd, LPCWSTR AddrS, LONGLONG LlMin,
                  LONGLONG LlMax, LONG Flag, LONG Step, LONG Type, LONG PN,
                  LONG TN, LPCWSTR FN);
  CString FindString(LONG PID, LONG Hwnd, LPCWSTR AddrS, LPCWSTR Str, LONG Flag,
                     LONG Nul, LONG Step, LONG Type, LONG PN, LONG TN,
                     LPCWSTR FN);
  LONG SuiJi(LONG RMin, LONG RMax);
  LONG GaiLu(LONG P);
  LONG YanShi(LONG RMin, LONG RMax);
  CString GetClipboard();
  LONG SetClipboard(LPCWSTR Str);
  LONG GetCPU(CString &Type, CString &CPUID);
  LONG GetCPURate();
  LONG SetAero(LONG Type);
  LONG Beep(LONG Hz, LONG T);
  LONG Msg(LONG x, LONG y, LPCWSTR Color, LPCWSTR BkColor, LPCWSTR FmColor,
           LPCWSTR Text, LONG T);
  LONG GetFontSmoothing();
  LONG SetFontSmoothing(LONG Type);
  LONG GetUAC();
  LONG SetUAC(LONG Type);
  LONG GetBeep();
  LONG SetBeep(LONG Type);
  LONG SetPower(LONG VT, LONG ST);
  LONG SetPowerState(LONG Type);
  LONG GetPower(LONG &VT, LONG &ST);
  LONG SetScreenSave(LONG Type);
  LONG ExitOs(LONG Type);
  ULONG GetTime();
  LONG GetScreen(LONG &Width, LONG &Height);
  LONG SetScreen(LONG Width, LONG Height);
  LONG GetMemory(LONG &TPhy, DOUBLE &APhy);
  LONG GetDPI();
  LONG Cmd(LPCWSTR CL, LONG Type);
  CString GetGc();
  CString GetDisk(CString &Model, CString &Revision);
  LONG PlayMusic(LPCWSTR MF);
  LONG StopMusic();
  LONG RunApp(LPCWSTR Path, LONG Type);
  CString SuiJiMZ(LONG MN, LONG Type);
  CString GetSystemTime();
  LONG SetSystemTime(LPCWSTR ST);
  CString GetDiskSize();
  CString GetScreenS(LONG &xS, LONG &yS);
  CString GetMAC();
  LONG KeyDown(USHORT KeyD);
  LONG KeyUp(USHORT KeyD);
  LONG KeyPress(USHORT KeyD);
  LONG KeyDownS(LPCWSTR KeyDS);
  LONG KeyUpS(LPCWSTR KeyDS);
  LONG KeyPressS(LPCWSTR KeyDS);
  LONG KeyPressD(USHORT KeyD, LONG RMin, LONG RMax, LONG RDMin, LONG RDMax);
  LONG KeyPressSD(LPCWSTR KeyDS, LONG RMin, LONG RMax, LONG RDMin, LONG RDMax);
  LONG KeyPressZ(LPCWSTR KeyZ, LONG RMin, LONG RMax);
  LONG GetKeyDState(LONG KeyD);
  LONG WaitKeyD(LONG KeyD, LONG TKeyD);
  LONG LeftDown();
  LONG LeftUp();
  LONG RightDown();
  LONG RightUp();
  LONG MiddleDown();
  LONG MiddleUp();
  LONG WheelDown();
  LONG WheelUp();
  LONG LeftClick();
  LONG RightClick();
  LONG MiddleClick();
  LONG LeftClickD(LONG RMin, LONG RMax, LONG RDMin, LONG RDMax);
  LONG RightClickD(LONG RMin, LONG RMax, LONG RDMin, LONG RDMax);
  LONG MiddleClickD(LONG RMin, LONG RMax, LONG RDMin, LONG RDMax);
  LONG WheelDownD(LONG Num, LONG RMin, LONG RMax, LONG RDMin, LONG RDMax);
  LONG WheelUpD(LONG Num, LONG RMin, LONG RMax, LONG RDMin, LONG RDMax);
  LONG LeftDoubleClick();
  LONG LeftDoubleClickD(LONG RMin, LONG RMax, LONG RDMin, LONG RDMax,
                        LONG RDRMin, LONG RDRMax);
  LONG RightDoubleClickD(LONG RMin, LONG RMax, LONG RDMin, LONG RDMax,
                         LONG RDRMin, LONG RDRMax);
  LONG MiddleDoubleClickD(LONG RMin, LONG RMax, LONG RDMin, LONG RDMax,
                          LONG RDRMin, LONG RDRMax);
  LONG GetDoubleClickTime();
  LONG SetDoubleClickTime(LONG T);
  LONG SetMouseAccuracy(LONG MouseA);
  LONG SetMouseSpeed(LONG MouseS);
  LONG GetMouseSpeed();
  LONG MoveTo(LONG x, LONG y);
  LONG MoveR(LONG Rx, LONG Ry);
  LONG MoveToD(LONG x, LONG y, LONG xRMin, LONG xRMax, LONG yRMin, LONG yRMax,
               LONG RMin, LONG RMax, LONG Speed);
  LONG MoveRD(LONG Rx, LONG Ry, LONG xRMin, LONG xRMax, LONG yRMin, LONG yRMax,
              LONG RMin, LONG RMax, LONG Speed);
  LONG MoveToQ(LONG x, LONG y, LONG xRMin, LONG xRMax, LONG yRMin, LONG yRMax,
               LONG RMin, LONG RMax, LONG Speed);
  LONG MoveRQ(LONG Rx, LONG Ry, LONG xRMin, LONG xRMax, LONG yRMin, LONG yRMax,
              LONG RMin, LONG RMax, LONG Speed);
  LONG GetMousePos(LONG &x, LONG &y, LONG Type);
  LONG SetMousePos(LONG Sx1, LONG Sy1, LONG Sx2, LONG Sy2, LONG SDxy, LONG Dx1,
                   LONG Dy1, LONG Dx2, LONG Dy2, LONG RMin, LONG RMax,
                   LONG Speed, LONG Type);
  LONG GetMouseHotspot(LONG &x, LONG &y, LONG Type);
  CString GetMouseShape(LONG Type, LONG Flag);
  LONG SendString(LONG Hwnd, LPCWSTR Str, LONG RMin, LONG RMax, LONG Type,
                  LONG Flag);
  LONG BlockInput(LONG Type);
  LONG OpenURL(LPCWSTR URL);
  LONG DownloadFile(LPCWSTR URL, LPCWSTR FN, LONG Type);
  LONG GetDownloadState();
  LONG KQHouTai(LONG Hwnd, LPCWSTR Screen, LPCWSTR Keyboard, LPCWSTR Mouse,
                LPCWSTR Flag, LONG Type);
  LONG GBHouTai();
  LONG SetHwndSKM(LONG HwndS, LONG HwndK, LONG HwndM);
  LONG SetWindowSNA(LONG SNA);
  LONG SetKMSync(LONG Keyboard, ULONG uToK, LONG Mouse, ULONG uToM);
  LONG SetIme(LONG Type);
  LONG SetKMLock(LONG LockK, LONG LockM);
  LONG SetTimeS(ULONG TimeS);
  LONG DownCpu(ULONG DCpuT, LONG DCpuD);
  LONG LockScreen(LONG LockS);
  LONG GetFPS();
  LONG FindShape(LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR ColorP, LONG Dir,
                 DOUBLE SimP, DOUBLE SimD, LONG &x, LONG &y);
  CString FindShapeEx(LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR ColorP,
                      LONG Dir, DOUBLE SimP, DOUBLE SimD);
  CString FindColorSquEx(LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR Color,
                         DOUBLE Sim, DOUBLE SimD, LONG Dir, LONG Width,
                         LONG Height);
  LONG FindColorSqu(LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR Color,
                    DOUBLE Sim, DOUBLE SimD, LONG Dir, LONG Width, LONG Height,
                    LONG &x, LONG &y);
  CString FindPicDEx(LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR PicName,
                     LPCWSTR ColorP, DOUBLE Sim, DOUBLE SimD, LONG Dir,
                     LONG Type, LONG TypeT);
  LONG FindPicD(LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR PicName,
                LPCWSTR ColorP, DOUBLE Sim, DOUBLE SimD, LONG Dir, LONG Type,
                CString &Pic, LONG &x, LONG &y);
  CString FindPicEx(LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR PicName,
                    LPCWSTR ColorP, DOUBLE Sim, LONG Dir, LONG Type,
                    LONG TypeT);
  LONG FindPic(LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR PicName,
               LPCWSTR ColorP, DOUBLE Sim, LONG Dir, LONG Type, CString &Pic,
               LONG &x, LONG &y);
  CString FindMultiColorEx(LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR Color,
                           LPCWSTR ColorP, DOUBLE Sim, LONG Dir, DOUBLE SimP,
                           DOUBLE SimD);
  LONG FindMultiColor(LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR Color,
                      LPCWSTR ColorP, DOUBLE Sim, LONG Dir, DOUBLE SimP,
                      DOUBLE SimD, LONG &x, LONG &y);
  CString FindColorEx(LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR Color,
                      DOUBLE Sim, LONG Dir);
  LONG FindColor(LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR Color, DOUBLE Sim,
                 LONG Dir, LONG &x, LONG &y);
  LONG FindColorM(LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR Color, DOUBLE Sim,
                  LONG Count);
  LONG GetColorNum(LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR Color,
                   DOUBLE Sim);
  VARIANT GetColorAve(LONG x1, LONG y1, LONG x2, LONG y2, LONG Type);
  LONG CmpColor(LONG x, LONG y, LPCWSTR Color, DOUBLE Sim, LONG Type);
  VARIANT GetColor(LONG x, LONG y, LONG Type, LONG TypeD);
  CString BGRorRGB(LPCWSTR Color);
  CString BGRorRGBtoHSV(LPCWSTR Color, LONG Type);
  CString HSVtoBGRorRGB(LPCWSTR Color, LONG Type);
  LONG LoadPic(LPCWSTR PicName);
  LONG FreePic(LPCWSTR PicName);
  LONG IsScreenStuck(LONG x1, LONG y1, LONG x2, LONG y2, LONG T);
  LONG GetPicSize(LPCWSTR PicName, LONG &PicW, LONG &PicH);
  LONG PicToBmp(LPCWSTR PicName, LPCWSTR BmpName);
  LONG ScreenShot(LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR PicName,
                  LONG Type, LONG Quality, ULONG TD, ULONG T, LONG Flag,
                  LONG Mouse);
  LONG LoadDict(LONG DNum, LPCWSTR DName);
  LONG SetDict(LONG DNum);
  CString Ocr(LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR Str, LPCWSTR Color,
              DOUBLE Sim, LONG TypeC, LONG TypeD, LONG TypeR, LONG TypeT,
              LPCWSTR HLine, LPCWSTR PicName);
  LONG FindStr(LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR Str, LPCWSTR Color,
               DOUBLE Sim, LONG Dir, LONG TypeC, LONG TypeD, CString &StrD,
               LONG &x, LONG &y);
  LONG FreeDict(LONG DNum);
  LONG GetDict(LONG GD, LONG DNum, LONG Type);
  LONG SetDictWidth(LONG DW);
  LONG SetDictHeight(LONG DH);
  LONG FindStrM(LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR Str, LPCWSTR Color,
                DOUBLE Sim, LONG TypeC, LONG TypeD, CString &StrD, LONG &x,
                LONG &y);
  CString FindStrMEx(LONG x1, LONG y1, LONG x2, LONG y2, LPCWSTR Str,
                     LPCWSTR Color, DOUBLE Sim, LONG TypeC, LONG TypeD,
                     LPCWSTR HLine);
  LONG SetParam64ToAddr();
};

