//=============================================================================
// Common
//=============================================================================
#include "stdafx.h"

namespace Gura {

const char *EXTNAME_Script		= ".gura";
const char *EXTNAME_ScriptWin	= ".guraw";
const char *EXTNAME_Compound	= ".gurc";
const char *EXTNAME_CompoundWin	= ".gurcw";
const char *EXTNAME_BinModule	= ".gurd";

const char *SRCNAME_unknown		= "<unknown>";
const char *SRCNAME_cmdline		= "<cmdline>";
const char *SRCNAME_interactive	= "<interactive>";
const char *SRCNAME_string		= "<string>";
const char *SRCNAME_dumb		= "<dumb>";
const char *SRCNAME_fifo		= "<fifo>";
const char *SRCNAME_memory		= "<memory>";

const int MAX_STACK_LEVEL = 20000;
const size_t InvalidSize = static_cast<size_t>(-1);

const Number Math_PI = 3.14159265358979323846;
const Number Math_E = 2.71828182845904523536;
const Number RoundOffThreshold = 1e-10;

bool IsBigEndian()
{
	long num = 0x12345678;
	return *reinterpret_cast<char *>(&num) == 0x12;
}

}
