//-----------------------------------------------------------------------------
// Gura conio module
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include "Module_conio.h"
#if defined(GURA_ON_MSWIN)
#include <conio.h>
#elif defined(GURA_ON_LINUX)
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#else
#error unsupported platform
#endif

#define Gura_AssignValueOf(v) Gura_AssignValue(v, v)

Gura_BeginModule(conio)

enum {
	K_BACKSPACE	= 0x7f,
	K_TAB		= 0x09,
	K_RETURN	= 0x0a,
	K_ESCAPE	= 0x1b,
	K_SPACE		= 0x20,
	// special key code
	K_UP		= 0x80,
	K_DOWN,
	K_RIGHT,
	K_LEFT,
	K_INSERT,
	K_HOME,
	K_END,
	K_PAGEUP,
	K_PAGEDOWN,
	K_DELETE,
};

bool SymbolToNumber(Signal sig, const Symbol *pSymbol, int *pNum);

//-----------------------------------------------------------------------------
// Gura module functions: conio
//-----------------------------------------------------------------------------
// conio.clear(region?:symbol):void
Gura_DeclareFunction(clear)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "region", VTYPE_symbol, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "clear screen");
}

// conio.getwinsize()
Gura_DeclareFunction(getwinsize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), "get window size");
}

// conio.setcolor(fg:symbol:nil, bg?:symbol):map:void {block?}
Gura_DeclareFunction(setcolor)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "fg", VTYPE_symbol, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "bg", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "set text color");
}

// conio.moveto(x:number, y:number):map:void {block?}
Gura_DeclareFunction(moveto)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "move cursor to specified position");
}

// conio.waitkey():[raise]
Gura_DeclareFunction(waitkey)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(raise));
	AddHelp(Gura_Symbol(en), "get one character from keyboard");
}

#if defined(GURA_ON_MSWIN)
Gura_ImplementFunction(clear)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	::GetConsoleScreenBufferInfo(hConsole, &csbi);
	const Symbol *pSymbol = args.IsSymbol(0)? args.GetSymbol(0) : NULL;
	COORD coordStart = { 0, 0 };
	COORD coordHome = { 0, 0 };
	DWORD dwConSize = 0;
	if (pSymbol == NULL) {
		dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	} else if (pSymbol == Gura_Symbol(line)) {
		int width = csbi.dwSize.X;
		coordStart = csbi.dwCursorPosition;
		coordStart.X = 0;
		coordHome = csbi.dwCursorPosition;
		dwConSize = width;
	} else if (pSymbol == Gura_Symbol(up)) {
		int height = csbi.dwCursorPosition.Y + 1;
		coordHome = csbi.dwCursorPosition;
		dwConSize = csbi.dwSize.X * height;
	} else if (pSymbol == Gura_Symbol(down)) {
		int height = csbi.dwSize.Y - csbi.dwCursorPosition.Y;
		coordStart = csbi.dwCursorPosition;
		coordStart.X = 0;
		coordHome = csbi.dwCursorPosition;
		dwConSize = csbi.dwSize.X * height;
	} else if (pSymbol == Gura_Symbol(left)) {
		int width = csbi.dwCursorPosition.X + 1;
		coordStart = csbi.dwCursorPosition;
		coordStart.X = 0;
		coordHome = csbi.dwCursorPosition;
		dwConSize = width;
	} else if (pSymbol == Gura_Symbol(right)) {
		int width = csbi.dwSize.X - csbi.dwCursorPosition.X;
		coordStart = csbi.dwCursorPosition;
		coordHome = csbi.dwCursorPosition;
		dwConSize = width;
	} else {
		sig.SetError(ERR_ValueError, "invalid symbol %s", pSymbol->GetName());
		return Value::Null;
	}
	do {
		DWORD cCharsWritten;
		::FillConsoleOutputCharacter(hConsole, ' ',
							dwConSize, coordStart, &cCharsWritten);
		::FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
							dwConSize, coordStart, &cCharsWritten );
		::SetConsoleCursorPosition(hConsole, coordHome);
	} while (0);
	return Value::Null;
}

Gura_ImplementFunction(getwinsize)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	::GetConsoleScreenBufferInfo(hConsole, &csbi);
	return ReturnValue(env, sig, args,
		Value::CreateAsList(env,
				Value(csbi.srWindow.Right + 1 - csbi.srWindow.Left),
				Value(csbi.srWindow.Bottom + 1 - csbi.srWindow.Top)));
}

