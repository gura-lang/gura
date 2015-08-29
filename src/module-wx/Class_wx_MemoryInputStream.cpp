//----------------------------------------------------------------------------
// wxMemoryInputStream
// extracted from strmmem.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MemoryInputStream: public wxMemoryInputStream, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MemoryInputStream *_pObj;
public:
	//inline wx_MemoryInputStream(const char * data, size_t len) : wxMemoryInputStream(data, len), _pObj(nullptr) {}
	inline wx_MemoryInputStream(const wxMemoryOutputStream& stream) : wxMemoryInputStream(stream), _pObj(nullptr) {}
	~wx_MemoryInputStream();
	inline void AssocWithGura(Object_wx_MemoryInputStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MemoryInputStream::~wx_MemoryInputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MemoryInputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryInputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(MemoryInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_MemoryInputStream));
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(MemoryInputStream)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	char data = arg.GetChar(0);
	size_t len = arg.GetSizeT(1);
	wx_MemoryInputStream *pEntity = new wx_MemoryInputStream(data, len);
	Object_wx_MemoryInputStream *pObj = Object_wx_MemoryInputStream::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_MemoryInputStream(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareFunction(MemoryInputStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MemoryInputStream));
	DeclareArg(env, "stream", VTYPE_wx_MemoryOutputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MemoryInputStream_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxMemoryOutputStream *stream = Object_wx_MemoryOutputStream::GetObject(arg, 0)->GetEntity();
	wx_MemoryInputStream *pEntity = new wx_MemoryInputStream(*stream);
	Object_wx_MemoryInputStream *pObj = Object_wx_MemoryInputStream::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_MemoryInputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_MemoryInputStream, GetInputStreamBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MemoryInputStream, GetInputStreamBuffer)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryInputStream *pThis = Object_wx_MemoryInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxStreamBuffer *rtn = (wxStreamBuffer *)pThis->GetEntity()->GetInputStreamBuffer();
	return ReturnValue(env, arg, Value(new Object_wx_StreamBuffer(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxMemoryInputStream
//----------------------------------------------------------------------------
Object_wx_MemoryInputStream::~Object_wx_MemoryInputStream()
{
}

Object *Object_wx_MemoryInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_MemoryInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.MemoryInputStream:");
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
// Class implementation for wxMemoryInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryInputStream)
{
	Gura_AssignFunction(MemoryInputStream);
	Gura_AssignFunction(MemoryInputStream_1);
	Gura_AssignMethod(wx_MemoryInputStream, GetInputStreamBuffer);
}

Gura_ImplementDescendantCreator(wx_MemoryInputStream)
{
	return new Object_wx_MemoryInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
