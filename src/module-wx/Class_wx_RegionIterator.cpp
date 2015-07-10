//----------------------------------------------------------------------------
// wxRegionIterator
// extracted from region.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RegionIterator: public wxRegionIterator, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_RegionIterator *_pObj;
public:
	inline wx_RegionIterator() : wxRegionIterator(), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_RegionIterator(const wxRegion& region) : wxRegionIterator(region), _pSig(nullptr), _pObj(nullptr) {}
	~wx_RegionIterator();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RegionIterator *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RegionIterator::~wx_RegionIterator()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RegionIterator::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRegionIterator
//----------------------------------------------------------------------------
Gura_DeclareFunction(RegionIteratorEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RegionIterator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RegionIteratorEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_RegionIterator *pEntity = new wx_RegionIterator();
	Object_wx_RegionIterator *pObj = Object_wx_RegionIterator::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RegionIterator(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(RegionIterator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RegionIterator));
	DeclareArg(env, "region", VTYPE_wx_Region, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RegionIterator)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxRegion *region = Object_wx_Region::GetObject(args, 0)->GetEntity();
	wx_RegionIterator *pEntity = new wx_RegionIterator(*region);
	Object_wx_RegionIterator *pObj = Object_wx_RegionIterator::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RegionIterator(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_RegionIterator, GetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegionIterator, GetX)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pThis->GetEntity()->GetX();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegionIterator, GetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegionIterator, GetY)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pThis->GetEntity()->GetY();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegionIterator, GetW)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegionIterator, GetW)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pThis->GetEntity()->GetW();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegionIterator, GetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegionIterator, GetHeight)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pThis->GetEntity()->GetHeight();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegionIterator, GetH)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegionIterator, GetH)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pThis->GetEntity()->GetH();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegionIterator, GetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegionIterator, GetRect)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect rtn = pThis->GetEntity()->GetRect();
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_RegionIterator, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegionIterator, GetWidth)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pThis->GetEntity()->GetWidth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegionIterator, HaveRects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegionIterator, HaveRects)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HaveRects();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegionIterator, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "region", VTYPE_wx_Region, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegionIterator, Reset)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	if (args.IsValid(0)) {
		wxRegion *region = Object_wx_Region::GetObject(args, 0)->GetEntity();
		pThis->GetEntity()->Reset(*region);
	} else {
		pThis->GetEntity()->Reset();
	}
	return Value::Null;
}

Gura_DeclareMethod(wx_RegionIterator, Next)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, Next)
{
	Object_wx_RegionIterator *pThis = Object_wx_RegionIterator::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	(*pThis->GetEntity())++;
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxRegionIterator
//----------------------------------------------------------------------------
Object_wx_RegionIterator::~Object_wx_RegionIterator()
{
}

Object *Object_wx_RegionIterator::Clone() const
{
	return nullptr;
}

String Object_wx_RegionIterator::ToString(bool exprFlag)
{
	String rtn("<wx.RegionIterator:");
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
// Class implementation for wxRegionIterator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RegionIterator)
{
	Gura_AssignFunction(RegionIteratorEmpty);
	Gura_AssignFunction(RegionIterator);
	Gura_AssignMethod(wx_RegionIterator, GetX);
	Gura_AssignMethod(wx_RegionIterator, GetY);
	Gura_AssignMethod(wx_RegionIterator, GetW);
	Gura_AssignMethod(wx_RegionIterator, GetHeight);
	Gura_AssignMethod(wx_RegionIterator, GetH);
	Gura_AssignMethod(wx_RegionIterator, GetRect);
	Gura_AssignMethod(wx_RegionIterator, GetWidth);
	Gura_AssignMethod(wx_RegionIterator, HaveRects);
	Gura_AssignMethod(wx_RegionIterator, Reset);
	Gura_AssignMethod(wx_RegionIterator, Next);
}

Gura_ImplementDescendantCreator(wx_RegionIterator)
{
	return new Object_wx_RegionIterator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
