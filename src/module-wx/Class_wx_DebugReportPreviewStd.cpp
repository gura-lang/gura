//----------------------------------------------------------------------------
// wxDebugReportPreviewStd
// extracted from debugrptpvwstd.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DebugReportPreviewStd: public wxDebugReportPreviewStd, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DebugReportPreviewStd *_pObj;
public:
	inline wx_DebugReportPreviewStd() : wxDebugReportPreviewStd(), _pObj(nullptr) {}
	~wx_DebugReportPreviewStd();
	inline void AssocWithGura(Object_wx_DebugReportPreviewStd *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DebugReportPreviewStd::~wx_DebugReportPreviewStd()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DebugReportPreviewStd::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugReportPreviewStd
//----------------------------------------------------------------------------
Gura_DeclareFunction(DebugReportPreviewStdEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DebugReportPreviewStd));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DebugReportPreviewStdEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wx_DebugReportPreviewStd *pEntity = new wx_DebugReportPreviewStd();
	Object_wx_DebugReportPreviewStd *pObj = Object_wx_DebugReportPreviewStd::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DebugReportPreviewStd(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_DebugReportPreviewStd, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dbgrpt", VTYPE_wx_DebugReport, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReportPreviewStd, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReportPreviewStd *pThis = Object_wx_DebugReportPreviewStd::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDebugReport *dbgrpt = Object_wx_DebugReport::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Show(*dbgrpt);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDebugReportPreviewStd
//----------------------------------------------------------------------------
Object_wx_DebugReportPreviewStd::~Object_wx_DebugReportPreviewStd()
{
}

Object *Object_wx_DebugReportPreviewStd::Clone() const
{
	return nullptr;
}

String Object_wx_DebugReportPreviewStd::ToString(bool exprFlag)
{
	String rtn("<wx.DebugReportPreviewStd:");
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
// Class implementation for wxDebugReportPreviewStd
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugReportPreviewStd)
{
	Gura_AssignFunction(DebugReportPreviewStdEmpty);
	Gura_AssignMethod(wx_DebugReportPreviewStd, Show);
}

Gura_ImplementDescendantCreator(wx_DebugReportPreviewStd)
{
	return new Object_wx_DebugReportPreviewStd((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
