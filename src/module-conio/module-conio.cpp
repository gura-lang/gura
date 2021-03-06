//=============================================================================
// Gura module: conio
//=============================================================================
#include "stdafx.h"

#undef black
#undef blue
#undef green
#undef aqua
#undef cyan
#undef red
#undef purple
#undef magenta
#undef yellow
#undef white
#undef gray

#define Gura_AssignValueOf(v) Gura_AssignValue(v, v)

Gura_BeginModuleBody(conio)

enum {
	K_CTRL_A	= 0x01,
	K_CTRL_B	= 0x02,
	K_CTRL_C	= 0x03,
	K_CTRL_D	= 0x04,
	K_CTRL_E	= 0x05,
	K_CTRL_F	= 0x06,
	K_CTRL_G	= 0x07,
	K_CTRL_H	= 0x08,
	K_CTRL_I	= 0x09,
	K_CTRL_J	= 0x0a,
	K_CTRL_K	= 0x0b,
	K_CTRL_L	= 0x0c,
	K_CTRL_M	= 0x0d,
	K_CTRL_N	= 0x0e,
	K_CTRL_O	= 0x0f,
	K_CTRL_P	= 0x10,
	K_CTRL_Q	= 0x11,
	K_CTRL_R	= 0x12,
	K_CTRL_S	= 0x13,
	K_CTRL_T	= 0x14,
	K_CTRL_U	= 0x15,
	K_CTRL_V	= 0x16,
	K_CTRL_W	= 0x17,
	K_CTRL_X	= 0x18,
	K_CTRL_Y	= 0x19,
	K_CTRL_Z	= 0x1a,
	K_BACKSPACE	= 0x08,
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

void Clear(Environment &env, const Symbol *pSymbol);
void GetWinSize(Environment &env, size_t *pWidth, size_t *pHeight);
void SetColor(Environment &env, const Symbol *pSymbolFg,
			  const Symbol *pSymbolBg, const Expr_Block *pExprBlock);
void MoveTo(Environment &env, int x, int y, const Expr_Block *pExprBlock);
bool CheckKey();
int WaitKey(Environment &env, bool raiseFlag);

bool SymbolToNumber(Signal &sig, const Symbol *pSymbol, int *pNum);

//-----------------------------------------------------------------------------
// Gura module functions: conio
//-----------------------------------------------------------------------------
// conio.clear(region?:symbol):void
Gura_DeclareFunction(clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "region", VTYPE_symbol, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Clears the screen.\n"
		"\n"
		"In default, it clears whole the screen.\n"
		"Argument `region` that takes one of the symbols below\n"
		"would specify the region to be cleared.\n"
		"\n"
		"- `` `line`` .. clears characters in the line where the cursor exists.\n"
		"- `` `left`` .. clears characters on the left side of the cursor.\n"
		"- `` `right`` .. clears characters on the right side of the cursor.\n"
		"- `` `top`` .. clears characters on the above side of the cursor.\n"
		"- `` `bottom`` .. clears characters on the below side of the cursor.\n");
}

Gura_ImplementFunction(clear)
{
	Clear(env, arg.Is_symbol(0)? arg.GetSymbol(0) : nullptr);
	return Value::Nil;
}

// conio.getwinsize()
Gura_DeclareFunction(getwinsize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns the screen size as a list `[width, height]`.");
}

Gura_ImplementFunction(getwinsize)
{
	size_t width, height;
	GetWinSize(env, &width, &height);
	return ReturnValue(env, arg,
		Value::CreateList(env, Value(width), Value(height)));
}

// conio.setcolor(fg:symbol:nil, bg?:symbol):map:void {block?}
Gura_DeclareFunction(setcolor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "fg", VTYPE_symbol, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "bg", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Sets foreground and background color of text by specifying a color symbol.\n"
		"Available color symbols are listed below:\n"
		"\n"
		"- `` `black``\n"
		"- `` `blue``\n"
		"- `` `green``\n"
		"- `` `aqua``\n"
		"- `` `cyan``\n"
		"- `` `red``\n"
		"- `` `purple``\n"
		"- `` `magenta``\n"
		"- `` `yellow``\n"
		"- `` `white``\n"
		"- `` `gray``\n"
		"- `` `bright_blue``\n"
		"- `` `bright_green``\n"
		"- `` `bright_aqua``\n"
		"- `` `bright_cyan``\n"
		"- `` `bright_red``\n"
		"- `` `bright_purple``\n"
		"- `` `bright_magenta``\n"
		"- `` `bright_yellow``\n"
		"- `` `bright_white``\n"
		"\n"
		"If `fg` is set to nil, the foreground color remains unchanged.\n"
		"If `bg` is omitted or set to nil, the background color remains unchanged.\n"
		"\n"
		"If `block` is specified, the color is changed before evaluating the block,\n"
		"and then gets back to what has been set when done.\n");
}

