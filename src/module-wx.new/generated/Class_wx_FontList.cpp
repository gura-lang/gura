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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_FontList, wxFontList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontList, wxFontList)
{
	Object_wx_FontList *pThis = Object_wx_FontList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxFontList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontList, FindOrCreateFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "point_size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "underline", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "facename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontList, FindOrCreateFont)
{
	Object_wx_FontList *pThis = Object_wx_FontList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int point_size = arg.GetNumber(0)
	//int family = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//int weight = arg.GetNumber(3)
	//int underline = arg.GetNumber(4)
	//int facename = arg.GetNumber(5)
	//int encoding = arg.GetNumber(6)
	//pThis->GetEntity()->FindOrCreateFont();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFontList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontList)
{
	Gura_AssignMethod(wx_FontList, wxFontList);
	Gura_AssignMethod(wx_FontList, FindOrCreateFont);
}

Gura_ImplementDescendantCreator(wx_FontList)
{
	return new Object_wx_FontList((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
