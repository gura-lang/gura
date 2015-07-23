//----------------------------------------------------------------------------
// wxWizard
// extracted from wizard.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(GetPageAreaSizer);
Gura_DeclarePrivUserSymbol(HasNextPage);
Gura_DeclarePrivUserSymbol(HasPrevPage);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Wizard: public wxWizard, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_Wizard *_pObj;
public:
	inline wx_Wizard() : wxWizard(), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_Wizard(wxWindow* parent, int id, const wxString& title, const wxBitmap& bitmap, const wxPoint& pos, long style) : wxWizard(parent, id, title, bitmap, pos, style), _pSig(nullptr), _pObj(nullptr) {}
	//virtual wxSizer* GetPageAreaSizer();
	//virtual bool HasNextPage(wxWizardPage * page);
	//virtual bool HasPrevPage(wxWizardPage * page);
	~wx_Wizard();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Wizard *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Wizard::~wx_Wizard()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Wizard::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxWizard
//----------------------------------------------------------------------------
Gura_DeclareFunction(WizardEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Wizard));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WizardEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Wizard *pEntity = new wx_Wizard();
	Object_wx_Wizard *pObj = Object_wx_Wizard::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Wizard(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(Wizard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Wizard));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Wizard)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : nullptr;
	int id = -1;
	if (args.IsValid(1)) id = args.GetInt(1);
	wxString title = wxEmptyString;
	if (args.IsValid(2)) title = wxString::FromUTF8(args.GetString(2));
	wxBitmap *bitmap = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(3)) bitmap = Object_wx_Bitmap::GetObject(args, 3)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(4)) pos = Object_wx_Point::GetObject(args, 4)->GetEntity();
	long style = wxDEFAULT_DIALOG_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wx_Wizard *pEntity = new wx_Wizard(parent, id, title, *bitmap, *pos, style);
	Object_wx_Wizard *pObj = Object_wx_Wizard::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Wizard(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_Wizard, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Wizard, Create)
{
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : nullptr;
	int id = -1;
	if (args.IsValid(1)) id = args.GetInt(1);
	wxString title = wxEmptyString;
	if (args.IsValid(2)) title = wxString::FromUTF8(args.GetString(2));
	wxBitmap *bitmap = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(3)) bitmap = Object_wx_Bitmap::GetObject(args, 3)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(4)) pos = Object_wx_Point::GetObject(args, 4)->GetEntity();
	long style = wxDEFAULT_DIALOG_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	bool rtn = pThis->GetEntity()->Create(parent, id, title, *bitmap, *pos, style);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Wizard, FitToPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "firstPage", VTYPE_wx_WizardPage, OCCUR_Once);
}

Gura_ImplementMethod(wx_Wizard, FitToPage)
{
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWizardPage *firstPage = Object_wx_WizardPage::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->FitToPage(firstPage);
	return Value::Null;
}

