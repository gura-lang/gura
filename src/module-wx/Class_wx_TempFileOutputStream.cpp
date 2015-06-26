//----------------------------------------------------------------------------
// wxTempFileOutputStream
// extracted from tempfilestrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TempFileOutputStream: public wxTempFileOutputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TempFileOutputStream *_pObj;
public:
	inline wx_TempFileOutputStream(const wxString& fileName) : wxTempFileOutputStream(fileName), _sig(nullptr), _pObj(nullptr) {}
	~wx_TempFileOutputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TempFileOutputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TempFileOutputStream::~wx_TempFileOutputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TempFileOutputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTempFileOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(TempFileOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TempFileOutputStream));
	DeclareArg(env, "fileName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TempFileOutputStream)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString fileName = wxString::FromUTF8(args.GetString(0));
	wx_TempFileOutputStream *pEntity = new wx_TempFileOutputStream(fileName);
	Object_wx_TempFileOutputStream *pObj = Object_wx_TempFileOutputStream::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TempFileOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_TempFileOutputStream, Commit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TempFileOutputStream, Commit)
{
	Object_wx_TempFileOutputStream *pThis = Object_wx_TempFileOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Commit();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TempFileOutputStream, Discard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TempFileOutputStream, Discard)
{
	Object_wx_TempFileOutputStream *pThis = Object_wx_TempFileOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Discard();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxTempFileOutputStream
//----------------------------------------------------------------------------
Object_wx_TempFileOutputStream::~Object_wx_TempFileOutputStream()
{
}

Object *Object_wx_TempFileOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_TempFileOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.TempFileOutputStream:");
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
// Class implementation for wxTempFileOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TempFileOutputStream)
{
	Gura_AssignFunction(TempFileOutputStream);
	Gura_AssignMethod(wx_TempFileOutputStream, Commit);
	Gura_AssignMethod(wx_TempFileOutputStream, Discard);
}

Gura_ImplementDescendantCreator(wx_TempFileOutputStream)
{
	return new Object_wx_TempFileOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
