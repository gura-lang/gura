//----------------------------------------------------------------------------
// wxHtmlDCRenderer
// extracted from htdcrend.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlDCRenderer: public wxHtmlDCRenderer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_HtmlDCRenderer *_pObj;
public:
	inline wx_HtmlDCRenderer() : wxHtmlDCRenderer(), _pObj(nullptr) {}
	~wx_HtmlDCRenderer();
	inline void AssocWithGura(Object_wx_HtmlDCRenderer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlDCRenderer::~wx_HtmlDCRenderer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlDCRenderer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlDCRenderer
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlDCRendererEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlDCRenderer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlDCRendererEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_HtmlDCRenderer *pEntity = new wx_HtmlDCRenderer();
	Object_wx_HtmlDCRenderer *pObj = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlDCRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_HtmlDCRenderer, SetDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "pixel_scale", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, SetDC)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(arg, 0)->GetEntity();
	double pixel_scale = 1.0;
	if (arg.IsValid(1)) pixel_scale = arg.GetDouble(1);
	pThis->GetEntity()->SetDC(dc, pixel_scale);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlDCRenderer, SetFonts)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "normal_face", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "fixed_face", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "*sizes", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_HtmlDCRenderer, SetFonts)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString normal_face = wxString::FromUTF8(arg.GetString(0));
	wxString fixed_face = wxString::FromUTF8(arg.GetString(1));
	int *sizes = nullptr;
	if (arg.IsValid(2)) *sizes = arg.GetInt(2);
	pThis->GetEntity()->SetFonts(normal_face, fixed_face, *sizes);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlDCRenderer, SetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, SetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width = arg.GetInt(0);
	int height = arg.GetInt(1);
	pThis->GetEntity()->SetSize(width, height);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlDCRenderer, SetHtmlText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "html", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "basepath", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "isdir", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, SetHtmlText)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString html = wxString::FromUTF8(arg.GetString(0));
	wxString basepath = wxEmptyString;
	if (arg.IsValid(1)) basepath = wxString::FromUTF8(arg.GetString(1));
	bool isdir = true;
	if (arg.IsValid(2)) isdir = arg.GetBoolean(2);
	pThis->GetEntity()->SetHtmlText(html, basepath, isdir);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlDCRenderer, Render)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "from", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "dont_render", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, Render)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = arg.GetInt(0);
	int y = arg.GetInt(1);
	int from = 0;
	if (arg.IsValid(2)) from = arg.GetInt(2);
	int dont_render = false;
	if (arg.IsValid(3)) dont_render = arg.GetInt(3);
	int rtn = pThis->GetEntity()->Render(x, y, from, dont_render);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlDCRenderer, GetTotalHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, GetTotalHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetTotalHeight();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlDCRenderer
//----------------------------------------------------------------------------
Object_wx_HtmlDCRenderer::~Object_wx_HtmlDCRenderer()
{
}

Object *Object_wx_HtmlDCRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlDCRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlDCRenderer:");
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
// Class implementation for wxHtmlDCRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlDCRenderer)
{
	Gura_AssignFunction(HtmlDCRendererEmpty);
	Gura_AssignMethod(wx_HtmlDCRenderer, SetDC);
	Gura_AssignMethod(wx_HtmlDCRenderer, SetFonts);
	Gura_AssignMethod(wx_HtmlDCRenderer, SetSize);
	Gura_AssignMethod(wx_HtmlDCRenderer, SetHtmlText);
	Gura_AssignMethod(wx_HtmlDCRenderer, Render);
	Gura_AssignMethod(wx_HtmlDCRenderer, GetTotalHeight);
}

Gura_ImplementDescendantCreator(wx_HtmlDCRenderer)
{
	return new Object_wx_HtmlDCRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
