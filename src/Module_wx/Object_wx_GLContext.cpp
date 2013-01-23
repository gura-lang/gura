//----------------------------------------------------------------------------
// wxGLContext
// extracted from glcontext.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GLContext: public wxGLContext, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GLContext *_pObj;
public:
	inline wx_GLContext(wxGLCanvas* win, const wxGLContext* other) : wxGLContext(win, other), _sig(NULL), _pObj(NULL) {}
	~wx_GLContext();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GLContext *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GLContext::~wx_GLContext()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GLContext::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGLContext
//----------------------------------------------------------------------------
Gura_DeclareFunction(GLContext)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GLContext));
	DeclareArg(env, "win", VTYPE_wx_GLCanvas, OCCUR_Once);
	DeclareArg(env, "other", VTYPE_wx_GLContext, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GLContext)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxGLCanvas *win = Object_wx_GLCanvas::GetObject(args, 0)->GetEntity();
	wxGLContext *other = (wxGLContext *)(NULL);
	if (args.IsValid(1)) other = Object_wx_GLContext::GetObject(args, 1)->GetEntity();
	wx_GLContext *pEntity = new wx_GLContext(win, other);
	Object_wx_GLContext *pObj = Object_wx_GLContext::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GLContext(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_GLContext, SetCurrent)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_GLCanvas, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLContext, SetCurrent)
{
	Object_wx_GLContext *pSelf = Object_wx_GLContext::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxGLCanvas *win = Object_wx_GLCanvas::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetCurrent(*win);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxGLContext
//----------------------------------------------------------------------------
Object_wx_GLContext::~Object_wx_GLContext()
{
}

Object *Object_wx_GLContext::Clone() const
{
	return NULL;
}

String Object_wx_GLContext::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GLContext:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_GLContext::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(GLContext);
}

//----------------------------------------------------------------------------
// Class implementation for wxGLContext
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GLContext)
{
	Gura_AssignMethod(wx_GLContext, SetCurrent);
}

Gura_ImplementDescendantCreator(wx_GLContext)
{
	return new Object_wx_GLContext((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
