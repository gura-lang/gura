//----------------------------------------------------------------------------
// wxGenericDirCtrl
// extracted from dirctrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GenericDirCtrl: public wxGenericDirCtrl, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GenericDirCtrl *_pObj;
public:
	inline wx_GenericDirCtrl() : wxGenericDirCtrl(), _sig(NULL), _pObj(NULL) {}
	inline wx_GenericDirCtrl(wxWindow* parent, const wxWindowID id, const wxString& dir, const wxPoint& pos, const wxSize& size, long style, const wxString& filter, int defaultFilter, const wxString& name) : wxGenericDirCtrl(parent, id, dir, pos, size, style, filter, defaultFilter, name), _sig(NULL), _pObj(NULL) {}
	~wx_GenericDirCtrl();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GenericDirCtrl *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GenericDirCtrl::~wx_GenericDirCtrl()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_GenericDirCtrl::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGenericDirCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(GenericDirCtrlEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GenericDirCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GenericDirCtrlEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GenericDirCtrl *pEntity = new wx_GenericDirCtrl();
	Object_wx_GenericDirCtrl *pObj = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GenericDirCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(GenericDirCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_GenericDirCtrl));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "filter", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "defaultFilter", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GenericDirCtrl)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = -1;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxString dir = wxDirDialogDefaultFolderStr;
	if (args.IsValid(2)) dir = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxDIRCTRL_3D_INTERNAL|wxSUNKEN_BORDER;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString filter = wxEmptyString;
	if (args.IsValid(6)) filter = wxString::FromUTF8(args.GetString(6));
	int defaultFilter = 0;
	if (args.IsValid(7)) defaultFilter = args.GetInt(7);
	wxString name = wxTreeCtrlNameStr;
	if (args.IsValid(8)) name = wxString::FromUTF8(args.GetString(8));
	wx_GenericDirCtrl *pEntity = new wx_GenericDirCtrl(parent, id, dir, *pos, *size, style, filter, defaultFilter, name);
	Object_wx_GenericDirCtrl *pObj = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GenericDirCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_GenericDirCtrl, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "filter", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "defaultFilter", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GenericDirCtrl, Create)
{
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = -1;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxString dir = wxDirDialogDefaultFolderStr;
	if (args.IsValid(2)) dir = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxDIRCTRL_3D_INTERNAL|wxSUNKEN_BORDER;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString filter = wxEmptyString;
	if (args.IsValid(6)) filter = wxString::FromUTF8(args.GetString(6));
	int defaultFilter = 0;
	if (args.IsValid(7)) defaultFilter = args.GetInt(7);
	wxString name = wxTreeCtrlNameStr;
	if (args.IsValid(8)) name = wxString::FromUTF8(args.GetString(8));
	bool rtn = pThis->GetEntity()->Create(parent, id, dir, *pos, *size, style, filter, defaultFilter, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GenericDirCtrl, Init)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericDirCtrl, Init)
{
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Init();
	return Value::Null;
}

Gura_DeclareMethod(wx_GenericDirCtrl, CollapseTree)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericDirCtrl, CollapseTree)
{
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->CollapseTree();
	return Value::Null;
}

