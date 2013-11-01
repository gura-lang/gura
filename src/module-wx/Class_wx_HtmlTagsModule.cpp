//----------------------------------------------------------------------------
// wxHtmlTagsModule
// extracted from httagmod.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(FillHandlersTable);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlTagsModule: public wxHtmlTagsModule, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HtmlTagsModule *_pObj;
public:
	//virtual void FillHandlersTable(wxHtmlWinParser *parser);
	~wx_HtmlTagsModule();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlTagsModule *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlTagsModule::~wx_HtmlTagsModule()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HtmlTagsModule::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlTagsModule
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_HtmlTagsModule, FillHandlersTable)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*parser", VTYPE_wx_HtmlWinParser, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlTagsModule, FillHandlersTable)
{
#if 0
	Object_wx_HtmlTagsModule *pThis = Object_wx_HtmlTagsModule::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxHtmlWinParser **parser = Object_wx_HtmlWinParser::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->FillHandlersTable(**parser);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlTagsModule
//----------------------------------------------------------------------------
Object_wx_HtmlTagsModule::~Object_wx_HtmlTagsModule()
{
}

Object *Object_wx_HtmlTagsModule::Clone() const
{
	return NULL;
}

String Object_wx_HtmlTagsModule::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlTagsModule:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlTagsModule
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlTagsModule)
{
	Gura_RealizeUserSymbol(FillHandlersTable);
	Gura_AssignMethod(wx_HtmlTagsModule, FillHandlersTable);
}

Gura_ImplementDescendantCreator(wx_HtmlTagsModule)
{
	return new Object_wx_HtmlTagsModule((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
