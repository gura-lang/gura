//----------------------------------------------------------------------------
// wxGridellStringRenderer
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridellStringRenderer: public wxGridellStringRenderer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_GridellStringRenderer *_pObj;
public:
	~wx_GridellStringRenderer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridellStringRenderer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridellStringRenderer::~wx_GridellStringRenderer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GridellStringRenderer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridellStringRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridellStringRenderer
//----------------------------------------------------------------------------
Object_wx_GridellStringRenderer::~Object_wx_GridellStringRenderer()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_GridellStringRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridellStringRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridellStringRenderer:");
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
// Class implementation for wxGridellStringRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridellStringRenderer)
{
}

Gura_ImplementDescendantCreator(wx_GridellStringRenderer)
{
	return new Object_wx_GridellStringRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
