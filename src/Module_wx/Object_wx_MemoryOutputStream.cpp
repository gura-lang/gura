//----------------------------------------------------------------------------
// wxMemoryOutputStream
// extracted from strmmem.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MemoryOutputStream: public wxMemoryOutputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MemoryOutputStream *_pObj;
public:
	//inline wx_MemoryOutputStream(char * data, size_t length) : wxMemoryOutputStream(data, length), _sig(NULL), _pObj(NULL) {}
	~wx_MemoryOutputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MemoryOutputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MemoryOutputStream::~wx_MemoryOutputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MemoryOutputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(MemoryOutputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_MemoryOutputStream));
	DeclareArg(env, "data", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "length", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(MemoryOutputStream)
{
#if 0
	char data = NULL;
	if (args.IsValid(0)) data = args.GetChar(0);
	size_t length = 0;
	if (args.IsValid(1)) length = args.GetSizeT(1);
	wx_MemoryOutputStream *pEntity = new wx_MemoryOutputStream(data, length);
	Object_wx_MemoryOutputStream *pObj = Object_wx_MemoryOutputStream::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MemoryOutputStream(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_MemoryOutputStream, CopyTo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MemoryOutputStream, CopyTo)
{
#if 0
	Object_wx_MemoryOutputStream *pSelf = Object_wx_MemoryOutputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	char buffer = args.GetChar(0);
	size_t len = args.GetSizeT(1);
	size_t rtn = pSelf->GetEntity()->CopyTo(buffer, len);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_MemoryOutputStream, GetOutputStreamBuffer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MemoryOutputStream, GetOutputStreamBuffer)
{
	Object_wx_MemoryOutputStream *pSelf = Object_wx_MemoryOutputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxStreamBuffer *rtn = (wxStreamBuffer *)pSelf->GetEntity()->GetOutputStreamBuffer();
	return ReturnValue(env, sig, args, Value(new Object_wx_StreamBuffer(rtn, NULL, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxMemoryOutputStream
//----------------------------------------------------------------------------
Object_wx_MemoryOutputStream::~Object_wx_MemoryOutputStream()
{
}

Object *Object_wx_MemoryOutputStream::Clone() const
{
	return NULL;
}

String Object_wx_MemoryOutputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.MemoryOutputStream:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_MemoryOutputStream::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(MemoryOutputStream);
}

//----------------------------------------------------------------------------
// Class implementation for wxMemoryOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryOutputStream)
{
	Gura_AssignMethod(wx_MemoryOutputStream, CopyTo);
	Gura_AssignMethod(wx_MemoryOutputStream, GetOutputStreamBuffer);
}

Gura_ImplementDescendantCreator(wx_MemoryOutputStream)
{
	return new Object_wx_MemoryOutputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
