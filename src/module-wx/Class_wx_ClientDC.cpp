//----------------------------------------------------------------------------
// wxClientDC
// extracted from clientdc.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ClientDC: public wxClientDC, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ClientDC *_pObj;
public:
	inline wx_ClientDC(wxWindow* window) : wxClientDC(window), _pObj(nullptr) {}
	~wx_ClientDC();
	inline void AssocWithGura(Object_wx_ClientDC *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ClientDC::~wx_ClientDC()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ClientDC::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxClientDC
//----------------------------------------------------------------------------
Gura_DeclareFunction(ClientDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ClientDC));
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ClientDC)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wx_ClientDC *pEntity = new wx_ClientDC(window);
	Object_wx_ClientDC *pObj = Object_wx_ClientDC::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_ClientDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxClientDC
//----------------------------------------------------------------------------
Object_wx_ClientDC::~Object_wx_ClientDC()
{
}

Object *Object_wx_ClientDC::Clone() const
{
	return nullptr;
}

String Object_wx_ClientDC::ToString(bool exprFlag)
{
	String rtn("<wx.ClientDC:");
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
// Class implementation for wxClientDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClientDC)
{
	Gura_AssignFunction(ClientDC);
}

Gura_ImplementDescendantCreator(wx_ClientDC)
{
	return new Object_wx_ClientDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
