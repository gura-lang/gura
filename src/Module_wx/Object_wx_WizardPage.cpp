//----------------------------------------------------------------------------
// wxWizardPage
// extracted from wizpage.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_WizardPage: public wxWizardPage, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_WizardPage *_pObj;
public:
	//inline wx_WizardPage(wxWizard* parent, const wxBitmap& bitmap, const wxChar *resource) : wxWizardPage(parent, bitmap, *resource), _sig(NULL), _pObj(NULL) {}
	~wx_WizardPage();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_WizardPage *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_WizardPage::~wx_WizardPage()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_WizardPage::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxWizardPage
//----------------------------------------------------------------------------
Gura_DeclareFunction(WizardPage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_WizardPage));
	DeclareArg(env, "parent", VTYPE_wx_Wizard, OCCUR_Once);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareArg(env, "*resource", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(WizardPage)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxWizard *parent = Object_wx_Wizard::GetObject(args, 0)->GetEntity();
	wxBitmap *bitmap = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(1)) bitmap = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	wxChar *resource = NULL;
	if (args.IsValid(2)) *resource = static_cast<wxChar>(args.GetInt(2));
	wx_WizardPage *pEntity = new wx_WizardPage(parent, *bitmap, *resource);
	Object_wx_WizardPage *pObj = Object_wx_WizardPage::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_WizardPage(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_WizardPage, GetPrev)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_WizardPage, GetPrev)
{
	Object_wx_WizardPage *pThis = Object_wx_WizardPage::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWizardPage *rtn = (wxWizardPage *)pThis->GetEntity()->GetPrev();
	return ReturnValue(env, sig, args, Value(new Object_wx_WizardPage(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_WizardPage, GetNext)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_WizardPage, GetNext)
{
	Object_wx_WizardPage *pThis = Object_wx_WizardPage::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWizardPage *rtn = (wxWizardPage *)pThis->GetEntity()->GetNext();
	return ReturnValue(env, sig, args, Value(new Object_wx_WizardPage(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_WizardPage, GetBitmap)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_WizardPage, GetBitmap)
{
	Object_wx_WizardPage *pThis = Object_wx_WizardPage::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap rtn = pThis->GetEntity()->GetBitmap();
	return ReturnValue(env, sig, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), NULL, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxWizardPage
//----------------------------------------------------------------------------
Object_wx_WizardPage::~Object_wx_WizardPage()
{
}

Object *Object_wx_WizardPage::Clone() const
{
	return NULL;
}

String Object_wx_WizardPage::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.WizardPage:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_WizardPage::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(WizardPage);
}

//----------------------------------------------------------------------------
// Class implementation for wxWizardPage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WizardPage)
{
	Gura_AssignMethod(wx_WizardPage, GetPrev);
	Gura_AssignMethod(wx_WizardPage, GetNext);
	Gura_AssignMethod(wx_WizardPage, GetBitmap);
}

Gura_ImplementDescendantCreator(wx_WizardPage)
{
	return new Object_wx_WizardPage((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
