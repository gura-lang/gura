//----------------------------------------------------------------------------
// wxSocketOutputStream
// extracted from strmsock.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SocketOutputStream: public wxSocketOutputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_SocketOutputStream *_pObj;
public:
	inline wx_SocketOutputStream(wxSocketBase& s) : wxSocketOutputStream(s), _sig(NULL), _pObj(NULL) {}
	~wx_SocketOutputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SocketOutputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SocketOutputStream::~wx_SocketOutputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_SocketOutputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(SocketOutputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SocketOutputStream));
	DeclareArg(env, "s", VTYPE_wx_SocketBase, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SocketOutputStream)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxSocketBase *s = Object_wx_SocketBase::GetObject(args, 0)->GetEntity();
	wx_SocketOutputStream *pEntity = new wx_SocketOutputStream(*s);
	Object_wx_SocketOutputStream *pObj = Object_wx_SocketOutputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_SocketOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxSocketOutputStream
//----------------------------------------------------------------------------
Object_wx_SocketOutputStream::~Object_wx_SocketOutputStream()
{
}

Object *Object_wx_SocketOutputStream::Clone() const
{
	return NULL;
}

String Object_wx_SocketOutputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.SocketOutputStream:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxSocketOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketOutputStream)
{
	Gura_AssignFunction(SocketOutputStream);
}

Gura_ImplementDescendantCreator(wx_SocketOutputStream)
{
	return new Object_wx_SocketOutputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
