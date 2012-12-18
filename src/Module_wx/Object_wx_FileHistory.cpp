//----------------------------------------------------------------------------
// wxFileHistory
// extracted from filehist.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FileHistory: public wxFileHistory, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FileHistory *_pObj;
public:
	inline wx_FileHistory(size_t maxFiles, wxWindowID idBase) : wxFileHistory(maxFiles, idBase), _sig(NULL), _pObj(NULL) {}
	~wx_FileHistory();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FileHistory *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FileHistory::~wx_FileHistory()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FileHistory::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFileHistory
//----------------------------------------------------------------------------
Gura_DeclareFunction(FileHistory)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FileHistory));
	DeclareArg(env, "maxFiles", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "idBase", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileHistory)
{
	size_t maxFiles = 9;
	if (args.IsValid(0)) maxFiles = args.GetSizeT(0);
	wxWindowID idBase = wxID_FILE1;
	if (args.IsValid(1)) idBase = static_cast<wxWindowID>(args.GetInt(1));
	wx_FileHistory *pEntity = new wx_FileHistory(maxFiles, idBase);
	Object_wx_FileHistory *pObj = Object_wx_FileHistory::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FileHistory(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_FileHistory, AddFileToHistory)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, AddFileToHistory)
{
	Object_wx_FileHistory *pSelf = Object_wx_FileHistory::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->AddFileToHistory(filename);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileHistory, AddFilesToMenu)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileHistory, AddFilesToMenu)
{
	Object_wx_FileHistory *pSelf = Object_wx_FileHistory::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->AddFilesToMenu();
	return Value::Null;
}

Gura_DeclareMethod(wx_FileHistory, AddFilesToMenu_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, AddFilesToMenu_1)
{
	Object_wx_FileHistory *pSelf = Object_wx_FileHistory::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenu *menu = Object_wx_Menu::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->AddFilesToMenu(menu);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileHistory, GetBaseId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileHistory, GetBaseId)
{
	Object_wx_FileHistory *pSelf = Object_wx_FileHistory::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindowID rtn = pSelf->GetEntity()->GetBaseId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileHistory, GetCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileHistory, GetCount)
{
	Object_wx_FileHistory *pSelf = Object_wx_FileHistory::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t rtn = pSelf->GetEntity()->GetCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileHistory, GetHistoryFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileHistory, GetHistoryFile)
{
	Object_wx_FileHistory *pSelf = Object_wx_FileHistory::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t index = args.GetSizeT(0);
	wxString rtn = pSelf->GetEntity()->GetHistoryFile(index);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileHistory, GetMaxFiles)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileHistory, GetMaxFiles)
{
	Object_wx_FileHistory *pSelf = Object_wx_FileHistory::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetMaxFiles();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileHistory, GetMenus)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileHistory, GetMenus)
{
#if 0
	Object_wx_FileHistory *pSelf = Object_wx_FileHistory::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxList &rtn = pSelf->GetEntity()->GetMenus();
	return ReturnValue(env, sig, args, Value(new Object_wx_List(new wxList(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileHistory, Load)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "config", VTYPE_wx_ConfigBase, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, Load)
{
	Object_wx_FileHistory *pSelf = Object_wx_FileHistory::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxConfigBase *config = Object_wx_ConfigBase::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->Load(*config);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileHistory, RemoveFileFromHistory)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, RemoveFileFromHistory)
{
	Object_wx_FileHistory *pSelf = Object_wx_FileHistory::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t i = args.GetSizeT(0);
	pSelf->GetEntity()->RemoveFileFromHistory(i);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileHistory, RemoveMenu)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, RemoveMenu)
{
	Object_wx_FileHistory *pSelf = Object_wx_FileHistory::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenu *menu = Object_wx_Menu::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->RemoveMenu(menu);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileHistory, Save)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "config", VTYPE_wx_ConfigBase, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, Save)
{
	Object_wx_FileHistory *pSelf = Object_wx_FileHistory::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxConfigBase *config = Object_wx_ConfigBase::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->Save(*config);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileHistory, SetBaseId)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "baseId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, SetBaseId)
{
	Object_wx_FileHistory *pSelf = Object_wx_FileHistory::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindowID baseId = static_cast<wxWindowID>(args.GetInt(0));
	pSelf->GetEntity()->SetBaseId(baseId);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileHistory, UseMenu)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileHistory, UseMenu)
{
	Object_wx_FileHistory *pSelf = Object_wx_FileHistory::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenu *menu = Object_wx_Menu::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->UseMenu(menu);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxFileHistory
//----------------------------------------------------------------------------
Object_wx_FileHistory::~Object_wx_FileHistory()
{
}

Object *Object_wx_FileHistory::Clone() const
{
	return NULL;
}

String Object_wx_FileHistory::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.FileHistory:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_FileHistory::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(FileHistory);
}

//----------------------------------------------------------------------------
// Class implementation for wxFileHistory
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileHistory)
{
	Gura_AssignMethod(wx_FileHistory, AddFileToHistory);
	Gura_AssignMethod(wx_FileHistory, AddFilesToMenu);
	Gura_AssignMethod(wx_FileHistory, AddFilesToMenu_1);
	Gura_AssignMethod(wx_FileHistory, GetBaseId);
	Gura_AssignMethod(wx_FileHistory, GetCount);
	Gura_AssignMethod(wx_FileHistory, GetHistoryFile);
	Gura_AssignMethod(wx_FileHistory, GetMaxFiles);
	Gura_AssignMethod(wx_FileHistory, GetMenus);
	Gura_AssignMethod(wx_FileHistory, Load);
	Gura_AssignMethod(wx_FileHistory, RemoveFileFromHistory);
	Gura_AssignMethod(wx_FileHistory, RemoveMenu);
	Gura_AssignMethod(wx_FileHistory, Save);
	Gura_AssignMethod(wx_FileHistory, SetBaseId);
	Gura_AssignMethod(wx_FileHistory, UseMenu);
}

Gura_ImplementDescendantCreator(wx_FileHistory)
{
	return new Object_wx_FileHistory((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
