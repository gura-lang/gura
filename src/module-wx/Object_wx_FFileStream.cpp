//----------------------------------------------------------------------------
// wxFFileStream
// extracted from ffilestr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FFileStream: public wxFFileStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FFileStream *_pObj;
public:
	inline wx_FFileStream(const wxString& iofileName) : wxFFileStream(iofileName), _sig(NULL), _pObj(NULL) {}
	~wx_FFileStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FFileStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FFileStream::~wx_FFileStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FFileStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFFileStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(FFileStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FFileStream));
	DeclareArg(env, "iofileName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FFileStream)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString iofileName = wxString::FromUTF8(args.GetString(0));
	wx_FFileStream *pEntity = new wx_FFileStream(iofileName);
	Object_wx_FFileStream *pObj = Object_wx_FFileStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FFileStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxFFileStream
//----------------------------------------------------------------------------
Object_wx_FFileStream::~Object_wx_FFileStream()
{
}

Object *Object_wx_FFileStream::Clone() const
{
	return NULL;
}

String Object_wx_FFileStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.FFileStream:");
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
// Class implementation for wxFFileStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FFileStream)
{
	Gura_AssignFunction(FFileStream);
}

Gura_ImplementDescendantCreator(wx_FFileStream)
{
	return new Object_wx_FFileStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
