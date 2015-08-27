//----------------------------------------------------------------------------
// wxDataObjectComposite
// extracted from dobjcomp.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataObjectComposite: public wxDataObjectComposite, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DataObjectComposite *_pObj;
public:
	inline wx_DataObjectComposite() : wxDataObjectComposite(), _pObj(nullptr) {}
	~wx_DataObjectComposite();
	inline void AssocWithGura(Object_wx_DataObjectComposite *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataObjectComposite::~wx_DataObjectComposite()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DataObjectComposite::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataObjectComposite
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataObjectCompositeEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DataObjectComposite));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataObjectCompositeEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_DataObjectComposite *pEntity = new wx_DataObjectComposite();
	Object_wx_DataObjectComposite *pObj = Object_wx_DataObjectComposite::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataObjectComposite(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_DataObjectComposite, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*dataObject", VTYPE_wx_DataObjectSimple, OCCUR_Once);
	DeclareArg(env, "preferred", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_DataObjectComposite, Add)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DataObjectComposite *pThis = Object_wx_DataObjectComposite::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDataObjectSimple **dataObject = Object_wx_DataObjectSimple::GetObject(args, 0)->GetEntity();
	bool preferred = false;
	if (args.IsValid(1)) preferred = args.GetBoolean(1);
	pThis->GetEntity()->Add(**dataObject, preferred);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataObjectComposite, GetReceivedFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataObjectComposite, GetReceivedFormat)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataObjectComposite *pThis = Object_wx_DataObjectComposite::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDataFormat rtn = pThis->GetEntity()->GetReceivedFormat();
	return ReturnValue(env, args, Value(new Object_wx_DataFormat(new wxDataFormat(rtn), nullptr, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxDataObjectComposite
//----------------------------------------------------------------------------
Object_wx_DataObjectComposite::~Object_wx_DataObjectComposite()
{
}

Object *Object_wx_DataObjectComposite::Clone() const
{
	return nullptr;
}

String Object_wx_DataObjectComposite::ToString(bool exprFlag)
{
	String rtn("<wx.DataObjectComposite:");
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
// Class implementation for wxDataObjectComposite
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataObjectComposite)
{
	Gura_AssignFunction(DataObjectCompositeEmpty);
	Gura_AssignMethod(wx_DataObjectComposite, Add);
	Gura_AssignMethod(wx_DataObjectComposite, GetReceivedFormat);
}

Gura_ImplementDescendantCreator(wx_DataObjectComposite)
{
	return new Object_wx_DataObjectComposite((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
