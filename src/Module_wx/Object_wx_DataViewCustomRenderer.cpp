//----------------------------------------------------------------------------
// wxDataViewCustomRenderer
// extracted from dataviewrenderer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(Activate);
Gura_DeclarePrivUserSymbol(GetDC);
Gura_DeclarePrivUserSymbol(GetSize);
Gura_DeclarePrivUserSymbol(LeftClick);
Gura_DeclarePrivUserSymbol(Render);
Gura_DeclarePrivUserSymbol(RightClick);
Gura_DeclarePrivUserSymbol(StartDrag);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataViewCustomRenderer: public wxDataViewCustomRenderer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DataViewCustomRenderer *_pObj;
public:
	inline wx_DataViewCustomRenderer(const wxString& varianttype, wxDataViewCellMode mode) : wxDataViewCustomRenderer(varianttype, mode), _sig(NULL), _pObj(NULL) {}
	virtual bool Activate(wxRect cell, wxDataViewListModel* model, unsigned int col, unsigned int row);
	virtual wxDC* GetDC();
	virtual wxSize GetSize();
	virtual bool LeftClick(wxPoint cursor, wxRect cell, wxDataViewListModel* model, unsigned int col, unsigned int row);
	virtual bool Render(wxRect cell, wxDC* dc, int state);
	virtual bool RightClick(wxPoint cursor, wxRect cell, wxDataViewListModel* model, unsigned int col, unsigned int row);
	virtual bool StartDrag(wxPoint cursor, wxRect cell, wxDataViewListModel* model, unsigned int col, unsigned int row);
	~wx_DataViewCustomRenderer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DataViewCustomRenderer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataViewCustomRenderer::~wx_DataViewCustomRenderer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DataViewCustomRenderer::GuraObjectDeleted()
{
	_pObj = NULL;
}

bool wx_DataViewCustomRenderer::Activate(wxRect cell, wxDataViewListModel* model, unsigned int col, unsigned int row)
{
	return false;
}

wxDC* wx_DataViewCustomRenderer::GetDC()
{
	return NULL;
}

wxSize wx_DataViewCustomRenderer::GetSize()
{
	return wxSize();
}

bool wx_DataViewCustomRenderer::LeftClick(wxPoint cursor, wxRect cell, wxDataViewListModel* model, unsigned int col, unsigned int row)
{
	return false;
}

bool wx_DataViewCustomRenderer::Render(wxRect cell, wxDC* dc, int state)
{
	return false;
}

bool wx_DataViewCustomRenderer::RightClick(wxPoint cursor, wxRect cell, wxDataViewListModel* model, unsigned int col, unsigned int row)
{
	return false;
}

