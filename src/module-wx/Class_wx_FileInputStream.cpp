//----------------------------------------------------------------------------
// wxFileInputStream
// extracted from fileistr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FileInputStream: public wxFileInputStream, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_FileInputStream *_pObj;
public:
	inline wx_FileInputStream(const wxString& ifileName) : wxFileInputStream(ifileName), _pObj(nullptr) {}
	inline wx_FileInputStream(wxFile& file) : wxFileInputStream(file), _pObj(nullptr) {}
	inline wx_FileInputStream(int fd) : wxFileInputStream(fd), _pObj(nullptr) {}
	~wx_FileInputStream();
	inline void AssocWithGura(Object_wx_FileInputStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FileInputStream::~wx_FileInputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FileInputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFileInputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(FileInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FileInputStream));
	DeclareArg(env, "ifileName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileInputStream)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString ifileName = wxString::FromUTF8(arg.GetString(0));
	wx_FileInputStream *pEntity = new wx_FileInputStream(ifileName);
	Object_wx_FileInputStream *pObj = Object_wx_FileInputStream::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_FileInputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_FileInputStream, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileInputStream, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileInputStream *pThis = Object_wx_FileInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxFileInputStream
//----------------------------------------------------------------------------
Object_wx_FileInputStream::~Object_wx_FileInputStream()
{
}

Object *Object_wx_FileInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_FileInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.FileInputStream:");
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
// Class implementation for wxFileInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileInputStream)
{
	Gura_AssignFunction(FileInputStream);
	Gura_AssignMethod(wx_FileInputStream, IsOk);
	Gura_AssignMethodEx(wx_FileInputStream, IsOk, "Ok");
}

Gura_ImplementDescendantCreator(wx_FileInputStream)
{
	return new Object_wx_FileInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
