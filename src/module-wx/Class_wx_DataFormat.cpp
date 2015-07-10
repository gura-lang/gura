//----------------------------------------------------------------------------
// wxDataFormat
// extracted from dataform.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataFormat: public wxDataFormat, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_DataFormat *_pObj;
public:
	inline wx_DataFormat(NativeFormat format) : wxDataFormat(format), _pSig(nullptr), _pObj(nullptr) {}
	//inline wx_DataFormat(const wxChar *format) : wxDataFormat(*format), _pSig(nullptr), _pObj(nullptr) {}
	~wx_DataFormat();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DataFormat *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataFormat::~wx_DataFormat()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DataFormat::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataFormat
//----------------------------------------------------------------------------
#if 0
Gura_DeclareFunction(DataFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DataFormat));
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataFormat)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDataFormatId format = wxDF_INVALID;
	if (args.IsValid(0)) format = static_cast<wxDataFormat::NativeFormat>(args.GetInt(0));
	wx_DataFormat *pEntity = new wx_DataFormat(format);
	Object_wx_DataFormat *pObj = Object_wx_DataFormat::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataFormat(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(DataFormat_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DataFormat));
	DeclareArg(env, "*format", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(DataFormat_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxChar *format = static_cast<wxChar>(args.GetInt(0));
	wx_DataFormat *pEntity = new wx_DataFormat(*format);
	Object_wx_DataFormat *pObj = Object_wx_DataFormat::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataFormat(pEntity, pEntity, OwnerFalse);
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
#endif

Gura_DeclareMethod(wx_DataFormat, GetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataFormat, GetId)
{
	Object_wx_DataFormat *pThis = Object_wx_DataFormat::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetId();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DataFormat, GetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataFormat, GetType)
{
#if 0
	Object_wx_DataFormat *pThis = Object_wx_DataFormat::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataFormat::NativeFormat rtn = pThis->GetEntity()->GetType();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataFormat, SetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*format", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_DataFormat, SetId)
{
#if 0
	Object_wx_DataFormat *pThis = Object_wx_DataFormat::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxChar *format = static_cast<wxChar>(args.GetInt(0));
	pThis->GetEntity()->SetId(*format);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataFormat, SetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataFormat, SetType)
{
#if 0
	Object_wx_DataFormat *pThis = Object_wx_DataFormat::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataFormat::NativeFormat format = static_cast<wxDataFormat::NativeFormat>(args.GetInt(0));
	pThis->GetEntity()->SetType(format);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDataFormat
//----------------------------------------------------------------------------
Object_wx_DataFormat::~Object_wx_DataFormat()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_DataFormat::Clone() const
{
	return nullptr;
}

String Object_wx_DataFormat::ToString(bool exprFlag)
{
	String rtn("<wx.DataFormat:");
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
// Class implementation for wxDataFormat
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataFormat)
{
	//Gura_AssignFunction(DataFormat);
	//Gura_AssignFunction(DataFormat_1);
	Gura_AssignMethod(wx_DataFormat, GetId);
	Gura_AssignMethod(wx_DataFormat, GetType);
	Gura_AssignMethod(wx_DataFormat, SetId);
	Gura_AssignMethod(wx_DataFormat, SetType);
}

Gura_ImplementDescendantCreator(wx_DataFormat)
{
	return new Object_wx_DataFormat((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
