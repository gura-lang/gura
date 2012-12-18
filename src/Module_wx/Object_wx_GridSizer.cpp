//----------------------------------------------------------------------------
// wxGridSizer
// extracted from gridsizr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridSizer: public wxGridSizer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GridSizer *_pObj;
public:
	inline wx_GridSizer(int rows, int cols, int vgap, int hgap) : wxGridSizer(rows, cols, vgap, hgap), _sig(NULL), _pObj(NULL) {}
	inline wx_GridSizer(int cols, int vgap, int hgap) : wxGridSizer(cols, vgap, hgap), _sig(NULL), _pObj(NULL) {}
	~wx_GridSizer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridSizer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridSizer::~wx_GridSizer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GridSizer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridSizer
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridSizer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GridSizer));
	DeclareArg(env, "rows", VTYPE_number, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "vgap", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "hgap", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridSizer)
{
	int rows = 0;
	int cols = args.GetInt(1);
	int vgap = 0;
	if (args.IsValid(2)) vgap = args.GetInt(2);
	int hgap = 0;
	if (args.IsValid(3)) hgap = args.GetInt(3);
	wx_GridSizer *pEntity = NULL;
	if (args.IsNumber(0)) {
		int rows = args.GetInt(0);
		pEntity = new wx_GridSizer(rows, cols, vgap, hgap);
	} else {
		pEntity = new wx_GridSizer(cols, vgap, hgap);
	}
	Object_wx_GridSizer *pObj = Object_wx_GridSizer::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GridSizer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_GridSizer, GetCols)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizer, GetCols)
{
	Object_wx_GridSizer *pSelf = Object_wx_GridSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetCols();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridSizer, GetHGap)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizer, GetHGap)
{
	Object_wx_GridSizer *pSelf = Object_wx_GridSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetHGap();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridSizer, GetRows)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizer, GetRows)
{
	Object_wx_GridSizer *pSelf = Object_wx_GridSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetRows();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridSizer, GetVGap)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridSizer, GetVGap)
{
	Object_wx_GridSizer *pSelf = Object_wx_GridSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetVGap();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridSizer, SetCols)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, SetCols)
{
	Object_wx_GridSizer *pSelf = Object_wx_GridSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int cols = args.GetInt(0);
	pSelf->GetEntity()->SetCols(cols);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridSizer, SetHGap)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "gap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, SetHGap)
{
	Object_wx_GridSizer *pSelf = Object_wx_GridSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int gap = args.GetInt(0);
	pSelf->GetEntity()->SetHGap(gap);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridSizer, SetRows)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, SetRows)
{
	Object_wx_GridSizer *pSelf = Object_wx_GridSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rows = args.GetInt(0);
	pSelf->GetEntity()->SetRows(rows);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridSizer, SetVGap)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "gap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, SetVGap)
{
	Object_wx_GridSizer *pSelf = Object_wx_GridSizer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int gap = args.GetInt(0);
	pSelf->GetEntity()->SetVGap(gap);
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
	return NULL;
}

String Object_wx_GridSizer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GridSizer:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_GridSizer::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(GridSizer);
}

//----------------------------------------------------------------------------
// Class implementation for wxGridSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridSizer)
{
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
	return new Object_wx_GridSizer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
