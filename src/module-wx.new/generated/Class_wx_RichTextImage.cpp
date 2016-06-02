//----------------------------------------------------------------------------
// wxRichTextImage
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextImage
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextImage
//----------------------------------------------------------------------------
Object_wx_RichTextImage::~Object_wx_RichTextImage()
{
}

Object *Object_wx_RichTextImage::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextImage::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextImage:");
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
Gura_DeclareMethod(wx_RichTextImage, wxRichTextImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, wxRichTextImage)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, wxRichTextImage_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "charStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, wxRichTextImage_1)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int charStyle = arg.GetNumber(2)
	//pThis->GetEntity()->wxRichTextImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, wxRichTextImage_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageBlock", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "charStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, wxRichTextImage_2)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imageBlock = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int charStyle = arg.GetNumber(2)
	//pThis->GetEntity()->wxRichTextImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, wxRichTextImage_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, wxRichTextImage_3)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, Draw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, Draw)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int range = arg.GetNumber(2)
	//int selection = arg.GetNumber(3)
	//int rect = arg.GetNumber(4)
	//int descent = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//pThis->GetEntity()->Draw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, Layout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, Layout)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int parentRect = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Layout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, GetRangeSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "partialExtents", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, GetRangeSize)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int descent = arg.GetNumber(2)
	//int dc = arg.GetNumber(3)
	//int context = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//int position = arg.GetNumber(6)
	//int parentSize = arg.GetNumber(7)
	//int partialExtents = arg.GetNumber(8)
	//pThis->GetEntity()->GetRangeSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, GetNaturalSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, GetNaturalSize)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNaturalSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, IsEmpty)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, CanEditProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, CanEditProperties)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanEditProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, EditProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, EditProperties)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//pThis->GetEntity()->EditProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, GetPropertiesMenuLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, GetPropertiesMenuLabel)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPropertiesMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, UsesParagraphAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, UsesParagraphAttributes)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UsesParagraphAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, ImportFromXML)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recurse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, ImportFromXML)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int node = arg.GetNumber(1)
	//int handler = arg.GetNumber(2)
	//int recurse = arg.GetNumber(3)
	//pThis->GetEntity()->ImportFromXML();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, ExportXML)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, ExportXML)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int indent = arg.GetNumber(1)
	//int handler = arg.GetNumber(2)
	//pThis->GetEntity()->ExportXML();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, ExportXML_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, ExportXML_1)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int handler = arg.GetNumber(1)
	//pThis->GetEntity()->ExportXML();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, IsFloatable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, IsFloatable)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFloatable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, GetXMLNodeName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, GetXMLNodeName)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetXMLNodeName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, GetImageCache)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, GetImageCache)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImageCache();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, SetImageCache)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, SetImageCache)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetImageCache();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, ResetImageCache)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, ResetImageCache)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ResetImageCache();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, GetImageBlock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, GetImageBlock)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImageBlock();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, GetOriginalImageSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, GetOriginalImageSize)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOriginalImageSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, SetOriginalImageSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, SetOriginalImageSize)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetOriginalImageSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, Copy)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, Clone)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, LoadImageCache)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "retImageSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "resetCache", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, LoadImageCache)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int retImageSize = arg.GetNumber(2)
	//int resetCache = arg.GetNumber(3)
	//int parentSize = arg.GetNumber(4)
	//pThis->GetEntity()->LoadImageCache();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, LoadAndScaleImageCache)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "delayLoading", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "changed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, LoadAndScaleImageCache)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//int sz = arg.GetNumber(1)
	//int delayLoading = arg.GetNumber(2)
	//int changed = arg.GetNumber(3)
	//pThis->GetEntity()->LoadAndScaleImageCache();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, GetImageState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, GetImageState)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImageState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImage, SetImageState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, SetImageState)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int state = arg.GetNumber(0)
	//pThis->GetEntity()->SetImageState();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextImage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextImage)
{
	Gura_AssignMethod(wx_RichTextImage, wxRichTextImage);
	Gura_AssignMethod(wx_RichTextImage, wxRichTextImage_1);
	Gura_AssignMethod(wx_RichTextImage, wxRichTextImage_2);
	Gura_AssignMethod(wx_RichTextImage, wxRichTextImage_3);
	Gura_AssignMethod(wx_RichTextImage, Draw);
	Gura_AssignMethod(wx_RichTextImage, Layout);
	Gura_AssignMethod(wx_RichTextImage, GetRangeSize);
	Gura_AssignMethod(wx_RichTextImage, GetNaturalSize);
	Gura_AssignMethod(wx_RichTextImage, IsEmpty);
	Gura_AssignMethod(wx_RichTextImage, CanEditProperties);
	Gura_AssignMethod(wx_RichTextImage, EditProperties);
	Gura_AssignMethod(wx_RichTextImage, GetPropertiesMenuLabel);
	Gura_AssignMethod(wx_RichTextImage, UsesParagraphAttributes);
	Gura_AssignMethod(wx_RichTextImage, ImportFromXML);
	Gura_AssignMethod(wx_RichTextImage, ExportXML);
	Gura_AssignMethod(wx_RichTextImage, ExportXML_1);
	Gura_AssignMethod(wx_RichTextImage, IsFloatable);
	Gura_AssignMethod(wx_RichTextImage, GetXMLNodeName);
	Gura_AssignMethod(wx_RichTextImage, GetImageCache);
	Gura_AssignMethod(wx_RichTextImage, SetImageCache);
	Gura_AssignMethod(wx_RichTextImage, ResetImageCache);
	Gura_AssignMethod(wx_RichTextImage, GetImageBlock);
	Gura_AssignMethod(wx_RichTextImage, GetOriginalImageSize);
	Gura_AssignMethod(wx_RichTextImage, SetOriginalImageSize);
	Gura_AssignMethod(wx_RichTextImage, Copy);
	Gura_AssignMethod(wx_RichTextImage, Clone);
	Gura_AssignMethod(wx_RichTextImage, LoadImageCache);
	Gura_AssignMethod(wx_RichTextImage, LoadAndScaleImageCache);
	Gura_AssignMethod(wx_RichTextImage, GetImageState);
	Gura_AssignMethod(wx_RichTextImage, SetImageState);
}

Gura_ImplementDescendantCreator(wx_RichTextImage)
{
	return new Object_wx_RichTextImage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
