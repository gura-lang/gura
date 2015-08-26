//----------------------------------------------------------------------------
// wxClientData
// extracted from clientdat.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
wx_ClientData::~wx_ClientData()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ClientData::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxClientData
//----------------------------------------------------------------------------
Gura_DeclareFunction(ClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ClientData));
	DeclareArg(env, "data", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ClientData)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_ClientData *pEntity = new wx_ClientData(args.GetValue(0));
	Object_wx_ClientData *pObj = Object_wx_ClientData::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ClientData(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_ClientData, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ClientData, GetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_ClientData *pThis = Object_wx_ClientData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wx_ClientData *pEntity = dynamic_cast<wx_ClientData *>(pThis->GetEntity());
	if (pEntity == nullptr) return Value::Nil;
	return pEntity->GetValue();
}

Gura_DeclareMethod(wx_ClientData, SetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "data", VTYPE_any, OCCUR_Once);
}

Gura_ImplementMethod(wx_ClientData, SetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_ClientData *pThis = Object_wx_ClientData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wx_ClientData *pEntity = dynamic_cast<wx_ClientData *>(pThis->GetEntity());
	if (pEntity == nullptr) return Value::Nil;
	pEntity->SetValue(args.GetValue(0));
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxClientData
//----------------------------------------------------------------------------
Object_wx_ClientData::~Object_wx_ClientData()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_ClientData::Clone() const
{
	return nullptr;
}

bool Object_wx_ClientData::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(value));
	return true;
}

Value Object_wx_ClientData::DoGetProp(Environment &env, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(value))) {
		evaluatedFlag = true;
		return GetEntity()->GetValue();
	}
	return Value::Nil;
}

Value Object_wx_ClientData::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(value))) {
		GetEntity()->SetValue(value);
		return value;
	}
	return Value::Nil;
}

String Object_wx_ClientData::ToString(bool exprFlag)
{
	String rtn("<wx.ClientData:");
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
	return new Object_wx_ClientData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
