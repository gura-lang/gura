//----------------------------------------------------------------------------
// wxArrayString
// extracted from arrstrng.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ArrayString: public wxArrayString, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ArrayString *_pObj;
public:
	inline wx_ArrayString() : wxArrayString(), _sig(NULL), _pObj(NULL) {}
	inline wx_ArrayString(const wxArrayString& array) : wxArrayString(array), _sig(NULL), _pObj(NULL) {}
	inline wx_ArrayString(size_t sz, const wxChar** arr) : wxArrayString(sz, arr), _sig(NULL), _pObj(NULL) {}
	inline wx_ArrayString(size_t sz, const wxString* arr) : wxArrayString(sz, arr), _sig(NULL), _pObj(NULL) {}
	~wx_ArrayString();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ArrayString *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ArrayString::~wx_ArrayString()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ArrayString::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxArrayString
//----------------------------------------------------------------------------
Gura_DeclareFunction(ArrayStringEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ArrayString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ArrayStringEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ArrayString *pEntity = new wx_ArrayString();
	Object_wx_ArrayString *pObj = Object_wx_ArrayString::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ArrayString(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(ArrayString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ArrayString));
	DeclareArg(env, "array", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ArrayString)
{
	if (!CheckWxReady(sig)) return Value::Null;
	std::auto_ptr<wxArrayString> array(CreateArrayString(args.GetList(0)));
	wx_ArrayString *pEntity = new wx_ArrayString(*array);
	Object_wx_ArrayString *pObj = Object_wx_ArrayString::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ArrayString(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(ArrayString_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ArrayString));
	DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "arr", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ArrayString_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	size_t sz = args.GetSizeT(0);
	wxChar arr = static_cast<wxChar>(args.GetInt(1));
	wx_ArrayString *pEntity = new wx_ArrayString(sz, arr);
	Object_wx_ArrayString *pObj = Object_wx_ArrayString::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ArrayString(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(ArrayString_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ArrayString));
	DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "arr", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ArrayString_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
	size_t sz = args.GetSizeT(0);
	wxString arr = wxString::FromUTF8(args.GetString(1));
	wx_ArrayString *pEntity = new wx_ArrayString(sz, arr);
	Object_wx_ArrayString *pObj = Object_wx_ArrayString::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ArrayString(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_ArrayString, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "copies", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArrayString, Add)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	size_t copies = 1;
	if (args.IsValid(1)) copies = args.GetSizeT(1);
	size_t rtn = pThis->GetEntity()->Add(str, copies);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ArrayString, Alloc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "nCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, Alloc)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t nCount = args.GetSizeT(0);
	pThis->GetEntity()->Alloc(nCount);
	return Value::Null;
}

Gura_DeclareMethod(wx_ArrayString, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArrayString, Clear)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Clear();
	return Value::Null;
}

Gura_DeclareMethod(wx_ArrayString, Count)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArrayString, Count)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->Count();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ArrayString, Empty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArrayString, Empty)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Empty();
	return Value::Null;
}

Gura_DeclareMethod(wx_ArrayString, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArrayString, GetCount)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ArrayString, Index)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sz", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bCase", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "bFromEnd", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArrayString, Index)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString sz = wxString::FromUTF8(args.GetString(0));
	bool bCase = true;
	if (args.IsValid(1)) bCase = args.GetBoolean(1);
	bool bFromEnd = false;
	if (args.IsValid(2)) bFromEnd = args.GetBoolean(2);
	int rtn = pThis->GetEntity()->Index(sz, bCase, bFromEnd);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ArrayString, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "nIndex", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "copies", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArrayString, Insert)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	size_t nIndex = args.GetSizeT(1);
	size_t copies = 1;
	if (args.IsValid(2)) copies = args.GetSizeT(2);
	pThis->GetEntity()->Insert(str, nIndex, copies);
	return Value::Null;
}

Gura_DeclareMethod(wx_ArrayString, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArrayString, IsEmpty)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsEmpty();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ArrayString, Item)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "nIndex", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArrayString, Item)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t nIndex = args.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->Item(nIndex);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ArrayString, Last)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArrayString, Last)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->Last();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ArrayString, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sz", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, Remove)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString sz = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->Remove(sz);
	return Value::Null;
}

Gura_DeclareMethod(wx_ArrayString, RemoveAt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "nIndex", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArrayString, RemoveAt)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t nIndex = args.GetSizeT(0);
	size_t count = 1;
	if (args.IsValid(1)) count = args.GetSizeT(1);
	pThis->GetEntity()->RemoveAt(nIndex, count);
	return Value::Null;
}

Gura_DeclareMethod(wx_ArrayString, Shrink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArrayString, Shrink)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Shrink();
	return Value::Null;
}

Gura_DeclareMethod(wx_ArrayString, Sort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "reverseOrder", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArrayString, Sort)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool reverseOrder = false;
	if (args.IsValid(0)) reverseOrder = args.GetBoolean(0);
	pThis->GetEntity()->Sort(reverseOrder);
	return Value::Null;
}

Gura_DeclareMethod(wx_ArrayString, Sort_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_ArrayString, Sort_1)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Sort();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxArrayString
//----------------------------------------------------------------------------
Object_wx_ArrayString::~Object_wx_ArrayString()
{
}

Object *Object_wx_ArrayString::Clone() const
{
	return NULL;
}

String Object_wx_ArrayString::ToString(bool exprFlag)
{
	String rtn("<wx.ArrayString:");
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
// Class implementation for wxArrayString
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArrayString)
{
	Gura_AssignFunction(ArrayStringEmpty);
	Gura_AssignFunction(ArrayString);
	Gura_AssignFunction(ArrayString_1);
	Gura_AssignFunction(ArrayString_2);
	Gura_AssignMethod(wx_ArrayString, Add);
	Gura_AssignMethod(wx_ArrayString, Alloc);
	Gura_AssignMethod(wx_ArrayString, Clear);
	Gura_AssignMethod(wx_ArrayString, Count);
	Gura_AssignMethod(wx_ArrayString, Empty);
	Gura_AssignMethod(wx_ArrayString, GetCount);
	Gura_AssignMethod(wx_ArrayString, Index);
	Gura_AssignMethod(wx_ArrayString, Insert);
	Gura_AssignMethod(wx_ArrayString, IsEmpty);
	Gura_AssignMethod(wx_ArrayString, Item);
	Gura_AssignMethod(wx_ArrayString, Last);
	Gura_AssignMethod(wx_ArrayString, Remove);
	Gura_AssignMethod(wx_ArrayString, RemoveAt);
	Gura_AssignMethod(wx_ArrayString, Shrink);
	Gura_AssignMethod(wx_ArrayString, Sort);
	Gura_AssignMethod(wx_ArrayString, Sort_1);
}

Gura_ImplementDescendantCreator(wx_ArrayString)
{
	return new Object_wx_ArrayString((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
