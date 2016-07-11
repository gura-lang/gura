//=============================================================================
// Gura module: doxygen
//=============================================================================
#ifndef __GURA_MODULE_DOXYGEN_H__
#define __GURA_MODULE_DOXYGEN_H__
#include <gura.h>
#include "CommandFormat.h"
#include "Elem.h"
#include "Alias.h"
#include "Parser.h"
#include "Configuration.h"
#include "Class_elem.h"
#include "Class_document.h"
#include "Class_configuration.h"
#include "Class_aliases.h"

Gura_BeginModuleHeader(doxygen)

Gura_DeclareUserSymbol(elem);

//-----------------------------------------------------------------------------
// HelpPresenter_doxygen
//-----------------------------------------------------------------------------
class HelpPresenter_doxygen : public HelpPresenter {
public:
	inline HelpPresenter_doxygen() : HelpPresenter("doxygen") {}
	virtual bool DoPresent(Environment &env, const char *title, const Help *pHelp) const;
};

Gura_EndModuleHeader(doxygen)

#endif
