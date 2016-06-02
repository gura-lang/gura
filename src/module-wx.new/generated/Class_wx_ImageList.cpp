//----------------------------------------------------------------------------
// wxImageList
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxImageList
//----------------------------------------------------------------------------

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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ImageList, wxImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ImageList, wxImageList)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxImageList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageList, wxImageList_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "initialCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageList, wxImageList_1)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//int mask = arg.GetNumber(2)
	//int initialCount = arg.GetNumber(3)
	//pThis->GetEntity()->wxImageList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageList, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageList, Add)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int mask = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageList, Add_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maskColour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageList, Add_1)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int maskColour = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageList, Add_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageList, Add_2)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int icon = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageList, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "initialCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageList, Create)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//int mask = arg.GetNumber(2)
	//int initialCount = arg.GetNumber(3)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageList, Draw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "solidBackground", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageList, Draw)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int x = arg.GetNumber(2)
	//int y = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//int solidBackground = arg.GetNumber(5)
	//pThis->GetEntity()->Draw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageList, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageList, GetBitmap)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageList, GetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageList, GetIcon)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->GetIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageList, GetImageCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ImageList, GetImageCount)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImageCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageList, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageList, GetSize)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageList, GetSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ImageList, GetSize_1)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageList, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageList, Remove)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageList, RemoveAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ImageList, RemoveAll)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RemoveAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageList, Replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageList, Replace)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//int mask = arg.GetNumber(2)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageList, Replace_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageList, Replace_1)
{
	Object_wx_ImageList *pThis = Object_wx_ImageList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int icon = arg.GetNumber(1)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxImageList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ImageList)
{
	Gura_AssignMethod(wx_ImageList, wxImageList);
	Gura_AssignMethod(wx_ImageList, wxImageList_1);
	Gura_AssignMethod(wx_ImageList, Add);
	Gura_AssignMethod(wx_ImageList, Add_1);
	Gura_AssignMethod(wx_ImageList, Add_2);
	Gura_AssignMethod(wx_ImageList, Create);
	Gura_AssignMethod(wx_ImageList, Draw);
	Gura_AssignMethod(wx_ImageList, GetBitmap);
	Gura_AssignMethod(wx_ImageList, GetIcon);
	Gura_AssignMethod(wx_ImageList, GetImageCount);
	Gura_AssignMethod(wx_ImageList, GetSize);
	Gura_AssignMethod(wx_ImageList, GetSize_1);
	Gura_AssignMethod(wx_ImageList, Remove);
	Gura_AssignMethod(wx_ImageList, RemoveAll);
	Gura_AssignMethod(wx_ImageList, Replace);
	Gura_AssignMethod(wx_ImageList, Replace_1);
}

Gura_ImplementDescendantCreator(wx_ImageList)
{
	return new Object_wx_ImageList((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
