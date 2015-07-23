//----------------------------------------------------------------------------
// wxFlexGridSizer
// extracted from flexsizr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FlexGridSizer: public wxFlexGridSizer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_FlexGridSizer *_pObj;
public:
	inline wx_FlexGridSizer(int rows, int cols, int vgap, int hgap) : wxFlexGridSizer(rows, cols, vgap, hgap), _pObj(nullptr) {}
	inline wx_FlexGridSizer(int cols, int vgap, int hgap) : wxFlexGridSizer(cols, vgap, hgap), _pObj(nullptr) {}
	~wx_FlexGridSizer();
	inline void AssocWithGura(Object_wx_FlexGridSizer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FlexGridSizer::~wx_FlexGridSizer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FlexGridSizer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFlexGridSizer
//----------------------------------------------------------------------------
Gura_DeclareFunction(FlexGridSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FlexGridSizer));
	DeclareArg(env, "rows", VTYPE_number, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "vgap", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "hgap", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FlexGridSizer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int rows = 0;
	int cols = args.GetInt(1);
	int vgap = 0;
	if (args.IsValid(2)) vgap = args.GetInt(2);
	int hgap = 0;
	if (args.IsValid(3)) hgap = args.GetInt(3);
	wx_FlexGridSizer *pEntity = nullptr;
	if (args.Is_number(0)) {
		int rows = args.GetInt(0);
		pEntity = new wx_FlexGridSizer(rows, cols, vgap, hgap);
	} else {
		pEntity = new wx_FlexGridSizer(cols, vgap, hgap);
	}
	Object_wx_FlexGridSizer *pObj = Object_wx_FlexGridSizer::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_FlexGridSizer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_FlexGridSizer, AddGrowableCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "proportion", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FlexGridSizer, AddGrowableCol)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t idx = args.GetSizeT(0);
	int proportion = 0;
	if (args.IsValid(1)) proportion = args.GetInt(1);
	pThis->GetEntity()->AddGrowableCol(idx, proportion);
	return Value::Null;
}

Gura_DeclareMethod(wx_FlexGridSizer, AddGrowableRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "proportion", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FlexGridSizer, AddGrowableRow)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t idx = args.GetSizeT(0);
	int proportion = 0;
	if (args.IsValid(1)) proportion = args.GetInt(1);
	pThis->GetEntity()->AddGrowableRow(idx, proportion);
	return Value::Null;
}

Gura_DeclareMethod(wx_FlexGridSizer, GetFlexibleDirection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FlexGridSizer, GetFlexibleDirection)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetFlexibleDirection();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_FlexGridSizer, GetNonFlexibleGrowMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FlexGridSizer, GetNonFlexibleGrowMode)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetNonFlexibleGrowMode();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_FlexGridSizer, RemoveGrowableCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, RemoveGrowableCol)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t idx = args.GetSizeT(0);
	pThis->GetEntity()->RemoveGrowableCol(idx);
	return Value::Null;
}

Gura_DeclareMethod(wx_FlexGridSizer, RemoveGrowableRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, RemoveGrowableRow)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t idx = args.GetSizeT(0);
	pThis->GetEntity()->RemoveGrowableRow(idx);
	return Value::Null;
}

Gura_DeclareMethod(wx_FlexGridSizer, SetFlexibleDirection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, SetFlexibleDirection)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int direction = args.GetInt(0);
	pThis->GetEntity()->SetFlexibleDirection(direction);
	return Value::Null;
}

Gura_DeclareMethod(wx_FlexGridSizer, SetNonFlexibleGrowMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, SetNonFlexibleGrowMode)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFlexSizerGrowMode mode = static_cast<wxFlexSizerGrowMode>(args.GetInt(0));
	pThis->GetEntity()->SetNonFlexibleGrowMode(mode);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxFlexGridSizer
//----------------------------------------------------------------------------
Object_wx_FlexGridSizer::~Object_wx_FlexGridSizer()
{
}

Object *Object_wx_FlexGridSizer::Clone() const
{
	return nullptr;
}

String Object_wx_FlexGridSizer::ToString(bool exprFlag)
{
	String rtn("<wx.FlexGridSizer:");
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
// Class implementation for wxFlexGridSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FlexGridSizer)
{
	Gura_AssignFunction(FlexGridSizer);
	Gura_AssignMethod(wx_FlexGridSizer, AddGrowableCol);
	Gura_AssignMethod(wx_FlexGridSizer, AddGrowableRow);
	Gura_AssignMethod(wx_FlexGridSizer, GetFlexibleDirection);
	Gura_AssignMethod(wx_FlexGridSizer, GetNonFlexibleGrowMode);
	Gura_AssignMethod(wx_FlexGridSizer, RemoveGrowableCol);
	Gura_AssignMethod(wx_FlexGridSizer, RemoveGrowableRow);
	Gura_AssignMethod(wx_FlexGridSizer, SetFlexibleDirection);
	Gura_AssignMethod(wx_FlexGridSizer, SetNonFlexibleGrowMode);
}

Gura_ImplementDescendantCreator(wx_FlexGridSizer)
{
	return new Object_wx_FlexGridSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
