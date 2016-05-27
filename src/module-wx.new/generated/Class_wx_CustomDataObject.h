//----------------------------------------------------------------------------
// wxCustomDataObject
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CUSTOMDATAOBJECT_H__
#define __CLASS_WX_CUSTOMDATAOBJECT_H__
#include <wx/dataobj.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCustomDataObject
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CustomDataObject);

//----------------------------------------------------------------------------
// Object declaration for wxCustomDataObject
//----------------------------------------------------------------------------
class Object_wx_CustomDataObject : public Object_wx_DataObjectSimple {
public:
	Gura_DeclareObjectAccessor(wx_CustomDataObject)
public:
	inline Object_wx_CustomDataObject(wxCustomDataObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataObjectSimple(Gura_UserClass(wx_CustomDataObject), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_CustomDataObject(Class *pClass, wxCustomDataObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataObjectSimple(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_CustomDataObject();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxCustomDataObject *GetEntity() {
		return static_cast<wxCustomDataObject *>(_pEntity);
	}
	inline wxCustomDataObject *ReleaseEntity() {
		wxCustomDataObject *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxCustomDataObject");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
