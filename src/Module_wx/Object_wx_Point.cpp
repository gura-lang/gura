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
	Object_wx_Point *pObj = Object_wx_Point::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Point(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
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
	Object_wx_Point *pObj = Object_wx_Point::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Point(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_Point, __eq__)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "item1", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "item2", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Point, __eq__)
{
	Object_wx_Point *pSelf = Object_wx_Point::GetSelfObj(args);
	wxPoint *item1 = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxPoint *item2 = Object_wx_Point::GetObject(args, 1)->GetEntity();
	return *item1 == *item2;
}

Gura_DeclareMethod(wx_Point, __ne__)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "item1", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "item2", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Point, __ne__)
{
	Object_wx_Point *pSelf = Object_wx_Point::GetSelfObj(args);
	wxPoint *item1 = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxPoint *item2 = Object_wx_Point::GetObject(args, 1)->GetEntity();
	return *item1 != *item2;
}

Gura_DeclareMethod(wx_Point, __add__)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "item1", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "item2", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Point, __add__)
{
	Object_wx_Point *pSelf = Object_wx_Point::GetSelfObj(args);
	wxPoint *item1 = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxPoint rtn;
	if (args.IsInstanceOf(1, VTYPE_wx_Point)) {
		wxPoint *item2 = Object_wx_Point::GetObject(args, 1)->GetEntity();
		rtn = *item1 + *item2;
	} else if (args.IsInstanceOf(1, VTYPE_wx_Size)) {
		wxSize *item2 = Object_wx_Size::GetObject(args, 1)->GetEntity();
		rtn = *item1 + *item2;
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 1);
		return Value::Null;
	}
	return Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue));
}

Gura_DeclareMethod(wx_Point, __sub__)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "item1", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "item2", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Point, __sub__)
{
	Object_wx_Point *pSelf = Object_wx_Point::GetSelfObj(args);
	wxPoint *item1 = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxPoint rtn;
	if (args.IsInstanceOf(1, VTYPE_wx_Point)) {
		wxPoint *item2 = Object_wx_Point::GetObject(args, 1)->GetEntity();
		rtn = *item1 - *item2;
	} else if (args.IsInstanceOf(1, VTYPE_wx_Size)) {
		wxSize *item2 = Object_wx_Size::GetObject(args, 1)->GetEntity();
		rtn = *item1 - *item2;
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 1);
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

bool Object_wx_Point::DoPropDir(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoPropDir(sig, symbols)) return false;
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
	return true;
}

Value Object_wx_Point::DoPropGet(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag)
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

Value Object_wx_Point::DoPropSet(Signal sig,
			const Symbol *pSymbol, const Value &value, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.IsNumber()) {
			sig.SetError(ERR_ValueError, "number must be specified");
			return Value::Null;
		}
		GetEntity()->x = value.GetInt();
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.IsNumber()) {
			sig.SetError(ERR_ValueError, "number must be specified");
			return Value::Null;
		}
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
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Point::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(PointEmpty);
	Gura_AssignFunction(Point);
}

//----------------------------------------------------------------------------
// Class implementation for wxPoint
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Point)
{
	Gura_AssignMethod(wx_Point, __eq__);
	Gura_AssignMethod(wx_Point, __ne__);
	Gura_AssignMethod(wx_Point, __add__);
	Gura_AssignMethod(wx_Point, __sub__);
}

Gura_ImplementDescendantCreator(wx_Point)
{
	return new Object_wx_Point((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
