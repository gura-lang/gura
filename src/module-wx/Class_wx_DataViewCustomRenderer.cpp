//----------------------------------------------------------------------------
// wxDataViewCustomRenderer
// extracted from dataviewrenderer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(GetMode);
Gura_DeclarePrivUserSymbol(GetOwner);
Gura_DeclarePrivUserSymbol(GetValue);
Gura_DeclarePrivUserSymbol(GetVariantType);
Gura_DeclarePrivUserSymbol(SetOwner);
Gura_DeclarePrivUserSymbol(SetValue);
Gura_DeclarePrivUserSymbol(Validate);
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
	//Gura::Signal *_pSig;
	Object_wx_DataViewCustomRenderer *_pObj;
public:
	inline wx_DataViewCustomRenderer(const wxString& varianttype, wxDataViewCellMode mode) : wxDataViewCustomRenderer(varianttype, mode), _pObj(nullptr) {}
	// wxDataViewRenderer
	virtual wxDataViewCellMode GetMode();
	virtual wxDataViewColumn* GetOwner();
	virtual bool GetValue(wxVariant& value);
	virtual wxString GetVariantType();
	virtual void SetOwner(wxDataViewColumn* owner);
	virtual bool SetValue(const wxVariant& value);
	virtual bool Validate(wxVariant& value);
	// wxDataViewCustomRenderer
	virtual bool Activate(wxRect cell, wxDataViewListModel* model, unsigned int col, unsigned int row);
	virtual wxDC* GetDC();
	virtual wxSize GetSize();
	virtual bool LeftClick(wxPoint cursor, wxRect cell, wxDataViewListModel* model, unsigned int col, unsigned int row);
	virtual bool Render(wxRect cell, wxDC* dc, int state);
	virtual bool RightClick(wxPoint cursor, wxRect cell, wxDataViewListModel* model, unsigned int col, unsigned int row);
	virtual bool StartDrag(wxPoint cursor, wxRect cell, wxDataViewListModel* model, unsigned int col, unsigned int row);
	~wx_DataViewCustomRenderer();
	inline void AssocWithGura(Object_wx_DataViewCustomRenderer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataViewCustomRenderer::~wx_DataViewCustomRenderer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DataViewCustomRenderer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

wxDataViewCellMode wx_DataViewCustomRenderer::GetMode()
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetMode);
	if (pFunc == nullptr) return wxDataViewCustomRenderer::GetMode();
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, ValueList::Empty);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return wxDATAVIEW_CELL_INERT;
	return static_cast<wxDataViewCellMode>(rtn.GetInt());
}

wxDataViewColumn* wx_DataViewCustomRenderer::GetOwner()
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetOwner);
	if (pFunc == nullptr) return wxDataViewCustomRenderer::GetOwner();
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, ValueList::Empty);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_wx_DataViewColumn)) return nullptr;
	return Object_wx_DataViewColumn::GetObject(rtn)->GetEntity();
}

bool wx_DataViewCustomRenderer::GetValue(wxVariant& value)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetValue);
	if (pFunc == nullptr) return wxDataViewCustomRenderer::GetValue(value);
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, ValueList::Empty);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_wx_Variant, true)) return false;
	if (rtn.IsInvalid()) return false;
	value = *Object_wx_Variant::GetObject(rtn)->GetEntity();
	return true;
}

wxString wx_DataViewCustomRenderer::GetVariantType()
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetVariantType);
	if (pFunc == nullptr) return wxDataViewCustomRenderer::GetVariantType();
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, ValueList::Empty);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_string)) return wxEmptyString;
	return wxString::FromUTF8(rtn.GetString());
}

void wx_DataViewCustomRenderer::SetOwner(wxDataViewColumn* owner)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, SetOwner);
	if (pFunc == nullptr) return wxDataViewCustomRenderer::SetOwner(owner);
	ValueList valListArg;
	valListArg.reserve(1);
	valListArg.push_back(Value(new Object_wx_DataViewColumn(owner, nullptr, OwnerFalse)));
	_pObj->EvalMethod(*_pObj, pFunc, valListArg);
	CheckMethodResult(_pObj->GetSignal());
}

bool wx_DataViewCustomRenderer::SetValue(const wxVariant& value)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, SetValue);
	if (pFunc == nullptr) return wxDataViewCustomRenderer::SetValue(value);
	ValueList valListArg;
	valListArg.reserve(1);
	valListArg.push_back(Value(new Object_wx_Variant(new wxVariant(value), nullptr, OwnerTrue)));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valListArg);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

