//----------------------------------------------------------------------------
// wxPaintDC
// extracted from paintdc.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PaintDC: public wxPaintDC, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PaintDC *_pObj;
public:
	inline wx_PaintDC(wxWindow* window) : wxPaintDC(window), _sig(NULL), _pObj(NULL) {}
	~wx_PaintDC();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PaintDC *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PaintDC::~wx_PaintDC()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_PaintDC::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPaintDC
//----------------------------------------------------------------------------
Gura_DeclareFunction(PaintDC)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PaintDC));
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PaintDC)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wx_PaintDC *pEntity = new wx_PaintDC(window);
	Object_wx_PaintDC *pObj = Object_wx_PaintDC::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PaintDC(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxPaintDC
//----------------------------------------------------------------------------
Object_wx_PaintDC::~Object_wx_PaintDC()
{
}

Object *Object_wx_PaintDC::Clone() const
{
	return NULL;
}

String Object_wx_PaintDC::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.PaintDC:");
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
// Class implementation for wxPaintDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PaintDC)
{
	Gura_AssignFunction(PaintDC);
}

Gura_ImplementDescendantCreator(wx_PaintDC)
{
	return new Object_wx_PaintDC((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
