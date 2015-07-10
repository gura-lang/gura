//----------------------------------------------------------------------------
// wxSizerFlags
// extracted from sizer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SizerFlags: public wxSizerFlags, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_SizerFlags *_pObj;
public:
	inline wx_SizerFlags(int proportion) : wxSizerFlags(proportion), _pSig(nullptr), _pObj(nullptr) {}
	~wx_SizerFlags();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SizerFlags *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SizerFlags::~wx_SizerFlags()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SizerFlags::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSizerFlags
//----------------------------------------------------------------------------
Gura_DeclareFunction(SizerFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SizerFlags));
	DeclareArg(env, "proportion", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SizerFlags)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int proportion = 0;
	if (args.IsValid(0)) proportion = args.GetInt(0);
	wx_SizerFlags *pEntity = new wx_SizerFlags(proportion);
	Object_wx_SizerFlags *pObj = Object_wx_SizerFlags::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SizerFlags(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_SizerFlags, Align)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "align", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SizerFlags, Align)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int align = 0;
	if (args.IsValid(0)) align = args.GetInt(0);
	wxSizerFlags &rtn = pThis->GetEntity()->Align(align);
	return ReturnValue(env, sig, args, Value(new Object_wx_SizerFlags(new wxSizerFlags(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_SizerFlags, Border)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "borderinpixels", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SizerFlags, Border)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	if (args.IsInvalid(0)) {
		wxSizerFlags &rtn = pThis->GetEntity()->Border();
		return ReturnValue(env, sig, args, Value(new Object_wx_SizerFlags(new wxSizerFlags(rtn), nullptr, OwnerTrue)));
	}
	int direction = args.GetInt(0);
	int borderinpixels = -1;
	if (args.IsValid(1)) borderinpixels = args.GetInt(1);
	wxSizerFlags &rtn = pThis->GetEntity()->Border(direction, borderinpixels);
	return ReturnValue(env, sig, args, Value(new Object_wx_SizerFlags(new wxSizerFlags(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_SizerFlags, Center)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SizerFlags, Center)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSizerFlags &rtn = pThis->GetEntity()->Center();
	return ReturnValue(env, sig, args, Value(new Object_wx_SizerFlags(new wxSizerFlags(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_SizerFlags, Centre)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SizerFlags, Centre)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSizerFlags &rtn = pThis->GetEntity()->Centre();
	return ReturnValue(env, sig, args, Value(new Object_wx_SizerFlags(new wxSizerFlags(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_SizerFlags, DoubleBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SizerFlags, DoubleBorder)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int direction = wxALL;
	if (args.IsValid(0)) direction = args.GetInt(0);
	wxSizerFlags &rtn = pThis->GetEntity()->DoubleBorder(direction);
	return ReturnValue(env, sig, args, Value(new Object_wx_SizerFlags(new wxSizerFlags(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_SizerFlags, DoubleHorzBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SizerFlags, DoubleHorzBorder)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSizerFlags &rtn = pThis->GetEntity()->DoubleHorzBorder();
	return ReturnValue(env, sig, args, Value(new Object_wx_SizerFlags(new wxSizerFlags(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_SizerFlags, Expand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SizerFlags, Expand)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSizerFlags &rtn = pThis->GetEntity()->Expand();
	return ReturnValue(env, sig, args, Value(new Object_wx_SizerFlags(new wxSizerFlags(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_SizerFlags, GetDefaultBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_SizerFlags, GetDefaultBorder)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int rtn = wxSizerFlags::GetDefaultBorder();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SizerFlags, Left)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SizerFlags, Left)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSizerFlags &rtn = pThis->GetEntity()->Left();
	return ReturnValue(env, sig, args, Value(new Object_wx_SizerFlags(new wxSizerFlags(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_SizerFlags, FixedMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SizerFlags, FixedMinSize)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSizerFlags &rtn = pThis->GetEntity()->FixedMinSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_SizerFlags(new wxSizerFlags(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_SizerFlags, Proportion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "proportion", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SizerFlags, Proportion)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int proportion = 0;
	if (args.IsValid(0)) proportion = args.GetInt(0);
	wxSizerFlags &rtn = pThis->GetEntity()->Proportion(proportion);
	return ReturnValue(env, sig, args, Value(new Object_wx_SizerFlags(new wxSizerFlags(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_SizerFlags, ReserveSpaceEvenIfHidden)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SizerFlags, ReserveSpaceEvenIfHidden)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSizerFlags &rtn = pThis->GetEntity()->ReserveSpaceEvenIfHidden();
	return ReturnValue(env, sig, args, Value(new Object_wx_SizerFlags(new wxSizerFlags(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_SizerFlags, Right)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SizerFlags, Right)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSizerFlags &rtn = pThis->GetEntity()->Right();
	return ReturnValue(env, sig, args, Value(new Object_wx_SizerFlags(new wxSizerFlags(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_SizerFlags, Shaped)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SizerFlags, Shaped)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSizerFlags &rtn = pThis->GetEntity()->Shaped();
	return ReturnValue(env, sig, args, Value(new Object_wx_SizerFlags(new wxSizerFlags(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_SizerFlags, TripleBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SizerFlags, TripleBorder)
{
	Object_wx_SizerFlags *pThis = Object_wx_SizerFlags::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int direction = wxALL;
	if (args.IsValid(0)) direction = args.GetInt(0);
	wxSizerFlags &rtn = pThis->GetEntity()->TripleBorder(direction);
	return ReturnValue(env, sig, args, Value(new Object_wx_SizerFlags(new wxSizerFlags(rtn), nullptr, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxSizerFlags
//----------------------------------------------------------------------------
Object_wx_SizerFlags::~Object_wx_SizerFlags()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_SizerFlags::Clone() const
{
	return nullptr;
}

String Object_wx_SizerFlags::ToString(bool exprFlag)
{
	String rtn("<wx.SizerFlags:");
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
// Class implementation for wxSizerFlags
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SizerFlags)
{
	Gura_AssignFunction(SizerFlags);
	Gura_AssignMethod(wx_SizerFlags, Align);
	Gura_AssignMethod(wx_SizerFlags, Border);
	Gura_AssignMethod(wx_SizerFlags, Center);
	Gura_AssignMethod(wx_SizerFlags, Centre);
	Gura_AssignMethod(wx_SizerFlags, DoubleBorder);
	Gura_AssignMethod(wx_SizerFlags, DoubleHorzBorder);
	Gura_AssignMethod(wx_SizerFlags, Expand);
	Gura_AssignMethod(wx_SizerFlags, GetDefaultBorder);
	Gura_AssignMethod(wx_SizerFlags, Left);
	Gura_AssignMethod(wx_SizerFlags, FixedMinSize);
	Gura_AssignMethod(wx_SizerFlags, Proportion);
	Gura_AssignMethod(wx_SizerFlags, ReserveSpaceEvenIfHidden);
	Gura_AssignMethod(wx_SizerFlags, Right);
	Gura_AssignMethod(wx_SizerFlags, Shaped);
	Gura_AssignMethod(wx_SizerFlags, TripleBorder);
}

Gura_ImplementDescendantCreator(wx_SizerFlags)
{
	return new Object_wx_SizerFlags((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
