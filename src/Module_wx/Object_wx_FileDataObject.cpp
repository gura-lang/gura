//----------------------------------------------------------------------------
// wxFileDataObject
// extracted from fildatob.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(AddFile);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FileDataObject: public wxFileDataObject, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FileDataObject *_pObj;
public:
	inline wx_FileDataObject() : wxFileDataObject(), _sig(NULL), _pObj(NULL) {}
	//virtual void AddFile(const wxString& file);
	~wx_FileDataObject();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FileDataObject *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FileDataObject::~wx_FileDataObject()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FileDataObject::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFileDataObject
//----------------------------------------------------------------------------
Gura_DeclareFunction(FileDataObjectEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FileDataObject));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileDataObjectEmpty)
{
	wx_FileDataObject *pEntity = new wx_FileDataObject();
	Object_wx_FileDataObject *pObj = Object_wx_FileDataObject::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FileDataObject(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_FileDataObject, AddFile)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDataObject, AddFile)
{
	Object_wx_FileDataObject *pSelf = Object_wx_FileDataObject::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString file = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->AddFile(file);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileDataObject, GetFilenames)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileDataObject, GetFilenames)
{
	Object_wx_FileDataObject *pSelf = Object_wx_FileDataObject::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxArrayString rtn = pSelf->GetEntity()->GetFilenames();
	return ReturnValue(env, sig, args, ArrayStringToValue(env, rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxFileDataObject
//----------------------------------------------------------------------------
Object_wx_FileDataObject::~Object_wx_FileDataObject()
{
}

Object *Object_wx_FileDataObject::Clone() const
{
	return NULL;
}

String Object_wx_FileDataObject::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.FileDataObject:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_FileDataObject::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(AddFile);
	Gura_AssignFunction(FileDataObjectEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxFileDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileDataObject)
{
	Gura_AssignMethod(wx_FileDataObject, AddFile);
	Gura_AssignMethod(wx_FileDataObject, GetFilenames);
}

Gura_ImplementDescendantCreator(wx_FileDataObject)
{
	return new Object_wx_FileDataObject((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
