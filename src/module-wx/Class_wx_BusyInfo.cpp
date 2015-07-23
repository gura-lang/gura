//----------------------------------------------------------------------------
// wxBusyInfo
// extracted from busyinfo.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_BusyInfo: public wxBusyInfo, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_BusyInfo *_pObj;
public:
	inline wx_BusyInfo(const wxString& msg, wxWindow* parent) : wxBusyInfo(msg, parent), _pObj(nullptr) {}
	~wx_BusyInfo();
	inline void AssocWithGura(Object_wx_BusyInfo *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BusyInfo::~wx_BusyInfo()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_BusyInfo::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBusyInfo
//----------------------------------------------------------------------------
Gura_DeclareFunction(BusyInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_BusyInfo));
	DeclareArg(env, "msg", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementFunction(BusyInfo)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString msg = wxString::FromUTF8(args.GetString(0));
	wxWindow *parent = (wxWindow *)(nullptr);
	if (args.IsValid(1)) parent = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wx_BusyInfo busyInfo(msg, parent);
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	SeqPostHandler *pSeqPostHandler = nullptr;
	Value rtn = pExprBlock->Exec2(env, sig, pSeqPostHandler);
	return rtn;
}

//----------------------------------------------------------------------------
// Object implementation for wxBusyInfo
//----------------------------------------------------------------------------
Object_wx_BusyInfo::~Object_wx_BusyInfo()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_BusyInfo::Clone() const
{
	return nullptr;
}

String Object_wx_BusyInfo::ToString(bool exprFlag)
{
	String rtn("<wx.BusyInfo:");
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
// Class implementation for wxBusyInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BusyInfo)
{
	Gura_AssignFunction(BusyInfo);
}

Gura_ImplementDescendantCreator(wx_BusyInfo)
{
	return new Object_wx_BusyInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