Gura_ImplementFunction(setcolor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	::GetConsoleScreenBufferInfo(hConsole, &csbi);
	int fg = csbi.wAttributes & 0x000f;
	int bg = (csbi.wAttributes & 0x00f0) >> 4;
	if (args.IsSymbol(0) && !SymbolToNumber(sig, args.GetSymbol(0), &fg)) {
		return Value::Null;
	}
	if (args.IsSymbol(1) && !SymbolToNumber(sig, args.GetSymbol(1), &bg)) {
		return Value::Null;
	}
	::SetConsoleTextAttribute(hConsole, fg + (bg << 4));
	if (args.IsBlockSpecified()) {
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec(env, sig);
		::SetConsoleTextAttribute(hConsole, csbi.wAttributes);
	}
	return Value::Null;
}

Gura_ImplementFunction(moveto)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	::GetConsoleScreenBufferInfo(hConsole, &csbi);
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	COORD pos = { x, y };
	::SetConsoleCursorPosition(hConsole, pos);
	if (args.IsBlockSpecified()) {
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec(env, sig);
		::SetConsoleCursorPosition(hConsole, csbi.dwCursorPosition);
	}
	return Value::Null;
}

Gura_ImplementFunction(waitkey)
{
	bool raiseFlag = args.IsSet(Gura_Symbol(raise));
	int chRtn = 0;
	enum {
		STAT_None, STAT_Special,
	} stat = STAT_None;
	for (;;) {
		int ch = ::_getch();
		//::printf("- %02x\n", ch);
		if (stat == STAT_None) {
			if (ch == 0xe0) {
				stat = STAT_Special;
			} else if (ch == 0x0d) {
				chRtn = K_RETURN;
				break;
			} else if (raiseFlag && ch == 0x03) {
				sig.SetSignal(SIGTYPE_Terminate, Value::Null);
				return Value::Null;
			} else {
				chRtn = ch;
				break;
			}
		} else if (stat == STAT_Special) {
			if (ch == 0x52) {			// E0 52
				chRtn = K_INSERT;
				break;
			} else if (ch == 0x53) {	// E0 53
				chRtn = K_DELETE;
				break;
			} else if (ch == 0x49) {	// E0 49
				chRtn = K_PAGEUP;
				break;
			} else if (ch == 0x51) {	// E0 51
				chRtn = K_PAGEDOWN;
				break;
			} else if (ch == 0x47) {	// E0 47
				chRtn = K_HOME;
				break;
			} else if (ch == 0x4f) {	// E0 4F
				chRtn = K_END;
				break;
			} else if (ch == 0x48) {	// E0 48
				chRtn = K_UP;
				break;
			} else if (ch == 0x50) {	// E0 50
				chRtn = K_DOWN;
				break;
			} else if (ch == 0x4d) {	// E0 4D
				chRtn = K_RIGHT;
				break;
			} else if (ch == 0x4b) {	// E0 4B
				chRtn = K_LEFT;
				break;
			} else {
				chRtn = ch;
				break;
			}
		}
	}
	return Value(chRtn);
}

#elif defined(GURA_ON_LINUX)

Gura_ImplementFunction(clear)
{
	const Symbol *pSymbol = args.IsSymbol(0)? args.GetSymbol(0) : NULL;
	if (pSymbol == NULL) {
		::printf("\033[2J");
		::printf("\033[H");
	} else if (pSymbol == Gura_Symbol(line)) {
		::printf("\033[2K");
	} else if (pSymbol == Gura_Symbol(up)) {
		::printf("\033[D");
		::printf("\033[1J");
	} else if (pSymbol == Gura_Symbol(down)) {
		::printf("\033[J");
	} else if (pSymbol == Gura_Symbol(left)) {
		::printf("\033[1K");
	} else if (pSymbol == Gura_Symbol(right)) {
		::printf("\033[K");
	} else {
		sig.SetError(ERR_ValueError, "invalid symbol %s", pSymbol->GetName());
		return Value::Null;
	}
	return Value::Null;
}

Gura_ImplementFunction(getwinsize)
{
	struct winsize ws;
	::ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	return ReturnValue(env, sig, args,
		Value::CreateAsList(env, Value(ws.ws_col), Value(ws.ws_row)));
}

StringList g_attrStack;

