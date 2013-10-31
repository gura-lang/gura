//----------------------------------------------------------------------------
// wxAutoBufferedPaintDC
// extracted from bufferdc.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AutoBufferedPaintDC: public wxAutoBufferedPaintDC, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_AutoBufferedPaintDC *_pObj;
public:
	inline wx_AutoBufferedPaintDC(wxWindow * window) : wxAutoBufferedPaintDC(window), _sig(NULL), _pObj(NULL) {}
	~wx_AutoBufferedPaintDC();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_AutoBufferedPaintDC *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AutoBufferedPaintDC::~wx_AutoBufferedPaintDC()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_AutoBufferedPaintDC::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAutoBufferedPaintDC
//----------------------------------------------------------------------------
Gura_DeclareFunction(AutoBufferedPaintDC)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_AutoBufferedPaintDC));
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AutoBufferedPaintDC)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wx_AutoBufferedPaintDC *pEntity = new wx_AutoBufferedPaintDC(window);
	Object_wx_AutoBufferedPaintDC *pObj = Object_wx_AutoBufferedPaintDC::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_AutoBufferedPaintDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxAutoBufferedPaintDC
//----------------------------------------------------------------------------
Object_wx_AutoBufferedPaintDC::~Object_wx_AutoBufferedPaintDC()
{
}

Object *Object_wx_AutoBufferedPaintDC::Clone() const
{
	return NULL;
}

String Object_wx_AutoBufferedPaintDC::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.AutoBufferedPaintDC:");
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
// Class implementation for wxAutoBufferedPaintDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AutoBufferedPaintDC)
{
	Gura_AssignFunction(AutoBufferedPaintDC);
}

Gura_ImplementDescendantCreator(wx_AutoBufferedPaintDC)
{
	return new Object_wx_AutoBufferedPaintDC((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
