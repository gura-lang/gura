//----------------------------------------------------------------------------
// wxStreamBuffer
// extracted from stream.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StreamBuffer: public wxStreamBuffer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_StreamBuffer *_pObj;
public:
	inline wx_StreamBuffer(wxStreamBase& stream, BufMode mode) : wxStreamBuffer(stream, mode), _sig(NULL), _pObj(NULL) {}
	inline wx_StreamBuffer(BufMode mode) : wxStreamBuffer(mode), _sig(NULL), _pObj(NULL) {}
	inline wx_StreamBuffer(const wxStreamBuffer& buffer) : wxStreamBuffer(buffer), _sig(NULL), _pObj(NULL) {}
	//inline wx_StreamBuffer() : wxStreamBuffer(), _sig(NULL), _pObj(NULL) {}
	~wx_StreamBuffer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_StreamBuffer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StreamBuffer::~wx_StreamBuffer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_StreamBuffer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStreamBuffer
//----------------------------------------------------------------------------
Gura_DeclareFunction(StreamBuffer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StreamBuffer));
	DeclareArg(env, "stream", VTYPE_wx_StreamBase, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StreamBuffer)
{
	wxStreamBase *stream = Object_wx_StreamBase::GetObject(args, 0)->GetEntity();
	wxStreamBuffer::BufMode mode = static_cast<wxStreamBuffer::BufMode>(args.GetInt(1));
	wx_StreamBuffer *pEntity = new wx_StreamBuffer(*stream, mode);
	Object_wx_StreamBuffer *pObj = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StreamBuffer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(StreamBuffer_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StreamBuffer));
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StreamBuffer_1)
{
	wxStreamBuffer::BufMode mode = static_cast<wxStreamBuffer::BufMode>(args.GetInt(0));
	wx_StreamBuffer *pEntity = new wx_StreamBuffer(mode);
	Object_wx_StreamBuffer *pObj = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StreamBuffer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(StreamBuffer_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StreamBuffer));
	DeclareArg(env, "buffer", VTYPE_wx_StreamBuffer, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StreamBuffer_2)
{
	wxStreamBuffer *buffer = Object_wx_StreamBuffer::GetObject(args, 0)->GetEntity();
	wx_StreamBuffer *pEntity = new wx_StreamBuffer(*buffer);
	Object_wx_StreamBuffer *pObj = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StreamBuffer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(StreamBufferEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_StreamBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(StreamBufferEmpty)
{
#if 0
	wx_StreamBuffer *pEntity = new wx_StreamBuffer();
	Object_wx_StreamBuffer *pObj = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StreamBuffer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_StreamBuffer, Read)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBuffer, Read)
{
#if 0
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int buffer = args.GetInt(0);
	size_t size = args.GetSizeT(1);
	size_t rtn = pSelf->GetEntity()->Read(buffer, size);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_StreamBuffer, Read_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buffer", VTYPE_wx_StreamBuffer, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBuffer, Read_1)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxStreamBuffer *buffer = Object_wx_StreamBuffer::GetObject(args, 0)->GetEntity();
	size_t rtn = pSelf->GetEntity()->Read(buffer);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StreamBuffer, Write)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBuffer, Write)
{
#if 0
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int buffer = args.GetInt(0);
	size_t size = args.GetSizeT(1);
	size_t rtn = pSelf->GetEntity()->Write(buffer, size);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_StreamBuffer, Write_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buffer", VTYPE_wx_StreamBuffer, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBuffer, Write_1)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxStreamBuffer *buffer = Object_wx_StreamBuffer::GetObject(args, 0)->GetEntity();
	size_t rtn = pSelf->GetEntity()->Write(buffer);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StreamBuffer, GetChar)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBuffer, GetChar)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	char rtn = pSelf->GetEntity()->GetChar();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StreamBuffer, PutChar)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StreamBuffer, PutChar)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	char c = args.GetChar(0);
	pSelf->GetEntity()->PutChar(c);
	return Value::Null;
}

Gura_DeclareMethod(wx_StreamBuffer, Tell)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBuffer, Tell)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	off_t rtn = pSelf->GetEntity()->Tell();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StreamBuffer, Seek)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBuffer, Seek)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	off_t pos = static_cast<off_t>(args.GetLong(0));
	wxSeekMode mode = static_cast<wxSeekMode>(args.GetInt(1));
	off_t rtn = pSelf->GetEntity()->Seek(pos, mode);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StreamBuffer, ResetBuffer)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StreamBuffer, ResetBuffer)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->ResetBuffer();
	return Value::Null;
}

Gura_DeclareMethod(wx_StreamBuffer, SetBufferIO)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "buffer_start", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "buffer_end", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_StreamBuffer, SetBufferIO)
{
#if 0
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	char buffer_start = args.GetChar(0);
	char buffer_end = args.GetChar(1);
	pSelf->GetEntity()->SetBufferIO(buffer_start, buffer_end);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_StreamBuffer, SetBufferIO_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bufsize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StreamBuffer, SetBufferIO_1)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t bufsize = args.GetSizeT(0);
	pSelf->GetEntity()->SetBufferIO(bufsize);
	return Value::Null;
}

