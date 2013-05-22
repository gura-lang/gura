//----------------------------------------------------------------------------
// wxBrushList
// extracted from brush.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_BrushList: public wxBrushList, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_BrushList *_pObj;
public:
	inline wx_BrushList() : wxBrushList(), _sig(NULL), _pObj(NULL) {}
	~wx_BrushList();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_BrushList *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BrushList::~wx_BrushList()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_BrushList::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBrushList
//----------------------------------------------------------------------------
Gura_DeclareFunction(BrushListEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_BrushList));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BrushListEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_BrushList *pEntity = new wx_BrushList();
	Object_wx_BrushList *pObj = Object_wx_BrushList::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_BrushList(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_BrushList, FindOrCreateBrush)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BrushList, FindOrCreateBrush)
{
	Object_wx_BrushList *pThis = Object_wx_BrushList::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	int style = wxSOLID;
	if (args.IsValid(1)) style = args.GetInt(1);
	wxBrush *rtn = (wxBrush *)pThis->GetEntity()->FindOrCreateBrush(*colour, style);
	return ReturnValue(env, sig, args, Value(new Object_wx_Brush(rtn, NULL, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxBrushList
//----------------------------------------------------------------------------
Object_wx_BrushList::~Object_wx_BrushList()
{
}

Object *Object_wx_BrushList::Clone() const
{
	return NULL;
}

String Object_wx_BrushList::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.BrushList:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_BrushList::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(BrushListEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxBrushList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BrushList)
{
	Gura_AssignMethod(wx_BrushList, FindOrCreateBrush);
}

Gura_ImplementDescendantCreator(wx_BrushList)
{
	return new Object_wx_BrushList((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
