//----------------------------------------------------------------------------
// wxGridCellRenderer
// extracted from gridrend.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(Draw);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellRenderer: public wxGridCellRenderer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	AutoPtr<Object_wx_GridCellRenderer> _pObj;
public:
	~wx_GridCellRenderer();
	inline void AssocWithGura(Object_wx_GridCellRenderer *pObj) {
		_pObj.reset(Object_wx_GridCellRenderer::Reference(pObj));
	}
	virtual void Draw(wxGrid &grid, wxGridCellAttr &attr, wxDC &dc,
					const wxRect &rect, int row, int col, bool isSelected);
	// reveal private or protected member functions to public
	inline void _Draw(wxGrid &grid, wxGridCellAttr &attr, wxDC &dc,
					const wxRect &rect, int row, int col, bool isSelected) {
		wxGridCellRenderer::Draw(grid, attr, dc, rect, row, col, isSelected);
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellRenderer::~wx_GridCellRenderer()
{
}

void wx_GridCellRenderer::Draw(wxGrid &grid, wxGridCellAttr &attr, wxDC &dc,
					const wxRect &rect, int row, int col, bool isSelected)
{
	bool evaluatedFlag = false;
	_pObj->EvalMethod_Draw(_pObj->GetSignal(), evaluatedFlag,
							grid, attr, dc, rect, row, col, isSelected);
	if (!evaluatedFlag) wxGridCellRenderer::Draw(grid, attr, dc, rect, row, col, isSelected);
}

void wx_GridCellRenderer::GuraObjectDeleted()
{
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellRenderer
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_GridCellRenderer, Draw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "grid", VTYPE_wx_Grid, OCCUR_Once);
	DeclareArg(env, "attr", VTYPE_wx_GridCellAttr, OCCUR_Once);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "isSelected", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellRenderer, Draw)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellRenderer *pThis = Object_wx_GridCellRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGrid *grid = Object_wx_Grid::GetObject(args, 0)->GetEntity();
	wxGridCellAttr *attr = Object_wx_GridCellAttr::GetObject(args, 1)->GetEntity();
	wxDC *dc = Object_wx_DC::GetObject(args, 2)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 3)->GetEntity();
	int row = args.GetInt(4);
	int col = args.GetInt(5);
	bool isSelected = args.GetBoolean(6);
	dynamic_cast<wx_GridCellRenderer *>(pThis->GetEntity())->
		_Draw(*grid, *attr, *dc, *rect, row, col, isSelected);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridCellRenderer, GetBestSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "grid", VTYPE_wx_Grid, OCCUR_Once);
	DeclareArg(env, "attr", VTYPE_wx_GridCellAttr, OCCUR_Once);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellRenderer, GetBestSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellRenderer *pThis = Object_wx_GridCellRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGrid *grid = Object_wx_Grid::GetObject(args, 0)->GetEntity();
	wxGridCellAttr *attr = Object_wx_GridCellAttr::GetObject(args, 1)->GetEntity();
	wxDC *dc = Object_wx_DC::GetObject(args, 2)->GetEntity();
	int row = args.GetInt(3);
	int col = args.GetInt(4);
	wxSize rtn = pThis->GetEntity()->GetBestSize(*grid, *attr, *dc, row, col);
	return ReturnValue(env, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GridCellRenderer, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridCellRenderer, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellRenderer *pThis = Object_wx_GridCellRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellRenderer *rtn = (wxGridCellRenderer *)pThis->GetEntity()->Clone();
	return ReturnValue(env, args, Value(new Object_wx_GridCellRenderer(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellRenderer::~Object_wx_GridCellRenderer()
{
}

Object *Object_wx_GridCellRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellRenderer:");
	if (GetEntity() == nullptr) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_GridCellRenderer::EvalMethod_Draw(Signal &sig, bool &evaluatedFlag,
			wxGrid &grid, wxGridCellAttr &attr, wxDC &dc,
			const wxRect &rect, int row, int col, bool isSelected)
{
	evaluatedFlag = false;
	const Function *pFunc = LookupFunctionCustom(Gura_UserSymbol(Draw), ENVREF_Escalate);
	if (pFunc == nullptr) return;
	evaluatedFlag = true;
	ValueList valList;
	valList.push_back(Value(new Object_wx_Grid(&grid, nullptr, OwnerFalse)));
	valList.push_back(Value(new Object_wx_GridCellAttr(&attr, nullptr, OwnerFalse)));
	valList.push_back(Value(new Object_wx_DC(&dc, nullptr, OwnerFalse)));
	valList.push_back(Value(new Object_wx_Rect(const_cast<wxRect *>(&rect), nullptr, OwnerFalse)));
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	valList.push_back(Value(isSelected));
	Value rtn = EvalMethod(*this, pFunc, valList);
	CheckMethodResult(sig);
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellRenderer)
{
	Gura_RealizeUserSymbol(Draw);
	Gura_AssignMethod(wx_GridCellRenderer, Draw);
	Gura_AssignMethod(wx_GridCellRenderer, GetBestSize);
	Gura_AssignMethod(wx_GridCellRenderer, Clone);
}

Gura_ImplementDescendantCreator(wx_GridCellRenderer)
{
	return new Object_wx_GridCellRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