Gura_ImplementFunction(setcolor)
{
	Signal &sig = env.GetSignal();
	const Expr_Block *pExprBlock = arg.GetBlockCooked(env);
	if (sig.IsSignalled()) return Value::Nil;
	SetColor(env, arg.Is_symbol(0)? arg.GetSymbol(0) : nullptr,
			 arg.Is_symbol(1)? arg.GetSymbol(1) : nullptr, pExprBlock);
	return Value::Nil;
}

// conio.moveto(x:number, y:number):map:void {block?}
Gura_DeclareFunction(moveto)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Moves cursor to the specified position.\n"
		"The most top-left position on the screen is represented as `0, 0`.\n"
		"\n"
		"If `block` is specified, the cursor is moved before evaluating the block,\n"
		"and then gets back to where it has been when done.\n");
}

Gura_ImplementFunction(moveto)
{
	const Expr_Block *pExprBlock = arg.GetBlockCooked(env);
	if (env.IsSignalled()) return Value::Nil;
	MoveTo(env, arg.GetInt(0), arg.GetInt(1), pExprBlock);
	return Value::Nil;
}

// conio.waitkey():[raise]
Gura_DeclareFunction(waitkey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(raise));
	AddHelp(
		Gura_Symbol(en),
		"Waits for a keyboard input and returns a character code number associated with the key.\n"
		"\n"
		"If `:raise` attribute is specified, hitting `Ctrl-C` issues a terminating signal\n"
		"that causes the program done.\n"
		"\n"
		"Character code numbers of some of the special keys are defined as below:\n"
		"\n"
		"- `conio.K_BACKSPACE`\n"
		"- `conio.K_TAB`\n"
		"- `conio.K_RETURN`\n"
		"- `conio.K_ESCAPE`\n"
		"- `conio.K_SPACE`\n"
		"- `conio.K_UP`\n"
		"- `conio.K_DOWN`\n"
		"- `conio.K_RIGHT`\n"
		"- `conio.K_LEFT`\n"
		"- `conio.K_INSERT`\n"
		"- `conio.K_HOME`\n"
		"- `conio.K_END`\n"
		"- `conio.K_PAGEUP`\n"
		"- `conio.K_PAGEDOWN`\n"
		"- `conio.K_DELETE`\n");
}

Gura_ImplementFunction(waitkey)
{
	int chRtn = WaitKey(env, arg.IsSet(Gura_Symbol(raise)));
	if (env.IsSignalled()) return Value::Nil;
	return Value(chRtn);
}

// conio.readkey():[raise]
Gura_DeclareFunction(readkey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(raise));
	AddHelp(
		Gura_Symbol(en),
		"Reads a keyboard input and returns a character code number associated with the key\n"
		"without blocking."
		"\n"
		"If `:raise` attribute is specified, hitting `Ctrl-C` issues a terminating signal\n"
		"that causes the program done.\n"
		"\n"
		"Character code numbers of some of the special keys are defined as below:\n"
		"\n"
		"- `conio.K_BACKSPACE`\n"
		"- `conio.K_TAB`\n"
		"- `conio.K_RETURN`\n"
		"- `conio.K_ESCAPE`\n"
		"- `conio.K_SPACE`\n"
		"- `conio.K_UP`\n"
		"- `conio.K_DOWN`\n"
		"- `conio.K_RIGHT`\n"
		"- `conio.K_LEFT`\n"
		"- `conio.K_INSERT`\n"
		"- `conio.K_HOME`\n"
		"- `conio.K_END`\n"
		"- `conio.K_PAGEUP`\n"
		"- `conio.K_PAGEDOWN`\n"
		"- `conio.K_DELETE`\n");
}

