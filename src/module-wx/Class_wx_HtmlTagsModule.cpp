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
	//Gura::Signal *_pSig;
	Object_wx_HtmlTagsModule *_pObj;
public:
	//virtual void FillHandlersTable(wxHtmlWinParser *parser);
	~wx_HtmlTagsModule();
	inline void AssocWithGura(Object_wx_HtmlTagsModule *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlTagsModule::~wx_HtmlTagsModule()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlTagsModule::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlTagsModule
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_HtmlTagsModule, FillHandlersTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*parser", VTYPE_wx_HtmlWinParser, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlTagsModule, FillHandlersTable)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlTagsModule *pThis = Object_wx_HtmlTagsModule::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlWinParser **parser = Object_wx_HtmlWinParser::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->FillHandlersTable(**parser);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlTagsModule
//----------------------------------------------------------------------------
Object_wx_HtmlTagsModule::~Object_wx_HtmlTagsModule()
{
}

Object *Object_wx_HtmlTagsModule::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlTagsModule::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlTagsModule:");
	if (GetEntity() == nullptr) {
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
	return new Object_wx_HtmlTagsModule((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
