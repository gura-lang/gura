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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextFormattingDialogFactory, wxRichTextFormattingDialogFactory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFormattingDialogFactory, wxRichTextFormattingDialogFactory)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialogFactory *pThis = Object_wx_RichTextFormattingDialogFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextFormattingDialogFactory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFormattingDialogFactory, ~wxRichTextFormattingDialogFactory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFormattingDialogFactory, ~wxRichTextFormattingDialogFactory)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialogFactory *pThis = Object_wx_RichTextFormattingDialogFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxRichTextFormattingDialogFactory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFormattingDialogFactory, CreateButtons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFormattingDialogFactory, CreateButtons)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialogFactory *pThis = Object_wx_RichTextFormattingDialogFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dialog = arg.GetNumber(0)
	//pThis->GetEntity()->CreateButtons();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFormattingDialogFactory, CreatePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFormattingDialogFactory, CreatePage)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialogFactory *pThis = Object_wx_RichTextFormattingDialogFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int title = arg.GetNumber(1)
	//int dialog = arg.GetNumber(2)
	//pThis->GetEntity()->CreatePage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFormattingDialogFactory, CreatePages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pages", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFormattingDialogFactory, CreatePages)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialogFactory *pThis = Object_wx_RichTextFormattingDialogFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pages = arg.GetNumber(0)
	//int dialog = arg.GetNumber(1)
	//pThis->GetEntity()->CreatePages();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFormattingDialogFactory, GetPageId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFormattingDialogFactory, GetPageId)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialogFactory *pThis = Object_wx_RichTextFormattingDialogFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFormattingDialogFactory, GetPageIdCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFormattingDialogFactory, GetPageIdCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialogFactory *pThis = Object_wx_RichTextFormattingDialogFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPageIdCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFormattingDialogFactory, GetPageImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFormattingDialogFactory, GetPageImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialogFactory *pThis = Object_wx_RichTextFormattingDialogFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFormattingDialogFactory, SetSheetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFormattingDialogFactory, SetSheetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialogFactory *pThis = Object_wx_RichTextFormattingDialogFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dialog = arg.GetNumber(0)
	//pThis->GetEntity()->SetSheetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFormattingDialogFactory, ShowHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFormattingDialogFactory, ShowHelp)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextFormattingDialogFactory *pThis = Object_wx_RichTextFormattingDialogFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_RichTextFormattingDialogFactory, wxRichTextFormattingDialogFactory);
	Gura_AssignMethod(wx_RichTextFormattingDialogFactory, ~wxRichTextFormattingDialogFactory);
	Gura_AssignMethod(wx_RichTextFormattingDialogFactory, CreateButtons);
	Gura_AssignMethod(wx_RichTextFormattingDialogFactory, CreatePage);
	Gura_AssignMethod(wx_RichTextFormattingDialogFactory, CreatePages);
	Gura_AssignMethod(wx_RichTextFormattingDialogFactory, GetPageId);
	Gura_AssignMethod(wx_RichTextFormattingDialogFactory, GetPageIdCount);
	Gura_AssignMethod(wx_RichTextFormattingDialogFactory, GetPageImage);
	Gura_AssignMethod(wx_RichTextFormattingDialogFactory, SetSheetStyle);
	Gura_AssignMethod(wx_RichTextFormattingDialogFactory, ShowHelp);
}

Gura_ImplementDescendantCreator(wx_RichTextFormattingDialogFactory)
{
	return new Object_wx_RichTextFormattingDialogFactory((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
