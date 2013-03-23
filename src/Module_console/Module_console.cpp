//-----------------------------------------------------------------------------
// Gura console module
//-----------------------------------------------------------------------------
#include "Module_console.h"

Gura_BeginModule(console)

bool SymbolToNumber(Signal sig, const Symbol *pSymbol, int *pNum);

//-----------------------------------------------------------------------------
// Gura module functions: console
//-----------------------------------------------------------------------------
// console.clear():void
Gura_DeclareFunction(clear)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), "clear screen");
}

// console.setcolor(fg:symbol:nil, bg?:symbol):map {block?}
Gura_DeclareFunction(setcolor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "fg", VTYPE_symbol, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "bg", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "set text color");
}

// console.moveto(x:number, y:number):map {block?}
Gura_DeclareFunction(moveto)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	static const COORD coordScreen = { 0, 0 };
	::GetConsoleScreenBufferInfo(hConsole, &csbi);
	DWORD cCharsWritten;
	DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	::FillConsoleOutputCharacter(hConsole, ' ',
							dwConSize, coordScreen, &cCharsWritten);
	::FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
							dwConSize, coordScreen, &cCharsWritten );
	::SetConsoleCursorPosition(hConsole, coordScreen);
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
	Value value;
	if (args.IsBlockSpecified()) {
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		value = pExprBlock->Exec(env, sig);
		::SetConsoleTextAttribute(hConsole, csbi.wAttributes);
	}
	return value;
}

Gura_ImplementFunction(moveto)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	::GetConsoleScreenBufferInfo(hConsole, &csbi);
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	COORD pos = {x, y};
	::SetConsoleCursorPosition(hConsole, pos);
	Value value;
	if (args.IsBlockSpecified()) {
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		value = pExprBlock->Exec(env, sig);
		::SetConsoleCursorPosition(hConsole, csbi.dwCursorPosition);
	}
	return value;
}

#elif defined(GURA_ON_LINUX)

Gura_ImplementFunction(clear)
{
	::printf("\033[2J");
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
	Value value;
	if (args.IsBlockSpecified()) {
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		value = pExprBlock->Exec(env, sig);
		::printf("\033[0m");
	}
	return value;
}

Gura_ImplementFunction(moveto)
{
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	Value value;
	if (args.IsBlockSpecified()) {
		::printf("\033[s");
		::printf("\033[%d;%dH", y, x);
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		value = pExprBlock->Exec(env, sig);
		::printf("\033[u");
	} else {
		::printf("\033[%d;%dH", y, x);
	}
	return value;
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
