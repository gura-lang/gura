//----------------------------------------------------------------------------
// wxSocketOutputStream
// extracted from strmsock.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SocketOutputStream: public wxSocketOutputStream, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SocketOutputStream *_pObj;
public:
	inline wx_SocketOutputStream(wxSocketBase& s) : wxSocketOutputStream(s), _pObj(nullptr) {}
	~wx_SocketOutputStream();
	inline void AssocWithGura(Object_wx_SocketOutputStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SocketOutputStream::~wx_SocketOutputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SocketOutputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(SocketOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SocketOutputStream));
	DeclareArg(env, "s", VTYPE_wx_SocketBase, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SocketOutputStream)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxSocketBase *s = Object_wx_SocketBase::GetObject(args, 0)->GetEntity();
	wx_SocketOutputStream *pEntity = new wx_SocketOutputStream(*s);
	Object_wx_SocketOutputStream *pObj = Object_wx_SocketOutputStream::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SocketOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxSocketOutputStream
//----------------------------------------------------------------------------
Object_wx_SocketOutputStream::~Object_wx_SocketOutputStream()
{
}

Object *Object_wx_SocketOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_SocketOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.SocketOutputStream:");
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
// Class implementation for wxSocketOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketOutputStream)
{
	Gura_AssignFunction(SocketOutputStream);
}

Gura_ImplementDescendantCreator(wx_SocketOutputStream)
{
	return new Object_wx_SocketOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
