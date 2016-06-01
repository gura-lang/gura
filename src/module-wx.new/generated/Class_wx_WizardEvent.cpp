//----------------------------------------------------------------------------
// wxWizardEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWizardEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWizardEvent
//----------------------------------------------------------------------------
Object_wx_WizardEvent::~Object_wx_WizardEvent()
{
}

Object *Object_wx_WizardEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WizardEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WizardEvent:");
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
Gura_DeclareMethod(wx_WizardEvent, wxWizardEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardEvent, wxWizardEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_WizardEvent *pThis = Object_wx_WizardEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int direction = arg.GetNumber(2)
	//int page = arg.GetNumber(3)
	//pThis->GetEntity()->wxWizardEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WizardEvent, GetDirection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WizardEvent, GetDirection)
{
	Signal &sig = env.GetSignal();
	Object_wx_WizardEvent *pThis = Object_wx_WizardEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDirection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WizardEvent, GetPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WizardEvent, GetPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_WizardEvent *pThis = Object_wx_WizardEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPage();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWizardEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WizardEvent)
{
	Gura_AssignMethod(wx_WizardEvent, wxWizardEvent);
	Gura_AssignMethod(wx_WizardEvent, GetDirection);
	Gura_AssignMethod(wx_WizardEvent, GetPage);
}

Gura_ImplementDescendantCreator(wx_WizardEvent)
{
	return new Object_wx_WizardEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
