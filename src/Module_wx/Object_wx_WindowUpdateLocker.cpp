//----------------------------------------------------------------------------
// wxWindowUpdateLocker
// extracted from wupdlock.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_WindowUpdateLocker: public wxWindowUpdateLocker, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_WindowUpdateLocker *_pObj;
public:
	inline wx_WindowUpdateLocker(wxWindow * win) : wxWindowUpdateLocker(win), _sig(NULL), _pObj(NULL) {}
	~wx_WindowUpdateLocker();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_WindowUpdateLocker *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_WindowUpdateLocker::~wx_WindowUpdateLocker()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_WindowUpdateLocker::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowUpdateLocker
//----------------------------------------------------------------------------
Gura_DeclareFunction(WindowUpdateLocker)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_WindowUpdateLocker));
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WindowUpdateLocker)
{
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wx_WindowUpdateLocker *pEntity = new wx_WindowUpdateLocker(win);
	Object_wx_WindowUpdateLocker *pObj = Object_wx_WindowUpdateLocker::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_WindowUpdateLocker(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

//----------------------------------------------------------------------------
// Object implementation for wxWindowUpdateLocker
//----------------------------------------------------------------------------
Object_wx_WindowUpdateLocker::~Object_wx_WindowUpdateLocker()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_WindowUpdateLocker::Clone() const
{
	return NULL;
}

String Object_wx_WindowUpdateLocker::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.WindowUpdateLocker:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_WindowUpdateLocker::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(WindowUpdateLocker);
}

//----------------------------------------------------------------------------
// Class implementation for wxWindowUpdateLocker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowUpdateLocker)
{
}

Gura_ImplementDescendantCreator(wx_WindowUpdateLocker)
{
	return new Object_wx_WindowUpdateLocker((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
