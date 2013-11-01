//----------------------------------------------------------------------------
// wxSizerItem
// extracted from sizeritem.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SIZERITEM_H__
#define __OBJECT_WX_SIZERITEM_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSizerItem
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SizerItem);

//----------------------------------------------------------------------------
// Object declaration for wxSizerItem
//----------------------------------------------------------------------------
class Object_wx_SizerItem : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_SizerItem)
public:
	inline Object_wx_SizerItem(wxSizerItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_SizerItem), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SizerItem(Class *pClass, wxSizerItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SizerItem();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSizerItem *GetEntity() {
		return dynamic_cast<wxSizerItem *>(_pEntity);
	}
	inline wxSizerItem *ReleaseEntity() {
		wxSizerItem *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSizerItem");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
