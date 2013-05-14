//----------------------------------------------------------------------------
// wxSize
// extracted from size.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Size: public wxSize, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Size *_pObj;
public:
	inline wx_Size() : wxSize(), _sig(NULL), _pObj(NULL) {}
	inline wx_Size(int width, int height) : wxSize(width, height), _sig(NULL), _pObj(NULL) {}
	~wx_Size();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Size *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Size::~wx_Size()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Size::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSize
//----------------------------------------------------------------------------
Gura_DeclareFunction(SizeEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Size));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SizeEmpty)
{
	//if (!CheckWxReady(sig)) return Value::Null;
	wx_Size *pEntity = new wx_Size();
	Object_wx_Size *pObj = Object_wx_Size::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Size(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Size)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Size));
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Size)
{
	//if (!CheckWxReady(sig)) return Value::Null;
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	wx_Size *pEntity = new wx_Size(width, height);
	Object_wx_Size *pObj = Object_wx_Size::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Size(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_Size, DecBy)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, DecBy)
{
	Object_wx_Size *pThis = Object_wx_Size::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->DecBy(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_Size, DecBy_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, DecBy_1)
{
	Object_wx_Size *pThis = Object_wx_Size::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int dx = args.GetInt(0);
	int dy = args.GetInt(1);
	pThis->GetEntity()->DecBy(dx, dy);
	return Value::Null;
}

Gura_DeclareMethod(wx_Size, DecBy_2)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, DecBy_2)
{
	Object_wx_Size *pThis = Object_wx_Size::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int d = args.GetInt(0);
	pThis->GetEntity()->DecBy(d);
	return Value::Null;
}

Gura_DeclareMethod(wx_Size, DecTo)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, DecTo)
{
	Object_wx_Size *pThis = Object_wx_Size::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->DecTo(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_Size, IsFullySpecified)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Size, IsFullySpecified)
{
	Object_wx_Size *pThis = Object_wx_Size::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsFullySpecified();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Size, GetWidth)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Size, GetWidth)
{
	Object_wx_Size *pThis = Object_wx_Size::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetWidth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Size, GetHeight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Size, GetHeight)
{
	Object_wx_Size *pThis = Object_wx_Size::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetHeight();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Size, IncBy)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, IncBy)
{
	Object_wx_Size *pThis = Object_wx_Size::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->IncBy(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_Size, IncBy_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, IncBy_1)
{
	Object_wx_Size *pThis = Object_wx_Size::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int dx = args.GetInt(0);
	int dy = args.GetInt(1);
	pThis->GetEntity()->IncBy(dx, dy);
	return Value::Null;
}

Gura_DeclareMethod(wx_Size, IncBy_2)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, IncBy_2)
{
	Object_wx_Size *pThis = Object_wx_Size::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int d = args.GetInt(0);
	pThis->GetEntity()->IncBy(d);
	return Value::Null;
}

Gura_DeclareMethod(wx_Size, IncTo)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, IncTo)
{
	Object_wx_Size *pThis = Object_wx_Size::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->IncTo(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_Size, Scale)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "xscale", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "yscale", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Size, Scale)
{
	Object_wx_Size *pThis = Object_wx_Size::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	float xscale = args.GetFloat(0);
	float yscale = args.GetFloat(1);
	wxSize &rtn = pThis->GetEntity()->Scale(xscale, yscale);
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Size, Set)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, Set)
{
	Object_wx_Size *pThis = Object_wx_Size::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	pThis->GetEntity()->Set(width, height);
	return Value::Null;
}

Gura_DeclareMethod(wx_Size, SetDefaults)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sizeDefault", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, SetDefaults)
{
	Object_wx_Size *pThis = Object_wx_Size::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *sizeDefault = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDefaults(*sizeDefault);
	return Value::Null;
}

Gura_DeclareMethod(wx_Size, SetHeight)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, SetHeight)
{
	Object_wx_Size *pThis = Object_wx_Size::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int height = args.GetInt(0);
	pThis->GetEntity()->SetHeight(height);
	return Value::Null;
}

Gura_DeclareMethod(wx_Size, SetWidth)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Size, SetWidth)
{
	Object_wx_Size *pThis = Object_wx_Size::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pThis->GetEntity()->SetWidth(width);
	return Value::Null;
}

