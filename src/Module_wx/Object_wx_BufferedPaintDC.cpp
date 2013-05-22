//----------------------------------------------------------------------------
// wxBufferedPaintDC
// extracted from bufferdc.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_BufferedPaintDC: public wxBufferedPaintDC, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_BufferedPaintDC *_pObj;
public:
	inline wx_BufferedPaintDC(wxWindow * window, wxBitmap& buffer, int style) : wxBufferedPaintDC(window, buffer, style), _sig(NULL), _pObj(NULL) {}
	inline wx_BufferedPaintDC(wxWindow * window, int style) : wxBufferedPaintDC(window, style), _sig(NULL), _pObj(NULL) {}
	~wx_BufferedPaintDC();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_BufferedPaintDC *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BufferedPaintDC::~wx_BufferedPaintDC()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_BufferedPaintDC::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBufferedPaintDC
//----------------------------------------------------------------------------
Gura_DeclareFunction(BufferedPaintDC)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_BufferedPaintDC));
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "buffer", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BufferedPaintDC)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxBitmap *buffer = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	int style = wxBUFFER_CLIENT_AREA;
	if (args.IsValid(2)) style = args.GetInt(2);
	wx_BufferedPaintDC *pEntity = new wx_BufferedPaintDC(window, *buffer, style);
	Object_wx_BufferedPaintDC *pObj = Object_wx_BufferedPaintDC::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_BufferedPaintDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(BufferedPaintDC_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_BufferedPaintDC));
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BufferedPaintDC_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int style = wxBUFFER_CLIENT_AREA;
	if (args.IsValid(1)) style = args.GetInt(1);
	wx_BufferedPaintDC *pEntity = new wx_BufferedPaintDC(window, style);
	Object_wx_BufferedPaintDC *pObj = Object_wx_BufferedPaintDC::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_BufferedPaintDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxBufferedPaintDC
//----------------------------------------------------------------------------
Object_wx_BufferedPaintDC::~Object_wx_BufferedPaintDC()
{
}

Object *Object_wx_BufferedPaintDC::Clone() const
{
	return NULL;
}

String Object_wx_BufferedPaintDC::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.BufferedPaintDC:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_BufferedPaintDC::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(BufferedPaintDC);
	Gura_AssignFunction(BufferedPaintDC_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxBufferedPaintDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BufferedPaintDC)
{
}

Gura_ImplementDescendantCreator(wx_BufferedPaintDC)
{
	return new Object_wx_BufferedPaintDC((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