Gura_DeclareMethod(wx_StreamBuffer, GetBufferStart)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StreamBuffer, GetBufferStart)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->GetBufferStart();
	return Value::Null;
}

Gura_DeclareMethod(wx_StreamBuffer, GetBufferEnd)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StreamBuffer, GetBufferEnd)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->GetBufferEnd();
	return Value::Null;
}

Gura_DeclareMethod(wx_StreamBuffer, GetBufferPos)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StreamBuffer, GetBufferPos)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->GetBufferPos();
	return Value::Null;
}

Gura_DeclareMethod(wx_StreamBuffer, GetIntPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBuffer, GetIntPosition)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	off_t rtn = pSelf->GetEntity()->GetIntPosition();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StreamBuffer, SetIntPosition)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StreamBuffer, SetIntPosition)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t pos = args.GetSizeT(0);
	pSelf->GetEntity()->SetIntPosition(pos);
	return Value::Null;
}

Gura_DeclareMethod(wx_StreamBuffer, GetLastAccess)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBuffer, GetLastAccess)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t rtn = pSelf->GetEntity()->GetLastAccess();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StreamBuffer, Fixed)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "fixed", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_StreamBuffer, Fixed)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool fixed = args.GetBoolean(0);
	pSelf->GetEntity()->Fixed(fixed);
	return Value::Null;
}

Gura_DeclareMethod(wx_StreamBuffer, Flushable)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flushable", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_StreamBuffer, Flushable)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool flushable = args.GetBoolean(0);
	pSelf->GetEntity()->Flushable(flushable);
	return Value::Null;
}

Gura_DeclareMethod(wx_StreamBuffer, FlushBuffer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBuffer, FlushBuffer)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->FlushBuffer();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StreamBuffer, FillBuffer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBuffer, FillBuffer)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->FillBuffer();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StreamBuffer, GetDataLeft)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBuffer, GetDataLeft)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t rtn = pSelf->GetEntity()->GetDataLeft();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StreamBuffer, Stream)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StreamBuffer, Stream)
{
	Object_wx_StreamBuffer *pSelf = Object_wx_StreamBuffer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxStreamBase *rtn = (wxStreamBase *)pSelf->GetEntity()->Stream();
	return ReturnValue(env, sig, args, Value(new Object_wx_StreamBase(rtn, NULL, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxStreamBuffer
//----------------------------------------------------------------------------
Object_wx_StreamBuffer::~Object_wx_StreamBuffer()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_StreamBuffer::Clone() const
{
	return NULL;
}

String Object_wx_StreamBuffer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.StreamBuffer:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_StreamBuffer::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(StreamBuffer);
	Gura_AssignFunction(StreamBuffer_1);
	Gura_AssignFunction(StreamBuffer_2);
	Gura_AssignFunction(StreamBufferEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxStreamBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StreamBuffer)
{
	Gura_AssignMethod(wx_StreamBuffer, Read);
	Gura_AssignMethod(wx_StreamBuffer, Read_1);
	Gura_AssignMethod(wx_StreamBuffer, Write);
	Gura_AssignMethod(wx_StreamBuffer, Write_1);
	Gura_AssignMethod(wx_StreamBuffer, GetChar);
	Gura_AssignMethod(wx_StreamBuffer, PutChar);
	Gura_AssignMethod(wx_StreamBuffer, Tell);
	Gura_AssignMethod(wx_StreamBuffer, Seek);
	Gura_AssignMethod(wx_StreamBuffer, ResetBuffer);
	Gura_AssignMethod(wx_StreamBuffer, SetBufferIO);
	Gura_AssignMethod(wx_StreamBuffer, SetBufferIO_1);
	Gura_AssignMethod(wx_StreamBuffer, GetBufferStart);
	Gura_AssignMethod(wx_StreamBuffer, GetBufferEnd);
	Gura_AssignMethod(wx_StreamBuffer, GetBufferPos);
	Gura_AssignMethod(wx_StreamBuffer, GetIntPosition);
	Gura_AssignMethod(wx_StreamBuffer, SetIntPosition);
	Gura_AssignMethod(wx_StreamBuffer, GetLastAccess);
	Gura_AssignMethod(wx_StreamBuffer, Fixed);
	Gura_AssignMethod(wx_StreamBuffer, Flushable);
	Gura_AssignMethod(wx_StreamBuffer, FlushBuffer);
	Gura_AssignMethod(wx_StreamBuffer, FillBuffer);
	Gura_AssignMethod(wx_StreamBuffer, GetDataLeft);
	Gura_AssignMethod(wx_StreamBuffer, Stream);
}

Gura_ImplementDescendantCreator(wx_StreamBuffer)
{
	return new Object_wx_StreamBuffer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
