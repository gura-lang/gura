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
	//Gura::Signal *_pSig;
	Object_wx_DebugReportUpload *_pObj;
public:
	inline wx_DebugReportUpload(const wxString& url, const wxString& input, const wxString& action, const wxString& curl) : wxDebugReportUpload(url, input, action, curl), _pObj(nullptr) {}
	~wx_DebugReportUpload();
	inline void AssocWithGura(Object_wx_DebugReportUpload *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DebugReportUpload::~wx_DebugReportUpload()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DebugReportUpload::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugReportUpload
//----------------------------------------------------------------------------
Gura_DeclareFunction(DebugReportUpload)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DebugReportUpload));
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "input", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "action", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "curl", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DebugReportUpload)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString url = wxString::FromUTF8(args.GetString(0));
	wxString input = wxString::FromUTF8(args.GetString(1));
	wxString action = wxString::FromUTF8(args.GetString(2));
	wxString curl = _T("curl");
	if (args.IsValid(3)) curl = wxString::FromUTF8(args.GetString(3));
	wx_DebugReportUpload *pEntity = new wx_DebugReportUpload(url, input, action, curl);
	Object_wx_DebugReportUpload *pObj = Object_wx_DebugReportUpload::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DebugReportUpload(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_DebugReportUpload, OnServerReply)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "WXUNUSED(reply)", VTYPE_string, OCCUR_Once, FLAG_List);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReportUpload, OnServerReply)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DebugReportUpload *pThis = Object_wx_DebugReportUpload::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	std::unique_ptr<wxArrayString> WXUNUSED(reply)(CreateArrayString(args.GetList(0)));
	bool rtn = pThis->GetEntity()->OnServerReply(*WXUNUSED(reply));
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxDebugReportUpload
//----------------------------------------------------------------------------
Object_wx_DebugReportUpload::~Object_wx_DebugReportUpload()
{
}

Object *Object_wx_DebugReportUpload::Clone() const
{
	return nullptr;
}

String Object_wx_DebugReportUpload::ToString(bool exprFlag)
{
	String rtn("<wx.DebugReportUpload:");
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
// Class implementation for wxDebugReportUpload
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugReportUpload)
{
	Gura_AssignFunction(DebugReportUpload);
	Gura_AssignMethod(wx_DebugReportUpload, OnServerReply);
}

Gura_ImplementDescendantCreator(wx_DebugReportUpload)
{
	return new Object_wx_DebugReportUpload((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
