//----------------------------------------------------------------------------
// wxDebugReportPreviewStd
// extracted from debugrptpvwstd.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DebugReportPreviewStd: public wxDebugReportPreviewStd, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DebugReportPreviewStd *_pObj;
public:
	inline wx_DebugReportPreviewStd() : wxDebugReportPreviewStd(), _sig(NULL), _pObj(NULL) {}
	~wx_DebugReportPreviewStd();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DebugReportPreviewStd *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DebugReportPreviewStd::~wx_DebugReportPreviewStd()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DebugReportPreviewStd::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugReportPreviewStd
//----------------------------------------------------------------------------
Gura_DeclareFunction(DebugReportPreviewStdEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DebugReportPreviewStd));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DebugReportPreviewStdEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_DebugReportPreviewStd *pEntity = new wx_DebugReportPreviewStd();
	Object_wx_DebugReportPreviewStd *pObj = Object_wx_DebugReportPreviewStd::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DebugReportPreviewStd(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_DebugReportPreviewStd, Show)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dbgrpt", VTYPE_wx_DebugReport, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReportPreviewStd, Show)
{
	Object_wx_DebugReportPreviewStd *pThis = Object_wx_DebugReportPreviewStd::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDebugReport *dbgrpt = Object_wx_DebugReport::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Show(*dbgrpt);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDebugReportPreviewStd
//----------------------------------------------------------------------------
Object_wx_DebugReportPreviewStd::~Object_wx_DebugReportPreviewStd()
{
}

Object *Object_wx_DebugReportPreviewStd::Clone() const
{
	return NULL;
}

String Object_wx_DebugReportPreviewStd::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DebugReportPreviewStd:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DebugReportPreviewStd::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(DebugReportPreviewStdEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxDebugReportPreviewStd
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugReportPreviewStd)
{
	Gura_AssignMethod(wx_DebugReportPreviewStd, Show);
}

Gura_ImplementDescendantCreator(wx_DebugReportPreviewStd)
{
	return new Object_wx_DebugReportPreviewStd((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
