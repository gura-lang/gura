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
	//Gura::Signal *_pSig;
	Object_wx_ImageList *_pObj;
public:
	inline wx_ImageList() : wxImageList(), _pObj(nullptr) {}
	inline wx_ImageList(int width, int height, bool mask, int initialCount) : wxImageList(width, height, mask, initialCount), _pObj(nullptr) {}
	~wx_ImageList();
	inline void AssocWithGura(Object_wx_ImageList *pObj) {
		_pObj = pObj;
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_ImageList *pEntity = new wx_ImageList();
	Object_wx_ImageList *pObj = Object_wx_ImageList::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_ImageList(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int width = arg.GetInt(0);
	int height = arg.GetInt(1);
	bool mask = true;
	if (arg.IsValid(2)) mask = arg.GetBoolean(2);
	int initialCount = 1;
	if (arg.IsValid(3)) initialCount = arg.GetInt(3);
	wx_ImageList *pEntity = new wx_ImageList(width, height, mask, initialCount);
	Object_wx_ImageList *pObj = Object_wx_ImageList::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_ImageList(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
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
	Signal &sig = env.GetSignal();
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(arg, 0)->GetEntity();
	wxBitmap *mask = (wxBitmap *)(&wxNullBitmap);
	if (arg.IsValid(1)) mask = Object_wx_Bitmap::GetObject(arg, 1)->GetEntity();
	int rtn = pThis->GetEntity()->Add(*bitmap, *mask);
	return ReturnValue(env, arg, Value(rtn));
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
	Signal &sig = env.GetSignal();
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(arg, 0)->GetEntity();
	wxColour *maskColour = Object_wx_Colour::GetObject(arg, 1)->GetEntity();
	int rtn = pThis->GetEntity()->Add(*bitmap, *maskColour);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ImageList, AddIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, AddIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxIcon *icon = Object_wx_Icon::GetObject(arg, 0)->GetEntity();
	int rtn = pThis->GetEntity()->Add(*icon);
	return ReturnValue(env, arg, Value(rtn));
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
	Signal &sig = env.GetSignal();
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width = arg.GetInt(0);
	int height = arg.GetInt(1);
	bool mask = true;
	if (arg.IsValid(2)) mask = arg.GetBoolean(2);
	int initialCount = 1;
	if (arg.IsValid(3)) initialCount = arg.GetInt(3);
	bool rtn = pThis->GetEntity()->Create(width, height, mask, initialCount);
	return ReturnValue(env, arg, Value(rtn));
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
	Signal &sig = env.GetSignal();
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int index = arg.GetInt(0);
	wxDC *dc = Object_wx_DC::GetObject(arg, 1)->GetEntity();
	int x = arg.GetInt(2);
	int y = arg.GetInt(3);
	int flags = wxIMAGELIST_DRAW_NORMAL;
	if (arg.IsValid(4)) flags = arg.GetInt(4);
	bool solidBackground = false;
	if (arg.IsValid(5)) solidBackground = arg.GetBoolean(5);
	bool rtn = pThis->GetEntity()->Draw(index, *dc, x, y, flags, solidBackground);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ImageList, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, GetBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int index = arg.GetInt(0);
	wxBitmap rtn = pThis->GetEntity()->GetBitmap(index);
	return ReturnValue(env, arg, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ImageList, GetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, GetIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int index = arg.GetInt(0);
	wxIcon rtn = pThis->GetEntity()->GetIcon(index);
	return ReturnValue(env, arg, Value(new Object_wx_Icon(new wxIcon(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ImageList, GetImageCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, GetImageCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetImageCount();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ImageList, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int index = arg.GetInt(0);
	int width;
	int height;
	bool rtn = pThis->GetEntity()->GetSize(index, width, height);
	Value value;
	if (rtn) value = Value::CreateList(env, width, height);
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_ImageList, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, Remove)
{
	Signal &sig = env.GetSignal();
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int index = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->Remove(index);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ImageList, RemoveAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ImageList, RemoveAll)
{
	Signal &sig = env.GetSignal();
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->RemoveAll();
	return ReturnValue(env, arg, Value(rtn));
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
	Signal &sig = env.GetSignal();
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int index = arg.GetInt(0);
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(arg, 1)->GetEntity();
	wxBitmap *mask = (wxBitmap *)(&wxNullBitmap);
	if (arg.IsValid(2)) mask = Object_wx_Bitmap::GetObject(arg, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->Replace(index, *bitmap, *mask);
	return ReturnValue(env, arg, Value(rtn));
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
	Signal &sig = env.GetSignal();
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int index = arg.GetInt(0);
	wxIcon *icon = Object_wx_Icon::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Replace(index, *icon);
	return ReturnValue(env, arg, Value(rtn));
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
