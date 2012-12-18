//----------------------------------------------------------------------------
// wxObject
// extracted from object.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

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
	wx_Object *pEntity = new wx_Object();
	Object_wx_Object *pObj = Object_wx_Object::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Object(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
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
	wxObject *other = Object_wx_Object::GetObject(args, 0)->GetEntity();
	wx_Object *pEntity = new wx_Object(*other);
	Object_wx_Object *pObj = Object_wx_Object::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Object(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(ObjectEmpty_1)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Object));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ObjectEmpty_1)
{
	wx_Object *pEntity = new wx_Object();
	Object_wx_Object *pObj = Object_wx_Object::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Object(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
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
	Object_wx_Object *pSelf = Object_wx_Object::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	Stream & stream = args.GetStream(0);
	pSelf->GetEntity()->Dump(stream);
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
	Object_wx_Object *pSelf = Object_wx_Object::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxClassInfo *rtn = (wxClassInfo *)pSelf->GetEntity()->GetClassInfo();
	return ReturnValue(env, sig, args, Value(new Object_wx_ClassInfo(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Object, GetRefData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Object, GetRefData)
{
	Object_wx_Object *pSelf = Object_wx_Object::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxObjectRefData *rtn = (wxObjectRefData *)pSelf->GetEntity()->GetRefData();
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
	Object_wx_Object *pSelf = Object_wx_Object::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxClassInfo *info = Object_wx_ClassInfo::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->IsKindOf(info);
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
	Object_wx_Object *pSelf = Object_wx_Object::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxObject *obj = Object_wx_Object::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->IsSameAs(*obj);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Object, Ref)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "clone", VTYPE_wx_Object, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, Ref)
{
	Object_wx_Object *pSelf = Object_wx_Object::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxObject *clone = Object_wx_Object::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->Ref(*clone);
	return Value::Null;
}

Gura_DeclareMethod(wx_Object, SetRefData)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "data", VTYPE_wx_ObjectRefData, OCCUR_Once);
}

Gura_ImplementMethod(wx_Object, SetRefData)
{
	Object_wx_Object *pSelf = Object_wx_Object::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxObjectRefData *data = Object_wx_ObjectRefData::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetRefData(data);
	return Value::Null;
}

Gura_DeclareMethod(wx_Object, UnRef)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, UnRef)
{
	Object_wx_Object *pSelf = Object_wx_Object::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->UnRef();
	return Value::Null;
}

Gura_DeclareMethod(wx_Object, UnShare)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Object, UnShare)
{
	Object_wx_Object *pSelf = Object_wx_Object::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->UnShare();
	return Value::Null;
}

Gura_DeclareMethod(wx_Object, __eq__)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "item1", VTYPE_wx_Object, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "item2", VTYPE_wx_Object, OCCUR_Once, FLAG_Nil);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Object, __eq__)
{
	Object_wx_Object *pSelf = Object_wx_Object::GetSelfObj(args);
	if (args.IsValid(0) && args.IsValid(1)) {
		wxObject *item1 = Object_wx_Object::GetObject(args, 0)->GetEntity();
		wxObject *item2 = Object_wx_Object::GetObject(args, 1)->GetEntity();
		return item1 == item2;
	}
	return args.IsInvalid(0) && args.IsInvalid(1);
}

Gura_DeclareMethod(wx_Object, __ne__)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "item1", VTYPE_wx_Object, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "item2", VTYPE_wx_Object, OCCUR_Once, FLAG_Nil);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Object, __ne__)
{
	Object_wx_Object *pSelf = Object_wx_Object::GetSelfObj(args);
	if (args.IsValid(0) && args.IsValid(1)) {
		wxObject *item1 = Object_wx_Object::GetObject(args, 0)->GetEntity();
		wxObject *item2 = Object_wx_Object::GetObject(args, 1)->GetEntity();
		return item1 != item2;
	}
	return !(args.IsInvalid(0) && args.IsInvalid(1));
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

void Object_wx_Object::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(ObjectEmpty);
	Gura_AssignFunction(Object);
	Gura_AssignFunction(ObjectEmpty_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Object)
{
	Gura_AssignMethod(wx_Object, Dump);
	Gura_AssignMethod(wx_Object, GetClassInfo);
	Gura_AssignMethod(wx_Object, GetRefData);
	Gura_AssignMethod(wx_Object, IsKindOf);
	Gura_AssignMethod(wx_Object, IsSameAs);
	Gura_AssignMethod(wx_Object, Ref);
	Gura_AssignMethod(wx_Object, SetRefData);
	Gura_AssignMethod(wx_Object, UnRef);
	Gura_AssignMethod(wx_Object, UnShare);
	Gura_AssignMethod(wx_Object, __eq__);
	Gura_AssignMethod(wx_Object, __ne__);
}

Gura_ImplementDescendantCreator(wx_Object)
{
	return new Object_wx_Object((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
