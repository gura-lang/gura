//----------------------------------------------------------------------------
// wxDataViewDateRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewDateRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewDateRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewDateRenderer::~Object_wx_DataViewDateRenderer()
{
}

Object *Object_wx_DataViewDateRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewDateRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewDateRenderer:");
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
Gura_DeclareFunctionAlias(__DataViewDateRenderer, "DataViewDateRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DataViewDateRenderer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DataViewDateRenderer)
{
	//const wxString& varianttype = arg.GetNumber(0)
	//wxDataViewCellMode mode = arg.GetNumber(1)
	//int align = arg.GetNumber(2)
	//wxDataViewDateRenderer(varianttype, mode, align);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataViewDateRenderer, __GetDefaultType, "GetDefaultType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewDateRenderer, __GetDefaultType)
{
	Object_wx_DataViewDateRenderer *pThis = Object_wx_DataViewDateRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetDefaultType();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewDateRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewDateRenderer)
{
	// Constructor assignment
	Gura_AssignFunction(__DataViewDateRenderer);
	// Method assignment
	Gura_AssignMethod(wx_DataViewDateRenderer, __GetDefaultType);
}

Gura_ImplementDescendantCreator(wx_DataViewDateRenderer)
{
	return new Object_wx_DataViewDateRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
