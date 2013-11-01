//----------------------------------------------------------------------------
// wxFileName
// extracted from filename.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FileName: public wxFileName, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FileName *_pObj;
public:
	//inline wx_FileName() : wxFileName(), _sig(NULL), _pObj(NULL) {}
	//inline wx_FileName(const wxFileName& filename) : wxFileName(filename), _sig(NULL), _pObj(NULL) {}
	//inline wx_FileName(const wxString& fullpath, wxPathFormat format) : wxFileName(fullpath, format), _sig(NULL), _pObj(NULL) {}
	//inline wx_FileName(const wxString& path, const wxString& name, wxPathFormat format) : wxFileName(path, name, format), _sig(NULL), _pObj(NULL) {}
	//inline wx_FileName(const wxString& path, const wxString& name, const wxString& ext, wxPathFormat format) : wxFileName(path, name, ext, format), _sig(NULL), _pObj(NULL) {}
	//inline wx_FileName(const wxString& volume, const wxString& path, const wxString& name, const wxString& ext, wxPathFormat format) : wxFileName(volume, path, name, ext, format), _sig(NULL), _pObj(NULL) {}
	~wx_FileName();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FileName *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FileName::~wx_FileName()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FileName::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFileName
//----------------------------------------------------------------------------
Gura_DeclareFunction(FileNameEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FileName));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FileNameEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_FileName *pEntity = new wx_FileName();
	Object_wx_FileName *pObj = Object_wx_FileName::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FileName(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareFunction(FileName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FileName));
	DeclareArg(env, "filename", VTYPE_wx_FileName, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FileName)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxFileName *filename = Object_wx_FileName::GetObject(args, 0)->GetEntity();
	wx_FileName *pEntity = new wx_FileName(*filename);
	Object_wx_FileName *pObj = Object_wx_FileName::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FileName(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareFunction(FileName_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FileName));
	DeclareArg(env, "fullpath", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FileName_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString fullpath = wxString::FromUTF8(args.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(1)) format = static_cast<wxPathFormat>(args.GetInt(1));
	wx_FileName *pEntity = new wx_FileName(fullpath, format);
	Object_wx_FileName *pObj = Object_wx_FileName::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FileName(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareFunction(FileName_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FileName));
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FileName_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString path = wxString::FromUTF8(args.GetString(0));
	wxString name = wxString::FromUTF8(args.GetString(1));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(2)) format = static_cast<wxPathFormat>(args.GetInt(2));
	wx_FileName *pEntity = new wx_FileName(path, name, format);
	Object_wx_FileName *pObj = Object_wx_FileName::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FileName(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareFunction(FileName_3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FileName));
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "ext", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FileName_3)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString path = wxString::FromUTF8(args.GetString(0));
	wxString name = wxString::FromUTF8(args.GetString(1));
	wxString ext = wxString::FromUTF8(args.GetString(2));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(3)) format = static_cast<wxPathFormat>(args.GetInt(3));
	wx_FileName *pEntity = new wx_FileName(path, name, ext, format);
	Object_wx_FileName *pObj = Object_wx_FileName::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FileName(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareFunction(FileName_4)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FileName));
	DeclareArg(env, "volume", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "ext", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FileName_4)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString volume = wxString::FromUTF8(args.GetString(0));
	wxString path = wxString::FromUTF8(args.GetString(1));
	wxString name = wxString::FromUTF8(args.GetString(2));
	wxString ext = wxString::FromUTF8(args.GetString(3));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(4)) format = static_cast<wxPathFormat>(args.GetInt(4));
	wx_FileName *pEntity = new wx_FileName(volume, path, name, ext, format);
	Object_wx_FileName *pObj = Object_wx_FileName::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FileName(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_FileName, AppendDir)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_FileName, AppendDir)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->AppendDir(dir);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, Assign)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "filepath", VTYPE_wx_FileName, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_FileName, Assign)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileName *filepath = Object_wx_FileName::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Assign(*filepath);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, Assign_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "fullpath", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_FileName, Assign_1)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString fullpath = wxString::FromUTF8(args.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(1)) format = static_cast<wxPathFormat>(args.GetInt(1));
	pThis->GetEntity()->Assign(fullpath, format);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, Assign_2)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "volume", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "ext", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "hasExt", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_FileName, Assign_2)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString volume = wxString::FromUTF8(args.GetString(0));
	wxString path = wxString::FromUTF8(args.GetString(1));
	wxString name = wxString::FromUTF8(args.GetString(2));
	wxString ext = wxString::FromUTF8(args.GetString(3));
	bool hasExt = args.GetBoolean(4);
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(5)) format = static_cast<wxPathFormat>(args.GetInt(5));
	pThis->GetEntity()->Assign(volume, path, name, ext, hasExt, format);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, Assign_3)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "volume", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "ext", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_FileName, Assign_3)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString volume = wxString::FromUTF8(args.GetString(0));
	wxString path = wxString::FromUTF8(args.GetString(1));
	wxString name = wxString::FromUTF8(args.GetString(2));
	wxString ext = wxString::FromUTF8(args.GetString(3));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(4)) format = static_cast<wxPathFormat>(args.GetInt(4));
	pThis->GetEntity()->Assign(volume, path, name, ext, format);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, Assign_4)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_FileName, Assign_4)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	wxString name = wxString::FromUTF8(args.GetString(1));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(2)) format = static_cast<wxPathFormat>(args.GetInt(2));
	pThis->GetEntity()->Assign(path, name, format);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, Assign_5)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "ext", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_FileName, Assign_5)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	wxString name = wxString::FromUTF8(args.GetString(1));
	wxString ext = wxString::FromUTF8(args.GetString(2));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(3)) format = static_cast<wxPathFormat>(args.GetInt(3));
	pThis->GetEntity()->Assign(path, name, ext, format);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, AssignCwd)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "volume", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementClassMethod(wx_FileName, AssignCwd)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString volume = wxEmptyString;
	if (args.IsValid(0)) volume = wxString::FromUTF8(args.GetString(0));
	wxFileName::AssignCwd(volume);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, AssignDir)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_FileName, AssignDir)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(1)) format = static_cast<wxPathFormat>(args.GetInt(1));
	pThis->GetEntity()->AssignDir(dir, format);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, AssignHomeDir)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, AssignHomeDir)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->AssignHomeDir();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, AssignTempFileName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "prefix", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "fileTemp", VTYPE_wx_File, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_FileName, AssignTempFileName)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString prefix = wxString::FromUTF8(args.GetString(0));
	wxFile *fileTemp = (wxFile *)(NULL);
	if (args.IsValid(1)) fileTemp = Object_wx_File::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->AssignTempFileName(prefix, fileTemp);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, Clear)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, Clear)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Clear();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, SetClearExt)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, SetClearExt)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->SetClearExt();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, CreateTempFileName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "prefix", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "fileTemp", VTYPE_wx_File, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, CreateTempFileName)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString prefix = wxString::FromUTF8(args.GetString(0));
	wxFile *fileTemp = (wxFile *)(NULL);
	if (args.IsValid(1)) fileTemp = Object_wx_File::GetObject(args, 1)->GetEntity();
	wxString rtn = wxFileName::CreateTempFileName(prefix, fileTemp);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, DirExists)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, DirExists)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->DirExists();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, DirExists_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, DirExists_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxFileName::DirExists(dir);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_FileName, DirName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, DirName)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString dir = wxString::FromUTF8(args.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(1)) format = static_cast<wxPathFormat>(args.GetInt(1));
	wxFileName rtn = wxFileName::DirName(dir, format);
	return ReturnValue(env, sig, args, Value(new Object_wx_FileName(new wxFileName(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, FileExists)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, FileExists)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->FileExists();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, FileExists_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, FileExists_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString file = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxFileName::FileExists(file);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_FileName, FileName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, FileName)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString file = wxString::FromUTF8(args.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(1)) format = static_cast<wxPathFormat>(args.GetInt(1));
	wxFileName rtn = wxFileName::FileName(file, format);
	return ReturnValue(env, sig, args, Value(new Object_wx_FileName(new wxFileName(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, GetCwd)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "volume", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetCwd)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString volume = wxT("");
	if (args.IsValid(0)) volume = wxString::FromUTF8(args.GetString(0));
	wxString rtn = wxFileName::GetCwd(volume);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, GetDirCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetDirCount)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetDirCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, GetDirs)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetDirs)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxArrayString rtn = pThis->GetEntity()->GetDirs();
	return ReturnValue(env, sig, args, ArrayStringToValue(env, rtn));
}

