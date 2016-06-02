//----------------------------------------------------------------------------
// wxTextAttrDimensionConverter
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttrDimensionConverter
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextAttrDimensionConverter
//----------------------------------------------------------------------------
Object_wx_TextAttrDimensionConverter::~Object_wx_TextAttrDimensionConverter()
{
}

Object *Object_wx_TextAttrDimensionConverter::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttrDimensionConverter::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttrDimensionConverter:");
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
Gura_DeclareMethod(wx_TextAttrDimensionConverter, wxTextAttrDimensionConverter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "scale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimensionConverter, wxTextAttrDimensionConverter)
{
	Object_wx_TextAttrDimensionConverter *pThis = Object_wx_TextAttrDimensionConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int scale = arg.GetNumber(1)
	//int parentSize = arg.GetNumber(2)
	//pThis->GetEntity()->wxTextAttrDimensionConverter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimensionConverter, wxTextAttrDimensionConverter_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ppi", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "scale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimensionConverter, wxTextAttrDimensionConverter_1)
{
	Object_wx_TextAttrDimensionConverter *pThis = Object_wx_TextAttrDimensionConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ppi = arg.GetNumber(0)
	//int scale = arg.GetNumber(1)
	//int parentSize = arg.GetNumber(2)
	//pThis->GetEntity()->wxTextAttrDimensionConverter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimensionConverter, GetPixels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dim", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimensionConverter, GetPixels)
{
	Object_wx_TextAttrDimensionConverter *pThis = Object_wx_TextAttrDimensionConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dim = arg.GetNumber(0)
	//int direction = arg.GetNumber(1)
	//pThis->GetEntity()->GetPixels();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimensionConverter, GetTenthsMM)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dim", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimensionConverter, GetTenthsMM)
{
	Object_wx_TextAttrDimensionConverter *pThis = Object_wx_TextAttrDimensionConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dim = arg.GetNumber(0)
	//pThis->GetEntity()->GetTenthsMM();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimensionConverter, ConvertTenthsMMToPixels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimensionConverter, ConvertTenthsMMToPixels)
{
	Object_wx_TextAttrDimensionConverter *pThis = Object_wx_TextAttrDimensionConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int units = arg.GetNumber(0)
	//pThis->GetEntity()->ConvertTenthsMMToPixels();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrDimensionConverter, ConvertPixelsToTenthsMM)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixels", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrDimensionConverter, ConvertPixelsToTenthsMM)
{
	Object_wx_TextAttrDimensionConverter *pThis = Object_wx_TextAttrDimensionConverter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixels = arg.GetNumber(0)
	//pThis->GetEntity()->ConvertPixelsToTenthsMM();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextAttrDimensionConverter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttrDimensionConverter)
{
	Gura_AssignMethod(wx_TextAttrDimensionConverter, wxTextAttrDimensionConverter);
	Gura_AssignMethod(wx_TextAttrDimensionConverter, wxTextAttrDimensionConverter_1);
	Gura_AssignMethod(wx_TextAttrDimensionConverter, GetPixels);
	Gura_AssignMethod(wx_TextAttrDimensionConverter, GetTenthsMM);
	Gura_AssignMethod(wx_TextAttrDimensionConverter, ConvertTenthsMMToPixels);
	Gura_AssignMethod(wx_TextAttrDimensionConverter, ConvertPixelsToTenthsMM);
}

Gura_ImplementDescendantCreator(wx_TextAttrDimensionConverter)
{
	return new Object_wx_TextAttrDimensionConverter((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
