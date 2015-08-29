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
	//Gura::Signal *_pSig;
	Object_wx_TextFile *_pObj;
public:
	inline wx_TextFile() : wxTextFile(), _pObj(nullptr) {}
	inline wx_TextFile(const wxString& strFile) : wxTextFile(strFile), _pObj(nullptr) {}
	~wx_TextFile();
	inline void AssocWithGura(Object_wx_TextFile *pObj) {
		_pObj = pObj;
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_TextFile *pEntity = new wx_TextFile();
	Object_wx_TextFile *pObj = Object_wx_TextFile::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_TextFile(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString strFile = wxString::FromUTF8(arg.GetString(0));
	wx_TextFile *pEntity = new wx_TextFile(strFile);
	Object_wx_TextFile *pObj = Object_wx_TextFile::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_TextFile(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString str = wxString::FromUTF8(arg.GetString(0));
	wxTextFileType *type = (wxTextFileType *)(&typeDefault);
	if (arg.IsValid(1)) type = Object_wx_TextFileType::GetObject(arg, 1)->GetEntity();
	pThis->GetEntity()->AddLine(str, *type);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, Close)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Close();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, Create)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Create();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString strFile = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->Create(strFile);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, Exists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, Exists)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Exists();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, IsOpened)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, IsOpened)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOpened();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GetLineCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, GetLineCount)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetLineCount();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = arg.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->GetLine(n);
	return ReturnValue(env, arg, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GetCurrentLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, GetCurrentLine)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetCurrentLine();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = arg.GetSizeT(0);
	pThis->GetEntity()->GoToLine(n);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, Eof)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, Eof)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Eof();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxTextFileType *type = (wxTextFileType *)(&typeDefault);
	if (arg.IsValid(0)) type = Object_wx_TextFileType::GetObject(arg, 0)->GetEntity();
	char rtn = wxTextFile::GetEOL(*type);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GetFirstLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, GetFirstLine)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetFirstLine();
	return ReturnValue(env, arg, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GetNextLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, GetNextLine)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetNextLine();
	return ReturnValue(env, arg, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GetPrevLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, GetPrevLine)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetPrevLine();
	return ReturnValue(env, arg, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GetLastLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, GetLastLine)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetLastLine();
	return ReturnValue(env, arg, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = arg.GetSizeT(0);
	wxTextFileType rtn = pThis->GetEntity()->GetLineType(n);
	return ReturnValue(env, arg, Value(new Object_wx_TextFileType(new wxTextFileType(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GuessType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, GuessType)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTextFileType rtn = pThis->GetEntity()->GuessType();
	return ReturnValue(env, arg, Value(new Object_wx_TextFileType(new wxTextFileType(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextFile, GetName)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	char rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString str = wxString::FromUTF8(arg.GetString(0));
	size_t n = arg.GetSizeT(1);
	wxTextFileType *type = (wxTextFileType *)(&typeDefault);
	if (arg.IsValid(2)) type = Object_wx_TextFileType::GetObject(arg, 2)->GetEntity();
	pThis->GetEntity()->InsertLine(str, n, *type);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMBConv *conv = (wxMBConv *)(&wxConvUTF8);
	if (arg.IsValid(0)) conv = Object_wx_MBConv::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Open(*conv);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString strFile = wxString::FromUTF8(arg.GetString(0));
	wxMBConv *conv = (wxMBConv *)(&wxConvUTF8);
	if (arg.IsValid(1)) conv = Object_wx_MBConv::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Open(strFile, *conv);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = arg.GetSizeT(0);
	pThis->GetEntity()->RemoveLine(n);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, Clear)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Clear();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTextFileType *typeNew = (wxTextFileType *)(&wxTextFileType_None);
	if (arg.IsValid(0)) typeNew = Object_wx_TextFileType::GetObject(arg, 0)->GetEntity();
	wxMBConv *conv = (wxMBConv *)(&wxConvUTF8);
	if (arg.IsValid(1)) conv = Object_wx_MBConv::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Write(*typeNew, *conv);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
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
