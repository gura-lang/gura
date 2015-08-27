//----------------------------------------------------------------------------
// wxClipboard
// extracted from clipbrd.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Clipboard: public wxClipboard, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Clipboard *_pObj;
public:
	inline wx_Clipboard() : wxClipboard(), _pObj(nullptr) {}
	~wx_Clipboard();
	inline void AssocWithGura(Object_wx_Clipboard *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Clipboard::~wx_Clipboard()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Clipboard::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxClipboard
//----------------------------------------------------------------------------
Gura_DeclareFunction(Clipboard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Clipboard));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Clipboard)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Clipboard *pEntity = new wx_Clipboard();
	Object_wx_Clipboard *pObj = Object_wx_Clipboard::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Clipboard(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_Clipboard, AddData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "data", VTYPE_wx_DataObject, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Clipboard, AddData)
{
	Signal &sig = env.GetSignal();
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDataObject *data = Object_wx_DataObject::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->AddData(data);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Clipboard, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Clipboard, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Clipboard, Close)
{
	Signal &sig = env.GetSignal();
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Clipboard, Flush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Clipboard, Flush)
{
	Signal &sig = env.GetSignal();
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Flush();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Clipboard, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "data", VTYPE_wx_DataObject, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Clipboard, GetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDataObject *data = Object_wx_DataObject::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->GetData(*data);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Clipboard, IsOpened)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Clipboard, IsOpened)
{
	Signal &sig = env.GetSignal();
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOpened();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Clipboard, IsSupported)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "format", VTYPE_wx_DataFormat, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Clipboard, IsSupported)
{
	Signal &sig = env.GetSignal();
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDataFormat *format = Object_wx_DataFormat::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsSupported(*format);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Clipboard, Open)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Clipboard, Open)
{
	Signal &sig = env.GetSignal();
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Open();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Clipboard, SetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "data", VTYPE_wx_DataObject, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Clipboard, SetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDataObject *data = Object_wx_DataObject::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->SetData(data);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Clipboard, UsePrimarySelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "primary", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Clipboard, UsePrimarySelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Clipboard *pThis = Object_wx_Clipboard::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool primary = true;
	if (args.IsValid(0)) primary = args.GetBoolean(0);
	pThis->GetEntity()->UsePrimarySelection(primary);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxClipboard
//----------------------------------------------------------------------------
Object_wx_Clipboard::~Object_wx_Clipboard()
{
}

Object *Object_wx_Clipboard::Clone() const
{
	return nullptr;
}

String Object_wx_Clipboard::ToString(bool exprFlag)
{
	String rtn("<wx.Clipboard:");
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
	return new Object_wx_Clipboard((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
