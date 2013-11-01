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
	Gura::Signal _sig;
	Object_wx_SystemSettings *_pObj;
public:
	inline wx_SystemSettings() : wxSystemSettings(), _sig(NULL), _pObj(NULL) {}
	~wx_SystemSettings();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SystemSettings *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SystemSettings::~wx_SystemSettings()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_SystemSettings::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSystemSettings
//----------------------------------------------------------------------------
Gura_DeclareFunction(SystemSettings)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SystemSettings));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SystemSettings)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_SystemSettings *pEntity = new wx_SystemSettings();
	Object_wx_SystemSettings *pObj = Object_wx_SystemSettings::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_SystemSettings(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareClassMethod(wx_SystemSettings, GetColour)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_SystemSettings, GetColour)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxSystemColour index = static_cast<wxSystemColour>(args.GetInt(0));
	wxColour rtn = wxSystemSettings::GetColour(index);
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_SystemSettings, GetFont)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_SystemSettings, GetFont)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxSystemFont index = static_cast<wxSystemFont>(args.GetInt(0));
	wxFont rtn = wxSystemSettings::GetFont(index);
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_SystemSettings, GetMetric)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_SystemSettings, GetMetric)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxSystemMetric index = static_cast<wxSystemMetric>(args.GetInt(0));
	wxWindow *win = (wxWindow *)(NULL);
	if (args.IsValid(1)) win = Object_wx_Window::GetObject(args, 1)->GetEntity();
	int rtn = wxSystemSettings::GetMetric(index, win);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_SystemSettings, GetScreenType)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_SystemSettings, GetScreenType)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxSystemScreenType rtn = wxSystemSettings::GetScreenType();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxSystemSettings
//----------------------------------------------------------------------------
Object_wx_SystemSettings::~Object_wx_SystemSettings()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_SystemSettings::Clone() const
{
	return NULL;
}

String Object_wx_SystemSettings::ToString(bool exprFlag)
{
	String rtn("<wx.SystemSettings:");
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
	return new Object_wx_SystemSettings((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
