//----------------------------------------------------------------------------
// wxBufferedInputStream
// extracted from strmbfrd.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_BufferedInputStream: public wxBufferedInputStream, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_BufferedInputStream *_pObj;
public:
	~wx_BufferedInputStream();
	inline void AssocWithGura(Object_wx_BufferedInputStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BufferedInputStream::~wx_BufferedInputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_BufferedInputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBufferedInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBufferedInputStream
//----------------------------------------------------------------------------
Object_wx_BufferedInputStream::~Object_wx_BufferedInputStream()
{
}

Object *Object_wx_BufferedInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_BufferedInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.BufferedInputStream:");
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
// Class implementation for wxBufferedInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BufferedInputStream)
{
}

Gura_ImplementDescendantCreator(wx_BufferedInputStream)
{
	return new Object_wx_BufferedInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
