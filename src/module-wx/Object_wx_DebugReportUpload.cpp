//----------------------------------------------------------------------------
// wxDebugReportUpload
// extracted from debugrptup.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DebugReportUpload: public wxDebugReportUpload, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DebugReportUpload *_pObj;
public:
	inline wx_DebugReportUpload(const wxString& url, const wxString& input, const wxString& action, const wxString& curl) : wxDebugReportUpload(url, input, action, curl), _sig(NULL), _pObj(NULL) {}
	~wx_DebugReportUpload();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DebugReportUpload *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DebugReportUpload::~wx_DebugReportUpload()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DebugReportUpload::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugReportUpload
//----------------------------------------------------------------------------
Gura_DeclareFunction(DebugReportUpload)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DebugReportUpload));
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "input", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "action", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "curl", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DebugReportUpload)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString url = wxString::FromUTF8(args.GetString(0));
	wxString input = wxString::FromUTF8(args.GetString(1));
	wxString action = wxString::FromUTF8(args.GetString(2));
	wxString curl = _T("curl");
	if (args.IsValid(3)) curl = wxString::FromUTF8(args.GetString(3));
	wx_DebugReportUpload *pEntity = new wx_DebugReportUpload(url, input, action, curl);
	Object_wx_DebugReportUpload *pObj = Object_wx_DebugReportUpload::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DebugReportUpload(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_DebugReportUpload, OnServerReply)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "WXUNUSED(reply)", VTYPE_string, OCCUR_Once, FLAG_List);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReportUpload, OnServerReply)
{
#if 0
	Object_wx_DebugReportUpload *pThis = Object_wx_DebugReportUpload::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	std::auto_ptr<wxArrayString> WXUNUSED(reply)(CreateArrayString(args.GetList(0)));
	bool rtn = pThis->GetEntity()->OnServerReply(*WXUNUSED(reply));
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDebugReportUpload
//----------------------------------------------------------------------------
Object_wx_DebugReportUpload::~Object_wx_DebugReportUpload()
{
}

Object *Object_wx_DebugReportUpload::Clone() const
{
	return NULL;
}

String Object_wx_DebugReportUpload::ToString(bool exprFlag)
{
	String rtn("<wx.DebugReportUpload:");
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
// Class implementation for wxDebugReportUpload
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugReportUpload)
{
	Gura_AssignFunction(DebugReportUpload);
	Gura_AssignMethod(wx_DebugReportUpload, OnServerReply);
}

Gura_ImplementDescendantCreator(wx_DebugReportUpload)
{
	return new Object_wx_DebugReportUpload((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
