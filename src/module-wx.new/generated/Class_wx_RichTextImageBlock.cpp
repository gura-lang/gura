//----------------------------------------------------------------------------
// wxRichTextImageBlock
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextImageBlock
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextImageBlock
//----------------------------------------------------------------------------
Object_wx_RichTextImageBlock::~Object_wx_RichTextImageBlock()
{
}

Object *Object_wx_RichTextImageBlock::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextImageBlock::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextImageBlock:");
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
Gura_DeclareFunctionAlias(__RichTextImageBlock, "RichTextImageBlock")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextImageBlock));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextImageBlock)
{
	//wxRichTextImageBlock();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextImageBlock_1, "RichTextImageBlock_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "block", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextImageBlock));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextImageBlock_1)
{
	//int block = arg.GetNumber(0)
	//wxRichTextImageBlock();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextImageBlock, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __Init)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __Clear)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __MakeImageBlock, "MakeImageBlock")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "convertToJPEG", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __MakeImageBlock)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int imageType = arg.GetNumber(1)
	//int image = arg.GetNumber(2)
	//int convertToJPEG = arg.GetNumber(3)
	//pThis->GetEntity()->MakeImageBlock();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __MakeImageBlock_1, "MakeImageBlock_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "quality", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __MakeImageBlock_1)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//int imageType = arg.GetNumber(1)
	//int quality = arg.GetNumber(2)
	//pThis->GetEntity()->MakeImageBlock();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __MakeImageBlockDefaultQuality, "MakeImageBlockDefaultQuality")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __MakeImageBlockDefaultQuality)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//int imageType = arg.GetNumber(1)
	//pThis->GetEntity()->MakeImageBlockDefaultQuality();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __DoMakeImageBlock, "DoMakeImageBlock")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __DoMakeImageBlock)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//int imageType = arg.GetNumber(1)
	//pThis->GetEntity()->DoMakeImageBlock();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __Write, "Write")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __Write)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __WriteHex, "WriteHex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __WriteHex)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->WriteHex();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __ReadHex, "ReadHex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __ReadHex)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int length = arg.GetNumber(1)
	//int imageType = arg.GetNumber(2)
	//pThis->GetEntity()->ReadHex();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "block", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __Copy)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int block = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __Load, "Load")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __Load)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __GetData, "GetData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __GetData)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __GetDataSize, "GetDataSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __GetDataSize)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDataSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __GetImageType, "GetImageType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __GetImageType)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImageType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __SetData, "SetData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __SetData)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __SetDataSize, "SetDataSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __SetDataSize)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetDataSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __SetImageType, "SetImageType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __SetImageType)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imageType = arg.GetNumber(0)
	//pThis->GetEntity()->SetImageType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __IsOk)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __Ok, "Ok")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __Ok)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Ok();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __GetExtension, "GetExtension")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __GetExtension)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtension();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __ReadBlock, "ReadBlock")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __ReadBlock)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->ReadBlock();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __ReadBlock_1, "ReadBlock_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __ReadBlock_1)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->ReadBlock();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __WriteBlock, "WriteBlock")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "block", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __WriteBlock)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int block = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->WriteBlock();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextImageBlock, __WriteBlock_1, "WriteBlock_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "block", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, __WriteBlock_1)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int block = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->WriteBlock();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextImageBlock
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextImageBlock)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextImageBlock);
	Gura_AssignFunction(__RichTextImageBlock_1);
	// Method assignment
	Gura_AssignMethod(wx_RichTextImageBlock, __Init);
	Gura_AssignMethod(wx_RichTextImageBlock, __Clear);
	Gura_AssignMethod(wx_RichTextImageBlock, __MakeImageBlock);
	Gura_AssignMethod(wx_RichTextImageBlock, __MakeImageBlock_1);
	Gura_AssignMethod(wx_RichTextImageBlock, __MakeImageBlockDefaultQuality);
	Gura_AssignMethod(wx_RichTextImageBlock, __DoMakeImageBlock);
	Gura_AssignMethod(wx_RichTextImageBlock, __Write);
	Gura_AssignMethod(wx_RichTextImageBlock, __WriteHex);
	Gura_AssignMethod(wx_RichTextImageBlock, __ReadHex);
	Gura_AssignMethod(wx_RichTextImageBlock, __Copy);
	Gura_AssignMethod(wx_RichTextImageBlock, __Load);
	Gura_AssignMethod(wx_RichTextImageBlock, __GetData);
	Gura_AssignMethod(wx_RichTextImageBlock, __GetDataSize);
	Gura_AssignMethod(wx_RichTextImageBlock, __GetImageType);
	Gura_AssignMethod(wx_RichTextImageBlock, __SetData);
	Gura_AssignMethod(wx_RichTextImageBlock, __SetDataSize);
	Gura_AssignMethod(wx_RichTextImageBlock, __SetImageType);
	Gura_AssignMethod(wx_RichTextImageBlock, __IsOk);
	Gura_AssignMethod(wx_RichTextImageBlock, __Ok);
	Gura_AssignMethod(wx_RichTextImageBlock, __GetExtension);
	Gura_AssignMethod(wx_RichTextImageBlock, __ReadBlock);
	Gura_AssignMethod(wx_RichTextImageBlock, __ReadBlock_1);
	Gura_AssignMethod(wx_RichTextImageBlock, __WriteBlock);
	Gura_AssignMethod(wx_RichTextImageBlock, __WriteBlock_1);
}

Gura_ImplementDescendantCreator(wx_RichTextImageBlock)
{
	return new Object_wx_RichTextImageBlock((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
