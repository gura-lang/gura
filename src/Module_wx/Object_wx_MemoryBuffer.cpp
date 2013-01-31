//----------------------------------------------------------------------------
// wxMemoryBuffer
// extracted from membuf.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MemoryBuffer: public wxMemoryBuffer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MemoryBuffer *_pObj;
public:
	inline wx_MemoryBuffer(const wxMemoryBuffer& src) : wxMemoryBuffer(src), _sig(NULL), _pObj(NULL) {}
	inline wx_MemoryBuffer(size_t size) : wxMemoryBuffer(size), _sig(NULL), _pObj(NULL) {}
	~wx_MemoryBuffer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MemoryBuffer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MemoryBuffer::~wx_MemoryBuffer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MemoryBuffer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryBuffer
//----------------------------------------------------------------------------
Gura_DeclareFunction(MemoryBuffer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MemoryBuffer));
	DeclareArg(env, "src", VTYPE_wx_MemoryBuffer, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MemoryBuffer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxMemoryBuffer *src = Object_wx_MemoryBuffer::GetObject(args, 0)->GetEntity();
	wx_MemoryBuffer *pEntity = new wx_MemoryBuffer(*src);
	Object_wx_MemoryBuffer *pObj = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MemoryBuffer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(MemoryBuffer_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MemoryBuffer));
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MemoryBuffer_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	size_t size = args.GetSizeT(0);
	wx_MemoryBuffer *pEntity = new wx_MemoryBuffer(size);
	Object_wx_MemoryBuffer *pObj = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MemoryBuffer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_MemoryBuffer, GetData)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MemoryBuffer, GetData)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->GetData();
	return Value::Null;
}

Gura_DeclareMethod(wx_MemoryBuffer, GetBufSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MemoryBuffer, GetBufSize)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetBufSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MemoryBuffer, GetDataLen)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MemoryBuffer, GetDataLen)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetDataLen();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MemoryBuffer, SetBufSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, SetBufSize)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t size = args.GetSizeT(0);
	pThis->GetEntity()->SetBufSize(size);
	return Value::Null;
}

Gura_DeclareMethod(wx_MemoryBuffer, SetDataLen)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, SetDataLen)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t size = args.GetSizeT(0);
	pThis->GetEntity()->SetDataLen(size);
	return Value::Null;
}

Gura_DeclareMethod(wx_MemoryBuffer, GetWriteBuf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sizeNeeded", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, GetWriteBuf)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t sizeNeeded = args.GetSizeT(0);
	pThis->GetEntity()->GetWriteBuf(sizeNeeded);
	return Value::Null;
}

Gura_DeclareMethod(wx_MemoryBuffer, UngetWriteBuf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sizeUsed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, UngetWriteBuf)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t sizeUsed = args.GetSizeT(0);
	pThis->GetEntity()->UngetWriteBuf(sizeUsed);
	return Value::Null;
}

Gura_DeclareMethod(wx_MemoryBuffer, GetAppendBuf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sizeNeeded", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, GetAppendBuf)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t sizeNeeded = args.GetSizeT(0);
	pThis->GetEntity()->GetAppendBuf(sizeNeeded);
	return Value::Null;
}

Gura_DeclareMethod(wx_MemoryBuffer, UngetAppendBuf)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sizeUsed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, UngetAppendBuf)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t sizeUsed = args.GetSizeT(0);
	pThis->GetEntity()->UngetAppendBuf(sizeUsed);
	return Value::Null;
}

Gura_DeclareMethod(wx_MemoryBuffer, AppendByte)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, AppendByte)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char data = args.GetChar(0);
	pThis->GetEntity()->AppendByte(data);
	return Value::Null;
}

Gura_DeclareMethod(wx_MemoryBuffer, AppendData)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_MemoryBuffer, AppendData)
{
#if 0
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int data = args.GetInt(0);
	size_t len = args.GetSizeT(1);
	pThis->GetEntity()->AppendData(data, len);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxMemoryBuffer
//----------------------------------------------------------------------------
Object_wx_MemoryBuffer::~Object_wx_MemoryBuffer()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_MemoryBuffer::Clone() const
{
	return NULL;
}

String Object_wx_MemoryBuffer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.MemoryBuffer:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_MemoryBuffer::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(MemoryBuffer);
	Gura_AssignFunction(MemoryBuffer_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxMemoryBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryBuffer)
{
	Gura_AssignMethod(wx_MemoryBuffer, GetData);
	Gura_AssignMethod(wx_MemoryBuffer, GetBufSize);
	Gura_AssignMethod(wx_MemoryBuffer, GetDataLen);
	Gura_AssignMethod(wx_MemoryBuffer, SetBufSize);
	Gura_AssignMethod(wx_MemoryBuffer, SetDataLen);
	Gura_AssignMethod(wx_MemoryBuffer, GetWriteBuf);
	Gura_AssignMethod(wx_MemoryBuffer, UngetWriteBuf);
	Gura_AssignMethod(wx_MemoryBuffer, GetAppendBuf);
	Gura_AssignMethod(wx_MemoryBuffer, UngetAppendBuf);
	Gura_AssignMethod(wx_MemoryBuffer, AppendByte);
	Gura_AssignMethod(wx_MemoryBuffer, AppendData);
}

Gura_ImplementDescendantCreator(wx_MemoryBuffer)
{
	return new Object_wx_MemoryBuffer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
