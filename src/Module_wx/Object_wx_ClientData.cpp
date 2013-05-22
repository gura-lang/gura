//----------------------------------------------------------------------------
// wxClientData
// extracted from clientdat.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
wx_ClientData::~wx_ClientData()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ClientData::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxClientData
//----------------------------------------------------------------------------
Gura_DeclareFunction(ClientData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ClientData));
	DeclareArg(env, "data", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ClientData)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ClientData *pEntity = new wx_ClientData(args.GetValue(0));
	Object_wx_ClientData *pObj = Object_wx_ClientData::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ClientData(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_ClientData, GetData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ClientData, GetData)
{
	Object_wx_ClientData *pThis = Object_wx_ClientData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wx_ClientData *pEntity = dynamic_cast<wx_ClientData *>(pThis->GetEntity());
	if (pEntity == NULL) return Value::Null;
	return pEntity->GetValue();
}

Gura_DeclareMethod(wx_ClientData, SetData)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "data", VTYPE_any, OCCUR_Once);
}

Gura_ImplementMethod(wx_ClientData, SetData)
{
	Object_wx_ClientData *pThis = Object_wx_ClientData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wx_ClientData *pEntity = dynamic_cast<wx_ClientData *>(pThis->GetEntity());
	if (pEntity == NULL) return Value::Null;
	pEntity->SetValue(args.GetValue(0));
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxClientData
//----------------------------------------------------------------------------
Object_wx_ClientData::~Object_wx_ClientData()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_ClientData::Clone() const
{
	return NULL;
}

bool Object_wx_ClientData::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(value));
	return true;
}

Value Object_wx_ClientData::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(value))) {
		evaluatedFlag = true;
		return GetEntity()->GetValue();
	}
	return Value::Null;
}

Value Object_wx_ClientData::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(value))) {
		GetEntity()->SetValue(value);
		return value;
	}
	return Value::Null;
}

String Object_wx_ClientData::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ClientData:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxClientData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClientData)
{
	Gura_AssignFunction(ClientData);
	Gura_AssignMethod(wx_ClientData, GetData);
	Gura_AssignMethod(wx_ClientData, SetData);
}

Gura_ImplementDescendantCreator(wx_ClientData)
{
	return new Object_wx_ClientData((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
