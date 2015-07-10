//----------------------------------------------------------------------------
// wxDataObjectComposite
// extracted from dobjcomp.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAOBJECTCOMPOSITE_H__
#define __CLASS_WX_DATAOBJECTCOMPOSITE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataObjectComposite
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataObjectComposite);

//----------------------------------------------------------------------------
// Object declaration for wxDataObjectComposite
//----------------------------------------------------------------------------
class Object_wx_DataObjectComposite : public Object_wx_DataObject {
public:
	Gura_DeclareObjectAccessor(wx_DataObjectComposite)
public:
	inline Object_wx_DataObjectComposite(wxDataObjectComposite *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataObject(Gura_UserClass(wx_DataObjectComposite), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataObjectComposite(Class *pClass, wxDataObjectComposite *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataObjectComposite();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataObjectComposite *GetEntity() {
		return dynamic_cast<wxDataObjectComposite *>(_pEntity);
	}
	inline wxDataObjectComposite *ReleaseEntity() {
		wxDataObjectComposite *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDataObjectComposite");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