Gura_ImplementFunction(setcolor)
{
	int fg = 0, bg = 0;
	String str;
	if (!args.IsSymbol(0)) {
		// nothing to do
	} else if (!SymbolToNumber(sig, args.GetSymbol(0), &fg)) {
		return Value::Null;
	} else {
		if (fg & 8) {
			str += "1;";
		} else {
			str += "0;";
		}
		str += '3';
		str += ('0' + (fg & 7));
	}
	if (!args.IsSymbol(1)) {
		// nothing to do
	} else if (!SymbolToNumber(sig, args.GetSymbol(1), &bg)) {
		return Value::Null;
	} else {
		if (!str.empty()) str += ';';
		str += '4';
		str += ('0' + (bg & 7));
	}
	if (!str.empty()) {
		::printf("\033[%sm", str.c_str());
	}
	if (args.IsBlockSpecified()) {
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		g_attrStack.push_back(str);
		pExprBlock->Exec(env, sig);
		if (!g_attrStack.empty()) g_attrStack.pop_back();
		if (g_attrStack.empty()) {
			::printf("\033[0m");
		} else {
			::printf("\033[%sm", g_attrStack.back().c_str());
		}
	} else {
		if (!g_attrStack.empty()) g_attrStack.pop_back();
		g_attrStack.push_back(str);
	}
	return Value::Null;
}

Gura_ImplementFunction(moveto)
{
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	if (args.IsBlockSpecified()) {
		::printf("\033[s");
		::printf("\033[%d;%dH", y + 1, x + 1);
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		pExprBlock->Exec(env, sig);
		::printf("\033[u");
	} else {
		::printf("\033[%d;%dH", y + 1, x + 1);
	}
	return Value::Null;
}

Gura_ImplementFunction(waitkey)
{
	bool raiseFlag = args.IsSet(Gura_Symbol(raise));
	struct termios termios_org, termios_new;
	::tcgetattr(STDIN_FILENO, &termios_org);
	termios_new = termios_org;
	termios_new.c_lflag &= ~ICANON;	// cancel canonical mode
	termios_new.c_lflag &= ~ECHO;	// cancel echo
	termios_new.c_lflag &= ~ISIG;	// disable signal
	::tcsetattr(STDIN_FILENO, TCSANOW, &termios_new);
	int chRtn = 0;
	enum {
		STAT_None, STAT_ESC, STAT_LBracket, STAT_O, STAT_SkipChar,
	} stat = STAT_None;
	for (;;) {
		int ch = ::getchar();
		//::printf("- %02x\n", ch);
		if (stat == STAT_None) {
			if (ch == 0x1b) {
				stat = STAT_ESC;
			} else if (raiseFlag && ch == 0x03) {
				sig.SetSignal(SIGTYPE_Terminate, Value::Null);
				::tcsetattr(STDIN_FILENO, TCSANOW, &termios_org);
				return Value::Null;
			} else {
				chRtn = ch;
				break;
			}
		} else if (stat == STAT_ESC) {
			if (ch == '[') {
				stat = STAT_LBracket;
			} else if (ch == 'O') {
				stat = STAT_O;
			} else {
				chRtn = ch;
				break;
			}
		} else if (stat == STAT_LBracket) {
			if (ch == '1') {			// ESC [1
				chRtn = K_HOME;
				stat = STAT_SkipChar;
			} else if (ch == '2') {		// ESC [2
				chRtn = K_INSERT;
				stat = STAT_SkipChar;
			} else if (ch == '3') {		// ESC [3
				chRtn = K_DELETE;
				stat = STAT_SkipChar;
			} else if (ch == '4') {		// ESC [4
				chRtn = K_END;
				stat = STAT_SkipChar;
			} else if (ch == '5') {		// ESC [5
				chRtn = K_PAGEUP;
				stat = STAT_SkipChar;
			} else if (ch == '6') {		// ESC [6
				chRtn = K_PAGEDOWN;
				stat = STAT_SkipChar;
			} else if (ch == 'A') {		// ESC [A
				chRtn = K_UP;
				break;
			} else if (ch == 'B') {		// ESC [B 
				chRtn = K_DOWN;
				break;
			} else if (ch == 'C') {		// ESC [C
				chRtn = K_RIGHT;
				break;
			} else if (ch == 'D') {		// ESC [D
				chRtn = K_LEFT;
				break;
			} else {
				chRtn = ch;
				break;
			}
		} else if (stat == STAT_O) {
			if (ch == 'F') {			// ESC OF
				chRtn = K_END;
				break;
			} else if (ch == 'H') {		// ESC OH
				chRtn = K_HOME;
				break;
			} else {
				chRtn = ch;
				break;
			}
		} else if (stat == STAT_SkipChar) {
			break;
		}
	}
	::tcsetattr(STDIN_FILENO, TCSANOW, &termios_org);
	return Value(chRtn);
}

