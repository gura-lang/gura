//----------------------------------------------------------------------------
// wxDataObjectSimple
// extracted from dobjsmpl.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DATAOBJECTSIMPLE_H__
#define __OBJECT_WX_DATAOBJECTSIMPLE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataObjectSimple
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataObjectSimple);

//----------------------------------------------------------------------------
// Object declaration for wxDataObjectSimple
//----------------------------------------------------------------------------
class Object_wx_DataObjectSimple : public Object_wx_DataObject {
public:
	Gura_DeclareObjectAccessor(wx_DataObjectSimple)
public:
	inline Object_wx_DataObjectSimple(wxDataObjectSimple *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataObject(Gura_UserClass(wx_DataObjectSimple), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataObjectSimple(Class *pClass, wxDataObjectSimple *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataObjectSimple();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDataObjectSimple *GetEntity() {
		return dynamic_cast<wxDataObjectSimple *>(_pEntity);
	}
	inline wxDataObjectSimple *ReleaseEntity() {
		wxDataObjectSimple *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDataObjectSimple");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
