//----------------------------------------------------------------------------
// wxObject
// extracted from object.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
wx_Object::~wx_Object()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Object::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxObject
//----------------------------------------------------------------------------
Gura_DeclareFunction(ObjectEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Object));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ObjectEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Object *pEntity = new wx_Object();
	Object_wx_Object *pObj = Object_wx_Object::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Object(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Object)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Object));
	DeclareArg(env, "other", VTYPE_wx_Object, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Object)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxObject *other = Object_wx_Object::GetObject(args, 0)->GetEntity();
	wx_Object *pEntity = new wx_Object(*other);
	Object_wx_Object *pObj = Object_wx_Object::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Object(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(ObjectEmpty_1)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Object));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ObjectEmpty_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Object *pEntity = new wx_Object();
	Object_wx_Object *pObj = Object_wx_Object::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Object(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_Object, Dump)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Object, Dump)
{
#if 0
	Object_wx_Object *pThis = Object_wx_Object::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	Stream & stream = args.GetStream(0);
	pThis->GetEntity()->Dump(stream);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Object, GetClassInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Object, GetClassInfo)
{
	Object_wx_Object *pThis = Object_wx_Object::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxClassInfo *rtn = (wxClassInfo *)pThis->GetEntity()->GetClassInfo();
	return ReturnValue(env, sig, args, Value(new Object_wx_ClassInfo(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Object, GetRefData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Object, GetRefData)
{
	Object_wx_Object *pThis = Object_wx_Object::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxObjectRefData *rtn = (wxObjectRefData *)pThis->GetEntity()->GetRefData();
	return ReturnValue(env, sig, args, Value(new Object_wx_ObjectRefData(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Object, IsKindOf)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "info", VTYPE_wx_ClassInfo, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Object, IsKindOf)
{
	Object_wx_Object *pThis = Object_wx_Object::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxClassInfo *info = Object_wx_ClassInfo::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsKindOf(info);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Object, IsSameAs)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "obj", VTYPE_wx_Object, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Object, IsSameAs)
{
	Object_wx_Object *pThis = Object_wx_Object::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxObject *obj = Object_wx_Object::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsSameAs(*obj);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Object, Ref)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "clone", VTYPE_wx_Object, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, Ref)
{
	Object_wx_Object *pThis = Object_wx_Object::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxObject *clone = Object_wx_Object::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Ref(*clone);
	return Value::Null;
}

Gura_DeclareMethod(wx_Object, SetRefData)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "data", VTYPE_wx_ObjectRefData, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, SetRefData)
{
	Object_wx_Object *pThis = Object_wx_Object::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxObjectRefData *data = Object_wx_ObjectRefData::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetRefData(data);
	return Value::Null;
}

Gura_DeclareMethod(wx_Object, UnRef)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, UnRef)
{
	Object_wx_Object *pThis = Object_wx_Object::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->UnRef();
	return Value::Null;
}

Gura_DeclareMethod(wx_Object, UnShare)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, UnShare)
{
	Object_wx_Object *pThis = Object_wx_Object::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->UnShare();
	return Value::Null;
}

// operator ==
Gura_ImplementBinaryOperator(Eq, wx_Object, any)
{
	if (valueRight.IsInstanceOf(VTYPE_wx_Object)) {
		wxObject *item1 = Object_wx_Object::GetObject(valueLeft)->GetEntity();
		wxObject *item2 = Object_wx_Object::GetObject(valueRight)->GetEntity();
		return item1 == item2;
	}
	return valueLeft.IsInvalid() && valueRight.IsInvalid();
}

// operator !=
Gura_ImplementBinaryOperator(Ne, wx_Object, any)
{
	if (valueRight.IsInstanceOf(VTYPE_wx_Object)) {
		wxObject *item1 = Object_wx_Object::GetObject(valueLeft)->GetEntity();
		wxObject *item2 = Object_wx_Object::GetObject(valueRight)->GetEntity();
		return item1 != item2;
	}
	return !(valueLeft.IsInvalid() && valueRight.IsInvalid());
}

//----------------------------------------------------------------------------
// Object implementation for wxObject
//----------------------------------------------------------------------------
Object_wx_Object::~Object_wx_Object()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_Object::Clone() const
{
	return NULL;
}

String Object_wx_Object::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Object:");
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
// Class implementation for wxObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Object)
{
	Gura_AssignFunction(ObjectEmpty);
	Gura_AssignFunction(Object);
	Gura_AssignFunction(ObjectEmpty_1);
	Gura_AssignBinaryOperator(Eq, wx_Object, any);
	Gura_AssignBinaryOperator(Ne, wx_Object, any);
	Gura_AssignMethod(wx_Object, Dump);
	Gura_AssignMethod(wx_Object, GetClassInfo);
	Gura_AssignMethod(wx_Object, GetRefData);
	Gura_AssignMethod(wx_Object, IsKindOf);
	Gura_AssignMethod(wx_Object, IsSameAs);
	Gura_AssignMethod(wx_Object, Ref);
	Gura_AssignMethod(wx_Object, SetRefData);
	Gura_AssignMethod(wx_Object, UnRef);
	Gura_AssignMethod(wx_Object, UnShare);
}

Gura_ImplementDescendantCreator(wx_Object)
{
	return new Object_wx_Object((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
