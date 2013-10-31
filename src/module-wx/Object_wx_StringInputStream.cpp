//----------------------------------------------------------------------------
// wxStringInputStream
// extracted from sistream.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StringInputStream: public wxStringInputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_StringInputStream *_pObj;
public:
	inline wx_StringInputStream(const wxString& s) : wxStringInputStream(s), _sig(NULL), _pObj(NULL) {}
	~wx_StringInputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_StringInputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StringInputStream::~wx_StringInputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_StringInputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStringInputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(StringInputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StringInputStream));
	DeclareArg(env, "s", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StringInputStream)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString s = wxString::FromUTF8(args.GetString(0));
	wx_StringInputStream *pEntity = new wx_StringInputStream(s);
	Object_wx_StringInputStream *pObj = Object_wx_StringInputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StringInputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxStringInputStream
//----------------------------------------------------------------------------
Object_wx_StringInputStream::~Object_wx_StringInputStream()
{
}

Object *Object_wx_StringInputStream::Clone() const
{
	return NULL;
}

String Object_wx_StringInputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.StringInputStream:");
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
// Class implementation for wxStringInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringInputStream)
{
	Gura_AssignFunction(StringInputStream);
}

Gura_ImplementDescendantCreator(wx_StringInputStream)
{
	return new Object_wx_StringInputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
