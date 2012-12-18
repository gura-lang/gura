//----------------------------------------------------------------------------
// wxDataViewRenderer
// extracted from dataviewrenderer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(GetMode);
Gura_DeclarePrivUserSymbol(GetOwner);
Gura_DeclarePrivUserSymbol(GetValue);
Gura_DeclarePrivUserSymbol(GetVariantType);
Gura_DeclarePrivUserSymbol(SetOwner);
Gura_DeclarePrivUserSymbol(SetValue);
Gura_DeclarePrivUserSymbol(Validate);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataViewRenderer: public wxDataViewRenderer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DataViewRenderer *_pObj;
public:
	//inline wx_DataViewRenderer(const wxString& varianttype, wxDataViewCellMode mode) : wxDataViewRenderer(varianttype, mode), _sig(NULL), _pObj(NULL) {}
	//virtual wxDataViewCellMode GetMode();
	//virtual wxDataViewColumn* GetOwner();
	//virtual bool GetValue(wxVariant& value);
	//virtual wxString GetVariantType();
	//virtual void SetOwner(wxDataViewColumn* owner);
	//virtual bool SetValue(const wxVariant& value);
	//virtual bool Validate(wxVariant& value);
	~wx_DataViewRenderer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DataViewRenderer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataViewRenderer::~wx_DataViewRenderer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DataViewRenderer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewRenderer
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataViewRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DataViewRenderer));
	DeclareArg(env, "varianttype", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(DataViewRenderer)
{
#if 0
	wxString varianttype = wxString::FromUTF8(args.GetString(0));
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(1)) mode = static_cast<wxDataViewCellMode>(args.GetInt(1));
	wx_DataViewRenderer *pEntity = new wx_DataViewRenderer(varianttype, mode);
	Object_wx_DataViewRenderer *pObj = Object_wx_DataViewRenderer::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DataViewRenderer(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_DataViewRenderer, GetMode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewRenderer, GetMode)
{
#if 0
	Object_wx_DataViewRenderer *pSelf = Object_wx_DataViewRenderer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDataViewCellMode rtn = pSelf->GetEntity()->GetMode();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewRenderer, GetOwner)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewRenderer, GetOwner)
{
#if 0
	Object_wx_DataViewRenderer *pSelf = Object_wx_DataViewRenderer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDataViewColumn *rtn = (wxDataViewColumn *)pSelf->GetEntity()->GetOwner();
	return ReturnValue(env, sig, args, Value(new Object_wx_DataViewColumn(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewRenderer, GetValue)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "value", VTYPE_wx_Variant, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewRenderer, GetValue)
{
#if 0
	Object_wx_DataViewRenderer *pSelf = Object_wx_DataViewRenderer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxVariant *value = Object_wx_Variant::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->GetValue(*value);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewRenderer, GetVariantType)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewRenderer, GetVariantType)
{
#if 0
	Object_wx_DataViewRenderer *pSelf = Object_wx_DataViewRenderer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetVariantType();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewRenderer, SetOwner)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "owner", VTYPE_wx_DataViewColumn, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_DataViewRenderer, SetOwner)
{
#if 0
	Object_wx_DataViewRenderer *pSelf = Object_wx_DataViewRenderer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDataViewColumn *owner = Object_wx_DataViewColumn::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetOwner(owner);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewRenderer, SetValue)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "value", VTYPE_wx_Variant, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewRenderer, SetValue)
{
#if 0
	Object_wx_DataViewRenderer *pSelf = Object_wx_DataViewRenderer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxVariant *value = Object_wx_Variant::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->SetValue(*value);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewRenderer, Validate)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "value", VTYPE_wx_Variant, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewRenderer, Validate)
{
#if 0
	Object_wx_DataViewRenderer *pSelf = Object_wx_DataViewRenderer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxVariant *value = Object_wx_Variant::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->Validate(*value);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDataViewRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewRenderer::~Object_wx_DataViewRenderer()
{
}

Object *Object_wx_DataViewRenderer::Clone() const
{
	return NULL;
}

String Object_wx_DataViewRenderer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DataViewRenderer:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DataViewRenderer::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(GetMode);
	Gura_RealizeUserSymbol(GetOwner);
	Gura_RealizeUserSymbol(GetValue);
	Gura_RealizeUserSymbol(GetVariantType);
	Gura_RealizeUserSymbol(SetOwner);
	Gura_RealizeUserSymbol(SetValue);
	Gura_RealizeUserSymbol(Validate);
	Gura_AssignFunction(DataViewRenderer);
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewRenderer)
{
	Gura_AssignMethod(wx_DataViewRenderer, GetMode);
	Gura_AssignMethod(wx_DataViewRenderer, GetOwner);
	Gura_AssignMethod(wx_DataViewRenderer, GetValue);
	Gura_AssignMethod(wx_DataViewRenderer, GetVariantType);
	Gura_AssignMethod(wx_DataViewRenderer, SetOwner);
	Gura_AssignMethod(wx_DataViewRenderer, SetValue);
	Gura_AssignMethod(wx_DataViewRenderer, Validate);
}

Gura_ImplementDescendantCreator(wx_DataViewRenderer)
{
	return new Object_wx_DataViewRenderer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
