//----------------------------------------------------------------------------
// wxHtmlWidgetCell
// extracted from htwidget.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlWidgetCell: public wxHtmlWidgetCell, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HtmlWidgetCell *_pObj;
public:
	inline wx_HtmlWidgetCell(wxWindow* wnd, int w) : wxHtmlWidgetCell(wnd, w), _sig(NULL), _pObj(NULL) {}
	~wx_HtmlWidgetCell();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlWidgetCell *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlWidgetCell::~wx_HtmlWidgetCell()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HtmlWidgetCell::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWidgetCell
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlWidgetCell)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HtmlWidgetCell));
	DeclareArg(env, "wnd", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "w", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlWidgetCell)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *wnd = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int w = 0;
	if (args.IsValid(1)) w = args.GetInt(1);
	wx_HtmlWidgetCell *pEntity = new wx_HtmlWidgetCell(wnd, w);
	Object_wx_HtmlWidgetCell *pObj = Object_wx_HtmlWidgetCell::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HtmlWidgetCell(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWidgetCell
//----------------------------------------------------------------------------
Object_wx_HtmlWidgetCell::~Object_wx_HtmlWidgetCell()
{
}

Object *Object_wx_HtmlWidgetCell::Clone() const
{
	return NULL;
}

String Object_wx_HtmlWidgetCell::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlWidgetCell:");
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
// Class implementation for wxHtmlWidgetCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWidgetCell)
{
	Gura_AssignFunction(HtmlWidgetCell);
}

Gura_ImplementDescendantCreator(wx_HtmlWidgetCell)
{
	return new Object_wx_HtmlWidgetCell((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
