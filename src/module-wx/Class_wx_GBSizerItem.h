//----------------------------------------------------------------------------
// wxGBSizerItem
// extracted from gbsizeritem.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GBSIZERITEM_H__
#define __CLASS_WX_GBSIZERITEM_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGBSizerItem
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GBSizerItem);

//----------------------------------------------------------------------------
// Object declaration for wxGBSizerItem
//----------------------------------------------------------------------------
class Object_wx_GBSizerItem : public Object_wx_SizerItem {
public:
	Gura_DeclareObjectAccessor(wx_GBSizerItem)
public:
	inline Object_wx_GBSizerItem(wxGBSizerItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SizerItem(Gura_UserClass(wx_GBSizerItem), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GBSizerItem(Class *pClass, wxGBSizerItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SizerItem(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GBSizerItem();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGBSizerItem *GetEntity() {
		return dynamic_cast<wxGBSizerItem *>(_pEntity);
	}
	inline wxGBSizerItem *ReleaseEntity() {
		wxGBSizerItem *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGBSizerItem");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
