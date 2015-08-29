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
	//Gura::Signal *_pSig;
	Object_wx_AutoBufferedPaintDC *_pObj;
public:
	inline wx_AutoBufferedPaintDC(wxWindow * window) : wxAutoBufferedPaintDC(window), _pObj(nullptr) {}
	~wx_AutoBufferedPaintDC();
	inline void AssocWithGura(Object_wx_AutoBufferedPaintDC *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AutoBufferedPaintDC::~wx_AutoBufferedPaintDC()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_AutoBufferedPaintDC::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAutoBufferedPaintDC
//----------------------------------------------------------------------------
Gura_DeclareFunction(AutoBufferedPaintDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_AutoBufferedPaintDC));
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AutoBufferedPaintDC)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wx_AutoBufferedPaintDC *pEntity = new wx_AutoBufferedPaintDC(window);
	Object_wx_AutoBufferedPaintDC *pObj = Object_wx_AutoBufferedPaintDC::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_AutoBufferedPaintDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxAutoBufferedPaintDC
//----------------------------------------------------------------------------
Object_wx_AutoBufferedPaintDC::~Object_wx_AutoBufferedPaintDC()
{
}

Object *Object_wx_AutoBufferedPaintDC::Clone() const
{
	return nullptr;
}

String Object_wx_AutoBufferedPaintDC::ToString(bool exprFlag)
{
	String rtn("<wx.AutoBufferedPaintDC:");
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
// Class implementation for wxAutoBufferedPaintDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AutoBufferedPaintDC)
{
	Gura_AssignFunction(AutoBufferedPaintDC);
}

Gura_ImplementDescendantCreator(wx_AutoBufferedPaintDC)
{
	return new Object_wx_AutoBufferedPaintDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
