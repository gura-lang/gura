//----------------------------------------------------------------------------
// wxRealPoint
// extracted from realpoin.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RealPoint: public wxRealPoint, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_RealPoint *_pObj;
public:
	inline wx_RealPoint() : wxRealPoint(), _pObj(nullptr) {}
	inline wx_RealPoint(double x, double y) : wxRealPoint(x, y), _pObj(nullptr) {}
	~wx_RealPoint();
	inline void AssocWithGura(Object_wx_RealPoint *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RealPoint::~wx_RealPoint()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RealPoint::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRealPoint
//----------------------------------------------------------------------------
Gura_DeclareFunction(RealPointEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RealPoint));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RealPointEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wx_RealPoint *pEntity = new wx_RealPoint();
	Object_wx_RealPoint *pObj = Object_wx_RealPoint::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RealPoint(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(RealPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RealPoint));
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RealPoint)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	double x = args.GetDouble(0);
	double y = args.GetDouble(1);
	wx_RealPoint *pEntity = new wx_RealPoint(x, y);
	Object_wx_RealPoint *pObj = Object_wx_RealPoint::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RealPoint(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxRealPoint
//----------------------------------------------------------------------------
Object_wx_RealPoint::~Object_wx_RealPoint()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_RealPoint::Clone() const
{
	return nullptr;
}

String Object_wx_RealPoint::ToString(bool exprFlag)
{
	String rtn("<wx.RealPoint:");
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
// Class implementation for wxRealPoint
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RealPoint)
{
	Gura_AssignFunction(RealPointEmpty);
	Gura_AssignFunction(RealPoint);
}

Gura_ImplementDescendantCreator(wx_RealPoint)
{
	return new Object_wx_RealPoint((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
