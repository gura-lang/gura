//----------------------------------------------------------------------------
// wxGridCellBoolRenderer
// extracted from gridrend.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridCellBoolRenderer: public wxGridCellBoolRenderer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	AutoPtr<Object_wx_GridCellBoolRenderer> _pObj;
public:
	inline wx_GridCellBoolRenderer() : wxGridCellBoolRenderer(), _pObj(nullptr) {}
	inline wx_GridCellBoolRenderer(const wx_GridCellBoolRenderer &renderer) :
		wxGridCellBoolRenderer(), _pObj(Object_wx_GridCellBoolRenderer::Reference(renderer._pObj.get())) {}
	~wx_GridCellBoolRenderer();
	inline void AssocWithGura(Object_wx_GridCellBoolRenderer *pObj) {
		_pObj.reset(Object_wx_GridCellBoolRenderer::Reference(pObj));
	}
	virtual void Draw(wxGrid &grid, wxGridCellAttr &attr, wxDC &dc,
					const wxRect &rect, int row, int col, bool isSelected);
	virtual wxGridCellRenderer *Clone() const;
	// reveal private or protected member functions to public
	inline void _Draw(wxGrid &grid, wxGridCellAttr &attr, wxDC &dc,
					const wxRect &rect, int row, int col, bool isSelected) {
		wxGridCellBoolRenderer::Draw(grid, attr, dc, rect, row, col, isSelected);
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridCellBoolRenderer::~wx_GridCellBoolRenderer()
{
}

void wx_GridCellBoolRenderer::Draw(wxGrid &grid, wxGridCellAttr &attr, wxDC &dc,
					const wxRect &rect, int row, int col, bool isSelected)
{
	bool evaluatedFlag = false;
	_pObj->EvalMethod_Draw(_pObj->GetSignal(), evaluatedFlag,
							grid, attr, dc, rect, row, col, isSelected);
	if (!evaluatedFlag) wxGridCellBoolRenderer::Draw(grid, attr, dc, rect, row, col, isSelected);
}

wxGridCellRenderer *wx_GridCellBoolRenderer::Clone() const
{
	return new wx_GridCellBoolRenderer(*this);
}

void wx_GridCellBoolRenderer::GuraObjectDeleted()
{
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellBoolRenderer
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridCellBoolRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridCellBoolRenderer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridCellBoolRenderer)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_GridCellBoolRenderer *pEntity = new wx_GridCellBoolRenderer();
	Object_wx_GridCellBoolRenderer *pObj = Object_wx_GridCellBoolRenderer::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridCellBoolRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_GridCellBoolRenderer, Draw)
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

Gura_ImplementMethod(wx_GridCellBoolRenderer, Draw)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellRenderer *pThis = Object_wx_GridCellRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGrid *grid = Object_wx_Grid::GetObject(arg, 0)->GetEntity();
	wxGridCellAttr *attr = Object_wx_GridCellAttr::GetObject(arg, 1)->GetEntity();
	wxDC *dc = Object_wx_DC::GetObject(arg, 2)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(arg, 3)->GetEntity();
	int row = arg.GetInt(4);
	int col = arg.GetInt(5);
	bool isSelected = arg.GetBoolean(6);
	dynamic_cast<wx_GridCellBoolRenderer *>(pThis->GetEntity())->
		_Draw(*grid, *attr, *dc, *rect, row, col, isSelected);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxGridCellBoolRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellBoolRenderer::~Object_wx_GridCellBoolRenderer()
{
}

Object *Object_wx_GridCellBoolRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellBoolRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellBoolRenderer:");
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
// Class implementation for wxGridCellBoolRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellBoolRenderer)
{
	Gura_AssignFunction(GridCellBoolRenderer);
	Gura_AssignMethod(wx_GridCellBoolRenderer, Draw);
}

Gura_ImplementDescendantCreator(wx_GridCellBoolRenderer)
{
	return new Object_wx_GridCellBoolRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
