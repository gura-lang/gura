//----------------------------------------------------------------------------
// wxFFileInputStream
// extracted from ffilestr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FFileInputStream: public wxFFileInputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FFileInputStream *_pObj;
public:
	//inline wx_FFileInputStream(const wxString& filename, const wxChar * mode) : wxFFileInputStream(filename, mode), _sig(NULL), _pObj(NULL) {}
	//inline wx_FFileInputStream(wxFFile& file) : wxFFileInputStream(file), _sig(NULL), _pObj(NULL) {}
	//inline wx_FFileInputStream(FILE * fp) : wxFFileInputStream(fp), _sig(NULL), _pObj(NULL) {}
	~wx_FFileInputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FFileInputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FFileInputStream::~wx_FFileInputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FFileInputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFFileInputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(FFileInputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FFileInputStream));
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FFileInputStream)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxString _mode;
	const wxChar *mode = wxT("rb");
	if (args.IsValid(1)) {
		_mode = wxString::FromUTF8(args.GetString(1));
		mode = _mode;
	}
	wx_FFileInputStream *pEntity = new wx_FFileInputStream(filename, mode);
	Object_wx_FFileInputStream *pObj = Object_wx_FFileInputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FFileInputStream(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareFunction(FFileInputStream_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FFileInputStream));
	DeclareArg(env, "file", VTYPE_wx_FFile, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FFileInputStream_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxFFile *file = Object_wx_FFile::GetObject(args, 0)->GetEntity();
	wx_FFileInputStream *pEntity = new wx_FFileInputStream(*file);
	Object_wx_FFileInputStream *pObj = Object_wx_FFileInputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FFileInputStream(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareFunction(FFileInputStream_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FFileInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FFileInputStream_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_FFileInputStream *pEntity = new wx_FFileInputStream();
	Object_wx_FFileInputStream *pObj = Object_wx_FFileInputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FFileInputStream(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_FFileInputStream, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FFileInputStream, IsOk)
{
	Object_wx_FFileInputStream *pThis = Object_wx_FFileInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxFFileInputStream
//----------------------------------------------------------------------------
Object_wx_FFileInputStream::~Object_wx_FFileInputStream()
{
}

Object *Object_wx_FFileInputStream::Clone() const
{
	return NULL;
}

String Object_wx_FFileInputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.FFileInputStream:");
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
// Class implementation for wxFFileInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FFileInputStream)
{
	Gura_AssignFunction(FFileInputStream);
	Gura_AssignFunction(FFileInputStream_1);
	Gura_AssignFunction(FFileInputStream_2);
	Gura_AssignMethod(wx_FFileInputStream, IsOk);
}

Gura_ImplementDescendantCreator(wx_FFileInputStream)
{
	return new Object_wx_FFileInputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
