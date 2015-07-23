//----------------------------------------------------------------------------
// wxHtmlListBox
// extracted from htmllbox.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(OnLinkClicked);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlListBox: public wxHtmlListBox, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_HtmlListBox *_pObj;
public:
	//inline wx_HtmlListBox(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxHtmlListBox(parent, id, pos, size, style, name), _pObj(nullptr) {}
	//inline wx_HtmlListBox() : wxHtmlListBox(), _pObj(nullptr) {}
	//virtual void OnLinkClicked(size_t n, const wxHtmlLinkInfo& link);
	~wx_HtmlListBox();
	inline void AssocWithGura(Object_wx_HtmlListBox *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlListBox::~wx_HtmlListBox()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlListBox::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlListBox
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlListBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_HtmlListBox));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(HtmlListBox)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = 0;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxHtmlListBoxNameStr;
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	wx_HtmlListBox *pEntity = new wx_HtmlListBox(parent, id, *pos, *size, style, name);
	Object_wx_HtmlListBox *pObj = Object_wx_HtmlListBox::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlListBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(HtmlListBoxEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_HtmlListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(HtmlListBoxEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_HtmlListBox *pEntity = new wx_HtmlListBox();
	Object_wx_HtmlListBox *pObj = Object_wx_HtmlListBox::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlListBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlListBox, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlListBox, Create)
{
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = 0;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxHtmlListBoxNameStr;
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, style, name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlListBox, GetFileSystem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlListBox, GetFileSystem)
{
#if 0
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileSystem &rtn = pThis->GetEntity()->GetFileSystem();
	return ReturnValue(env, args, Value(new Object_wx_FileSystem(new wxFileSystem(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlListBox, GetFileSystem_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlListBox, GetFileSystem_1)
{
#if 0
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxFileSystem &rtn = pThis->GetEntity()->GetFileSystem();
	return ReturnValue(env, args, Value(new Object_wx_FileSystem(new wxFileSystem(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlListBox, GetSelectedTextBgColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "colBg", VTYPE_wx_Colour, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlListBox, GetSelectedTextBgColour)
{
#if 0
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colBg = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	wxColour rtn = pThis->GetEntity()->GetSelectedTextBgColour(*colBg);
	return ReturnValue(env, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlListBox, GetSelectedTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "colFg", VTYPE_wx_Colour, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlListBox, GetSelectedTextColour)
{
#if 0
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colFg = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	wxColour rtn = pThis->GetEntity()->GetSelectedTextColour(*colFg);
	return ReturnValue(env, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlListBox, OnGetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlListBox, OnGetItem)
{
#if 0
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t n = args.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->OnGetItem(n);
	return ReturnValue(env, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlListBox, OnGetItemMarkup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlListBox, OnGetItemMarkup)
{
#if 0
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t n = args.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->OnGetItemMarkup(n);
	return ReturnValue(env, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlListBox, OnLinkClicked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "link", VTYPE_wx_HtmlLinkInfo, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlListBox, OnLinkClicked)
{
#if 0
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t n = args.GetSizeT(0);
	wxHtmlLinkInfo *link = Object_wx_HtmlLinkInfo::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->OnLinkClicked(n, *link);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlListBox
//----------------------------------------------------------------------------
Object_wx_HtmlListBox::~Object_wx_HtmlListBox()
{
}

Object *Object_wx_HtmlListBox::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlListBox::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlListBox:");
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
// Class implementation for wxHtmlListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlListBox)
{
	Gura_RealizeUserSymbol(OnLinkClicked);
	Gura_AssignWxStringValue(HtmlListBoxNameStr);
	Gura_AssignFunction(HtmlListBox);
	Gura_AssignFunction(HtmlListBoxEmpty);
	Gura_AssignMethod(wx_HtmlListBox, Create);
	Gura_AssignMethod(wx_HtmlListBox, GetFileSystem);
	Gura_AssignMethod(wx_HtmlListBox, GetFileSystem_1);
	Gura_AssignMethod(wx_HtmlListBox, GetSelectedTextBgColour);
	Gura_AssignMethod(wx_HtmlListBox, GetSelectedTextColour);
	Gura_AssignMethod(wx_HtmlListBox, OnGetItem);
	Gura_AssignMethod(wx_HtmlListBox, OnGetItemMarkup);
	Gura_AssignMethod(wx_HtmlListBox, OnLinkClicked);
}

Gura_ImplementDescendantCreator(wx_HtmlListBox)
{
	return new Object_wx_HtmlListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
