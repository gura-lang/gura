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
	Gura::Signal _sig;
	Object_wx_Mask *_pObj;
public:
	inline wx_Mask() : wxMask(), _sig(nullptr), _pObj(nullptr) {}
	inline wx_Mask(const wxBitmap& bitmap) : wxMask(bitmap), _sig(nullptr), _pObj(nullptr) {}
	inline wx_Mask(const wxBitmap& bitmap, const wxColour& colour) : wxMask(bitmap, colour), _sig(nullptr), _pObj(nullptr) {}
	inline wx_Mask(const wxBitmap& bitmap, int index) : wxMask(bitmap, index), _sig(nullptr), _pObj(nullptr) {}
	~wx_Mask();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Mask *pObj) {
		_sig = sig, _pObj = pObj;
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
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Mask *pEntity = new wx_Mask();
	Object_wx_Mask *pObj = Object_wx_Mask::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Mask(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	wx_Mask *pEntity = new wx_Mask(*bitmap);
	Object_wx_Mask *pObj = Object_wx_Mask::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Mask(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	wxColour *colour = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wx_Mask *pEntity = new wx_Mask(*bitmap, *colour);
	Object_wx_Mask *pObj = Object_wx_Mask::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Mask(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	int index = args.GetInt(1);
	wx_Mask *pEntity = new wx_Mask(*bitmap, index);
	Object_wx_Mask *pObj = Object_wx_Mask::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Mask(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_Mask, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Mask, Create)
{
	Object_wx_Mask *pThis = Object_wx_Mask::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Create(*bitmap);
	return ReturnValue(env, sig, args, Value(rtn));
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
	Object_wx_Mask *pThis = Object_wx_Mask::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	wxColour *colour = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Create(*bitmap, *colour);
	return ReturnValue(env, sig, args, Value(rtn));
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
	Object_wx_Mask *pThis = Object_wx_Mask::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	int index = args.GetInt(1);
	bool rtn = pThis->GetEntity()->Create(*bitmap, index);
	return ReturnValue(env, sig, args, Value(rtn));
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
