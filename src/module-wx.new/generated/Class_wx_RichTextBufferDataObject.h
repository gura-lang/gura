//----------------------------------------------------------------------------
// wxRichTextBufferDataObject
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTBUFFERDATAOBJECT_H__
#define __CLASS_WX_RICHTEXTBUFFERDATAOBJECT_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextBufferDataObject
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextBufferDataObject);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextBufferDataObject
//----------------------------------------------------------------------------
class Object_wx_RichTextBufferDataObject : public Object_wx_DataObjectSimple {
public:
	Gura_DeclareObjectAccessor(wx_RichTextBufferDataObject)
public:
	inline Object_wx_RichTextBufferDataObject(wxRichTextBufferDataObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataObjectSimple(Gura_UserClass(wx_RichTextBufferDataObject), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextBufferDataObject(Class *pClass, wxRichTextBufferDataObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataObjectSimple(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextBufferDataObject();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextBufferDataObject *GetEntity() {
		return static_cast<wxRichTextBufferDataObject *>(_pEntity);
	}
	inline wxRichTextBufferDataObject *ReleaseEntity() {
		wxRichTextBufferDataObject *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRichTextBufferDataObject");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
