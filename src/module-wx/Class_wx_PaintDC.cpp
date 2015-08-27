//----------------------------------------------------------------------------
// wxPaintDC
// extracted from paintdc.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PaintDC: public wxPaintDC, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_PaintDC *_pObj;
public:
	inline wx_PaintDC(wxWindow* window) : wxPaintDC(window), _pObj(nullptr) {}
	~wx_PaintDC();
	inline void AssocWithGura(Object_wx_PaintDC *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PaintDC::~wx_PaintDC()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PaintDC::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPaintDC
//----------------------------------------------------------------------------
Gura_DeclareFunction(PaintDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PaintDC));
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PaintDC)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wx_PaintDC *pEntity = new wx_PaintDC(window);
	Object_wx_PaintDC *pObj = Object_wx_PaintDC::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PaintDC(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxPaintDC
//----------------------------------------------------------------------------
Object_wx_PaintDC::~Object_wx_PaintDC()
{
}

Object *Object_wx_PaintDC::Clone() const
{
	return nullptr;
}

String Object_wx_PaintDC::ToString(bool exprFlag)
{
	String rtn("<wx.PaintDC:");
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
// Class implementation for wxPaintDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PaintDC)
{
	Gura_AssignFunction(PaintDC);
}

Gura_ImplementDescendantCreator(wx_PaintDC)
{
	return new Object_wx_PaintDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
