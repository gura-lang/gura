//----------------------------------------------------------------------------
// wxRichTextParagraphLayoutBox
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextParagraphLayoutBox: public wxRichTextParagraphLayoutBox, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RichTextParagraphLayoutBox *_pObj;
public:
	~wx_RichTextParagraphLayoutBox();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextParagraphLayoutBox *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextParagraphLayoutBox::~wx_RichTextParagraphLayoutBox()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RichTextParagraphLayoutBox::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextParagraphLayoutBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextParagraphLayoutBox
//----------------------------------------------------------------------------
Object_wx_RichTextParagraphLayoutBox::~Object_wx_RichTextParagraphLayoutBox()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_RichTextParagraphLayoutBox::Clone() const
{
	return NULL;
}

String Object_wx_RichTextParagraphLayoutBox::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextParagraphLayoutBox:");
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
// Class implementation for wxRichTextParagraphLayoutBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextParagraphLayoutBox)
{
}

Gura_ImplementDescendantCreator(wx_RichTextParagraphLayoutBox)
{
	return new Object_wx_RichTextParagraphLayoutBox((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
