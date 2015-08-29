//----------------------------------------------------------------------------
// wxMask
// extracted from mask.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Mask: public wxMask, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Mask *_pObj;
public:
	inline wx_Mask() : wxMask(), _pObj(nullptr) {}
	inline wx_Mask(const wxBitmap& bitmap) : wxMask(bitmap), _pObj(nullptr) {}
	inline wx_Mask(const wxBitmap& bitmap, const wxColour& colour) : wxMask(bitmap, colour), _pObj(nullptr) {}
	inline wx_Mask(const wxBitmap& bitmap, int index) : wxMask(bitmap, index), _pObj(nullptr) {}
	~wx_Mask();
	inline void AssocWithGura(Object_wx_Mask *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Mask::~wx_Mask()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Mask::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMask
//----------------------------------------------------------------------------
Gura_DeclareFunction(MaskEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Mask));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MaskEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Mask *pEntity = new wx_Mask();
	Object_wx_Mask *pObj = Object_wx_Mask::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Mask(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Mask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Mask));
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Mask)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(arg, 0)->GetEntity();
	wx_Mask *pEntity = new wx_Mask(*bitmap);
	Object_wx_Mask *pObj = Object_wx_Mask::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Mask(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Mask_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Mask));
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Mask_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(arg, 0)->GetEntity();
	wxColour *colour = Object_wx_Colour::GetObject(arg, 1)->GetEntity();
	wx_Mask *pEntity = new wx_Mask(*bitmap, *colour);
	Object_wx_Mask *pObj = Object_wx_Mask::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Mask(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Mask_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Mask));
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Mask_2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(arg, 0)->GetEntity();
	int index = arg.GetInt(1);
	wx_Mask *pEntity = new wx_Mask(*bitmap, index);
	Object_wx_Mask *pObj = Object_wx_Mask::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Mask(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_Mask, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Mask, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Mask *pThis = Object_wx_Mask::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Create(*bitmap);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Mask, Create_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Mask, Create_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Mask *pThis = Object_wx_Mask::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(arg, 0)->GetEntity();
	wxColour *colour = Object_wx_Colour::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Create(*bitmap, *colour);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Mask, Create_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Mask, Create_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Mask *pThis = Object_wx_Mask::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(arg, 0)->GetEntity();
	int index = arg.GetInt(1);
	bool rtn = pThis->GetEntity()->Create(*bitmap, index);
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxMask
//----------------------------------------------------------------------------
Object_wx_Mask::~Object_wx_Mask()
{
}

Object *Object_wx_Mask::Clone() const
{
	return nullptr;
}

String Object_wx_Mask::ToString(bool exprFlag)
{
	String rtn("<wx.Mask:");
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
// Class implementation for wxMask
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Mask)
{
	Gura_AssignFunction(MaskEmpty);
	Gura_AssignFunction(Mask);
	Gura_AssignFunction(Mask_1);
	Gura_AssignFunction(Mask_2);
	Gura_AssignMethod(wx_Mask, Create);
	Gura_AssignMethod(wx_Mask, Create_1);
	Gura_AssignMethod(wx_Mask, Create_2);
}

Gura_ImplementDescendantCreator(wx_Mask)
{
	return new Object_wx_Mask((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