Gura_DeclareMethod(wx_FileName, GetExt)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetExt)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetExt();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_FileName, GetForbiddenChars)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetForbiddenChars)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(0)) format = static_cast<wxPathFormat>(args.GetInt(0));
	wxString rtn = wxFileName::GetForbiddenChars(format);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, GetFormat)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetFormat)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(0)) format = static_cast<wxPathFormat>(args.GetInt(0));
	wxPathFormat rtn = wxFileName::GetFormat(format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, GetFullName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetFullName)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetFullName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileName, GetFullPath)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetFullPath)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(0)) format = static_cast<wxPathFormat>(args.GetInt(0));
	wxString rtn = pThis->GetEntity()->GetFullPath(format);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_FileName, GetHomeDir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetHomeDir)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString rtn = wxFileName::GetHomeDir();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, GetLongPath)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetLongPath)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetLongPath();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileName, GetModificationTime)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetModificationTime)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime rtn = pThis->GetEntity()->GetModificationTime();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_FileName, GetName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetName)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileName, GetPath)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetPath)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int flags = wxPATH_GET_VOLUME;
	if (args.IsValid(0)) flags = args.GetInt(0);
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(1)) format = static_cast<wxPathFormat>(args.GetInt(1));
	wxString rtn = pThis->GetEntity()->GetPath(flags, format);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_FileName, GetPathSeparator)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetPathSeparator)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(0)) format = static_cast<wxPathFormat>(args.GetInt(0));
	wxChar rtn = wxFileName::GetPathSeparator(format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, GetPathSeparators)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetPathSeparators)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(0)) format = static_cast<wxPathFormat>(args.GetInt(0));
	wxString rtn = wxFileName::GetPathSeparators(format);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, GetPathTerminators)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetPathTerminators)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(0)) format = static_cast<wxPathFormat>(args.GetInt(0));
	wxString rtn = wxFileName::GetPathTerminators(format);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, GetPathWithSep)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetPathWithSep)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(0)) format = static_cast<wxPathFormat>(args.GetInt(0));
	wxString rtn = pThis->GetEntity()->GetPathWithSep(format);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileName, GetShortPath)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetShortPath)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetShortPath();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileName, GetSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetSize)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxULongLong rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_ULongLong(new wxULongLong(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, GetSize_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetSize_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxULongLong rtn = wxFileName::GetSize(filename);
	return ReturnValue(env, sig, args, Value(new Object_wx_ULongLong(new wxULongLong(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, GetHumanReadableSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "failmsg", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "precision", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetHumanReadableSize)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString failmsg = wxT("Not available");
	if (args.IsValid(0)) failmsg = wxString::FromUTF8(args.GetString(0));
	int precision = 1;
	if (args.IsValid(1)) precision = args.GetInt(1);
	wxString rtn = pThis->GetEntity()->GetHumanReadableSize(failmsg, precision);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, GetHumanReadableSize_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "bytes", VTYPE_wx_ULongLong, OCCUR_Once);
	DeclareArg(env, "nullsize", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "precision", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetHumanReadableSize_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxULongLong *bytes = Object_wx_ULongLong::GetObject(args, 0)->GetEntity();
	wxString nullsize = wxT("Not available");
	if (args.IsValid(1)) nullsize = wxString::FromUTF8(args.GetString(1));
	int precision = 1;
	if (args.IsValid(2)) precision = args.GetInt(2);
	wxString rtn = wxFileName::GetHumanReadableSize(*bytes, nullsize, precision);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, GetTempDir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetTempDir)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString rtn = wxFileName::GetTempDir();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, GetTimes)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dtAccess", VTYPE_wx_DateTime, OCCUR_Once);
	DeclareArg(env, "dtMod", VTYPE_wx_DateTime, OCCUR_Once);
	DeclareArg(env, "dtCreate", VTYPE_wx_DateTime, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetTimes)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime *dtAccess = Object_wx_DateTime::GetObject(args, 0)->GetEntity();
	wxDateTime *dtMod = Object_wx_DateTime::GetObject(args, 1)->GetEntity();
	wxDateTime *dtCreate = Object_wx_DateTime::GetObject(args, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->GetTimes(dtAccess, dtMod, dtCreate);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, GetVolume)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetVolume)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetVolume();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_FileName, GetVolumeSeparator)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetVolumeSeparator)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(0)) format = static_cast<wxPathFormat>(args.GetInt(0));
	wxString rtn = wxFileName::GetVolumeSeparator(format);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, HasExt)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, HasExt)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasExt();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, HasName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, HasName)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasName();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, HasVolume)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, HasVolume)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasVolume();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, InsertDir)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "before", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_FileName, InsertDir)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t before = args.GetSizeT(0);
	wxString dir = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->InsertDir(before, dir);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, IsAbsolute)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, IsAbsolute)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(0)) format = static_cast<wxPathFormat>(args.GetInt(0));
	bool rtn = pThis->GetEntity()->IsAbsolute(format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, IsCaseSensitive)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, IsCaseSensitive)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(0)) format = static_cast<wxPathFormat>(args.GetInt(0));
	bool rtn = wxFileName::IsCaseSensitive(format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, IsDirReadable)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, IsDirReadable)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsDirReadable();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, IsDirReadable_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, IsDirReadable_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxFileName::IsDirReadable(dir);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, IsDirWritable)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, IsDirWritable)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsDirWritable();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, IsDirWritable_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, IsDirWritable_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxFileName::IsDirWritable(dir);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, IsFileExecutable)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, IsFileExecutable)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsFileExecutable();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, IsFileExecutable_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, IsFileExecutable_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString file = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxFileName::IsFileExecutable(file);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, IsFileReadable)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, IsFileReadable)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsFileReadable();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, IsFileReadable_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, IsFileReadable_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString file = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxFileName::IsFileReadable(file);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, IsFileWritable)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, IsFileWritable)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsFileWritable();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, IsFileWritable_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, IsFileWritable_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString file = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxFileName::IsFileWritable(file);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, IsOk)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_FileName, IsPathSeparator)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, IsPathSeparator)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(1)) format = static_cast<wxPathFormat>(args.GetInt(1));
	bool rtn = wxFileName::IsPathSeparator(ch, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, IsRelative)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, IsRelative)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(0)) format = static_cast<wxPathFormat>(args.GetInt(0));
	bool rtn = pThis->GetEntity()->IsRelative(format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, IsDir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, IsDir)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsDir();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_FileName, MacFindDefaultTypeAndCreator)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ext", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "creator", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, MacFindDefaultTypeAndCreator)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString ext = wxString::FromUTF8(args.GetString(0));
	wxUint32 type = static_cast<wxUint32>(args.GetULong(1));
	wxUint32 creator = static_cast<wxUint32>(args.GetULong(2));
	bool rtn = wxFileName::MacFindDefaultTypeAndCreator(ext, type, creator);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, MacRegisterDefaultTypeAndCreator)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "ext", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "creator", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementClassMethod(wx_FileName, MacRegisterDefaultTypeAndCreator)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString ext = wxString::FromUTF8(args.GetString(0));
	wxUint32 type = static_cast<wxUint32>(args.GetULong(1));
	wxUint32 creator = static_cast<wxUint32>(args.GetULong(2));
	wxFileName::MacRegisterDefaultTypeAndCreator(ext, type, creator);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, MacSetDefaultTypeAndCreator)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, MacSetDefaultTypeAndCreator)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->MacSetDefaultTypeAndCreator();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, MakeAbsolute)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "cwd", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, MakeAbsolute)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString cwd = wxEmptyString;
	if (args.IsValid(0)) cwd = wxString::FromUTF8(args.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(1)) format = static_cast<wxPathFormat>(args.GetInt(1));
	bool rtn = pThis->GetEntity()->MakeAbsolute(cwd, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, MakeRelativeTo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "pathBase", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, MakeRelativeTo)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString pathBase = wxEmptyString;
	if (args.IsValid(0)) pathBase = wxString::FromUTF8(args.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(1)) format = static_cast<wxPathFormat>(args.GetInt(1));
	bool rtn = pThis->GetEntity()->MakeRelativeTo(pathBase, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, Mkdir)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "perm", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, Mkdir)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int perm = 0777;
	if (args.IsValid(0)) perm = args.GetInt(0);
	int flags = 0;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = pThis->GetEntity()->Mkdir(perm, flags);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, Mkdir_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "perm", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, Mkdir_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString dir = wxString::FromUTF8(args.GetString(0));
	int perm = 0777;
	if (args.IsValid(1)) perm = args.GetInt(1);
	int flags = 0;
	if (args.IsValid(2)) flags = args.GetInt(2);
	bool rtn = wxFileName::Mkdir(dir, perm, flags);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, Normalize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "cwd", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, Normalize)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int flags = wxPATH_NORM_ALL;
	if (args.IsValid(0)) flags = args.GetInt(0);
	wxString cwd = wxEmptyString;
	if (args.IsValid(1)) cwd = wxString::FromUTF8(args.GetString(1));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(2)) format = static_cast<wxPathFormat>(args.GetInt(2));
	bool rtn = pThis->GetEntity()->Normalize(flags, cwd, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, PrependDir)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_FileName, PrependDir)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->PrependDir(dir);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, RemoveDir)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_FileName, RemoveDir)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t pos = args.GetSizeT(0);
	pThis->GetEntity()->RemoveDir(pos);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, RemoveLastDir)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, RemoveLastDir)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->RemoveLastDir();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, Rmdir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, Rmdir)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Rmdir();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, Rmdir_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, Rmdir_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString dir = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxFileName::Rmdir(dir);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, SameAs)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filepath", VTYPE_wx_FileName, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, SameAs)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileName *filepath = Object_wx_FileName::GetObject(args, 0)->GetEntity();
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(1)) format = static_cast<wxPathFormat>(args.GetInt(1));
	bool rtn = pThis->GetEntity()->SameAs(*filepath, format);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, SetCwd)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, SetCwd)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->SetCwd();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, SetCwd_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "cwd", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, SetCwd_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString cwd = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxFileName::SetCwd(cwd);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, SetExt)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "ext", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_FileName, SetExt)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString ext = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetExt(ext);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, SetEmptyExt)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, SetEmptyExt)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->SetEmptyExt();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, SetFullName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "fullname", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_FileName, SetFullName)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString fullname = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetFullName(fullname);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, SetName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_FileName, SetName)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetName(name);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, SetTimes)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "dtAccess", VTYPE_wx_DateTime, OCCUR_Once);
	DeclareArg(env, "dtMod", VTYPE_wx_DateTime, OCCUR_Once);
	DeclareArg(env, "dtCreate", VTYPE_wx_DateTime, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, SetTimes)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime *dtAccess = Object_wx_DateTime::GetObject(args, 0)->GetEntity();
	wxDateTime *dtMod = Object_wx_DateTime::GetObject(args, 1)->GetEntity();
	wxDateTime *dtCreate = Object_wx_DateTime::GetObject(args, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->SetTimes(dtAccess, dtMod, dtCreate);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, SetVolume)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "volume", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_FileName, SetVolume)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString volume = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetVolume(volume);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, SplitPath)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "fullpath", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "volume", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "ext", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "*hasExt", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementClassMethod(wx_FileName, SplitPath)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString fullpath = wxString::FromUTF8(args.GetString(0));
	wxString volume = wxString::FromUTF8(args.GetString(1));
	wxString path = wxString::FromUTF8(args.GetString(2));
	wxString name = wxString::FromUTF8(args.GetString(3));
	wxString ext = wxString::FromUTF8(args.GetString(4));
	bool *hasExt = NULL;
	if (args.IsValid(5)) *hasExt = args.GetBoolean(5);
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(6)) format = static_cast<wxPathFormat>(args.GetInt(6));
	wxFileName::SplitPath(fullpath, volume, path, name, ext, *hasExt, format);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, SplitPath_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "fullpath", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "volume", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "ext", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementClassMethod(wx_FileName, SplitPath_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString fullpath = wxString::FromUTF8(args.GetString(0));
	wxString volume = wxString::FromUTF8(args.GetString(1));
	wxString path = wxString::FromUTF8(args.GetString(2));
	wxString name = wxString::FromUTF8(args.GetString(3));
	wxString ext = wxString::FromUTF8(args.GetString(4));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(5)) format = static_cast<wxPathFormat>(args.GetInt(5));
	wxFileName::SplitPath(fullpath, volume, path, name, ext, format);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, SplitPath_2)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "fullpath", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "ext", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementClassMethod(wx_FileName, SplitPath_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString fullpath = wxString::FromUTF8(args.GetString(0));
	wxString path = wxString::FromUTF8(args.GetString(1));
	wxString name = wxString::FromUTF8(args.GetString(2));
	wxString ext = wxString::FromUTF8(args.GetString(3));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(4)) format = static_cast<wxPathFormat>(args.GetInt(4));
	wxFileName::SplitPath(fullpath, path, name, ext, format);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileName, SplitVolume)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "fullpath", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "volume", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementClassMethod(wx_FileName, SplitVolume)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString fullpath = wxString::FromUTF8(args.GetString(0));
	wxString volume = wxString::FromUTF8(args.GetString(1));
	wxString path = wxString::FromUTF8(args.GetString(2));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(3)) format = static_cast<wxPathFormat>(args.GetInt(3));
	wxFileName::SplitVolume(fullpath, volume, path, format);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileName, Touch)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, Touch)
{
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Touch();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxFileName
//----------------------------------------------------------------------------
Object_wx_FileName::~Object_wx_FileName()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_FileName::Clone() const
{
	return NULL;
}

String Object_wx_FileName::ToString(bool exprFlag)
{
	String rtn("<wx.FileName:");
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
// Class implementation for wxFileName
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileName)
{
	Gura_AssignFunction(FileNameEmpty);
	Gura_AssignFunction(FileName);
	Gura_AssignFunction(FileName_1);
	Gura_AssignFunction(FileName_2);
	Gura_AssignFunction(FileName_3);
	Gura_AssignFunction(FileName_4);
	Gura_AssignMethod(wx_FileName, AppendDir);
	Gura_AssignMethod(wx_FileName, Assign);
	Gura_AssignMethod(wx_FileName, Assign_1);
	Gura_AssignMethod(wx_FileName, Assign_2);
	Gura_AssignMethod(wx_FileName, Assign_3);
	Gura_AssignMethod(wx_FileName, Assign_4);
	Gura_AssignMethod(wx_FileName, Assign_5);
	Gura_AssignMethod(wx_FileName, AssignCwd);
	Gura_AssignMethod(wx_FileName, AssignDir);
	Gura_AssignMethod(wx_FileName, AssignHomeDir);
	Gura_AssignMethod(wx_FileName, AssignTempFileName);
	Gura_AssignMethod(wx_FileName, Clear);
	Gura_AssignMethod(wx_FileName, SetClearExt);
	Gura_AssignMethod(wx_FileName, CreateTempFileName);
	Gura_AssignMethod(wx_FileName, DirExists);
	Gura_AssignMethod(wx_FileName, DirExists_1);
	Gura_AssignMethod(wx_FileName, DirName);
	Gura_AssignMethod(wx_FileName, FileExists);
	Gura_AssignMethod(wx_FileName, FileExists_1);
	Gura_AssignMethod(wx_FileName, FileName);
	Gura_AssignMethod(wx_FileName, GetCwd);
	Gura_AssignMethod(wx_FileName, GetDirCount);
	Gura_AssignMethod(wx_FileName, GetDirs);
	Gura_AssignMethod(wx_FileName, GetExt);
	Gura_AssignMethod(wx_FileName, GetForbiddenChars);
	Gura_AssignMethod(wx_FileName, GetFormat);
	Gura_AssignMethod(wx_FileName, GetFullName);
	Gura_AssignMethod(wx_FileName, GetFullPath);
	Gura_AssignMethod(wx_FileName, GetHomeDir);
	Gura_AssignMethod(wx_FileName, GetLongPath);
	Gura_AssignMethod(wx_FileName, GetModificationTime);
	Gura_AssignMethod(wx_FileName, GetName);
	Gura_AssignMethod(wx_FileName, GetPath);
	Gura_AssignMethod(wx_FileName, GetPathSeparator);
	Gura_AssignMethod(wx_FileName, GetPathSeparators);
	Gura_AssignMethod(wx_FileName, GetPathTerminators);
	Gura_AssignMethod(wx_FileName, GetPathWithSep);
	Gura_AssignMethod(wx_FileName, GetShortPath);
	Gura_AssignMethod(wx_FileName, GetSize);
	Gura_AssignMethod(wx_FileName, GetSize_1);
	Gura_AssignMethod(wx_FileName, GetHumanReadableSize);
	Gura_AssignMethod(wx_FileName, GetHumanReadableSize_1);
	Gura_AssignMethod(wx_FileName, GetTempDir);
	Gura_AssignMethod(wx_FileName, GetTimes);
	Gura_AssignMethod(wx_FileName, GetVolume);
	Gura_AssignMethod(wx_FileName, GetVolumeSeparator);
	Gura_AssignMethod(wx_FileName, HasExt);
	Gura_AssignMethod(wx_FileName, HasName);
	Gura_AssignMethod(wx_FileName, HasVolume);
	Gura_AssignMethod(wx_FileName, InsertDir);
	Gura_AssignMethod(wx_FileName, IsAbsolute);
	Gura_AssignMethod(wx_FileName, IsCaseSensitive);
	Gura_AssignMethod(wx_FileName, IsDirReadable);
	Gura_AssignMethod(wx_FileName, IsDirReadable_1);
	Gura_AssignMethod(wx_FileName, IsDirWritable);
	Gura_AssignMethod(wx_FileName, IsDirWritable_1);
	Gura_AssignMethod(wx_FileName, IsFileExecutable);
	Gura_AssignMethod(wx_FileName, IsFileExecutable_1);
	Gura_AssignMethod(wx_FileName, IsFileReadable);
	Gura_AssignMethod(wx_FileName, IsFileReadable_1);
	Gura_AssignMethod(wx_FileName, IsFileWritable);
	Gura_AssignMethod(wx_FileName, IsFileWritable_1);
	Gura_AssignMethod(wx_FileName, IsOk);
	Gura_AssignMethod(wx_FileName, IsPathSeparator);
	Gura_AssignMethod(wx_FileName, IsRelative);
	Gura_AssignMethod(wx_FileName, IsDir);
	Gura_AssignMethod(wx_FileName, MacFindDefaultTypeAndCreator);
	Gura_AssignMethod(wx_FileName, MacRegisterDefaultTypeAndCreator);
	Gura_AssignMethod(wx_FileName, MacSetDefaultTypeAndCreator);
	Gura_AssignMethod(wx_FileName, MakeAbsolute);
	Gura_AssignMethod(wx_FileName, MakeRelativeTo);
	Gura_AssignMethod(wx_FileName, Mkdir);
	Gura_AssignMethod(wx_FileName, Mkdir_1);
	Gura_AssignMethod(wx_FileName, Normalize);
	Gura_AssignMethod(wx_FileName, PrependDir);
	Gura_AssignMethod(wx_FileName, RemoveDir);
	Gura_AssignMethod(wx_FileName, RemoveLastDir);
	Gura_AssignMethod(wx_FileName, Rmdir);
	Gura_AssignMethod(wx_FileName, Rmdir_1);
	Gura_AssignMethod(wx_FileName, SameAs);
	Gura_AssignMethod(wx_FileName, SetCwd);
	Gura_AssignMethod(wx_FileName, SetCwd_1);
	Gura_AssignMethod(wx_FileName, SetExt);
	Gura_AssignMethod(wx_FileName, SetEmptyExt);
	Gura_AssignMethod(wx_FileName, SetFullName);
	Gura_AssignMethod(wx_FileName, SetName);
	Gura_AssignMethod(wx_FileName, SetTimes);
	Gura_AssignMethod(wx_FileName, SetVolume);
	Gura_AssignMethod(wx_FileName, SplitPath);
	Gura_AssignMethod(wx_FileName, SplitPath_1);
	Gura_AssignMethod(wx_FileName, SplitPath_2);
	Gura_AssignMethod(wx_FileName, SplitVolume);
	Gura_AssignMethod(wx_FileName, Touch);
}

Gura_ImplementDescendantCreator(wx_FileName)
{
	return new Object_wx_FileName((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
