//----------------------------------------------------------------------------
// wxGridCellStringRenderer
// extracted from gridrend.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellStringRenderer: public wxGridCellStringRenderer, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	AutoPtr<Object_wx_GridCellStringRenderer> _pObj;
public:
	inline wx_GridCellStringRenderer() : wxGridCellStringRenderer(), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_GridCellStringRenderer(const wx_GridCellStringRenderer &renderer) :
		wxGridCellStringRenderer(), _pSig(renderer._pSig),
		_pObj(Object_wx_GridCellStringRenderer::Reference(renderer._pObj.get())) {}
	~wx_GridCellStringRenderer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridCellStringRenderer *pObj) {
		_pSig = &sig, _pObj.reset(Object_wx_GridCellStringRenderer::Reference(pObj));
	}
	virtual void Draw(wxGrid &grid, wxGridCellAttr &attr, wxDC &dc,
					const wxRect &rect, int row, int col, bool isSelected);
	virtual wxGridCellRenderer *Clone() const;
	// reveal private or protected member functions to public
	inline void _Draw(wxGrid &grid, wxGridCellAttr &attr, wxDC &dc,
					const wxRect &rect, int row, int col, bool isSelected) {
		wxGridCellStringRenderer::Draw(grid, attr, dc, rect, row, col, isSelected);
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellStringRenderer::~wx_GridCellStringRenderer()
{
}

void wx_GridCellStringRenderer::Draw(wxGrid &grid, wxGridCellAttr &attr, wxDC &dc,
					const wxRect &rect, int row, int col, bool isSelected)
{
	bool evaluatedFlag = false;
	_pObj->EvalMethod_Draw(*_pSig, evaluatedFlag,
							grid, attr, dc, rect, row, col, isSelected);
	if (!evaluatedFlag) wxGridCellStringRenderer::Draw(grid, attr, dc, rect, row, col, isSelected);
}

wxGridCellRenderer *wx_GridCellStringRenderer::Clone() const
{
	return new wx_GridCellStringRenderer(*this);
}

void wx_GridCellStringRenderer::GuraObjectDeleted()
{
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellStringRenderer
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridCellStringRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridCellStringRenderer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellStringRenderer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GridCellStringRenderer *pEntity = new wx_GridCellStringRenderer();
	Object_wx_GridCellStringRenderer *pObj = Object_wx_GridCellStringRenderer::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridCellStringRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_GridCellStringRenderer, Draw)
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

Gura_ImplementMethod(wx_GridCellStringRenderer, Draw)
{
	Object_wx_GridCellRenderer *pThis = Object_wx_GridCellRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGrid *grid = Object_wx_Grid::GetObject(args, 0)->GetEntity();
	wxGridCellAttr *attr = Object_wx_GridCellAttr::GetObject(args, 1)->GetEntity();
	wxDC *dc = Object_wx_DC::GetObject(args, 2)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 3)->GetEntity();
	int row = args.GetInt(4);
	int col = args.GetInt(5);
	bool isSelected = args.GetBoolean(6);
	dynamic_cast<wx_GridCellStringRenderer *>(pThis->GetEntity())->
		_Draw(*grid, *attr, *dc, *rect, row, col, isSelected);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellStringRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellStringRenderer::~Object_wx_GridCellStringRenderer()
{
}

Object *Object_wx_GridCellStringRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellStringRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellStringRenderer:");
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
// Class implementation for wxGridCellStringRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellStringRenderer)
{
	Gura_AssignFunction(GridCellStringRenderer);
	Gura_AssignMethod(wx_GridCellStringRenderer, Draw);
}

Gura_ImplementDescendantCreator(wx_GridCellStringRenderer)
{
	return new Object_wx_GridCellStringRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
