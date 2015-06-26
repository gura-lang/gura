//----------------------------------------------------------------------------
// wxRichTextImageBlock
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextImageBlock: public wxRichTextImageBlock, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RichTextImageBlock *_pObj;
public:
	~wx_RichTextImageBlock();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextImageBlock *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextImageBlock::~wx_RichTextImageBlock()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RichTextImageBlock::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextImageBlock
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextImageBlock
//----------------------------------------------------------------------------
Object_wx_RichTextImageBlock::~Object_wx_RichTextImageBlock()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_RichTextImageBlock::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextImageBlock::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextImageBlock:");
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
// Class implementation for wxRichTextImageBlock
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextImageBlock)
{
}

Gura_ImplementDescendantCreator(wx_RichTextImageBlock)
{
	return new Object_wx_RichTextImageBlock((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
