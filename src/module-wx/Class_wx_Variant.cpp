//----------------------------------------------------------------------------
// wxVariant
// extracted from variant.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Variant: public wxVariant, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Variant *_pObj;
public:
	inline wx_Variant() : wxVariant(), _pObj(nullptr) {}
	inline wx_Variant(const wxVariant& variant) : wxVariant(variant), _pObj(nullptr) {}
	inline wx_Variant(const wxChar* value, const wxString& name) : wxVariant(value, name), _pObj(nullptr) {}
	inline wx_Variant(const wxString& value, const wxString& name) : wxVariant(value, name), _pObj(nullptr) {}
	inline wx_Variant(wxChar value, const wxString& name) : wxVariant(value, name), _pObj(nullptr) {}
	inline wx_Variant(long value, const wxString& name) : wxVariant(value, name), _pObj(nullptr) {}
	inline wx_Variant(bool value, const wxString& name) : wxVariant(value, name), _pObj(nullptr) {}
	inline wx_Variant(double value, const wxString& name) : wxVariant(value, name), _pObj(nullptr) {}
	//inline wx_Variant(const wxList& value, const wxString& name) : wxVariant(value, name), _pObj(nullptr) {}
	inline wx_Variant(void* value, const wxString& name) : wxVariant(value, name), _pObj(nullptr) {}
	inline wx_Variant(wxObject* value, const wxString& name) : wxVariant(value, name), _pObj(nullptr) {}
	inline wx_Variant(wxVariantData* data, const wxString& name) : wxVariant(data, name), _pObj(nullptr) {}
	inline wx_Variant(wxDateTime& val, const wxString& name) : wxVariant(val, name), _pObj(nullptr) {}
	inline wx_Variant(wxArrayString& val, const wxString& name) : wxVariant(val, name), _pObj(nullptr) {}
	//inline wx_Variant(DATE_STRUCT* val, const wxString& name) : wxVariant(val, name), _pObj(nullptr) {}
	//inline wx_Variant(TIME_STRUCT* val, const wxString& name) : wxVariant(val, name), _pObj(nullptr) {}
	//inline wx_Variant(TIMESTAMP_STRUCT* val, const wxString& name) : wxVariant(val, name), _pObj(nullptr) {}
	~wx_Variant();
	inline void AssocWithGura(Object_wx_Variant *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Variant::~wx_Variant()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Variant::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxVariant
//----------------------------------------------------------------------------
Gura_DeclareFunction(VariantEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Variant));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(VariantEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Variant *pEntity = new wx_Variant();
	Object_wx_Variant *pObj = Object_wx_Variant::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Variant(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Variant)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Variant));
	DeclareArg(env, "value", VTYPE_any, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Variant)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Variant *pEntity = nullptr;
	wxString name = wxEmptyString;
	if (arg.IsValid(1)) name = wxString::FromUTF8(arg.GetString(1));
	if (arg.Is_string(0)) {
		pEntity = new wx_Variant(arg.GetString(0), name);
	} else if (arg.Is_number(0)) {
		pEntity = new wx_Variant(arg.GetLong(0), name);
	} else if (arg.Is_boolean(0)) {
		pEntity = new wx_Variant(arg.GetBoolean(0), name);
	} else if (arg.Is_list(0)) {
		wxArrayString val;
		foreach_const (ValueList, pValue, arg.GetList(0)) {
			const Value &value = *pValue;
			if (!value.Is_string()) {
				sig.SetError(ERR_TypeError, "elements in the list must be string");
				return Value::Nil;
			}
			val.push_back(wxString::FromUTF8(value.GetString()));
		}
		pEntity = new wx_Variant(val, name);
	} else if (arg.IsInstanceOf(0, VTYPE_wx_VariantData)) {
		pEntity = new wx_Variant(Object_wx_VariantData::GetObject(arg, 0)->GetEntity(), name);
	} else if (arg.IsInstanceOf(0, VTYPE_wx_DateTime)) {
		pEntity = new wx_Variant(*Object_wx_DateTime::GetObject(arg, 0)->GetEntity(), name);
	} else if (arg.IsInstanceOf(0, VTYPE_wx_Colour)) {
		pEntity = new wx_Variant();
		(*pEntity) << *Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	} else if (arg.IsInstanceOf(0, VTYPE_wx_Image)) {
		pEntity = new wx_Variant();
		(*pEntity) << *Object_wx_Image::GetObject(arg, 0)->GetEntity();
	} else if (arg.IsInstanceOf(0, VTYPE_wx_Icon)) {
		pEntity = new wx_Variant();
		(*pEntity) << *Object_wx_Icon::GetObject(arg, 0)->GetEntity();
	} else if (arg.IsInstanceOf(0, VTYPE_wx_Bitmap)) {
		pEntity = new wx_Variant();
		(*pEntity) << *Object_wx_Bitmap::GetObject(arg, 0)->GetEntity();
	} else if (arg.IsInstanceOf(0, VTYPE_wx_Object)) {
		pEntity = new wx_Variant(new wxObject(*Object_wx_Object::GetObject(arg, 0)->GetEntity()), name);
	} else {
		SetError_ArgumentTypeByIndex(env, arg, 0);
		return Value::Nil;
	}
	Object_wx_Variant *pObj = Object_wx_Variant::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Variant(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_Variant, Append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_wx_Variant, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, Append)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxVariant *value = Object_wx_Variant::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->Append(*value);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, ClearList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, ClearList)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->ClearList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Convert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, Convert)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long value = arg.GetLong(0);
	bool rtn = pThis->GetEntity()->Convert(value);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Convert_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "value", VTYPE_boolean, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, Convert_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool value = arg.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Convert(value);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Convert_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, Convert_2)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	double value = arg.GetDouble(0);
	bool rtn = pThis->GetEntity()->Convert(value);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Convert_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, Convert_3)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString value = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->Convert(value);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Convert_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, Convert_4)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString value = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->Convert(value);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, Convert_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_wx_DateTime, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, Convert_5)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateTime *value = Object_wx_DateTime::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Convert(value);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Variant, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, GetCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetCount();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Variant, Delete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, Delete)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t item = arg.GetSizeT(0);
	bool rtn = pThis->GetEntity()->Delete(item);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Variant, GetArrayString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, GetArrayString)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArrayString rtn = pThis->GetEntity()->GetArrayString();
	return ReturnValue(env, arg, ArrayStringToValue(env, rtn));
}

