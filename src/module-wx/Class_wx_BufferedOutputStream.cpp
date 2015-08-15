//----------------------------------------------------------------------------
// wxBufferedOutputStream
// extracted from strmbfrd.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_BufferedOutputStream: public wxBufferedOutputStream, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_BufferedOutputStream *_pObj;
public:
	inline wx_BufferedOutputStream(wxOutputStream& parent) : wxBufferedOutputStream(parent), _pObj(nullptr) {}
	~wx_BufferedOutputStream();
	inline void AssocWithGura(Object_wx_BufferedOutputStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BufferedOutputStream::~wx_BufferedOutputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_BufferedOutputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBufferedOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(BufferedOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_BufferedOutputStream));
	DeclareArg(env, "parent", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BufferedOutputStream)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxOutputStream *parent = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wx_BufferedOutputStream *pEntity = new wx_BufferedOutputStream(*parent);
	Object_wx_BufferedOutputStream *pObj = Object_wx_BufferedOutputStream::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_BufferedOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_BufferedOutputStream, SeekO)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BufferedOutputStream, SeekO)
{
	Signal &sig = env.GetSignal();
	Object_wx_BufferedOutputStream *pThis = Object_wx_BufferedOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	off_t pos = static_cast<off_t>(args.GetLong(0));
	wxSeekMode mode = static_cast<wxSeekMode>(args.GetInt(1));
	off_t rtn = pThis->GetEntity()->SeekO(pos, mode);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_BufferedOutputStream, Sync)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BufferedOutputStream, Sync)
{
	Signal &sig = env.GetSignal();
	Object_wx_BufferedOutputStream *pThis = Object_wx_BufferedOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Sync();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxBufferedOutputStream
//----------------------------------------------------------------------------
Object_wx_BufferedOutputStream::~Object_wx_BufferedOutputStream()
{
}

Object *Object_wx_BufferedOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_BufferedOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.BufferedOutputStream:");
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
// Class implementation for wxBufferedOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BufferedOutputStream)
{
	Gura_AssignFunction(BufferedOutputStream);
	Gura_AssignMethod(wx_BufferedOutputStream, SeekO);
	Gura_AssignMethod(wx_BufferedOutputStream, Sync);
}

Gura_ImplementDescendantCreator(wx_BufferedOutputStream)
{
	return new Object_wx_BufferedOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
