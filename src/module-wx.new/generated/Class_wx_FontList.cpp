//----------------------------------------------------------------------------
// wxFontList
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFontList
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFontList
//----------------------------------------------------------------------------
Object_wx_FontList::~Object_wx_FontList()
{
}

Object *Object_wx_FontList::Clone() const
{
	return nullptr;
}

String Object_wx_FontList::ToString(bool exprFlag)
{
	String rtn("<wx.FontList:");
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
Gura_DeclareFunctionAlias(__FontList, "FontList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FontList));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FontList)
{
	//wxFontList();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FontList, __FindOrCreateFont, "FindOrCreateFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "point_size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "underline", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "facename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontList, __FindOrCreateFont)
{
	Object_wx_FontList *pThis = Object_wx_FontList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int point_size = arg.GetNumber(0)
	//wxFontFamily family = arg.GetNumber(1)
	//wxFontStyle style = arg.GetNumber(2)
	//wxFontWeight weight = arg.GetNumber(3)
	//bool underline = arg.GetNumber(4)
	//const wxString& facename = arg.GetNumber(5)
	//wxFontEncoding encoding = arg.GetNumber(6)
	//wxFont* _rtn = pThis->GetEntity()->FindOrCreateFont(point_size, family, style, weight, underline, facename, encoding);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFontList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontList)
{
	// Constructor assignment
	Gura_AssignFunction(__FontList);
	// Method assignment
	Gura_AssignMethod(wx_FontList, __FindOrCreateFont);
}

Gura_ImplementDescendantCreator(wx_FontList)
{
	return new Object_wx_FontList((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
