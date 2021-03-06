//----------------------------------------------------------------------------
// wxArchiveInputStream
// extracted from archive.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ArchiveInputStream: public wxArchiveInputStream, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ArchiveInputStream *_pObj;
public:
	~wx_ArchiveInputStream();
	inline void AssocWithGura(Object_wx_ArchiveInputStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ArchiveInputStream::~wx_ArchiveInputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ArchiveInputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveInputStream
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ArchiveInputStream, CloseEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveInputStream, CloseEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveInputStream *pThis = Object_wx_ArchiveInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CloseEntry();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ArchiveInputStream, GetNextEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveInputStream, GetNextEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveInputStream *pThis = Object_wx_ArchiveInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArchiveEntry *rtn = (wxArchiveEntry *)pThis->GetEntity()->GetNextEntry();
	return ReturnValue(env, arg, Value(new Object_wx_ArchiveEntry(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ArchiveInputStream, OpenEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "entry", VTYPE_wx_ArchiveEntry, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveInputStream, OpenEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveInputStream *pThis = Object_wx_ArchiveInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArchiveEntry *entry = Object_wx_ArchiveEntry::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->OpenEntry(*entry);
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxArchiveInputStream
//----------------------------------------------------------------------------
Object_wx_ArchiveInputStream::~Object_wx_ArchiveInputStream()
{
}

Object *Object_wx_ArchiveInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_ArchiveInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.ArchiveInputStream:");
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
	return new Object_wx_ArchiveInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
