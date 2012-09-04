#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <string>
#include <vector>

namespace Core { namespace StackTrace {

#ifdef _DEBUG
	#define StackLog Stackage lpLocalStackage(TEXT(__FUNCTION__));
	#define FinalErrorM(Message) ErrExit::FinalError(Message,TEXT(__FUNCTION__),TEXT(__FILE__),__LINE__);
	#define Trn(Fn) if(Fn)ErrExit::FinalError(TEXT(#Fn),TEXT(__FUNCTION__),TEXT(__FILE__),__LINE__,GetLastError());
	#define Try(Fn) Trn(!(Fn))
#else
	#define StackLog
	#define FinalErrorM(Message)ErrExit::FinalError(Message,TEXT(__FUNCTION__),TEXT(__FUNCTION__),__LINE__,GetLastError());
	#define Trn(Fn) Fn
	#define Try(Fn) Fn
#endif

typedef std::basic_string<TCHAR> TString;

class Stackage
{
	static std::vector<TCHAR*> vStack;
	static unsigned int Deep;

	public:
	Stackage(TCHAR *Function);
	~Stackage();
	static TString GetString();
};

class ErrExit
{
	ErrExit(){}
	static TString GetLocalTime();
	public:
	static void ClipBoardSetText(const TCHAR *Text);
	static void GetSystemErrText(int MessageID, TCHAR *Buffer, int BufferSize);
	static void FinalError(const TCHAR *FailCall, const TCHAR *Function, const TCHAR *File, const long Line, const DWORD SystemErrorID=0, const TCHAR *ErrorText=0);
};

} }
