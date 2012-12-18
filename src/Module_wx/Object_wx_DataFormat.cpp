//----------------------------------------------------------------------------
// wxDataFormat
// extracted from dataform.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataFormat: public wxDataFormat, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DataFormat *_pObj;
public:
	inline wx_DataFormat(NativeFormat format) : wxDataFormat(format), _sig(NULL), _pObj(NULL) {}
	//inline wx_DataFormat(const wxChar *format) : wxDataFormat(*format), _sig(NULL), _pObj(NULL) {}
	~wx_DataFormat();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DataFormat *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataFormat::~wx_DataFormat()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DataFormat::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataFormat
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataFormat)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DataFormat));
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataFormat)
{
	wxDataFormat::NativeFormat format = wxDF_INVALID;
	if (args.IsValid(0)) format = static_cast<wxDataFormat::NativeFormat>(args.GetInt(0));
	wx_DataFormat *pEntity = new wx_DataFormat(format);
	Object_wx_DataFormat *pObj = Object_wx_DataFormat::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DataFormat(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(DataFormat_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DataFormat));
	DeclareArg(env, "*format", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(DataFormat_1)
{
#if 0
	wxChar *format = static_cast<wxChar>(args.GetInt(0));
	wx_DataFormat *pEntity = new wx_DataFormat(*format);
	Object_wx_DataFormat *pObj = Object_wx_DataFormat::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DataFormat(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataFormat, GetId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataFormat, GetId)
{
	Object_wx_DataFormat *pSelf = Object_wx_DataFormat::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetId();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DataFormat, GetType)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataFormat, GetType)
{
	Object_wx_DataFormat *pSelf = Object_wx_DataFormat::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDataFormat::NativeFormat rtn = pSelf->GetEntity()->GetType();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataFormat, SetId)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*format", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_DataFormat, SetId)
{
#if 0
	Object_wx_DataFormat *pSelf = Object_wx_DataFormat::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxChar *format = static_cast<wxChar>(args.GetInt(0));
	pSelf->GetEntity()->SetId(*format);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataFormat, SetType)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataFormat, SetType)
{
	Object_wx_DataFormat *pSelf = Object_wx_DataFormat::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDataFormat::NativeFormat format = static_cast<wxDataFormat::NativeFormat>(args.GetInt(0));
	pSelf->GetEntity()->SetType(format);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDataFormat
//----------------------------------------------------------------------------
Object_wx_DataFormat::~Object_wx_DataFormat()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_DataFormat::Clone() const
{
	return NULL;
}

String Object_wx_DataFormat::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DataFormat:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DataFormat::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(DataFormat);
	Gura_AssignFunction(DataFormat_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxDataFormat
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClassWithCast(wx_DataFormat)
{
	Gura_AssignMethod(wx_DataFormat, GetId);
	Gura_AssignMethod(wx_DataFormat, GetType);
	Gura_AssignMethod(wx_DataFormat, SetId);
	Gura_AssignMethod(wx_DataFormat, SetType);
}

Gura_ImplementDescendantCreator(wx_DataFormat)
{
	return new Object_wx_DataFormat((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_ImplementCastFrom(wx_DataFormat)
{
	if (!value.IsNumber()) return false;
	wxDataFormat::NativeFormat format =
					static_cast<wxDataFormat::NativeFormat>(value.GetInt());
	wx_DataFormat *pDataFormat = new wx_DataFormat(format);
	Object_wx_DataFormat *pObj = new Object_wx_DataFormat(pDataFormat, pDataFormat, OwnerFalse);
	pDataFormat->AssocWithGura(sig, pObj);
	value = Value(pObj);
	return true;
}

Gura_ImplementCastTo(wx_DataFormat)
{
	return false;
}

}}
