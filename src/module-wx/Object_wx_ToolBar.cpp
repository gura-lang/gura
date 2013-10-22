//----------------------------------------------------------------------------
// wxToolBar
// extracted from toolbar.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ToolBar: public wxToolBar, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ToolBar *_pObj;
public:
	inline wx_ToolBar() : wxToolBar(), _sig(NULL), _pObj(NULL) {}
	inline wx_ToolBar(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxToolBar(parent, id, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	~wx_ToolBar();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ToolBar *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ToolBar::~wx_ToolBar()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ToolBar::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxToolBar
//----------------------------------------------------------------------------
Gura_DeclareFunction(ToolBarEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ToolBar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ToolBarEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ToolBar *pEntity = new wx_ToolBar();
	Object_wx_ToolBar *pObj = Object_wx_ToolBar::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ToolBar(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(ToolBar)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ToolBar));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ToolBar)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxTB_HORIZONTAL | wxNO_BORDER;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxPanelNameStr;
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	wx_ToolBar *pEntity = new wx_ToolBar(parent, id, *pos, *size, style, name);
	Object_wx_ToolBar *pObj = Object_wx_ToolBar::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ToolBar(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_ToolBar, AddControl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "control", VTYPE_wx_Control, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, AddControl)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxControl *control = Object_wx_Control::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->AddControl(control);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ToolBar, AddSeparator)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, AddSeparator)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->AddSeparator();
	return Value::Null;
}

