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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextPlainTextHandler, wxRichTextPlainTextHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainTextHandler, wxRichTextPlainTextHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainTextHandler *pThis = Object_wx_RichTextPlainTextHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int ext = arg.GetNumber(1)
	//int type = arg.GetNumber(2)
	//pThis->GetEntity()->wxRichTextPlainTextHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainTextHandler, CanSave)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainTextHandler, CanSave)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainTextHandler *pThis = Object_wx_RichTextPlainTextHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanSave();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainTextHandler, CanLoad)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainTextHandler, CanLoad)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainTextHandler *pThis = Object_wx_RichTextPlainTextHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanLoad();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainTextHandler, DoLoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainTextHandler, DoLoadFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainTextHandler *pThis = Object_wx_RichTextPlainTextHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int stream = arg.GetNumber(1)
	//pThis->GetEntity()->DoLoadFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainTextHandler, DoSaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainTextHandler, DoSaveFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainTextHandler *pThis = Object_wx_RichTextPlainTextHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_RichTextPlainTextHandler, wxRichTextPlainTextHandler);
	Gura_AssignMethod(wx_RichTextPlainTextHandler, CanSave);
	Gura_AssignMethod(wx_RichTextPlainTextHandler, CanLoad);
	Gura_AssignMethod(wx_RichTextPlainTextHandler, DoLoadFile);
	Gura_AssignMethod(wx_RichTextPlainTextHandler, DoSaveFile);
}

Gura_ImplementDescendantCreator(wx_RichTextPlainTextHandler)
{
	return new Object_wx_RichTextPlainTextHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