Gura_DeclareMethod(wx_GenericDirCtrl, ExpandPath)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GenericDirCtrl, ExpandPath)
{
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->ExpandPath(path);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GenericDirCtrl, CollapsePath)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GenericDirCtrl, CollapsePath)
{
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->CollapsePath(path);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GenericDirCtrl, GetDefaultPath)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GenericDirCtrl, GetDefaultPath)
{
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetDefaultPath();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_GenericDirCtrl, GetPath)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GenericDirCtrl, GetPath)
{
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetPath();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_GenericDirCtrl, GetFilePath)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GenericDirCtrl, GetFilePath)
{
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetFilePath();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_GenericDirCtrl, GetFilter)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GenericDirCtrl, GetFilter)
{
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetFilter();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_GenericDirCtrl, GetFilterIndex)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GenericDirCtrl, GetFilterIndex)
{
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetFilterIndex();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GenericDirCtrl, GetFilterListCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GenericDirCtrl, GetFilterListCtrl)
{
#if 0
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDirFilterListCtrl *rtn = (wxDirFilterListCtrl *)pThis->GetEntity()->GetFilterListCtrl();
	return ReturnValue(env, sig, args, Value(new Object_wx_DirFilterListCtrl(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_GenericDirCtrl, GetRootId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GenericDirCtrl, GetRootId)
{
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId rtn = pThis->GetEntity()->GetRootId();
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_GenericDirCtrl, GetTreeCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GenericDirCtrl, GetTreeCtrl)
{
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeCtrl *rtn = (wxTreeCtrl *)pThis->GetEntity()->GetTreeCtrl();
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeCtrl(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_GenericDirCtrl, ReCreateTree)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericDirCtrl, ReCreateTree)
{
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->ReCreateTree();
	return Value::Null;
}

Gura_DeclareMethod(wx_GenericDirCtrl, SetDefaultPath)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericDirCtrl, SetDefaultPath)
{
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetDefaultPath(path);
	return Value::Null;
}

Gura_DeclareMethod(wx_GenericDirCtrl, SetFilter)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filter", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericDirCtrl, SetFilter)
{
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filter = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetFilter(filter);
	return Value::Null;
}

Gura_DeclareMethod(wx_GenericDirCtrl, SetFilterIndex)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericDirCtrl, SetFilterIndex)
{
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int n = args.GetInt(0);
	pThis->GetEntity()->SetFilterIndex(n);
	return Value::Null;
}

Gura_DeclareMethod(wx_GenericDirCtrl, SetPath)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericDirCtrl, SetPath)
{
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetPath(path);
	return Value::Null;
}

Gura_DeclareMethod(wx_GenericDirCtrl, ShowHidden)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericDirCtrl, ShowHidden)
{
	Object_wx_GenericDirCtrl *pThis = Object_wx_GenericDirCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool show = args.GetBoolean(0);
	pThis->GetEntity()->ShowHidden(show);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxGenericDirCtrl
//----------------------------------------------------------------------------
Object_wx_GenericDirCtrl::~Object_wx_GenericDirCtrl()
{
}

Object *Object_wx_GenericDirCtrl::Clone() const
{
	return NULL;
}

String Object_wx_GenericDirCtrl::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GenericDirCtrl:");
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
// Class implementation for wxGenericDirCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GenericDirCtrl)
{
	Gura_AssignFunction(GenericDirCtrlEmpty);
	Gura_AssignFunction(GenericDirCtrl);
	Gura_AssignMethod(wx_GenericDirCtrl, Create);
	Gura_AssignMethod(wx_GenericDirCtrl, Init);
	Gura_AssignMethod(wx_GenericDirCtrl, CollapseTree);
	Gura_AssignMethod(wx_GenericDirCtrl, ExpandPath);
	Gura_AssignMethod(wx_GenericDirCtrl, CollapsePath);
	Gura_AssignMethod(wx_GenericDirCtrl, GetDefaultPath);
	Gura_AssignMethod(wx_GenericDirCtrl, GetPath);
	Gura_AssignMethod(wx_GenericDirCtrl, GetFilePath);
	Gura_AssignMethod(wx_GenericDirCtrl, GetFilter);
	Gura_AssignMethod(wx_GenericDirCtrl, GetFilterIndex);
	Gura_AssignMethod(wx_GenericDirCtrl, GetFilterListCtrl);
	Gura_AssignMethod(wx_GenericDirCtrl, GetRootId);
	Gura_AssignMethod(wx_GenericDirCtrl, GetTreeCtrl);
	Gura_AssignMethod(wx_GenericDirCtrl, ReCreateTree);
	Gura_AssignMethod(wx_GenericDirCtrl, SetDefaultPath);
	Gura_AssignMethod(wx_GenericDirCtrl, SetFilter);
	Gura_AssignMethod(wx_GenericDirCtrl, SetFilterIndex);
	Gura_AssignMethod(wx_GenericDirCtrl, SetPath);
	Gura_AssignMethod(wx_GenericDirCtrl, ShowHidden);
}

Gura_ImplementDescendantCreator(wx_GenericDirCtrl)
{
	return new Object_wx_GenericDirCtrl((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
