//----------------------------------------------------------------------------
// wxWizardPageSimple
// extracted from wizpage.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_WizardPageSimple: public wxWizardPageSimple, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_WizardPageSimple *_pObj;
public:
	inline wx_WizardPageSimple(wxWizard* parent, wxWizardPage* prev, wxWizardPage* next, const wxBitmap& bitmap) : wxWizardPageSimple(parent, prev, next, bitmap), _sig(NULL), _pObj(NULL) {}
	~wx_WizardPageSimple();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_WizardPageSimple *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_WizardPageSimple::~wx_WizardPageSimple()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_WizardPageSimple::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxWizardPageSimple
//----------------------------------------------------------------------------
Gura_DeclareFunction(WizardPageSimple)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_WizardPageSimple));
	DeclareArg(env, "parent", VTYPE_wx_Wizard, OCCUR_ZeroOrOnce);
	DeclareArg(env, "prev", VTYPE_wx_WizardPage, OCCUR_ZeroOrOnce);
	DeclareArg(env, "next", VTYPE_wx_WizardPage, OCCUR_ZeroOrOnce);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WizardPageSimple)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWizard *parent = (wxWizard *)(NULL);
	if (args.IsValid(0)) parent = Object_wx_Wizard::GetObject(args, 0)->GetEntity();
	wxWizardPage *prev = (wxWizardPage *)(NULL);
	if (args.IsValid(1)) prev = Object_wx_WizardPage::GetObject(args, 1)->GetEntity();
	wxWizardPage *next = (wxWizardPage *)(NULL);
	if (args.IsValid(2)) next = Object_wx_WizardPage::GetObject(args, 2)->GetEntity();
	wxBitmap *bitmap = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(3)) bitmap = Object_wx_Bitmap::GetObject(args, 3)->GetEntity();
	wx_WizardPageSimple *pEntity = new wx_WizardPageSimple(parent, prev, next, *bitmap);
	Object_wx_WizardPageSimple *pObj = Object_wx_WizardPageSimple::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_WizardPageSimple(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_WizardPageSimple, SetPrev)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "prev", VTYPE_wx_WizardPage, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardPageSimple, SetPrev)
{
	Object_wx_WizardPageSimple *pThis = Object_wx_WizardPageSimple::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWizardPage *prev = Object_wx_WizardPage::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPrev(prev);
	return Value::Null;
}

Gura_DeclareMethod(wx_WizardPageSimple, SetNext)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "next", VTYPE_wx_WizardPage, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardPageSimple, SetNext)
{
	Object_wx_WizardPageSimple *pThis = Object_wx_WizardPageSimple::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWizardPage *next = Object_wx_WizardPage::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetNext(next);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_WizardPageSimple, Chain)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "first", VTYPE_wx_WizardPageSimple, OCCUR_Once);
	DeclareArg(env, "second", VTYPE_wx_WizardPageSimple, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_WizardPageSimple, Chain)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWizardPageSimple *first = Object_wx_WizardPageSimple::GetObject(args, 0)->GetEntity();
	wxWizardPageSimple *second = Object_wx_WizardPageSimple::GetObject(args, 1)->GetEntity();
	wxWizardPageSimple::Chain(first, second);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxWizardPageSimple
//----------------------------------------------------------------------------
Object_wx_WizardPageSimple::~Object_wx_WizardPageSimple()
{
}

Object *Object_wx_WizardPageSimple::Clone() const
{
	return NULL;
}

String Object_wx_WizardPageSimple::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.WizardPageSimple:");
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
// Class implementation for wxWizardPageSimple
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WizardPageSimple)
{
	Gura_AssignFunction(WizardPageSimple);
	Gura_AssignMethod(wx_WizardPageSimple, SetPrev);
	Gura_AssignMethod(wx_WizardPageSimple, SetNext);
	Gura_AssignMethod(wx_WizardPageSimple, Chain);
}

Gura_ImplementDescendantCreator(wx_WizardPageSimple)
{
	return new Object_wx_WizardPageSimple((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