#else
#error unsupported platform
#endif

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(clear);
	Gura_AssignFunction(getwinsize);
	Gura_AssignFunction(setcolor);
	Gura_AssignFunction(moveto);
	Gura_AssignFunction(waitkey);
	// value assignment
	Gura_AssignValueOf(K_BACKSPACE);
	Gura_AssignValueOf(K_TAB);
	Gura_AssignValueOf(K_RETURN);
	Gura_AssignValueOf(K_ESCAPE);
	Gura_AssignValueOf(K_SPACE);
	Gura_AssignValueOf(K_UP);
	Gura_AssignValueOf(K_DOWN);
	Gura_AssignValueOf(K_RIGHT);
	Gura_AssignValueOf(K_LEFT);
	Gura_AssignValueOf(K_INSERT);
	Gura_AssignValueOf(K_HOME);
	Gura_AssignValueOf(K_END);
	Gura_AssignValueOf(K_PAGEUP);
	Gura_AssignValueOf(K_PAGEDOWN);
	Gura_AssignValueOf(K_DELETE);
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utility function
//-----------------------------------------------------------------------------
bool SymbolToNumber(Signal sig, const Symbol *pSymbol, int *pNum)
{
#if defined(GURA_ON_MSWIN)
	int num =
		(pSymbol == Gura_Symbol(black))?			0 :
		(pSymbol == Gura_Symbol(blue))?				1 :
		(pSymbol == Gura_Symbol(green))?			2 :
		(pSymbol == Gura_Symbol(aqua))?				3 :
		(pSymbol == Gura_Symbol(cyan))?				3 :
		(pSymbol == Gura_Symbol(red))?				4 :
		(pSymbol == Gura_Symbol(purple))?			5 :
		(pSymbol == Gura_Symbol(magenta))?			5 :
		(pSymbol == Gura_Symbol(yellow))?			6 :
		(pSymbol == Gura_Symbol(white))?			7 :
		(pSymbol == Gura_Symbol(gray))?				8 :
		(pSymbol == Gura_Symbol(bright_blue))?		9 :
		(pSymbol == Gura_Symbol(bright_green))?		10 :
		(pSymbol == Gura_Symbol(bright_aqua))?		11 :
		(pSymbol == Gura_Symbol(bright_cyan))?		11 :
		(pSymbol == Gura_Symbol(bright_red))?		12 :
		(pSymbol == Gura_Symbol(bright_purple))?	13 :
		(pSymbol == Gura_Symbol(bright_magenta))?	13 :
		(pSymbol == Gura_Symbol(bright_yellow))?	14 :
		(pSymbol == Gura_Symbol(bright_white))?		15 : -1;
#elif defined(GURA_ON_LINUX)
	int num =
		(pSymbol == Gura_Symbol(black))?			0 :
		(pSymbol == Gura_Symbol(red))?				1 :
		(pSymbol == Gura_Symbol(green))?			2 :
		(pSymbol == Gura_Symbol(yellow))?			3 :
		(pSymbol == Gura_Symbol(blue))?				4 :
		(pSymbol == Gura_Symbol(purple))?			5 :
		(pSymbol == Gura_Symbol(magenta))?			5 :
		(pSymbol == Gura_Symbol(aqua))?				6 :
		(pSymbol == Gura_Symbol(cyan))?				6 :
		(pSymbol == Gura_Symbol(white))?			7 :
		(pSymbol == Gura_Symbol(gray))?				8 :
		(pSymbol == Gura_Symbol(bright_red))?		9 :
		(pSymbol == Gura_Symbol(bright_green))?		10 :
		(pSymbol == Gura_Symbol(bright_yellow))?	11 :
		(pSymbol == Gura_Symbol(bright_blue))?		12 :
		(pSymbol == Gura_Symbol(bright_purple))?	13 :
		(pSymbol == Gura_Symbol(bright_magenta))?	13 :
		(pSymbol == Gura_Symbol(bright_aqua))?		14 :
		(pSymbol == Gura_Symbol(bright_cyan))?		14 :
		(pSymbol == Gura_Symbol(bright_white))?		15 : -1;
#else
#error unsupported platform
#endif
	if (num < 0) {
		sig.SetError(ERR_ValueError, "invalid symbol for color: %s", pSymbol->GetName());
		return false;
	}
	*pNum = num;
	return true;
}

Gura_EndModule(conio, conio)

Gura_RegisterModule(conio)
