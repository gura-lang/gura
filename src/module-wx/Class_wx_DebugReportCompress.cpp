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
	//Gura::Signal *_pSig;
	Object_wx_DebugReportCompress *_pObj;
public:
	inline wx_DebugReportCompress() : wxDebugReportCompress(), _pObj(nullptr) {}
	~wx_DebugReportCompress();
	inline void AssocWithGura(Object_wx_DebugReportCompress *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DebugReportCompress::~wx_DebugReportCompress()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DebugReportCompress::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugReportCompress
//----------------------------------------------------------------------------
Gura_DeclareFunction(DebugReportCompressEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DebugReportCompress));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DebugReportCompressEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_DebugReportCompress *pEntity = new wx_DebugReportCompress();
	Object_wx_DebugReportCompress *pObj = Object_wx_DebugReportCompress::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DebugReportCompress(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_DebugReportCompress, GetCompressedFileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DebugReportCompress, GetCompressedFileName)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReportCompress *pThis = Object_wx_DebugReportCompress::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetCompressedFileName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxDebugReportCompress
//----------------------------------------------------------------------------
Object_wx_DebugReportCompress::~Object_wx_DebugReportCompress()
{
}

Object *Object_wx_DebugReportCompress::Clone() const
{
	return nullptr;
}

String Object_wx_DebugReportCompress::ToString(bool exprFlag)
{
	String rtn("<wx.DebugReportCompress:");
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
// Class implementation for wxDebugReportCompress
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugReportCompress)
{
	Gura_AssignFunction(DebugReportCompressEmpty);
	Gura_AssignMethod(wx_DebugReportCompress, GetCompressedFileName);
}

Gura_ImplementDescendantCreator(wx_DebugReportCompress)
{
	return new Object_wx_DebugReportCompress((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
