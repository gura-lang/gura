//----------------------------------------------------------------------------
// wxDataViewToggleRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewToggleRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewToggleRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewToggleRenderer::~Object_wx_DataViewToggleRenderer()
{
}

Object *Object_wx_DataViewToggleRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewToggleRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewToggleRenderer:");
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
Gura_DeclareFunctionAlias(__DataViewToggleRenderer, "DataViewToggleRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DataViewToggleRenderer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DataViewToggleRenderer)
{
	//const wxString& varianttype = arg.GetNumber(0)
	//wxDataViewCellMode mode = arg.GetNumber(1)
	//int align = arg.GetNumber(2)
	//wxDataViewToggleRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataViewToggleRenderer, __GetDefaultType, "GetDefaultType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewToggleRenderer, __GetDefaultType)
{
	Object_wx_DataViewToggleRenderer *pThis = Object_wx_DataViewToggleRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultType();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewToggleRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewToggleRenderer)
{
	// Constructor assignment
	Gura_AssignFunction(__DataViewToggleRenderer);
	// Method assignment
	Gura_AssignMethod(wx_DataViewToggleRenderer, __GetDefaultType);
}

Gura_ImplementDescendantCreator(wx_DataViewToggleRenderer)
{
	return new Object_wx_DataViewToggleRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
