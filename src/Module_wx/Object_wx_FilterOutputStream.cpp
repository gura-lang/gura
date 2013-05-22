//----------------------------------------------------------------------------
// wxFilterOutputStream
// extracted from fltoutst.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FilterOutputStream: public wxFilterOutputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FilterOutputStream *_pObj;
public:
	inline wx_FilterOutputStream(wxOutputStream& stream) : wxFilterOutputStream(stream), _sig(NULL), _pObj(NULL) {}
	inline wx_FilterOutputStream(wxOutputStream* stream) : wxFilterOutputStream(stream), _sig(NULL), _pObj(NULL) {}
	~wx_FilterOutputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FilterOutputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FilterOutputStream::~wx_FilterOutputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FilterOutputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFilterOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(FilterOutputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FilterOutputStream));
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FilterOutputStream)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wx_FilterOutputStream *pEntity = new wx_FilterOutputStream(*stream);
	Object_wx_FilterOutputStream *pObj = Object_wx_FilterOutputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FilterOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(FilterOutputStream_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FilterOutputStream));
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FilterOutputStream_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wx_FilterOutputStream *pEntity = new wx_FilterOutputStream(stream);
	Object_wx_FilterOutputStream *pObj = Object_wx_FilterOutputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FilterOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxFilterOutputStream
//----------------------------------------------------------------------------
Object_wx_FilterOutputStream::~Object_wx_FilterOutputStream()
{
}

Object *Object_wx_FilterOutputStream::Clone() const
{
	return NULL;
}

String Object_wx_FilterOutputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.FilterOutputStream:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_FilterOutputStream::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(FilterOutputStream);
	Gura_AssignFunction(FilterOutputStream_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxFilterOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FilterOutputStream)
{
}

Gura_ImplementDescendantCreator(wx_FilterOutputStream)
{
	return new Object_wx_FilterOutputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
