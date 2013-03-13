//----------------------------------------------------------------------------
// wxGridCellAttrProvider
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(GetAttr);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellAttrProvider: public wxGridCellAttrProvider, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	AutoPtr<Object_wx_GridCellAttrProvider> _pObj;
public:
	~wx_GridCellAttrProvider();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridCellAttrProvider *pObj) {
		_sig = sig, _pObj.reset(Object_wx_GridCellAttrProvider::Reference(pObj));
	}
	virtual wxGridCellAttr *GetAttr(int row, int col,
									wxGridCellAttr::wxAttrKind kind) const;
	// reveal private or protected member functions to public
	inline wxGridCellAttr *_GetAttr(int row, int col, wxGridCellAttr::wxAttrKind kind) const {
		return wxGridCellAttrProvider::GetAttr(row, col, kind);
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellAttrProvider::~wx_GridCellAttrProvider()
{
}

wxGridCellAttr *wx_GridCellAttrProvider::GetAttr(int row, int col, wxGridCellAttr::wxAttrKind kind) const
{
	Function *pFunc = _pObj->LookupFunctionCustom(Gura_UserSymbol(GetAttr), true);
	if (pFunc == NULL) {
		return wxGridCellAttrProvider::GetAttr(row, col, kind);
	}
	ValueList valList;
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	valList.push_back(Value(kind));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	if (!CheckMethodResult(_sig, rtn, VTYPE_wx_GridCellAttr, true)) return NULL;
	return rtn.IsValid()? Object_wx_GridCellAttr::GetObject(rtn)->GetEntity() : NULL;
}

void wx_GridCellAttrProvider::GuraObjectDeleted()
{
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellAttrProvider
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridCellAttrProvider)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GridCellAttrProvider));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellAttrProvider)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GridCellAttrProvider *pEntity = new wx_GridCellAttrProvider();
	Object_wx_GridCellAttrProvider *pObj = Object_wx_GridCellAttrProvider::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GridCellAttrProvider(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_GridCellAttrProvider, GetAttr)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttrProvider, GetAttr)
{
	Object_wx_GridCellAttrProvider *pThis = Object_wx_GridCellAttrProvider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxGridCellAttr::wxAttrKind kind = static_cast<wxGridCellAttr::wxAttrKind>(args.GetInt(2));
	wxGridCellAttr *rtn = dynamic_cast<wx_GridCellAttrProvider *>(pThis->GetEntity())->_GetAttr(row, col, kind);
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_GridCellAttr(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellAttrProvider
//----------------------------------------------------------------------------
Object_wx_GridCellAttrProvider::~Object_wx_GridCellAttrProvider()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_GridCellAttrProvider::Clone() const
{
	return NULL;
}

String Object_wx_GridCellAttrProvider::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GridCellAttrProvider:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_GridCellAttrProvider::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(GetAttr);
	Gura_AssignFunction(GridCellAttrProvider);
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellAttrProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellAttrProvider)
{
	Gura_AssignMethod(wx_GridCellAttrProvider, GetAttr);
}

Gura_ImplementDescendantCreator(wx_GridCellAttrProvider)
{
	return new Object_wx_GridCellAttrProvider((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