Gura_DeclareMethod(wx_ToolBar, AddTool_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bitmap1", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "shortHelpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "kind", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, AddTool_1)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int toolId = args.GetInt(0);
	wxString label = wxString::FromUTF8(args.GetString(1));
	wxBitmap *bitmap1 = Object_wx_Bitmap::GetObject(args, 2)->GetEntity();
	wxString shortHelpString = wxT("");
	if (args.IsValid(3)) shortHelpString = wxString::FromUTF8(args.GetString(3));
	wxItemKind kind = wxITEM_NORMAL;
	if (args.IsValid(4)) kind = static_cast<wxItemKind>(args.GetInt(4));
	wxToolBarToolBase *rtn = (wxToolBarToolBase *)pThis->GetEntity()->AddTool(toolId, label, *bitmap1, shortHelpString, kind);
	return ReturnValue(env, sig, args, Value(new Object_wx_ToolBarToolBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ToolBar, AddTool)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bitmap1", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "bitmap2", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareArg(env, "kind", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "shortHelpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "longHelpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "clientData", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, AddTool)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int toolId = args.GetInt(0);
	wxString label = wxString::FromUTF8(args.GetString(1));
	wxBitmap *bitmap1 = Object_wx_Bitmap::GetObject(args, 2)->GetEntity();
	wxBitmap *bitmap2 = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(3)) bitmap2 = Object_wx_Bitmap::GetObject(args, 3)->GetEntity();
	wxItemKind kind = wxITEM_NORMAL;
	if (args.IsValid(4)) kind = static_cast<wxItemKind>(args.GetInt(4));
	wxString shortHelpString = wxT("");
	if (args.IsValid(5)) shortHelpString = wxString::FromUTF8(args.GetString(5));
	wxString longHelpString = wxT("");
	if (args.IsValid(6)) longHelpString = wxString::FromUTF8(args.GetString(6));
	wxObject *clientData = NULL;
	if (args.IsValid(7)) clientData = new ObjectWithValue(args.GetValue(7));
	wxToolBarToolBase *rtn = (wxToolBarToolBase *)pThis->GetEntity()->AddTool(toolId, label, *bitmap1, *bitmap2, kind, shortHelpString, longHelpString, clientData);
	return ReturnValue(env, sig, args, Value(new Object_wx_ToolBarToolBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ToolBar, AddTool_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "tool", VTYPE_wx_ToolBarToolBase, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, AddTool_2)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxToolBarToolBase *tool = Object_wx_ToolBarToolBase::GetObject(args, 0)->GetEntity();
	wxToolBarToolBase *rtn = (wxToolBarToolBase *)pThis->GetEntity()->AddTool(tool);
	return ReturnValue(env, sig, args, Value(new Object_wx_ToolBarToolBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ToolBar, AddCheckTool)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bitmap1", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "bitmap2", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "shortHelpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "longHelpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "clientData", VTYPE_wx_Object, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, AddCheckTool)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int toolId = args.GetInt(0);
	wxString label = wxString::FromUTF8(args.GetString(1));
	wxBitmap *bitmap1 = Object_wx_Bitmap::GetObject(args, 2)->GetEntity();
	wxBitmap *bitmap2 = Object_wx_Bitmap::GetObject(args, 3)->GetEntity();
	wxString shortHelpString = wxT("");
	if (args.IsValid(4)) shortHelpString = wxString::FromUTF8(args.GetString(4));
	wxString longHelpString = wxT("");
	if (args.IsValid(5)) longHelpString = wxString::FromUTF8(args.GetString(5));
	wxObject *clientData = NULL;
	if (args.IsValid(6)) clientData = new ObjectWithValue(args.GetValue(6));
	wxToolBarToolBase *rtn = (wxToolBarToolBase *)pThis->GetEntity()->AddCheckTool(toolId, label, *bitmap1, *bitmap2, shortHelpString, longHelpString, clientData);
	return ReturnValue(env, sig, args, Value(new Object_wx_ToolBarToolBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ToolBar, AddRadioTool)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bitmap1", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "bitmap2", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "shortHelpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "longHelpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "clientData", VTYPE_wx_Object, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, AddRadioTool)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int toolId = args.GetInt(0);
	wxString label = wxString::FromUTF8(args.GetString(1));
	wxBitmap *bitmap1 = Object_wx_Bitmap::GetObject(args, 2)->GetEntity();
	wxBitmap *bitmap2 = Object_wx_Bitmap::GetObject(args, 3)->GetEntity();
	wxString shortHelpString = wxT("");
	if (args.IsValid(4)) shortHelpString = wxString::FromUTF8(args.GetString(4));
	wxString longHelpString = wxT("");
	if (args.IsValid(5)) longHelpString = wxString::FromUTF8(args.GetString(5));
	wxObject *clientData = NULL;
	if (args.IsValid(6)) clientData = new ObjectWithValue(args.GetValue(6));
	wxToolBarToolBase *rtn = (wxToolBarToolBase *)pThis->GetEntity()->AddRadioTool(toolId, label, *bitmap1, *bitmap2, shortHelpString, longHelpString, clientData);
	return ReturnValue(env, sig, args, Value(new Object_wx_ToolBarToolBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ToolBar, ClearTools)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, ClearTools)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->ClearTools();
	return Value::Null;
}

Gura_DeclareMethod(wx_ToolBar, DeleteTool)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, DeleteTool)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int toolId = args.GetInt(0);
	bool rtn = pThis->GetEntity()->DeleteTool(toolId);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ToolBar, DeleteToolByPos)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, DeleteToolByPos)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t pos = args.GetSizeT(0);
	bool rtn = pThis->GetEntity()->DeleteToolByPos(pos);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ToolBar, EnableTool)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, EnableTool)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int toolId = args.GetInt(0);
	bool enable = args.GetBoolean(1);
	pThis->GetEntity()->EnableTool(toolId, enable);
	return Value::Null;
}

