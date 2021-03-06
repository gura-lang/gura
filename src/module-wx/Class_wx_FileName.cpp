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
	//Gura::Signal *_pSig;
	Object_wx_FileName *_pObj;
public:
	//inline wx_FileName() : wxFileName(), _pObj(nullptr) {}
	//inline wx_FileName(const wxFileName& filename) : wxFileName(filename), _pObj(nullptr) {}
	//inline wx_FileName(const wxString& fullpath, wxPathFormat format) : wxFileName(fullpath, format), _pObj(nullptr) {}
	//inline wx_FileName(const wxString& path, const wxString& name, wxPathFormat format) : wxFileName(path, name, format), _pObj(nullptr) {}
	//inline wx_FileName(const wxString& path, const wxString& name, const wxString& ext, wxPathFormat format) : wxFileName(path, name, ext, format), _pObj(nullptr) {}
	//inline wx_FileName(const wxString& volume, const wxString& path, const wxString& name, const wxString& ext, wxPathFormat format) : wxFileName(volume, path, name, ext, format), _pObj(nullptr) {}
	~wx_FileName();
	inline void AssocWithGura(Object_wx_FileName *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FileName::~wx_FileName()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FileName::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFileName
//----------------------------------------------------------------------------
Gura_DeclareFunction(FileNameEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FileName));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FileNameEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_FileName *pEntity = new wx_FileName();
	Object_wx_FileName *pObj = Object_wx_FileName::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_FileName(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(FileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FileName));
	DeclareArg(env, "filename", VTYPE_wx_FileName, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FileName)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxFileName *filename = Object_wx_FileName::GetObject(arg, 0)->GetEntity();
	wx_FileName *pEntity = new wx_FileName(*filename);
	Object_wx_FileName *pObj = Object_wx_FileName::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_FileName(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(FileName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FileName));
	DeclareArg(env, "fullpath", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FileName_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString fullpath = wxString::FromUTF8(arg.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(1)) format = static_cast<wxPathFormat>(arg.GetInt(1));
	wx_FileName *pEntity = new wx_FileName(fullpath, format);
	Object_wx_FileName *pObj = Object_wx_FileName::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_FileName(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(FileName_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString path = wxString::FromUTF8(arg.GetString(0));
	wxString name = wxString::FromUTF8(arg.GetString(1));
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(2)) format = static_cast<wxPathFormat>(arg.GetInt(2));
	wx_FileName *pEntity = new wx_FileName(path, name, format);
	Object_wx_FileName *pObj = Object_wx_FileName::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_FileName(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(FileName_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString path = wxString::FromUTF8(arg.GetString(0));
	wxString name = wxString::FromUTF8(arg.GetString(1));
	wxString ext = wxString::FromUTF8(arg.GetString(2));
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(3)) format = static_cast<wxPathFormat>(arg.GetInt(3));
	wx_FileName *pEntity = new wx_FileName(path, name, ext, format);
	Object_wx_FileName *pObj = Object_wx_FileName::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_FileName(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(FileName_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString volume = wxString::FromUTF8(arg.GetString(0));
	wxString path = wxString::FromUTF8(arg.GetString(1));
	wxString name = wxString::FromUTF8(arg.GetString(2));
	wxString ext = wxString::FromUTF8(arg.GetString(3));
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(4)) format = static_cast<wxPathFormat>(arg.GetInt(4));
	wx_FileName *pEntity = new wx_FileName(volume, path, name, ext, format);
	Object_wx_FileName *pObj = Object_wx_FileName::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_FileName(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, AppendDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_FileName, AppendDir)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString dir = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->AppendDir(dir);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Assign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "filepath", VTYPE_wx_FileName, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_FileName, Assign)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFileName *filepath = Object_wx_FileName::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->Assign(*filepath);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Assign_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "fullpath", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_FileName, Assign_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString fullpath = wxString::FromUTF8(arg.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(1)) format = static_cast<wxPathFormat>(arg.GetInt(1));
	pThis->GetEntity()->Assign(fullpath, format);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Assign_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString volume = wxString::FromUTF8(arg.GetString(0));
	wxString path = wxString::FromUTF8(arg.GetString(1));
	wxString name = wxString::FromUTF8(arg.GetString(2));
	wxString ext = wxString::FromUTF8(arg.GetString(3));
	bool hasExt = arg.GetBoolean(4);
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(5)) format = static_cast<wxPathFormat>(arg.GetInt(5));
	pThis->GetEntity()->Assign(volume, path, name, ext, hasExt, format);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Assign_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString volume = wxString::FromUTF8(arg.GetString(0));
	wxString path = wxString::FromUTF8(arg.GetString(1));
	wxString name = wxString::FromUTF8(arg.GetString(2));
	wxString ext = wxString::FromUTF8(arg.GetString(3));
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(4)) format = static_cast<wxPathFormat>(arg.GetInt(4));
	pThis->GetEntity()->Assign(volume, path, name, ext, format);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Assign_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_FileName, Assign_4)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString path = wxString::FromUTF8(arg.GetString(0));
	wxString name = wxString::FromUTF8(arg.GetString(1));
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(2)) format = static_cast<wxPathFormat>(arg.GetInt(2));
	pThis->GetEntity()->Assign(path, name, format);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Assign_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "ext", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_FileName, Assign_5)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString path = wxString::FromUTF8(arg.GetString(0));
	wxString name = wxString::FromUTF8(arg.GetString(1));
	wxString ext = wxString::FromUTF8(arg.GetString(2));
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(3)) format = static_cast<wxPathFormat>(arg.GetInt(3));
	pThis->GetEntity()->Assign(path, name, ext, format);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, AssignCwd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "volume", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementClassMethod(wx_FileName, AssignCwd)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString volume = wxEmptyString;
	if (arg.IsValid(0)) volume = wxString::FromUTF8(arg.GetString(0));
	wxFileName::AssignCwd(volume);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, AssignDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_FileName, AssignDir)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString dir = wxString::FromUTF8(arg.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(1)) format = static_cast<wxPathFormat>(arg.GetInt(1));
	pThis->GetEntity()->AssignDir(dir, format);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, AssignHomeDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, AssignHomeDir)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->AssignHomeDir();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, AssignTempFileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "prefix", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "fileTemp", VTYPE_wx_File, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_FileName, AssignTempFileName)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString prefix = wxString::FromUTF8(arg.GetString(0));
	wxFile *fileTemp = (wxFile *)(nullptr);
	if (arg.IsValid(1)) fileTemp = Object_wx_File::GetObject(arg, 1)->GetEntity();
	pThis->GetEntity()->AssignTempFileName(prefix, fileTemp);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, Clear)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Clear();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SetClearExt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, SetClearExt)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->SetClearExt();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, CreateTempFileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "prefix", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "fileTemp", VTYPE_wx_File, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, CreateTempFileName)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString prefix = wxString::FromUTF8(arg.GetString(0));
	wxFile *fileTemp = (wxFile *)(nullptr);
	if (arg.IsValid(1)) fileTemp = Object_wx_File::GetObject(arg, 1)->GetEntity();
	wxString rtn = wxFileName::CreateTempFileName(prefix, fileTemp);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, DirExists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, DirExists)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->DirExists();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, DirExists_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, DirExists_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString dir = wxString::FromUTF8(arg.GetString(0));
	bool rtn = wxFileName::DirExists(dir);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareClassMethod(wx_FileName, DirName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, DirName)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString dir = wxString::FromUTF8(arg.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(1)) format = static_cast<wxPathFormat>(arg.GetInt(1));
	wxFileName rtn = wxFileName::DirName(dir, format);
	return ReturnValue(env, arg, Value(new Object_wx_FileName(new wxFileName(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, FileExists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, FileExists)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->FileExists();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, FileExists_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, FileExists_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString file = wxString::FromUTF8(arg.GetString(0));
	bool rtn = wxFileName::FileExists(file);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareClassMethod(wx_FileName, FileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, FileName)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString file = wxString::FromUTF8(arg.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(1)) format = static_cast<wxPathFormat>(arg.GetInt(1));
	wxFileName rtn = wxFileName::FileName(file, format);
	return ReturnValue(env, arg, Value(new Object_wx_FileName(new wxFileName(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, GetCwd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "volume", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetCwd)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString volume = wxT("");
	if (arg.IsValid(0)) volume = wxString::FromUTF8(arg.GetString(0));
	wxString rtn = wxFileName::GetCwd(volume);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetDirCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetDirCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetDirCount();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, GetDirs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetDirs)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArrayString rtn = pThis->GetEntity()->GetDirs();
	return ReturnValue(env, arg, ArrayStringToValue(env, rtn));
}

Gura_DeclareMethod(wx_FileName, GetExt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetExt)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetExt();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_FileName, GetForbiddenChars)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetForbiddenChars)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(0)) format = static_cast<wxPathFormat>(arg.GetInt(0));
	wxString rtn = wxFileName::GetForbiddenChars(format);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, GetFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetFormat)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(0)) format = static_cast<wxPathFormat>(arg.GetInt(0));
	wxPathFormat rtn = wxFileName::GetFormat(format);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetFullName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetFullName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetFullName();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileName, GetFullPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetFullPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(0)) format = static_cast<wxPathFormat>(arg.GetInt(0));
	wxString rtn = pThis->GetEntity()->GetFullPath(format);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_FileName, GetHomeDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetHomeDir)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString rtn = wxFileName::GetHomeDir();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetLongPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetLongPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetLongPath();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileName, GetModificationTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetModificationTime)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateTime rtn = pThis->GetEntity()->GetModificationTime();
	return ReturnValue(env, arg, Value(new Object_wx_DateTime(new wxDateTime(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_FileName, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileName, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int flags = wxPATH_GET_VOLUME;
	if (arg.IsValid(0)) flags = arg.GetInt(0);
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(1)) format = static_cast<wxPathFormat>(arg.GetInt(1));
	wxString rtn = pThis->GetEntity()->GetPath(flags, format);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_FileName, GetPathSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetPathSeparator)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(0)) format = static_cast<wxPathFormat>(arg.GetInt(0));
	wxChar rtn = wxFileName::GetPathSeparator(format);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, GetPathSeparators)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetPathSeparators)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(0)) format = static_cast<wxPathFormat>(arg.GetInt(0));
	wxString rtn = wxFileName::GetPathSeparators(format);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, GetPathTerminators)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetPathTerminators)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(0)) format = static_cast<wxPathFormat>(arg.GetInt(0));
	wxString rtn = wxFileName::GetPathTerminators(format);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetPathWithSep)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetPathWithSep)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(0)) format = static_cast<wxPathFormat>(arg.GetInt(0));
	wxString rtn = pThis->GetEntity()->GetPathWithSep(format);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileName, GetShortPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetShortPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetShortPath();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileName, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetSize)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxULongLong rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, arg, Value(new Object_wx_ULongLong(new wxULongLong(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, GetSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetSize_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString filename = wxString::FromUTF8(arg.GetString(0));
	wxULongLong rtn = wxFileName::GetSize(filename);
	return ReturnValue(env, arg, Value(new Object_wx_ULongLong(new wxULongLong(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetHumanReadableSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "failmsg", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "precision", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetHumanReadableSize)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString failmsg = wxT("Not available");
	if (arg.IsValid(0)) failmsg = wxString::FromUTF8(arg.GetString(0));
	int precision = 1;
	if (arg.IsValid(1)) precision = arg.GetInt(1);
	wxString rtn = pThis->GetEntity()->GetHumanReadableSize(failmsg, precision);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, GetHumanReadableSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "bytes", VTYPE_wx_ULongLong, OCCUR_Once);
	DeclareArg(env, "nullsize", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "precision", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetHumanReadableSize_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxULongLong *bytes = Object_wx_ULongLong::GetObject(arg, 0)->GetEntity();
	wxString nullsize = wxT("Not available");
	if (arg.IsValid(1)) nullsize = wxString::FromUTF8(arg.GetString(1));
	int precision = 1;
	if (arg.IsValid(2)) precision = arg.GetInt(2);
	wxString rtn = wxFileName::GetHumanReadableSize(*bytes, nullsize, precision);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, GetTempDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetTempDir)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString rtn = wxFileName::GetTempDir();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetTimes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dtAccess", VTYPE_wx_DateTime, OCCUR_Once);
	DeclareArg(env, "dtMod", VTYPE_wx_DateTime, OCCUR_Once);
	DeclareArg(env, "dtCreate", VTYPE_wx_DateTime, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetTimes)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateTime *dtAccess = Object_wx_DateTime::GetObject(arg, 0)->GetEntity();
	wxDateTime *dtMod = Object_wx_DateTime::GetObject(arg, 1)->GetEntity();
	wxDateTime *dtCreate = Object_wx_DateTime::GetObject(arg, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->GetTimes(dtAccess, dtMod, dtCreate);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, GetVolume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, GetVolume)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetVolume();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_FileName, GetVolumeSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, GetVolumeSeparator)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(0)) format = static_cast<wxPathFormat>(arg.GetInt(0));
	wxString rtn = wxFileName::GetVolumeSeparator(format);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, HasExt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, HasExt)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasExt();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, HasName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, HasName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasName();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, HasVolume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, HasVolume)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasVolume();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, InsertDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "before", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_FileName, InsertDir)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t before = arg.GetSizeT(0);
	wxString dir = wxString::FromUTF8(arg.GetString(1));
	pThis->GetEntity()->InsertDir(before, dir);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsAbsolute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, IsAbsolute)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(0)) format = static_cast<wxPathFormat>(arg.GetInt(0));
	bool rtn = pThis->GetEntity()->IsAbsolute(format);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, IsCaseSensitive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, IsCaseSensitive)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(0)) format = static_cast<wxPathFormat>(arg.GetInt(0));
	bool rtn = wxFileName::IsCaseSensitive(format);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsDirReadable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, IsDirReadable)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsDirReadable();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, IsDirReadable_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, IsDirReadable_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString dir = wxString::FromUTF8(arg.GetString(0));
	bool rtn = wxFileName::IsDirReadable(dir);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, IsDirWritable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, IsDirWritable)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsDirWritable();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, IsDirWritable_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, IsDirWritable_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString dir = wxString::FromUTF8(arg.GetString(0));
	bool rtn = wxFileName::IsDirWritable(dir);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, IsFileExecutable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, IsFileExecutable)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsFileExecutable();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, IsFileExecutable_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, IsFileExecutable_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString file = wxString::FromUTF8(arg.GetString(0));
	bool rtn = wxFileName::IsFileExecutable(file);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, IsFileReadable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, IsFileReadable)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsFileReadable();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, IsFileReadable_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, IsFileReadable_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString file = wxString::FromUTF8(arg.GetString(0));
	bool rtn = wxFileName::IsFileReadable(file);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, IsFileWritable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, IsFileWritable)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsFileWritable();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, IsFileWritable_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, IsFileWritable_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString file = wxString::FromUTF8(arg.GetString(0));
	bool rtn = wxFileName::IsFileWritable(file);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareClassMethod(wx_FileName, IsPathSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, IsPathSeparator)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxChar ch = static_cast<wxChar>(arg.GetInt(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(1)) format = static_cast<wxPathFormat>(arg.GetInt(1));
	bool rtn = wxFileName::IsPathSeparator(ch, format);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsRelative)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, IsRelative)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(0)) format = static_cast<wxPathFormat>(arg.GetInt(0));
	bool rtn = pThis->GetEntity()->IsRelative(format);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, IsDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsDir();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareClassMethod(wx_FileName, MacFindDefaultTypeAndCreator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ext", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "creator", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, MacFindDefaultTypeAndCreator)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString ext = wxString::FromUTF8(arg.GetString(0));
	wxUint32 type = static_cast<wxUint32>(arg.GetULong(1));
	wxUint32 creator = static_cast<wxUint32>(arg.GetULong(2));
	bool rtn = wxFileName::MacFindDefaultTypeAndCreator(ext, type, creator);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, MacRegisterDefaultTypeAndCreator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "ext", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "creator", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementClassMethod(wx_FileName, MacRegisterDefaultTypeAndCreator)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString ext = wxString::FromUTF8(arg.GetString(0));
	wxUint32 type = static_cast<wxUint32>(arg.GetULong(1));
	wxUint32 creator = static_cast<wxUint32>(arg.GetULong(2));
	wxFileName::MacRegisterDefaultTypeAndCreator(ext, type, creator);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, MacSetDefaultTypeAndCreator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, MacSetDefaultTypeAndCreator)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->MacSetDefaultTypeAndCreator();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, MakeAbsolute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "cwd", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, MakeAbsolute)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString cwd = wxEmptyString;
	if (arg.IsValid(0)) cwd = wxString::FromUTF8(arg.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(1)) format = static_cast<wxPathFormat>(arg.GetInt(1));
	bool rtn = pThis->GetEntity()->MakeAbsolute(cwd, format);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, MakeRelativeTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "pathBase", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, MakeRelativeTo)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString pathBase = wxEmptyString;
	if (arg.IsValid(0)) pathBase = wxString::FromUTF8(arg.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(1)) format = static_cast<wxPathFormat>(arg.GetInt(1));
	bool rtn = pThis->GetEntity()->MakeRelativeTo(pathBase, format);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Mkdir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "perm", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, Mkdir)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int perm = 0777;
	if (arg.IsValid(0)) perm = arg.GetInt(0);
	int flags = 0;
	if (arg.IsValid(1)) flags = arg.GetInt(1);
	bool rtn = pThis->GetEntity()->Mkdir(perm, flags);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, Mkdir_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "perm", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, Mkdir_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString dir = wxString::FromUTF8(arg.GetString(0));
	int perm = 0777;
	if (arg.IsValid(1)) perm = arg.GetInt(1);
	int flags = 0;
	if (arg.IsValid(2)) flags = arg.GetInt(2);
	bool rtn = wxFileName::Mkdir(dir, perm, flags);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Normalize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "cwd", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, Normalize)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int flags = wxPATH_NORM_ALL;
	if (arg.IsValid(0)) flags = arg.GetInt(0);
	wxString cwd = wxEmptyString;
	if (arg.IsValid(1)) cwd = wxString::FromUTF8(arg.GetString(1));
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(2)) format = static_cast<wxPathFormat>(arg.GetInt(2));
	bool rtn = pThis->GetEntity()->Normalize(flags, cwd, format);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, PrependDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_FileName, PrependDir)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString dir = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->PrependDir(dir);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, RemoveDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_FileName, RemoveDir)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pos = arg.GetSizeT(0);
	pThis->GetEntity()->RemoveDir(pos);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, RemoveLastDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, RemoveLastDir)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->RemoveLastDir();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Rmdir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, Rmdir)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Rmdir();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, Rmdir_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, Rmdir_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString dir = wxString::FromUTF8(arg.GetString(0));
	bool rtn = wxFileName::Rmdir(dir);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SameAs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filepath", VTYPE_wx_FileName, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, SameAs)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFileName *filepath = Object_wx_FileName::GetObject(arg, 0)->GetEntity();
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(1)) format = static_cast<wxPathFormat>(arg.GetInt(1));
	bool rtn = pThis->GetEntity()->SameAs(*filepath, format);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FileName, SetCwd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, SetCwd)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->SetCwd();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, SetCwd_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "cwd", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileName, SetCwd_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString cwd = wxString::FromUTF8(arg.GetString(0));
	bool rtn = wxFileName::SetCwd(cwd);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SetExt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "ext", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_FileName, SetExt)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString ext = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetExt(ext);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SetEmptyExt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, SetEmptyExt)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->SetEmptyExt();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SetFullName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "fullname", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_FileName, SetFullName)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString fullname = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetFullName(fullname);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_FileName, SetName)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetName(name);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SetTimes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "dtAccess", VTYPE_wx_DateTime, OCCUR_Once);
	DeclareArg(env, "dtMod", VTYPE_wx_DateTime, OCCUR_Once);
	DeclareArg(env, "dtCreate", VTYPE_wx_DateTime, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, SetTimes)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateTime *dtAccess = Object_wx_DateTime::GetObject(arg, 0)->GetEntity();
	wxDateTime *dtMod = Object_wx_DateTime::GetObject(arg, 1)->GetEntity();
	wxDateTime *dtCreate = Object_wx_DateTime::GetObject(arg, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->SetTimes(dtAccess, dtMod, dtCreate);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SetVolume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "volume", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_FileName, SetVolume)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString volume = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetVolume(volume);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, SplitPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString fullpath = wxString::FromUTF8(arg.GetString(0));
	wxString volume = wxString::FromUTF8(arg.GetString(1));
	wxString path = wxString::FromUTF8(arg.GetString(2));
	wxString name = wxString::FromUTF8(arg.GetString(3));
	wxString ext = wxString::FromUTF8(arg.GetString(4));
	bool *hasExt = nullptr;
	if (arg.IsValid(5)) *hasExt = arg.GetBoolean(5);
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(6)) format = static_cast<wxPathFormat>(arg.GetInt(6));
	wxFileName::SplitPath(fullpath, volume, path, name, ext, *hasExt, format);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, SplitPath_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString fullpath = wxString::FromUTF8(arg.GetString(0));
	wxString volume = wxString::FromUTF8(arg.GetString(1));
	wxString path = wxString::FromUTF8(arg.GetString(2));
	wxString name = wxString::FromUTF8(arg.GetString(3));
	wxString ext = wxString::FromUTF8(arg.GetString(4));
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(5)) format = static_cast<wxPathFormat>(arg.GetInt(5));
	wxFileName::SplitPath(fullpath, volume, path, name, ext, format);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, SplitPath_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString fullpath = wxString::FromUTF8(arg.GetString(0));
	wxString path = wxString::FromUTF8(arg.GetString(1));
	wxString name = wxString::FromUTF8(arg.GetString(2));
	wxString ext = wxString::FromUTF8(arg.GetString(3));
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(4)) format = static_cast<wxPathFormat>(arg.GetInt(4));
	wxFileName::SplitPath(fullpath, path, name, ext, format);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileName, SplitVolume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "fullpath", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "volume", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementClassMethod(wx_FileName, SplitVolume)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString fullpath = wxString::FromUTF8(arg.GetString(0));
	wxString volume = wxString::FromUTF8(arg.GetString(1));
	wxString path = wxString::FromUTF8(arg.GetString(2));
	wxPathFormat format = wxPATH_NATIVE;
	if (arg.IsValid(3)) format = static_cast<wxPathFormat>(arg.GetInt(3));
	wxFileName::SplitVolume(fullpath, volume, path, format);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Touch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileName, Touch)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Touch();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxFileName
//----------------------------------------------------------------------------
Object_wx_FileName::~Object_wx_FileName()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_FileName::Clone() const
{
	return nullptr;
}

String Object_wx_FileName::ToString(bool exprFlag)
{
	String rtn("<wx.FileName:");
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
	return new Object_wx_FileName((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
