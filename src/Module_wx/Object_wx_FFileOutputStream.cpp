//----------------------------------------------------------------------------
// wxFFileOutputStream
// extracted from ffilestr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FFileOutputStream: public wxFFileOutputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FFileOutputStream *_pObj;
public:
	inline wx_FFileOutputStream(const wxString& filename, const wxChar * mode) : wxFFileOutputStream(filename, mode), _sig(NULL), _pObj(NULL) {}
	inline wx_FFileOutputStream(wxFFile& file) : wxFFileOutputStream(file), _sig(NULL), _pObj(NULL) {}
	//inline wx_FFileOutputStream(FILE * fp) : wxFFileOutputStream(fp), _sig(NULL), _pObj(NULL) {}
	~wx_FFileOutputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FFileOutputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FFileOutputStream::~wx_FFileOutputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FFileOutputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFFileOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(FFileOutputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FFileOutputStream));
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FFileOutputStream)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxString _mode;
	const wxChar *mode = wxT("w+b");
	if (args.IsValid(1)) {
		_mode = wxString::FromUTF8(args.GetString(1));
		mode = _mode;
	}
	wx_FFileOutputStream *pEntity = new wx_FFileOutputStream(filename, mode);
	Object_wx_FFileOutputStream *pObj = Object_wx_FFileOutputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FFileOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(FFileOutputStream_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FFileOutputStream));
	DeclareArg(env, "file", VTYPE_wx_FFile, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FFileOutputStream_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxFFile *file = Object_wx_FFile::GetObject(args, 0)->GetEntity();
	wx_FFileOutputStream *pEntity = new wx_FFileOutputStream(*file);
	Object_wx_FFileOutputStream *pObj = Object_wx_FFileOutputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FFileOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(FFileOutputStream_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FFileOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FFileOutputStream_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_FFileOutputStream *pEntity = new wx_FFileOutputStream();
	Object_wx_FFileOutputStream *pObj = Object_wx_FFileOutputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FFileOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FFileOutputStream, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FFileOutputStream, IsOk)
{
	Object_wx_FFileOutputStream *pThis = Object_wx_FFileOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxFFileOutputStream
//----------------------------------------------------------------------------
Object_wx_FFileOutputStream::~Object_wx_FFileOutputStream()
{
}

Object *Object_wx_FFileOutputStream::Clone() const
{
	return NULL;
}

String Object_wx_FFileOutputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.FFileOutputStream:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_FFileOutputStream::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(FFileOutputStream);
	Gura_AssignFunction(FFileOutputStream_1);
	Gura_AssignFunction(FFileOutputStream_2);
}

//----------------------------------------------------------------------------
// Class implementation for wxFFileOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FFileOutputStream)
{
	Gura_AssignMethod(wx_FFileOutputStream, IsOk);
}

Gura_ImplementDescendantCreator(wx_FFileOutputStream)
{
	return new Object_wx_FFileOutputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
