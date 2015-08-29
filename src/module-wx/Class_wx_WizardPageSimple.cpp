//----------------------------------------------------------------------------
// wxWizardPageSimple
// extracted from wizpage.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_WizardPageSimple: public wxWizardPageSimple, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_WizardPageSimple *_pObj;
public:
	inline wx_WizardPageSimple(wxWizard* parent, wxWizardPage* prev, wxWizardPage* next, const wxBitmap& bitmap) : wxWizardPageSimple(parent, prev, next, bitmap), _pObj(nullptr) {}
	~wx_WizardPageSimple();
	inline void AssocWithGura(Object_wx_WizardPageSimple *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_WizardPageSimple::~wx_WizardPageSimple()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_WizardPageSimple::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxWizardPageSimple
//----------------------------------------------------------------------------
Gura_DeclareFunction(WizardPageSimple)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_WizardPageSimple));
	DeclareArg(env, "parent", VTYPE_wx_Wizard, OCCUR_ZeroOrOnce);
	DeclareArg(env, "prev", VTYPE_wx_WizardPage, OCCUR_ZeroOrOnce);
	DeclareArg(env, "next", VTYPE_wx_WizardPage, OCCUR_ZeroOrOnce);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WizardPageSimple)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWizard *parent = (wxWizard *)(nullptr);
	if (arg.IsValid(0)) parent = Object_wx_Wizard::GetObject(arg, 0)->GetEntity();
	wxWizardPage *prev = (wxWizardPage *)(nullptr);
	if (arg.IsValid(1)) prev = Object_wx_WizardPage::GetObject(arg, 1)->GetEntity();
	wxWizardPage *next = (wxWizardPage *)(nullptr);
	if (arg.IsValid(2)) next = Object_wx_WizardPage::GetObject(arg, 2)->GetEntity();
	wxBitmap *bitmap = (wxBitmap *)(&wxNullBitmap);
	if (arg.IsValid(3)) bitmap = Object_wx_Bitmap::GetObject(arg, 3)->GetEntity();
	wx_WizardPageSimple *pEntity = new wx_WizardPageSimple(parent, prev, next, *bitmap);
	Object_wx_WizardPageSimple *pObj = Object_wx_WizardPageSimple::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_WizardPageSimple(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_WizardPageSimple, SetPrev)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "prev", VTYPE_wx_WizardPage, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardPageSimple, SetPrev)
{
	Signal &sig = env.GetSignal();
	Object_wx_WizardPageSimple *pThis = Object_wx_WizardPageSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	Object_wx_WizardPage *prev = Object_wx_WizardPage::GetObject(arg, 0);
	pThis->SetPrev(prev);
	return Value::Nil;
}

Gura_DeclareMethod(wx_WizardPageSimple, SetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "next", VTYPE_wx_WizardPage, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardPageSimple, SetNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_WizardPageSimple *pThis = Object_wx_WizardPageSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	Object_wx_WizardPage *next = Object_wx_WizardPage::GetObject(arg, 0);
	pThis->SetNext(next);
	return Value::Nil;
}

Gura_DeclareMethod(wx_WizardPageSimple, Chain)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "next", VTYPE_wx_WizardPageSimple, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardPageSimple, Chain)
{
	Signal &sig = env.GetSignal();
	Object_wx_WizardPageSimple *pThis = Object_wx_WizardPageSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	Object_wx_WizardPageSimple *next = Object_wx_WizardPageSimple::GetObject(arg, 0);
	pThis->SetNext(next);
	next->SetPrev(pThis);
	return arg.GetValueThis();
}

Gura_DeclareClassMethod(wx_WizardPageSimple, ChainBoth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "first", VTYPE_wx_WizardPageSimple, OCCUR_Once);
	DeclareArg(env, "second", VTYPE_wx_WizardPageSimple, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_WizardPageSimple, ChainBoth)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	Object_wx_WizardPageSimple *first = Object_wx_WizardPageSimple::GetObject(arg, 0);
	Object_wx_WizardPageSimple *second = Object_wx_WizardPageSimple::GetObject(arg, 1);
	first->SetNext(second);
	second->SetPrev(first);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxWizardPageSimple
//----------------------------------------------------------------------------
Object_wx_WizardPageSimple::~Object_wx_WizardPageSimple()
{
}

Object *Object_wx_WizardPageSimple::Clone() const
{
	return nullptr;
}

String Object_wx_WizardPageSimple::ToString(bool exprFlag)
{
	String rtn("<wx.WizardPageSimple:");
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
// Class implementation for wxWizardPageSimple
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WizardPageSimple)
{
	Gura_AssignFunction(WizardPageSimple);
	Gura_AssignMethod(wx_WizardPageSimple, SetPrev);
	Gura_AssignMethod(wx_WizardPageSimple, SetNext);
	Gura_AssignMethod(wx_WizardPageSimple, Chain);
	Gura_AssignMethod(wx_WizardPageSimple, ChainBoth);
}

Gura_ImplementDescendantCreator(wx_WizardPageSimple)
{
	return new Object_wx_WizardPageSimple((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
