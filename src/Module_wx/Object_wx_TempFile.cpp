//----------------------------------------------------------------------------
// wxTempFile
// extracted from tempfile.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TempFile: public wxTempFile, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TempFile *_pObj;
public:
	inline wx_TempFile() : wxTempFile(), _sig(NULL), _pObj(NULL) {}
	inline wx_TempFile(const wxString& strName) : wxTempFile(strName), _sig(NULL), _pObj(NULL) {}
	~wx_TempFile();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TempFile *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TempFile::~wx_TempFile()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TempFile::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTempFile
//----------------------------------------------------------------------------
Gura_DeclareFunction(TempFileEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TempFile));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TempFileEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_TempFile *pEntity = new wx_TempFile();
	Object_wx_TempFile *pObj = Object_wx_TempFile::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TempFile(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(TempFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TempFile));
	DeclareArg(env, "strName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TempFile)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString strName = wxString::FromUTF8(args.GetString(0));
	wx_TempFile *pEntity = new wx_TempFile(strName);
	Object_wx_TempFile *pObj = Object_wx_TempFile::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TempFile(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_TempFile, Open)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "strName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TempFile, Open)
{
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString strName = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Open(strName);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TempFile, IsOpened)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TempFile, IsOpened)
{
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOpened();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TempFile, Length)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TempFile, Length)
{
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileOffset rtn = pThis->GetEntity()->Length();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TempFile, Seek)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ofs", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TempFile, Seek)
{
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileOffset ofs = static_cast<wxFileOffset>(args.GetInt64(0));
	wxSeekMode mode = wxFromStart;
	if (args.IsValid(1)) mode = static_cast<wxSeekMode>(args.GetInt(1));
	wxFileOffset rtn = pThis->GetEntity()->Seek(ofs, mode);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TempFile, Tell)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TempFile, Tell)
{
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileOffset rtn = pThis->GetEntity()->Tell();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TempFile, Write)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*p", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TempFile, Write)
{
#if 0
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int *p = args.GetInt(0);
	size_t n = args.GetSizeT(1);
	bool rtn = pThis->GetEntity()->Write(*p, n);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TempFile, Write_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TempFile, Write_1)
{
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	wxMBConv *conv = (wxMBConv *)(&wxConvLibc);
	if (args.IsValid(1)) conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Write(str, *conv);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TempFile, Commit)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TempFile, Commit)
{
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Commit();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TempFile, Discard)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TempFile, Discard)
{
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Discard();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxTempFile
//----------------------------------------------------------------------------
Object_wx_TempFile::~Object_wx_TempFile()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_TempFile::Clone() const
{
	return NULL;
}

String Object_wx_TempFile::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TempFile:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_TempFile::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(TempFileEmpty);
	Gura_AssignFunction(TempFile);
}

//----------------------------------------------------------------------------
// Class implementation for wxTempFile
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TempFile)
{
	Gura_AssignMethod(wx_TempFile, Open);
	Gura_AssignMethod(wx_TempFile, IsOpened);
	Gura_AssignMethod(wx_TempFile, Length);
	Gura_AssignMethod(wx_TempFile, Seek);
	Gura_AssignMethod(wx_TempFile, Tell);
	Gura_AssignMethod(wx_TempFile, Write);
	Gura_AssignMethod(wx_TempFile, Write_1);
	Gura_AssignMethod(wx_TempFile, Commit);
	Gura_AssignMethod(wx_TempFile, Discard);
}

Gura_ImplementDescendantCreator(wx_TempFile)
{
	return new Object_wx_TempFile((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
