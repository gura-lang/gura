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
	Gura::Signal *_pSig;
	Object_wx_FileInputStream *_pObj;
public:
	inline wx_FileInputStream(const wxString& ifileName) : wxFileInputStream(ifileName), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_FileInputStream(wxFile& file) : wxFileInputStream(file), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_FileInputStream(int fd) : wxFileInputStream(fd), _pSig(nullptr), _pObj(nullptr) {}
	~wx_FileInputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FileInputStream *pObj) {
		_pSig = &sig, _pObj = pObj;
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxString ifileName = wxString::FromUTF8(args.GetString(0));
	wx_FileInputStream *pEntity = new wx_FileInputStream(ifileName);
	Object_wx_FileInputStream *pObj = Object_wx_FileInputStream::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_FileInputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_FileInputStream, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileInputStream, IsOk)
{
	Object_wx_FileInputStream *pThis = Object_wx_FileInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, args, Value(rtn));
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
