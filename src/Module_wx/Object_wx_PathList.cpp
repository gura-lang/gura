//----------------------------------------------------------------------------
// wxPathList
// extracted from pathlist.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PathList: public wxPathList, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PathList *_pObj;
public:
	inline wx_PathList() : wxPathList(), _sig(NULL), _pObj(NULL) {}
	inline wx_PathList(const wxArrayString& arr) : wxPathList(arr), _sig(NULL), _pObj(NULL) {}
	~wx_PathList();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PathList *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PathList::~wx_PathList()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_PathList::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPathList
//----------------------------------------------------------------------------
Gura_DeclareFunction(PathListEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PathList));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PathListEmpty)
{
	wx_PathList *pEntity = new wx_PathList();
	Object_wx_PathList *pObj = Object_wx_PathList::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PathList(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(PathList)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PathList));
	DeclareArg(env, "arr", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PathList)
{
	std::auto_ptr<wxArrayString> arr(CreateArrayString(args.GetList(0)));
	wx_PathList *pEntity = new wx_PathList(*arr);
	Object_wx_PathList *pObj = Object_wx_PathList::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PathList(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_PathList, AddEnvList)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "env_variable", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_PathList, AddEnvList)
{
	Object_wx_PathList *pSelf = Object_wx_PathList::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString env_variable = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->AddEnvList(env_variable);
	return Value::Null;
}

Gura_DeclareMethod(wx_PathList, Add)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PathList, Add)
{
	Object_wx_PathList *pSelf = Object_wx_PathList::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->Add(path);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PathList, Add_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "arr", VTYPE_string, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_PathList, Add_1)
{
	Object_wx_PathList *pSelf = Object_wx_PathList::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	std::auto_ptr<wxArrayString> arr(CreateArrayString(args.GetList(0)));
	pSelf->GetEntity()->Add(*arr);
	return Value::Null;
}

Gura_DeclareMethod(wx_PathList, EnsureFileAccessible)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PathList, EnsureFileAccessible)
{
	Object_wx_PathList *pSelf = Object_wx_PathList::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->EnsureFileAccessible(filename);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PathList, FindAbsoluteValidPath)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PathList, FindAbsoluteValidPath)
{
	Object_wx_PathList *pSelf = Object_wx_PathList::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString file = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pSelf->GetEntity()->FindAbsoluteValidPath(file);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_PathList, FindValidPath)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PathList, FindValidPath)
{
	Object_wx_PathList *pSelf = Object_wx_PathList::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString file = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pSelf->GetEntity()->FindValidPath(file);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxPathList
//----------------------------------------------------------------------------
Object_wx_PathList::~Object_wx_PathList()
{
}

Object *Object_wx_PathList::Clone() const
{
	return NULL;
}

String Object_wx_PathList::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.PathList:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_PathList::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(PathListEmpty);
	Gura_AssignFunction(PathList);
}

//----------------------------------------------------------------------------
// Class implementation for wxPathList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PathList)
{
	Gura_AssignMethod(wx_PathList, AddEnvList);
	Gura_AssignMethod(wx_PathList, Add);
	Gura_AssignMethod(wx_PathList, Add_1);
	Gura_AssignMethod(wx_PathList, EnsureFileAccessible);
	Gura_AssignMethod(wx_PathList, FindAbsoluteValidPath);
	Gura_AssignMethod(wx_PathList, FindValidPath);
}

Gura_ImplementDescendantCreator(wx_PathList)
{
	return new Object_wx_PathList((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
