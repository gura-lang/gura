//----------------------------------------------------------------------------
// wxDebugReportCompress
// extracted from debugrptz.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DebugReportCompress: public wxDebugReportCompress, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DebugReportCompress *_pObj;
public:
	inline wx_DebugReportCompress() : wxDebugReportCompress(), _sig(NULL), _pObj(NULL) {}
	~wx_DebugReportCompress();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DebugReportCompress *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DebugReportCompress::~wx_DebugReportCompress()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DebugReportCompress::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugReportCompress
//----------------------------------------------------------------------------
Gura_DeclareFunction(DebugReportCompressEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DebugReportCompress));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DebugReportCompressEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_DebugReportCompress *pEntity = new wx_DebugReportCompress();
	Object_wx_DebugReportCompress *pObj = Object_wx_DebugReportCompress::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DebugReportCompress(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_DebugReportCompress, GetCompressedFileName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReportCompress, GetCompressedFileName)
{
	Object_wx_DebugReportCompress *pThis = Object_wx_DebugReportCompress::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetCompressedFileName();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxDebugReportCompress
//----------------------------------------------------------------------------
Object_wx_DebugReportCompress::~Object_wx_DebugReportCompress()
{
}

Object *Object_wx_DebugReportCompress::Clone() const
{
	return NULL;
}

String Object_wx_DebugReportCompress::ToString(bool exprFlag)
{
	String rtn("<wx.DebugReportCompress:");
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
// Class implementation for wxDebugReportCompress
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugReportCompress)
{
	Gura_AssignFunction(DebugReportCompressEmpty);
	Gura_AssignMethod(wx_DebugReportCompress, GetCompressedFileName);
}

Gura_ImplementDescendantCreator(wx_DebugReportCompress)
{
	return new Object_wx_DebugReportCompress((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
