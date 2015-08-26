//----------------------------------------------------------------------------
// wxSystemSettings
// extracted from settings.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SystemSettings: public wxSystemSettings, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SystemSettings *_pObj;
public:
	inline wx_SystemSettings() : wxSystemSettings(), _pObj(nullptr) {}
	~wx_SystemSettings();
	inline void AssocWithGura(Object_wx_SystemSettings *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SystemSettings::~wx_SystemSettings()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SystemSettings::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSystemSettings
//----------------------------------------------------------------------------
Gura_DeclareFunction(SystemSettings)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SystemSettings));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SystemSettings)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_SystemSettings *pEntity = new wx_SystemSettings();
	Object_wx_SystemSettings *pObj = Object_wx_SystemSettings::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SystemSettings(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareClassMethod(wx_SystemSettings, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_SystemSettings, GetColour)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxSystemColour index = static_cast<wxSystemColour>(args.GetInt(0));
	wxColour rtn = wxSystemSettings::GetColour(index);
	return ReturnValue(env, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_SystemSettings, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_SystemSettings, GetFont)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxSystemFont index = static_cast<wxSystemFont>(args.GetInt(0));
	wxFont rtn = wxSystemSettings::GetFont(index);
	return ReturnValue(env, args, Value(new Object_wx_Font(new wxFont(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_SystemSettings, GetMetric)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_SystemSettings, GetMetric)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxSystemMetric index = static_cast<wxSystemMetric>(args.GetInt(0));
	wxWindow *win = (wxWindow *)(nullptr);
	if (args.IsValid(1)) win = Object_wx_Window::GetObject(args, 1)->GetEntity();
	int rtn = wxSystemSettings::GetMetric(index, win);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_SystemSettings, GetScreenType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_SystemSettings, GetScreenType)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxSystemScreenType rtn = wxSystemSettings::GetScreenType();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxSystemSettings
//----------------------------------------------------------------------------
Object_wx_SystemSettings::~Object_wx_SystemSettings()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_SystemSettings::Clone() const
{
	return nullptr;
}

String Object_wx_SystemSettings::ToString(bool exprFlag)
{
	String rtn("<wx.SystemSettings:");
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
// Class implementation for wxSystemSettings
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SystemSettings)
{
	Gura_AssignFunction(SystemSettings);
	Gura_AssignMethod(wx_SystemSettings, GetColour);
	Gura_AssignMethod(wx_SystemSettings, GetFont);
	Gura_AssignMethod(wx_SystemSettings, GetMetric);
	Gura_AssignMethod(wx_SystemSettings, GetScreenType);
}

Gura_ImplementDescendantCreator(wx_SystemSettings)
{
	return new Object_wx_SystemSettings((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
