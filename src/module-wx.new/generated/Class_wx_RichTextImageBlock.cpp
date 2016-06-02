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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextImageBlock, wxRichTextImageBlock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImageBlock, wxRichTextImageBlock)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextImageBlock();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, wxRichTextImageBlock_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "block", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, wxRichTextImageBlock_1)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int block = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextImageBlock();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImageBlock, Init)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImageBlock, Clear)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, MakeImageBlock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "convertToJPEG", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, MakeImageBlock)
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

Gura_DeclareMethod(wx_RichTextImageBlock, MakeImageBlock_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "quality", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, MakeImageBlock_1)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//int imageType = arg.GetNumber(1)
	//int quality = arg.GetNumber(2)
	//pThis->GetEntity()->MakeImageBlock();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, MakeImageBlockDefaultQuality)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, MakeImageBlockDefaultQuality)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//int imageType = arg.GetNumber(1)
	//pThis->GetEntity()->MakeImageBlockDefaultQuality();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, DoMakeImageBlock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, DoMakeImageBlock)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//int imageType = arg.GetNumber(1)
	//pThis->GetEntity()->DoMakeImageBlock();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, Write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, Write)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, WriteHex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, WriteHex)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->WriteHex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, ReadHex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, ReadHex)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int length = arg.GetNumber(1)
	//int imageType = arg.GetNumber(2)
	//pThis->GetEntity()->ReadHex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "block", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, Copy)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int block = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, Load)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, Load)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImageBlock, GetData)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, GetDataSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImageBlock, GetDataSize)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDataSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, GetImageType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImageBlock, GetImageType)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImageType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, SetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, SetData)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, SetDataSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, SetDataSize)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetDataSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, SetImageType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, SetImageType)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imageType = arg.GetNumber(0)
	//pThis->GetEntity()->SetImageType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImageBlock, IsOk)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, Ok)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImageBlock, Ok)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Ok();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, GetExtension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextImageBlock, GetExtension)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtension();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, ReadBlock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, ReadBlock)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->ReadBlock();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, ReadBlock_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, ReadBlock_1)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->ReadBlock();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, WriteBlock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "block", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, WriteBlock)
{
	Object_wx_RichTextImageBlock *pThis = Object_wx_RichTextImageBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int block = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->WriteBlock();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextImageBlock, WriteBlock_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "block", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextImageBlock, WriteBlock_1)
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
	Gura_AssignMethod(wx_RichTextImageBlock, wxRichTextImageBlock);
	Gura_AssignMethod(wx_RichTextImageBlock, wxRichTextImageBlock_1);
	Gura_AssignMethod(wx_RichTextImageBlock, Init);
	Gura_AssignMethod(wx_RichTextImageBlock, Clear);
	Gura_AssignMethod(wx_RichTextImageBlock, MakeImageBlock);
	Gura_AssignMethod(wx_RichTextImageBlock, MakeImageBlock_1);
	Gura_AssignMethod(wx_RichTextImageBlock, MakeImageBlockDefaultQuality);
	Gura_AssignMethod(wx_RichTextImageBlock, DoMakeImageBlock);
	Gura_AssignMethod(wx_RichTextImageBlock, Write);
	Gura_AssignMethod(wx_RichTextImageBlock, WriteHex);
	Gura_AssignMethod(wx_RichTextImageBlock, ReadHex);
	Gura_AssignMethod(wx_RichTextImageBlock, Copy);
	Gura_AssignMethod(wx_RichTextImageBlock, Load);
	Gura_AssignMethod(wx_RichTextImageBlock, GetData);
	Gura_AssignMethod(wx_RichTextImageBlock, GetDataSize);
	Gura_AssignMethod(wx_RichTextImageBlock, GetImageType);
	Gura_AssignMethod(wx_RichTextImageBlock, SetData);
	Gura_AssignMethod(wx_RichTextImageBlock, SetDataSize);
	Gura_AssignMethod(wx_RichTextImageBlock, SetImageType);
	Gura_AssignMethod(wx_RichTextImageBlock, IsOk);
	Gura_AssignMethod(wx_RichTextImageBlock, Ok);
	Gura_AssignMethod(wx_RichTextImageBlock, GetExtension);
	Gura_AssignMethod(wx_RichTextImageBlock, ReadBlock);
	Gura_AssignMethod(wx_RichTextImageBlock, ReadBlock_1);
	Gura_AssignMethod(wx_RichTextImageBlock, WriteBlock);
	Gura_AssignMethod(wx_RichTextImageBlock, WriteBlock_1);
}

Gura_ImplementDescendantCreator(wx_RichTextImageBlock)
{
	return new Object_wx_RichTextImageBlock((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
