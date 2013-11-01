//----------------------------------------------------------------------------
// wxCustomDataObject
// extracted from custdobj.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(Alloc);
Gura_DeclarePrivUserSymbol(Free);
Gura_DeclarePrivUserSymbol(GetSize);
Gura_DeclarePrivUserSymbol(GetData);
Gura_DeclarePrivUserSymbol(SetData);
Gura_DeclarePrivUserSymbol(TakeData);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CustomDataObject: public wxCustomDataObject, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_CustomDataObject *_pObj;
public:
	inline wx_CustomDataObject(const wxDataFormat& format) : wxCustomDataObject(format), _sig(NULL), _pObj(NULL) {}
	//virtual void * Alloc(size_t size);
	//virtual void Free();
	//virtual size_t GetSize();
	//virtual void * GetData();
	//virtual void SetData(size_t size, const void *data);
	//virtual void TakeData(size_t size, const void *data);
	~wx_CustomDataObject();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_CustomDataObject *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CustomDataObject::~wx_CustomDataObject()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_CustomDataObject::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCustomDataObject
//----------------------------------------------------------------------------
Gura_DeclareFunction(CustomDataObject)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_CustomDataObject));
	DeclareArg(env, "format", VTYPE_wx_DataFormat, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CustomDataObject)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDataFormat *format = (wxDataFormat *)(&wxFormatInvalid);
	if (args.IsValid(0)) format = Object_wx_DataFormat::GetObject(args, 0)->GetEntity();
	wx_CustomDataObject *pEntity = new wx_CustomDataObject(*format);
	Object_wx_CustomDataObject *pObj = Object_wx_CustomDataObject::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CustomDataObject(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_CustomDataObject, Alloc)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CustomDataObject, Alloc)
{
	Object_wx_CustomDataObject *pThis = Object_wx_CustomDataObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t size = args.GetSizeT(0);
	pThis->GetEntity()->Alloc(size);
	return Value::Null;
}

Gura_DeclareMethod(wx_CustomDataObject, Free)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CustomDataObject, Free)
{
	Object_wx_CustomDataObject *pThis = Object_wx_CustomDataObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Free();
	return Value::Null;
}

Gura_DeclareMethod(wx_CustomDataObject, GetSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CustomDataObject, GetSize)
{
	Object_wx_CustomDataObject *pThis = Object_wx_CustomDataObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CustomDataObject, GetData)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CustomDataObject, GetData)
{
	Object_wx_CustomDataObject *pThis = Object_wx_CustomDataObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->GetData();
	return Value::Null;
}

Gura_DeclareMethod(wx_CustomDataObject, SetData)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*data", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_CustomDataObject, SetData)
{
#if 0
	Object_wx_CustomDataObject *pThis = Object_wx_CustomDataObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t size = args.GetSizeT(0);
	int *data = args.GetInt(1);
	pThis->GetEntity()->SetData(size, *data);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_CustomDataObject, TakeData)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*data", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_CustomDataObject, TakeData)
{
#if 0
	Object_wx_CustomDataObject *pThis = Object_wx_CustomDataObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t size = args.GetSizeT(0);
	int *data = args.GetInt(1);
	pThis->GetEntity()->TakeData(size, *data);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxCustomDataObject
//----------------------------------------------------------------------------
Object_wx_CustomDataObject::~Object_wx_CustomDataObject()
{
}

Object *Object_wx_CustomDataObject::Clone() const
{
	return NULL;
}

String Object_wx_CustomDataObject::ToString(bool exprFlag)
{
	String rtn("<wx.CustomDataObject:");
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
// Class implementation for wxCustomDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CustomDataObject)
{
	Gura_RealizeUserSymbol(Alloc);
	Gura_RealizeUserSymbol(Free);
	Gura_RealizeUserSymbol(GetSize);
	Gura_RealizeUserSymbol(GetData);
	Gura_RealizeUserSymbol(SetData);
	Gura_RealizeUserSymbol(TakeData);
	Gura_AssignFunction(CustomDataObject);
	Gura_AssignMethod(wx_CustomDataObject, Alloc);
	Gura_AssignMethod(wx_CustomDataObject, Free);
	Gura_AssignMethod(wx_CustomDataObject, GetSize);
	Gura_AssignMethod(wx_CustomDataObject, GetData);
	Gura_AssignMethod(wx_CustomDataObject, SetData);
	Gura_AssignMethod(wx_CustomDataObject, TakeData);
}

Gura_ImplementDescendantCreator(wx_CustomDataObject)
{
	return new Object_wx_CustomDataObject((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
