//----------------------------------------------------------------------------
// wxStringBufferLength
// extracted from wxstring.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StringBufferLength: public wxStringBufferLength, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_StringBufferLength *_pObj;
public:
	inline wx_StringBufferLength(wxString& str, size_t len) : wxStringBufferLength(str, len), _pSig(nullptr), _pObj(nullptr) {}
	~wx_StringBufferLength();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_StringBufferLength *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StringBufferLength::~wx_StringBufferLength()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_StringBufferLength::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStringBufferLength
//----------------------------------------------------------------------------
Gura_DeclareFunction(StringBufferLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StringBufferLength));
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StringBufferLength)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	size_t len = args.GetSizeT(1);
	wx_StringBufferLength *pEntity = new wx_StringBufferLength(str, len);
	Object_wx_StringBufferLength *pObj = Object_wx_StringBufferLength::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_StringBufferLength(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_StringBufferLength, SetLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "nLength", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StringBufferLength, SetLength)
{
	Object_wx_StringBufferLength *pThis = Object_wx_StringBufferLength::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t nLength = args.GetSizeT(0);
	pThis->GetEntity()->SetLength(nLength);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxStringBufferLength
//----------------------------------------------------------------------------
Object_wx_StringBufferLength::~Object_wx_StringBufferLength()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_StringBufferLength::Clone() const
{
	return nullptr;
}

String Object_wx_StringBufferLength::ToString(bool exprFlag)
{
	String rtn("<wx.StringBufferLength:");
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
// Class implementation for wxStringBufferLength
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringBufferLength)
{
	Gura_AssignFunction(StringBufferLength);
	Gura_AssignMethod(wx_StringBufferLength, SetLength);
}

Gura_ImplementDescendantCreator(wx_StringBufferLength)
{
	return new Object_wx_StringBufferLength((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
