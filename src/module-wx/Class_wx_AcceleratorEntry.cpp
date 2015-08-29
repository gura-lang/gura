//----------------------------------------------------------------------------
// wxAcceleratorEntry
// extracted from accel.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

int ArgToKeyCode(const Function *pFunc, Signal &sig, Argument &arg, size_t iArg);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AcceleratorEntry: public wxAcceleratorEntry, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_AcceleratorEntry *_pObj;
public:
	inline wx_AcceleratorEntry() : wxAcceleratorEntry(), _pObj(nullptr) {}
	inline wx_AcceleratorEntry(int flags, int keyCode, int cmd) : wxAcceleratorEntry(flags, keyCode, cmd), _pObj(nullptr) {}
	~wx_AcceleratorEntry();
	inline void AssocWithGura(Object_wx_AcceleratorEntry *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AcceleratorEntry::~wx_AcceleratorEntry()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_AcceleratorEntry::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAcceleratorEntry
//----------------------------------------------------------------------------
Gura_DeclareFunction(AcceleratorEntryEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AcceleratorEntry));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AcceleratorEntryEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_AcceleratorEntry *pEntity = new wx_AcceleratorEntry();
	Object_wx_AcceleratorEntry *pObj = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_AcceleratorEntry(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(AcceleratorEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_AcceleratorEntry));
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "keyCode", VTYPE_any, OCCUR_Once);
	DeclareArg(env, "cmd", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AcceleratorEntry)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int flags = arg.GetInt(0);
	int keyCode = ArgToKeyCode(this, sig, arg, 1);
	if (sig.IsSignalled()) return Value::Nil;
	int cmd = arg.GetInt(2);
	wx_AcceleratorEntry *pEntity = new wx_AcceleratorEntry(flags, keyCode, cmd);
	Object_wx_AcceleratorEntry *pObj = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_AcceleratorEntry(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_AcceleratorEntry, GetCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AcceleratorEntry, GetCommand)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetCommand();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AcceleratorEntry, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AcceleratorEntry, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetFlags();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AcceleratorEntry, GetKeyCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AcceleratorEntry, GetKeyCode)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetKeyCode();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_AcceleratorEntry, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "keyCode", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "cmd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorEntry, Set)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int flags = arg.GetInt(0);
	int keyCode = ArgToKeyCode(this, sig, arg, 1);
	if (sig.IsSignalled()) return Value::Nil;
	int cmd = arg.GetInt(2);
	pThis->GetEntity()->Set(flags, keyCode, cmd);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxAcceleratorEntry
//----------------------------------------------------------------------------
Object_wx_AcceleratorEntry::~Object_wx_AcceleratorEntry()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_AcceleratorEntry::Clone() const
{
	return nullptr;
}

String Object_wx_AcceleratorEntry::ToString(bool exprFlag)
{
	String rtn("<wx.AcceleratorEntry:");
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
// Class implementation for wxAcceleratorEntry
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AcceleratorEntry)
{
	Gura_AssignFunction(AcceleratorEntryEmpty);
	Gura_AssignFunction(AcceleratorEntry);
	Gura_AssignMethod(wx_AcceleratorEntry, GetCommand);
	Gura_AssignMethod(wx_AcceleratorEntry, GetFlags);
	Gura_AssignMethod(wx_AcceleratorEntry, GetKeyCode);
	Gura_AssignMethod(wx_AcceleratorEntry, Set);
}

Gura_ImplementDescendantCreator(wx_AcceleratorEntry)
{
	return new Object_wx_AcceleratorEntry((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

int ArgToKeyCode(const Function *pFunc, Signal &sig, Argument &arg, size_t iArg)
{
	int keyCode = 0;
	if (arg.IsInstanceOf(iArg, VTYPE_number)) {
		keyCode = arg.GetInt(iArg);
	} else if (arg.IsInstanceOf(iArg, VTYPE_string)) {
		const char *str = arg.GetString(iArg);
		size_t len = ::strlen(str);
		if (len != 1) {
			sig.SetError(ERR_ValueError,
					"string for keyCode must contain only one character");
			return 0;
		}
		keyCode = str[0];
	} else {
		pFunc->SetError_ArgumentTypeByIndex(sig, arg, iArg);
	}
	return keyCode;
}

Gura_EndModuleScope(wx)
