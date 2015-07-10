//----------------------------------------------------------------------------
// wxGBPosition
// extracted from gbposition.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GBPosition: public wxGBPosition, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_GBPosition *_pObj;
public:
	inline wx_GBPosition() : wxGBPosition(), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_GBPosition(int row, int col) : wxGBPosition(row, col), _pSig(nullptr), _pObj(nullptr) {}
	~wx_GBPosition();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GBPosition *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GBPosition::~wx_GBPosition()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GBPosition::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGBPosition
//----------------------------------------------------------------------------
Gura_DeclareFunction(GBPositionEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GBPosition));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GBPositionEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GBPosition *pEntity = new wx_GBPosition();
	Object_wx_GBPosition *pObj = Object_wx_GBPosition::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GBPosition(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(GBPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GBPosition));
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GBPosition)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wx_GBPosition *pEntity = new wx_GBPosition(row, col);
	Object_wx_GBPosition *pObj = Object_wx_GBPosition::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GBPosition(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_GBPosition, GetCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBPosition, GetCol)
{
	Object_wx_GBPosition *pThis = Object_wx_GBPosition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetCol();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GBPosition, GetRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBPosition, GetRow)
{
	Object_wx_GBPosition *pThis = Object_wx_GBPosition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetRow();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GBPosition, SetCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBPosition, SetCol)
{
	Object_wx_GBPosition *pThis = Object_wx_GBPosition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	pThis->GetEntity()->SetCol(col);
	return Value::Null;
}

Gura_DeclareMethod(wx_GBPosition, SetRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBPosition, SetRow)
{
	Object_wx_GBPosition *pThis = Object_wx_GBPosition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	pThis->GetEntity()->SetRow(row);
	return Value::Null;
}

// operator ==
Gura_ImplementBinaryOperator(Eq, wx_GBPosition, wx_GBPosition)
{
	wxGBPosition *item1 = Object_wx_GBPosition::GetObject(valueLeft)->GetEntity();
	wxGBPosition *item2 = Object_wx_GBPosition::GetObject(valueRight)->GetEntity();
	return *item1 == *item2;
}

// operator !=
Gura_ImplementBinaryOperator(Ne, wx_GBPosition, wx_GBPosition)
{
	wxGBPosition *item1 = Object_wx_GBPosition::GetObject(valueLeft)->GetEntity();
	wxGBPosition *item2 = Object_wx_GBPosition::GetObject(valueRight)->GetEntity();
	return *item1 != *item2;
}

#if 0
// operator !
Gura_ImplementUnaryOperator(Not, wx_GBPosition)
{
	wxGBPosition *item = Object_wx_GBPosition::GetObject(value)->GetEntity();
	return Value(!*item);
}
#endif

//----------------------------------------------------------------------------
// Object implementation for wxGBPosition
//----------------------------------------------------------------------------
Object_wx_GBPosition::~Object_wx_GBPosition()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_GBPosition::Clone() const
{
	return nullptr;
}

String Object_wx_GBPosition::ToString(bool exprFlag)
{
	String rtn("<wx.GBPosition:");
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
// Class implementation for wxGBPosition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GBPosition)
{
	Gura_AssignFunction(GBPositionEmpty);
	Gura_AssignFunction(GBPosition);
	Gura_AssignBinaryOperator(Eq, wx_GBPosition, wx_GBPosition);
	Gura_AssignBinaryOperator(Ne, wx_GBPosition, wx_GBPosition);
	//Gura_AssignUnaryOperator(Not, wx_GBPosition);
	Gura_AssignMethod(wx_GBPosition, GetCol);
	Gura_AssignMethod(wx_GBPosition, GetRow);
	Gura_AssignMethod(wx_GBPosition, SetCol);
	Gura_AssignMethod(wx_GBPosition, SetRow);
}

Gura_ImplementDescendantCreator(wx_GBPosition)
{
	return new Object_wx_GBPosition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
