//----------------------------------------------------------------------------
// wxTarInputStream
// extracted from tarstrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TarInputStream: public wxTarInputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TarInputStream *_pObj;
public:
	inline wx_TarInputStream(wxInputStream& stream, wxMBConv& conv) : wxTarInputStream(stream, conv), _sig(NULL), _pObj(NULL) {}
	inline wx_TarInputStream(wxInputStream* stream, wxMBConv& conv) : wxTarInputStream(stream, conv), _sig(NULL), _pObj(NULL) {}
	~wx_TarInputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TarInputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TarInputStream::~wx_TarInputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TarInputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTarInputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(TarInputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TarInputStream));
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TarInputStream)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxMBConv *conv = (wxMBConv *)(&wxConvLocal);
	if (args.IsValid(1)) conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	wx_TarInputStream *pEntity = new wx_TarInputStream(*stream, *conv);
	Object_wx_TarInputStream *pObj = Object_wx_TarInputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TarInputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(TarInputStream_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TarInputStream));
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TarInputStream_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxMBConv *conv = (wxMBConv *)(&wxConvLocal);
	if (args.IsValid(1)) conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	wx_TarInputStream *pEntity = new wx_TarInputStream(stream, *conv);
	Object_wx_TarInputStream *pObj = Object_wx_TarInputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TarInputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_TarInputStream, CloseEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarInputStream, CloseEntry)
{
	Object_wx_TarInputStream *pThis = Object_wx_TarInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CloseEntry();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarInputStream, GetNextEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarInputStream, GetNextEntry)
{
	Object_wx_TarInputStream *pThis = Object_wx_TarInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTarEntry *rtn = (wxTarEntry *)pThis->GetEntity()->GetNextEntry();
	return ReturnValue(env, sig, args, Value(new Object_wx_TarEntry(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_TarInputStream, OpenEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "entry", VTYPE_wx_TarEntry, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarInputStream, OpenEntry)
{
	Object_wx_TarInputStream *pThis = Object_wx_TarInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTarEntry *entry = Object_wx_TarEntry::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->OpenEntry(*entry);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxTarInputStream
//----------------------------------------------------------------------------
Object_wx_TarInputStream::~Object_wx_TarInputStream()
{
}

Object *Object_wx_TarInputStream::Clone() const
{
	return NULL;
}

String Object_wx_TarInputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TarInputStream:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_TarInputStream::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(TarInputStream);
	Gura_AssignFunction(TarInputStream_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxTarInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TarInputStream)
{
	Gura_AssignMethod(wx_TarInputStream, CloseEntry);
	Gura_AssignMethod(wx_TarInputStream, GetNextEntry);
	Gura_AssignMethod(wx_TarInputStream, OpenEntry);
}

Gura_ImplementDescendantCreator(wx_TarInputStream)
{
	return new Object_wx_TarInputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
