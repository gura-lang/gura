//----------------------------------------------------------------------------
// wxSimpleHelpProvider
// extracted from hprovsmp.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SimpleHelpProvider: public wxSimpleHelpProvider, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SimpleHelpProvider *_pObj;
public:
	~wx_SimpleHelpProvider();
	inline void AssocWithGura(Object_wx_SimpleHelpProvider *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SimpleHelpProvider::~wx_SimpleHelpProvider()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SimpleHelpProvider::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSimpleHelpProvider
//----------------------------------------------------------------------------
Gura_DeclareFunction(SimpleHelpProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SimpleHelpProvider));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SimpleHelpProvider)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_SimpleHelpProvider *pEntity = new wx_SimpleHelpProvider();
	Object_wx_SimpleHelpProvider *pObj = Object_wx_SimpleHelpProvider::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SimpleHelpProvider(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxSimpleHelpProvider
//----------------------------------------------------------------------------
Object_wx_SimpleHelpProvider::~Object_wx_SimpleHelpProvider()
{
}

Object *Object_wx_SimpleHelpProvider::Clone() const
{
	return nullptr;
}

String Object_wx_SimpleHelpProvider::ToString(bool exprFlag)
{
	String rtn("<wx.SimpleHelpProvider:");
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
// Class implementation for wxSimpleHelpProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SimpleHelpProvider)
{
	Gura_AssignFunction(SimpleHelpProvider);
}

Gura_ImplementDescendantCreator(wx_SimpleHelpProvider)
{
	return new Object_wx_SimpleHelpProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
