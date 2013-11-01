//----------------------------------------------------------------------------
// wxMetafile
// extracted from metafile.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Metafile: public wxMetafile, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Metafile *_pObj;
public:
	inline wx_Metafile(const wxString& filename) : wxMetafile(filename), _sig(NULL), _pObj(NULL) {}
	~wx_Metafile();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Metafile *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Metafile::~wx_Metafile()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Metafile::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMetafile
//----------------------------------------------------------------------------
Gura_DeclareFunction(Metafile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Metafile));
	DeclareArg(env, "filename", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Metafile)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString filename = wxT("");
	if (args.IsValid(0)) filename = wxString::FromUTF8(args.GetString(0));
	wx_Metafile *pEntity = new wx_Metafile(filename);
	Object_wx_Metafile *pObj = Object_wx_Metafile::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Metafile(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_Metafile, Ok)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Metafile, Ok)
{
	Object_wx_Metafile *pThis = Object_wx_Metafile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Ok();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Metafile, Play)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Metafile, Play)
{
	Object_wx_Metafile *pThis = Object_wx_Metafile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Play(dc);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Metafile, SetClipboard)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Metafile, SetClipboard)
{
	Object_wx_Metafile *pThis = Object_wx_Metafile::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = 0;
	if (args.IsValid(0)) width = args.GetInt(0);
	int height = 0;
	if (args.IsValid(1)) height = args.GetInt(1);
	bool rtn = pThis->GetEntity()->SetClipboard(width, height);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxMetafile
//----------------------------------------------------------------------------
Object_wx_Metafile::~Object_wx_Metafile()
{
}

Object *Object_wx_Metafile::Clone() const
{
	return NULL;
}

String Object_wx_Metafile::ToString(bool exprFlag)
{
	String rtn("<wx.Metafile:");
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
// Class implementation for wxMetafile
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Metafile)
{
	Gura_AssignFunction(Metafile);
	Gura_AssignMethod(wx_Metafile, Ok);
	Gura_AssignMethod(wx_Metafile, Play);
	Gura_AssignMethod(wx_Metafile, SetClipboard);
}

Gura_ImplementDescendantCreator(wx_Metafile)
{
	return new Object_wx_Metafile((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
