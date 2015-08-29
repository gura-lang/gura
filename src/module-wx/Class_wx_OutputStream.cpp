//----------------------------------------------------------------------------
// wxOutputStream
// extracted from outptstr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_OutputStream: public wxOutputStream, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_OutputStream *_pObj;
public:
	//inline wx_OutputStream() : wxOutputStream(), _pObj(nullptr) {}
	~wx_OutputStream();
	inline void AssocWithGura(Object_wx_OutputStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_OutputStream::~wx_OutputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_OutputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(OutputStreamEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_OutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(OutputStreamEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_OutputStream *pEntity = new wx_OutputStream();
	Object_wx_OutputStream *pObj = Object_wx_OutputStream::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_OutputStream(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_OutputStream, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_OutputStream, Close)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Close();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_OutputStream, LastWrite)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_OutputStream, LastWrite)
{
	Signal &sig = env.GetSignal();
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->LastWrite();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_OutputStream, PutC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_OutputStream, PutC)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	char c = arg.GetChar(0);
	pThis->GetEntity()->PutC(c);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_OutputStream, SeekO)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_OutputStream, SeekO)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	off_t pos = static_cast<off_t>(arg.GetLong(0));
	wxSeekMode mode = wxFromStart;
	if (arg.IsValid(1)) mode = static_cast<wxSeekMode>(arg.GetInt(1));
	off_t rtn = pThis->GetEntity()->SeekO(pos, mode);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_OutputStream, TellO)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_OutputStream, TellO)
{
	Signal &sig = env.GetSignal();
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	off_t rtn = pThis->GetEntity()->TellO();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_OutputStream, Write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_OutputStream, Write)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int buffer = arg.GetInt(0);
	size_t size = arg.GetSizeT(1);
	wxOutputStream &rtn = pThis->GetEntity()->Write(buffer, size);
	return ReturnValue(env, arg, Value(new Object_wx_OutputStream(new wxOutputStream(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_OutputStream, Write_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "stream_in", VTYPE_wx_InputStream, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_OutputStream, Write_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxInputStream *stream_in = Object_wx_InputStream::GetObject(arg, 0)->GetEntity();
	wxOutputStream &rtn = pThis->GetEntity()->Write(*stream_in);
	return ReturnValue(env, arg, Value(new Object_wx_OutputStream(new wxOutputStream(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxOutputStream
//----------------------------------------------------------------------------
Object_wx_OutputStream::~Object_wx_OutputStream()
{
}

Object *Object_wx_OutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_OutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.OutputStream:");
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
// Class implementation for wxOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_OutputStream)
{
	Gura_AssignFunction(OutputStreamEmpty);
	Gura_AssignMethod(wx_OutputStream, Close);
	Gura_AssignMethod(wx_OutputStream, LastWrite);
	Gura_AssignMethod(wx_OutputStream, PutC);
	Gura_AssignMethod(wx_OutputStream, SeekO);
	Gura_AssignMethod(wx_OutputStream, TellO);
	Gura_AssignMethod(wx_OutputStream, Write);
	Gura_AssignMethod(wx_OutputStream, Write_1);
}

Gura_ImplementDescendantCreator(wx_OutputStream)
{
	return new Object_wx_OutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
