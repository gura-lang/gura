//----------------------------------------------------------------------------
// wxPoint
// extracted from point.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Point: public wxPoint, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Point *_pObj;
public:
	inline wx_Point() : wxPoint(), _sig(NULL), _pObj(NULL) {}
	inline wx_Point(int x, int y) : wxPoint(x, y), _sig(NULL), _pObj(NULL) {}
	~wx_Point();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Point *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Point::~wx_Point()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Point::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPoint
//----------------------------------------------------------------------------
Gura_DeclareFunction(PointEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Point));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PointEmpty)
{
	//if (!CheckWxReady(sig)) return Value::Null;
	wx_Point *pEntity = new wx_Point();
	Object_wx_Point *pObj = Object_wx_Point::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Point(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Point)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Point));
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Point)
{
	//if (!CheckWxReady(sig)) return Value::Null;
	int x = 0;
	if (args.IsValid(0)) x = args.GetInt(0);
	int y = 0;
	if (args.IsValid(1)) y = args.GetInt(1);
	wx_Point *pEntity = new wx_Point(x, y);
	Object_wx_Point *pObj = Object_wx_Point::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Point(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

// operator ==
Gura_ImplementBinaryOperator(Equal, wx_Point, wx_Point)
{
	wxPoint *item1 = Object_wx_Point::GetObject(valueLeft)->GetEntity();
	wxPoint *item2 = Object_wx_Point::GetObject(valueRight)->GetEntity();
	return *item1 == *item2;
}

// operator !=
Gura_ImplementBinaryOperator(NotEqual, wx_Point, wx_Point)
{
	wxPoint *item1 = Object_wx_Point::GetObject(valueLeft)->GetEntity();
	wxPoint *item2 = Object_wx_Point::GetObject(valueRight)->GetEntity();
	return *item1 != *item2;
}

// operator +
Gura_ImplementBinaryOperator(Plus, wx_Point, any)
{
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
		return Value::Null;
	}
	return Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue));
}

// operator -
Gura_ImplementBinaryOperator(Minus, wx_Point, any)
{
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
		return Value::Null;
	}
	return Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue));
}

//----------------------------------------------------------------------------
// Object implementation for wxPoint
//----------------------------------------------------------------------------
Object_wx_Point::~Object_wx_Point()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_Point::Clone() const
{
	return NULL;
}

bool Object_wx_Point::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
	return true;
}

Value Object_wx_Point::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		return Value(GetEntity()->x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		return Value(GetEntity()->y);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_wx_Point::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		GetEntity()->x = value.GetInt();
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		GetEntity()->y = value.GetInt();
		return value;
	}
	return Value::Null;
}

String Object_wx_Point::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Point:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%d,%d>", GetEntity()->x, GetEntity()->y);
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Point::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(PointEmpty);
	Gura_AssignFunction(Point);
	Gura_AssignBinaryOperator(Equal, wx_Point, wx_Point);
	Gura_AssignBinaryOperator(NotEqual, wx_Point, wx_Point);
	Gura_AssignBinaryOperator(Plus, wx_Point, any);
	Gura_AssignBinaryOperator(Minus, wx_Point, any);
}

//----------------------------------------------------------------------------
// Class implementation for wxPoint
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Point)
{
}

Gura_ImplementDescendantCreator(wx_Point)
{
	return new Object_wx_Point((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
