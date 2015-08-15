//----------------------------------------------------------------------------
// wxPathList
// extracted from pathlist.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PathList: public wxPathList, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_PathList *_pObj;
public:
	inline wx_PathList() : wxPathList(), _pObj(nullptr) {}
	inline wx_PathList(const wxArrayString& arr) : wxPathList(arr), _pObj(nullptr) {}
	~wx_PathList();
	inline void AssocWithGura(Object_wx_PathList *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PathList::~wx_PathList()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PathList::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPathList
//----------------------------------------------------------------------------
Gura_DeclareFunction(PathListEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PathList));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PathListEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_PathList *pEntity = new wx_PathList();
	Object_wx_PathList *pObj = Object_wx_PathList::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PathList(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(PathList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PathList));
	DeclareArg(env, "arr", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PathList)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	std::unique_ptr<wxArrayString> arr(CreateArrayString(args.GetList(0)));
	wx_PathList *pEntity = new wx_PathList(*arr);
	Object_wx_PathList *pObj = Object_wx_PathList::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PathList(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_PathList, AddEnvList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "env_variable", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_PathList, AddEnvList)
{
	Signal &sig = env.GetSignal();
	Object_wx_PathList *pThis = Object_wx_PathList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString env_variable = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->AddEnvList(env_variable);
	return Value::Nil;
}

Gura_DeclareMethod(wx_PathList, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PathList, Add)
{
	Signal &sig = env.GetSignal();
	Object_wx_PathList *pThis = Object_wx_PathList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString path = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Add(path);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_PathList, Add_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "arr", VTYPE_string, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_PathList, Add_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PathList *pThis = Object_wx_PathList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	std::unique_ptr<wxArrayString> arr(CreateArrayString(args.GetList(0)));
	pThis->GetEntity()->Add(*arr);
	return Value::Nil;
}

Gura_DeclareMethod(wx_PathList, EnsureFileAccessible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PathList, EnsureFileAccessible)
{
	Signal &sig = env.GetSignal();
	Object_wx_PathList *pThis = Object_wx_PathList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->EnsureFileAccessible(filename);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_PathList, FindAbsoluteValidPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PathList, FindAbsoluteValidPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_PathList *pThis = Object_wx_PathList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString file = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->FindAbsoluteValidPath(file);
	return ReturnValue(env, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_PathList, FindValidPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PathList, FindValidPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_PathList *pThis = Object_wx_PathList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString file = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->FindValidPath(file);
	return ReturnValue(env, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxPathList
//----------------------------------------------------------------------------
Object_wx_PathList::~Object_wx_PathList()
{
}

Object *Object_wx_PathList::Clone() const
{
	return nullptr;
}

String Object_wx_PathList::ToString(bool exprFlag)
{
	String rtn("<wx.PathList:");
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
// Class implementation for wxPathList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PathList)
{
	Gura_AssignFunction(PathListEmpty);
	Gura_AssignFunction(PathList);
	Gura_AssignMethod(wx_PathList, AddEnvList);
	Gura_AssignMethod(wx_PathList, Add);
	Gura_AssignMethod(wx_PathList, Add_1);
	Gura_AssignMethod(wx_PathList, EnsureFileAccessible);
	Gura_AssignMethod(wx_PathList, FindAbsoluteValidPath);
	Gura_AssignMethod(wx_PathList, FindValidPath);
}

Gura_ImplementDescendantCreator(wx_PathList)
{
	return new Object_wx_PathList((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
