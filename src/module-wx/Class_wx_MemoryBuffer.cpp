//----------------------------------------------------------------------------
// wxMemoryBuffer
// extracted from membuf.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MemoryBuffer: public wxMemoryBuffer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MemoryBuffer *_pObj;
public:
	inline wx_MemoryBuffer(const wxMemoryBuffer& src) : wxMemoryBuffer(src), _pObj(nullptr) {}
	inline wx_MemoryBuffer(size_t size) : wxMemoryBuffer(size), _pObj(nullptr) {}
	~wx_MemoryBuffer();
	inline void AssocWithGura(Object_wx_MemoryBuffer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MemoryBuffer::~wx_MemoryBuffer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MemoryBuffer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryBuffer
//----------------------------------------------------------------------------
Gura_DeclareFunction(MemoryBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MemoryBuffer));
	DeclareArg(env, "src", VTYPE_wx_MemoryBuffer, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MemoryBuffer)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxMemoryBuffer *src = Object_wx_MemoryBuffer::GetObject(args, 0)->GetEntity();
	wx_MemoryBuffer *pEntity = new wx_MemoryBuffer(*src);
	Object_wx_MemoryBuffer *pObj = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_MemoryBuffer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(MemoryBuffer_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MemoryBuffer));
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MemoryBuffer_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	size_t size = args.GetSizeT(0);
	wx_MemoryBuffer *pEntity = new wx_MemoryBuffer(size);
	Object_wx_MemoryBuffer *pObj = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_MemoryBuffer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_MemoryBuffer, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MemoryBuffer, GetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, GetBufSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MemoryBuffer, GetBufSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetBufSize();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_MemoryBuffer, GetDataLen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MemoryBuffer, GetDataLen)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetDataLen();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_MemoryBuffer, SetBufSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, SetBufSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t size = args.GetSizeT(0);
	pThis->GetEntity()->SetBufSize(size);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, SetDataLen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, SetDataLen)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t size = args.GetSizeT(0);
	pThis->GetEntity()->SetDataLen(size);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, GetWriteBuf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sizeNeeded", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, GetWriteBuf)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t sizeNeeded = args.GetSizeT(0);
	pThis->GetEntity()->GetWriteBuf(sizeNeeded);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, UngetWriteBuf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sizeUsed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, UngetWriteBuf)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t sizeUsed = args.GetSizeT(0);
	pThis->GetEntity()->UngetWriteBuf(sizeUsed);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, GetAppendBuf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sizeNeeded", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, GetAppendBuf)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t sizeNeeded = args.GetSizeT(0);
	pThis->GetEntity()->GetAppendBuf(sizeNeeded);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, UngetAppendBuf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sizeUsed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, UngetAppendBuf)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t sizeUsed = args.GetSizeT(0);
	pThis->GetEntity()->UngetAppendBuf(sizeUsed);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, AppendByte)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, AppendByte)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	char data = args.GetChar(0);
	pThis->GetEntity()->AppendByte(data);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, AppendData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_MemoryBuffer, AppendData)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int data = args.GetInt(0);
	size_t len = args.GetSizeT(1);
	pThis->GetEntity()->AppendData(data, len);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxMemoryBuffer
//----------------------------------------------------------------------------
Object_wx_MemoryBuffer::~Object_wx_MemoryBuffer()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_MemoryBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_MemoryBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.MemoryBuffer:");
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
// Class implementation for wxMemoryBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryBuffer)
{
	Gura_AssignFunction(MemoryBuffer);
	Gura_AssignFunction(MemoryBuffer_1);
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
	return new Object_wx_MemoryBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
