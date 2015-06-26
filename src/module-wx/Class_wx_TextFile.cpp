//----------------------------------------------------------------------------
// wxTextFile
// extracted from textfile.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TextFile: public wxTextFile, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TextFile *_pObj;
public:
	inline wx_TextFile() : wxTextFile(), _sig(nullptr), _pObj(nullptr) {}
	inline wx_TextFile(const wxString& strFile) : wxTextFile(strFile), _sig(nullptr), _pObj(nullptr) {}
	~wx_TextFile();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TextFile *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TextFile::~wx_TextFile()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TextFile::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTextFile
//----------------------------------------------------------------------------
Gura_DeclareFunction(TextFileEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TextFile));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TextFileEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_TextFile *pEntity = new wx_TextFile();
	Object_wx_TextFile *pObj = Object_wx_TextFile::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TextFile(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(TextFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TextFile));
	DeclareArg(env, "strFile", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TextFile)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString strFile = wxString::FromUTF8(args.GetString(0));
	wx_TextFile *pEntity = new wx_TextFile(strFile);
	Object_wx_TextFile *pObj = Object_wx_TextFile::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TextFile(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_TextFile, AddLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_wx_TextFileType, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_TextFile, AddLine)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	wxTextFileType *type = (wxTextFileType *)(&typeDefault);
	if (args.IsValid(1)) type = Object_wx_TextFileType::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->AddLine(str, *type);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, Close)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Close();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, Create)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Create();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, Create_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "strFile", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, Create_1)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString strFile = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Create(strFile);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, Exists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, Exists)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Exists();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, IsOpened)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, IsOpened)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOpened();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, GetLineCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, GetLineCount)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetLineCount();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, GetLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, GetLine)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t n = args.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->GetLine(n);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, GetCurrentLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, GetCurrentLine)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetCurrentLine();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, GoToLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_TextFile, GoToLine)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t n = args.GetSizeT(0);
	pThis->GetEntity()->GoToLine(n);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, Eof)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, Eof)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Eof();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_TextFile, GetEOL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "type", VTYPE_wx_TextFileType, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TextFile, GetEOL)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxTextFileType *type = (wxTextFileType *)(&typeDefault);
	if (args.IsValid(0)) type = Object_wx_TextFileType::GetObject(args, 0)->GetEntity();
	char rtn = wxTextFile::GetEOL(*type);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, GetFirstLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, GetFirstLine)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetFirstLine();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, GetNextLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, GetNextLine)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetNextLine();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, GetPrevLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, GetPrevLine)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetPrevLine();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, GetLastLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, GetLastLine)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetLastLine();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, GetLineType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, GetLineType)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t n = args.GetSizeT(0);
	wxTextFileType rtn = pThis->GetEntity()->GetLineType(n);
	return ReturnValue(env, sig, args, Value(new Object_wx_TextFileType(new wxTextFileType(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, GuessType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, GuessType)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTextFileType rtn = pThis->GetEntity()->GuessType();
	return ReturnValue(env, sig, args, Value(new Object_wx_TextFileType(new wxTextFileType(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, GetName)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, InsertLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_wx_TextFileType, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_TextFile, InsertLine)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	size_t n = args.GetSizeT(1);
	wxTextFileType *type = (wxTextFileType *)(&typeDefault);
	if (args.IsValid(2)) type = Object_wx_TextFileType::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->InsertLine(str, n, *type);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, Open)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, Open)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMBConv *conv = (wxMBConv *)(&wxConvUTF8);
	if (args.IsValid(0)) conv = Object_wx_MBConv::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Open(*conv);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, Open_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "strFile", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, Open_1)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString strFile = wxString::FromUTF8(args.GetString(0));
	wxMBConv *conv = (wxMBConv *)(&wxConvUTF8);
	if (args.IsValid(1)) conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Open(strFile, *conv);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, RemoveLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_TextFile, RemoveLine)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t n = args.GetSizeT(0);
	pThis->GetEntity()->RemoveLine(n);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, Clear)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Clear();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextFile, Write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "typeNew", VTYPE_wx_TextFileType, OCCUR_ZeroOrOnce);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, Write)
{
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTextFileType *typeNew = (wxTextFileType *)(&wxTextFileType_None);
	if (args.IsValid(0)) typeNew = Object_wx_TextFileType::GetObject(args, 0)->GetEntity();
	wxMBConv *conv = (wxMBConv *)(&wxConvUTF8);
	if (args.IsValid(1)) conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Write(*typeNew, *conv);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxTextFile
//----------------------------------------------------------------------------
Object_wx_TextFile::~Object_wx_TextFile()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_TextFile::Clone() const
{
	return nullptr;
}

String Object_wx_TextFile::ToString(bool exprFlag)
{
	String rtn("<wx.TextFile:");
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
// Class implementation for wxTextFile
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextFile)
{
	Gura_AssignFunction(TextFileEmpty);
	Gura_AssignFunction(TextFile);
	Gura_AssignMethod(wx_TextFile, AddLine);
	Gura_AssignMethod(wx_TextFile, Close);
	Gura_AssignMethod(wx_TextFile, Create);
	Gura_AssignMethod(wx_TextFile, Create_1);
	Gura_AssignMethod(wx_TextFile, Exists);
	Gura_AssignMethod(wx_TextFile, IsOpened);
	Gura_AssignMethod(wx_TextFile, GetLineCount);
	Gura_AssignMethod(wx_TextFile, GetLine);
	Gura_AssignMethod(wx_TextFile, GetCurrentLine);
	Gura_AssignMethod(wx_TextFile, GoToLine);
	Gura_AssignMethod(wx_TextFile, Eof);
	Gura_AssignMethod(wx_TextFile, GetEOL);
	Gura_AssignMethod(wx_TextFile, GetFirstLine);
	Gura_AssignMethod(wx_TextFile, GetNextLine);
	Gura_AssignMethod(wx_TextFile, GetPrevLine);
	Gura_AssignMethod(wx_TextFile, GetLastLine);
	Gura_AssignMethod(wx_TextFile, GetLineType);
	Gura_AssignMethod(wx_TextFile, GuessType);
	Gura_AssignMethod(wx_TextFile, GetName);
	Gura_AssignMethod(wx_TextFile, InsertLine);
	Gura_AssignMethod(wx_TextFile, Open);
	Gura_AssignMethod(wx_TextFile, Open_1);
	Gura_AssignMethod(wx_TextFile, RemoveLine);
	Gura_AssignMethod(wx_TextFile, Clear);
	Gura_AssignMethod(wx_TextFile, Write);
}

Gura_ImplementDescendantCreator(wx_TextFile)
{
	return new Object_wx_TextFile((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
