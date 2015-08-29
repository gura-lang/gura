//----------------------------------------------------------------------------
// wxFileConfig
// extracted from fileconf.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FileConfig: public wxFileConfig, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_FileConfig *_pObj;
public:
	inline wx_FileConfig(wxInputStream& is, wxMBConv& conv) : wxFileConfig(is, conv), _pObj(nullptr) {}
	~wx_FileConfig();
	inline void AssocWithGura(Object_wx_FileConfig *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FileConfig::~wx_FileConfig()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FileConfig::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFileConfig
//----------------------------------------------------------------------------
Gura_DeclareFunction(FileConfig)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FileConfig));
	DeclareArg(env, "is", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileConfig)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxInputStream *is = Object_wx_InputStream::GetObject(arg, 0)->GetEntity();
	wxMBConv *conv = (wxMBConv *)(&wxConvUTF8);
	if (arg.IsValid(1)) conv = Object_wx_MBConv::GetObject(arg, 1)->GetEntity();
	wx_FileConfig *pEntity = new wx_FileConfig(*is, *conv);
	Object_wx_FileConfig *pObj = Object_wx_FileConfig::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_FileConfig(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_FileConfig, Save)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "os", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileConfig, Save)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxOutputStream *os = Object_wx_OutputStream::GetObject(arg, 0)->GetEntity();
	wxMBConv *conv = (wxMBConv *)(&wxConvUTF8);
	if (arg.IsValid(1)) conv = Object_wx_MBConv::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Save(*os, *conv);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FileConfig, SetUmask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileConfig, SetUmask)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileConfig *pThis = Object_wx_FileConfig::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int mode = arg.GetInt(0);
	pThis->GetEntity()->SetUmask(mode);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxFileConfig
//----------------------------------------------------------------------------
Object_wx_FileConfig::~Object_wx_FileConfig()
{
}

Object *Object_wx_FileConfig::Clone() const
{
	return nullptr;
}

String Object_wx_FileConfig::ToString(bool exprFlag)
{
	String rtn("<wx.FileConfig:");
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
// Class implementation for wxFileConfig
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileConfig)
{
	Gura_AssignFunction(FileConfig);
	Gura_AssignMethod(wx_FileConfig, Save);
	Gura_AssignMethod(wx_FileConfig, SetUmask);
}

Gura_ImplementDescendantCreator(wx_FileConfig)
{
	return new Object_wx_FileConfig((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
