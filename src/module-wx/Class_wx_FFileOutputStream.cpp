//----------------------------------------------------------------------------
// wxFFileOutputStream
// extracted from ffilestr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FFileOutputStream: public wxFFileOutputStream, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_FFileOutputStream *_pObj;
public:
	inline wx_FFileOutputStream(const wxString& filename, const wxChar * mode) : wxFFileOutputStream(filename, mode), _pObj(nullptr) {}
	inline wx_FFileOutputStream(wxFFile& file) : wxFFileOutputStream(file), _pObj(nullptr) {}
	//inline wx_FFileOutputStream(FILE * fp) : wxFFileOutputStream(fp), _pObj(nullptr) {}
	~wx_FFileOutputStream();
	inline void AssocWithGura(Object_wx_FFileOutputStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FFileOutputStream::~wx_FFileOutputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FFileOutputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFFileOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(FFileOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FFileOutputStream));
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FFileOutputStream)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxString _mode;
	const wxChar *mode = wxT("w+b");
	if (args.IsValid(1)) {
		_mode = wxString::FromUTF8(args.GetString(1));
		mode = _mode;
	}
	wx_FFileOutputStream *pEntity = new wx_FFileOutputStream(filename, mode);
	Object_wx_FFileOutputStream *pObj = Object_wx_FFileOutputStream::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_FFileOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(FFileOutputStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FFileOutputStream));
	DeclareArg(env, "file", VTYPE_wx_FFile, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FFileOutputStream_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxFFile *file = Object_wx_FFile::GetObject(args, 0)->GetEntity();
	wx_FFileOutputStream *pEntity = new wx_FFileOutputStream(*file);
	Object_wx_FFileOutputStream *pObj = Object_wx_FFileOutputStream::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_FFileOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(FFileOutputStream_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FFileOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FFileOutputStream_2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_FFileOutputStream *pEntity = new wx_FFileOutputStream();
	Object_wx_FFileOutputStream *pObj = Object_wx_FFileOutputStream::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_FFileOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFileOutputStream, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FFileOutputStream, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_FFileOutputStream *pThis = Object_wx_FFileOutputStream::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxFFileOutputStream
//----------------------------------------------------------------------------
Object_wx_FFileOutputStream::~Object_wx_FFileOutputStream()
{
}

Object *Object_wx_FFileOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_FFileOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.FFileOutputStream:");
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
// Class implementation for wxFFileOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FFileOutputStream)
{
	Gura_AssignFunction(FFileOutputStream);
	Gura_AssignFunction(FFileOutputStream_1);
	Gura_AssignFunction(FFileOutputStream_2);
	Gura_AssignMethod(wx_FFileOutputStream, IsOk);
}

Gura_ImplementDescendantCreator(wx_FFileOutputStream)
{
	return new Object_wx_FFileOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
