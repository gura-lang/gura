//----------------------------------------------------------------------------
// wxRichTextHeaderFooterData
// extracted from richtextheaderfooterdata.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RICHTEXTHEADERFOOTERDATA_H__
#define __OBJECT_WX_RICHTEXTHEADERFOOTERDATA_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextHeaderFooterData
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextHeaderFooterData);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextHeaderFooterData
//----------------------------------------------------------------------------
class Object_wx_RichTextHeaderFooterData : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_RichTextHeaderFooterData)
public:
	inline Object_wx_RichTextHeaderFooterData(wxRichTextHeaderFooterData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_RichTextHeaderFooterData), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextHeaderFooterData(Class *pClass, wxRichTextHeaderFooterData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextHeaderFooterData();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxRichTextHeaderFooterData *GetEntity() {
		return dynamic_cast<wxRichTextHeaderFooterData *>(_pEntity);
	}
	inline wxRichTextHeaderFooterData *ReleaseEntity() {
		wxRichTextHeaderFooterData *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRichTextHeaderFooterData");
		return true;
	}
};

}}

#endif
