//----------------------------------------------------------------------------
// wxGridEditorCreatedEvent
// extracted from gridevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridEditorCreatedEvent: public wxGridEditorCreatedEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_GridEditorCreatedEvent *_pObj;
public:
	//inline wx_GridEditorCreatedEvent() : wxGridEditorCreatedEvent(), _pObj(nullptr) {}
	//inline wx_GridEditorCreatedEvent(int id, wxEventType type, wxObject* obj, int row, int col, wxControl* ctrl) : wxGridEditorCreatedEvent(id, type, obj, row, col, ctrl), _pObj(nullptr) {}
	~wx_GridEditorCreatedEvent();
	inline void AssocWithGura(Object_wx_GridEditorCreatedEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridEditorCreatedEvent::~wx_GridEditorCreatedEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GridEditorCreatedEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridEditorCreatedEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridEditorCreatedEventEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_GridEditorCreatedEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(GridEditorCreatedEventEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_GridEditorCreatedEvent *pEntity = new wx_GridEditorCreatedEvent();
	Object_wx_GridEditorCreatedEvent *pObj = Object_wx_GridEditorCreatedEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridEditorCreatedEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GridEditorCreatedEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_GridEditorCreatedEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "obj", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "ctrl", VTYPE_wx_Control, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(GridEditorCreatedEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int id = args.GetInt(0);
	wxEventType type = static_cast<wxEventType>(args.GetInt(1));
	wxObject *obj = Object_wx_Object::GetObject(args, 2)->GetEntity();
	int row = args.GetInt(3);
	int col = args.GetInt(4);
	wxControl *ctrl = Object_wx_Control::GetObject(args, 5)->GetEntity();
	wx_GridEditorCreatedEvent *pEntity = new wx_GridEditorCreatedEvent(id, type, obj, row, col, ctrl);
	Object_wx_GridEditorCreatedEvent *pObj = Object_wx_GridEditorCreatedEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridEditorCreatedEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridEditorCreatedEvent, GetCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, GetCol)
{
#if 0
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetCol();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridEditorCreatedEvent, GetControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, GetControl)
{
#if 0
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxControl *rtn = (wxControl *)pThis->GetEntity()->GetControl();
	return ReturnValue(env, args, Value(new Object_wx_Control(rtn, nullptr, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridEditorCreatedEvent, GetRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, GetRow)
{
#if 0
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetRow();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridEditorCreatedEvent, SetCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, SetCol)
{
#if 0
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	pThis->GetEntity()->SetCol(col);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridEditorCreatedEvent, SetControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "ctrl", VTYPE_wx_Control, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, SetControl)
{
#if 0
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxControl *ctrl = Object_wx_Control::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetControl(ctrl);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridEditorCreatedEvent, SetRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_GridEditorCreatedEvent, SetRow)
{
#if 0
	Object_wx_GridEditorCreatedEvent *pThis = Object_wx_GridEditorCreatedEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	pThis->GetEntity()->SetRow(row);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxGridEditorCreatedEvent
//----------------------------------------------------------------------------
Object_wx_GridEditorCreatedEvent::~Object_wx_GridEditorCreatedEvent()
{
}

Object *Object_wx_GridEditorCreatedEvent::Clone() const
{
	return nullptr;
}

String Object_wx_GridEditorCreatedEvent::ToString(bool exprFlag)
{
	String rtn("<wx.GridEditorCreatedEvent:");
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
// Class implementation for wxGridEditorCreatedEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridEditorCreatedEvent)
{
	Gura_AssignFunction(GridEditorCreatedEventEmpty);
	Gura_AssignFunction(GridEditorCreatedEvent);
	Gura_AssignMethod(wx_GridEditorCreatedEvent, GetCol);
	Gura_AssignMethod(wx_GridEditorCreatedEvent, GetControl);
	Gura_AssignMethod(wx_GridEditorCreatedEvent, GetRow);
	Gura_AssignMethod(wx_GridEditorCreatedEvent, SetCol);
	Gura_AssignMethod(wx_GridEditorCreatedEvent, SetControl);
	Gura_AssignMethod(wx_GridEditorCreatedEvent, SetRow);
}

Gura_ImplementDescendantCreator(wx_GridEditorCreatedEvent)
{
	return new Object_wx_GridEditorCreatedEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