Gura_DeclareMethod(wx_ToolBar, FindById)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, FindById)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxToolBarToolBase *rtn = (wxToolBarToolBase *)pThis->GetEntity()->FindById(id);
	return ReturnValue(env, sig, args, Value(new Object_wx_ToolBarToolBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ToolBar, FindControl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, FindControl)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxControl *rtn = (wxControl *)pThis->GetEntity()->FindControl(id);
	return ReturnValue(env, sig, args, Value(new Object_wx_Control(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ToolBar, FindToolForPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, FindToolForPosition)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxToolBarToolBase *rtn = (wxToolBarToolBase *)pThis->GetEntity()->FindToolForPosition(x, y);
	return ReturnValue(env, sig, args, Value(new Object_wx_ToolBarToolBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ToolBar, GetToolsCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, GetToolsCount)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetToolsCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ToolBar, GetToolSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, GetToolSize)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetToolSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ToolBar, GetToolBitmapSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, GetToolBitmapSize)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetToolBitmapSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ToolBar, GetMargins)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, GetMargins)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetMargins();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ToolBar, GetToolClientData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, GetToolClientData)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int toolId = args.GetInt(0);
	ObjectWithValue *rtn = wxDynamicCast(
				pThis->GetEntity()->GetToolClientData(toolId), ObjectWithValue);
	Value result;
	if (rtn != NULL) result = rtn->GetValue();
	return ReturnValue(env, sig, args, result);
}

Gura_DeclareMethod(wx_ToolBar, GetToolEnabled)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, GetToolEnabled)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int toolId = args.GetInt(0);
	bool rtn = pThis->GetEntity()->GetToolEnabled(toolId);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ToolBar, GetToolLongHelp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, GetToolLongHelp)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int toolId = args.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetToolLongHelp(toolId);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ToolBar, GetToolPacking)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, GetToolPacking)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetToolPacking();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ToolBar, GetToolPos)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, GetToolPos)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int toolId = args.GetInt(0);
	int rtn = pThis->GetEntity()->GetToolPos(toolId);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ToolBar, GetToolSeparation)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, GetToolSeparation)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetToolSeparation();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ToolBar, GetToolShortHelp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, GetToolShortHelp)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int toolId = args.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetToolShortHelp(toolId);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ToolBar, GetToolState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, GetToolState)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int toolId = args.GetInt(0);
	bool rtn = pThis->GetEntity()->GetToolState(toolId);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ToolBar, InsertControl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "control", VTYPE_wx_Control, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, InsertControl)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t pos = args.GetSizeT(0);
	wxControl *control = Object_wx_Control::GetObject(args, 1)->GetEntity();
	wxToolBarToolBase *rtn = (wxToolBarToolBase *)pThis->GetEntity()->InsertControl(pos, control);
	return ReturnValue(env, sig, args, Value(new Object_wx_ToolBarToolBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ToolBar, InsertSeparator)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, InsertSeparator)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t pos = args.GetSizeT(0);
	wxToolBarToolBase *rtn = (wxToolBarToolBase *)pThis->GetEntity()->InsertSeparator(pos);
	return ReturnValue(env, sig, args, Value(new Object_wx_ToolBarToolBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ToolBar, InsertTool)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "bitmap1", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "bitmap2", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareArg(env, "isToggle", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "clientData", VTYPE_wx_Object, OCCUR_ZeroOrOnce);
	DeclareArg(env, "shortHelpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "longHelpString", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, InsertTool)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t pos = args.GetSizeT(0);
	int toolId = args.GetInt(1);
	wxBitmap *bitmap1 = Object_wx_Bitmap::GetObject(args, 2)->GetEntity();
	wxBitmap *bitmap2 = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(3)) bitmap2 = Object_wx_Bitmap::GetObject(args, 3)->GetEntity();
	bool isToggle = false;
	if (args.IsValid(4)) isToggle = args.GetBoolean(4);
	wxObject *clientData = NULL;
	if (args.IsValid(5)) clientData = new ObjectWithValue(args.GetValue(5));
	wxString shortHelpString = wxT("");
	if (args.IsValid(6)) shortHelpString = wxString::FromUTF8(args.GetString(6));
	wxString longHelpString = wxT("");
	if (args.IsValid(7)) longHelpString = wxString::FromUTF8(args.GetString(7));
	wxToolBarToolBase *rtn = (wxToolBarToolBase *)pThis->GetEntity()->InsertTool(pos, toolId, *bitmap1, *bitmap2, isToggle, clientData, shortHelpString, longHelpString);
	return ReturnValue(env, sig, args, Value(new Object_wx_ToolBarToolBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ToolBar, InsertTool_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "tool", VTYPE_wx_ToolBarToolBase, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, InsertTool_1)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t pos = args.GetSizeT(0);
	wxToolBarToolBase *tool = Object_wx_ToolBarToolBase::GetObject(args, 1)->GetEntity();
	wxToolBarToolBase *rtn = (wxToolBarToolBase *)pThis->GetEntity()->InsertTool(pos, tool);
	return ReturnValue(env, sig, args, Value(new Object_wx_ToolBarToolBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ToolBar, OnLeftClick)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "toggleDown", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, OnLeftClick)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int toolId = args.GetInt(0);
	bool toggleDown = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->OnLeftClick(toolId, toggleDown);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ToolBar, OnMouseEnter)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, OnMouseEnter)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int toolId = args.GetInt(0);
	pThis->GetEntity()->OnMouseEnter(toolId);
	return Value::Null;
}

