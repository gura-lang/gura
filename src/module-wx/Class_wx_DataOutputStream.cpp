//----------------------------------------------------------------------------
// wxDataOutputStream
// extracted from datostrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataOutputStream: public wxDataOutputStream, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DataOutputStream *_pObj;
public:
	inline wx_DataOutputStream(wxOutputStream& stream) : wxDataOutputStream(stream), _pObj(nullptr) {}
	//inline wx_DataOutputStream(wxOutputStream& stream, wxMBConv& conv) : wxDataOutputStream(stream, conv), _pObj(nullptr) {}
	~wx_DataOutputStream();
	inline void AssocWithGura(Object_wx_DataOutputStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataOutputStream::~wx_DataOutputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DataOutputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DataOutputStream));
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataOutputStream)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wx_DataOutputStream *pEntity = new wx_DataOutputStream(*stream);
	Object_wx_DataOutputStream *pObj = Object_wx_DataOutputStream::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(DataOutputStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DataOutputStream));
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(DataOutputStream_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wxMBConv *conv = (wxMBConv *)(&wxMBConvUTF8);
	if (args.IsValid(1)) conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	wx_DataOutputStream *pEntity = new wx_DataOutputStream(*stream, *conv);
	Object_wx_DataOutputStream *pObj = Object_wx_DataOutputStream::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, BigEndianOrdered)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "be_order", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, BigEndianOrdered)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool be_order = args.GetBoolean(0);
	pThis->GetEntity()->BigEndianOrdered(be_order);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, Write8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataOutputStream, Write8)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Write8();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, Write8_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_DataOutputStream, Write8_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxUint8 buffer = static_cast<wxUint8>(args.GetUChar(0));
	size_t size = args.GetSizeT(1);
	pThis->GetEntity()->Write8(buffer, size);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, Write16)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataOutputStream, Write16)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Write16();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, Write16_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_DataOutputStream, Write16_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxUint16 buffer = static_cast<wxUint16>(args.GetUShort(0));
	size_t size = args.GetSizeT(1);
	pThis->GetEntity()->Write16(buffer, size);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, Write32)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataOutputStream, Write32)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Write32();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, Write32_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_DataOutputStream, Write32_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxUint32 buffer = static_cast<wxUint32>(args.GetULong(0));
	size_t size = args.GetSizeT(1);
	pThis->GetEntity()->Write32(buffer, size);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, Write64)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataOutputStream, Write64)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Write64();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, Write64_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_wx_Uint64, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_DataOutputStream, Write64_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxUint64 *buffer = Object_wx_Uint64::GetObject(args, 0)->GetEntity();
	size_t size = args.GetSizeT(1);
	pThis->GetEntity()->Write64(buffer, size);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, WriteDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataOutputStream, WriteDouble)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->WriteDouble();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, WriteDouble_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_DataOutputStream, WriteDouble_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	double buffer = args.GetDouble(0);
	size_t size = args.GetSizeT(1);
	pThis->GetEntity()->WriteDouble(buffer, size);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, WriteString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataOutputStream, WriteString)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->WriteString();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxDataOutputStream
//----------------------------------------------------------------------------
Object_wx_DataOutputStream::~Object_wx_DataOutputStream()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_DataOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_DataOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.DataOutputStream:");
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
// Class implementation for wxDataOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataOutputStream)
{
	Gura_AssignFunction(DataOutputStream);
	Gura_AssignFunction(DataOutputStream_1);
	Gura_AssignMethod(wx_DataOutputStream, BigEndianOrdered);
	Gura_AssignMethod(wx_DataOutputStream, Write8);
	Gura_AssignMethod(wx_DataOutputStream, Write8_1);
	Gura_AssignMethod(wx_DataOutputStream, Write16);
	Gura_AssignMethod(wx_DataOutputStream, Write16_1);
	Gura_AssignMethod(wx_DataOutputStream, Write32);
	Gura_AssignMethod(wx_DataOutputStream, Write32_1);
	Gura_AssignMethod(wx_DataOutputStream, Write64);
	Gura_AssignMethod(wx_DataOutputStream, Write64_1);
	Gura_AssignMethod(wx_DataOutputStream, WriteDouble);
	Gura_AssignMethod(wx_DataOutputStream, WriteDouble_1);
	Gura_AssignMethod(wx_DataOutputStream, WriteString);
}

Gura_ImplementDescendantCreator(wx_DataOutputStream)
{
	return new Object_wx_DataOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
