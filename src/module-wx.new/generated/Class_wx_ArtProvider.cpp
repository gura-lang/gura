//----------------------------------------------------------------------------
// wxArtProvider
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxArtProvider
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArtProvider
//----------------------------------------------------------------------------
Object_wx_ArtProvider::~Object_wx_ArtProvider()
{
}

Object *Object_wx_ArtProvider::Clone() const
{
	return nullptr;
}

String Object_wx_ArtProvider::ToString(bool exprFlag)
{
	String rtn("<wx.ArtProvider:");
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
Gura_DeclareMethodAlias(wx_ArtProvider, __Delete, "Delete")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "provider", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, __Delete)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int provider = arg.GetNumber(0)
	//pThis->GetEntity()->Delete();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArtProvider, __GetBitmap, "GetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, __GetBitmap)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int client = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArtProvider, __GetIcon, "GetIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, __GetIcon)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int client = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->GetIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArtProvider, __GetNativeSizeHint, "GetNativeSizeHint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "client", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, __GetNativeSizeHint)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int client = arg.GetNumber(0)
	//pThis->GetEntity()->GetNativeSizeHint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArtProvider, __GetSizeHint, "GetSizeHint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "client", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "platform_default", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, __GetSizeHint)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int client = arg.GetNumber(0)
	//int platform_default = arg.GetNumber(1)
	//pThis->GetEntity()->GetSizeHint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArtProvider, __GetIconBundle, "GetIconBundle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, __GetIconBundle)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int client = arg.GetNumber(1)
	//pThis->GetEntity()->GetIconBundle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArtProvider, __HasNativeProvider, "HasNativeProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArtProvider, __HasNativeProvider)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasNativeProvider();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArtProvider, __Insert, "Insert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "provider", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, __Insert)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int provider = arg.GetNumber(0)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArtProvider, __Pop, "Pop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArtProvider, __Pop)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Pop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArtProvider, __Push, "Push")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "provider", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, __Push)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int provider = arg.GetNumber(0)
	//pThis->GetEntity()->Push();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArtProvider, __PushBack, "PushBack")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "provider", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, __PushBack)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int provider = arg.GetNumber(0)
	//pThis->GetEntity()->PushBack();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArtProvider, __Remove, "Remove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "provider", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, __Remove)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int provider = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArtProvider, __GetMessageBoxIconId, "GetMessageBoxIconId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, __GetMessageBoxIconId)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->GetMessageBoxIconId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArtProvider, __GetMessageBoxIcon, "GetMessageBoxIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, __GetMessageBoxIcon)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->GetMessageBoxIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArtProvider, __CreateBitmap, "CreateBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, __CreateBitmap)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int client = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->CreateBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArtProvider, __CreateIconBundle, "CreateIconBundle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, __CreateIconBundle)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int client = arg.GetNumber(1)
	//pThis->GetEntity()->CreateIconBundle();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxArtProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArtProvider)
{
	Gura_AssignMethod(wx_ArtProvider, __Delete);
	Gura_AssignMethod(wx_ArtProvider, __GetBitmap);
	Gura_AssignMethod(wx_ArtProvider, __GetIcon);
	Gura_AssignMethod(wx_ArtProvider, __GetNativeSizeHint);
	Gura_AssignMethod(wx_ArtProvider, __GetSizeHint);
	Gura_AssignMethod(wx_ArtProvider, __GetIconBundle);
	Gura_AssignMethod(wx_ArtProvider, __HasNativeProvider);
	Gura_AssignMethod(wx_ArtProvider, __Insert);
	Gura_AssignMethod(wx_ArtProvider, __Pop);
	Gura_AssignMethod(wx_ArtProvider, __Push);
	Gura_AssignMethod(wx_ArtProvider, __PushBack);
	Gura_AssignMethod(wx_ArtProvider, __Remove);
	Gura_AssignMethod(wx_ArtProvider, __GetMessageBoxIconId);
	Gura_AssignMethod(wx_ArtProvider, __GetMessageBoxIcon);
	Gura_AssignMethod(wx_ArtProvider, __CreateBitmap);
	Gura_AssignMethod(wx_ArtProvider, __CreateIconBundle);
}

Gura_ImplementDescendantCreator(wx_ArtProvider)
{
	return new Object_wx_ArtProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
