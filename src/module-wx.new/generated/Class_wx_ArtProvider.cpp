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
Gura_DeclareMethod(wx_ArtProvider, Delete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "provider", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, Delete)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int provider = arg.GetNumber(0)
	//pThis->GetEntity()->Delete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArtProvider, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, GetBitmap)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int client = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArtProvider, GetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, GetIcon)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int client = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->GetIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArtProvider, GetNativeSizeHint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "client", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, GetNativeSizeHint)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int client = arg.GetNumber(0)
	//pThis->GetEntity()->GetNativeSizeHint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArtProvider, GetSizeHint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "client", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "platform_default", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, GetSizeHint)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int client = arg.GetNumber(0)
	//int platform_default = arg.GetNumber(1)
	//pThis->GetEntity()->GetSizeHint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArtProvider, GetIconBundle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, GetIconBundle)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int client = arg.GetNumber(1)
	//pThis->GetEntity()->GetIconBundle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArtProvider, HasNativeProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArtProvider, HasNativeProvider)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasNativeProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArtProvider, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "provider", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, Insert)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int provider = arg.GetNumber(0)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArtProvider, Pop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArtProvider, Pop)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Pop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArtProvider, Push)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "provider", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, Push)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int provider = arg.GetNumber(0)
	//pThis->GetEntity()->Push();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArtProvider, PushBack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "provider", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, PushBack)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int provider = arg.GetNumber(0)
	//pThis->GetEntity()->PushBack();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArtProvider, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "provider", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, Remove)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int provider = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArtProvider, GetMessageBoxIconId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, GetMessageBoxIconId)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->GetMessageBoxIconId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArtProvider, GetMessageBoxIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, GetMessageBoxIcon)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->GetMessageBoxIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArtProvider, CreateBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, CreateBitmap)
{
	Object_wx_ArtProvider *pThis = Object_wx_ArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int client = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->CreateBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArtProvider, CreateIconBundle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArtProvider, CreateIconBundle)
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
	Gura_AssignMethod(wx_ArtProvider, Delete);
	Gura_AssignMethod(wx_ArtProvider, GetBitmap);
	Gura_AssignMethod(wx_ArtProvider, GetIcon);
	Gura_AssignMethod(wx_ArtProvider, GetNativeSizeHint);
	Gura_AssignMethod(wx_ArtProvider, GetSizeHint);
	Gura_AssignMethod(wx_ArtProvider, GetIconBundle);
	Gura_AssignMethod(wx_ArtProvider, HasNativeProvider);
	Gura_AssignMethod(wx_ArtProvider, Insert);
	Gura_AssignMethod(wx_ArtProvider, Pop);
	Gura_AssignMethod(wx_ArtProvider, Push);
	Gura_AssignMethod(wx_ArtProvider, PushBack);
	Gura_AssignMethod(wx_ArtProvider, Remove);
	Gura_AssignMethod(wx_ArtProvider, GetMessageBoxIconId);
	Gura_AssignMethod(wx_ArtProvider, GetMessageBoxIcon);
	Gura_AssignMethod(wx_ArtProvider, CreateBitmap);
	Gura_AssignMethod(wx_ArtProvider, CreateIconBundle);
}

Gura_ImplementDescendantCreator(wx_ArtProvider)
{
	return new Object_wx_ArtProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
