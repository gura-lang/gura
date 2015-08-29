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
	//Gura::Signal *_pSig;
	Object_wx_Metafile *_pObj;
public:
	inline wx_Metafile(const wxString& filename) : wxMetafile(filename), _pObj(nullptr) {}
	~wx_Metafile();
	inline void AssocWithGura(Object_wx_Metafile *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Metafile::~wx_Metafile()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Metafile::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMetafile
//----------------------------------------------------------------------------
Gura_DeclareFunction(Metafile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Metafile));
	DeclareArg(env, "filename", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Metafile)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString filename = wxT("");
	if (arg.IsValid(0)) filename = wxString::FromUTF8(arg.GetString(0));
	wx_Metafile *pEntity = new wx_Metafile(filename);
	Object_wx_Metafile *pObj = Object_wx_Metafile::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Metafile(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_Metafile, Ok)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Metafile, Ok)
{
	Signal &sig = env.GetSignal();
	Object_wx_Metafile *pThis = Object_wx_Metafile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Ok();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Metafile, Play)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Metafile, Play)
{
	Signal &sig = env.GetSignal();
	Object_wx_Metafile *pThis = Object_wx_Metafile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Play(dc);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Metafile, SetClipboard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Metafile, SetClipboard)
{
	Signal &sig = env.GetSignal();
	Object_wx_Metafile *pThis = Object_wx_Metafile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width = 0;
	if (arg.IsValid(0)) width = arg.GetInt(0);
	int height = 0;
	if (arg.IsValid(1)) height = arg.GetInt(1);
	bool rtn = pThis->GetEntity()->SetClipboard(width, height);
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxMetafile
//----------------------------------------------------------------------------
Object_wx_Metafile::~Object_wx_Metafile()
{
}

Object *Object_wx_Metafile::Clone() const
{
	return nullptr;
}

String Object_wx_Metafile::ToString(bool exprFlag)
{
	String rtn("<wx.Metafile:");
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
	return new Object_wx_Metafile((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
