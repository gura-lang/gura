//=============================================================================
// Gura module: doxygen
//=============================================================================
#ifndef __GURA_MODULE_DOXYGEN_H__
#define __GURA_MODULE_DOXYGEN_H__
#include <gura.h>
#include "CommandFormat.h"
#include "Parser.h"

Gura_BeginModuleHeader(doxygen)

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
