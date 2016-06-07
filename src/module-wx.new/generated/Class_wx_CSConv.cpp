//----------------------------------------------------------------------------
// wxCSConv
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCSConv
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCSConv
//----------------------------------------------------------------------------
Object_wx_CSConv::~Object_wx_CSConv()
{
}

Object *Object_wx_CSConv::Clone() const
{
	return nullptr;
}

String Object_wx_CSConv::ToString(bool exprFlag)
{
	String rtn("<wx.CSConv:");
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
Gura_DeclareFunctionAlias(__CSConv, "CSConv")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "charset", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CSConv));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CSConv)
{
	//const wxString& charset = arg.GetNumber(0)
	//wxCSConv(charset);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CSConv_1, "CSConv_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CSConv));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CSConv_1)
{
	//wxFontEncoding encoding = arg.GetNumber(0)
	//wxCSConv(encoding);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_CSConv, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CSConv, __IsOk)
{
	Object_wx_CSConv *pThis = Object_wx_CSConv::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCSConv
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CSConv)
{
	// Constructor assignment
	Gura_AssignFunction(__CSConv);
	Gura_AssignFunction(__CSConv_1);
	// Method assignment
	Gura_AssignMethod(wx_CSConv, __IsOk);
}

Gura_ImplementDescendantCreator(wx_CSConv)
{
	return new Object_wx_CSConv((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