Gura_DeclareMethod(wx_ToolBar, OnRightClick)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, OnRightClick)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int toolId = args.GetInt(0);
	float x = args.GetFloat(1);
	float y = args.GetFloat(2);
	pThis->GetEntity()->OnRightClick(toolId, x, y);
	return Value::Null;
}

Gura_DeclareMethod(wx_ToolBar, Realize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, Realize)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Realize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ToolBar, RemoveTool)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolBar, RemoveTool)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxToolBarToolBase *rtn = (wxToolBarToolBase *)pThis->GetEntity()->RemoveTool(id);
	return ReturnValue(env, sig, args, Value(new Object_wx_ToolBarToolBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ToolBar, SetBitmapResource)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "resourceId", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_ToolBar, SetBitmapResource)
{
#if 0
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int resourceId = args.GetInt(0);
	pThis->GetEntity()->SetBitmapResource(resourceId);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ToolBar, SetMargins)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetMargins)
{
#if defined(__WXMSW__)
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetMargins(*size);
	return Value::Null;
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_ToolBar, SetMargins_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetMargins_1)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	pThis->GetEntity()->SetMargins(x, y);
	return Value::Null;
}

Gura_DeclareMethod(wx_ToolBar, SetToolBitmapSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetToolBitmapSize)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetToolBitmapSize(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_ToolBar, SetToolClientData)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "clientData", VTYPE_any, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetToolClientData)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxObject *clientData = new ObjectWithValue(args.GetValue(1));
	pThis->GetEntity()->SetToolClientData(id, clientData);
	return Value::Null;
}

Gura_DeclareMethod(wx_ToolBar, SetToolDisabledBitmap)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetToolDisabledBitmap)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetToolDisabledBitmap(id, *bitmap);
	return Value::Null;
}

Gura_DeclareMethod(wx_ToolBar, SetToolLongHelp)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetToolLongHelp)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int toolId = args.GetInt(0);
	wxString helpString = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetToolLongHelp(toolId, helpString);
	return Value::Null;
}

Gura_DeclareMethod(wx_ToolBar, SetToolPacking)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "packing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetToolPacking)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int packing = args.GetInt(0);
	pThis->GetEntity()->SetToolPacking(packing);
	return Value::Null;
}

Gura_DeclareMethod(wx_ToolBar, SetToolShortHelp)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "helpString", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetToolShortHelp)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int toolId = args.GetInt(0);
	wxString helpString = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetToolShortHelp(toolId, helpString);
	return Value::Null;
}

Gura_DeclareMethod(wx_ToolBar, SetToolNormalBitmap)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetToolNormalBitmap)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetToolNormalBitmap(id, *bitmap);
	return Value::Null;
}

Gura_DeclareMethod(wx_ToolBar, SetToolSeparation)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "separation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetToolSeparation)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int separation = args.GetInt(0);
	pThis->GetEntity()->SetToolSeparation(separation);
	return Value::Null;
}

Gura_DeclareMethod(wx_ToolBar, ToggleTool)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "toggle", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, ToggleTool)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int toolId = args.GetInt(0);
	bool toggle = args.GetBoolean(1);
	pThis->GetEntity()->ToggleTool(toolId, toggle);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxToolBar
