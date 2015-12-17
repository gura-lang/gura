//----------------------------------------------------------------------------
// wxDataObject
// extracted from dataobj.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(GetAllFormats);
Gura_DeclarePrivUserSymbol(GetDataHere);
Gura_DeclarePrivUserSymbol(GetDataSize);
Gura_DeclarePrivUserSymbol(GetFormatCount);
Gura_DeclarePrivUserSymbol(GetPreferredFormat);
Gura_DeclarePrivUserSymbol(SetData);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataObject: public wxDataObject, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DataObject *_pObj;
public:
	//inline wx_DataObject() : wxDataObject(), _pObj(nullptr) {}
	//virtual void GetAllFormats(wxDataFormat * formats, Direction dir);
	//virtual bool GetDataHere(const wxDataFormat& format, void *buf);
	//virtual size_t GetDataSize(const wxDataFormat& format);
	//virtual size_t GetFormatCount(Direction dir);
	//virtual wxDataFormat GetPreferredFormat(Direction dir);
	//virtual bool SetData(const wxDataFormat& format, size_t len, const void *buf);
	~wx_DataObject();
	inline void AssocWithGura(Object_wx_DataObject *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataObject::~wx_DataObject()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DataObject::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataObject
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DataObject));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(DataObject)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_DataObject *pEntity = new wx_DataObject();
	Object_wx_DataObject *pObj = Object_wx_DataObject::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataObject(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataObject, GetAllFormats)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "dir", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataObject, GetAllFormats)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataObject *pThis = Object_wx_DataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDataObject::Direction dir = wxDataObject::Get;
	size_t n = pThis->GetEntity()->GetFormatCount(dir);
	if (arg.IsValid(0)) dir = static_cast<wxDataObject::Direction>(arg.GetInt(0));
	Value rtn;
	wxDataFormat *formats = new wxDataFormat[n];
	pThis->GetEntity()->GetAllFormats(formats, dir);
	Object_list *pObjList = rtn.Init_AsList(env);
	pObjList->Reserve(n);
	for (size_t i = 0; i < n; i++) {
		pObjList->Add(Value(new Object_wx_DataFormat(new wxDataFormat(formats[i]), nullptr, OwnerTrue)));
	}
	delete[] formats;
	return rtn;
}

Gura_DeclareMethod(wx_DataObject, GetDataHere)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_wx_DataFormat, OCCUR_Once);
	DeclareArg(env, "*buf", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataObject, GetDataHere)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DataObject *pThis = Object_wx_DataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDataFormat *format = Object_wx_DataFormat::GetObject(arg, 0)->GetEntity();
	int *buf = arg.GetInt(1);
	bool rtn = pThis->GetEntity()->GetDataHere(*format, *buf);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataObject, GetDataSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "format", VTYPE_wx_DataFormat, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataObject, GetDataSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataObject *pThis = Object_wx_DataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDataFormat *format = Object_wx_DataFormat::GetObject(arg, 0)->GetEntity();
	size_t rtn = pThis->GetEntity()->GetDataSize(*format);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DataObject, GetFormatCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataObject, GetFormatCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataObject *pThis = Object_wx_DataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetFormatCount();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DataObject, GetPreferredFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataObject, GetPreferredFormat)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataObject *pThis = Object_wx_DataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDataFormat rtn = pThis->GetEntity()->GetPreferredFormat();
	return ReturnValue(env, arg, Value(new Object_wx_DataFormat(new wxDataFormat(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DataObject, SetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_wx_DataFormat, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*buf", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataObject, SetData)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DataObject *pThis = Object_wx_DataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDataFormat *format = Object_wx_DataFormat::GetObject(arg, 0)->GetEntity();
	size_t len = arg.GetSizeT(1);
	int *buf = arg.GetInt(2);
	bool rtn = pThis->GetEntity()->SetData(*format, len, *buf);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxDataObject
//----------------------------------------------------------------------------
Object_wx_DataObject::~Object_wx_DataObject()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_DataObject::Clone() const
{
	return nullptr;
}

String Object_wx_DataObject::ToString(bool exprFlag)
{
	String rtn("<wx.DataObject:");
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
// Class implementation for wxDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataObject)
{
	Gura_RealizeUserSymbol(GetAllFormats);
	Gura_RealizeUserSymbol(GetDataHere);
	Gura_RealizeUserSymbol(GetDataSize);
	Gura_RealizeUserSymbol(GetFormatCount);
	Gura_RealizeUserSymbol(GetPreferredFormat);
	Gura_RealizeUserSymbol(SetData);
	Gura_AssignFunction(DataObject);
	Gura_AssignClassValue(Get, wxDataObject::Get);
	Gura_AssignClassValue(Set, wxDataObject::Set);
	Gura_AssignMethod(wx_DataObject, GetAllFormats);
	Gura_AssignMethod(wx_DataObject, GetDataHere);
	Gura_AssignMethod(wx_DataObject, GetDataSize);
	Gura_AssignMethod(wx_DataObject, GetFormatCount);
	Gura_AssignMethod(wx_DataObject, GetPreferredFormat);
	Gura_AssignMethod(wx_DataObject, SetData);
}

Gura_ImplementDescendantCreator(wx_DataObject)
{
	return new Object_wx_DataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
