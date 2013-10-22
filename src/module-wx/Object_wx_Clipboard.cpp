//----------------------------------------------------------------------------
// wxClipboard
// extracted from clipbrd.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Clipboard: public wxClipboard, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Clipboard *_pObj;
public:
	inline wx_Clipboard() : wxClipboard(), _sig(NULL), _pObj(NULL) {}
	~wx_Clipboard();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Clipboard *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Clipboard::~wx_Clipboard()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Clipboard::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxClipboard
//----------------------------------------------------------------------------
Gura_DeclareFunction(Clipboard)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Clipboard));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Clipboard)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Clipboard *pEntity = new wx_Clipboard();
	Object_wx_Clipboard *pObj = Object_wx_Clipboard::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Clipboard(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_Clipboard, AddData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "data", VTYPE_wx_DataObject, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Clipboard, AddData)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataObject *data = Object_wx_DataObject::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->AddData(data);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Clipboard, Clear)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, Clear)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Clear();
	return Value::Null;
}

Gura_DeclareMethod(wx_Clipboard, Close)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, Close)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Close();
	return Value::Null;
}

Gura_DeclareMethod(wx_Clipboard, Flush)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Clipboard, Flush)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Flush();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Clipboard, GetData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "data", VTYPE_wx_DataObject, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Clipboard, GetData)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataObject *data = Object_wx_DataObject::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->GetData(*data);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Clipboard, IsOpened)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Clipboard, IsOpened)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOpened();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Clipboard, IsSupported)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "format", VTYPE_wx_DataFormat, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Clipboard, IsSupported)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataFormat *format = Object_wx_DataFormat::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsSupported(*format);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Clipboard, Open)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Clipboard, Open)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Open();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Clipboard, SetData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "data", VTYPE_wx_DataObject, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Clipboard, SetData)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataObject *data = Object_wx_DataObject::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->SetData(data);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Clipboard, UsePrimarySelection)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "primary", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Clipboard, UsePrimarySelection)
{
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool primary = true;
	if (args.IsValid(0)) primary = args.GetBoolean(0);
	pThis->GetEntity()->UsePrimarySelection(primary);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxClipboard
//----------------------------------------------------------------------------
Object_wx_Clipboard::~Object_wx_Clipboard()
{
}

Object *Object_wx_Clipboard::Clone() const
{
	return NULL;
}

String Object_wx_Clipboard::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Clipboard:");
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
// Class implementation for wxClipboard
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Clipboard)
{
	Gura_AssignFunction(Clipboard);
	Gura_AssignMethod(wx_Clipboard, AddData);
	Gura_AssignMethod(wx_Clipboard, Clear);
	Gura_AssignMethod(wx_Clipboard, Close);
	Gura_AssignMethod(wx_Clipboard, Flush);
	Gura_AssignMethod(wx_Clipboard, GetData);
	Gura_AssignMethod(wx_Clipboard, IsOpened);
	Gura_AssignMethod(wx_Clipboard, IsSupported);
	Gura_AssignMethod(wx_Clipboard, Open);
	Gura_AssignMethod(wx_Clipboard, SetData);
	Gura_AssignMethod(wx_Clipboard, UsePrimarySelection);
}

Gura_ImplementDescendantCreator(wx_Clipboard)
{
	return new Object_wx_Clipboard((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
