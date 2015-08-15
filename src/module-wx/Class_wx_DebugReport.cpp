//----------------------------------------------------------------------------
// wxDebugReport
// extracted from debugrpt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DebugReport: public wxDebugReport, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DebugReport *_pObj;
public:
	inline wx_DebugReport() : wxDebugReport(), _pObj(nullptr) {}
	~wx_DebugReport();
	inline void AssocWithGura(Object_wx_DebugReport *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DebugReport::~wx_DebugReport()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DebugReport::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugReport
//----------------------------------------------------------------------------
Gura_DeclareFunction(DebugReportEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DebugReport));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DebugReportEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_DebugReport *pEntity = new wx_DebugReport();
	Object_wx_DebugReport *pObj = Object_wx_DebugReport::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DebugReport(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_DebugReport, AddAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementMethod(wx_DebugReport, AddAll)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->AddAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugReport, AddContext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, AddContext)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->AddContext();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugReport, AddCurrentContext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, AddCurrentContext)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->AddCurrentContext();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugReport, AddCurrentDump)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, AddCurrentDump)
{
	Signal &sig = env.GetSignal();
#if defined(__WXMSW__)
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->AddCurrentDump();
	return ReturnValue(env, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Nil;
#endif	
}

Gura_DeclareMethod(wx_DebugReport, AddDump)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, AddDump)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->AddDump();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugReport, AddExceptionContext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, AddExceptionContext)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->AddExceptionContext();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugReport, AddExceptionDump)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, AddExceptionDump)
{
	Signal &sig = env.GetSignal();
#if defined(__WXMSW__)
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->AddExceptionDump();
	return ReturnValue(env, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Nil;
#endif	
}

Gura_DeclareMethod(wx_DebugReport, AddFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "description", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugReport, AddFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxString description = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->AddFile(filename, description);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugReport, AddText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "description", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, AddText)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxString text = wxString::FromUTF8(args.GetString(1));
	wxString description = wxString::FromUTF8(args.GetString(2));
	bool rtn = pThis->GetEntity()->AddText(filename, text, description);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugReport, DoAddCustomContext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "nodeRoot", VTYPE_wx_XmlNode, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_DebugReport, DoAddCustomContext)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *nodeRoot = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->DoAddCustomContext(nodeRoot);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugReport, DoAddExceptionInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "nodeContext", VTYPE_wx_XmlNode, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, DoAddExceptionInfo)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *nodeContext = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->DoAddExceptionInfo(nodeContext);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugReport, DoAddLoadedModules)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "nodeModules", VTYPE_wx_XmlNode, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, DoAddLoadedModules)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *nodeModules = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->DoAddLoadedModules(nodeModules);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugReport, DoAddSystemInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "nodeSystemInfo", VTYPE_wx_XmlNode, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, DoAddSystemInfo)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *nodeSystemInfo = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->DoAddSystemInfo(nodeSystemInfo);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugReport, GetDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, GetDirectory)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetDirectory();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DebugReport, GetFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "desc", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, GetFile)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = args.GetSizeT(0);
	wxString name = wxString::FromUTF8(args.GetString(1));
	wxString desc = wxString::FromUTF8(args.GetString(2));
	bool rtn = pThis->GetEntity()->GetFile(n, name, desc);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugReport, GetFilesCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, GetFilesCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetFilesCount();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugReport, GetReportName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, GetReportName)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetReportName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DebugReport, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugReport, Process)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReport, Process)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Process();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DebugReport, RemoveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugReport, RemoveFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->RemoveFile(name);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugReport, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DebugReport, Reset)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReport *pThis = Object_wx_DebugReport::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Reset();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxDebugReport
//----------------------------------------------------------------------------
Object_wx_DebugReport::~Object_wx_DebugReport()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_DebugReport::Clone() const
{
	return nullptr;
}

String Object_wx_DebugReport::ToString(bool exprFlag)
{
	String rtn("<wx.DebugReport:");
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
	return new Object_wx_DebugReport((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
