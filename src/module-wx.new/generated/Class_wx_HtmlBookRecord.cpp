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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HtmlBookRecord, "HtmlBookRecord")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bookfile", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "basepath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HtmlBookRecord));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlBookRecord)
{
	//const wxString& bookfile = arg.GetNumber(0)
	//const wxString& basepath = arg.GetNumber(1)
	//const wxString& title = arg.GetNumber(2)
	//const wxString& start = arg.GetNumber(3)
	//wxHtmlBookRecord(bookfile, basepath, title, start);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlBookRecord, __GetBookFile, "GetBookFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlBookRecord, __GetBookFile)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBookFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlBookRecord, __GetTitle, "GetTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlBookRecord, __GetTitle)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlBookRecord, __GetStart, "GetStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlBookRecord, __GetStart)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlBookRecord, __GetBasePath, "GetBasePath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlBookRecord, __GetBasePath)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBasePath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlBookRecord, __SetContentsRange, "SetContentsRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlBookRecord, __SetContentsRange)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->SetContentsRange(start, end);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlBookRecord, __GetContentsStart, "GetContentsStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlBookRecord, __GetContentsStart)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContentsStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlBookRecord, __GetContentsEnd, "GetContentsEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlBookRecord, __GetContentsEnd)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContentsEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlBookRecord, __SetTitle, "SetTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlBookRecord, __SetTitle)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& title = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitle(title);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlBookRecord, __SetBasePath, "SetBasePath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlBookRecord, __SetBasePath)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& path = arg.GetNumber(0)
	//pThis->GetEntity()->SetBasePath(path);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlBookRecord, __SetStart, "SetStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlBookRecord, __SetStart)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& start = arg.GetNumber(0)
	//pThis->GetEntity()->SetStart(start);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlBookRecord, __GetFullPath, "GetFullPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlBookRecord, __GetFullPath)
{
	Object_wx_HtmlBookRecord *pThis = Object_wx_HtmlBookRecord::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& page = arg.GetNumber(0)
	//pThis->GetEntity()->GetFullPath(page);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlBookRecord
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlBookRecord)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlBookRecord);
	// Method assignment
	Gura_AssignMethod(wx_HtmlBookRecord, __GetBookFile);
	Gura_AssignMethod(wx_HtmlBookRecord, __GetTitle);
	Gura_AssignMethod(wx_HtmlBookRecord, __GetStart);
	Gura_AssignMethod(wx_HtmlBookRecord, __GetBasePath);
	Gura_AssignMethod(wx_HtmlBookRecord, __SetContentsRange);
	Gura_AssignMethod(wx_HtmlBookRecord, __GetContentsStart);
	Gura_AssignMethod(wx_HtmlBookRecord, __GetContentsEnd);
	Gura_AssignMethod(wx_HtmlBookRecord, __SetTitle);
	Gura_AssignMethod(wx_HtmlBookRecord, __SetBasePath);
	Gura_AssignMethod(wx_HtmlBookRecord, __SetStart);
	Gura_AssignMethod(wx_HtmlBookRecord, __GetFullPath);
}

Gura_ImplementDescendantCreator(wx_HtmlBookRecord)
{
	return new Object_wx_HtmlBookRecord((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
