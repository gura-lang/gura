//----------------------------------------------------------------------------
// wxMemoryInputStream
// extracted from strmmem.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MemoryInputStream: public wxMemoryInputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MemoryInputStream *_pObj;
public:
	//inline wx_MemoryInputStream(const char * data, size_t len) : wxMemoryInputStream(data, len), _sig(NULL), _pObj(NULL) {}
	inline wx_MemoryInputStream(const wxMemoryOutputStream& stream) : wxMemoryInputStream(stream), _sig(NULL), _pObj(NULL) {}
	~wx_MemoryInputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MemoryInputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MemoryInputStream::~wx_MemoryInputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MemoryInputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryInputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(MemoryInputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_MemoryInputStream));
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(MemoryInputStream)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char data = args.GetChar(0);
	size_t len = args.GetSizeT(1);
	wx_MemoryInputStream *pEntity = new wx_MemoryInputStream(data, len);
	Object_wx_MemoryInputStream *pObj = Object_wx_MemoryInputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MemoryInputStream(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareFunction(MemoryInputStream_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MemoryInputStream));
	DeclareArg(env, "stream", VTYPE_wx_MemoryOutputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MemoryInputStream_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxMemoryOutputStream *stream = Object_wx_MemoryOutputStream::GetObject(args, 0)->GetEntity();
	wx_MemoryInputStream *pEntity = new wx_MemoryInputStream(*stream);
	Object_wx_MemoryInputStream *pObj = Object_wx_MemoryInputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MemoryInputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_MemoryInputStream, GetInputStreamBuffer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MemoryInputStream, GetInputStreamBuffer)
{
	Object_wx_MemoryInputStream *pThis = Object_wx_MemoryInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxStreamBuffer *rtn = (wxStreamBuffer *)pThis->GetEntity()->GetInputStreamBuffer();
	return ReturnValue(env, sig, args, Value(new Object_wx_StreamBuffer(rtn, NULL, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxMemoryInputStream
//----------------------------------------------------------------------------
Object_wx_MemoryInputStream::~Object_wx_MemoryInputStream()
{
}

Object *Object_wx_MemoryInputStream::Clone() const
{
	return NULL;
}

String Object_wx_MemoryInputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.MemoryInputStream:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_MemoryInputStream::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(MemoryInputStream);
	Gura_AssignFunction(MemoryInputStream_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxMemoryInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryInputStream)
{
	Gura_AssignMethod(wx_MemoryInputStream, GetInputStreamBuffer);
}

Gura_ImplementDescendantCreator(wx_MemoryInputStream)
{
	return new Object_wx_MemoryInputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
