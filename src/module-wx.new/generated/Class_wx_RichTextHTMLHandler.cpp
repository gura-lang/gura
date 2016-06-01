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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextHTMLHandler, wxRichTextHTMLHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, wxRichTextHTMLHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int ext = arg.GetNumber(1)
	//int type = arg.GetNumber(2)
	//pThis->GetEntity()->wxRichTextHTMLHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, ClearTemporaryImageLocations)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, ClearTemporaryImageLocations)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ClearTemporaryImageLocations();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, DeleteTemporaryImages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, DeleteTemporaryImages)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DeleteTemporaryImages();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, DeleteTemporaryImages_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageLocations", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, DeleteTemporaryImages_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int imageLocations = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteTemporaryImages();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, GetFontSizeMapping)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, GetFontSizeMapping)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFontSizeMapping();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, GetTempDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, GetTempDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTempDir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, GetTemporaryImageLocations)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, GetTemporaryImageLocations)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTemporaryImageLocations();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, SetFileCounter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "counter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, SetFileCounter)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int counter = arg.GetNumber(0)
	//pThis->GetEntity()->SetFileCounter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, SetFontSizeMapping)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fontSizeMapping", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, SetFontSizeMapping)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fontSizeMapping = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontSizeMapping();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, SetTempDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tempDir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, SetTempDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int tempDir = arg.GetNumber(0)
	//pThis->GetEntity()->SetTempDir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, SetTemporaryImageLocations)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "locations", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, SetTemporaryImageLocations)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int locations = arg.GetNumber(0)
	//pThis->GetEntity()->SetTemporaryImageLocations();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHTMLHandler, DoSaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHTMLHandler, DoSaveFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHTMLHandler *pThis = Object_wx_RichTextHTMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_RichTextHTMLHandler, wxRichTextHTMLHandler);
	Gura_AssignMethod(wx_RichTextHTMLHandler, ClearTemporaryImageLocations);
	Gura_AssignMethod(wx_RichTextHTMLHandler, DeleteTemporaryImages);
	Gura_AssignMethod(wx_RichTextHTMLHandler, DeleteTemporaryImages_1);
	Gura_AssignMethod(wx_RichTextHTMLHandler, GetFontSizeMapping);
	Gura_AssignMethod(wx_RichTextHTMLHandler, GetTempDir);
	Gura_AssignMethod(wx_RichTextHTMLHandler, GetTemporaryImageLocations);
	Gura_AssignMethod(wx_RichTextHTMLHandler, SetFileCounter);
	Gura_AssignMethod(wx_RichTextHTMLHandler, SetFontSizeMapping);
	Gura_AssignMethod(wx_RichTextHTMLHandler, SetTempDir);
	Gura_AssignMethod(wx_RichTextHTMLHandler, SetTemporaryImageLocations);
	Gura_AssignMethod(wx_RichTextHTMLHandler, DoSaveFile);
}

Gura_ImplementDescendantCreator(wx_RichTextHTMLHandler)
{
	return new Object_wx_RichTextHTMLHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
