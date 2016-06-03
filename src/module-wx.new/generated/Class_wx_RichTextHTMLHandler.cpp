//----------------------------------------------------------------------------
// wxRichTextHTMLHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextHTMLHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextHTMLHandler
//----------------------------------------------------------------------------
Object_wx_RichTextHTMLHandler::~Object_wx_RichTextHTMLHandler()
{
}

Object *Object_wx_RichTextHTMLHandler::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextHTMLHandler::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextHTMLHandler:");
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
Gura_DeclareFunctionAlias(__wxRichTextHTMLHandler, "wxRichTextHTMLHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxRichTextHTMLHandler)
{
	//int name = arg.GetNumber(0)
	//int ext = arg.GetNumber(1)
	//int type = arg.GetNumber(2)
	//wxRichTextHTMLHandler();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextHTMLHandler, __ClearTemporaryImageLocations, "ClearTemporaryImageLocations")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, __ClearTemporaryImageLocations)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearTemporaryImageLocations();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHTMLHandler, __DeleteTemporaryImages, "DeleteTemporaryImages")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, __DeleteTemporaryImages)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteTemporaryImages();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHTMLHandler, __DeleteTemporaryImages_1, "DeleteTemporaryImages_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageLocations", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, __DeleteTemporaryImages_1)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int imageLocations = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteTemporaryImages();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHTMLHandler, __GetFontSizeMapping, "GetFontSizeMapping")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, __GetFontSizeMapping)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFontSizeMapping();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHTMLHandler, __GetTempDir, "GetTempDir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, __GetTempDir)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTempDir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHTMLHandler, __GetTemporaryImageLocations, "GetTemporaryImageLocations")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, __GetTemporaryImageLocations)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTemporaryImageLocations();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHTMLHandler, __SetFileCounter, "SetFileCounter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "counter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, __SetFileCounter)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int counter = arg.GetNumber(0)
	//pThis->GetEntity()->SetFileCounter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHTMLHandler, __SetFontSizeMapping, "SetFontSizeMapping")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fontSizeMapping", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, __SetFontSizeMapping)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fontSizeMapping = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontSizeMapping();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHTMLHandler, __SetTempDir, "SetTempDir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tempDir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, __SetTempDir)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tempDir = arg.GetNumber(0)
	//pThis->GetEntity()->SetTempDir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHTMLHandler, __SetTemporaryImageLocations, "SetTemporaryImageLocations")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "locations", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, __SetTemporaryImageLocations)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int locations = arg.GetNumber(0)
	//pThis->GetEntity()->SetTemporaryImageLocations();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHTMLHandler, __DoSaveFile, "DoSaveFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, __DoSaveFile)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int stream = arg.GetNumber(1)
	//pThis->GetEntity()->DoSaveFile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextHTMLHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextHTMLHandler)
{
	// Constructor assignment
	Gura_AssignFunction(__wxRichTextHTMLHandler);
	// Method assignment
	Gura_AssignMethod(wx_RichTextHTMLHandler, __ClearTemporaryImageLocations);
	Gura_AssignMethod(wx_RichTextHTMLHandler, __DeleteTemporaryImages);
	Gura_AssignMethod(wx_RichTextHTMLHandler, __DeleteTemporaryImages_1);
	Gura_AssignMethod(wx_RichTextHTMLHandler, __GetFontSizeMapping);
	Gura_AssignMethod(wx_RichTextHTMLHandler, __GetTempDir);
	Gura_AssignMethod(wx_RichTextHTMLHandler, __GetTemporaryImageLocations);
	Gura_AssignMethod(wx_RichTextHTMLHandler, __SetFileCounter);
	Gura_AssignMethod(wx_RichTextHTMLHandler, __SetFontSizeMapping);
	Gura_AssignMethod(wx_RichTextHTMLHandler, __SetTempDir);
	Gura_AssignMethod(wx_RichTextHTMLHandler, __SetTemporaryImageLocations);
	Gura_AssignMethod(wx_RichTextHTMLHandler, __DoSaveFile);
}

Gura_ImplementDescendantCreator(wx_RichTextHTMLHandler)
{
	return new Object_wx_RichTextHTMLHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
