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
	Gura::Signal _sig;
	Object_wx_BufferedInputStream *_pObj;
public:
	~wx_BufferedInputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_BufferedInputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BufferedInputStream::~wx_BufferedInputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_BufferedInputStream::GuraObjectDeleted()
{
	_pObj = NULL;
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
	return NULL;
}

String Object_wx_BufferedInputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.BufferedInputStream:");
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
// Class implementation for wxBufferedInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BufferedInputStream)
{
}

Gura_ImplementDescendantCreator(wx_BufferedInputStream)
{
	return new Object_wx_BufferedInputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
