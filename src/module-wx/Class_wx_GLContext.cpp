//----------------------------------------------------------------------------
// wxGLContext
// extracted from glcontext.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GLContext: public wxGLContext, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_GLContext *_pObj;
public:
	inline wx_GLContext(wxGLCanvas* win, const wxGLContext* other) : wxGLContext(win, other), _pObj(nullptr) {}
	~wx_GLContext();
	inline void AssocWithGura(Object_wx_GLContext *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GLContext::~wx_GLContext()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GLContext::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGLContext
//----------------------------------------------------------------------------
Gura_DeclareFunction(GLContext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GLContext));
	DeclareArg(env, "win", VTYPE_wx_GLCanvas, OCCUR_Once);
	DeclareArg(env, "other", VTYPE_wx_GLContext, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GLContext)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxGLCanvas *win = Object_wx_GLCanvas::GetObject(arg, 0)->GetEntity();
	wxGLContext *other = (wxGLContext *)(nullptr);
	if (arg.IsValid(1)) other = Object_wx_GLContext::GetObject(arg, 1)->GetEntity();
	wx_GLContext *pEntity = new wx_GLContext(win, other);
	Object_wx_GLContext *pObj = Object_wx_GLContext::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_GLContext(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_GLContext, SetCurrent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_GLCanvas, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLContext, SetCurrent)
{
	Signal &sig = env.GetSignal();
	Object_wx_GLContext *pThis = Object_wx_GLContext::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGLCanvas *win = Object_wx_GLCanvas::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetCurrent(*win);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxGLContext
//----------------------------------------------------------------------------
Object_wx_GLContext::~Object_wx_GLContext()
{
}

Object *Object_wx_GLContext::Clone() const
{
	return nullptr;
}

String Object_wx_GLContext::ToString(bool exprFlag)
{
	String rtn("<wx.GLContext:");
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
// Class implementation for wxGLContext
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GLContext)
{
	Gura_AssignFunction(GLContext);
	Gura_AssignMethod(wx_GLContext, SetCurrent);
}

Gura_ImplementDescendantCreator(wx_GLContext)
{
	return new Object_wx_GLContext((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
