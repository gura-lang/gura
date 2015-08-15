//----------------------------------------------------------------------------
// wxMemoryOutputStream
// extracted from strmmem.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MemoryOutputStream: public wxMemoryOutputStream, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MemoryOutputStream *_pObj;
public:
	//inline wx_MemoryOutputStream(char * data, size_t length) : wxMemoryOutputStream(data, length), _pObj(nullptr) {}
	~wx_MemoryOutputStream();
	inline void AssocWithGura(Object_wx_MemoryOutputStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MemoryOutputStream::~wx_MemoryOutputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MemoryOutputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(MemoryOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_MemoryOutputStream));
	DeclareArg(env, "data", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "length", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(MemoryOutputStream)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	char data = nullptr;
	if (args.IsValid(0)) data = args.GetChar(0);
	size_t length = 0;
	if (args.IsValid(1)) length = args.GetSizeT(1);
	wx_MemoryOutputStream *pEntity = new wx_MemoryOutputStream(data, length);
	Object_wx_MemoryOutputStream *pObj = Object_wx_MemoryOutputStream::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_MemoryOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryOutputStream, CopyTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MemoryOutputStream, CopyTo)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_MemoryOutputStream *pThis = Object_wx_MemoryOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	char buffer = args.GetChar(0);
	size_t len = args.GetSizeT(1);
	size_t rtn = pThis->GetEntity()->CopyTo(buffer, len);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryOutputStream, GetOutputStreamBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MemoryOutputStream, GetOutputStreamBuffer)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryOutputStream *pThis = Object_wx_MemoryOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxStreamBuffer *rtn = (wxStreamBuffer *)pThis->GetEntity()->GetOutputStreamBuffer();
	return ReturnValue(env, args, Value(new Object_wx_StreamBuffer(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxMemoryOutputStream
//----------------------------------------------------------------------------
Object_wx_MemoryOutputStream::~Object_wx_MemoryOutputStream()
{
}

Object *Object_wx_MemoryOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_MemoryOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.MemoryOutputStream:");
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
// Class implementation for wxMemoryOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryOutputStream)
{
	Gura_AssignFunction(MemoryOutputStream);
	Gura_AssignMethod(wx_MemoryOutputStream, CopyTo);
	Gura_AssignMethod(wx_MemoryOutputStream, GetOutputStreamBuffer);
}

Gura_ImplementDescendantCreator(wx_MemoryOutputStream)
{
	return new Object_wx_MemoryOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
