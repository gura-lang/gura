//----------------------------------------------------------------------------
// wxHtmlBookRecord
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlBookRecord
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlBookRecord
//----------------------------------------------------------------------------
Object_wx_HtmlBookRecord::~Object_wx_HtmlBookRecord()
{
}

Object *Object_wx_HtmlBookRecord::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlBookRecord::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlBookRecord:");
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
Gura_DeclareMethod(wx_HtmlBookRecord, wxHtmlBookRecord)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bookfile", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "basepath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlBookRecord, wxHtmlBookRecord)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bookfile = arg.GetNumber(0)
	//int basepath = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int start = arg.GetNumber(3)
	//pThis->GetEntity()->wxHtmlBookRecord();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlBookRecord, GetBookFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlBookRecord, GetBookFile)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBookFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlBookRecord, GetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlBookRecord, GetTitle)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlBookRecord, GetStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlBookRecord, GetStart)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlBookRecord, GetBasePath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlBookRecord, GetBasePath)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBasePath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlBookRecord, SetContentsRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlBookRecord, SetContentsRange)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->SetContentsRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlBookRecord, GetContentsStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlBookRecord, GetContentsStart)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContentsStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlBookRecord, GetContentsEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlBookRecord, GetContentsEnd)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContentsEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlBookRecord, SetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlBookRecord, SetTitle)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlBookRecord, SetBasePath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlBookRecord, SetBasePath)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->SetBasePath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlBookRecord, SetStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlBookRecord, SetStart)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//pThis->GetEntity()->SetStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlBookRecord, GetFullPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlBookRecord, GetFullPath)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->GetFullPath();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlBookRecord
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlBookRecord)
{
	Gura_AssignMethod(wx_HtmlBookRecord, wxHtmlBookRecord);
	Gura_AssignMethod(wx_HtmlBookRecord, GetBookFile);
	Gura_AssignMethod(wx_HtmlBookRecord, GetTitle);
	Gura_AssignMethod(wx_HtmlBookRecord, GetStart);
	Gura_AssignMethod(wx_HtmlBookRecord, GetBasePath);
	Gura_AssignMethod(wx_HtmlBookRecord, SetContentsRange);
	Gura_AssignMethod(wx_HtmlBookRecord, GetContentsStart);
	Gura_AssignMethod(wx_HtmlBookRecord, GetContentsEnd);
	Gura_AssignMethod(wx_HtmlBookRecord, SetTitle);
	Gura_AssignMethod(wx_HtmlBookRecord, SetBasePath);
	Gura_AssignMethod(wx_HtmlBookRecord, SetStart);
	Gura_AssignMethod(wx_HtmlBookRecord, GetFullPath);
}

Gura_ImplementDescendantCreator(wx_HtmlBookRecord)
{
	return new Object_wx_HtmlBookRecord((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
