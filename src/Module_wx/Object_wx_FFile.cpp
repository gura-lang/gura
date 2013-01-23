//----------------------------------------------------------------------------
// wxFFile
// extracted from ffile.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FFile: public wxFFile, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FFile *_pObj;
public:
	//inline wx_FFile() : wxFFile(), _sig(NULL), _pObj(NULL) {}
	//inline wx_FFile(const char* filename, const char* mode) : wxFFile(filename, mode), _sig(NULL), _pObj(NULL) {}
	//inline wx_FFile(FILE* fp) : wxFFile(fp), _sig(NULL), _pObj(NULL) {}
	~wx_FFile();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FFile *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FFile::~wx_FFile()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FFile::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFFile
//----------------------------------------------------------------------------
Gura_DeclareFunction(FFileEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FFile));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FFileEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_FFile *pEntity = new wx_FFile();
	Object_wx_FFile *pObj = Object_wx_FFile::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FFile(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(FFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FFile));
	DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FFile)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char filename = args.GetChar(0);
	char mode = wxT("r");
	if (args.IsValid(1)) mode = args.GetChar(1);
	wx_FFile *pEntity = new wx_FFile(filename, mode);
	Object_wx_FFile *pObj = Object_wx_FFile::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FFile(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(FFile_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FFile));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FFile_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_FFile *pEntity = new wx_FFile();
	Object_wx_FFile *pObj = Object_wx_FFile::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FFile(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FFile, Attach)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
#endif
}

Gura_ImplementMethod(wx_FFile, Attach)
{
#if 0
	Object_wx_FFile *pSelf = Object_wx_FFile::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Attach();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FFile, Close)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FFile, Close)
{
#if 0
	Object_wx_FFile *pSelf = Object_wx_FFile::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->Close();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FFile, Detach)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, Detach)
{
#if 0
	Object_wx_FFile *pSelf = Object_wx_FFile::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Detach();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FFile, fp)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FFile, fp)
{
	Object_wx_FFile *pSelf = Object_wx_FFile::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_FFile, Eof)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FFile, Eof)
{
	Object_wx_FFile *pSelf = Object_wx_FFile::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->Eof();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FFile, Flush)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FFile, Flush)
{
#if 0
	Object_wx_FFile *pSelf = Object_wx_FFile::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->Flush();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FFile, GetKind)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FFile, GetKind)
{
#if 0
	Object_wx_FFile *pSelf = Object_wx_FFile::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFileKind rtn = pSelf->GetEntity()->GetKind();
	return ReturnValue(env, sig, args, Value(new Object_wx_FileKind(new wxFileKind(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FFile, IsOpened)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FFile, IsOpened)
{
	Object_wx_FFile *pSelf = Object_wx_FFile::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsOpened();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FFile, Length)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FFile, Length)
{
	Object_wx_FFile *pSelf = Object_wx_FFile::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFileOffset rtn = pSelf->GetEntity()->Length();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FFile, Open)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FFile, Open)
{
#if 0
	Object_wx_FFile *pSelf = Object_wx_FFile::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	char filename = args.GetChar(0);
	char mode = wxT("r");
	if (args.IsValid(1)) mode = args.GetChar(1);
	bool rtn = pSelf->GetEntity()->Open(filename, mode);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FFile, Read)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FFile, Read)
{
#if 0
	Object_wx_FFile *pSelf = Object_wx_FFile::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int buffer = args.GetInt(0);
	size_t count = args.GetSizeT(1);
	size_t rtn = pSelf->GetEntity()->Read(buffer, count);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FFile, ReadAll)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FFile, ReadAll)
{
#if 0
	Object_wx_FFile *pSelf = Object_wx_FFile::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	wxMBConv *conv = (wxMBConv *)(&wxConvUTF8);
	if (args.IsValid(1)) conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->ReadAll(str, *conv);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FFile, Seek)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ofs", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FFile, Seek)
{
#if 0
	Object_wx_FFile *pSelf = Object_wx_FFile::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFileOffset ofs = static_cast<wxFileOffset>(args.GetInt64(0));
	wxSeekMode mode = wxFromStart;
	if (args.IsValid(1)) mode = static_cast<wxSeekMode>(args.GetInt(1));
	bool rtn = pSelf->GetEntity()->Seek(ofs, mode);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FFile, SeekEnd)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ofs", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FFile, SeekEnd)
{
#if 0
	Object_wx_FFile *pSelf = Object_wx_FFile::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFileOffset ofs = 0;
	if (args.IsValid(0)) ofs = static_cast<wxFileOffset>(args.GetInt64(0));
	bool rtn = pSelf->GetEntity()->SeekEnd(ofs);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FFile, Tell)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FFile, Tell)
{
	Object_wx_FFile *pSelf = Object_wx_FFile::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFileOffset rtn = pSelf->GetEntity()->Tell();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FFile, Write)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FFile, Write)
{
#if 0
	Object_wx_FFile *pSelf = Object_wx_FFile::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int buffer = args.GetInt(0);
	size_t count = args.GetSizeT(1);
	size_t rtn = pSelf->GetEntity()->Write(buffer, count);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FFile, Write_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "s", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FFile, Write_1)
{
#if 0
	Object_wx_FFile *pSelf = Object_wx_FFile::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString s = wxString::FromUTF8(args.GetString(0));
	wxMBConv *conv = (wxMBConv *)(&wxConvUTF8);
	if (args.IsValid(1)) conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->Write(s, *conv);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxFFile
//----------------------------------------------------------------------------
Object_wx_FFile::~Object_wx_FFile()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_FFile::Clone() const
{
	return NULL;
}

String Object_wx_FFile::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.FFile:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_FFile::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(FFileEmpty);
	Gura_AssignFunction(FFile);
	Gura_AssignFunction(FFile_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxFFile
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FFile)
{
	Gura_AssignMethod(wx_FFile, Attach);
	Gura_AssignMethod(wx_FFile, Close);
	Gura_AssignMethod(wx_FFile, Detach);
	Gura_AssignMethod(wx_FFile, fp);
	Gura_AssignMethod(wx_FFile, Eof);
	Gura_AssignMethod(wx_FFile, Flush);
	Gura_AssignMethod(wx_FFile, GetKind);
	Gura_AssignMethod(wx_FFile, IsOpened);
	Gura_AssignMethod(wx_FFile, Length);
	Gura_AssignMethod(wx_FFile, Open);
	Gura_AssignMethod(wx_FFile, Read);
	Gura_AssignMethod(wx_FFile, ReadAll);
	Gura_AssignMethod(wx_FFile, Seek);
	Gura_AssignMethod(wx_FFile, SeekEnd);
	Gura_AssignMethod(wx_FFile, Tell);
	Gura_AssignMethod(wx_FFile, Write);
	Gura_AssignMethod(wx_FFile, Write_1);
}

Gura_ImplementDescendantCreator(wx_FFile)
{
	return new Object_wx_FFile((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
