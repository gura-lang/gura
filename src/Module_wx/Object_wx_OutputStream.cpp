//----------------------------------------------------------------------------
// wxOutputStream
// extracted from outptstr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_OutputStream: public wxOutputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_OutputStream *_pObj;
public:
	//inline wx_OutputStream() : wxOutputStream(), _sig(NULL), _pObj(NULL) {}
	~wx_OutputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_OutputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_OutputStream::~wx_OutputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_OutputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(OutputStreamEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_OutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(OutputStreamEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_OutputStream *pEntity = new wx_OutputStream();
	Object_wx_OutputStream *pObj = Object_wx_OutputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_OutputStream(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_OutputStream, Close)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_OutputStream, Close)
{
#if 0
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Close();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_OutputStream, LastWrite)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_OutputStream, LastWrite)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->LastWrite();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_OutputStream, PutC)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_OutputStream, PutC)
{
#if 0
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char c = args.GetChar(0);
	pThis->GetEntity()->PutC(c);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_OutputStream, SeekO)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_OutputStream, SeekO)
{
#if 0
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	off_t pos = static_cast<off_t>(args.GetLong(0));
	wxSeekMode mode = wxFromStart;
	if (args.IsValid(1)) mode = static_cast<wxSeekMode>(args.GetInt(1));
	off_t rtn = pThis->GetEntity()->SeekO(pos, mode);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_OutputStream, TellO)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_OutputStream, TellO)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	off_t rtn = pThis->GetEntity()->TellO();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_OutputStream, Write)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_OutputStream, Write)
{
#if 0
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int buffer = args.GetInt(0);
	size_t size = args.GetSizeT(1);
	wxOutputStream &rtn = pThis->GetEntity()->Write(buffer, size);
	return ReturnValue(env, sig, args, Value(new Object_wx_OutputStream(new wxOutputStream(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_OutputStream, Write_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "stream_in", VTYPE_wx_InputStream, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_OutputStream, Write_1)
{
#if 0
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxInputStream *stream_in = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxOutputStream &rtn = pThis->GetEntity()->Write(*stream_in);
	return ReturnValue(env, sig, args, Value(new Object_wx_OutputStream(new wxOutputStream(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxOutputStream
//----------------------------------------------------------------------------
Object_wx_OutputStream::~Object_wx_OutputStream()
{
}

Object *Object_wx_OutputStream::Clone() const
{
	return NULL;
}

String Object_wx_OutputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.OutputStream:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_OutputStream::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(OutputStreamEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_OutputStream)
{
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
	return new Object_wx_OutputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
