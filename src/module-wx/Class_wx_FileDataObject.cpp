//----------------------------------------------------------------------------
// wxFileDataObject
// extracted from fildatob.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(AddFile);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FileDataObject: public wxFileDataObject, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_FileDataObject *_pObj;
public:
	inline wx_FileDataObject() : wxFileDataObject(), _pObj(nullptr) {}
	//virtual void AddFile(const wxString& file);
	~wx_FileDataObject();
	inline void AssocWithGura(Object_wx_FileDataObject *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FileDataObject::~wx_FileDataObject()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FileDataObject::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFileDataObject
//----------------------------------------------------------------------------
Gura_DeclareFunction(FileDataObjectEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FileDataObject));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileDataObjectEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_FileDataObject *pEntity = new wx_FileDataObject();
	Object_wx_FileDataObject *pObj = Object_wx_FileDataObject::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_FileDataObject(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_FileDataObject, AddFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDataObject, AddFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileDataObject *pThis = Object_wx_FileDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString file = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->AddFile(file);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDataObject, GetFilenames)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileDataObject, GetFilenames)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileDataObject *pThis = Object_wx_FileDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArrayString rtn = pThis->GetEntity()->GetFilenames();
	return ReturnValue(env, arg, ArrayStringToValue(env, rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxFileDataObject
//----------------------------------------------------------------------------
Object_wx_FileDataObject::~Object_wx_FileDataObject()
{
}

Object *Object_wx_FileDataObject::Clone() const
{
	return nullptr;
}

String Object_wx_FileDataObject::ToString(bool exprFlag)
{
	String rtn("<wx.FileDataObject:");
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
// Class implementation for wxFileDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileDataObject)
{
	Gura_RealizeUserSymbol(AddFile);
	Gura_AssignFunction(FileDataObjectEmpty);
	Gura_AssignMethod(wx_FileDataObject, AddFile);
	Gura_AssignMethod(wx_FileDataObject, GetFilenames);
}

Gura_ImplementDescendantCreator(wx_FileDataObject)
{
	return new Object_wx_FileDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
