//----------------------------------------------------------------------------
// wxActiveXContainer
// extracted from activexcontainer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ActiveXContainer: public wxActiveXContainer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ActiveXContainer *_pObj;
public:
	//inline wx_ActiveXContainer(wxWindow* parent, REFIID iid, IUnknown* pUnk) : wxActiveXContainer(parent, iid, pUnk), _pObj(nullptr) {}
	~wx_ActiveXContainer();
	inline void AssocWithGura(Object_wx_ActiveXContainer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ActiveXContainer::~wx_ActiveXContainer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ActiveXContainer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxActiveXContainer
//----------------------------------------------------------------------------
Gura_DeclareFunction(ActiveXContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_ActiveXContainer));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(ActiveXContainer)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wx_ActiveXContainer *pEntity = new wx_ActiveXContainer(parent, , );
	Object_wx_ActiveXContainer *pObj = Object_wx_ActiveXContainer::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_ActiveXContainer(pEntity, pEntity, OwnerFalse);
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

//----------------------------------------------------------------------------
// Object implementation for wxActiveXContainer
//----------------------------------------------------------------------------
Object_wx_ActiveXContainer::~Object_wx_ActiveXContainer()
{
}

Object *Object_wx_ActiveXContainer::Clone() const
{
	return nullptr;
}

String Object_wx_ActiveXContainer::ToString(bool exprFlag)
{
	String rtn("<wx.ActiveXContainer:");
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
// Class implementation for wxActiveXContainer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ActiveXContainer)
{
	Gura_AssignFunction(ActiveXContainer);
}

Gura_ImplementDescendantCreator(wx_ActiveXContainer)
{
	return new Object_wx_ActiveXContainer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
