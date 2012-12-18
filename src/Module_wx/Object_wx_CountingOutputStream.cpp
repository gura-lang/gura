//----------------------------------------------------------------------------
// wxCountingOutputStream
// extracted from countstr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CountingOutputStream: public wxCountingOutputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_CountingOutputStream *_pObj;
public:
	inline wx_CountingOutputStream() : wxCountingOutputStream(), _sig(NULL), _pObj(NULL) {}
	~wx_CountingOutputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_CountingOutputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CountingOutputStream::~wx_CountingOutputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_CountingOutputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCountingOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(CountingOutputStreamEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CountingOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CountingOutputStreamEmpty)
{
	wx_CountingOutputStream *pEntity = new wx_CountingOutputStream();
	Object_wx_CountingOutputStream *pObj = Object_wx_CountingOutputStream::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CountingOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_CountingOutputStream, GetSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CountingOutputStream, GetSize)
{
	Object_wx_CountingOutputStream *pSelf = Object_wx_CountingOutputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t rtn = pSelf->GetEntity()->GetSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxCountingOutputStream
//----------------------------------------------------------------------------
Object_wx_CountingOutputStream::~Object_wx_CountingOutputStream()
{
}

Object *Object_wx_CountingOutputStream::Clone() const
{
	return NULL;
}

String Object_wx_CountingOutputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.CountingOutputStream:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_CountingOutputStream::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(CountingOutputStreamEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxCountingOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CountingOutputStream)
{
	Gura_AssignMethod(wx_CountingOutputStream, GetSize);
}

Gura_ImplementDescendantCreator(wx_CountingOutputStream)
{
	return new Object_wx_CountingOutputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