bool wx_DataViewCustomRenderer::Validate(wxVariant& value)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, Validate);
	if (pFunc == nullptr) return wxDataViewCustomRenderer::Validate(value);
	ValueList valListArg;
	valListArg.reserve(1);
	valListArg.push_back(Value(new Object_wx_Variant(new wxVariant(value), nullptr, OwnerTrue)));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valListArg);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

bool wx_DataViewCustomRenderer::Activate(wxRect cell, wxDataViewListModel* model, unsigned int col, unsigned int row)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, Activate);
	if (pFunc == nullptr) return wxDataViewCustomRenderer::Activate(cell, model, col, row);
	ValueList valListArg;
	valListArg.reserve(4);
	valListArg.push_back(Value(new Object_wx_Rect(new wxRect(cell), nullptr, OwnerTrue)));
	valListArg.push_back(Value(new Object_wx_DataViewListModel(model, nullptr, OwnerFalse)));
	valListArg.push_back(Value(col));
	valListArg.push_back(Value(row));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valListArg);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

wxDC* wx_DataViewCustomRenderer::GetDC()
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetDC);
	if (pFunc == nullptr) return wxDataViewCustomRenderer::GetDC();
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, ValueList::Empty);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_wx_DC)) return nullptr;
	return Object_wx_DC::GetObject(rtn)->GetEntity();
}

// pure virtual function
wxSize wx_DataViewCustomRenderer::GetSize()
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetSize);
	if (pFunc == nullptr) {
		_pObj->GetSignal().SetError(ERR_NotImplementedError, "wx.DataViewCustomRenderer#GetSize method is missing");
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
		return wxSize();
	}
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, ValueList::Empty);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_wx_Size)) return wxSize();
	return *Object_wx_Size::GetObject(rtn)->GetEntity();
}

bool wx_DataViewCustomRenderer::LeftClick(wxPoint cursor, wxRect cell, wxDataViewListModel* model, unsigned int col, unsigned int row)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, LeftClick);
	if (pFunc == nullptr) return wxDataViewCustomRenderer::LeftClick(cursor, cell, model, col, row);
	ValueList valListArg;
	valListArg.reserve(5);
	valListArg.push_back(Value(new Object_wx_Point(new wxPoint(cursor), nullptr, OwnerTrue)));
	valListArg.push_back(Value(new Object_wx_Rect(new wxRect(cell), nullptr, OwnerTrue)));
	valListArg.push_back(Value(new Object_wx_DataViewListModel(model, nullptr, OwnerFalse)));
	valListArg.push_back(Value(col));
	valListArg.push_back(Value(row));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valListArg);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

// pure virtual function
bool wx_DataViewCustomRenderer::Render(wxRect cell, wxDC* dc, int state)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, Render);
	if (pFunc == nullptr) {
		_pObj->GetSignal().SetError(ERR_NotImplementedError, "wx.DataViewCustomRenderer#Render method is missing");
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
		return false;
	}
	ValueList valListArg;
	valListArg.reserve(3);
	valListArg.push_back(Value(new Object_wx_Rect(new wxRect(cell), nullptr, OwnerTrue)));
	valListArg.push_back(Value(new Object_wx_DC(dc, nullptr, OwnerFalse)));
	valListArg.push_back(Value(state));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valListArg);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

bool wx_DataViewCustomRenderer::RightClick(wxPoint cursor, wxRect cell, wxDataViewListModel* model, unsigned int col, unsigned int row)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, RightClick);
	if (pFunc == nullptr) return wxDataViewCustomRenderer::RightClick(cursor, cell, model, col, row);
	ValueList valListArg;
	valListArg.reserve(5);
	valListArg.push_back(Value(new Object_wx_Point(new wxPoint(cursor), nullptr, OwnerTrue)));
	valListArg.push_back(Value(new Object_wx_Rect(new wxRect(cell), nullptr, OwnerTrue)));
	valListArg.push_back(Value(new Object_wx_DataViewListModel(model, nullptr, OwnerFalse)));
	valListArg.push_back(Value(col));
	valListArg.push_back(Value(row));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valListArg);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

