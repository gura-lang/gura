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
	//Gura::Signal *_pSig;
	Object_wx_HtmlWidgetCell *_pObj;
public:
	inline wx_HtmlWidgetCell(wxWindow* wnd, int w) : wxHtmlWidgetCell(wnd, w), _pObj(nullptr) {}
	~wx_HtmlWidgetCell();
	inline void AssocWithGura(Object_wx_HtmlWidgetCell *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlWidgetCell::~wx_HtmlWidgetCell()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlWidgetCell::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWidgetCell
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlWidgetCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HtmlWidgetCell));
	DeclareArg(env, "wnd", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "w", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlWidgetCell)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *wnd = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	int w = 0;
	if (arg.IsValid(1)) w = arg.GetInt(1);
	wx_HtmlWidgetCell *pEntity = new wx_HtmlWidgetCell(wnd, w);
	Object_wx_HtmlWidgetCell *pObj = Object_wx_HtmlWidgetCell::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlWidgetCell(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWidgetCell
//----------------------------------------------------------------------------
Object_wx_HtmlWidgetCell::~Object_wx_HtmlWidgetCell()
{
}

Object *Object_wx_HtmlWidgetCell::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlWidgetCell::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlWidgetCell:");
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
// Class implementation for wxHtmlWidgetCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWidgetCell)
{
	Gura_AssignFunction(HtmlWidgetCell);
}

Gura_ImplementDescendantCreator(wx_HtmlWidgetCell)
{
	return new Object_wx_HtmlWidgetCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
