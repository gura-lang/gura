//----------------------------------------------------------------------------
// wxGridCellAttrProvider
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(GetAttr);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellAttrProvider: public wxGridCellAttrProvider, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	AutoPtr<Object_wx_GridCellAttrProvider> _pObj;
public:
	~wx_GridCellAttrProvider();
	inline void AssocWithGura(Object_wx_GridCellAttrProvider *pObj) {
		_pObj.reset(Object_wx_GridCellAttrProvider::Reference(pObj));
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
	Function *pFunc = Gura_LookupWxMethod(_pObj, GetAttr);
	if (pFunc == nullptr) {
		return wxGridCellAttrProvider::GetAttr(row, col, kind);
	}
	ValueList valList;
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	valList.push_back(Value(kind));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_wx_GridCellAttr, true)) return nullptr;
	return rtn.IsValid()? Object_wx_GridCellAttr::GetObject(rtn)->GetEntity() : nullptr;
}

void wx_GridCellAttrProvider::GuraObjectDeleted()
{
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellAttrProvider
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridCellAttrProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GridCellAttrProvider));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellAttrProvider)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_GridCellAttrProvider *pEntity = new wx_GridCellAttrProvider();
	Object_wx_GridCellAttrProvider *pObj = Object_wx_GridCellAttrProvider::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridCellAttrProvider(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_GridCellAttrProvider, GetAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttrProvider, GetAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttrProvider *pThis = Object_wx_GridCellAttrProvider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxGridCellAttr::wxAttrKind kind = static_cast<wxGridCellAttr::wxAttrKind>(args.GetInt(2));
	wxGridCellAttr *rtn = dynamic_cast<wx_GridCellAttrProvider *>(pThis->GetEntity())->_GetAttr(row, col, kind);
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_GridCellAttr(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, args, value);
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellAttrProvider
//----------------------------------------------------------------------------
Object_wx_GridCellAttrProvider::~Object_wx_GridCellAttrProvider()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_GridCellAttrProvider::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellAttrProvider::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellAttrProvider:");
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
// Class implementation for wxGridCellAttrProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellAttrProvider)
{
	Gura_RealizeUserSymbol(GetAttr);
	Gura_AssignFunction(GridCellAttrProvider);
	Gura_AssignMethod(wx_GridCellAttrProvider, GetAttr);
}

Gura_ImplementDescendantCreator(wx_GridCellAttrProvider)
{
	return new Object_wx_GridCellAttrProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
