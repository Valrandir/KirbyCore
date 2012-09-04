#pragma once
#include <time.h>
#include <tchar.h>
#include <sstream>
#include "StackTrace.h"

using namespace std;
using namespace Core::StackTrace;

//Unicode
#ifdef _UNICODE
	typedef wstringstream TStringStream;
	#define CF_T CF_UNICODETEXT
#else
	typedef std::stringstream TStringStream;
	#define CF_T CF_TEXT
#endif

//Definition of Static Members
vector<TCHAR*> Stackage::vStack;
unsigned int Stackage::Deep = 0;

//Constructor
Stackage::Stackage(TCHAR *Function)
{
	vStack.push_back(Function);
	++Deep;
}

//Destructor
Stackage::~Stackage()
{
	vStack.pop_back();
	--Deep;
}

//Return the complete callstack in a continuous string
TString Stackage::GetString()
{
	vector<TCHAR*>::iterator it;
	TString stack;
	TString separator = TEXT(" -> ");

	//Build Stack String
	for(it=vStack.begin(); it!=vStack.end(); ++it)
	{
		stack.append(*it);
		stack.append(separator);
	}

	//Remove last separator
	if(stack.length() >= separator.length())
		stack.erase(stack.end() - separator.length(), stack.end());

	return stack;
}

TString ErrExit::GetLocalTime()
{
	TCHAR Buff[32];
	time_t now;
	tm stm;

	time(&now);
	localtime_s(&stm, &now);
	_tcsftime(Buff, 32, TEXT("%Y.%m.%d %H:%M:%S"), &stm);

	return Buff;
}

void ErrExit::ClipBoardSetText(const TCHAR *Text)
{
	SIZE_T BufferSize;
	HGLOBAL hClipMem;
	TCHAR *TextBuffer;
	StackLog;

	BufferSize = _tcslen(Text) * sizeof(TCHAR) + sizeof(TCHAR);
	hClipMem = GlobalAlloc(GMEM_MOVEABLE, BufferSize);
	TextBuffer = (TCHAR*)GlobalLock(hClipMem);
	memcpy(TextBuffer, Text, BufferSize);
	GlobalUnlock(hClipMem);
	OpenClipboard(HWND_DESKTOP);
	EmptyClipboard();
	SetClipboardData(CF_T, hClipMem);
	CloseClipboard();
}

void ErrExit::GetSystemErrText(int MessageID, TCHAR *Buffer, int BufferSize)
{
	DWORD ret = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, MessageID, LANG_NEUTRAL, Buffer, BufferSize, NULL);
	if(!ret)
		Buffer = NULL;
}

void ErrExit::FinalError(const TCHAR *FailCall, const TCHAR *Function, const TCHAR *File, const long Line, const DWORD SystemErrorID, const TCHAR *ErrorText)
{
	const TCHAR *newl = TEXT("\r\n");
	TCHAR Buffer[MAX_PATH];
	int Response;
	TStringStream msg;

	//General Information
	msg << TEXT("DateTime: ") << GetLocalTime() << newl
	    << TEXT("FailCall: ") << FailCall << newl
	    << TEXT("Function: ") << Function << newl
	    << TEXT("File: ") << File << newl
	    << TEXT("Line: ") << Line << newl << newl;

	//Get Windows LastError Information
	if(SystemErrorID)
	{
		GetSystemErrText(SystemErrorID, Buffer, MAX_PATH);
		msg << TEXT("GetLastError: ") << SystemErrorID << newl
		    << Buffer << newl;
	}
	else if(ErrorText)
	{
		msg << TEXT("ErrorText: ") << newl << ErrorText << newl << newl;
	}

	//Get CallStack
	msg << TEXT("Stack: ") << newl << Stackage::GetString() << newl;

	//Display MessageBox and Copy to Clipboard
	TString info = msg.str();
	msg << newl << TEXT("Copy this information to clipboard?");
	Response = MessageBox(HWND_DESKTOP, msg.str().c_str(), TEXT("Fatal Error"), MB_YESNO | MB_ICONHAND | MB_DEFBUTTON2);
	if(Response == IDYES)
		ClipBoardSetText(info.c_str());

	//Fatal Fail
	ExitProcess(1);
}
