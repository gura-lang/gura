//----------------------------------------------------------------------------
// wxAcceleratorEntry
// extracted from accel.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

int ArgToKeyCode(const Function *pFunc, Signal sig, Args &args, size_t iArg);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AcceleratorEntry: public wxAcceleratorEntry, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_AcceleratorEntry *_pObj;
public:
	inline wx_AcceleratorEntry() : wxAcceleratorEntry(), _sig(NULL), _pObj(NULL) {}
	inline wx_AcceleratorEntry(int flags, int keyCode, int cmd) : wxAcceleratorEntry(flags, keyCode, cmd), _sig(NULL), _pObj(NULL) {}
	~wx_AcceleratorEntry();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_AcceleratorEntry *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AcceleratorEntry::~wx_AcceleratorEntry()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_AcceleratorEntry::GuraObjectDeleted()
{
	_pObj = NULL;
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
	if (!CheckWxReady(sig)) return Value::Null;
	wx_AcceleratorEntry *pEntity = new wx_AcceleratorEntry();
	Object_wx_AcceleratorEntry *pObj = Object_wx_AcceleratorEntry::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_AcceleratorEntry(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
	int flags = args.GetInt(0);
	int keyCode = ArgToKeyCode(this, sig, args, 1);
	if (sig.IsSignalled()) return Value::Null;
	int cmd = args.GetInt(2);
	wx_AcceleratorEntry *pEntity = new wx_AcceleratorEntry(flags, keyCode, cmd);
	Object_wx_AcceleratorEntry *pObj = Object_wx_AcceleratorEntry::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_AcceleratorEntry(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_AcceleratorEntry, GetCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AcceleratorEntry, GetCommand)
{
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetCommand();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AcceleratorEntry, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AcceleratorEntry, GetFlags)
{
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetFlags();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AcceleratorEntry, GetKeyCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AcceleratorEntry, GetKeyCode)
{
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetKeyCode();
	return ReturnValue(env, sig, args, Value(rtn));
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
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int flags = args.GetInt(0);
	int keyCode = ArgToKeyCode(this, sig, args, 1);
	if (sig.IsSignalled()) return Value::Null;
	int cmd = args.GetInt(2);
	pThis->GetEntity()->Set(flags, keyCode, cmd);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxAcceleratorEntry
//----------------------------------------------------------------------------
Object_wx_AcceleratorEntry::~Object_wx_AcceleratorEntry()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_AcceleratorEntry::Clone() const
{
	return NULL;
}

String Object_wx_AcceleratorEntry::ToString(bool exprFlag)
{
	String rtn("<wx.AcceleratorEntry:");
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
	return new Object_wx_AcceleratorEntry((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

int ArgToKeyCode(const Function *pFunc, Signal sig, Args &args, size_t iArg)
{
	int keyCode = 0;
	if (args.IsInstanceOf(iArg, VTYPE_number)) {
		keyCode = args.GetInt(iArg);
	} else if (args.IsInstanceOf(iArg, VTYPE_string)) {
		const char *str = args.GetString(iArg);
		size_t len = ::strlen(str);
		if (len != 1) {
			sig.SetError(ERR_ValueError,
					"string for keyCode must contain only one character");
			return 0;
		}
		keyCode = str[0];
	} else {
		pFunc->SetError_ArgumentTypeByIndex(sig, args, iArg);
	}
	return keyCode;
}

Gura_EndModuleScope(wx)
