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
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Object::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxObject
//----------------------------------------------------------------------------
Gura_DeclareFunction(ObjectEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Object));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ObjectEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Object *pEntity = new wx_Object();
	Object_wx_Object *pObj = Object_wx_Object::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Object(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Object)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Object));
	DeclareArg(env, "other", VTYPE_wx_Object, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Object)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxObject *other = Object_wx_Object::GetObject(arg, 0)->GetEntity();
	wx_Object *pEntity = new wx_Object(*other);
	Object_wx_Object *pObj = Object_wx_Object::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Object(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(ObjectEmpty_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Object));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ObjectEmpty_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Object *pEntity = new wx_Object();
	Object_wx_Object *pObj = Object_wx_Object::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Object(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_Object, Dump)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Object, Dump)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	Stream & stream = arg.GetStream(0);
	pThis->GetEntity()->Dump(stream);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Object, GetClassInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Object, GetClassInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxClassInfo *rtn = (wxClassInfo *)pThis->GetEntity()->GetClassInfo();
	return ReturnValue(env, arg, Value(new Object_wx_ClassInfo(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Object, GetRefData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Object, GetRefData)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxObjectRefData *rtn = (wxObjectRefData *)pThis->GetEntity()->GetRefData();
	return ReturnValue(env, arg, Value(new Object_wx_ObjectRefData(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Object, IsKindOf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "info", VTYPE_wx_ClassInfo, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Object, IsKindOf)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxClassInfo *info = Object_wx_ClassInfo::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsKindOf(info);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Object, IsSameAs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "obj", VTYPE_wx_Object, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Object, IsSameAs)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxObject *obj = Object_wx_Object::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsSameAs(*obj);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Object, Ref)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "clone", VTYPE_wx_Object, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, Ref)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxObject *clone = Object_wx_Object::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->Ref(*clone);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Object, SetRefData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "data", VTYPE_wx_ObjectRefData, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, SetRefData)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxObjectRefData *data = Object_wx_ObjectRefData::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetRefData(data);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Object, UnRef)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, UnRef)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->UnRef();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Object, UnShare)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, UnShare)
{
	Signal &sig = env.GetSignal();
	Object_wx_Object *pThis = Object_wx_Object::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->UnShare();
	return Value::Nil;
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
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_Object::Clone() const
{
	return nullptr;
}

String Object_wx_Object::ToString(bool exprFlag)
{
	String rtn("<wx.Object:");
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
	return new Object_wx_Object((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
