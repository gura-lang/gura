//----------------------------------------------------------------------------
// wxZipInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxZipInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxZipInputStream
//----------------------------------------------------------------------------
Object_wx_ZipInputStream::~Object_wx_ZipInputStream()
{
}

Object *Object_wx_ZipInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_ZipInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.ZipInputStream:");
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
Gura_DeclareFunctionAlias(__ZipInputStream, "ZipInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ZipInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ZipInputStream)
{
	//wxInputStream& stream = arg.GetNumber(0)
	//wxMBConv& conv = arg.GetNumber(1)
	//wxZipInputStream(stream, conv);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__ZipInputStream_1, "ZipInputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ZipInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ZipInputStream_1)
{
	//wxInputStream* stream = arg.GetNumber(0)
	//wxMBConv& conv = arg.GetNumber(1)
	//wxZipInputStream(stream, conv);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ZipInputStream, __CloseEntry, "CloseEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipInputStream, __CloseEntry)
{
	Object_wx_ZipInputStream *pThis = Object_wx_ZipInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CloseEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipInputStream, __GetComment, "GetComment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipInputStream, __GetComment)
{
	Object_wx_ZipInputStream *pThis = Object_wx_ZipInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetComment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipInputStream, __GetNextEntry, "GetNextEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipInputStream, __GetNextEntry)
{
	Object_wx_ZipInputStream *pThis = Object_wx_ZipInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNextEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipInputStream, __GetTotalEntries, "GetTotalEntries")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipInputStream, __GetTotalEntries)
{
	Object_wx_ZipInputStream *pThis = Object_wx_ZipInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTotalEntries();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipInputStream, __OpenEntry, "OpenEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipInputStream, __OpenEntry)
{
	Object_wx_ZipInputStream *pThis = Object_wx_ZipInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxZipEntry& entry = arg.GetNumber(0)
	//pThis->GetEntity()->OpenEntry(entry);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxZipInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZipInputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__ZipInputStream);
	Gura_AssignFunction(__ZipInputStream_1);
	// Method assignment
	Gura_AssignMethod(wx_ZipInputStream, __CloseEntry);
	Gura_AssignMethod(wx_ZipInputStream, __GetComment);
	Gura_AssignMethod(wx_ZipInputStream, __GetNextEntry);
	Gura_AssignMethod(wx_ZipInputStream, __GetTotalEntries);
	Gura_AssignMethod(wx_ZipInputStream, __OpenEntry);
}

Gura_ImplementDescendantCreator(wx_ZipInputStream)
{
	return new Object_wx_ZipInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
