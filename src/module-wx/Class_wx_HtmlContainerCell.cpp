//----------------------------------------------------------------------------
// wxHtmlContainerCell
// extracted from htcontnr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlContainerCell: public wxHtmlContainerCell, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HtmlContainerCell *_pObj;
public:
	//inline wx_HtmlContainerCell(wxHtmlContainerCell *parent) : wxHtmlContainerCell(*parent), _sig(NULL), _pObj(NULL) {}
	~wx_HtmlContainerCell();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlContainerCell *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlContainerCell::~wx_HtmlContainerCell()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HtmlContainerCell::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlContainerCell
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlContainerCell)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_HtmlContainerCell));
	DeclareArg(env, "*parent", VTYPE_wx_HtmlContainerCell, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(HtmlContainerCell)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxHtmlContainerCell **parent = Object_wx_HtmlContainerCell::GetObject(args, 0)->GetEntity();
	wx_HtmlContainerCell *pEntity = new wx_HtmlContainerCell(**parent);
	Object_wx_HtmlContainerCell *pObj = Object_wx_HtmlContainerCell::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HtmlContainerCell(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlContainerCell, GetAlignHor)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlContainerCell, GetAlignHor)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetAlignHor();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlContainerCell, GetAlignVer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlContainerCell, GetAlignVer)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetAlignVer();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlContainerCell, GetBackgroundColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlContainerCell, GetBackgroundColour)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour rtn = pThis->GetEntity()->GetBackgroundColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_HtmlContainerCell, GetIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ind", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlContainerCell, GetIndent)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int ind = args.GetInt(0);
	int rtn = pThis->GetEntity()->GetIndent(ind);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlContainerCell, GetIndentUnits)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ind", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlContainerCell, GetIndentUnits)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int ind = args.GetInt(0);
	int rtn = pThis->GetEntity()->GetIndentUnits(ind);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlContainerCell, InsertCell)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*cell", VTYPE_wx_HtmlCell, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlContainerCell, InsertCell)
{
#if 0
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxHtmlCell **cell = Object_wx_HtmlCell::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->InsertCell(**cell);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlContainerCell, SetAlign)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "tag", VTYPE_wx_HtmlTag, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlContainerCell, SetAlign)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxHtmlTag *tag = Object_wx_HtmlTag::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetAlign(*tag);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlContainerCell, SetAlignHor)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "al", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlContainerCell, SetAlignHor)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int al = args.GetInt(0);
	pThis->GetEntity()->SetAlignHor(al);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlContainerCell, SetAlignVer)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "al", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlContainerCell, SetAlignVer)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int al = args.GetInt(0);
	pThis->GetEntity()->SetAlignVer(al);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlContainerCell, SetBackgroundColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "clr", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlContainerCell, SetBackgroundColour)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *clr = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBackgroundColour(*clr);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlContainerCell, SetBorder)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "clr1", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "clr2", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlContainerCell, SetBorder)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *clr1 = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	wxColour *clr2 = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetBorder(*clr1, *clr2);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlContainerCell, SetIndent)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "what", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "units", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlContainerCell, SetIndent)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int i = args.GetInt(0);
	int what = args.GetInt(1);
	int units = wxHTML_UNITS_PIXELS;
	if (args.IsValid(2)) units = args.GetInt(2);
	pThis->GetEntity()->SetIndent(i, what, units);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlContainerCell, SetMinHeight)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "align", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlContainerCell, SetMinHeight)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int h = args.GetInt(0);
	int align = wxHTML_ALIGN_TOP;
	if (args.IsValid(1)) align = args.GetInt(1);
	pThis->GetEntity()->SetMinHeight(h, align);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlContainerCell, SetWidthFloat)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlContainerCell, SetWidthFloat)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int w = args.GetInt(0);
	int units = args.GetInt(1);
	pThis->GetEntity()->SetWidthFloat(w, units);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlContainerCell, SetWidthFloat_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "tag", VTYPE_wx_HtmlTag, OCCUR_Once);
	DeclareArg(env, "pixel_scale", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlContainerCell, SetWidthFloat_1)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxHtmlTag *tag = Object_wx_HtmlTag::GetObject(args, 0)->GetEntity();
	double pixel_scale = 1.0;
	if (args.IsValid(1)) pixel_scale = args.GetDouble(1);
	pThis->GetEntity()->SetWidthFloat(*tag, pixel_scale);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlContainerCell
//----------------------------------------------------------------------------
Object_wx_HtmlContainerCell::~Object_wx_HtmlContainerCell()
{
}

Object *Object_wx_HtmlContainerCell::Clone() const
{
	return NULL;
}

String Object_wx_HtmlContainerCell::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlContainerCell:");
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
// Class implementation for wxHtmlContainerCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlContainerCell)
{
	Gura_AssignFunction(HtmlContainerCell);
	Gura_AssignMethod(wx_HtmlContainerCell, GetAlignHor);
	Gura_AssignMethod(wx_HtmlContainerCell, GetAlignVer);
	Gura_AssignMethod(wx_HtmlContainerCell, GetBackgroundColour);
	Gura_AssignMethod(wx_HtmlContainerCell, GetIndent);
	Gura_AssignMethod(wx_HtmlContainerCell, GetIndentUnits);
	Gura_AssignMethod(wx_HtmlContainerCell, InsertCell);
	Gura_AssignMethod(wx_HtmlContainerCell, SetAlign);
	Gura_AssignMethod(wx_HtmlContainerCell, SetAlignHor);
	Gura_AssignMethod(wx_HtmlContainerCell, SetAlignVer);
	Gura_AssignMethod(wx_HtmlContainerCell, SetBackgroundColour);
	Gura_AssignMethod(wx_HtmlContainerCell, SetBorder);
	Gura_AssignMethod(wx_HtmlContainerCell, SetIndent);
	Gura_AssignMethod(wx_HtmlContainerCell, SetMinHeight);
	Gura_AssignMethod(wx_HtmlContainerCell, SetWidthFloat);
	Gura_AssignMethod(wx_HtmlContainerCell, SetWidthFloat_1);
}

Gura_ImplementDescendantCreator(wx_HtmlContainerCell)
{
	return new Object_wx_HtmlContainerCell((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