Gura_ImplementFunction(readkey)
{
	if (!CheckKey()) return Value::Nil;
	int chRtn = WaitKey(env, arg.IsSet(Gura_Symbol(raise)));
	if (env.IsSignalled()) return Value::Nil;
	return Value(chRtn);
}

#if defined(GURA_ON_MSWIN)
void Clear(Environment &env, const Symbol *pSymbol)
{
	Signal &sig = env.GetSignal();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	::GetConsoleScreenBufferInfo(hConsole, &csbi);
	//const Symbol *pSymbol = arg.Is_symbol(0)? arg.GetSymbol(0) : nullptr;
	COORD coordStart = { 0, 0 };
	COORD coordHome = { 0, 0 };
	DWORD dwConSize = 0;
	if (pSymbol == nullptr) {
		dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	} else if (pSymbol == Gura_Symbol(line_)) {
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
		return;
	}
	do {
		DWORD cCharsWritten;
		::FillConsoleOutputCharacter(hConsole, ' ',
							dwConSize, coordStart, &cCharsWritten);
		::FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
							dwConSize, coordStart, &cCharsWritten );
		::SetConsoleCursorPosition(hConsole, coordHome);
	} while (0);
}

void GetWinSize(Environment &env, size_t *pWidth, size_t *pHeight)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	::GetConsoleScreenBufferInfo(hConsole, &csbi);
	*pWidth = csbi.srWindow.Right + 1 - csbi.srWindow.Left;
	*pHeight = csbi.srWindow.Bottom + 1 - csbi.srWindow.Top;
}

void SetColor(Environment &env, const Symbol *pSymbolFg,
			  const Symbol *pSymbolBg, const Expr_Block *pExprBlock)
{
	Signal &sig = env.GetSignal();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	::GetConsoleScreenBufferInfo(hConsole, &csbi);
	int fg = csbi.wAttributes & 0x000f;
	int bg = (csbi.wAttributes & 0x00f0) >> 4;
	if (pSymbolFg != nullptr && !SymbolToNumber(sig, pSymbolFg, &fg)) {
		return;
	}
	if (pSymbolBg != nullptr && !SymbolToNumber(sig, pSymbolBg, &bg)) {
		return;
	}
	::SetConsoleTextAttribute(hConsole, fg + (bg << 4));
	if (pExprBlock != nullptr) {
		pExprBlock->Exec(env);
		::SetConsoleTextAttribute(hConsole, csbi.wAttributes);
	}
}

void MoveTo(Environment &env, int x, int y, const Expr_Block *pExprBlock)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	::GetConsoleScreenBufferInfo(hConsole, &csbi);
	COORD pos = { x, y };
	::SetConsoleCursorPosition(hConsole, pos);
	if (pExprBlock != nullptr) {
		pExprBlock->Exec(env);
		::SetConsoleCursorPosition(hConsole, csbi.dwCursorPosition);
	}
}

bool CheckKey()
{
	return ::_kbhit() != 0;
}

int WaitKey(Environment &env, bool raiseFlag)
{
	Signal &sig = env.GetSignal();
	//bool raiseFlag = arg.IsSet(Gura_Symbol(raise));
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
				sig.SetSignal(SIGTYPE_Terminate, Value::Nil);
				return 0;
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
	return chRtn;
}

#elif defined(GURA_ON_LINUX) || defined(GURA_ON_DARWIN)
void Clear(Environment &env, const Symbol *pSymbol)
{
	Signal &sig = env.GetSignal();
	//const Symbol *pSymbol = arg.Is_symbol(0)? arg.GetSymbol(0) : nullptr;
	if (pSymbol == nullptr) {
		::printf("\033[2J");
		::printf("\033[H");
	} else if (pSymbol == Gura_Symbol(line_)) {
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
	}
}

void GetWinSize(Environment &env, size_t *pWidth, size_t *pHeight)
{
	struct winsize ws;
	::ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	*pWidth = ws.ws_col, *pHeight = ws.ws_row;
}

StringList g_attrStack;

