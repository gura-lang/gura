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
	Gura::Signal *_pSig;
	Object_wx_DataObject *_pObj;
public:
	//inline wx_DataObject() : wxDataObject(), _pSig(nullptr), _pObj(nullptr) {}
	//virtual void GetAllFormats(wxDataFormat * formats, Direction dir);
	//virtual bool GetDataHere(const wxDataFormat& format, void *buf);
	//virtual size_t GetDataSize(const wxDataFormat& format);
	//virtual size_t GetFormatCount(Direction dir);
	//virtual wxDataFormat GetPreferredFormat(Direction dir);
	//virtual bool SetData(const wxDataFormat& format, size_t len, const void *buf);
	~wx_DataObject();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DataObject *pObj) {
		_pSig = &sig, _pObj = pObj;
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
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_DataObject *pEntity = new wx_DataObject();
	Object_wx_DataObject *pObj = Object_wx_DataObject::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataObject(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_DataObject, GetAllFormats)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "dir", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataObject, GetAllFormats)
{
	Object_wx_DataObject *pThis = Object_wx_DataObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataObject::Direction dir = wxDataObject::Get;
	size_t n = pThis->GetEntity()->GetFormatCount(dir);
	if (args.IsValid(0)) dir = static_cast<wxDataObject::Direction>(args.GetInt(0));
	Value rtn;
	wxDataFormat *formats = new wxDataFormat[n];
	pThis->GetEntity()->GetAllFormats(formats, dir);
	ValueList &valList = rtn.InitAsList(env);
	valList.reserve(n);
	for (size_t i = 0; i < n; i++) {
		valList.push_back(Value(new Object_wx_DataFormat(new wxDataFormat(formats[i]), nullptr, OwnerTrue)));
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
#if 0
	Object_wx_DataObject *pThis = Object_wx_DataObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataFormat *format = Object_wx_DataFormat::GetObject(args, 0)->GetEntity();
	int *buf = args.GetInt(1);
	bool rtn = pThis->GetEntity()->GetDataHere(*format, *buf);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataObject, GetDataSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "format", VTYPE_wx_DataFormat, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataObject, GetDataSize)
{
	Object_wx_DataObject *pThis = Object_wx_DataObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataFormat *format = Object_wx_DataFormat::GetObject(args, 0)->GetEntity();
	size_t rtn = pThis->GetEntity()->GetDataSize(*format);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataObject, GetFormatCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataObject, GetFormatCount)
{
	Object_wx_DataObject *pThis = Object_wx_DataObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetFormatCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataObject, GetPreferredFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataObject, GetPreferredFormat)
{
	Object_wx_DataObject *pThis = Object_wx_DataObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataFormat rtn = pThis->GetEntity()->GetPreferredFormat();
	return ReturnValue(env, sig, args, Value(new Object_wx_DataFormat(new wxDataFormat(rtn), nullptr, OwnerTrue)));
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
#if 0
	Object_wx_DataObject *pThis = Object_wx_DataObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataFormat *format = Object_wx_DataFormat::GetObject(args, 0)->GetEntity();
	size_t len = args.GetSizeT(1);
	int *buf = args.GetInt(2);
	bool rtn = pThis->GetEntity()->SetData(*format, len, *buf);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
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
