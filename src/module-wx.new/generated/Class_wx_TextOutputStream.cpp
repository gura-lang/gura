//----------------------------------------------------------------------------
// wxTextOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextOutputStream
//----------------------------------------------------------------------------
Object_wx_TextOutputStream::~Object_wx_TextOutputStream()
{
}

Object *Object_wx_TextOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_TextOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.TextOutputStream:");
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
Gura_DeclareFunctionAlias(__TextOutputStream, "TextOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TextOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TextOutputStream)
{
	//wxOutputStream& stream = arg.GetNumber(0)
	//wxEOL mode = arg.GetNumber(1)
	//const wxMBConv& conv = arg.GetNumber(2)
	//wxTextOutputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TextOutputStream, __Flush, "Flush")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextOutputStream, __Flush)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Flush();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextOutputStream, __GetOutputStream, "GetOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextOutputStream, __GetOutputStream)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOutputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextOutputStream, __GetMode, "GetMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextOutputStream, __GetMode)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextOutputStream, __PutChar, "PutChar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextOutputStream, __PutChar)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxChar c = arg.GetNumber(0)
	//pThis->GetEntity()->PutChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextOutputStream, __SetMode, "SetMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextOutputStream, __SetMode)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxEOL mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextOutputStream, __Write, "Write")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextOutputStream, __Write)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const T& i = arg.GetNumber(0)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextOutputStream, __Write64, "Write64")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i64", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextOutputStream, __Write64)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUint64 i64 = arg.GetNumber(0)
	//pThis->GetEntity()->Write64();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextOutputStream, __Write32, "Write32")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i32", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextOutputStream, __Write32)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUint32 i32 = arg.GetNumber(0)
	//pThis->GetEntity()->Write32();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextOutputStream, __Write16, "Write16")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i16", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextOutputStream, __Write16)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUint16 i16 = arg.GetNumber(0)
	//pThis->GetEntity()->Write16();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextOutputStream, __Write8, "Write8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i8", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextOutputStream, __Write8)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUint8 i8 = arg.GetNumber(0)
	//pThis->GetEntity()->Write8();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextOutputStream, __WriteDouble, "WriteDouble")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "f", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextOutputStream, __WriteDouble)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double f = arg.GetNumber(0)
	//pThis->GetEntity()->WriteDouble();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextOutputStream, __WriteString, "WriteString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextOutputStream, __WriteString)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& string = arg.GetNumber(0)
	//pThis->GetEntity()->WriteString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextOutputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__TextOutputStream);
	// Method assignment
	Gura_AssignMethod(wx_TextOutputStream, __Flush);
	Gura_AssignMethod(wx_TextOutputStream, __GetOutputStream);
	Gura_AssignMethod(wx_TextOutputStream, __GetMode);
	Gura_AssignMethod(wx_TextOutputStream, __PutChar);
	Gura_AssignMethod(wx_TextOutputStream, __SetMode);
	Gura_AssignMethod(wx_TextOutputStream, __Write);
	Gura_AssignMethod(wx_TextOutputStream, __Write64);
	Gura_AssignMethod(wx_TextOutputStream, __Write32);
	Gura_AssignMethod(wx_TextOutputStream, __Write16);
	Gura_AssignMethod(wx_TextOutputStream, __Write8);
	Gura_AssignMethod(wx_TextOutputStream, __WriteDouble);
	Gura_AssignMethod(wx_TextOutputStream, __WriteString);
}

Gura_ImplementDescendantCreator(wx_TextOutputStream)
{
	return new Object_wx_TextOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
