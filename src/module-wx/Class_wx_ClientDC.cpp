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
	Gura::Signal _sig;
	Object_wx_ClientDC *_pObj;
public:
	inline wx_ClientDC(wxWindow* window) : wxClientDC(window), _sig(NULL), _pObj(NULL) {}
	~wx_ClientDC();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ClientDC *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ClientDC::~wx_ClientDC()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ClientDC::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxClientDC
//----------------------------------------------------------------------------
Gura_DeclareFunction(ClientDC)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ClientDC));
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ClientDC)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wx_ClientDC *pEntity = new wx_ClientDC(window);
	Object_wx_ClientDC *pObj = Object_wx_ClientDC::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ClientDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxClientDC
//----------------------------------------------------------------------------
Object_wx_ClientDC::~Object_wx_ClientDC()
{
}

Object *Object_wx_ClientDC::Clone() const
{
	return NULL;
}

String Object_wx_ClientDC::ToString(bool exprFlag)
{
	String rtn("<wx.ClientDC:");
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
// Class implementation for wxClientDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClientDC)
{
	Gura_AssignFunction(ClientDC);
}

Gura_ImplementDescendantCreator(wx_ClientDC)
{
	return new Object_wx_ClientDC((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
