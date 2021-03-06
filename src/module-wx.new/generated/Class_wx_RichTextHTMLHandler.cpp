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
Gura_DeclareFunctionAlias(__RichTextHTMLHandler, "RichTextHTMLHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextHTMLHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextHTMLHandler)
{
	//const wxString& name = arg.GetNumber(0)
	//const wxString& ext = arg.GetNumber(1)
	//int type = arg.GetNumber(2)
	//wxRichTextHTMLHandler(name, ext, type);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, __DeleteTemporaryImages)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->DeleteTemporaryImages();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHTMLHandler, __DeleteTemporaryImages_1, "DeleteTemporaryImages_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageLocations", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, __DeleteTemporaryImages_1)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//const wxArrayString& imageLocations = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->DeleteTemporaryImages(flags, imageLocations);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHTMLHandler, __GetFontSizeMapping, "GetFontSizeMapping")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, __GetFontSizeMapping)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArrayInt _rtn = pThis->GetEntity()->GetFontSizeMapping();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHTMLHandler, __GetTempDir, "GetTempDir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, __GetTempDir)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetTempDir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHTMLHandler, __GetTemporaryImageLocations, "GetTemporaryImageLocations")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, __GetTemporaryImageLocations)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayString& _rtn = pThis->GetEntity()->GetTemporaryImageLocations();
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
	//pThis->GetEntity()->SetFileCounter(counter);
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
	//const wxArrayInt& fontSizeMapping = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontSizeMapping(fontSizeMapping);
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
	//const wxString& tempDir = arg.GetNumber(0)
	//pThis->GetEntity()->SetTempDir(tempDir);
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
	//const wxArrayString& locations = arg.GetNumber(0)
	//pThis->GetEntity()->SetTemporaryImageLocations(locations);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHTMLHandler, __DoSaveFile, "DoSaveFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, __DoSaveFile)
{
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//wxOutputStream& stream = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->DoSaveFile(buffer, stream);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextHTMLHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextHTMLHandler)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextHTMLHandler);
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