//----------------------------------------------------------------------------
Object_wx_ToolBar::~Object_wx_ToolBar()
{
}

Object *Object_wx_ToolBar::Clone() const
{
	return NULL;
}

String Object_wx_ToolBar::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ToolBar:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxToolBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ToolBar)
{
	Gura_AssignFunction(ToolBarEmpty);
	Gura_AssignFunction(ToolBar);
	Gura_AssignMethod(wx_ToolBar, AddControl);
	Gura_AssignMethod(wx_ToolBar, AddSeparator);
	Gura_AssignMethod(wx_ToolBar, AddTool);
	Gura_AssignMethod(wx_ToolBar, AddTool_1);
	Gura_AssignMethod(wx_ToolBar, AddTool_2);
	Gura_AssignMethod(wx_ToolBar, AddCheckTool);
	Gura_AssignMethod(wx_ToolBar, AddRadioTool);
	Gura_AssignMethod(wx_ToolBar, ClearTools);
	Gura_AssignMethod(wx_ToolBar, DeleteTool);
	Gura_AssignMethod(wx_ToolBar, DeleteToolByPos);
	Gura_AssignMethod(wx_ToolBar, EnableTool);
	Gura_AssignMethod(wx_ToolBar, FindById);
	Gura_AssignMethod(wx_ToolBar, FindControl);
	Gura_AssignMethod(wx_ToolBar, FindToolForPosition);
	Gura_AssignMethod(wx_ToolBar, GetToolsCount);
	Gura_AssignMethod(wx_ToolBar, GetToolSize);
	Gura_AssignMethod(wx_ToolBar, GetToolBitmapSize);
	Gura_AssignMethod(wx_ToolBar, GetMargins);
	Gura_AssignMethod(wx_ToolBar, GetToolClientData);
	Gura_AssignMethod(wx_ToolBar, GetToolEnabled);
	Gura_AssignMethod(wx_ToolBar, GetToolLongHelp);
	Gura_AssignMethod(wx_ToolBar, GetToolPacking);
	Gura_AssignMethod(wx_ToolBar, GetToolPos);
	Gura_AssignMethod(wx_ToolBar, GetToolSeparation);
	Gura_AssignMethod(wx_ToolBar, GetToolShortHelp);
	Gura_AssignMethod(wx_ToolBar, GetToolState);
	Gura_AssignMethod(wx_ToolBar, InsertControl);
	Gura_AssignMethod(wx_ToolBar, InsertSeparator);
	Gura_AssignMethod(wx_ToolBar, InsertTool);
	Gura_AssignMethod(wx_ToolBar, InsertTool_1);
	Gura_AssignMethod(wx_ToolBar, OnLeftClick);
	Gura_AssignMethod(wx_ToolBar, OnMouseEnter);
	Gura_AssignMethod(wx_ToolBar, OnRightClick);
	Gura_AssignMethod(wx_ToolBar, Realize);
	Gura_AssignMethod(wx_ToolBar, RemoveTool);
	Gura_AssignMethod(wx_ToolBar, SetBitmapResource);
	Gura_AssignMethod(wx_ToolBar, SetMargins);
	Gura_AssignMethod(wx_ToolBar, SetMargins_1);
	Gura_AssignMethod(wx_ToolBar, SetToolBitmapSize);
	Gura_AssignMethod(wx_ToolBar, SetToolClientData);
	Gura_AssignMethod(wx_ToolBar, SetToolDisabledBitmap);
	Gura_AssignMethod(wx_ToolBar, SetToolLongHelp);
	Gura_AssignMethod(wx_ToolBar, SetToolPacking);
	Gura_AssignMethod(wx_ToolBar, SetToolShortHelp);
	Gura_AssignMethod(wx_ToolBar, SetToolNormalBitmap);
	Gura_AssignMethod(wx_ToolBar, SetToolSeparation);
	Gura_AssignMethod(wx_ToolBar, ToggleTool);
}

Gura_ImplementDescendantCreator(wx_ToolBar)
{
	return new Object_wx_ToolBar((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