bool wx_DataViewCustomRenderer::StartDrag(wxPoint cursor, wxRect cell, wxDataViewListModel* model, unsigned int col, unsigned int row)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, StartDrag);
	if (pFunc == nullptr) return wxDataViewCustomRenderer::StartDrag(cursor, cell, model, col, row);
	ValueList valListArg;
	valListArg.reserve(5);
	valListArg.push_back(Value(new Object_wx_Point(new wxPoint(cursor), nullptr, OwnerTrue)));
	valListArg.push_back(Value(new Object_wx_Rect(new wxRect(cell), nullptr, OwnerTrue)));
	valListArg.push_back(Value(new Object_wx_DataViewListModel(model, nullptr, OwnerFalse)));
	valListArg.push_back(Value(col));
	valListArg.push_back(Value(row));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valListArg);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewCustomRenderer
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataViewCustomRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DataViewCustomRenderer));
	DeclareArg(env, "varianttype", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataViewCustomRenderer)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString varianttype = wxT("string");
	if (args.IsValid(0)) varianttype = wxString::FromUTF8(args.GetString(0));
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(1)) mode = static_cast<wxDataViewCellMode>(args.GetInt(1));
	wx_DataViewCustomRenderer *pEntity = new wx_DataViewCustomRenderer(varianttype, mode);
	Object_wx_DataViewCustomRenderer *pObj = Object_wx_DataViewCustomRenderer::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataViewCustomRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, Activate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "cell", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "model", VTYPE_wx_DataViewListModel, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, Activate)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *cell = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxDataViewListModel *model = Object_wx_DataViewListModel::GetObject(args, 1)->GetEntity();
	unsigned col = args.GetInt(2);
	unsigned row = args.GetInt(3);
	bool rtn = pThis->GetEntity()->wxDataViewCustomRenderer::Activate(*cell, model, col, row);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, GetDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, GetDC)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *rtn = (wxDC *)pThis->GetEntity()->wxDataViewCustomRenderer::GetDC();
	return ReturnValue(env, args, Value(new Object_wx_DC(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, LeftClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "cursor", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "cell", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "model", VTYPE_wx_DataViewListModel, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, LeftClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *cursor = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxRect *cell = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	wxDataViewListModel *model = Object_wx_DataViewListModel::GetObject(args, 2)->GetEntity();
	unsigned col = args.GetInt(3);
	unsigned row = args.GetInt(4);
	bool rtn = pThis->GetEntity()->wxDataViewCustomRenderer::LeftClick(*cursor, *cell, model, col, row);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, RightClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "cursor", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "cell", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "model", VTYPE_wx_DataViewListModel, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, RightClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *cursor = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxRect *cell = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	wxDataViewListModel *model = Object_wx_DataViewListModel::GetObject(args, 2)->GetEntity();
	unsigned col = args.GetInt(3);
	unsigned row = args.GetInt(4);
	bool rtn = pThis->GetEntity()->wxDataViewCustomRenderer::RightClick(*cursor, *cell, model, col, row);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCustomRenderer, StartDrag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "cursor", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "cell", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "model", VTYPE_wx_DataViewListModel, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCustomRenderer, StartDrag)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCustomRenderer *pThis = Object_wx_DataViewCustomRenderer::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *cursor = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxRect *cell = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	wxDataViewListModel *model = Object_wx_DataViewListModel::GetObject(args, 2)->GetEntity();
	unsigned col = args.GetInt(3);
	unsigned row = args.GetInt(4);
	bool rtn = pThis->GetEntity()->wxDataViewCustomRenderer::StartDrag(*cursor, *cell, model, col, row);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDataViewCustomRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewCustomRenderer::~Object_wx_DataViewCustomRenderer()
{
}

Object *Object_wx_DataViewCustomRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewCustomRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewCustomRenderer:");
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
// Class implementation for wxDataViewCustomRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewCustomRenderer)
{
	Gura_RealizeUserSymbol(GetMode);
	Gura_RealizeUserSymbol(GetOwner);
	Gura_RealizeUserSymbol(GetValue);
	Gura_RealizeUserSymbol(GetVariantType);
	Gura_RealizeUserSymbol(SetOwner);
	Gura_RealizeUserSymbol(SetValue);
	Gura_RealizeUserSymbol(Validate);
	Gura_RealizeUserSymbol(Activate);
	Gura_RealizeUserSymbol(GetDC);
	Gura_RealizeUserSymbol(GetSize);
	Gura_RealizeUserSymbol(LeftClick);
	Gura_RealizeUserSymbol(Render);
	Gura_RealizeUserSymbol(RightClick);
	Gura_RealizeUserSymbol(StartDrag);
	Gura_AssignFunction(DataViewCustomRenderer);
	Gura_AssignMethod(wx_DataViewCustomRenderer, Activate);
	Gura_AssignMethod(wx_DataViewCustomRenderer, GetDC);
	Gura_AssignMethod(wx_DataViewCustomRenderer, LeftClick);
	Gura_AssignMethod(wx_DataViewCustomRenderer, RightClick);
	Gura_AssignMethod(wx_DataViewCustomRenderer, StartDrag);
}

Gura_ImplementDescendantCreator(wx_DataViewCustomRenderer)
{
	return new Object_wx_DataViewCustomRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
