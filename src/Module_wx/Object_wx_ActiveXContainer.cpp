//----------------------------------------------------------------------------
// wxActiveXContainer
// extracted from activexcontainer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ActiveXContainer: public wxActiveXContainer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ActiveXContainer *_pObj;
public:
	//inline wx_ActiveXContainer(wxWindow* parent, REFIID iid, IUnknown* pUnk) : wxActiveXContainer(parent, iid, pUnk), _sig(NULL), _pObj(NULL) {}
	~wx_ActiveXContainer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ActiveXContainer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ActiveXContainer::~wx_ActiveXContainer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ActiveXContainer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxActiveXContainer
//----------------------------------------------------------------------------
Gura_DeclareFunction(ActiveXContainer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_ActiveXContainer));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(ActiveXContainer)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wx_ActiveXContainer *pEntity = new wx_ActiveXContainer(parent, , );
	Object_wx_ActiveXContainer *pObj = Object_wx_ActiveXContainer::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ActiveXContainer(pEntity, pEntity, OwnerFalse);
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

//----------------------------------------------------------------------------
// Object implementation for wxActiveXContainer
//----------------------------------------------------------------------------
Object_wx_ActiveXContainer::~Object_wx_ActiveXContainer()
{
}

Object *Object_wx_ActiveXContainer::Clone() const
{
	return NULL;
}

String Object_wx_ActiveXContainer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ActiveXContainer:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ActiveXContainer::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(ActiveXContainer);
}

//----------------------------------------------------------------------------
// Class implementation for wxActiveXContainer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ActiveXContainer)
{
}

Gura_ImplementDescendantCreator(wx_ActiveXContainer)
{
	return new Object_wx_ActiveXContainer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
