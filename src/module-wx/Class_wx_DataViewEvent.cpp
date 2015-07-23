//----------------------------------------------------------------------------
// wxDataViewEvent
// extracted from dataviewevent.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataViewEvent: public wxDataViewEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DataViewEvent *_pObj;
public:
	inline wx_DataViewEvent(wxEventType commandType, int winid) : wxDataViewEvent(commandType, winid), _pObj(nullptr) {}
	inline wx_DataViewEvent(const wxDataViewEvent& event) : wxDataViewEvent(event), _pObj(nullptr) {}
	~wx_DataViewEvent();
	inline void AssocWithGura(Object_wx_DataViewEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataViewEvent::~wx_DataViewEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DataViewEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataViewEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DataViewEvent));
	DeclareArg(env, "commandType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "winid", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataViewEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxEventType commandType = wxEVT_NULL;
	if (args.IsValid(0)) commandType = static_cast<wxEventType>(args.GetInt(0));
	int winid = 0;
	if (args.IsValid(1)) winid = args.GetInt(1);
	wx_DataViewEvent *pEntity = new wx_DataViewEvent(commandType, winid);
	Object_wx_DataViewEvent *pObj = Object_wx_DataViewEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataViewEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(DataViewEvent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DataViewEvent));
	DeclareArg(env, "event", VTYPE_wx_DataViewEvent, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataViewEvent_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDataViewEvent *event = Object_wx_DataViewEvent::GetObject(args, 0)->GetEntity();
	wx_DataViewEvent *pEntity = new wx_DataViewEvent(*event);
	Object_wx_DataViewEvent *pObj = Object_wx_DataViewEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataViewEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_DataViewEvent, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewEvent, Clone)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEvent *rtn = (wxEvent *)pThis->GetEntity()->Clone();
	return ReturnValue(env, args, Value(new Object_wx_Event(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DataViewEvent, GetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewEvent, GetColumn)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetColumn();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewEvent, GetDataViewColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewEvent, GetDataViewColumn)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataViewColumn *rtn = (wxDataViewColumn *)pThis->GetEntity()->GetDataViewColumn();
	return ReturnValue(env, args, Value(new Object_wx_DataViewColumn(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DataViewEvent, GetModel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewEvent, GetModel)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataViewModel *rtn = (wxDataViewModel *)pThis->GetEntity()->GetModel();
	return ReturnValue(env, args, Value(new Object_wx_DataViewModel(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DataViewEvent, GetRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewEvent, GetRow)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetRow();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewEvent, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewEvent, GetValue)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxVariant &rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, args, Value(new Object_wx_Variant(new wxVariant(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DataViewEvent, IsEditCancelled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewEvent, IsEditCancelled)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsEditCancelled();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewEvent, SetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetColumn)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	pThis->GetEntity()->SetColumn(col);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewEvent, SetDataViewColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_wx_DataViewColumn, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetDataViewColumn)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataViewColumn *col = Object_wx_DataViewColumn::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDataViewColumn(col);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewEvent, SetEditCanceled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "editCancelled", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetEditCanceled)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool editCancelled = args.GetBoolean(0);
	pThis->GetEntity()->SetEditCanceled(editCancelled);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewEvent, SetModel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "model", VTYPE_wx_DataViewModel, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetModel)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataViewModel *model = Object_wx_DataViewModel::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetModel(model);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewEvent, SetRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetRow)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	pThis->GetEntity()->SetRow(row);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewEvent, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_wx_Variant, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewEvent, SetValue)
{
	Object_wx_DataViewEvent *pThis = Object_wx_DataViewEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxVariant *value = Object_wx_Variant::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetValue(*value);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDataViewEvent
//----------------------------------------------------------------------------
Object_wx_DataViewEvent::~Object_wx_DataViewEvent()
{
}

Object *Object_wx_DataViewEvent::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewEvent::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewEvent:");
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
// Class implementation for wxDataViewEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewEvent)
{
	Gura_AssignFunction(DataViewEvent);
	Gura_AssignFunction(DataViewEvent_1);
	Gura_AssignMethod(wx_DataViewEvent, Clone);
	Gura_AssignMethod(wx_DataViewEvent, GetColumn);
	Gura_AssignMethod(wx_DataViewEvent, GetDataViewColumn);
	Gura_AssignMethod(wx_DataViewEvent, GetModel);
	Gura_AssignMethod(wx_DataViewEvent, GetRow);
	Gura_AssignMethod(wx_DataViewEvent, GetValue);
	Gura_AssignMethod(wx_DataViewEvent, IsEditCancelled);
	Gura_AssignMethod(wx_DataViewEvent, SetColumn);
	Gura_AssignMethod(wx_DataViewEvent, SetDataViewColumn);
	Gura_AssignMethod(wx_DataViewEvent, SetEditCanceled);
	Gura_AssignMethod(wx_DataViewEvent, SetModel);
	Gura_AssignMethod(wx_DataViewEvent, SetRow);
	Gura_AssignMethod(wx_DataViewEvent, SetValue);
}

Gura_ImplementDescendantCreator(wx_DataViewEvent)
{
	return new Object_wx_DataViewEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
