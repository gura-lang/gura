//----------------------------------------------------------------------------
// wxRegionIterator
// extracted from region.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RegionIterator: public wxRegionIterator, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RegionIterator *_pObj;
public:
	inline wx_RegionIterator() : wxRegionIterator(), _sig(NULL), _pObj(NULL) {}
	inline wx_RegionIterator(const wxRegion& region) : wxRegionIterator(region), _sig(NULL), _pObj(NULL) {}
	~wx_RegionIterator();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RegionIterator *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RegionIterator::~wx_RegionIterator()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RegionIterator::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRegionIterator
//----------------------------------------------------------------------------
Gura_DeclareFunction(RegionIteratorEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RegionIterator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RegionIteratorEmpty)
{
	wx_RegionIterator *pEntity = new wx_RegionIterator();
	Object_wx_RegionIterator *pObj = Object_wx_RegionIterator::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RegionIterator(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(RegionIterator)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RegionIterator));
	DeclareArg(env, "region", VTYPE_wx_Region, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RegionIterator)
{
	wxRegion *region = Object_wx_Region::GetObject(args, 0)->GetEntity();
	wx_RegionIterator *pEntity = new wx_RegionIterator(*region);
	Object_wx_RegionIterator *pObj = Object_wx_RegionIterator::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RegionIterator(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_RegionIterator, GetX)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegionIterator, GetX)
{
	Object_wx_RegionIterator *pSelf = Object_wx_RegionIterator::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pSelf->GetEntity()->GetX();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegionIterator, GetY)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegionIterator, GetY)
{
	Object_wx_RegionIterator *pSelf = Object_wx_RegionIterator::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pSelf->GetEntity()->GetY();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegionIterator, GetW)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegionIterator, GetW)
{
	Object_wx_RegionIterator *pSelf = Object_wx_RegionIterator::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pSelf->GetEntity()->GetW();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegionIterator, GetHeight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegionIterator, GetHeight)
{
	Object_wx_RegionIterator *pSelf = Object_wx_RegionIterator::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pSelf->GetEntity()->GetHeight();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegionIterator, GetH)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegionIterator, GetH)
{
	Object_wx_RegionIterator *pSelf = Object_wx_RegionIterator::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pSelf->GetEntity()->GetH();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegionIterator, GetRect)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegionIterator, GetRect)
{
	Object_wx_RegionIterator *pSelf = Object_wx_RegionIterator::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRect rtn = pSelf->GetEntity()->GetRect();
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RegionIterator, GetWidth)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegionIterator, GetWidth)
{
	Object_wx_RegionIterator *pSelf = Object_wx_RegionIterator::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pSelf->GetEntity()->GetWidth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegionIterator, HaveRects)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegionIterator, HaveRects)
{
	Object_wx_RegionIterator *pSelf = Object_wx_RegionIterator::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HaveRects();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RegionIterator, Reset)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "region", VTYPE_wx_Region, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegionIterator, Reset)
{
	Object_wx_RegionIterator *pSelf = Object_wx_RegionIterator::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	if (args.IsValid(0)) {
		wxRegion *region = Object_wx_Region::GetObject(args, 0)->GetEntity();
		pSelf->GetEntity()->Reset(*region);
	} else {
		pSelf->GetEntity()->Reset();
	}
	return Value::Null;
}

Gura_DeclareMethod(wx_RegionIterator, Next)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegionIterator, Next)
{
	Object_wx_RegionIterator *pSelf = Object_wx_RegionIterator::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	(*pSelf->GetEntity())++;
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
	return NULL;
}

String Object_wx_RegionIterator::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.RegionIterator:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_RegionIterator::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(RegionIteratorEmpty);
	Gura_AssignFunction(RegionIterator);
}

//----------------------------------------------------------------------------
// Class implementation for wxRegionIterator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RegionIterator)
{
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
	return new Object_wx_RegionIterator((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
