//----------------------------------------------------------------------------
// wxGridHeaderLabelsRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridHeaderLabelsRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridHeaderLabelsRenderer
//----------------------------------------------------------------------------
Object_wx_GridHeaderLabelsRenderer::~Object_wx_GridHeaderLabelsRenderer()
{
}

Object *Object_wx_GridHeaderLabelsRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridHeaderLabelsRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridHeaderLabelsRenderer:");
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
Gura_DeclareMethodAlias(wx_GridHeaderLabelsRenderer, __DrawLabel, "DrawLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "horizAlign", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vertAlign", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textOrientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridHeaderLabelsRenderer, __DrawLabel)
{
	Object_wx_GridHeaderLabelsRenderer *pThis = Object_wx_GridHeaderLabelsRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int grid = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//int horizAlign = arg.GetNumber(4)
	//int vertAlign = arg.GetNumber(5)
	//int textOrientation = arg.GetNumber(6)
	//pThis->GetEntity()->DrawLabel();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridHeaderLabelsRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridHeaderLabelsRenderer)
{
	Gura_AssignMethod(wx_GridHeaderLabelsRenderer, __DrawLabel);
}

Gura_ImplementDescendantCreator(wx_GridHeaderLabelsRenderer)
{
	return new Object_wx_GridHeaderLabelsRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
