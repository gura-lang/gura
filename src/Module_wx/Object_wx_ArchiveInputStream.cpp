//----------------------------------------------------------------------------
// wxArchiveInputStream
// extracted from archive.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ArchiveInputStream: public wxArchiveInputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ArchiveInputStream *_pObj;
public:
	~wx_ArchiveInputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ArchiveInputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ArchiveInputStream::~wx_ArchiveInputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ArchiveInputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveInputStream
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ArchiveInputStream, CloseEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveInputStream, CloseEntry)
{
	Object_wx_ArchiveInputStream *pSelf = Object_wx_ArchiveInputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->CloseEntry();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ArchiveInputStream, GetNextEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveInputStream, GetNextEntry)
{
	Object_wx_ArchiveInputStream *pSelf = Object_wx_ArchiveInputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxArchiveEntry *rtn = (wxArchiveEntry *)pSelf->GetEntity()->GetNextEntry();
	return ReturnValue(env, sig, args, Value(new Object_wx_ArchiveEntry(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ArchiveInputStream, OpenEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "entry", VTYPE_wx_ArchiveEntry, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveInputStream, OpenEntry)
{
	Object_wx_ArchiveInputStream *pSelf = Object_wx_ArchiveInputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxArchiveEntry *entry = Object_wx_ArchiveEntry::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->OpenEntry(*entry);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxArchiveInputStream
//----------------------------------------------------------------------------
Object_wx_ArchiveInputStream::~Object_wx_ArchiveInputStream()
{
}

Object *Object_wx_ArchiveInputStream::Clone() const
{
	return NULL;
}

String Object_wx_ArchiveInputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ArchiveInputStream:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ArchiveInputStream::OnModuleEntry(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxArchiveInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveInputStream)
{
	Gura_AssignMethod(wx_ArchiveInputStream, CloseEntry);
	Gura_AssignMethod(wx_ArchiveInputStream, GetNextEntry);
	Gura_AssignMethod(wx_ArchiveInputStream, OpenEntry);
}

Gura_ImplementDescendantCreator(wx_ArchiveInputStream)
{
	return new Object_wx_ArchiveInputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
