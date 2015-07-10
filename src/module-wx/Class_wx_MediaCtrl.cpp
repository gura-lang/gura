//----------------------------------------------------------------------------
// wxMediaCtrl
// extracted from mediactrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MediaCtrl: public wxMediaCtrl, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_MediaCtrl *_pObj;
public:
	inline wx_MediaCtrl() : wxMediaCtrl(), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_MediaCtrl(wxWindow* parent, wxWindowID id, const wxString& fileName, const wxPoint& pos, const wxSize& size, long style, const wxString& szBackend, const wxValidator& validator, const wxString& name) : wxMediaCtrl(parent, id, fileName, pos, size, style, szBackend, validator, name), _pSig(nullptr), _pObj(nullptr) {}
	~wx_MediaCtrl();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MediaCtrl *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MediaCtrl::~wx_MediaCtrl()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MediaCtrl::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMediaCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(MediaCtrlEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MediaCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MediaCtrlEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_MediaCtrl *pEntity = new wx_MediaCtrl();
	Object_wx_MediaCtrl *pObj = Object_wx_MediaCtrl::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_MediaCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(MediaCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MediaCtrl));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "fileName", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "szBackend", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MediaCtrl)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString fileName = wxT("");
	if (args.IsValid(2)) fileName = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString szBackend = wxT("");
	if (args.IsValid(6)) szBackend = wxString::FromUTF8(args.GetString(6));
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(7)) validator = Object_wx_Validator::GetObject(args, 7)->GetEntity();
	wxString name = wxPanelNameStr;
	if (args.IsValid(8)) name = wxString::FromUTF8(args.GetString(8));
	wx_MediaCtrl *pEntity = new wx_MediaCtrl(parent, id, fileName, *pos, *size, style, szBackend, *validator, name);
	Object_wx_MediaCtrl *pObj = Object_wx_MediaCtrl::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_MediaCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_MediaCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "fileName", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "szBackend", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MediaCtrl, Create)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString fileName = wxT("");
	if (args.IsValid(2)) fileName = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString szBackend = wxT("");
	if (args.IsValid(6)) szBackend = wxString::FromUTF8(args.GetString(6));
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(7)) validator = Object_wx_Validator::GetObject(args, 7)->GetEntity();
	wxString name = wxPanelNameStr;
	if (args.IsValid(8)) name = wxString::FromUTF8(args.GetString(8));
	bool rtn = pThis->GetEntity()->Create(parent, id, fileName, *pos, *size, style, szBackend, *validator, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MediaCtrl, GetBestSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MediaCtrl, GetBestSize)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetBestSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_MediaCtrl, GetPlaybackRate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MediaCtrl, GetPlaybackRate)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double rtn = pThis->GetEntity()->GetPlaybackRate();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MediaCtrl, GetVolume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MediaCtrl, GetVolume)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double rtn = pThis->GetEntity()->GetVolume();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MediaCtrl, GetState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MediaCtrl, GetState)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetState();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MediaCtrl, Length)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MediaCtrl, Length)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileOffset rtn = pThis->GetEntity()->Length();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MediaCtrl, Load)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "fileName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MediaCtrl, Load)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString fileName = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Load(fileName);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MediaCtrl, Load_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "uri", VTYPE_wx_URI, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MediaCtrl, Load_1)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxURI *uri = Object_wx_URI::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Load(*uri);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MediaCtrl, Load_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "uri", VTYPE_wx_URI, OCCUR_Once);
	DeclareArg(env, "proxy", VTYPE_wx_URI, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MediaCtrl, Load_2)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxURI *uri = Object_wx_URI::GetObject(args, 0)->GetEntity();
	wxURI *proxy = Object_wx_URI::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Load(*uri, *proxy);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MediaCtrl, LoadURI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "uri", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MediaCtrl, LoadURI)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString uri = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->LoadURI(uri);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MediaCtrl, LoadURIWithProxy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "uri", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "proxy", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MediaCtrl, LoadURIWithProxy)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString uri = wxString::FromUTF8(args.GetString(0));
	wxString proxy = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->LoadURIWithProxy(uri, proxy);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MediaCtrl, Pause)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MediaCtrl, Pause)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Pause();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MediaCtrl, Play)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MediaCtrl, Play)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Play();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MediaCtrl, Seek)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "where", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MediaCtrl, Seek)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileOffset where = static_cast<wxFileOffset>(args.GetInt64(0));
	wxSeekMode mode = static_cast<wxSeekMode>(args.GetInt(1));
	wxFileOffset rtn = pThis->GetEntity()->Seek(where, mode);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MediaCtrl, SetPlaybackRate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dRate", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MediaCtrl, SetPlaybackRate)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double dRate = args.GetDouble(0);
	bool rtn = pThis->GetEntity()->SetPlaybackRate(dRate);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MediaCtrl, SetVolume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dVolume", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MediaCtrl, SetVolume)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double dVolume = args.GetDouble(0);
	bool rtn = pThis->GetEntity()->SetVolume(dVolume);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MediaCtrl, ShowPlayerControls)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MediaCtrl, ShowPlayerControls)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMediaCtrlPlayerControls flags = wxMEDIACTRLPLAYERCONTROLS_DEFAULT;
	if (args.IsValid(0)) flags = static_cast<wxMediaCtrlPlayerControls>(args.GetInt(0));
	bool rtn = pThis->GetEntity()->ShowPlayerControls(flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MediaCtrl, Stop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MediaCtrl, Stop)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Stop();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MediaCtrl, Tell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MediaCtrl, Tell)
{
	Object_wx_MediaCtrl *pThis = Object_wx_MediaCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileOffset rtn = pThis->GetEntity()->Tell();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxMediaCtrl
//----------------------------------------------------------------------------
Object_wx_MediaCtrl::~Object_wx_MediaCtrl()
{
}

Object *Object_wx_MediaCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_MediaCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.MediaCtrl:");
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
// Class implementation for wxMediaCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MediaCtrl)
{
	Gura_AssignFunction(MediaCtrlEmpty);
	Gura_AssignFunction(MediaCtrl);
	Gura_AssignMethod(wx_MediaCtrl, Create);
	Gura_AssignMethod(wx_MediaCtrl, GetBestSize);
	Gura_AssignMethod(wx_MediaCtrl, GetPlaybackRate);
	Gura_AssignMethod(wx_MediaCtrl, GetVolume);
	Gura_AssignMethod(wx_MediaCtrl, GetState);
	Gura_AssignMethod(wx_MediaCtrl, Length);
	Gura_AssignMethod(wx_MediaCtrl, Load);
	Gura_AssignMethod(wx_MediaCtrl, Load_1);
	Gura_AssignMethod(wx_MediaCtrl, Load_2);
	Gura_AssignMethod(wx_MediaCtrl, LoadURI);
	Gura_AssignMethod(wx_MediaCtrl, LoadURIWithProxy);
	Gura_AssignMethod(wx_MediaCtrl, Pause);
	Gura_AssignMethod(wx_MediaCtrl, Play);
	Gura_AssignMethod(wx_MediaCtrl, Seek);
	Gura_AssignMethod(wx_MediaCtrl, SetPlaybackRate);
	Gura_AssignMethod(wx_MediaCtrl, SetVolume);
	Gura_AssignMethod(wx_MediaCtrl, ShowPlayerControls);
	Gura_AssignMethod(wx_MediaCtrl, Stop);
	Gura_AssignMethod(wx_MediaCtrl, Tell);
}

Gura_ImplementDescendantCreator(wx_MediaCtrl)
{
	return new Object_wx_MediaCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
