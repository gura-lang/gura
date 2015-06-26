//----------------------------------------------------------------------------
// wxTextOutputStream
// extracted from txtstrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(WriteDouble);
Gura_DeclarePrivUserSymbol(WriteString);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TextOutputStream: public wxTextOutputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TextOutputStream *_pObj;
public:
	//inline wx_TextOutputStream(wxOutputStream& stream, wxEOL mode, wxMBConv& conv) : wxTextOutputStream(stream, mode, conv), _sig(nullptr), _pObj(nullptr) {}
	//virtual void WriteDouble();
	//virtual void WriteString();
	~wx_TextOutputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TextOutputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TextOutputStream::~wx_TextOutputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TextOutputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTextOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(TextOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_TextOutputStream));
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(TextOutputStream)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wxEOL mode = wxEOL_NATIVE;
	if (args.IsValid(1)) mode = static_cast<wxEOL>(args.GetInt(1));
	wxMBConv *conv = (wxMBConv *)(&wxConvUTF8);
	if (args.IsValid(2)) conv = Object_wx_MBConv::GetObject(args, 2)->GetEntity();
	wx_TextOutputStream *pEntity = new wx_TextOutputStream(*stream, mode, *conv);
	Object_wx_TextOutputStream *pObj = Object_wx_TextOutputStream::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TextOutputStream(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_TextOutputStream, GetMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextOutputStream, GetMode)
{
#if 0
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEOL rtn = pThis->GetEntity()->GetMode();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextOutputStream, PutChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextOutputStream, PutChar)
{
#if 0
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->PutChar();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethodAlias(wx_TextOutputStream, SetMode_, "SetMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextOutputStream, SetMode_)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->SetMode();
	return Value::Null;
}

Gura_DeclareMethod(wx_TextOutputStream, Write8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextOutputStream, Write8)
{
#if 0
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Write8();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextOutputStream, Write16)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextOutputStream, Write16)
{
#if 0
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Write16();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextOutputStream, Write32)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextOutputStream, Write32)
{
#if 0
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Write32();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextOutputStream, WriteDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextOutputStream, WriteDouble)
{
#if 0
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->WriteDouble();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextOutputStream, WriteString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextOutputStream, WriteString)
{
#if 0
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->WriteString();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxTextOutputStream
//----------------------------------------------------------------------------
Object_wx_TextOutputStream::~Object_wx_TextOutputStream()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_TextOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_TextOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.TextOutputStream:");
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
// Class implementation for wxTextOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextOutputStream)
{
	Gura_RealizeUserSymbol(WriteDouble);
	Gura_RealizeUserSymbol(WriteString);
	Gura_AssignFunction(TextOutputStream);
	Gura_AssignMethod(wx_TextOutputStream, GetMode);
	Gura_AssignMethod(wx_TextOutputStream, PutChar);
	Gura_AssignMethod(wx_TextOutputStream, SetMode_);
	Gura_AssignMethod(wx_TextOutputStream, Write8);
	Gura_AssignMethod(wx_TextOutputStream, Write16);
	Gura_AssignMethod(wx_TextOutputStream, Write32);
	Gura_AssignMethod(wx_TextOutputStream, WriteDouble);
	Gura_AssignMethod(wx_TextOutputStream, WriteString);
}

Gura_ImplementDescendantCreator(wx_TextOutputStream)
{
	return new Object_wx_TextOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
