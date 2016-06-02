//----------------------------------------------------------------------------
// wxHtmlHelpData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlHelpData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlHelpData
//----------------------------------------------------------------------------
Object_wx_HtmlHelpData::~Object_wx_HtmlHelpData()
{
}

Object *Object_wx_HtmlHelpData::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlHelpData::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlHelpData:");
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
Gura_DeclareMethod(wx_HtmlHelpData, wxHtmlHelpData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpData, wxHtmlHelpData)
{
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxHtmlHelpData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpData, AddBook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "book_url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpData, AddBook)
{
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int book_url = arg.GetNumber(0)
	//pThis->GetEntity()->AddBook();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpData, FindPageById)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpData, FindPageById)
{
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->FindPageById();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpData, FindPageByName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpData, FindPageByName)
{
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->FindPageByName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpData, GetBookRecArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpData, GetBookRecArray)
{
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBookRecArray();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpData, GetContentsArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpData, GetContentsArray)
{
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContentsArray();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpData, GetIndexArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpData, GetIndexArray)
{
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndexArray();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpData, SetTempDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpData, SetTempDir)
{
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->SetTempDir();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlHelpData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlHelpData)
{
	Gura_AssignMethod(wx_HtmlHelpData, wxHtmlHelpData);
	Gura_AssignMethod(wx_HtmlHelpData, AddBook);
	Gura_AssignMethod(wx_HtmlHelpData, FindPageById);
	Gura_AssignMethod(wx_HtmlHelpData, FindPageByName);
	Gura_AssignMethod(wx_HtmlHelpData, GetBookRecArray);
	Gura_AssignMethod(wx_HtmlHelpData, GetContentsArray);
	Gura_AssignMethod(wx_HtmlHelpData, GetIndexArray);
	Gura_AssignMethod(wx_HtmlHelpData, SetTempDir);
}

Gura_ImplementDescendantCreator(wx_HtmlHelpData)
{
	return new Object_wx_HtmlHelpData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
