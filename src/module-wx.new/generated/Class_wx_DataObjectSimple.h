//----------------------------------------------------------------------------
// wxDataObjectSimple
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAOBJECTSIMPLE_H__
#define __CLASS_WX_DATAOBJECTSIMPLE_H__
#include <wx/dataobj.h>

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
	virtual String ToString(bool exprFlag);
	inline wxDataObjectSimple *GetEntity() {
		return static_cast<wxDataObjectSimple *>(_pEntity);
	}
	inline wxDataObjectSimple *ReleaseEntity() {
		wxDataObjectSimple *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDataObjectSimple");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
