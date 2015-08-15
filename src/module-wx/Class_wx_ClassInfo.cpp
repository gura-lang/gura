//----------------------------------------------------------------------------
// wxClassInfo
// extracted from clasinfo.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ClassInfo: public wxClassInfo, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ClassInfo *_pObj;
public:
	//inline wx_ClassInfo(const wxChar * className, const wxClassInfo * baseClass1, const wxClassInfo * baseClass2, int size, wxObjectConstructorFn fn) : wxClassInfo(className, baseClass1, baseClass2, size, fn), _pObj(nullptr) {}
	~wx_ClassInfo();
	inline void AssocWithGura(Object_wx_ClassInfo *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ClassInfo::~wx_ClassInfo()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ClassInfo::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxClassInfo
//----------------------------------------------------------------------------
Gura_DeclareFunction(ClassInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_ClassInfo));
	DeclareArg(env, "className", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "baseClass1", VTYPE_wx_ClassInfo, OCCUR_Once);
	DeclareArg(env, "baseClass2", VTYPE_wx_ClassInfo, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "fn", VTYPE_wx_ObjectConstructorFn, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(ClassInfo)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString className = wxString::FromUTF8(args.GetString(0));
	wxClassInfo *baseClass1 = Object_wx_ClassInfo::GetObject(args, 1)->GetEntity();
	wxClassInfo *baseClass2 = Object_wx_ClassInfo::GetObject(args, 2)->GetEntity();
	int size = args.GetInt(3);
	wxObjectConstructorFn *fn = Object_wx_ObjectConstructorFn::GetObject(args, 4)->GetEntity();
	wx_ClassInfo *pEntity = new wx_ClassInfo(className, baseClass1, baseClass2, size, *fn);
	Object_wx_ClassInfo *pObj = Object_wx_ClassInfo::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ClassInfo(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ClassInfo, CreateObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ClassInfo, CreateObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxObject *rtn = (wxObject *)pThis->GetEntity()->CreateObject();
	return ReturnValue(env, args, Value(new Object_wx_Object(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_ClassInfo, FindClass)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ClassInfo, FindClass)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxClassInfo *rtn = (wxClassInfo *)wxClassInfo::FindClass(name);
	return ReturnValue(env, args, Value(new Object_wx_ClassInfo(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ClassInfo, GetBaseClassName1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ClassInfo, GetBaseClassName1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar rtn = pThis->GetEntity()->GetBaseClassName1();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ClassInfo, GetBaseClassName2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ClassInfo, GetBaseClassName2)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar rtn = pThis->GetEntity()->GetBaseClassName2();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ClassInfo, GetClassName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ClassInfo, GetClassName)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar rtn = pThis->GetEntity()->GetClassName();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ClassInfo, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ClassInfo, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_ClassInfo, InitializeClasses)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_ClassInfo, InitializeClasses)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxClassInfo::InitializeClasses();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ClassInfo, IsDynamic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ClassInfo, IsDynamic)
{
	Signal &sig = env.GetSignal();
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsDynamic();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ClassInfo, IsKindOf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "info", VTYPE_wx_ClassInfo, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ClassInfo, IsKindOf)
{
	Signal &sig = env.GetSignal();
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxClassInfo *info = Object_wx_ClassInfo::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsKindOf(info);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxClassInfo
//----------------------------------------------------------------------------
Object_wx_ClassInfo::~Object_wx_ClassInfo()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_ClassInfo::Clone() const
{
	return nullptr;
}

String Object_wx_ClassInfo::ToString(bool exprFlag)
{
	String rtn("<wx.ClassInfo:");
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
// Class implementation for wxClassInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClassInfo)
{
	Gura_AssignFunction(ClassInfo);
	Gura_AssignMethod(wx_ClassInfo, CreateObject);
	Gura_AssignMethod(wx_ClassInfo, FindClass);
	Gura_AssignMethod(wx_ClassInfo, GetBaseClassName1);
	Gura_AssignMethod(wx_ClassInfo, GetBaseClassName2);
	Gura_AssignMethod(wx_ClassInfo, GetClassName);
	Gura_AssignMethod(wx_ClassInfo, GetSize);
	Gura_AssignMethod(wx_ClassInfo, InitializeClasses);
	Gura_AssignMethod(wx_ClassInfo, IsDynamic);
	Gura_AssignMethod(wx_ClassInfo, IsKindOf);
}

Gura_ImplementDescendantCreator(wx_ClassInfo)
{
	return new Object_wx_ClassInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
