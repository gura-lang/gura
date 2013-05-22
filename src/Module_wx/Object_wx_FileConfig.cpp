//----------------------------------------------------------------------------
// wxFileConfig
// extracted from fileconf.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FileConfig: public wxFileConfig, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FileConfig *_pObj;
public:
	inline wx_FileConfig(wxInputStream& is, wxMBConv& conv) : wxFileConfig(is, conv), _sig(NULL), _pObj(NULL) {}
	~wx_FileConfig();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FileConfig *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FileConfig::~wx_FileConfig()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FileConfig::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFileConfig
//----------------------------------------------------------------------------
Gura_DeclareFunction(FileConfig)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FileConfig));
	DeclareArg(env, "is", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileConfig)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxInputStream *is = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxMBConv *conv = (wxMBConv *)(&wxConvUTF8);
	if (args.IsValid(1)) conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	wx_FileConfig *pEntity = new wx_FileConfig(*is, *conv);
	Object_wx_FileConfig *pObj = Object_wx_FileConfig::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FileConfig(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_FileConfig, Save)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "os", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileConfig, Save)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxOutputStream *os = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wxMBConv *conv = (wxMBConv *)(&wxConvUTF8);
	if (args.IsValid(1)) conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Save(*os, *conv);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileConfig, SetUmask)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, SetUmask)
{
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int mode = args.GetInt(0);
	pThis->GetEntity()->SetUmask(mode);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxFileConfig
//----------------------------------------------------------------------------
Object_wx_FileConfig::~Object_wx_FileConfig()
{
}

Object *Object_wx_FileConfig::Clone() const
{
	return NULL;
}

String Object_wx_FileConfig::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.FileConfig:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_FileConfig::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(FileConfig);
}

//----------------------------------------------------------------------------
// Class implementation for wxFileConfig
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileConfig)
{
	Gura_AssignMethod(wx_FileConfig, Save);
	Gura_AssignMethod(wx_FileConfig, SetUmask);
}

Gura_ImplementDescendantCreator(wx_FileConfig)
{
	return new Object_wx_FileConfig((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