// operator ==
Gura_ImplementBinaryOperator(Eq, wx_Size, wx_Size)
{
	wxSize *item1 = Object_wx_Size::GetObject(valueLeft)->GetEntity();
	wxSize *item2 = Object_wx_Size::GetObject(valueRight)->GetEntity();
	return *item1 == *item2;
}

// operator !=
Gura_ImplementBinaryOperator(Ne, wx_Size, wx_Size)
{
	wxSize *item1 = Object_wx_Size::GetObject(valueLeft)->GetEntity();
	wxSize *item2 = Object_wx_Size::GetObject(valueRight)->GetEntity();
	return *item1 != *item2;
}

// operator +
Gura_ImplementBinaryOperator(Add, wx_Size, wx_Size)
{
	wxSize *item1 = Object_wx_Size::GetObject(valueLeft)->GetEntity();
	wxSize *item2 = Object_wx_Size::GetObject(valueRight)->GetEntity();
	wxSize rtn = *item1 + *item2;
	return Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue));
}

// operator -
Gura_ImplementBinaryOperator(Sub, wx_Size, wx_Size)
{
	wxSize *item1 = Object_wx_Size::GetObject(valueLeft)->GetEntity();
	wxSize *item2 = Object_wx_Size::GetObject(valueRight)->GetEntity();
	wxSize rtn = *item1 - *item2;
	return Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue));
}

// operator *
Gura_ImplementBinaryOperator(Mul, wx_Size, number)
{
	wxSize *item = Object_wx_Size::GetObject(valueLeft)->GetEntity();
	int factor = valueRight.GetInt();
	wxSize rtn = *item * factor;
	return Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue));
}

// operator /
Gura_ImplementBinaryOperator(Div, wx_Size, number)
{
	wxSize *item = Object_wx_Size::GetObject(valueLeft)->GetEntity();
	int factor = valueRight.GetInt();
	wxSize rtn = *item / factor;
	return Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue));
}

//----------------------------------------------------------------------------
// Object implementation for wxSize
//----------------------------------------------------------------------------
Object_wx_Size::~Object_wx_Size()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_Size::Clone() const
{
	return NULL;
}

bool Object_wx_Size::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
	return true;
}

Value Object_wx_Size::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		return GetEntity()->x;
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		return GetEntity()->y;
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_wx_Size::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
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

String Object_wx_Size::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Size:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%d,%d>", GetEntity()->x, GetEntity()->y);
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Size::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(SizeEmpty);
	Gura_AssignFunction(Size);
	Gura_AssignBinaryOperator(Eq, wx_Size, wx_Size);
	Gura_AssignBinaryOperator(Ne, wx_Size, wx_Size);
	Gura_AssignBinaryOperator(Add, wx_Size, wx_Size);
	Gura_AssignBinaryOperator(Sub, wx_Size, wx_Size);
	Gura_AssignBinaryOperator(Mul, wx_Size, number);
	Gura_AssignBinaryOperator(Div, wx_Size, number);
}

//----------------------------------------------------------------------------
// Class implementation for wxSize
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Size)
{
	Gura_AssignMethod(wx_Size, DecBy);
	Gura_AssignMethod(wx_Size, DecBy_1);
	Gura_AssignMethod(wx_Size, DecBy_2);
	Gura_AssignMethod(wx_Size, DecTo);
	Gura_AssignMethod(wx_Size, IsFullySpecified);
	Gura_AssignMethod(wx_Size, GetWidth);
	Gura_AssignMethod(wx_Size, GetHeight);
	Gura_AssignMethod(wx_Size, IncBy);
	Gura_AssignMethod(wx_Size, IncBy_1);
	Gura_AssignMethod(wx_Size, IncBy_2);
	Gura_AssignMethod(wx_Size, IncTo);
	Gura_AssignMethod(wx_Size, Scale);
	Gura_AssignMethod(wx_Size, Set);
	Gura_AssignMethod(wx_Size, SetDefaults);
	Gura_AssignMethod(wx_Size, SetHeight);
	Gura_AssignMethod(wx_Size, SetWidth);
}

Gura_ImplementDescendantCreator(wx_Size)
{
	return new Object_wx_Size((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
