//----------------------------------------------------------------------------
// wxImageList
// extracted from imaglist.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ImageList: public wxImageList, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_ImageList *_pObj;
public:
	inline wx_ImageList() : wxImageList(), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_ImageList(int width, int height, bool mask, int initialCount) : wxImageList(width, height, mask, initialCount), _pSig(nullptr), _pObj(nullptr) {}
	~wx_ImageList();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ImageList *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ImageList::~wx_ImageList()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ImageList::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxImageList
//----------------------------------------------------------------------------
Gura_DeclareFunction(ImageListEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ImageList));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ImageListEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ImageList *pEntity = new wx_ImageList();
	Object_wx_ImageList *pObj = Object_wx_ImageList::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ImageList(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(ImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ImageList));
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mask", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "initialCount", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ImageList)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	bool mask = true;
	if (args.IsValid(2)) mask = args.GetBoolean(2);
	int initialCount = 1;
	if (args.IsValid(3)) initialCount = args.GetInt(3);
	wx_ImageList *pEntity = new wx_ImageList(width, height, mask, initialCount);
	Object_wx_ImageList *pObj = Object_wx_ImageList::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ImageList(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_ImageList, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "mask", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, Add)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	wxBitmap *mask = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(1)) mask = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	int rtn = pThis->GetEntity()->Add(*bitmap, *mask);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ImageList, AddWithColourMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "maskColour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, AddWithColourMask)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	wxColour *maskColour = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	int rtn = pThis->GetEntity()->Add(*bitmap, *maskColour);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ImageList, AddIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, AddIcon)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxIcon *icon = Object_wx_Icon::GetObject(args, 0)->GetEntity();
	int rtn = pThis->GetEntity()->Add(*icon);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ImageList, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mask", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "initialCount", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, Create)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	bool mask = true;
	if (args.IsValid(2)) mask = args.GetBoolean(2);
	int initialCount = 1;
	if (args.IsValid(3)) initialCount = args.GetInt(3);
	bool rtn = pThis->GetEntity()->Create(width, height, mask, initialCount);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ImageList, Draw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "solidBackground", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, Draw)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int index = args.GetInt(0);
	wxDC *dc = Object_wx_DC::GetObject(args, 1)->GetEntity();
	int x = args.GetInt(2);
	int y = args.GetInt(3);
	int flags = wxIMAGELIST_DRAW_NORMAL;
	if (args.IsValid(4)) flags = args.GetInt(4);
	bool solidBackground = false;
	if (args.IsValid(5)) solidBackground = args.GetBoolean(5);
	bool rtn = pThis->GetEntity()->Draw(index, *dc, x, y, flags, solidBackground);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ImageList, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, GetBitmap)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int index = args.GetInt(0);
	wxBitmap rtn = pThis->GetEntity()->GetBitmap(index);
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ImageList, GetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, GetIcon)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int index = args.GetInt(0);
	wxIcon rtn = pThis->GetEntity()->GetIcon(index);
	return ReturnValue(env, args, Value(new Object_wx_Icon(new wxIcon(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ImageList, GetImageCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, GetImageCount)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetImageCount();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ImageList, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, GetSize)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int index = args.GetInt(0);
	int width;
	int height;
	bool rtn = pThis->GetEntity()->GetSize(index, width, height);
	Value value;
	if (rtn) value = Value::CreateList(env, width, height);
	return ReturnValue(env, args, value);
}

Gura_DeclareMethod(wx_ImageList, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, Remove)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int index = args.GetInt(0);
	bool rtn = pThis->GetEntity()->Remove(index);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ImageList, RemoveAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, RemoveAll)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->RemoveAll();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ImageList, Replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "mask", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, Replace)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int index = args.GetInt(0);
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	wxBitmap *mask = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(2)) mask = Object_wx_Bitmap::GetObject(args, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->Replace(index, *bitmap, *mask);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ImageList, ReplaceWithIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, ReplaceWithIcon)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int index = args.GetInt(0);
	wxIcon *icon = Object_wx_Icon::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Replace(index, *icon);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxImageList
//----------------------------------------------------------------------------
Object_wx_ImageList::~Object_wx_ImageList()
{
}

Object *Object_wx_ImageList::Clone() const
{
	return nullptr;
}

String Object_wx_ImageList::ToString(bool exprFlag)
{
	String rtn("<wx.ImageList:");
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
// Class implementation for wxImageList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ImageList)
{
	Gura_AssignFunction(ImageListEmpty);
	Gura_AssignFunction(ImageList);
	Gura_AssignMethod(wx_ImageList, Add);
	Gura_AssignMethod(wx_ImageList, AddWithColourMask);
	Gura_AssignMethod(wx_ImageList, AddIcon);
	Gura_AssignMethod(wx_ImageList, Create);
	Gura_AssignMethod(wx_ImageList, Draw);
	Gura_AssignMethod(wx_ImageList, GetBitmap);
	Gura_AssignMethod(wx_ImageList, GetIcon);
	Gura_AssignMethod(wx_ImageList, GetImageCount);
	Gura_AssignMethod(wx_ImageList, GetSize);
	Gura_AssignMethod(wx_ImageList, Remove);
	Gura_AssignMethod(wx_ImageList, RemoveAll);
	Gura_AssignMethod(wx_ImageList, Replace);
	Gura_AssignMethod(wx_ImageList, ReplaceWithIcon);
}

Gura_ImplementDescendantCreator(wx_ImageList)
{
	return new Object_wx_ImageList((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
