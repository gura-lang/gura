//----------------------------------------------------------------------------
// wxObjectRefData
// extracted from object.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ObjectRefData: public wxObjectRefData, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ObjectRefData *_pObj;
public:
	inline wx_ObjectRefData() : wxObjectRefData(), _sig(NULL), _pObj(NULL) {}
	//inline wx_ObjectRefData() : wxObjectRefData(), _sig(NULL), _pObj(NULL) {}
	~wx_ObjectRefData();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ObjectRefData *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ObjectRefData::~wx_ObjectRefData()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ObjectRefData::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxObjectRefData
//----------------------------------------------------------------------------
Gura_DeclareFunction(ObjectRefDataEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ObjectRefData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ObjectRefDataEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ObjectRefData *pEntity = new wx_ObjectRefData();
	Object_wx_ObjectRefData *pObj = Object_wx_ObjectRefData::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ObjectRefData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(ObjectRefDataEmpty_1)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ObjectRefData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ObjectRefDataEmpty_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ObjectRefData *pEntity = new wx_ObjectRefData();
	Object_wx_ObjectRefData *pObj = Object_wx_ObjectRefData::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ObjectRefData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_ObjectRefData, GetRefCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ObjectRefData, GetRefCount)
{
	Object_wx_ObjectRefData *pSelf = Object_wx_ObjectRefData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetRefCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxObjectRefData
//----------------------------------------------------------------------------
Object_wx_ObjectRefData::~Object_wx_ObjectRefData()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_ObjectRefData::Clone() const
{
	return NULL;
}

String Object_wx_ObjectRefData::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ObjectRefData:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ObjectRefData::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(ObjectRefDataEmpty);
	Gura_AssignFunction(ObjectRefDataEmpty_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxObjectRefData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ObjectRefData)
{
	Gura_AssignMethod(wx_ObjectRefData, GetRefCount);
}

Gura_ImplementDescendantCreator(wx_ObjectRefData)
{
	return new Object_wx_ObjectRefData((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
