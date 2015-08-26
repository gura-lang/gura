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
	//Gura::Signal *_pSig;
	Object_wx_FFileStream *_pObj;
public:
	inline wx_FFileStream(const wxString& iofileName) : wxFFileStream(iofileName), _pObj(nullptr) {}
	~wx_FFileStream();
	inline void AssocWithGura(Object_wx_FFileStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FFileStream::~wx_FFileStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FFileStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFFileStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(FFileStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FFileStream));
	DeclareArg(env, "iofileName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FFileStream)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString iofileName = wxString::FromUTF8(args.GetString(0));
	wx_FFileStream *pEntity = new wx_FFileStream(iofileName);
	Object_wx_FFileStream *pObj = Object_wx_FFileStream::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_FFileStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxFFileStream
//----------------------------------------------------------------------------
Object_wx_FFileStream::~Object_wx_FFileStream()
{
}

Object *Object_wx_FFileStream::Clone() const
{
	return nullptr;
}

String Object_wx_FFileStream::ToString(bool exprFlag)
{
	String rtn("<wx.FFileStream:");
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
// Class implementation for wxFFileStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FFileStream)
{
	Gura_AssignFunction(FFileStream);
}

Gura_ImplementDescendantCreator(wx_FFileStream)
{
	return new Object_wx_FFileStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
