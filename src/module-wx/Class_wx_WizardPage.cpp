//----------------------------------------------------------------------------
// wxWizardPage
// extracted from wizpage.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(GetNext);
Gura_DeclarePrivUserSymbol(GetPrev);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_WizardPage: public wxWizardPage, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_WizardPage *_pObj;
public:
	inline wx_WizardPage(wxWizard* parent, const wxBitmap& bitmap) : wxWizardPage(parent, bitmap), _pObj(nullptr) {}
	virtual wxWizardPage *GetNext() const;
	virtual wxWizardPage *GetPrev() const;
	~wx_WizardPage();
	inline void AssocWithGura(Object_wx_WizardPage *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_WizardPage::~wx_WizardPage()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_WizardPage::GuraObjectDeleted()
{
	_pObj = nullptr;
}

wxWizardPage *wx_WizardPage::GetNext() const
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetNext);
	if (pFunc == nullptr) return nullptr;
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, ValueList::Empty);
	if (rtn.IsInvalid()) return nullptr;
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_wx_WizardPage)) return 0;
	return Object_wx_WizardPage::GetObject(rtn)->GetEntity();
}

wxWizardPage *wx_WizardPage::GetPrev() const
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetPrev);
	if (pFunc == nullptr) return nullptr;
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, ValueList::Empty);
	if (rtn.IsInvalid()) return nullptr;
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_wx_WizardPage)) return 0;
	return Object_wx_WizardPage::GetObject(rtn)->GetEntity();
}

//----------------------------------------------------------------------------
// Gura interfaces for wxWizardPage
//----------------------------------------------------------------------------
Gura_DeclareFunction(WizardPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_WizardPage));
	DeclareArg(env, "parent", VTYPE_wx_Wizard, OCCUR_Once);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WizardPage)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWizard *parent = Object_wx_Wizard::GetObject(args, 0)->GetEntity();
	wxBitmap *bitmap = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(1)) bitmap = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	wx_WizardPage *pEntity = new wx_WizardPage(parent, *bitmap);
	Object_wx_WizardPage *pObj = Object_wx_WizardPage::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_WizardPage(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_WizardPage, GetPrev)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_WizardPage, GetPrev)
{
	Signal &sig = env.GetSignal();
	Object_wx_WizardPage *pThis = Object_wx_WizardPage::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWizardPage *rtn = (wxWizardPage *)pThis->GetEntity()->GetPrev();
	return ReturnValue(env, args, Value(new Object_wx_WizardPage(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_WizardPage, GetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_WizardPage, GetNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_WizardPage *pThis = Object_wx_WizardPage::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWizardPage *rtn = (wxWizardPage *)pThis->GetEntity()->GetNext();
	return ReturnValue(env, args, Value(new Object_wx_WizardPage(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_WizardPage, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_WizardPage, GetBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_WizardPage *pThis = Object_wx_WizardPage::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBitmap rtn = pThis->GetEntity()->GetBitmap();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxWizardPage
//----------------------------------------------------------------------------
Object_wx_WizardPage::~Object_wx_WizardPage()
{
}

Object *Object_wx_WizardPage::Clone() const
{
	return nullptr;
}

String Object_wx_WizardPage::ToString(bool exprFlag)
{
	String rtn("<wx.WizardPage:");
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
// Class implementation for wxWizardPage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WizardPage)
{
	Gura_RealizeUserSymbol(GetNext);
	Gura_RealizeUserSymbol(GetPrev);
	Gura_AssignFunction(WizardPage);
	Gura_AssignMethod(wx_WizardPage, GetPrev);
	Gura_AssignMethod(wx_WizardPage, GetNext);
	Gura_AssignMethod(wx_WizardPage, GetBitmap);
}

Gura_ImplementDescendantCreator(wx_WizardPage)
{
	return new Object_wx_WizardPage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
