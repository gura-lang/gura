//----------------------------------------------------------------------------
// wxLogGui
// extracted from log.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_LogGui: public wxLogGui, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_LogGui *_pObj;
public:
	inline wx_LogGui() : wxLogGui(), _sig(NULL), _pObj(NULL) {}
	~wx_LogGui();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_LogGui *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LogGui::~wx_LogGui()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_LogGui::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLogGui
//----------------------------------------------------------------------------
Gura_DeclareFunction(LogGuiEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_LogGui));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LogGuiEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_LogGui *pEntity = new wx_LogGui();
	Object_wx_LogGui *pObj = Object_wx_LogGui::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_LogGui(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

//----------------------------------------------------------------------------
// Object implementation for wxLogGui
//----------------------------------------------------------------------------
Object_wx_LogGui::~Object_wx_LogGui()
{
}

Object *Object_wx_LogGui::Clone() const
{
	return NULL;
}

String Object_wx_LogGui::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.LogGui:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_LogGui::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(LogGuiEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxLogGui
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogGui)
{
}

Gura_ImplementDescendantCreator(wx_LogGui)
{
	return new Object_wx_LogGui((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
