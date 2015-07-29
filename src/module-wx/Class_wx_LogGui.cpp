//----------------------------------------------------------------------------
// wxLogGui
// extracted from log.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_LogGui: public wxLogGui, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_LogGui *_pObj;
public:
	inline wx_LogGui() : wxLogGui(), _pObj(nullptr) {}
	~wx_LogGui();
	inline void AssocWithGura(Object_wx_LogGui *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LogGui::~wx_LogGui()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_LogGui::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLogGui
//----------------------------------------------------------------------------
Gura_DeclareFunction(LogGuiEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_LogGui));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LogGuiEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wx_LogGui *pEntity = new wx_LogGui();
	Object_wx_LogGui *pObj = Object_wx_LogGui::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_LogGui(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxLogGui
//----------------------------------------------------------------------------
Object_wx_LogGui::~Object_wx_LogGui()
{
}

Object *Object_wx_LogGui::Clone() const
{
	return nullptr;
}

String Object_wx_LogGui::ToString(bool exprFlag)
{
	String rtn("<wx.LogGui:");
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
// Class implementation for wxLogGui
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogGui)
{
	Gura_AssignFunction(LogGuiEmpty);
}

Gura_ImplementDescendantCreator(wx_LogGui)
{
	return new Object_wx_LogGui((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
