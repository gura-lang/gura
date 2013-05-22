//----------------------------------------------------------------------------
// wxPenList
// extracted from pen.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PenList: public wxPenList, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PenList *_pObj;
public:
	inline wx_PenList() : wxPenList(), _sig(NULL), _pObj(NULL) {}
	~wx_PenList();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PenList *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PenList::~wx_PenList()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_PenList::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPenList
//----------------------------------------------------------------------------
Gura_DeclareFunction(PenListEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PenList));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PenListEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_PenList *pEntity = new wx_PenList();
	Object_wx_PenList *pObj = Object_wx_PenList::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PenList(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_PenList, FindOrCreatePen)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PenList, FindOrCreatePen)
{
	Object_wx_PenList *pThis = Object_wx_PenList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	int width = args.GetInt(1);
	int style = args.GetInt(2);
	wxPen *rtn = (wxPen *)pThis->GetEntity()->FindOrCreatePen(*colour, width, style);
	return ReturnValue(env, sig, args, Value(new Object_wx_Pen(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_PenList, FindOrCreatePen_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "colourName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PenList, FindOrCreatePen_1)
{
	Object_wx_PenList *pThis = Object_wx_PenList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString colourName = wxString::FromUTF8(args.GetString(0));
	int width = args.GetInt(1);
	int style = args.GetInt(2);
	wxPen *rtn = (wxPen *)pThis->GetEntity()->FindOrCreatePen(colourName, width, style);
	return ReturnValue(env, sig, args, Value(new Object_wx_Pen(rtn, NULL, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxPenList
//----------------------------------------------------------------------------
Object_wx_PenList::~Object_wx_PenList()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_PenList::Clone() const
{
	return NULL;
}

String Object_wx_PenList::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.PenList:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_PenList::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(PenListEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxPenList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PenList)
{
	Gura_AssignMethod(wx_PenList, FindOrCreatePen);
	Gura_AssignMethod(wx_PenList, FindOrCreatePen_1);
}

Gura_ImplementDescendantCreator(wx_PenList)
{
	return new Object_wx_PenList((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
