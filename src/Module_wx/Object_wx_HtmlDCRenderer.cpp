//----------------------------------------------------------------------------
// wxHtmlDCRenderer
// extracted from htdcrend.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlDCRenderer: public wxHtmlDCRenderer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HtmlDCRenderer *_pObj;
public:
	inline wx_HtmlDCRenderer() : wxHtmlDCRenderer(), _sig(NULL), _pObj(NULL) {}
	~wx_HtmlDCRenderer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlDCRenderer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlDCRenderer::~wx_HtmlDCRenderer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HtmlDCRenderer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlDCRenderer
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlDCRendererEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlDCRenderer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlDCRendererEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_HtmlDCRenderer *pEntity = new wx_HtmlDCRenderer();
	Object_wx_HtmlDCRenderer *pObj = Object_wx_HtmlDCRenderer::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HtmlDCRenderer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_HtmlDCRenderer, SetDC)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "pixel_scale", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, SetDC)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	double pixel_scale = 1.0;
	if (args.IsValid(1)) pixel_scale = args.GetDouble(1);
	pThis->GetEntity()->SetDC(dc, pixel_scale);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlDCRenderer, SetFonts)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "normal_face", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "fixed_face", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "*sizes", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_HtmlDCRenderer, SetFonts)
{
#if 0
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString normal_face = wxString::FromUTF8(args.GetString(0));
	wxString fixed_face = wxString::FromUTF8(args.GetString(1));
	int *sizes = NULL;
	if (args.IsValid(2)) *sizes = args.GetInt(2);
	pThis->GetEntity()->SetFonts(normal_face, fixed_face, *sizes);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlDCRenderer, SetSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, SetSize)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	pThis->GetEntity()->SetSize(width, height);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlDCRenderer, SetHtmlText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "html", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "basepath", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "isdir", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, SetHtmlText)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString html = wxString::FromUTF8(args.GetString(0));
	wxString basepath = wxEmptyString;
	if (args.IsValid(1)) basepath = wxString::FromUTF8(args.GetString(1));
	bool isdir = true;
	if (args.IsValid(2)) isdir = args.GetBoolean(2);
	pThis->GetEntity()->SetHtmlText(html, basepath, isdir);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlDCRenderer, Render)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
#if 0
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	int from = 0;
	if (args.IsValid(2)) from = args.GetInt(2);
	int dont_render = false;
	if (args.IsValid(3)) dont_render = args.GetInt(3);
	int rtn = pThis->GetEntity()->Render(x, y, from, dont_render);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlDCRenderer, GetTotalHeight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, GetTotalHeight)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetTotalHeight();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlDCRenderer
//----------------------------------------------------------------------------
Object_wx_HtmlDCRenderer::~Object_wx_HtmlDCRenderer()
{
}

Object *Object_wx_HtmlDCRenderer::Clone() const
{
	return NULL;
}

String Object_wx_HtmlDCRenderer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.HtmlDCRenderer:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_HtmlDCRenderer::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(HtmlDCRendererEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlDCRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlDCRenderer)
{
	Gura_AssignMethod(wx_HtmlDCRenderer, SetDC);
	Gura_AssignMethod(wx_HtmlDCRenderer, SetFonts);
	Gura_AssignMethod(wx_HtmlDCRenderer, SetSize);
	Gura_AssignMethod(wx_HtmlDCRenderer, SetHtmlText);
	Gura_AssignMethod(wx_HtmlDCRenderer, Render);
	Gura_AssignMethod(wx_HtmlDCRenderer, GetTotalHeight);
}

Gura_ImplementDescendantCreator(wx_HtmlDCRenderer)
{
	return new Object_wx_HtmlDCRenderer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
