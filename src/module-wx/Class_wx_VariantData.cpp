//----------------------------------------------------------------------------
// wxVariantData
// extracted from variant.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_VariantData: public wxVariantData, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_VariantData *_pObj;
public:
	//inline wx_VariantData() : wxVariantData(), _pSig(nullptr), _pObj(nullptr) {}
	~wx_VariantData();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_VariantData *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_VariantData::~wx_VariantData()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_VariantData::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxVariantData
//----------------------------------------------------------------------------
Gura_DeclareFunction(VariantDataEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_VariantData));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(VariantDataEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_VariantData *pEntity = new wx_VariantData();
	Object_wx_VariantData *pObj = Object_wx_VariantData::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_VariantData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_VariantData, DecRef)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantData, DecRef)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->DecRef();
	return Value::Null;
}

Gura_DeclareMethod(wx_VariantData, Eq)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "data", VTYPE_wx_VariantData, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VariantData, Eq)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxVariantData *data = Object_wx_VariantData::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Eq(*data);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VariantData, GetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VariantData, GetType)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetType();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_VariantData, GetValueClassInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VariantData, GetValueClassInfo)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxClassInfo *rtn = (wxClassInfo *)pThis->GetEntity()->GetValueClassInfo();
	return ReturnValue(env, sig, args, Value(new Object_wx_ClassInfo(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_VariantData, IncRef)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VariantData, IncRef)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->IncRef();
	return Value::Null;
}

Gura_DeclareMethod(wx_VariantData, Read)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VariantData, Read)
{
#if 0
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	Stream & stream = args.GetStream(0);
	bool rtn = pThis->GetEntity()->Read(stream);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_VariantData, Read_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VariantData, Read_1)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString string = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Read(string);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VariantData, Write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VariantData, Write)
{
#if 0
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	Stream & stream = args.GetStream(0);
	bool rtn = pThis->GetEntity()->Write(stream);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_VariantData, Write_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VariantData, Write_1)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString string = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Write(string);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_VariantData, wxGetVariantCast)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_VariantData, wxGetVariantCast)
{
	Object_wx_VariantData *pThis = Object_wx_VariantData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxVariantData
//----------------------------------------------------------------------------
Object_wx_VariantData::~Object_wx_VariantData()
{
}

Object *Object_wx_VariantData::Clone() const
{
	return nullptr;
}

String Object_wx_VariantData::ToString(bool exprFlag)
{
	String rtn("<wx.VariantData:");
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
// Class implementation for wxVariantData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VariantData)
{
	Gura_AssignFunction(VariantDataEmpty);
	Gura_AssignMethod(wx_VariantData, DecRef);
	Gura_AssignMethod(wx_VariantData, Eq);
	Gura_AssignMethod(wx_VariantData, GetType);
	Gura_AssignMethod(wx_VariantData, GetValueClassInfo);
	Gura_AssignMethod(wx_VariantData, IncRef);
	Gura_AssignMethod(wx_VariantData, Read);
	Gura_AssignMethod(wx_VariantData, Read_1);
	Gura_AssignMethod(wx_VariantData, Write);
	Gura_AssignMethod(wx_VariantData, Write_1);
	Gura_AssignMethod(wx_VariantData, wxGetVariantCast);
}

Gura_ImplementDescendantCreator(wx_VariantData)
{
	return new Object_wx_VariantData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
