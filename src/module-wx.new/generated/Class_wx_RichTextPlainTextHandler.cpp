//----------------------------------------------------------------------------
// wxRichTextPlainTextHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextPlainTextHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextPlainTextHandler
//----------------------------------------------------------------------------
Object_wx_RichTextPlainTextHandler::~Object_wx_RichTextPlainTextHandler()
{
}

Object *Object_wx_RichTextPlainTextHandler::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextPlainTextHandler::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextPlainTextHandler:");
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
Gura_DeclareFunctionAlias(__wxRichTextPlainTextHandler, "wxRichTextPlainTextHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextPlainTextHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextPlainTextHandler)
{
	//int name = arg.GetNumber(0)
	//int ext = arg.GetNumber(1)
	//int type = arg.GetNumber(2)
	//wxRichTextPlainTextHandler();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextPlainTextHandler, __CanSave, "CanSave")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainTextHandler, __CanSave)
{
	Object_wx_RichTextPlainTextHandler *pThis = Object_wx_RichTextPlainTextHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanSave();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainTextHandler, __CanLoad, "CanLoad")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainTextHandler, __CanLoad)
{
	Object_wx_RichTextPlainTextHandler *pThis = Object_wx_RichTextPlainTextHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanLoad();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainTextHandler, __DoLoadFile, "DoLoadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainTextHandler, __DoLoadFile)
{
	Object_wx_RichTextPlainTextHandler *pThis = Object_wx_RichTextPlainTextHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int stream = arg.GetNumber(1)
	//pThis->GetEntity()->DoLoadFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainTextHandler, __DoSaveFile, "DoSaveFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainTextHandler, __DoSaveFile)
{
	Object_wx_RichTextPlainTextHandler *pThis = Object_wx_RichTextPlainTextHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int stream = arg.GetNumber(1)
	//pThis->GetEntity()->DoSaveFile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextPlainTextHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextPlainTextHandler)
{
	// Constructor assignment
	Gura_AssignFunction(__wxRichTextPlainTextHandler);
	// Method assignment
	Gura_AssignMethod(wx_RichTextPlainTextHandler, __CanSave);
	Gura_AssignMethod(wx_RichTextPlainTextHandler, __CanLoad);
	Gura_AssignMethod(wx_RichTextPlainTextHandler, __DoLoadFile);
	Gura_AssignMethod(wx_RichTextPlainTextHandler, __DoSaveFile);
}

Gura_ImplementDescendantCreator(wx_RichTextPlainTextHandler)
{
	return new Object_wx_RichTextPlainTextHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
