//----------------------------------------------------------------------------
// wxIconBundle
// extracted from iconbndl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_IconBundle: public wxIconBundle, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_IconBundle *_pObj;
public:
	inline wx_IconBundle() : wxIconBundle(), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_IconBundle(const wxString& file, long type) : wxIconBundle(file, type), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_IconBundle(const wxIcon& icon) : wxIconBundle(icon), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_IconBundle(const wxIconBundle& ic) : wxIconBundle(ic), _pSig(nullptr), _pObj(nullptr) {}
	~wx_IconBundle();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_IconBundle *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_IconBundle::~wx_IconBundle()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_IconBundle::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxIconBundle
//----------------------------------------------------------------------------
Gura_DeclareFunction(IconBundleEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_IconBundle));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IconBundleEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_IconBundle *pEntity = new wx_IconBundle();
	Object_wx_IconBundle *pObj = Object_wx_IconBundle::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_IconBundle(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(IconBundle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_IconBundle));
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IconBundle)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString file = wxString::FromUTF8(args.GetString(0));
	long type = args.GetLong(1);
	wx_IconBundle *pEntity = new wx_IconBundle(file, type);
	Object_wx_IconBundle *pObj = Object_wx_IconBundle::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_IconBundle(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(IconBundle_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_IconBundle));
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IconBundle_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxIcon *icon = Object_wx_Icon::GetObject(args, 0)->GetEntity();
	wx_IconBundle *pEntity = new wx_IconBundle(*icon);
	Object_wx_IconBundle *pObj = Object_wx_IconBundle::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_IconBundle(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(IconBundle_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_IconBundle));
	DeclareArg(env, "ic", VTYPE_wx_IconBundle, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IconBundle_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxIconBundle *ic = Object_wx_IconBundle::GetObject(args, 0)->GetEntity();
	wx_IconBundle *pEntity = new wx_IconBundle(*ic);
	Object_wx_IconBundle *pObj = Object_wx_IconBundle::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_IconBundle(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_IconBundle, AddIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IconBundle, AddIcon)
{
	Object_wx_IconBundle *pThis = Object_wx_IconBundle::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString file = wxString::FromUTF8(args.GetString(0));
	long type = args.GetLong(1);
	pThis->GetEntity()->AddIcon(file, type);
	return Value::Null;
}

Gura_DeclareMethod(wx_IconBundle, AddIcon_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
}

Gura_ImplementMethod(wx_IconBundle, AddIcon_1)
{
	Object_wx_IconBundle *pThis = Object_wx_IconBundle::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxIcon *icon = Object_wx_Icon::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AddIcon(*icon);
	return Value::Null;
}

Gura_DeclareMethod(wx_IconBundle, GetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IconBundle, GetIcon)
{
	Object_wx_IconBundle *pThis = Object_wx_IconBundle::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	const wxIcon &rtn = pThis->GetEntity()->GetIcon(*size);
	return ReturnValue(env, sig, args, Value(new Object_wx_Icon(new wxIcon(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_IconBundle, GetIcon_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IconBundle, GetIcon_1)
{
	Object_wx_IconBundle *pThis = Object_wx_IconBundle::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord size = -1;
	if (args.IsValid(0)) size = static_cast<wxCoord>(args.GetInt(0));
	const wxIcon &rtn = pThis->GetEntity()->GetIcon(size);
	return ReturnValue(env, sig, args, Value(new Object_wx_Icon(new wxIcon(rtn), nullptr, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxIconBundle
//----------------------------------------------------------------------------
Object_wx_IconBundle::~Object_wx_IconBundle()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_IconBundle::Clone() const
{
	return nullptr;
}

String Object_wx_IconBundle::ToString(bool exprFlag)
{
	String rtn("<wx.IconBundle:");
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
// Class implementation for wxIconBundle
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IconBundle)
{
	Gura_AssignFunction(IconBundleEmpty);
	Gura_AssignFunction(IconBundle);
	Gura_AssignFunction(IconBundle_1);
	Gura_AssignFunction(IconBundle_2);
	Gura_AssignMethod(wx_IconBundle, AddIcon);
	Gura_AssignMethod(wx_IconBundle, AddIcon_1);
	Gura_AssignMethod(wx_IconBundle, GetIcon);
	Gura_AssignMethod(wx_IconBundle, GetIcon_1);
}

Gura_ImplementDescendantCreator(wx_IconBundle)
{
	return new Object_wx_IconBundle((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
