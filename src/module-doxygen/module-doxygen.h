//=============================================================================
// Gura module: doxygen
//=============================================================================
#ifndef __GURA_MODULE_DOXYGEN_H__
#define __GURA_MODULE_DOXYGEN_H__
#include <gura.h>
#include "CommandFormat.h"
#include "Elem.h"
#include "Alias.h"
#include "Structure.h"
#include "Parser.h"
#include "Document.h"
#include "Configuration.h"
#include "Renderer.h"
#include "Class_elem.h"
#include "Class_structure.h"
#include "Class_document.h"
#include "Class_configuration.h"
#include "Class_aliases.h"
#include "Class_renderer.h"

#define BeginPushbackRegion(var) \
_pushbackBuff[_pushbackLevel++] = var; \
while (_pushbackLevel > 0) { \
var = _pushbackBuff[--_pushbackLevel];

#define EndPushbackRegion() \
}

Gura_BeginModuleHeader(doxygen)

Gura_DeclareUserSymbol(aliases);
Gura_DeclareUserSymbol(elem);
Gura_DeclareUserSymbol(aftermember);

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
inline bool IsCommandMark(char ch)
{
	return ch == '@' || ch == '\\';
}

inline bool IsWordChar(char ch)
{
	return IsAlpha(ch) || IsDigit(ch) || ch == '_';
}

bool IsBlank(const char *str);
const char *SkipBlankLine(const char *str);

Gura_EndModuleHeader(doxygen)

#endif
