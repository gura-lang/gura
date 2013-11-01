//----------------------------------------------------------------------------
// wxDebugReportPreview
// extracted from debugrptpvw.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DebugReportPreview: public wxDebugReportPreview, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DebugReportPreview *_pObj;
public:
	//inline wx_DebugReportPreview() : wxDebugReportPreview(), _sig(NULL), _pObj(NULL) {}
	~wx_DebugReportPreview();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DebugReportPreview *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DebugReportPreview::~wx_DebugReportPreview()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DebugReportPreview::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugReportPreview
//----------------------------------------------------------------------------
Gura_DeclareFunction(DebugReportPreviewEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DebugReportPreview));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(DebugReportPreviewEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_DebugReportPreview *pEntity = new wx_DebugReportPreview();
	Object_wx_DebugReportPreview *pObj = Object_wx_DebugReportPreview::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DebugReportPreview(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DebugReportPreview, Show)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dbgrpt", VTYPE_wx_DebugReport, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReportPreview, Show)
{
	Object_wx_DebugReportPreview *pThis = Object_wx_DebugReportPreview::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDebugReport *dbgrpt = Object_wx_DebugReport::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Show(*dbgrpt);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDebugReportPreview
//----------------------------------------------------------------------------
Object_wx_DebugReportPreview::~Object_wx_DebugReportPreview()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_DebugReportPreview::Clone() const
{
	return NULL;
}

String Object_wx_DebugReportPreview::ToString(bool exprFlag)
{
	String rtn("<wx.DebugReportPreview:");
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
// Class implementation for wxDebugReportPreview
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugReportPreview)
{
	Gura_AssignFunction(DebugReportPreviewEmpty);
	Gura_AssignMethod(wx_DebugReportPreview, Show);
}

Gura_ImplementDescendantCreator(wx_DebugReportPreview)
{
	return new Object_wx_DebugReportPreview((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
