//----------------------------------------------------------------------------
// wxBitmapDataObject
// extracted from bmpdatob.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(GetBitmap);
Gura_DeclarePrivUserSymbol(SetBitmap);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_BitmapDataObject: public wxBitmapDataObject, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_BitmapDataObject *_pObj;
public:
	inline wx_BitmapDataObject(const wxBitmap& bitmap) : wxBitmapDataObject(bitmap), _pObj(nullptr) {}
	//virtual wxBitmap GetBitmap();
	//virtual void SetBitmap(const wxBitmap& bitmap);
	~wx_BitmapDataObject();
	inline void AssocWithGura(Object_wx_BitmapDataObject *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BitmapDataObject::~wx_BitmapDataObject()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_BitmapDataObject::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBitmapDataObject
//----------------------------------------------------------------------------
Gura_DeclareFunction(BitmapDataObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_BitmapDataObject));
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BitmapDataObject)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxBitmap *bitmap = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(0)) bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	wx_BitmapDataObject *pEntity = new wx_BitmapDataObject(*bitmap);
	Object_wx_BitmapDataObject *pObj = Object_wx_BitmapDataObject::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_BitmapDataObject(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_BitmapDataObject, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapDataObject, GetBitmap)
{
	Object_wx_BitmapDataObject *pThis = Object_wx_BitmapDataObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap rtn = pThis->GetEntity()->GetBitmap();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_BitmapDataObject, SetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapDataObject, SetBitmap)
{
	Object_wx_BitmapDataObject *pThis = Object_wx_BitmapDataObject::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBitmap(*bitmap);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxBitmapDataObject
//----------------------------------------------------------------------------
Object_wx_BitmapDataObject::~Object_wx_BitmapDataObject()
{
}

Object *Object_wx_BitmapDataObject::Clone() const
{
	return nullptr;
}

String Object_wx_BitmapDataObject::ToString(bool exprFlag)
{
	String rtn("<wx.BitmapDataObject:");
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
// Class implementation for wxBitmapDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BitmapDataObject)
{
	Gura_RealizeUserSymbol(GetBitmap);
	Gura_RealizeUserSymbol(SetBitmap);
	Gura_AssignFunction(BitmapDataObject);
	Gura_AssignMethod(wx_BitmapDataObject, GetBitmap);
	Gura_AssignMethod(wx_BitmapDataObject, SetBitmap);
}

Gura_ImplementDescendantCreator(wx_BitmapDataObject)
{
	return new Object_wx_BitmapDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
