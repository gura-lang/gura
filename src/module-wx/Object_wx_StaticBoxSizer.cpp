//----------------------------------------------------------------------------
// wxStaticBoxSizer
// extracted from sbsizer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StaticBoxSizer: public wxStaticBoxSizer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_StaticBoxSizer *_pObj;
public:
	inline wx_StaticBoxSizer(wxStaticBox* box, int orient) : wxStaticBoxSizer(box, orient), _sig(NULL), _pObj(NULL) {}
	inline wx_StaticBoxSizer(int orient, wxWindow *parent, const wxString& label) : wxStaticBoxSizer(orient, parent, label), _sig(NULL), _pObj(NULL) {}
	~wx_StaticBoxSizer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_StaticBoxSizer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StaticBoxSizer::~wx_StaticBoxSizer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_StaticBoxSizer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStaticBoxSizer
//----------------------------------------------------------------------------
Gura_DeclareFunction(StaticBoxSizer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StaticBoxSizer));
	DeclareArg(env, "box", VTYPE_wx_StaticBox, OCCUR_Once);
	DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StaticBoxSizer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxStaticBox *box = Object_wx_StaticBox::GetObject(args, 0)->GetEntity();
	int orient = args.GetInt(1);
	wx_StaticBoxSizer *pEntity = new wx_StaticBoxSizer(box, orient);
	Object_wx_StaticBoxSizer *pObj = Object_wx_StaticBoxSizer::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StaticBoxSizer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(StaticBoxSizerAuto)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StaticBoxSizer));
	DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StaticBoxSizerAuto)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int orient = args.GetInt(0);
	wxWindow *parent = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxString label = wxEmptyString;
	if (args.IsValid(2)) label = wxString::FromUTF8(args.GetString(2));
	wx_StaticBoxSizer *pEntity = new wx_StaticBoxSizer(orient, parent, label);
	Object_wx_StaticBoxSizer *pObj = Object_wx_StaticBoxSizer::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StaticBoxSizer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_StaticBoxSizer, GetStaticBox)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StaticBoxSizer, GetStaticBox)
{
	Object_wx_StaticBoxSizer *pThis = Object_wx_StaticBoxSizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxStaticBox *rtn = (wxStaticBox *)pThis->GetEntity()->GetStaticBox();
	return ReturnValue(env, sig, args, Value(new Object_wx_StaticBox(rtn, NULL, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxStaticBoxSizer
//----------------------------------------------------------------------------
Object_wx_StaticBoxSizer::~Object_wx_StaticBoxSizer()
{
}

Object *Object_wx_StaticBoxSizer::Clone() const
{
	return NULL;
}

String Object_wx_StaticBoxSizer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.StaticBoxSizer:");
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
// Class implementation for wxStaticBoxSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StaticBoxSizer)
{
	Gura_AssignFunction(StaticBoxSizer);
	Gura_AssignFunction(StaticBoxSizerAuto);
	Gura_AssignMethod(wx_StaticBoxSizer, GetStaticBox);
}

Gura_ImplementDescendantCreator(wx_StaticBoxSizer)
{
	return new Object_wx_StaticBoxSizer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
