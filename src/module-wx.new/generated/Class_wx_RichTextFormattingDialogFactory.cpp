//----------------------------------------------------------------------------
// wxRichTextFormattingDialogFactory
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextFormattingDialogFactory
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextFormattingDialogFactory
//----------------------------------------------------------------------------
Object_wx_RichTextFormattingDialogFactory::~Object_wx_RichTextFormattingDialogFactory()
{
}

Object *Object_wx_RichTextFormattingDialogFactory::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextFormattingDialogFactory::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextFormattingDialogFactory:");
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
Gura_DeclareFunctionAlias(__RichTextFormattingDialogFactory, "RichTextFormattingDialogFactory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextFormattingDialogFactory));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextFormattingDialogFactory)
{
	//wxRichTextFormattingDialogFactory();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextFormattingDialogFactory, __CreateButtons, "CreateButtons")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFormattingDialogFactory, __CreateButtons)
{
	Object_wx_RichTextFormattingDialogFactory *pThis = Object_wx_RichTextFormattingDialogFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dialog = arg.GetNumber(0)
	//pThis->GetEntity()->CreateButtons();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFormattingDialogFactory, __CreatePage, "CreatePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFormattingDialogFactory, __CreatePage)
{
	Object_wx_RichTextFormattingDialogFactory *pThis = Object_wx_RichTextFormattingDialogFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int title = arg.GetNumber(1)
	//int dialog = arg.GetNumber(2)
	//pThis->GetEntity()->CreatePage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFormattingDialogFactory, __CreatePages, "CreatePages")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pages", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFormattingDialogFactory, __CreatePages)
{
	Object_wx_RichTextFormattingDialogFactory *pThis = Object_wx_RichTextFormattingDialogFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pages = arg.GetNumber(0)
	//int dialog = arg.GetNumber(1)
	//pThis->GetEntity()->CreatePages();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFormattingDialogFactory, __GetPageId, "GetPageId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFormattingDialogFactory, __GetPageId)
{
	Object_wx_RichTextFormattingDialogFactory *pThis = Object_wx_RichTextFormattingDialogFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFormattingDialogFactory, __GetPageIdCount, "GetPageIdCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFormattingDialogFactory, __GetPageIdCount)
{
	Object_wx_RichTextFormattingDialogFactory *pThis = Object_wx_RichTextFormattingDialogFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageIdCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFormattingDialogFactory, __GetPageImage, "GetPageImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFormattingDialogFactory, __GetPageImage)
{
	Object_wx_RichTextFormattingDialogFactory *pThis = Object_wx_RichTextFormattingDialogFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFormattingDialogFactory, __SetSheetStyle, "SetSheetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFormattingDialogFactory, __SetSheetStyle)
{
	Object_wx_RichTextFormattingDialogFactory *pThis = Object_wx_RichTextFormattingDialogFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dialog = arg.GetNumber(0)
	//pThis->GetEntity()->SetSheetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFormattingDialogFactory, __ShowHelp, "ShowHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFormattingDialogFactory, __ShowHelp)
{
	Object_wx_RichTextFormattingDialogFactory *pThis = Object_wx_RichTextFormattingDialogFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int dialog = arg.GetNumber(1)
	//pThis->GetEntity()->ShowHelp();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextFormattingDialogFactory
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextFormattingDialogFactory)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextFormattingDialogFactory);
	// Method assignment
	Gura_AssignMethod(wx_RichTextFormattingDialogFactory, __CreateButtons);
	Gura_AssignMethod(wx_RichTextFormattingDialogFactory, __CreatePage);
	Gura_AssignMethod(wx_RichTextFormattingDialogFactory, __CreatePages);
	Gura_AssignMethod(wx_RichTextFormattingDialogFactory, __GetPageId);
	Gura_AssignMethod(wx_RichTextFormattingDialogFactory, __GetPageIdCount);
	Gura_AssignMethod(wx_RichTextFormattingDialogFactory, __GetPageImage);
	Gura_AssignMethod(wx_RichTextFormattingDialogFactory, __SetSheetStyle);
	Gura_AssignMethod(wx_RichTextFormattingDialogFactory, __ShowHelp);
}

Gura_ImplementDescendantCreator(wx_RichTextFormattingDialogFactory)
{
	return new Object_wx_RichTextFormattingDialogFactory((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
