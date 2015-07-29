//----------------------------------------------------------------------------
// wxInputStream
// extracted from inputstr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_InputStream: public wxInputStream, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_InputStream *_pObj;
public:
	//inline wx_InputStream() : wxInputStream(), _pObj(nullptr) {}
	~wx_InputStream();
	inline void AssocWithGura(Object_wx_InputStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_InputStream::~wx_InputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_InputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxInputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(InputStreamEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_InputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(InputStreamEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_InputStream *pEntity = new wx_InputStream();
	Object_wx_InputStream *pObj = Object_wx_InputStream::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_InputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_InputStream, CanRead)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_InputStream, CanRead)
{
	Signal &sig = env.GetSignal();
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CanRead();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_InputStream, GetC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_InputStream, GetC)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char rtn = pThis->GetEntity()->GetC();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_InputStream, Eof)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_InputStream, Eof)
{
	Signal &sig = env.GetSignal();
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Eof();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_InputStream, LastRead)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_InputStream, LastRead)
{
	Signal &sig = env.GetSignal();
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->LastRead();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_InputStream, Peek)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_InputStream, Peek)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char rtn = pThis->GetEntity()->Peek();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_InputStream, Read)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_InputStream, Read)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int buffer = args.GetInt(0);
	size_t size = args.GetSizeT(1);
	wxInputStream &rtn = pThis->GetEntity()->Read(buffer, size);
	return ReturnValue(env, args, Value(new Object_wx_InputStream(new wxInputStream(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_InputStream, Read_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "stream_out", VTYPE_wx_OutputStream, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_InputStream, Read_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxOutputStream *stream_out = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wxInputStream &rtn = pThis->GetEntity()->Read(*stream_out);
	return ReturnValue(env, args, Value(new Object_wx_InputStream(new wxInputStream(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_InputStream, SeekI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_InputStream, SeekI)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	off_t pos = static_cast<off_t>(args.GetLong(0));
	wxSeekMode mode = wxFromStart;
	if (args.IsValid(1)) mode = static_cast<wxSeekMode>(args.GetInt(1));
	off_t rtn = pThis->GetEntity()->SeekI(pos, mode);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_InputStream, TellI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_InputStream, TellI)
{
	Signal &sig = env.GetSignal();
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	off_t rtn = pThis->GetEntity()->TellI();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_InputStream, Ungetch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_InputStream, Ungetch)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char buffer = args.GetChar(0);
	size_t size = args.GetSizeT(1);
	size_t rtn = pThis->GetEntity()->Ungetch(buffer, size);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_InputStream, Ungetch_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_InputStream, Ungetch_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char c = args.GetChar(0);
	bool rtn = pThis->GetEntity()->Ungetch(c);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxInputStream
//----------------------------------------------------------------------------
Object_wx_InputStream::~Object_wx_InputStream()
{
}

Object *Object_wx_InputStream::Clone() const
{
	return nullptr;
}

String Object_wx_InputStream::ToString(bool exprFlag)
{
	String rtn("<wx.InputStream:");
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
// Class implementation for wxInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_InputStream)
{
	Gura_AssignFunction(InputStreamEmpty);
	Gura_AssignMethod(wx_InputStream, CanRead);
	Gura_AssignMethod(wx_InputStream, GetC);
	Gura_AssignMethod(wx_InputStream, Eof);
	Gura_AssignMethod(wx_InputStream, LastRead);
	Gura_AssignMethod(wx_InputStream, Peek);
	Gura_AssignMethod(wx_InputStream, Read);
	Gura_AssignMethod(wx_InputStream, Read_1);
	Gura_AssignMethod(wx_InputStream, SeekI);
	Gura_AssignMethod(wx_InputStream, TellI);
	Gura_AssignMethod(wx_InputStream, Ungetch);
	Gura_AssignMethod(wx_InputStream, Ungetch_1);
}

Gura_ImplementDescendantCreator(wx_InputStream)
{
	return new Object_wx_InputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
