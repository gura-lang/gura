//----------------------------------------------------------------------------
// wxTempFile
// extracted from tempfile.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TempFile: public wxTempFile, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_TempFile *_pObj;
public:
	inline wx_TempFile() : wxTempFile(), _pObj(nullptr) {}
	inline wx_TempFile(const wxString& strName) : wxTempFile(strName), _pObj(nullptr) {}
	~wx_TempFile();
	inline void AssocWithGura(Object_wx_TempFile *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TempFile::~wx_TempFile()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TempFile::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTempFile
//----------------------------------------------------------------------------
Gura_DeclareFunction(TempFileEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TempFile));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TempFileEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_TempFile *pEntity = new wx_TempFile();
	Object_wx_TempFile *pObj = Object_wx_TempFile::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_TempFile(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(TempFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TempFile));
	DeclareArg(env, "strName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TempFile)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString strName = wxString::FromUTF8(arg.GetString(0));
	wx_TempFile *pEntity = new wx_TempFile(strName);
	Object_wx_TempFile *pObj = Object_wx_TempFile::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_TempFile(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_TempFile, Open)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "strName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TempFile, Open)
{
	Signal &sig = env.GetSignal();
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString strName = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->Open(strName);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TempFile, IsOpened)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TempFile, IsOpened)
{
	Signal &sig = env.GetSignal();
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOpened();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TempFile, Length)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TempFile, Length)
{
	Signal &sig = env.GetSignal();
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFileOffset rtn = pThis->GetEntity()->Length();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TempFile, Seek)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ofs", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TempFile, Seek)
{
	Signal &sig = env.GetSignal();
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFileOffset ofs = static_cast<wxFileOffset>(arg.GetInt64(0));
	wxSeekMode mode = wxFromStart;
	if (arg.IsValid(1)) mode = static_cast<wxSeekMode>(arg.GetInt(1));
	wxFileOffset rtn = pThis->GetEntity()->Seek(ofs, mode);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TempFile, Tell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TempFile, Tell)
{
	Signal &sig = env.GetSignal();
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFileOffset rtn = pThis->GetEntity()->Tell();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TempFile, Write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*p", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TempFile, Write)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int *p = arg.GetInt(0);
	size_t n = arg.GetSizeT(1);
	bool rtn = pThis->GetEntity()->Write(*p, n);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TempFile, Write_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TempFile, Write_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString str = wxString::FromUTF8(arg.GetString(0));
	wxMBConv *conv = (wxMBConv *)(&wxConvLibc);
	if (arg.IsValid(1)) conv = Object_wx_MBConv::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Write(str, *conv);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TempFile, Commit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TempFile, Commit)
{
	Signal &sig = env.GetSignal();
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Commit();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TempFile, Discard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TempFile, Discard)
{
	Signal &sig = env.GetSignal();
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Discard();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxTempFile
//----------------------------------------------------------------------------
Object_wx_TempFile::~Object_wx_TempFile()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_TempFile::Clone() const
{
	return nullptr;
}

String Object_wx_TempFile::ToString(bool exprFlag)
{
	String rtn("<wx.TempFile:");
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
// Class implementation for wxTempFile
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TempFile)
{
	Gura_AssignFunction(TempFileEmpty);
	Gura_AssignFunction(TempFile);
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
	return new Object_wx_TempFile((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
