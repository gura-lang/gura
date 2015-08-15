//----------------------------------------------------------------------------
// wxTextDropTarget
// extracted from txtdrptg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(OnDrop);
Gura_DeclarePrivUserSymbol(OnDropText);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TextDropTarget: public wxTextDropTarget, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_TextDropTarget *_pObj;
public:
	inline wx_TextDropTarget() : wxTextDropTarget(), _pObj(nullptr) {}
	~wx_TextDropTarget();
	virtual bool OnDrop(wxCoord x, wxCoord y);
	virtual bool OnDropText(wxCoord x, wxCoord y, const wxString& data);
	inline void AssocWithGura(Object_wx_TextDropTarget *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TextDropTarget::~wx_TextDropTarget()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TextDropTarget::GuraObjectDeleted()
{
	_pObj = nullptr;
}

bool wx_TextDropTarget::OnDrop(wxCoord x, wxCoord y)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnDrop);
	if (pFunc == nullptr) return wxTextDropTarget::OnDrop(x, y);
	Environment &env = *_pObj;
	ValueList valList;
	valList.push_back(Value(x));
	valList.push_back(Value(y));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

bool wx_TextDropTarget::OnDropText(wxCoord x, wxCoord y, const wxString& data)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnDropText);
	if (pFunc == nullptr) return false;
	Environment &env = *_pObj;
	ValueList valList;
	valList.push_back(Value(x));
	valList.push_back(Value(y));
	valList.push_back(Value(data.ToUTF8()));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}
	
//----------------------------------------------------------------------------
// Gura interfaces for wxTextDropTarget
//----------------------------------------------------------------------------
Gura_DeclareFunction(TextDropTarget)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TextDropTarget));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TextDropTarget)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_TextDropTarget *pEntity = new wx_TextDropTarget();
	Object_wx_TextDropTarget *pObj = Object_wx_TextDropTarget::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TextDropTarget(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_TextDropTarget, OnDrop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextDropTarget, OnDrop)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextDropTarget *pThis = Object_wx_TextDropTarget::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long x = args.GetLong(0);
	long y = args.GetLong(1);
	int *data = args.GetInt(2);
	size_t size = args.GetSizeT(3);
	bool rtn = pThis->GetEntity()->OnDrop(x, y, *data, size);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextDropTarget, OnDropText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextDropTarget, OnDropText)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextDropTarget *pThis = Object_wx_TextDropTarget::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxString data = wxString::FromUTF8(args.GetString(2));
	bool rtn = pThis->GetEntity()->OnDropText(x, y, data);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxTextDropTarget
//----------------------------------------------------------------------------
Object_wx_TextDropTarget::~Object_wx_TextDropTarget()
{
}

Object *Object_wx_TextDropTarget::Clone() const
{
	return nullptr;
}

String Object_wx_TextDropTarget::ToString(bool exprFlag)
{
	String rtn("<wx.TextDropTarget:");
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
// Class implementation for wxTextDropTarget
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextDropTarget)
{
	Gura_RealizeUserSymbol(OnDrop);
	Gura_RealizeUserSymbol(OnDropText);
	Gura_AssignFunction(TextDropTarget);
	Gura_AssignMethod(wx_TextDropTarget, OnDrop);
	Gura_AssignMethod(wx_TextDropTarget, OnDropText);
}

Gura_ImplementDescendantCreator(wx_TextDropTarget)
{
	return new Object_wx_TextDropTarget((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
