//----------------------------------------------------------------------------
// wxWindowDC
// extracted from windowdc.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_WindowDC: public wxWindowDC, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_WindowDC *_pObj;
public:
	inline wx_WindowDC(wxWindow* window) : wxWindowDC(window), _pObj(nullptr) {}
	~wx_WindowDC();
	inline void AssocWithGura(Object_wx_WindowDC *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_WindowDC::~wx_WindowDC()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_WindowDC::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowDC
//----------------------------------------------------------------------------
Gura_DeclareFunction(WindowDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_WindowDC));
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WindowDC)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wx_WindowDC *pEntity = new wx_WindowDC(window);
	Object_wx_WindowDC *pObj = Object_wx_WindowDC::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_WindowDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxWindowDC
//----------------------------------------------------------------------------
Object_wx_WindowDC::~Object_wx_WindowDC()
{
}

Object *Object_wx_WindowDC::Clone() const
{
	return nullptr;
}

String Object_wx_WindowDC::ToString(bool exprFlag)
{
	String rtn("<wx.WindowDC:");
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
// Class implementation for wxWindowDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowDC)
{
	Gura_AssignFunction(WindowDC);
}

Gura_ImplementDescendantCreator(wx_WindowDC)
{
	return new Object_wx_WindowDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
