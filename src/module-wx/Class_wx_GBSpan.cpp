//----------------------------------------------------------------------------
// wxGBSpan
// extracted from gbspan.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GBSpan: public wxGBSpan, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_GBSpan *_pObj;
public:
	inline wx_GBSpan() : wxGBSpan(), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_GBSpan(int rowspan, int colspan) : wxGBSpan(rowspan, colspan), _pSig(nullptr), _pObj(nullptr) {}
	~wx_GBSpan();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GBSpan *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GBSpan::~wx_GBSpan()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GBSpan::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGBSpan
//----------------------------------------------------------------------------
Gura_DeclareFunction(GBSpanEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GBSpan));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GBSpanEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GBSpan *pEntity = new wx_GBSpan();
	Object_wx_GBSpan *pObj = Object_wx_GBSpan::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GBSpan(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(GBSpan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GBSpan));
	DeclareArg(env, "rowspan", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "colspan", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GBSpan)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int rowspan = args.GetInt(0);
	int colspan = args.GetInt(1);
	wx_GBSpan *pEntity = new wx_GBSpan(rowspan, colspan);
	Object_wx_GBSpan *pObj = Object_wx_GBSpan::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GBSpan(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_GBSpan, GetColspan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBSpan, GetColspan)
{
	Object_wx_GBSpan *pThis = Object_wx_GBSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetColspan();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GBSpan, GetRowspan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GBSpan, GetRowspan)
{
	Object_wx_GBSpan *pThis = Object_wx_GBSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetRowspan();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GBSpan, SetColspan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colspan", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSpan, SetColspan)
{
	Object_wx_GBSpan *pThis = Object_wx_GBSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int colspan = args.GetInt(0);
	pThis->GetEntity()->SetColspan(colspan);
	return Value::Null;
}

Gura_DeclareMethod(wx_GBSpan, SetRowspan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rowspan", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSpan, SetRowspan)
{
	Object_wx_GBSpan *pThis = Object_wx_GBSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rowspan = args.GetInt(0);
	pThis->GetEntity()->SetRowspan(rowspan);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxGBSpan
//----------------------------------------------------------------------------
Object_wx_GBSpan::~Object_wx_GBSpan()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_GBSpan::Clone() const
{
	return nullptr;
}

String Object_wx_GBSpan::ToString(bool exprFlag)
{
	String rtn("<wx.GBSpan:");
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
// Class implementation for wxGBSpan
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GBSpan)
{
	Gura_AssignFunction(GBSpanEmpty);
	Gura_AssignFunction(GBSpan);
	Gura_AssignMethod(wx_GBSpan, GetColspan);
	Gura_AssignMethod(wx_GBSpan, GetRowspan);
	Gura_AssignMethod(wx_GBSpan, SetColspan);
	Gura_AssignMethod(wx_GBSpan, SetRowspan);
}

Gura_ImplementDescendantCreator(wx_GBSpan)
{
	return new Object_wx_GBSpan((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
