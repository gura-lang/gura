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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HtmlHelpData, "HtmlHelpData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlHelpData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlHelpData)
{
	//wxHtmlHelpData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlHelpData, __AddBook, "AddBook")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "book_url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpData, __AddBook)
{
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& book_url = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->AddBook(book_url);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpData, __FindPageById, "FindPageById")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpData, __FindPageById)
{
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->FindPageById(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpData, __FindPageByName, "FindPageByName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpData, __FindPageByName)
{
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& page = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->FindPageByName(page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpData, __GetBookRecArray, "GetBookRecArray")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpData, __GetBookRecArray)
{
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxHtmlBookRecArray& _rtn = pThis->GetEntity()->GetBookRecArray();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpData, __GetContentsArray, "GetContentsArray")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpData, __GetContentsArray)
{
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxHtmlHelpDataItems& _rtn = pThis->GetEntity()->GetContentsArray();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpData, __GetIndexArray, "GetIndexArray")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpData, __GetIndexArray)
{
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxHtmlHelpDataItems& _rtn = pThis->GetEntity()->GetIndexArray();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpData, __SetTempDir, "SetTempDir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpData, __SetTempDir)
{
	Object_wx_HtmlHelpData *pThis = Object_wx_HtmlHelpData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& path = arg.GetNumber(0)
	//pThis->GetEntity()->SetTempDir(path);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlHelpData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlHelpData)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlHelpData);
	// Method assignment
	Gura_AssignMethod(wx_HtmlHelpData, __AddBook);
	Gura_AssignMethod(wx_HtmlHelpData, __FindPageById);
	Gura_AssignMethod(wx_HtmlHelpData, __FindPageByName);
	Gura_AssignMethod(wx_HtmlHelpData, __GetBookRecArray);
	Gura_AssignMethod(wx_HtmlHelpData, __GetContentsArray);
	Gura_AssignMethod(wx_HtmlHelpData, __GetIndexArray);
	Gura_AssignMethod(wx_HtmlHelpData, __SetTempDir);
}

Gura_ImplementDescendantCreator(wx_HtmlHelpData)
{
	return new Object_wx_HtmlHelpData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
