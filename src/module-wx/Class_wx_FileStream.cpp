//----------------------------------------------------------------------------
// wxFileStream
// extracted from filestrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FileStream: public wxFileStream, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_FileStream *_pObj;
public:
	inline wx_FileStream(const wxString& iofileName) : wxFileStream(iofileName), _pObj(nullptr) {}
	~wx_FileStream();
	inline void AssocWithGura(Object_wx_FileStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FileStream::~wx_FileStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FileStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFileStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(FileStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FileStream));
	DeclareArg(env, "iofileName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileStream)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString iofileName = wxString::FromUTF8(arg.GetString(0));
	wx_FileStream *pEntity = new wx_FileStream(iofileName);
	Object_wx_FileStream *pObj = Object_wx_FileStream::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_FileStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxFileStream
//----------------------------------------------------------------------------
Object_wx_FileStream::~Object_wx_FileStream()
{
}

Object *Object_wx_FileStream::Clone() const
{
	return nullptr;
}

String Object_wx_FileStream::ToString(bool exprFlag)
{
	String rtn("<wx.FileStream:");
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
// Class implementation for wxFileStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileStream)
{
	Gura_AssignFunction(FileStream);
}

Gura_ImplementDescendantCreator(wx_FileStream)
{
	return new Object_wx_FileStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