void SetColor(Environment &env, const Symbol *pSymbolFg,
			  const Symbol *pSymbolBg, const Expr_Block *pExprBlock)
{
	Signal &sig = env.GetSignal();
	int fg = 0, bg = 0;
	String str;
	if (pSymbolFg == nullptr) {
		// nothing to do
	} else if (!SymbolToNumber(sig, pSymbolFg, &fg)) {
		return;
	} else {
		if (fg & 8) {
			str += "1;";
		} else {
			str += "0;";
		}
		str += '3';
		str += ('0' + (fg & 7));
	}
	if (pSymbolBg == nullptr) {
		// nothing to do
	} else if (!SymbolToNumber(sig, pSymbolBg, &bg)) {
		return;
	} else {
		if (!str.empty()) str += ';';
		str += '4';
		str += ('0' + (bg & 7));
	}
	if (!str.empty()) {
		::printf("\033[%sm", str.c_str());
	}
	if (pExprBlock != nullptr) {
		g_attrStack.push_back(str);
		pExprBlock->Exec(env);
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
}

void MoveTo(Environment &env, int x, int y, const Expr_Block *pExprBlock)
{
	//Signal &sig = env.GetSignal();
	if (pExprBlock == nullptr) {
		::printf("\033[%d;%dH", y + 1, x + 1);
	} else {
		::printf("\033[s");
		::printf("\033[%d;%dH", y + 1, x + 1);
		pExprBlock->Exec(env);
		::printf("\033[u");
	}
}

bool CheckKey()
{
	struct timeval tv = { 0L, 0L };
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(0, &fds);
	return ::select(1, &fds, NULL, NULL, &tv) > 0;
}

int WaitKey(Environment &env, bool raiseFlag)
{
	Signal &sig = env.GetSignal();
	//bool raiseFlag = arg.IsSet(Gura_Symbol(raise));
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
			} else if (ch == 0x7f) {
				chRtn = K_BACKSPACE;
				break;
			} else if (raiseFlag && ch == 0x03) {
				sig.SetSignal(SIGTYPE_Terminate, Value::Nil);
				::tcsetattr(STDIN_FILENO, TCSANOW, &termios_org);
				return 0;
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
	return chRtn;
}

#else
#error unsupported platform
#endif

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(clear);
	Gura_AssignFunction(getwinsize);
	Gura_AssignFunction(setcolor);
	Gura_AssignFunction(moveto);
	Gura_AssignFunction(waitkey);
	Gura_AssignFunction(readkey);
	// value assignment
	Gura_AssignValueOf(K_CTRL_A);
	Gura_AssignValueOf(K_CTRL_B);
	Gura_AssignValueOf(K_CTRL_C);
	Gura_AssignValueOf(K_CTRL_D);
	Gura_AssignValueOf(K_CTRL_E);
	Gura_AssignValueOf(K_CTRL_F);
	Gura_AssignValueOf(K_CTRL_G);
	Gura_AssignValueOf(K_CTRL_H);
	Gura_AssignValueOf(K_CTRL_I);
	Gura_AssignValueOf(K_CTRL_J);
	Gura_AssignValueOf(K_CTRL_K);
	Gura_AssignValueOf(K_CTRL_L);
	Gura_AssignValueOf(K_CTRL_M);
	Gura_AssignValueOf(K_CTRL_N);
	Gura_AssignValueOf(K_CTRL_O);
	Gura_AssignValueOf(K_CTRL_P);
	Gura_AssignValueOf(K_CTRL_Q);
	Gura_AssignValueOf(K_CTRL_R);
	Gura_AssignValueOf(K_CTRL_S);
	Gura_AssignValueOf(K_CTRL_T);
	Gura_AssignValueOf(K_CTRL_U);
	Gura_AssignValueOf(K_CTRL_V);
	Gura_AssignValueOf(K_CTRL_W);
	Gura_AssignValueOf(K_CTRL_X);
	Gura_AssignValueOf(K_CTRL_Y);
	Gura_AssignValueOf(K_CTRL_Z);
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
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utility function
//-----------------------------------------------------------------------------
bool SymbolToNumber(Signal &sig, const Symbol *pSymbol, int *pNum)
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
#elif defined(GURA_ON_LINUX) || defined(GURA_ON_DARWIN)
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

Gura_EndModuleBody(conio, conio)

Gura_RegisterModule(conio)
