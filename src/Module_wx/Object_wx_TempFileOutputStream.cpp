//----------------------------------------------------------------------------
// wxTempFileOutputStream
// extracted from tempfilestrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TempFileOutputStream: public wxTempFileOutputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TempFileOutputStream *_pObj;
public:
	inline wx_TempFileOutputStream(const wxString& fileName) : wxTempFileOutputStream(fileName), _sig(NULL), _pObj(NULL) {}
	~wx_TempFileOutputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TempFileOutputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TempFileOutputStream::~wx_TempFileOutputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TempFileOutputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTempFileOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(TempFileOutputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TempFileOutputStream));
	DeclareArg(env, "fileName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TempFileOutputStream)
{
	wxString fileName = wxString::FromUTF8(args.GetString(0));
	wx_TempFileOutputStream *pEntity = new wx_TempFileOutputStream(fileName);
	Object_wx_TempFileOutputStream *pObj = Object_wx_TempFileOutputStream::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TempFileOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_TempFileOutputStream, Commit)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TempFileOutputStream, Commit)
{
	Object_wx_TempFileOutputStream *pSelf = Object_wx_TempFileOutputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->Commit();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TempFileOutputStream, Discard)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TempFileOutputStream, Discard)
{
	Object_wx_TempFileOutputStream *pSelf = Object_wx_TempFileOutputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Discard();
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
	return NULL;
}

String Object_wx_TempFileOutputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TempFileOutputStream:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_TempFileOutputStream::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(TempFileOutputStream);
}

//----------------------------------------------------------------------------
// Class implementation for wxTempFileOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TempFileOutputStream)
{
	Gura_AssignMethod(wx_TempFileOutputStream, Commit);
	Gura_AssignMethod(wx_TempFileOutputStream, Discard);
}

Gura_ImplementDescendantCreator(wx_TempFileOutputStream)
{
	return new Object_wx_TempFileOutputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
