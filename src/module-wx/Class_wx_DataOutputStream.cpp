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
	Gura::Signal _sig;
	Object_wx_DataOutputStream *_pObj;
public:
	inline wx_DataOutputStream(wxOutputStream& stream) : wxDataOutputStream(stream), _sig(NULL), _pObj(NULL) {}
	//inline wx_DataOutputStream(wxOutputStream& stream, wxMBConv& conv) : wxDataOutputStream(stream, conv), _sig(NULL), _pObj(NULL) {}
	~wx_DataOutputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DataOutputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataOutputStream::~wx_DataOutputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DataOutputStream::GuraObjectDeleted()
{
	_pObj = NULL;
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wx_DataOutputStream *pEntity = new wx_DataOutputStream(*stream);
	Object_wx_DataOutputStream *pObj = Object_wx_DataOutputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DataOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wxMBConv *conv = (wxMBConv *)(&wxMBConvUTF8);
	if (args.IsValid(1)) conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	wx_DataOutputStream *pEntity = new wx_DataOutputStream(*stream, *conv);
	Object_wx_DataOutputStream *pObj = Object_wx_DataOutputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DataOutputStream(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_DataOutputStream, BigEndianOrdered)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "be_order", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, BigEndianOrdered)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool be_order = args.GetBoolean(0);
	pThis->GetEntity()->BigEndianOrdered(be_order);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataOutputStream, Write8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataOutputStream, Write8)
{
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Write8();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
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
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxUint8 buffer = static_cast<wxUint8>(args.GetUChar(0));
	size_t size = args.GetSizeT(1);
	pThis->GetEntity()->Write8(buffer, size);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataOutputStream, Write16)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataOutputStream, Write16)
{
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Write16();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
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
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxUint16 buffer = static_cast<wxUint16>(args.GetUShort(0));
	size_t size = args.GetSizeT(1);
	pThis->GetEntity()->Write16(buffer, size);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataOutputStream, Write32)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataOutputStream, Write32)
{
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Write32();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
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
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxUint32 buffer = static_cast<wxUint32>(args.GetULong(0));
	size_t size = args.GetSizeT(1);
	pThis->GetEntity()->Write32(buffer, size);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataOutputStream, Write64)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataOutputStream, Write64)
{
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Write64();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
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
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxUint64 *buffer = Object_wx_Uint64::GetObject(args, 0)->GetEntity();
	size_t size = args.GetSizeT(1);
	pThis->GetEntity()->Write64(buffer, size);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataOutputStream, WriteDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataOutputStream, WriteDouble)
{
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->WriteDouble();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
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
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double buffer = args.GetDouble(0);
	size_t size = args.GetSizeT(1);
	pThis->GetEntity()->WriteDouble(buffer, size);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataOutputStream, WriteString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataOutputStream, WriteString)
{
#if 0
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->WriteString();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDataOutputStream
//----------------------------------------------------------------------------
Object_wx_DataOutputStream::~Object_wx_DataOutputStream()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_DataOutputStream::Clone() const
{
	return NULL;
}

String Object_wx_DataOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.DataOutputStream:");
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
	return new Object_wx_DataOutputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
