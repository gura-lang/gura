//----------------------------------------------------------------------------
// wxDataObjectComposite
// extracted from dobjcomp.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataObjectComposite: public wxDataObjectComposite, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DataObjectComposite *_pObj;
public:
	inline wx_DataObjectComposite() : wxDataObjectComposite(), _sig(NULL), _pObj(NULL) {}
	~wx_DataObjectComposite();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DataObjectComposite *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataObjectComposite::~wx_DataObjectComposite()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DataObjectComposite::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataObjectComposite
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataObjectCompositeEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DataObjectComposite));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataObjectCompositeEmpty)
{
	wx_DataObjectComposite *pEntity = new wx_DataObjectComposite();
	Object_wx_DataObjectComposite *pObj = Object_wx_DataObjectComposite::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DataObjectComposite(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_DataObjectComposite, Add)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*dataObject", VTYPE_wx_DataObjectSimple, OCCUR_Once);
	DeclareArg(env, "preferred", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_DataObjectComposite, Add)
{
#if 0
	Object_wx_DataObjectComposite *pSelf = Object_wx_DataObjectComposite::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDataObjectSimple **dataObject = Object_wx_DataObjectSimple::GetObject(args, 0)->GetEntity();
	bool preferred = false;
	if (args.IsValid(1)) preferred = args.GetBoolean(1);
	pSelf->GetEntity()->Add(**dataObject, preferred);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataObjectComposite, GetReceivedFormat)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataObjectComposite, GetReceivedFormat)
{
	Object_wx_DataObjectComposite *pSelf = Object_wx_DataObjectComposite::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDataFormat rtn = pSelf->GetEntity()->GetReceivedFormat();
	return ReturnValue(env, sig, args, Value(new Object_wx_DataFormat(new wxDataFormat(rtn), NULL, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxDataObjectComposite
//----------------------------------------------------------------------------
Object_wx_DataObjectComposite::~Object_wx_DataObjectComposite()
{
}

Object *Object_wx_DataObjectComposite::Clone() const
{
	return NULL;
}

String Object_wx_DataObjectComposite::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DataObjectComposite:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DataObjectComposite::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(DataObjectCompositeEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxDataObjectComposite
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataObjectComposite)
{
	Gura_AssignMethod(wx_DataObjectComposite, Add);
	Gura_AssignMethod(wx_DataObjectComposite, GetReceivedFormat);
}

Gura_ImplementDescendantCreator(wx_DataObjectComposite)
{
	return new Object_wx_DataObjectComposite((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