Gura_DeclareMethod(wx_Variant, GetBool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, GetBool)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetBool();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Variant, GetChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, GetChar)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar rtn = pThis->GetEntity()->GetChar();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Variant, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, GetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxVariantData *rtn = (wxVariantData *)pThis->GetEntity()->GetData();
	return ReturnValue(env, arg, Value(new Object_wx_VariantData(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Variant, GetDateTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, GetDateTime)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateTime rtn = pThis->GetEntity()->GetDateTime();
	return ReturnValue(env, arg, Value(new Object_wx_DateTime(new wxDateTime(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Variant, GetDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, GetDouble)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	double rtn = pThis->GetEntity()->GetDouble();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Variant, GetLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, GetLong)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetLong();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Variant, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Variant, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, GetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetString();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Variant, GetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, GetType)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetType();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Variant, GetVoidPtr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, GetVoidPtr)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->GetVoidPtr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, GetWxObjectPtr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, GetWxObjectPtr)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxObject *rtn = (wxObject *)pThis->GetEntity()->GetWxObjectPtr();
	return ReturnValue(env, arg, Value(new Object_wx_Object(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Variant, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_wx_Variant, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, Insert)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxVariant *value = Object_wx_Variant::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->Insert(*value);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, IsNull)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, IsNull)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsNull();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Variant, IsType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "type", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, IsType)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString type = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->IsType(type);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Variant, IsValueKindOf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "type", VTYPE_wx_ClassInfo, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, IsValueKindOf)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxClassInfo *type = Object_wx_ClassInfo::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsValueKindOf(*type);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, MakeNull)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, MakeNull)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->MakeNull();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, MakeString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, MakeString)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->MakeString();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Variant, Member)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_wx_Variant, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Variant, Member)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxVariant *value = Object_wx_Variant::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Member(*value);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Variant, NullList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Variant, NullList)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->NullList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Variant, SetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "data", VTYPE_wx_VariantData, OCCUR_Once);
}

Gura_ImplementMethod(wx_Variant, SetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_Variant *pThis = Object_wx_Variant::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxVariantData *data = Object_wx_VariantData::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetData(data);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxVariant
//----------------------------------------------------------------------------
Object_wx_Variant::~Object_wx_Variant()
{
}

Object *Object_wx_Variant::Clone() const
{
	return nullptr;
}

String Object_wx_Variant::ToString(bool exprFlag)
{
	String rtn("<wx.Variant:");
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
// Class implementation for wxVariant
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Variant)
{
	Gura_AssignFunction(VariantEmpty);
	Gura_AssignFunction(Variant);
	Gura_AssignMethod(wx_Variant, Append);
	Gura_AssignMethod(wx_Variant, Clear);
	Gura_AssignMethod(wx_Variant, ClearList);
	Gura_AssignMethod(wx_Variant, Convert);
	Gura_AssignMethod(wx_Variant, Convert_1);
	Gura_AssignMethod(wx_Variant, Convert_2);
	Gura_AssignMethod(wx_Variant, Convert_3);
	Gura_AssignMethod(wx_Variant, Convert_4);
	Gura_AssignMethod(wx_Variant, Convert_5);
	Gura_AssignMethod(wx_Variant, GetCount);
	Gura_AssignMethod(wx_Variant, Delete);
	Gura_AssignMethod(wx_Variant, GetArrayString);
	Gura_AssignMethod(wx_Variant, GetBool);
	Gura_AssignMethod(wx_Variant, GetChar);
	Gura_AssignMethod(wx_Variant, GetData);
	Gura_AssignMethod(wx_Variant, GetDateTime);
	Gura_AssignMethod(wx_Variant, GetDouble);
	Gura_AssignMethod(wx_Variant, GetLong);
	Gura_AssignMethod(wx_Variant, GetName);
	Gura_AssignMethod(wx_Variant, GetString);
	Gura_AssignMethod(wx_Variant, GetType);
	Gura_AssignMethod(wx_Variant, GetVoidPtr);
	Gura_AssignMethod(wx_Variant, GetWxObjectPtr);
	Gura_AssignMethod(wx_Variant, Insert);
	Gura_AssignMethod(wx_Variant, IsNull);
	Gura_AssignMethod(wx_Variant, IsType);
	Gura_AssignMethod(wx_Variant, IsValueKindOf);
	Gura_AssignMethod(wx_Variant, MakeNull);
	Gura_AssignMethod(wx_Variant, MakeString);
	Gura_AssignMethod(wx_Variant, Member);
	Gura_AssignMethod(wx_Variant, NullList);
	Gura_AssignMethod(wx_Variant, SetData);
}

Gura_ImplementDescendantCreator(wx_Variant)
{
	return new Object_wx_Variant((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
