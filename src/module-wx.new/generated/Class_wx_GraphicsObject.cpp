//----------------------------------------------------------------------------
// wxGraphicsObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsObject
//----------------------------------------------------------------------------
Object_wx_GraphicsObject::~Object_wx_GraphicsObject()
{
}

Object *Object_wx_GraphicsObject::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsObject::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsObject:");
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
Gura_DeclareMethod(wx_GraphicsObject, GetRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsObject, GetRenderer)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsObject *pThis = Object_wx_GraphicsObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRenderer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsObject, IsNull)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsObject, IsNull)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsObject *pThis = Object_wx_GraphicsObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsNull();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGraphicsObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsObject)
{
	Gura_AssignMethod(wx_GraphicsObject, GetRenderer);
	Gura_AssignMethod(wx_GraphicsObject, IsNull);
}

Gura_ImplementDescendantCreator(wx_GraphicsObject)
{
	return new Object_wx_GraphicsObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
