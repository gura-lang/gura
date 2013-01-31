//----------------------------------------------------------------------------
// wxGBPosition
// extracted from gbposition.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GBPosition: public wxGBPosition, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GBPosition *_pObj;
public:
	inline wx_GBPosition() : wxGBPosition(), _sig(NULL), _pObj(NULL) {}
	inline wx_GBPosition(int row, int col) : wxGBPosition(row, col), _sig(NULL), _pObj(NULL) {}
	~wx_GBPosition();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GBPosition *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GBPosition::~wx_GBPosition()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GBPosition::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGBPosition
//----------------------------------------------------------------------------
Gura_DeclareFunction(GBPositionEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GBPosition));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GBPositionEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GBPosition *pEntity = new wx_GBPosition();
	Object_wx_GBPosition *pObj = Object_wx_GBPosition::GetThisObj(args);
	if (pObj == NULL) {
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (pObj == NULL) {
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
	SetMode(RSLTMODE_Normal, FLAG_None);
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
	SetMode(RSLTMODE_Normal, FLAG_None);
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
	SetMode(RSLTMODE_Void, FLAG_Map);
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
	SetMode(RSLTMODE_Void, FLAG_Map);
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

Gura_DeclareMethod(wx_GBPosition, __eq__)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "item1", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareArg(env, "item2", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBPosition, __eq__)
{
	Object_wx_GBPosition *pThis = Object_wx_GBPosition::GetThisObj(args);
	wxGBPosition *item1 = Object_wx_GBPosition::GetObject(args, 0)->GetEntity();
	wxGBPosition *item2 = Object_wx_GBPosition::GetObject(args, 1)->GetEntity();
	return *item1 == *item2;
}

Gura_DeclareMethod(wx_GBPosition, __ne__)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "item1", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareArg(env, "item2", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBPosition, __ne__)
{
	Object_wx_GBPosition *pThis = Object_wx_GBPosition::GetThisObj(args);
	wxGBPosition *item1 = Object_wx_GBPosition::GetObject(args, 0)->GetEntity();
	wxGBPosition *item2 = Object_wx_GBPosition::GetObject(args, 1)->GetEntity();
	return *item1 != *item2;
}

#if 0
Gura_DeclareMethod(wx_GBPosition, __not__)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "item", VTYPE_wx_GBPosition, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBPosition, __not__)
{
	Object_wx_GBPosition *pThis = Object_wx_GBPosition::GetThisObj(args);
	wxGBPosition *item = Object_wx_GBPosition::GetObject(args, 0)->GetEntity();
	return Value(!*item);
}
#endif

//----------------------------------------------------------------------------
// Object implementation for wxGBPosition
//----------------------------------------------------------------------------
Object_wx_GBPosition::~Object_wx_GBPosition()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_GBPosition::Clone() const
{
	return NULL;
}

String Object_wx_GBPosition::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GBPosition:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_GBPosition::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(GBPositionEmpty);
	Gura_AssignFunction(GBPosition);
}

//----------------------------------------------------------------------------
// Class implementation for wxGBPosition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GBPosition)
{
	Gura_AssignMethod(wx_GBPosition, GetCol);
	Gura_AssignMethod(wx_GBPosition, GetRow);
	Gura_AssignMethod(wx_GBPosition, SetCol);
	Gura_AssignMethod(wx_GBPosition, SetRow);
	Gura_AssignMethod(wx_GBPosition, __eq__);
	Gura_AssignMethod(wx_GBPosition, __ne__);
	//Gura_AssignMethod(wx_GBPosition, __not__);
}

Gura_ImplementDescendantCreator(wx_GBPosition)
{
	return new Object_wx_GBPosition((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
