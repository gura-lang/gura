//----------------------------------------------------------------------------
// wxGridSizer
// extracted from gridsizr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridSizer: public wxGridSizer, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_GridSizer *_pObj;
public:
	inline wx_GridSizer(int rows, int cols, int vgap, int hgap) : wxGridSizer(rows, cols, vgap, hgap), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_GridSizer(int cols, int vgap, int hgap) : wxGridSizer(cols, vgap, hgap), _pSig(nullptr), _pObj(nullptr) {}
	~wx_GridSizer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridSizer *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridSizer::~wx_GridSizer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GridSizer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridSizer
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GridSizer));
	DeclareArg(env, "rows", VTYPE_number, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "vgap", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "hgap", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridSizer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int rows = 0;
	int cols = args.GetInt(1);
	int vgap = 0;
	if (args.IsValid(2)) vgap = args.GetInt(2);
	int hgap = 0;
	if (args.IsValid(3)) hgap = args.GetInt(3);
	wx_GridSizer *pEntity = nullptr;
	if (args.Is_number(0)) {
		int rows = args.GetInt(0);
		pEntity = new wx_GridSizer(rows, cols, vgap, hgap);
	} else {
		pEntity = new wx_GridSizer(cols, vgap, hgap);
	}
	Object_wx_GridSizer *pObj = Object_wx_GridSizer::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridSizer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_GridSizer, GetCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizer, GetCols)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetCols();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridSizer, GetHGap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizer, GetHGap)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetHGap();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridSizer, GetRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizer, GetRows)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetRows();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridSizer, GetVGap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizer, GetVGap)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetVGap();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridSizer, SetCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, SetCols)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int cols = args.GetInt(0);
	pThis->GetEntity()->SetCols(cols);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridSizer, SetHGap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "gap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, SetHGap)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int gap = args.GetInt(0);
	pThis->GetEntity()->SetHGap(gap);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridSizer, SetRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, SetRows)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rows = args.GetInt(0);
	pThis->GetEntity()->SetRows(rows);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridSizer, SetVGap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "gap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, SetVGap)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int gap = args.GetInt(0);
	pThis->GetEntity()->SetVGap(gap);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxGridSizer
//----------------------------------------------------------------------------
Object_wx_GridSizer::~Object_wx_GridSizer()
{
}

Object *Object_wx_GridSizer::Clone() const
{
	return nullptr;
}

String Object_wx_GridSizer::ToString(bool exprFlag)
{
	String rtn("<wx.GridSizer:");
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
// Class implementation for wxGridSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridSizer)
{
	Gura_AssignFunction(GridSizer);
	Gura_AssignMethod(wx_GridSizer, GetCols);
	Gura_AssignMethod(wx_GridSizer, GetHGap);
	Gura_AssignMethod(wx_GridSizer, GetRows);
	Gura_AssignMethod(wx_GridSizer, GetVGap);
	Gura_AssignMethod(wx_GridSizer, SetCols);
	Gura_AssignMethod(wx_GridSizer, SetHGap);
	Gura_AssignMethod(wx_GridSizer, SetRows);
	Gura_AssignMethod(wx_GridSizer, SetVGap);
}

Gura_ImplementDescendantCreator(wx_GridSizer)
{
	return new Object_wx_GridSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
