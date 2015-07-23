//----------------------------------------------------------------------------
// wxDropTarget
// extracted from droptrgt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(GetData);
Gura_DeclarePrivUserSymbol(OnData);
Gura_DeclarePrivUserSymbol(OnDrop);
Gura_DeclarePrivUserSymbol(OnEnter);
Gura_DeclarePrivUserSymbol(OnDragOver);
Gura_DeclarePrivUserSymbol(OnLeave);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DropTarget: public wxDropTarget, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DropTarget *_pObj;
public:
	inline wx_DropTarget(wxDataObject* data) : wxDropTarget(data), _pObj(nullptr) {}
	virtual bool GetData();
	virtual wxDragResult OnData(wxCoord x, wxCoord y, wxDragResult def);
	virtual bool OnDrop(wxCoord x, wxCoord y);
	virtual wxDragResult OnEnter(wxCoord x, wxCoord y, wxDragResult def);
	virtual wxDragResult OnDragOver(wxCoord x, wxCoord y, wxDragResult def);
	virtual void OnLeave();
	~wx_DropTarget();
	inline void AssocWithGura(Object_wx_DropTarget *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DropTarget::~wx_DropTarget()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DropTarget::GuraObjectDeleted()
{
	_pObj = nullptr;
}

bool wx_DropTarget::GetData()
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetData);
	if (pFunc == nullptr) return wxDropTarget::GetData();
	Value rtn = _pObj->EvalMethod(*_pObj, _pObj->GetSignal(), pFunc, ValueList::Null);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

wxDragResult wx_DropTarget::OnData(wxCoord x, wxCoord y, wxDragResult def)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnData);
	if (pFunc == nullptr) return def;
	Environment &env = *_pObj;
	ValueList valList;
	valList.push_back(Value(x));
	valList.push_back(Value(y));
	valList.push_back(Value(def));
	Value rtn = _pObj->EvalMethod(*_pObj, _pObj->GetSignal(), pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_number)) return def;
	return static_cast<wxDragResult>(rtn.GetInt());
}

bool wx_DropTarget::OnDrop(wxCoord x, wxCoord y)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnDrop);
	if (pFunc == nullptr) return wxDropTarget::OnDrop(x, y);
	Environment &env = *_pObj;
	ValueList valList;
	valList.push_back(Value(x));
	valList.push_back(Value(y));
	Value rtn = _pObj->EvalMethod(*_pObj, _pObj->GetSignal(), pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

wxDragResult wx_DropTarget::OnEnter(wxCoord x, wxCoord y, wxDragResult def)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnEnter);
	if (pFunc == nullptr) return wxDropTarget::OnEnter(x, y, def);
	Environment &env = *_pObj;
	ValueList valList;
	valList.push_back(Value(x));
	valList.push_back(Value(y));
	valList.push_back(Value(def));
	Value rtn = _pObj->EvalMethod(*_pObj, _pObj->GetSignal(), pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_number)) return def;
	return static_cast<wxDragResult>(rtn.GetInt());
}

wxDragResult wx_DropTarget::OnDragOver(wxCoord x, wxCoord y, wxDragResult def)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnDragOver);
	if (pFunc == nullptr) return wxDropTarget::OnDragOver(x, y, def);
	Environment &env = *_pObj;
	ValueList valList;
	valList.push_back(Value(x));
	valList.push_back(Value(y));
	valList.push_back(Value(def));
	Value rtn = _pObj->EvalMethod(*_pObj, _pObj->GetSignal(), pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_number)) return def;
	return static_cast<wxDragResult>(rtn.GetInt());
}

void wx_DropTarget::OnLeave()
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnLeave);
	if (pFunc == nullptr) return;
	_pObj->EvalMethod(*_pObj, _pObj->GetSignal(), pFunc, ValueList::Null);
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDropTarget
//----------------------------------------------------------------------------
Gura_DeclareFunction(DropTarget)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DropTarget));
	DeclareArg(env, "data", VTYPE_wx_DataObject, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DropTarget)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDataObject *data = (wxDataObject *)(nullptr);
	if (args.IsValid(0)) data = Object_wx_DataObject::GetObject(args, 0)->GetEntity();
	wx_DropTarget *pEntity = new wx_DropTarget(data);
	Object_wx_DropTarget *pObj = Object_wx_DropTarget::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DropTarget(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_DropTarget, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DropTarget, GetData)
{
#if 0
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->GetData();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DropTarget, OnData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "def", VTYPE_wx_DragResult, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DropTarget, OnData)
{
#if 0
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxDragResult *def = Object_wx_DragResult::GetObject(args, 2)->GetEntity();
	wxDragResult rtn = pThis->GetEntity()->OnData(x, y, *def);
	return ReturnValue(env, args, Value(new Object_wx_DragResult(new wxDragResult(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DropTarget, OnDrop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DropTarget, OnDrop)
{
#if 0
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	bool rtn = pThis->GetEntity()->OnDrop(x, y);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DropTarget, OnEnter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "def", VTYPE_wx_DragResult, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DropTarget, OnEnter)
{
#if 0
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxDragResult *def = Object_wx_DragResult::GetObject(args, 2)->GetEntity();
	wxDragResult rtn = pThis->GetEntity()->OnEnter(x, y, *def);
	return ReturnValue(env, args, Value(new Object_wx_DragResult(new wxDragResult(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DropTarget, OnDragOver)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "def", VTYPE_wx_DragResult, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DropTarget, OnDragOver)
{
#if 0
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxDragResult *def = Object_wx_DragResult::GetObject(args, 2)->GetEntity();
	wxDragResult rtn = pThis->GetEntity()->OnDragOver(x, y, *def);
	return ReturnValue(env, args, Value(new Object_wx_DragResult(new wxDragResult(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DropTarget, OnLeave)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DropTarget, OnLeave)
{
#if 0
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->OnLeave();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DropTarget, SetDataObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "data", VTYPE_wx_DataObject, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_DropTarget, SetDataObject)
{
#if 0
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataObject *data = Object_wx_DataObject::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDataObject(data);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDropTarget
//----------------------------------------------------------------------------
Object_wx_DropTarget::~Object_wx_DropTarget()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_DropTarget::Clone() const
{
	return nullptr;
}

String Object_wx_DropTarget::ToString(bool exprFlag)
{
	String rtn("<wx.DropTarget:");
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
// Class implementation for wxDropTarget
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DropTarget)
{
	Gura_RealizeUserSymbol(GetData);
	Gura_RealizeUserSymbol(OnData);
	Gura_RealizeUserSymbol(OnDrop);
	Gura_RealizeUserSymbol(OnEnter);
	Gura_RealizeUserSymbol(OnDragOver);
	Gura_RealizeUserSymbol(OnLeave);
	Gura_AssignFunction(DropTarget);
	Gura_AssignMethod(wx_DropTarget, GetData);
	Gura_AssignMethod(wx_DropTarget, OnData);
	Gura_AssignMethod(wx_DropTarget, OnDrop);
	Gura_AssignMethod(wx_DropTarget, OnEnter);
	Gura_AssignMethod(wx_DropTarget, OnDragOver);
	Gura_AssignMethod(wx_DropTarget, OnLeave);
	Gura_AssignMethod(wx_DropTarget, SetDataObject);
}

Gura_ImplementDescendantCreator(wx_DropTarget)
{
	return new Object_wx_DropTarget((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