bool wx_DataViewCustomRenderer::StartDrag(wxPoint cursor, wxRect cell, wxDataViewListModel* model, unsigned int col, unsigned int row)
{
	return false;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewCustomRenderer
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataViewCustomRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DataViewCustomRenderer));
	DeclareArg(env, "varianttype", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataViewCustomRenderer)
{
	wxString varianttype = wxT("string");
	if (args.IsValid(0)) varianttype = wxString::FromUTF8(args.GetString(0));
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(1)) mode = static_cast<wxDataViewCellMode>(args.GetInt(1));
	wx_DataViewCustomRenderer *pEntity = new wx_DataViewCustomRenderer(varianttype, mode);
	Object_wx_DataViewCustomRenderer *pObj = Object_wx_DataViewCustomRenderer::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DataViewCustomRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, Activate)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "cell", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "model", VTYPE_wx_DataViewListModel, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, Activate)
{
	Object_wx_DataViewCustomRenderer *pSelf = Object_wx_DataViewCustomRenderer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRect *cell = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxDataViewListModel *model = Object_wx_DataViewListModel::GetObject(args, 1)->GetEntity();
	unsigned col = args.GetInt(2);
	unsigned row = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->Activate(*cell, model, col, row);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, GetDC)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, GetDC)
{
	Object_wx_DataViewCustomRenderer *pSelf = Object_wx_DataViewCustomRenderer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC *rtn = (wxDC *)pSelf->GetEntity()->GetDC();
	return ReturnValue(env, sig, args, Value(new Object_wx_DC(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, GetSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, GetSize)
{
	Object_wx_DataViewCustomRenderer *pSelf = Object_wx_DataViewCustomRenderer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pSelf->GetEntity()->GetSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, LeftClick)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "cursor", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "cell", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "model", VTYPE_wx_DataViewListModel, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, LeftClick)
{
	Object_wx_DataViewCustomRenderer *pSelf = Object_wx_DataViewCustomRenderer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPoint *cursor = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxRect *cell = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	wxDataViewListModel *model = Object_wx_DataViewListModel::GetObject(args, 2)->GetEntity();
	unsigned col = args.GetInt(3);
	unsigned row = args.GetInt(4);
	bool rtn = pSelf->GetEntity()->LeftClick(*cursor, *cell, model, col, row);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, Render)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "cell", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, Render)
{
	Object_wx_DataViewCustomRenderer *pSelf = Object_wx_DataViewCustomRenderer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRect *cell = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxDC *dc = Object_wx_DC::GetObject(args, 1)->GetEntity();
	int state = args.GetInt(2);
	bool rtn = pSelf->GetEntity()->Render(*cell, dc, state);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, RightClick)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "cursor", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "cell", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "model", VTYPE_wx_DataViewListModel, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, RightClick)
{
	Object_wx_DataViewCustomRenderer *pSelf = Object_wx_DataViewCustomRenderer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPoint *cursor = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxRect *cell = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	wxDataViewListModel *model = Object_wx_DataViewListModel::GetObject(args, 2)->GetEntity();
	unsigned col = args.GetInt(3);
	unsigned row = args.GetInt(4);
	bool rtn = pSelf->GetEntity()->RightClick(*cursor, *cell, model, col, row);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, StartDrag)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "cursor", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "cell", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "model", VTYPE_wx_DataViewListModel, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, StartDrag)
{
	Object_wx_DataViewCustomRenderer *pSelf = Object_wx_DataViewCustomRenderer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPoint *cursor = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxRect *cell = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	wxDataViewListModel *model = Object_wx_DataViewListModel::GetObject(args, 2)->GetEntity();
	unsigned col = args.GetInt(3);
	unsigned row = args.GetInt(4);
	bool rtn = pSelf->GetEntity()->StartDrag(*cursor, *cell, model, col, row);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDataViewCustomRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewCustomRenderer::~Object_wx_DataViewCustomRenderer()
{
}

Object *Object_wx_DataViewCustomRenderer::Clone() const
{
	return NULL;
}

String Object_wx_DataViewCustomRenderer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DataViewCustomRenderer:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DataViewCustomRenderer::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(Activate);
	Gura_RealizeUserSymbol(GetDC);
	Gura_RealizeUserSymbol(GetSize);
	Gura_RealizeUserSymbol(LeftClick);
	Gura_RealizeUserSymbol(Render);
	Gura_RealizeUserSymbol(RightClick);
	Gura_RealizeUserSymbol(StartDrag);
	Gura_AssignFunction(DataViewCustomRenderer);
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewCustomRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewCustomRenderer)
{
	Gura_AssignMethod(wx_DataViewCustomRenderer, Activate);
	Gura_AssignMethod(wx_DataViewCustomRenderer, GetDC);
	Gura_AssignMethod(wx_DataViewCustomRenderer, GetSize);
	Gura_AssignMethod(wx_DataViewCustomRenderer, LeftClick);
	Gura_AssignMethod(wx_DataViewCustomRenderer, Render);
	Gura_AssignMethod(wx_DataViewCustomRenderer, RightClick);
	Gura_AssignMethod(wx_DataViewCustomRenderer, StartDrag);
}

Gura_ImplementDescendantCreator(wx_DataViewCustomRenderer)
{
	return new Object_wx_DataViewCustomRenderer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
