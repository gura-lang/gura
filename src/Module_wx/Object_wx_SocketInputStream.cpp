//----------------------------------------------------------------------------
// wxSocketInputStream
// extracted from strmsock.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SocketInputStream: public wxSocketInputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_SocketInputStream *_pObj;
public:
	inline wx_SocketInputStream(wxSocketBase& s) : wxSocketInputStream(s), _sig(NULL), _pObj(NULL) {}
	~wx_SocketInputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SocketInputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SocketInputStream::~wx_SocketInputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_SocketInputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketInputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(SocketInputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SocketInputStream));
	DeclareArg(env, "s", VTYPE_wx_SocketBase, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SocketInputStream)
{
	wxSocketBase *s = Object_wx_SocketBase::GetObject(args, 0)->GetEntity();
	wx_SocketInputStream *pEntity = new wx_SocketInputStream(*s);
	Object_wx_SocketInputStream *pObj = Object_wx_SocketInputStream::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_SocketInputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

//----------------------------------------------------------------------------
// Object implementation for wxSocketInputStream
//----------------------------------------------------------------------------
Object_wx_SocketInputStream::~Object_wx_SocketInputStream()
{
}

Object *Object_wx_SocketInputStream::Clone() const
{
	return NULL;
}

String Object_wx_SocketInputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.SocketInputStream:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_SocketInputStream::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(SocketInputStream);
}

//----------------------------------------------------------------------------
// Class implementation for wxSocketInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketInputStream)
{
}

Gura_ImplementDescendantCreator(wx_SocketInputStream)
{
	return new Object_wx_SocketInputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
