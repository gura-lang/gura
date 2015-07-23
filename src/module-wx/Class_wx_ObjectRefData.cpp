//----------------------------------------------------------------------------
// wxObjectRefData
// extracted from object.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ObjectRefData: public wxObjectRefData, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_ObjectRefData *_pObj;
public:
	inline wx_ObjectRefData() : wxObjectRefData(), _pSig(nullptr), _pObj(nullptr) {}
	//inline wx_ObjectRefData() : wxObjectRefData(), _pSig(nullptr), _pObj(nullptr) {}
	~wx_ObjectRefData();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ObjectRefData *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ObjectRefData::~wx_ObjectRefData()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ObjectRefData::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxObjectRefData
//----------------------------------------------------------------------------
Gura_DeclareFunction(ObjectRefDataEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ObjectRefData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ObjectRefDataEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ObjectRefData *pEntity = new wx_ObjectRefData();
	Object_wx_ObjectRefData *pObj = Object_wx_ObjectRefData::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ObjectRefData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(ObjectRefDataEmpty_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ObjectRefData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ObjectRefDataEmpty_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ObjectRefData *pEntity = new wx_ObjectRefData();
	Object_wx_ObjectRefData *pObj = Object_wx_ObjectRefData::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ObjectRefData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_ObjectRefData, GetRefCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ObjectRefData, GetRefCount)
{
	Object_wx_ObjectRefData *pThis = Object_wx_ObjectRefData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetRefCount();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxObjectRefData
//----------------------------------------------------------------------------
Object_wx_ObjectRefData::~Object_wx_ObjectRefData()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	//***************
	//if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_ObjectRefData::Clone() const
{
	return nullptr;
}

String Object_wx_ObjectRefData::ToString(bool exprFlag)
{
	String rtn("<wx.ObjectRefData:");
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
// Class implementation for wxObjectRefData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ObjectRefData)
{
	Gura_AssignFunction(ObjectRefDataEmpty);
	Gura_AssignFunction(ObjectRefDataEmpty_1);
	Gura_AssignMethod(wx_ObjectRefData, GetRefCount);
}

Gura_ImplementDescendantCreator(wx_ObjectRefData)
{
	return new Object_wx_ObjectRefData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
