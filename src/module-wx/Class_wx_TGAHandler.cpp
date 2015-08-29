//----------------------------------------------------------------------------
// wxTGAHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TGAHandler: public wxTGAHandler, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_TGAHandler *_pObj;
public:
	~wx_TGAHandler();
	inline void AssocWithGura(Object_wx_TGAHandler *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TGAHandler::~wx_TGAHandler()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TGAHandler::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTGAHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(TGAHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TGAHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TGAHandler)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_TGAHandler *pEntity = new wx_TGAHandler();
	Object_wx_TGAHandler *pObj = Object_wx_TGAHandler::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_TGAHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxTGAHandler
//----------------------------------------------------------------------------
Object_wx_TGAHandler::~Object_wx_TGAHandler()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_TGAHandler::Clone() const
{
	return nullptr;
}

String Object_wx_TGAHandler::ToString(bool exprFlag)
{
	String rtn("<wx.TGAHandler:");
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
// Class implementation for wxTGAHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TGAHandler)
{
	Gura_AssignFunction(TGAHandler);
}

Gura_ImplementDescendantCreator(wx_TGAHandler)
{
	return new Object_wx_TGAHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
