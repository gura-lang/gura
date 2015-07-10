//----------------------------------------------------------------------------
// wxVersionInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_VersionInfo: public wxVersionInfo, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_VersionInfo *_pObj;
public:
	inline wx_VersionInfo() : wxVersionInfo(), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_VersionInfo(const wxString &name, int major, int minor, int micro, const wxString &description, const wxString &copyright) :
				wxVersionInfo(name, major, minor, micro, description, copyright) {}
	~wx_VersionInfo();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_VersionInfo *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_VersionInfo::~wx_VersionInfo()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_VersionInfo::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxVersionInfo
//----------------------------------------------------------------------------
Gura_DeclareFunction(VersionInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Point));
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "major", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "minor", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "micro", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "description", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "copyright", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(VersionInfo)
{
	//if (!CheckWxReady(sig)) return Value::Null;
	wxString name;
	if (args.IsValid(0)) name = wxString::FromUTF8(args.GetString(0));
	int major = 0;
	if (args.IsValid(1)) major = args.GetInt(1);
	int minor = 0;
	if (args.IsValid(2)) minor = args.GetInt(2);
	int micro = 0;
	if (args.IsValid(3)) micro = args.GetInt(3);
	wxString description;
	if (args.IsValid(4)) description = wxString::FromUTF8(args.GetString(4));
	wxString copyright;
	if (args.IsValid(5)) copyright = wxString::FromUTF8(args.GetString(5));
	wx_VersionInfo *pEntity = new wx_VersionInfo(name, major, minor, micro, description, copyright);
	Object_wx_VersionInfo *pObj = Object_wx_VersionInfo::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_VersionInfo(pEntity, pEntity, OwnerTrue);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxVersionInfo
//----------------------------------------------------------------------------
Object_wx_VersionInfo::~Object_wx_VersionInfo()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_VersionInfo::Clone() const
{
	return nullptr;
}

String Object_wx_VersionInfo::ToString(bool exprFlag)
{
	String rtn("<wx.VersionInfo:");
	rtn += ">";
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxVersionInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VersionInfo)
{
	// assignment of functions
	Gura_AssignFunction(VersionInfo);
}

Gura_ImplementDescendantCreator(wx_VersionInfo)
{
	return new Object_wx_VersionInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