Gura_DeclareMethod(wx_Wizard, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Wizard, GetBitmap)
{
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxBitmap &rtn = pThis->GetEntity()->GetBitmap();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Wizard, GetBitmapBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Wizard, GetBitmapBackgroundColour)
{
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetBitmapBackgroundColour();
	return ReturnValue(env, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Wizard, GetBitmapPlacement)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Wizard, GetBitmapPlacement)
{
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetBitmapPlacement();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Wizard, GetCurrentPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Wizard, GetCurrentPage)
{
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWizardPage *rtn = (wxWizardPage *)pThis->GetEntity()->GetCurrentPage();
	if (rtn == nullptr) return Value::Null;
	return ReturnValue(env, args, Value(new Object_wx_WizardPage(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Wizard, GetMinimumBitmapWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Wizard, GetMinimumBitmapWidth)
{
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMinimumBitmapWidth();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Wizard, GetPageAreaSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Wizard, GetPageAreaSizer)
{
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSizer *rtn = (wxSizer *)pThis->GetEntity()->GetPageAreaSizer();
	return ReturnValue(env, args, Value(new Object_wx_Sizer(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Wizard, GetPageSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Wizard, GetPageSize)
{
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetPageSize();
	return ReturnValue(env, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Wizard, HasNextPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_wx_WizardPage, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Wizard, HasNextPage)
{
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWizardPage *page = Object_wx_WizardPage::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->HasNextPage(page);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Wizard, HasPrevPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_wx_WizardPage, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Wizard, HasPrevPage)
{
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWizardPage *page = Object_wx_WizardPage::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->HasPrevPage(page);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Wizard, RunWizard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "firstPage", VTYPE_wx_WizardPage, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Wizard, RunWizard)
{
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWizardPage *firstPage = Object_wx_WizardPage::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->RunWizard(firstPage);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Wizard, SetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_Wizard, SetBitmap)
{
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBitmap(*bitmap);
	return Value::Null;
}

Gura_DeclareMethod(wx_Wizard, SetBitmapBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Wizard, SetBitmapBackgroundColour)
{
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBitmapBackgroundColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_Wizard, SetBitmapPlacement)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "placement", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Wizard, SetBitmapPlacement)
{
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int placement = args.GetInt(0);
	pThis->GetEntity()->SetBitmapPlacement(placement);
	return Value::Null;
}

Gura_DeclareMethod(wx_Wizard, SetBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Wizard, SetBorder)
{
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int border = args.GetInt(0);
	pThis->GetEntity()->SetBorder(border);
	return Value::Null;
}

Gura_DeclareMethod(wx_Wizard, SetMinimumBitmapWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Wizard, SetMinimumBitmapWidth)
{
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pThis->GetEntity()->SetMinimumBitmapWidth(width);
	return Value::Null;
}

Gura_DeclareMethod(wx_Wizard, SetPageSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sizePage", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Wizard, SetPageSize)
{
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *sizePage = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPageSize(*sizePage);
	return Value::Null;
}

Gura_DeclareMethod(wx_Wizard, ShowPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_wx_WizardPage, OCCUR_Once);
	DeclareArg(env, "goingForward", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Wizard, ShowPage)
{
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWizardPage *page = Object_wx_WizardPage::GetObject(args, 0)->GetEntity();
	bool goingForward = args.IsValid(1)? args.GetBoolean(1) : true;
	bool rtn = pThis->GetEntity()->ShowPage(page, goingForward);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxWizard
//----------------------------------------------------------------------------
Object_wx_Wizard::~Object_wx_Wizard()
{
}

Object *Object_wx_Wizard::Clone() const
{
	return nullptr;
}

String Object_wx_Wizard::ToString(bool exprFlag)
{
	String rtn("<wx.Wizard:");
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
// Class implementation for wxWizard
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Wizard)
{
	Gura_RealizeUserSymbol(GetPageAreaSizer);
	Gura_RealizeUserSymbol(HasNextPage);
	Gura_RealizeUserSymbol(HasPrevPage);
	Gura_AssignFunction(WizardEmpty);
	Gura_AssignFunction(Wizard);
	Gura_AssignMethod(wx_Wizard, Create);
	Gura_AssignMethod(wx_Wizard, FitToPage);
	Gura_AssignMethod(wx_Wizard, GetBitmap);
	Gura_AssignMethod(wx_Wizard, GetBitmapBackgroundColour);
	Gura_AssignMethod(wx_Wizard, GetBitmapPlacement);
	Gura_AssignMethod(wx_Wizard, GetCurrentPage);
	Gura_AssignMethod(wx_Wizard, GetMinimumBitmapWidth);
	Gura_AssignMethod(wx_Wizard, GetPageAreaSizer);
	Gura_AssignMethod(wx_Wizard, GetPageSize);
	Gura_AssignMethod(wx_Wizard, HasNextPage);
	Gura_AssignMethod(wx_Wizard, HasPrevPage);
	Gura_AssignMethod(wx_Wizard, RunWizard);
	Gura_AssignMethod(wx_Wizard, SetBitmap);
	Gura_AssignMethod(wx_Wizard, SetBitmapBackgroundColour);
	Gura_AssignMethod(wx_Wizard, SetBitmapPlacement);
	Gura_AssignMethod(wx_Wizard, SetBorder);
	Gura_AssignMethod(wx_Wizard, SetMinimumBitmapWidth);
	Gura_AssignMethod(wx_Wizard, SetPageSize);
	Gura_AssignMethod(wx_Wizard, ShowPage);
}

Gura_ImplementDescendantCreator(wx_Wizard)
{
	return new Object_wx_Wizard((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
