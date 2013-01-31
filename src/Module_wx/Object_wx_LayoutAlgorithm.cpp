//----------------------------------------------------------------------------
// wxLayoutAlgorithm
// extracted from layalgor.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_LayoutAlgorithm: public wxLayoutAlgorithm, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_LayoutAlgorithm *_pObj;
public:
	inline wx_LayoutAlgorithm() : wxLayoutAlgorithm(), _sig(NULL), _pObj(NULL) {}
	~wx_LayoutAlgorithm();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_LayoutAlgorithm *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LayoutAlgorithm::~wx_LayoutAlgorithm()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_LayoutAlgorithm::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLayoutAlgorithm
//----------------------------------------------------------------------------
Gura_DeclareFunction(LayoutAlgorithm)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_LayoutAlgorithm));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LayoutAlgorithm)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_LayoutAlgorithm *pEntity = new wx_LayoutAlgorithm();
	Object_wx_LayoutAlgorithm *pObj = Object_wx_LayoutAlgorithm::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_LayoutAlgorithm(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_LayoutAlgorithm, LayoutFrame)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "frame", VTYPE_wx_Frame, OCCUR_Once);
	DeclareArg(env, "mainWindow", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LayoutAlgorithm, LayoutFrame)
{
	Object_wx_LayoutAlgorithm *pThis = Object_wx_LayoutAlgorithm::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFrame *frame = Object_wx_Frame::GetObject(args, 0)->GetEntity();
	wxWindow *mainWindow = (wxWindow *)(NULL);
	if (args.IsValid(1)) mainWindow = Object_wx_Window::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->LayoutFrame(frame, mainWindow);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_LayoutAlgorithm, LayoutMDIFrame)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "frame", VTYPE_wx_MDIParentFrame, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LayoutAlgorithm, LayoutMDIFrame)
{
	Object_wx_LayoutAlgorithm *pThis = Object_wx_LayoutAlgorithm::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMDIParentFrame *frame = Object_wx_MDIParentFrame::GetObject(args, 0)->GetEntity();
	wxRect *rect = (wxRect *)(NULL);
	if (args.IsValid(1)) rect = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->LayoutMDIFrame(frame, rect);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_LayoutAlgorithm, LayoutWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "mainWindow", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LayoutAlgorithm, LayoutWindow)
{
	Object_wx_LayoutAlgorithm *pThis = Object_wx_LayoutAlgorithm::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindow *mainWindow = (wxWindow *)(NULL);
	if (args.IsValid(1)) mainWindow = Object_wx_Window::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->LayoutWindow(parent, mainWindow);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxLayoutAlgorithm
//----------------------------------------------------------------------------
Object_wx_LayoutAlgorithm::~Object_wx_LayoutAlgorithm()
{
}

Object *Object_wx_LayoutAlgorithm::Clone() const
{
	return NULL;
}

String Object_wx_LayoutAlgorithm::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.LayoutAlgorithm:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_LayoutAlgorithm::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(LayoutAlgorithm);
}

//----------------------------------------------------------------------------
// Class implementation for wxLayoutAlgorithm
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LayoutAlgorithm)
{
	Gura_AssignMethod(wx_LayoutAlgorithm, LayoutFrame);
	Gura_AssignMethod(wx_LayoutAlgorithm, LayoutMDIFrame);
	Gura_AssignMethod(wx_LayoutAlgorithm, LayoutWindow);
}

Gura_ImplementDescendantCreator(wx_LayoutAlgorithm)
{
	return new Object_wx_LayoutAlgorithm((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
