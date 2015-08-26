//----------------------------------------------------------------------------
// wxLayoutAlgorithm
// extracted from layalgor.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_LayoutAlgorithm: public wxLayoutAlgorithm, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_LayoutAlgorithm *_pObj;
public:
	inline wx_LayoutAlgorithm() : wxLayoutAlgorithm(), _pObj(nullptr) {}
	~wx_LayoutAlgorithm();
	inline void AssocWithGura(Object_wx_LayoutAlgorithm *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LayoutAlgorithm::~wx_LayoutAlgorithm()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_LayoutAlgorithm::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLayoutAlgorithm
//----------------------------------------------------------------------------
Gura_DeclareFunction(LayoutAlgorithm)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_LayoutAlgorithm));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LayoutAlgorithm)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_LayoutAlgorithm *pEntity = new wx_LayoutAlgorithm();
	Object_wx_LayoutAlgorithm *pObj = Object_wx_LayoutAlgorithm::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_LayoutAlgorithm(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_LayoutAlgorithm, LayoutFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "frame", VTYPE_wx_Frame, OCCUR_Once);
	DeclareArg(env, "mainWindow", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LayoutAlgorithm, LayoutFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_LayoutAlgorithm *pThis = Object_wx_LayoutAlgorithm::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFrame *frame = Object_wx_Frame::GetObject(args, 0)->GetEntity();
	wxWindow *mainWindow = (wxWindow *)(nullptr);
	if (args.IsValid(1)) mainWindow = Object_wx_Window::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->LayoutFrame(frame, mainWindow);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_LayoutAlgorithm, LayoutMDIFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "frame", VTYPE_wx_MDIParentFrame, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LayoutAlgorithm, LayoutMDIFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_LayoutAlgorithm *pThis = Object_wx_LayoutAlgorithm::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMDIParentFrame *frame = Object_wx_MDIParentFrame::GetObject(args, 0)->GetEntity();
	wxRect *rect = (wxRect *)(nullptr);
	if (args.IsValid(1)) rect = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->LayoutMDIFrame(frame, rect);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_LayoutAlgorithm, LayoutWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "mainWindow", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LayoutAlgorithm, LayoutWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_LayoutAlgorithm *pThis = Object_wx_LayoutAlgorithm::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	// When the application runs on MacOS and is about to be closed, it sometimes happen
	// that parent has been destoyed before this function is called.
	if (parent == nullptr) return Value::Nil;
	wxWindow *mainWindow = (wxWindow *)(nullptr);
	if (args.IsValid(1)) mainWindow = Object_wx_Window::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->LayoutWindow(parent, mainWindow);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxLayoutAlgorithm
//----------------------------------------------------------------------------
Object_wx_LayoutAlgorithm::~Object_wx_LayoutAlgorithm()
{
}

Object *Object_wx_LayoutAlgorithm::Clone() const
{
	return nullptr;
}

String Object_wx_LayoutAlgorithm::ToString(bool exprFlag)
{
	String rtn("<wx.LayoutAlgorithm:");
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
// Class implementation for wxLayoutAlgorithm
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LayoutAlgorithm)
{
	Gura_AssignFunction(LayoutAlgorithm);
	Gura_AssignMethod(wx_LayoutAlgorithm, LayoutFrame);
	Gura_AssignMethod(wx_LayoutAlgorithm, LayoutMDIFrame);
	Gura_AssignMethod(wx_LayoutAlgorithm, LayoutWindow);
}

Gura_ImplementDescendantCreator(wx_LayoutAlgorithm)
{
	return new Object_wx_LayoutAlgorithm((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
