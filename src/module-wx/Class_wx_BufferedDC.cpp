//----------------------------------------------------------------------------
// wxBufferedDC
// extracted from bufferdc.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_BufferedDC: public wxBufferedDC, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_BufferedDC *_pObj;
public:
	inline wx_BufferedDC() : wxBufferedDC(), _pObj(nullptr) {}
	inline wx_BufferedDC(wxDC * dc, const wxSize& area, int style) : wxBufferedDC(dc, area, style), _pObj(nullptr) {}
	inline wx_BufferedDC(wxDC * dc, wxBitmap& buffer, int style) : wxBufferedDC(dc, buffer, style), _pObj(nullptr) {}
	~wx_BufferedDC();
	inline void AssocWithGura(Object_wx_BufferedDC *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BufferedDC::~wx_BufferedDC()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_BufferedDC::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBufferedDC
//----------------------------------------------------------------------------
Gura_DeclareFunction(BufferedDCEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_BufferedDC));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BufferedDCEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_BufferedDC *pEntity = new wx_BufferedDC();
	Object_wx_BufferedDC *pObj = Object_wx_BufferedDC::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_BufferedDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(BufferedDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_BufferedDC));
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "area", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BufferedDC)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxSize *area = Object_wx_Size::GetObject(args, 1)->GetEntity();
	int style = wxBUFFER_CLIENT_AREA;
	if (args.IsValid(2)) style = args.GetInt(2);
	wx_BufferedDC *pEntity = new wx_BufferedDC(dc, *area, style);
	Object_wx_BufferedDC *pObj = Object_wx_BufferedDC::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_BufferedDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(BufferedDC_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_BufferedDC));
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "buffer", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BufferedDC_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxBitmap *buffer = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	int style = wxBUFFER_CLIENT_AREA;
	if (args.IsValid(2)) style = args.GetInt(2);
	wx_BufferedDC *pEntity = new wx_BufferedDC(dc, *buffer, style);
	Object_wx_BufferedDC *pObj = Object_wx_BufferedDC::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_BufferedDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_BufferedDC, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "area", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BufferedDC, Init)
{
	Signal &sig = env.GetSignal();
	Object_wx_BufferedDC *pThis = Object_wx_BufferedDC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxSize *area = Object_wx_Size::GetObject(args, 1)->GetEntity();
	int style = wxBUFFER_CLIENT_AREA;
	if (args.IsValid(2)) style = args.GetInt(2);
	pThis->GetEntity()->Init(dc, *area, style);
	return Value::Nil;
}

Gura_DeclareMethod(wx_BufferedDC, Init_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "buffer", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BufferedDC, Init_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_BufferedDC *pThis = Object_wx_BufferedDC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxBitmap *buffer = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	int style = wxBUFFER_CLIENT_AREA;
	if (args.IsValid(2)) style = args.GetInt(2);
	pThis->GetEntity()->Init(dc, *buffer, style);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxBufferedDC
//----------------------------------------------------------------------------
Object_wx_BufferedDC::~Object_wx_BufferedDC()
{
}

Object *Object_wx_BufferedDC::Clone() const
{
	return nullptr;
}

String Object_wx_BufferedDC::ToString(bool exprFlag)
{
	String rtn("<wx.BufferedDC:");
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
// Class implementation for wxBufferedDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BufferedDC)
{
	Gura_AssignFunction(BufferedDCEmpty);
	Gura_AssignFunction(BufferedDC);
	Gura_AssignFunction(BufferedDC_1);
	Gura_AssignMethod(wx_BufferedDC, Init);
	Gura_AssignMethod(wx_BufferedDC, Init_1);
}

Gura_ImplementDescendantCreator(wx_BufferedDC)
{
	return new Object_wx_BufferedDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
