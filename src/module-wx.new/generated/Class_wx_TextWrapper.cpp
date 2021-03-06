//----------------------------------------------------------------------------
// wxTextWrapper
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextWrapper
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextWrapper
//----------------------------------------------------------------------------
Object_wx_TextWrapper::~Object_wx_TextWrapper()
{
}

Object *Object_wx_TextWrapper::Clone() const
{
	return nullptr;
}

String Object_wx_TextWrapper::ToString(bool exprFlag)
{
	String rtn("<wx.TextWrapper:");
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
Gura_DeclareFunctionAlias(__TextWrapper, "TextWrapper")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TextWrapper));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TextWrapper)
{
	//wxTextWrapper();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TextWrapper, __Wrap, "Wrap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "widthMax", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextWrapper, __Wrap)
{
	Object_wx_TextWrapper *pThis = Object_wx_TextWrapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//int widthMax = arg.GetNumber(2)
	//pThis->GetEntity()->Wrap(win, text, widthMax);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextWrapper, __OnOutputLine, "OnOutputLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextWrapper, __OnOutputLine)
{
	Object_wx_TextWrapper *pThis = Object_wx_TextWrapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& line = arg.GetNumber(0)
	//pThis->GetEntity()->OnOutputLine(line);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextWrapper, __OnNewLine, "OnNewLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextWrapper, __OnNewLine)
{
	Object_wx_TextWrapper *pThis = Object_wx_TextWrapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnNewLine();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextWrapper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextWrapper)
{
	// Constructor assignment
	Gura_AssignFunction(__TextWrapper);
	// Method assignment
	Gura_AssignMethod(wx_TextWrapper, __Wrap);
	Gura_AssignMethod(wx_TextWrapper, __OnOutputLine);
	Gura_AssignMethod(wx_TextWrapper, __OnNewLine);
}

Gura_ImplementDescendantCreator(wx_TextWrapper)
{
	return new Object_wx_TextWrapper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
