//----------------------------------------------------------------------------
// wxHtmlColourCell
// extracted from htcolor.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlColourCell: public wxHtmlColourCell, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HtmlColourCell *_pObj;
public:
	inline wx_HtmlColourCell(wxColour clr, int flags) : wxHtmlColourCell(clr, flags), _sig(NULL), _pObj(NULL) {}
	~wx_HtmlColourCell();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlColourCell *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlColourCell::~wx_HtmlColourCell()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HtmlColourCell::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlColourCell
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlColourCell)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HtmlColourCell));
	DeclareArg(env, "clr", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlColourCell)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxColour *clr = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	int flags = wxHTML_CLR_FOREGROUND;
	if (args.IsValid(1)) flags = args.GetInt(1);
	wx_HtmlColourCell *pEntity = new wx_HtmlColourCell(*clr, flags);
	Object_wx_HtmlColourCell *pObj = Object_wx_HtmlColourCell::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HtmlColourCell(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlColourCell
//----------------------------------------------------------------------------
Object_wx_HtmlColourCell::~Object_wx_HtmlColourCell()
{
}

Object *Object_wx_HtmlColourCell::Clone() const
{
	return NULL;
}

String Object_wx_HtmlColourCell::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.HtmlColourCell:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_HtmlColourCell::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(HtmlColourCell);
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlColourCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlColourCell)
{
}

Gura_ImplementDescendantCreator(wx_HtmlColourCell)
{
	return new Object_wx_HtmlColourCell((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
