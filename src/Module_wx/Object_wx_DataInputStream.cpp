//----------------------------------------------------------------------------
// wxDataInputStream
// extracted from datistrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataInputStream: public wxDataInputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DataInputStream *_pObj;
public:
	inline wx_DataInputStream(wxInputStream& stream) : wxDataInputStream(stream), _sig(NULL), _pObj(NULL) {}
	//inline wx_DataInputStream(wxInputStream& stream, wxMBConv& conv) : wxDataInputStream(stream, conv), _sig(NULL), _pObj(NULL) {}
	~wx_DataInputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DataInputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataInputStream::~wx_DataInputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DataInputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataInputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataInputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DataInputStream));
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataInputStream)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wx_DataInputStream *pEntity = new wx_DataInputStream(*stream);
	Object_wx_DataInputStream *pObj = Object_wx_DataInputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DataInputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(DataInputStream_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DataInputStream));
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(DataInputStream_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxMBConv *conv = (wxMBConv *)(&wxMBConvUTF8);
	if (args.IsValid(1)) conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	wx_DataInputStream *pEntity = new wx_DataInputStream(*stream, *conv);
	Object_wx_DataInputStream *pObj = Object_wx_DataInputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DataInputStream(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_DataInputStream, BigEndianOrdered)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "be_order", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataInputStream, BigEndianOrdered)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool be_order = args.GetBoolean(0);
	pThis->GetEntity()->BigEndianOrdered(be_order);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataInputStream, Read8)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataInputStream, Read8)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxUint8 rtn = pThis->GetEntity()->Read8();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataInputStream, Read8_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_DataInputStream, Read8_1)
{
#if 0
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxUint8 buffer = static_cast<wxUint8>(args.GetUChar(0));
	size_t size = args.GetSizeT(1);
	pThis->GetEntity()->Read8(buffer, size);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataInputStream, Read16)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataInputStream, Read16)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxUint16 rtn = pThis->GetEntity()->Read16();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataInputStream, Read16_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_DataInputStream, Read16_1)
{
#if 0
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxUint16 buffer = static_cast<wxUint16>(args.GetUShort(0));
	size_t size = args.GetSizeT(1);
	pThis->GetEntity()->Read16(buffer, size);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataInputStream, Read32)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataInputStream, Read32)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxUint32 rtn = pThis->GetEntity()->Read32();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataInputStream, Read32_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_DataInputStream, Read32_1)
{
#if 0
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxUint32 buffer = static_cast<wxUint32>(args.GetULong(0));
	size_t size = args.GetSizeT(1);
	pThis->GetEntity()->Read32(buffer, size);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataInputStream, Read64)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataInputStream, Read64)
{
#if 0
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxUint64 rtn = pThis->GetEntity()->Read64();
	return ReturnValue(env, sig, args, Value(new Object_wx_Uint64(new wxUint64(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataInputStream, Read64_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_wx_Uint64, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_DataInputStream, Read64_1)
{
#if 0
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxUint64 *buffer = Object_wx_Uint64::GetObject(args, 0)->GetEntity();
	size_t size = args.GetSizeT(1);
	pThis->GetEntity()->Read64(buffer, size);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataInputStream, ReadDouble)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataInputStream, ReadDouble)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double rtn = pThis->GetEntity()->ReadDouble();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataInputStream, ReadDouble_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_DataInputStream, ReadDouble_1)
{
#if 0
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double buffer = args.GetDouble(0);
	size_t size = args.GetSizeT(1);
	pThis->GetEntity()->ReadDouble(buffer, size);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataInputStream, ReadString)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataInputStream, ReadString)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->ReadString();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxDataInputStream
//----------------------------------------------------------------------------
Object_wx_DataInputStream::~Object_wx_DataInputStream()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_DataInputStream::Clone() const
{
	return NULL;
}

String Object_wx_DataInputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DataInputStream:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DataInputStream::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(DataInputStream);
	Gura_AssignFunction(DataInputStream_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxDataInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataInputStream)
{
	Gura_AssignMethod(wx_DataInputStream, BigEndianOrdered);
	Gura_AssignMethod(wx_DataInputStream, Read8);
	Gura_AssignMethod(wx_DataInputStream, Read8_1);
	Gura_AssignMethod(wx_DataInputStream, Read16);
	Gura_AssignMethod(wx_DataInputStream, Read16_1);
	Gura_AssignMethod(wx_DataInputStream, Read32);
	Gura_AssignMethod(wx_DataInputStream, Read32_1);
	Gura_AssignMethod(wx_DataInputStream, Read64);
	Gura_AssignMethod(wx_DataInputStream, Read64_1);
	Gura_AssignMethod(wx_DataInputStream, ReadDouble);
	Gura_AssignMethod(wx_DataInputStream, ReadDouble_1);
	Gura_AssignMethod(wx_DataInputStream, ReadString);
}

Gura_ImplementDescendantCreator(wx_DataInputStream)
{
	return new Object_wx_DataInputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
