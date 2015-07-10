//----------------------------------------------------------------------------
// wxFindReplaceData
// extracted from fdrepdlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FindReplaceData: public wxFindReplaceData, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_FindReplaceData *_pObj;
public:
	inline wx_FindReplaceData(wxUint32 flags) : wxFindReplaceData(flags), _pSig(nullptr), _pObj(nullptr) {}
	~wx_FindReplaceData();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FindReplaceData *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FindReplaceData::~wx_FindReplaceData()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FindReplaceData::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFindReplaceData
//----------------------------------------------------------------------------
Gura_DeclareFunction(FindReplaceData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FindReplaceData));
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindReplaceData)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxUint32 flags = 0;
	if (args.IsValid(0)) flags = static_cast<wxUint32>(args.GetULong(0));
	wx_FindReplaceData *pEntity = new wx_FindReplaceData(flags);
	Object_wx_FindReplaceData *pObj = Object_wx_FindReplaceData::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_FindReplaceData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_FindReplaceData, GetFindString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FindReplaceData, GetFindString)
{
	Object_wx_FindReplaceData *pThis = Object_wx_FindReplaceData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetFindString();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FindReplaceData, GetReplaceString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FindReplaceData, GetReplaceString)
{
	Object_wx_FindReplaceData *pThis = Object_wx_FindReplaceData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetReplaceString();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FindReplaceData, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FindReplaceData, GetFlags)
{
	Object_wx_FindReplaceData *pThis = Object_wx_FindReplaceData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetFlags();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FindReplaceData, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FindReplaceData, SetFlags)
{
	Object_wx_FindReplaceData *pThis = Object_wx_FindReplaceData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxUint32 flags = static_cast<wxUint32>(args.GetULong(0));
	pThis->GetEntity()->SetFlags(flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_FindReplaceData, SetFindString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FindReplaceData, SetFindString)
{
	Object_wx_FindReplaceData *pThis = Object_wx_FindReplaceData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetFindString(str);
	return Value::Null;
}

Gura_DeclareMethod(wx_FindReplaceData, SetReplaceString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FindReplaceData, SetReplaceString)
{
	Object_wx_FindReplaceData *pThis = Object_wx_FindReplaceData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetReplaceString(str);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxFindReplaceData
//----------------------------------------------------------------------------
Object_wx_FindReplaceData::~Object_wx_FindReplaceData()
{
}

Object *Object_wx_FindReplaceData::Clone() const
{
	return nullptr;
}

String Object_wx_FindReplaceData::ToString(bool exprFlag)
{
	String rtn("<wx.FindReplaceData:");
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
// Class implementation for wxFindReplaceData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FindReplaceData)
{
	Gura_AssignFunction(FindReplaceData);
	Gura_AssignMethod(wx_FindReplaceData, GetFindString);
	Gura_AssignMethod(wx_FindReplaceData, GetReplaceString);
	Gura_AssignMethod(wx_FindReplaceData, GetFlags);
	Gura_AssignMethod(wx_FindReplaceData, SetFlags);
	Gura_AssignMethod(wx_FindReplaceData, SetFindString);
	Gura_AssignMethod(wx_FindReplaceData, SetReplaceString);
}

Gura_ImplementDescendantCreator(wx_FindReplaceData)
{
	return new Object_wx_FindReplaceData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
