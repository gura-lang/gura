//----------------------------------------------------------------------------
// wxRichTextRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextRenderer
//----------------------------------------------------------------------------
Object_wx_RichTextRenderer::~Object_wx_RichTextRenderer()
{
}

Object *Object_wx_RichTextRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextRenderer:");
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
Gura_DeclareFunctionAlias(__wxRichTextRenderer, "wxRichTextRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxRichTextRenderer)
{
	//wxRichTextRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextRenderer, __DrawStandardBullet, "DrawStandardBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paragraph", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRenderer, __DrawStandardBullet)
{
	Object_wx_RichTextRenderer *pThis = Object_wx_RichTextRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int paragraph = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int attr = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawStandardBullet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRenderer, __DrawTextBullet, "DrawTextBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paragraph", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRenderer, __DrawTextBullet)
{
	Object_wx_RichTextRenderer *pThis = Object_wx_RichTextRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int paragraph = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int attr = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//int text = arg.GetNumber(4)
	//pThis->GetEntity()->DrawTextBullet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRenderer, __DrawBitmapBullet, "DrawBitmapBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paragraph", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRenderer, __DrawBitmapBullet)
{
	Object_wx_RichTextRenderer *pThis = Object_wx_RichTextRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int paragraph = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int attr = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawBitmapBullet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRenderer, __EnumerateStandardBulletNames, "EnumerateStandardBulletNames")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bulletNames", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRenderer, __EnumerateStandardBulletNames)
{
	Object_wx_RichTextRenderer *pThis = Object_wx_RichTextRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bulletNames = arg.GetNumber(0)
	//pThis->GetEntity()->EnumerateStandardBulletNames();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRenderer, __MeasureBullet, "MeasureBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paragraph", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRenderer, __MeasureBullet)
{
	Object_wx_RichTextRenderer *pThis = Object_wx_RichTextRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int paragraph = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int attr = arg.GetNumber(2)
	//int sz = arg.GetNumber(3)
	//pThis->GetEntity()->MeasureBullet();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextRenderer)
{
	// Constructor assignment
	Gura_AssignFunction(__wxRichTextRenderer);
	// Method assignment
	Gura_AssignMethod(wx_RichTextRenderer, __DrawStandardBullet);
	Gura_AssignMethod(wx_RichTextRenderer, __DrawTextBullet);
	Gura_AssignMethod(wx_RichTextRenderer, __DrawBitmapBullet);
	Gura_AssignMethod(wx_RichTextRenderer, __EnumerateStandardBulletNames);
	Gura_AssignMethod(wx_RichTextRenderer, __MeasureBullet);
}

Gura_ImplementDescendantCreator(wx_RichTextRenderer)
{
	return new Object_wx_RichTextRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
