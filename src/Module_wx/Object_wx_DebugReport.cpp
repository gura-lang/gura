//----------------------------------------------------------------------------
// wxDebugReport
// extracted from debugrpt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DebugReport: public wxDebugReport, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DebugReport *_pObj;
public:
	inline wx_DebugReport() : wxDebugReport(), _sig(NULL), _pObj(NULL) {}
	~wx_DebugReport();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DebugReport *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DebugReport::~wx_DebugReport()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DebugReport::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugReport
//----------------------------------------------------------------------------
Gura_DeclareFunction(DebugReportEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DebugReport));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DebugReportEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_DebugReport *pEntity = new wx_DebugReport();
	Object_wx_DebugReport *pObj = Object_wx_DebugReport::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DebugReport(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_DebugReport, AddAll)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_DebugReport, AddAll)
{
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->AddAll();
	return Value::Null;
}

Gura_DeclareMethod(wx_DebugReport, AddContext)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, AddContext)
{
#if 0
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->AddContext();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DebugReport, AddCurrentContext)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, AddCurrentContext)
{
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->AddCurrentContext();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugReport, AddCurrentDump)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, AddCurrentDump)
{
#if defined(__WXMSW__)
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->AddCurrentDump();
	return ReturnValue(env, sig, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_DebugReport, AddDump)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, AddDump)
{
#if 0
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->AddDump();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DebugReport, AddExceptionContext)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, AddExceptionContext)
{
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->AddExceptionContext();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugReport, AddExceptionDump)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, AddExceptionDump)
{
#if defined(__WXMSW__)
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->AddExceptionDump();
	return ReturnValue(env, sig, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_DebugReport, AddFile)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "description", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugReport, AddFile)
{
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxString description = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->AddFile(filename, description);
	return Value::Null;
}

Gura_DeclareMethod(wx_DebugReport, AddText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "description", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, AddText)
{
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxString text = wxString::FromUTF8(args.GetString(1));
	wxString description = wxString::FromUTF8(args.GetString(2));
	bool rtn = pThis->GetEntity()->AddText(filename, text, description);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugReport, DoAddCustomContext)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "nodeRoot", VTYPE_wx_XmlNode, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_DebugReport, DoAddCustomContext)
{
#if 0
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlNode *nodeRoot = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->DoAddCustomContext(nodeRoot);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DebugReport, DoAddExceptionInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "nodeContext", VTYPE_wx_XmlNode, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, DoAddExceptionInfo)
{
#if 0
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlNode *nodeContext = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->DoAddExceptionInfo(nodeContext);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DebugReport, DoAddLoadedModules)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "nodeModules", VTYPE_wx_XmlNode, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, DoAddLoadedModules)
{
#if 0
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlNode *nodeModules = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->DoAddLoadedModules(nodeModules);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DebugReport, DoAddSystemInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "nodeSystemInfo", VTYPE_wx_XmlNode, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, DoAddSystemInfo)
{
#if 0
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlNode *nodeSystemInfo = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->DoAddSystemInfo(nodeSystemInfo);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DebugReport, GetDirectory)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, GetDirectory)
{
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetDirectory();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DebugReport, GetFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "desc", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, GetFile)
{
#if 0
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t n = args.GetSizeT(0);
	wxString name = wxString::FromUTF8(args.GetString(1));
	wxString desc = wxString::FromUTF8(args.GetString(2));
	bool rtn = pThis->GetEntity()->GetFile(n, name, desc);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DebugReport, GetFilesCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, GetFilesCount)
{
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetFilesCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugReport, GetReportName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, GetReportName)
{
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetReportName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DebugReport, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, IsOk)
{
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugReport, Process)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, Process)
{
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Process();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugReport, RemoveFile)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugReport, RemoveFile)
{
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->RemoveFile(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_DebugReport, Reset)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DebugReport, Reset)
{
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Reset();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDebugReport
//----------------------------------------------------------------------------
Object_wx_DebugReport::~Object_wx_DebugReport()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_DebugReport::Clone() const
{
	return NULL;
}

String Object_wx_DebugReport::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DebugReport:");
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
// Class implementation for wxDebugReport
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugReport)
{
	Gura_AssignFunction(DebugReportEmpty);
	Gura_AssignMethod(wx_DebugReport, AddAll);
	Gura_AssignMethod(wx_DebugReport, AddContext);
	Gura_AssignMethod(wx_DebugReport, AddCurrentContext);
	Gura_AssignMethod(wx_DebugReport, AddCurrentDump);
	Gura_AssignMethod(wx_DebugReport, AddDump);
	Gura_AssignMethod(wx_DebugReport, AddExceptionContext);
	Gura_AssignMethod(wx_DebugReport, AddExceptionDump);
	Gura_AssignMethod(wx_DebugReport, AddFile);
	Gura_AssignMethod(wx_DebugReport, AddText);
	Gura_AssignMethod(wx_DebugReport, DoAddCustomContext);
	Gura_AssignMethod(wx_DebugReport, DoAddExceptionInfo);
	Gura_AssignMethod(wx_DebugReport, DoAddLoadedModules);
	Gura_AssignMethod(wx_DebugReport, DoAddSystemInfo);
	Gura_AssignMethod(wx_DebugReport, GetDirectory);
	Gura_AssignMethod(wx_DebugReport, GetFile);
	Gura_AssignMethod(wx_DebugReport, GetFilesCount);
	Gura_AssignMethod(wx_DebugReport, GetReportName);
	Gura_AssignMethod(wx_DebugReport, IsOk);
	Gura_AssignMethod(wx_DebugReport, Process);
	Gura_AssignMethod(wx_DebugReport, RemoveFile);
	Gura_AssignMethod(wx_DebugReport, Reset);
}

Gura_ImplementDescendantCreator(wx_DebugReport)
{
	return new Object_wx_DebugReport((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
