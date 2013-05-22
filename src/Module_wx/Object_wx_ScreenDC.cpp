//----------------------------------------------------------------------------
// wxScreenDC
// extracted from screendc.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ScreenDC: public wxScreenDC, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ScreenDC *_pObj;
public:
	inline wx_ScreenDC() : wxScreenDC(), _sig(NULL), _pObj(NULL) {}
	~wx_ScreenDC();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ScreenDC *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ScreenDC::~wx_ScreenDC()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ScreenDC::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxScreenDC
//----------------------------------------------------------------------------
Gura_DeclareFunction(ScreenDCEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ScreenDC));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ScreenDCEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ScreenDC *pEntity = new wx_ScreenDC();
	Object_wx_ScreenDC *pObj = Object_wx_ScreenDC::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ScreenDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_ScreenDC, StartDrawingOnTop)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScreenDC, StartDrawingOnTop)
{
	Object_wx_ScreenDC *pThis = Object_wx_ScreenDC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->StartDrawingOnTop(window);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ScreenDC, StartDrawingOnTop_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScreenDC, StartDrawingOnTop_1)
{
	Object_wx_ScreenDC *pThis = Object_wx_ScreenDC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = (wxRect *)(NULL);
	if (args.IsValid(0)) rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->StartDrawingOnTop(rect);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ScreenDC, EndDrawingOnTop)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScreenDC, EndDrawingOnTop)
{
	Object_wx_ScreenDC *pThis = Object_wx_ScreenDC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->EndDrawingOnTop();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxScreenDC
//----------------------------------------------------------------------------
Object_wx_ScreenDC::~Object_wx_ScreenDC()
{
}

Object *Object_wx_ScreenDC::Clone() const
{
	return NULL;
}

String Object_wx_ScreenDC::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ScreenDC:");
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
// Class implementation for wxScreenDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScreenDC)
{
	Gura_AssignFunction(ScreenDCEmpty);
	Gura_AssignMethod(wx_ScreenDC, StartDrawingOnTop);
	Gura_AssignMethod(wx_ScreenDC, StartDrawingOnTop_1);
	Gura_AssignMethod(wx_ScreenDC, EndDrawingOnTop);
}

Gura_ImplementDescendantCreator(wx_ScreenDC)
{
	return new Object_wx_ScreenDC((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
