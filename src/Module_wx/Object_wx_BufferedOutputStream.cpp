//----------------------------------------------------------------------------
// wxBufferedOutputStream
// extracted from strmbfrd.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_BufferedOutputStream: public wxBufferedOutputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_BufferedOutputStream *_pObj;
public:
	inline wx_BufferedOutputStream(wxOutputStream& parent) : wxBufferedOutputStream(parent), _sig(NULL), _pObj(NULL) {}
	~wx_BufferedOutputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_BufferedOutputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BufferedOutputStream::~wx_BufferedOutputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_BufferedOutputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBufferedOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(BufferedOutputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_BufferedOutputStream));
	DeclareArg(env, "parent", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BufferedOutputStream)
{
	wxOutputStream *parent = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wx_BufferedOutputStream *pEntity = new wx_BufferedOutputStream(*parent);
	Object_wx_BufferedOutputStream *pObj = Object_wx_BufferedOutputStream::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_BufferedOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_BufferedOutputStream, SeekO)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BufferedOutputStream, SeekO)
{
	Object_wx_BufferedOutputStream *pSelf = Object_wx_BufferedOutputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	off_t pos = static_cast<off_t>(args.GetLong(0));
	wxSeekMode mode = static_cast<wxSeekMode>(args.GetInt(1));
	off_t rtn = pSelf->GetEntity()->SeekO(pos, mode);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_BufferedOutputStream, Sync)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BufferedOutputStream, Sync)
{
	Object_wx_BufferedOutputStream *pSelf = Object_wx_BufferedOutputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Sync();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxBufferedOutputStream
//----------------------------------------------------------------------------
Object_wx_BufferedOutputStream::~Object_wx_BufferedOutputStream()
{
}

Object *Object_wx_BufferedOutputStream::Clone() const
{
	return NULL;
}

String Object_wx_BufferedOutputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.BufferedOutputStream:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_BufferedOutputStream::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(BufferedOutputStream);
}

//----------------------------------------------------------------------------
// Class implementation for wxBufferedOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BufferedOutputStream)
{
	Gura_AssignMethod(wx_BufferedOutputStream, SeekO);
	Gura_AssignMethod(wx_BufferedOutputStream, Sync);
}

Gura_ImplementDescendantCreator(wx_BufferedOutputStream)
{
	return new Object_wx_BufferedOutputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
