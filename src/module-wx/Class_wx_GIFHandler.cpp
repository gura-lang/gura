//----------------------------------------------------------------------------
// wxGIFHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GIFHandler: public wxGIFHandler, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_GIFHandler *_pObj;
public:
	~wx_GIFHandler();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GIFHandler *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GIFHandler::~wx_GIFHandler()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GIFHandler::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGIFHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(GIFHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GIFHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GIFHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GIFHandler *pEntity = new wx_GIFHandler();
	Object_wx_GIFHandler *pObj = Object_wx_GIFHandler::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GIFHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxGIFHandler
//----------------------------------------------------------------------------
Object_wx_GIFHandler::~Object_wx_GIFHandler()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_GIFHandler::Clone() const
{
	return nullptr;
}

String Object_wx_GIFHandler::ToString(bool exprFlag)
{
	String rtn("<wx.GIFHandler:");
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
// Class implementation for wxGIFHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GIFHandler)
{
	Gura_AssignFunction(GIFHandler);
}

Gura_ImplementDescendantCreator(wx_GIFHandler)
{
	return new Object_wx_GIFHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
