//-----------------------------------------------------------------------------
// Gura console module
//-----------------------------------------------------------------------------
#include "Module_console.h"

Gura_BeginModule(console)

bool SymbolToNumber(Signal sig, const Symbol *pSymbol, int *pNum);

//-----------------------------------------------------------------------------
// Gura module functions: console
//-----------------------------------------------------------------------------
// console.clear(region?:symbol):void
Gura_DeclareFunction(clear)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "region", VTYPE_symbol, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "clear screen");
}

// console.setcolor(fg:symbol:nil, bg?:symbol):map:void {block?}
Gura_DeclareFunction(setcolor)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "fg", VTYPE_symbol, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "bg", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "set text color");
}

// console.moveto(x:number, y:number):map:void {block?}
Gura_DeclareFunction(moveto)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "move cursor to specified position");
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
		coordHome = coordStart;
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

Gura_ImplementFunction(setcolor)
{
	int fg = 0, bg = 0;
	String str;
	bool brightFlag = false;
	if (!args.IsSymbol(0)) {
		// nothing to do
	} else if (!SymbolToNumber(sig, args.GetSymbol(0), &fg)) {
		return Value::Null;
	} else {
		if (fg & 8) str += "1;";
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
		pExprBlock->Exec(env, sig);
		::printf("\033[0m");
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
	Gura_AssignFunction(setcolor);
	Gura_AssignFunction(moveto);
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

Gura_EndModule(console, console)

Gura_RegisterModule(console)
