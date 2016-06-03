//----------------------------------------------------------------------------
// wxQuantize
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxQuantize
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxQuantize
//----------------------------------------------------------------------------
Object_wx_Quantize::~Object_wx_Quantize()
{
}

Object *Object_wx_Quantize::Clone() const
{
	return nullptr;
}

String Object_wx_Quantize::ToString(bool exprFlag)
{
	String rtn("<wx.Quantize:");
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
Gura_DeclareFunctionAlias(__Quantize, "Quantize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Quantize));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Quantize)
{
	//wxQuantize();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Quantize, __DoQuantize, "DoQuantize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "in_rows", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "out_rows", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "palette", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desiredNoColours", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Quantize, __DoQuantize)
{
	Object_wx_Quantize *pThis = Object_wx_Quantize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int w = arg.GetNumber(0)
	//unsigned int h = arg.GetNumber(1)
	//unsigned char** in_rows = arg.GetNumber(2)
	//unsigned char** out_rows = arg.GetNumber(3)
	//unsigned char* palette = arg.GetNumber(4)
	//int desiredNoColours = arg.GetNumber(5)
	//pThis->GetEntity()->DoQuantize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Quantize, __Quantize, "Quantize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dest", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pPalette", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desiredNoColours", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eightBitData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Quantize, __Quantize)
{
	Object_wx_Quantize *pThis = Object_wx_Quantize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxImage& src = arg.GetNumber(0)
	//wxImage& dest = arg.GetNumber(1)
	//wxPalette** pPalette = arg.GetNumber(2)
	//int desiredNoColours = arg.GetNumber(3)
	//unsigned char** eightBitData = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->Quantize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Quantize, __Quantize_1, "Quantize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dest", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desiredNoColours", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eightBitData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Quantize, __Quantize_1)
{
	Object_wx_Quantize *pThis = Object_wx_Quantize::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxImage& src = arg.GetNumber(0)
	//wxImage& dest = arg.GetNumber(1)
	//int desiredNoColours = arg.GetNumber(2)
	//unsigned char** eightBitData = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//pThis->GetEntity()->Quantize();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxQuantize
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Quantize)
{
	// Constructor assignment
	Gura_AssignFunction(__Quantize);
	// Method assignment
	Gura_AssignMethod(wx_Quantize, __DoQuantize);
	Gura_AssignMethod(wx_Quantize, __Quantize);
	Gura_AssignMethod(wx_Quantize, __Quantize_1);
}

Gura_ImplementDescendantCreator(wx_Quantize)
{
	return new Object_wx_Quantize((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
