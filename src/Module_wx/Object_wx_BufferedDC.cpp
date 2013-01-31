//----------------------------------------------------------------------------
// wxBufferedDC
// extracted from bufferdc.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_BufferedDC: public wxBufferedDC, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_BufferedDC *_pObj;
public:
	inline wx_BufferedDC() : wxBufferedDC(), _sig(NULL), _pObj(NULL) {}
	inline wx_BufferedDC(wxDC * dc, const wxSize& area, int style) : wxBufferedDC(dc, area, style), _sig(NULL), _pObj(NULL) {}
	inline wx_BufferedDC(wxDC * dc, wxBitmap& buffer, int style) : wxBufferedDC(dc, buffer, style), _sig(NULL), _pObj(NULL) {}
	~wx_BufferedDC();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_BufferedDC *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BufferedDC::~wx_BufferedDC()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_BufferedDC::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBufferedDC
//----------------------------------------------------------------------------
Gura_DeclareFunction(BufferedDCEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_BufferedDC));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BufferedDCEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_BufferedDC *pEntity = new wx_BufferedDC();
	Object_wx_BufferedDC *pObj = Object_wx_BufferedDC::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_BufferedDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(BufferedDC)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_BufferedDC));
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "area", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BufferedDC)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxSize *area = Object_wx_Size::GetObject(args, 1)->GetEntity();
	int style = wxBUFFER_CLIENT_AREA;
	if (args.IsValid(2)) style = args.GetInt(2);
	wx_BufferedDC *pEntity = new wx_BufferedDC(dc, *area, style);
	Object_wx_BufferedDC *pObj = Object_wx_BufferedDC::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_BufferedDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(BufferedDC_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_BufferedDC));
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "buffer", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BufferedDC_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxBitmap *buffer = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	int style = wxBUFFER_CLIENT_AREA;
	if (args.IsValid(2)) style = args.GetInt(2);
	wx_BufferedDC *pEntity = new wx_BufferedDC(dc, *buffer, style);
	Object_wx_BufferedDC *pObj = Object_wx_BufferedDC::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_BufferedDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_BufferedDC, Init)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "area", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BufferedDC, Init)
{
	Object_wx_BufferedDC *pThis = Object_wx_BufferedDC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxSize *area = Object_wx_Size::GetObject(args, 1)->GetEntity();
	int style = wxBUFFER_CLIENT_AREA;
	if (args.IsValid(2)) style = args.GetInt(2);
	pThis->GetEntity()->Init(dc, *area, style);
	return Value::Null;
}

Gura_DeclareMethod(wx_BufferedDC, Init_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "buffer", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BufferedDC, Init_1)
{
	Object_wx_BufferedDC *pThis = Object_wx_BufferedDC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxBitmap *buffer = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	int style = wxBUFFER_CLIENT_AREA;
	if (args.IsValid(2)) style = args.GetInt(2);
	pThis->GetEntity()->Init(dc, *buffer, style);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxBufferedDC
//----------------------------------------------------------------------------
Object_wx_BufferedDC::~Object_wx_BufferedDC()
{
}

Object *Object_wx_BufferedDC::Clone() const
{
	return NULL;
}

String Object_wx_BufferedDC::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.BufferedDC:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_BufferedDC::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(BufferedDCEmpty);
	Gura_AssignFunction(BufferedDC);
	Gura_AssignFunction(BufferedDC_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxBufferedDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BufferedDC)
{
	Gura_AssignMethod(wx_BufferedDC, Init);
	Gura_AssignMethod(wx_BufferedDC, Init_1);
}

Gura_ImplementDescendantCreator(wx_BufferedDC)
{
	return new Object_wx_BufferedDC((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
