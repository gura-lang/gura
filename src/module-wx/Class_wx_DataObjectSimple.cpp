//----------------------------------------------------------------------------
// wxDataObjectSimple
// extracted from dobjsmpl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(GetDataSize);
Gura_DeclarePrivUserSymbol(GetDataHere);
Gura_DeclarePrivUserSymbol(SetData);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataObjectSimple: public wxDataObjectSimple, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DataObjectSimple *_pObj;
public:
	inline wx_DataObjectSimple(const wxDataFormat& format) : wxDataObjectSimple(format), _pObj(nullptr) {}
	//virtual size_t GetDataSize();
	//virtual bool GetDataHere(void *buf);
	//virtual bool SetData(size_t len, const void *buf);
	~wx_DataObjectSimple();
	inline void AssocWithGura(Object_wx_DataObjectSimple *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataObjectSimple::~wx_DataObjectSimple()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DataObjectSimple::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataObjectSimple
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataObjectSimple)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DataObjectSimple));
	DeclareArg(env, "format", VTYPE_wx_DataFormat, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataObjectSimple)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxDataFormat *format = (wxDataFormat *)(&wxFormatInvalid);
	if (args.IsValid(0)) format = Object_wx_DataFormat::GetObject(args, 0)->GetEntity();
	wx_DataObjectSimple *pEntity = new wx_DataObjectSimple(*format);
	Object_wx_DataObjectSimple *pObj = Object_wx_DataObjectSimple::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataObjectSimple(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_DataObjectSimple, GetFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataObjectSimple, GetFormat)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataObjectSimple *pThis = Object_wx_DataObjectSimple::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxDataFormat &rtn = pThis->GetEntity()->GetFormat();
	return ReturnValue(env, args, Value(new Object_wx_DataFormat(new wxDataFormat(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DataObjectSimple, SetFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "format", VTYPE_wx_DataFormat, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataObjectSimple, SetFormat)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataObjectSimple *pThis = Object_wx_DataObjectSimple::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDataFormat *format = Object_wx_DataFormat::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetFormat(*format);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataObjectSimple, GetDataSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataObjectSimple, GetDataSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataObjectSimple *pThis = Object_wx_DataObjectSimple::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetDataSize();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataObjectSimple, GetDataHere)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*buf", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataObjectSimple, GetDataHere)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DataObjectSimple *pThis = Object_wx_DataObjectSimple::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int *buf = args.GetInt(0);
	bool rtn = pThis->GetEntity()->GetDataHere(*buf);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataObjectSimple, SetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*buf", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataObjectSimple, SetData)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DataObjectSimple *pThis = Object_wx_DataObjectSimple::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t len = args.GetSizeT(0);
	int *buf = args.GetInt(1);
	bool rtn = pThis->GetEntity()->SetData(len, *buf);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxDataObjectSimple
//----------------------------------------------------------------------------
Object_wx_DataObjectSimple::~Object_wx_DataObjectSimple()
{
}

Object *Object_wx_DataObjectSimple::Clone() const
{
	return nullptr;
}

String Object_wx_DataObjectSimple::ToString(bool exprFlag)
{
	String rtn("<wx.DataObjectSimple:");
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
// Class implementation for wxDataObjectSimple
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataObjectSimple)
{
	Gura_RealizeUserSymbol(GetDataSize);
	Gura_RealizeUserSymbol(GetDataHere);
	Gura_RealizeUserSymbol(SetData);
	Gura_AssignFunction(DataObjectSimple);
	Gura_AssignMethod(wx_DataObjectSimple, GetFormat);
	Gura_AssignMethod(wx_DataObjectSimple, SetFormat);
	Gura_AssignMethod(wx_DataObjectSimple, GetDataSize);
	Gura_AssignMethod(wx_DataObjectSimple, GetDataHere);
	Gura_AssignMethod(wx_DataObjectSimple, SetData);
}

Gura_ImplementDescendantCreator(wx_DataObjectSimple)
{
	return new Object_wx_DataObjectSimple((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
