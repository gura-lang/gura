//----------------------------------------------------------------------------
// wxPoint
// extracted from point.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Point: public wxPoint, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Point *_pObj;
public:
	inline wx_Point() : wxPoint(), _pObj(nullptr) {}
	inline wx_Point(int x, int y) : wxPoint(x, y), _pObj(nullptr) {}
	~wx_Point();
	inline void AssocWithGura(Object_wx_Point *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Point::~wx_Point()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Point::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPoint
//----------------------------------------------------------------------------
Gura_DeclareFunction(PointEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Point));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PointEmpty)
{
	Signal &sig = env.GetSignal();
	//if (!CheckWxReady(sig)) return Value::Nil;
	wx_Point *pEntity = new wx_Point();
	Object_wx_Point *pObj = Object_wx_Point::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Point(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(Point)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Point));
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Point)
{
	Signal &sig = env.GetSignal();
	//if (!CheckWxReady(sig)) return Value::Nil;
	int x = 0;
	if (arg.IsValid(0)) x = arg.GetInt(0);
	int y = 0;
	if (arg.IsValid(1)) y = arg.GetInt(1);
	wx_Point *pEntity = new wx_Point(x, y);
	Object_wx_Point *pObj = Object_wx_Point::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Point(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

// operator ==
Gura_ImplementBinaryOperator(Eq, wx_Point, wx_Point)
{
	wxPoint *item1 = Object_wx_Point::GetObject(valueLeft)->GetEntity();
	wxPoint *item2 = Object_wx_Point::GetObject(valueRight)->GetEntity();
	return *item1 == *item2;
}

// operator !=
Gura_ImplementBinaryOperator(Ne, wx_Point, wx_Point)
{
	wxPoint *item1 = Object_wx_Point::GetObject(valueLeft)->GetEntity();
	wxPoint *item2 = Object_wx_Point::GetObject(valueRight)->GetEntity();
	return *item1 != *item2;
}

// operator +
Gura_ImplementBinaryOperator(Add, wx_Point, any)
{
	Signal &sig = env.GetSignal();
	wxPoint *item1 = Object_wx_Point::GetObject(valueLeft)->GetEntity();
	wxPoint rtn;
	if (valueRight.IsInstanceOf(VTYPE_wx_Point)) {
		wxPoint *item2 = Object_wx_Point::GetObject(valueRight)->GetEntity();
		rtn = *item1 + *item2;
	} else if (valueRight.IsInstanceOf(VTYPE_wx_Size)) {
		wxSize *item2 = Object_wx_Size::GetObject(valueRight)->GetEntity();
		rtn = *item1 + *item2;
	} else {
		SetError_InvalidValueType(sig, valueLeft, valueRight);
		return Value::Nil;
	}
	return Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue));
}

// operator -
Gura_ImplementBinaryOperator(Sub, wx_Point, any)
{
	Signal &sig = env.GetSignal();
	wxPoint *item1 = Object_wx_Point::GetObject(valueLeft)->GetEntity();
	wxPoint rtn;
	if (valueRight.IsInstanceOf(VTYPE_wx_Point)) {
		wxPoint *item2 = Object_wx_Point::GetObject(valueRight)->GetEntity();
		rtn = *item1 - *item2;
	} else if (valueRight.IsInstanceOf(VTYPE_wx_Size)) {
		wxSize *item2 = Object_wx_Size::GetObject(valueRight)->GetEntity();
		rtn = *item1 - *item2;
	} else {
		SetError_InvalidValueType(sig, valueLeft, valueRight);
		return Value::Nil;
	}
	return Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// wx.Point#x
Gura_DeclareProperty_RW(wx_Point, x)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(wx_Point, x)
{
	Object_wx_Point *pObjThis = Object_wx_Point::GetObject(valueThis);
	return Value(pObjThis->GetEntity()->x);
}

Gura_ImplementPropertySetter(wx_Point, x)
{
	Object_wx_Point *pObjThis = Object_wx_Point::GetObject(valueThis);
	pObjThis->GetEntity()->x = value.GetInt();
	return value;
}

// wx.Point#y
Gura_DeclareProperty_RW(wx_Point, y)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(wx_Point, y)
{
	Object_wx_Point *pObjThis = Object_wx_Point::GetObject(valueThis);
	return Value(pObjThis->GetEntity()->y);
}

Gura_ImplementPropertySetter(wx_Point, y)
{
	Object_wx_Point *pObjThis = Object_wx_Point::GetObject(valueThis);
	pObjThis->GetEntity()->y = value.GetInt();
	return value;
}

//----------------------------------------------------------------------------
// Object implementation for wxPoint
//----------------------------------------------------------------------------
Object_wx_Point::~Object_wx_Point()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_Point::Clone() const
{
	return nullptr;
}

String Object_wx_Point::ToString(bool exprFlag)
{
	String rtn("<wx.Point:");
	if (GetEntity() == nullptr) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%d,%d>", GetEntity()->x, GetEntity()->y);
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxPoint
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Point)
{
	// Assignment of properties
	Gura_AssignProperty(wx_Point, x);
	Gura_AssignProperty(wx_Point, y);
	// Assignment of function
	Gura_AssignFunction(PointEmpty);
	Gura_AssignFunction(Point);
	// Assignment of operators
	Gura_AssignBinaryOperator(Eq, wx_Point, wx_Point);
	Gura_AssignBinaryOperator(Ne, wx_Point, wx_Point);
	Gura_AssignBinaryOperator(Add, wx_Point, any);
	Gura_AssignBinaryOperator(Sub, wx_Point, any);
}

Gura_ImplementDescendantCreator(wx_Point)
{
	return new Object_wx_Point((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
