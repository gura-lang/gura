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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RichTextImage, "RichTextImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextImage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextImage)
{
	//wxRichTextObject* parent = arg.GetNumber(0)
	//wxRichTextImage(parent);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextImage_1, "RichTextImage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "charStyle", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextImage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextImage_1)
{
	//const wxImage& image = arg.GetNumber(0)
	//wxRichTextObject* parent = arg.GetNumber(1)
	//wxRichTextAttr* charStyle = arg.GetNumber(2)
	//wxRichTextImage(image, parent, charStyle);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextImage_2, "RichTextImage_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageBlock", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "charStyle", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextImage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextImage_2)
{
	//const wxRichTextImageBlock& imageBlock = arg.GetNumber(0)
	//wxRichTextObject* parent = arg.GetNumber(1)
	//wxRichTextAttr* charStyle = arg.GetNumber(2)
	//wxRichTextImage(imageBlock, parent, charStyle);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextImage_3, "RichTextImage_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextImage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextImage_3)
{
	//const wxRichTextImage& obj = arg.GetNumber(0)
	//wxRichTextImage(obj);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextImage, __Draw, "Draw")
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

Gura_ImplementMethod(wx_RichTextImage, __Draw)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//const wxRichTextRange& range = arg.GetNumber(2)
	//const wxRichTextSelection& selection = arg.GetNumber(3)
	//const wxRect& rect = arg.GetNumber(4)
	//int descent = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//pThis->GetEntity()->Draw(dc, context, range, selection, rect, descent, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __Layout, "Layout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, __Layout)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//const wxRect& parentRect = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Layout(dc, context, rect, parentRect, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __GetRangeSize, "GetRangeSize")
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

Gura_ImplementMethod(wx_RichTextImage, __GetRangeSize)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//wxSize& size = arg.GetNumber(1)
	//int& descent = arg.GetNumber(2)
	//wxDC& dc = arg.GetNumber(3)
	//wxRichTextDrawingContext& context = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//const wxPoint& position = arg.GetNumber(6)
	//const wxSize& parentSize = arg.GetNumber(7)
	//wxArrayInt* partialExtents = arg.GetNumber(8)
	//pThis->GetEntity()->GetRangeSize(range, size, descent, dc, context, flags, position, parentSize, partialExtents);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __GetNaturalSize, "GetNaturalSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, __GetNaturalSize)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNaturalSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, __IsEmpty)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __CanEditProperties, "CanEditProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, __CanEditProperties)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanEditProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __EditProperties, "EditProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, __EditProperties)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxRichTextBuffer* buffer = arg.GetNumber(1)
	//pThis->GetEntity()->EditProperties(parent, buffer);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __GetPropertiesMenuLabel, "GetPropertiesMenuLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, __GetPropertiesMenuLabel)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPropertiesMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __UsesParagraphAttributes, "UsesParagraphAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, __UsesParagraphAttributes)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UsesParagraphAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __ImportFromXML, "ImportFromXML")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recurse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, __ImportFromXML)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//wxXmlNode* node = arg.GetNumber(1)
	//wxRichTextXMLHandler* handler = arg.GetNumber(2)
	//bool* recurse = arg.GetNumber(3)
	//pThis->GetEntity()->ImportFromXML(buffer, node, handler, recurse);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __ExportXML, "ExportXML")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, __ExportXML)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxOutputStream& stream = arg.GetNumber(0)
	//int indent = arg.GetNumber(1)
	//wxRichTextXMLHandler* handler = arg.GetNumber(2)
	//pThis->GetEntity()->ExportXML(stream, indent, handler);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __ExportXML_1, "ExportXML_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, __ExportXML_1)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxXmlNode* parent = arg.GetNumber(0)
	//wxRichTextXMLHandler* handler = arg.GetNumber(1)
	//pThis->GetEntity()->ExportXML(parent, handler);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __IsFloatable, "IsFloatable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, __IsFloatable)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFloatable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __GetXMLNodeName, "GetXMLNodeName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, __GetXMLNodeName)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetXMLNodeName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __GetImageCache, "GetImageCache")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, __GetImageCache)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImageCache();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __SetImageCache, "SetImageCache")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, __SetImageCache)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetImageCache(bitmap);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __ResetImageCache, "ResetImageCache")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, __ResetImageCache)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ResetImageCache();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __GetImageBlock, "GetImageBlock")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, __GetImageBlock)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImageBlock();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __GetOriginalImageSize, "GetOriginalImageSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, __GetOriginalImageSize)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOriginalImageSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __SetOriginalImageSize, "SetOriginalImageSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, __SetOriginalImageSize)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetOriginalImageSize(sz);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, __Copy)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextImage& obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, __Clone)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __LoadImageCache, "LoadImageCache")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "retImageSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "resetCache", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, __LoadImageCache)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//wxSize& retImageSize = arg.GetNumber(2)
	//bool resetCache = arg.GetNumber(3)
	//const wxSize& parentSize = arg.GetNumber(4)
	//pThis->GetEntity()->LoadImageCache(dc, context, retImageSize, resetCache, parentSize);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __LoadAndScaleImageCache, "LoadAndScaleImageCache")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "delayLoading", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "changed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, __LoadAndScaleImageCache)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxImage& image = arg.GetNumber(0)
	//const wxSize& sz = arg.GetNumber(1)
	//bool delayLoading = arg.GetNumber(2)
	//bool& changed = arg.GetNumber(3)
	//pThis->GetEntity()->LoadAndScaleImageCache(image, sz, delayLoading, changed);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __GetImageState, "GetImageState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImage, __GetImageState)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImageState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImage, __SetImageState, "SetImageState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImage, __SetImageState)
{
	Object_wx_RichTextImage *pThis = Object_wx_RichTextImage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int state = arg.GetNumber(0)
	//pThis->GetEntity()->SetImageState(state);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextImage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextImage)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextImage);
	Gura_AssignFunction(__RichTextImage_1);
	Gura_AssignFunction(__RichTextImage_2);
	Gura_AssignFunction(__RichTextImage_3);
	// Method assignment
	Gura_AssignMethod(wx_RichTextImage, __Draw);
	Gura_AssignMethod(wx_RichTextImage, __Layout);
	Gura_AssignMethod(wx_RichTextImage, __GetRangeSize);
	Gura_AssignMethod(wx_RichTextImage, __GetNaturalSize);
	Gura_AssignMethod(wx_RichTextImage, __IsEmpty);
	Gura_AssignMethod(wx_RichTextImage, __CanEditProperties);
	Gura_AssignMethod(wx_RichTextImage, __EditProperties);
	Gura_AssignMethod(wx_RichTextImage, __GetPropertiesMenuLabel);
	Gura_AssignMethod(wx_RichTextImage, __UsesParagraphAttributes);
	Gura_AssignMethod(wx_RichTextImage, __ImportFromXML);
	Gura_AssignMethod(wx_RichTextImage, __ExportXML);
	Gura_AssignMethod(wx_RichTextImage, __ExportXML_1);
	Gura_AssignMethod(wx_RichTextImage, __IsFloatable);
	Gura_AssignMethod(wx_RichTextImage, __GetXMLNodeName);
	Gura_AssignMethod(wx_RichTextImage, __GetImageCache);
	Gura_AssignMethod(wx_RichTextImage, __SetImageCache);
	Gura_AssignMethod(wx_RichTextImage, __ResetImageCache);
	Gura_AssignMethod(wx_RichTextImage, __GetImageBlock);
	Gura_AssignMethod(wx_RichTextImage, __GetOriginalImageSize);
	Gura_AssignMethod(wx_RichTextImage, __SetOriginalImageSize);
	Gura_AssignMethod(wx_RichTextImage, __Copy);
	Gura_AssignMethod(wx_RichTextImage, __Clone);
	Gura_AssignMethod(wx_RichTextImage, __LoadImageCache);
	Gura_AssignMethod(wx_RichTextImage, __LoadAndScaleImageCache);
	Gura_AssignMethod(wx_RichTextImage, __GetImageState);
	Gura_AssignMethod(wx_RichTextImage, __SetImageState);
}

Gura_ImplementDescendantCreator(wx_RichTextImage)
{
	return new Object_wx_RichTextImage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
