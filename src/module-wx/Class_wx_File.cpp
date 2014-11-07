//----------------------------------------------------------------------------
// wxFile
// extracted from file.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_File: public wxFile, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_File *_pObj;
public:
	inline wx_File() : wxFile(), _sig(NULL), _pObj(NULL) {}
	inline wx_File(const wxString& filename, wxFile::OpenMode mode) : wxFile(filename, mode), _sig(NULL), _pObj(NULL) {}
	//inline wx_File(int fd) : wxFile(fd), _sig(NULL), _pObj(NULL) {}
	~wx_File();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_File *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_File::~wx_File()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_File::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFile
//----------------------------------------------------------------------------
Gura_DeclareFunction(File)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_File));
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_wx_File, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(File)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_File *pEntity = NULL;
	if (args.IsValid(0)) {
		wxString filename = wxString::FromUTF8(args.GetString(0));
		wxFile::OpenMode mode = wxFile::read;
		if (args.IsValid(1)) mode = static_cast<wxFile::OpenMode>(args.GetInt(1));
		pEntity = new wx_File(filename, mode);
	} else {
		pEntity = new wx_File();
	}
	Object_wx_File *pObj = Object_wx_File::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_File(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}


Gura_DeclareClassMethod(wx_File, Access)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_File, Access)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxFile::OpenMode mode = static_cast<wxFile::OpenMode>(args.GetInt(1));
	bool rtn = wxFile::Access(name, mode);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_File, Attach)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "fd", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_File, Attach)
{
#if 0
	Object_wx_File *pThis = Object_wx_File::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int fd = args.GetInt(0);
	pThis->GetEntity()->Attach(fd);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_File, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_File, Close)
{
	Object_wx_File *pThis = Object_wx_File::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Close();
	return Value::Null;
}

Gura_DeclareMethod(wx_File, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "overwrite", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "access", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_File, Create)
{
	Object_wx_File *pThis = Object_wx_File::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool overwrite = false;
	if (args.IsValid(1)) overwrite = args.GetBoolean(1);
	int access = wxS_DEFAULT;
	if (args.IsValid(2)) access = args.GetInt(2);
	bool rtn = pThis->GetEntity()->Create(filename, overwrite, access);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_File, Detach)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_File, Detach)
{
	Object_wx_File *pThis = Object_wx_File::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Detach();
	return Value::Null;
}

Gura_DeclareMethod(wx_File, fd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_File, fd)
{
	Object_wx_File *pThis = Object_wx_File::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->fd();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_File, Eof)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_File, Eof)
{
	Object_wx_File *pThis = Object_wx_File::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Eof();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_File, Exists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_File, Exists)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxFile::Exists(filename);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_File, Flush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_File, Flush)
{
	Object_wx_File *pThis = Object_wx_File::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Flush();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_File, GetKind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_File, GetKind)
{
	Object_wx_File *pThis = Object_wx_File::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileKind rtn = pThis->GetEntity()->GetKind();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_File, IsOpened)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_File, IsOpened)
{
	Object_wx_File *pThis = Object_wx_File::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOpened();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_File, Length)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_File, Length)
{
	Object_wx_File *pThis = Object_wx_File::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileOffset rtn = pThis->GetEntity()->Length();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_File, Open)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_wx_File, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_File, Open)
{
	Object_wx_File *pThis = Object_wx_File::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxFile::OpenMode mode = wxFile::read;
	if (args.IsValid(1)) mode = static_cast<wxFile::OpenMode>(args.GetInt(1));
	bool rtn = pThis->GetEntity()->Open(filename, mode);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_File, Read)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_File, Read)
{
#if 0
	Object_wx_File *pThis = Object_wx_File::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int buffer = args.GetInt(0);
	size_t count = args.GetSizeT(1);
	size_t rtn = pThis->GetEntity()->Read(buffer, count);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_File, Seek)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ofs", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_File, Seek)
{
	Object_wx_File *pThis = Object_wx_File::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileOffset ofs = static_cast<wxFileOffset>(args.GetInt64(0));
	wxSeekMode mode = wxFromStart;
	if (args.IsValid(1)) mode = static_cast<wxSeekMode>(args.GetInt(1));
	wxFileOffset rtn = pThis->GetEntity()->Seek(ofs, mode);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_File, SeekEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ofs", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_File, SeekEnd)
{
	Object_wx_File *pThis = Object_wx_File::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileOffset ofs = 0;
	if (args.IsValid(0)) ofs = static_cast<wxFileOffset>(args.GetInt64(0));
	wxFileOffset rtn = pThis->GetEntity()->SeekEnd(ofs);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_File, Tell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_File, Tell)
{
	Object_wx_File *pThis = Object_wx_File::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileOffset rtn = pThis->GetEntity()->Tell();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_File, Write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buffer", VTYPE_binary, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_File, Write)
{
	Object_wx_File *pThis = Object_wx_File::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const Binary &binary = args.GetBinary(0);
	const void *buffer = binary.data();
	size_t count = binary.size();
	size_t rtn = pThis->GetEntity()->Write(buffer, count);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_File, Write_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "s", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_File, Write_1)
{
#if 0
	Object_wx_File *pThis = Object_wx_File::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString s = wxString::FromUTF8(args.GetString(0));
	wxMBConv *conv = (wxMBConv *)(&wxConvUTF8);
	if (args.IsValid(1)) conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Write(s, *conv);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxFile
//----------------------------------------------------------------------------
Object_wx_File::~Object_wx_File()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_File::Clone() const
{
	return NULL;
}

String Object_wx_File::ToString(bool exprFlag)
{
	String rtn("<wx.File:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxFile
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_File)
{
	Gura_AssignFunction(File);
	Gura_AssignClassValue(read, wxFile::read);
	Gura_AssignClassValue(write, wxFile::write);
	Gura_AssignClassValue(read_write, wxFile::read_write);
	Gura_AssignClassValue(write_append, wxFile::write_append);
	Gura_AssignClassValue(write_excl, wxFile::write_excl);
	Gura_AssignMethod(wx_File, Access);
	Gura_AssignMethod(wx_File, Attach);
	Gura_AssignMethod(wx_File, Close);
	Gura_AssignMethod(wx_File, Create);
	Gura_AssignMethod(wx_File, Detach);
	Gura_AssignMethod(wx_File, fd);
	Gura_AssignMethod(wx_File, Eof);
	Gura_AssignMethod(wx_File, Exists);
	Gura_AssignMethod(wx_File, Flush);
	Gura_AssignMethod(wx_File, GetKind);
	Gura_AssignMethod(wx_File, IsOpened);
	Gura_AssignMethod(wx_File, Length);
	Gura_AssignMethod(wx_File, Open);
	Gura_AssignMethod(wx_File, Read);
	Gura_AssignMethod(wx_File, Seek);
	Gura_AssignMethod(wx_File, SeekEnd);
	Gura_AssignMethod(wx_File, Tell);
	Gura_AssignMethod(wx_File, Write);
	Gura_AssignMethod(wx_File, Write_1);
}

Gura_ImplementDescendantCreator(wx_File)
{
	return new Object_wx_File((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
