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
	//Gura::Signal *_pSig;
	Object_wx_StringInputStream *_pObj;
public:
	inline wx_StringInputStream(const wxString& s) : wxStringInputStream(s), _pObj(nullptr) {}
	~wx_StringInputStream();
	inline void AssocWithGura(Object_wx_StringInputStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StringInputStream::~wx_StringInputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_StringInputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStringInputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(StringInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StringInputStream));
	DeclareArg(env, "s", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StringInputStream)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString s = wxString::FromUTF8(arg.GetString(0));
	wx_StringInputStream *pEntity = new wx_StringInputStream(s);
	Object_wx_StringInputStream *pObj = Object_wx_StringInputStream::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_StringInputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxStringInputStream
//----------------------------------------------------------------------------
Object_wx_StringInputStream::~Object_wx_StringInputStream()
{
}

Object *Object_wx_StringInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_StringInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.StringInputStream:");
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
// Class implementation for wxStringInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringInputStream)
{
	Gura_AssignFunction(StringInputStream);
}

Gura_ImplementDescendantCreator(wx_StringInputStream)
{
	return new Object_wx_StringInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
