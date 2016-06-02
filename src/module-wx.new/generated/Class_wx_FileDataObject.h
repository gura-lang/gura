//----------------------------------------------------------------------------
// wxFileDataObject
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FILEDATAOBJECT_H__
#define __CLASS_WX_FILEDATAOBJECT_H__
#include <wx/dataobj.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFileDataObject
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FileDataObject);

//----------------------------------------------------------------------------
// Object declaration for wxFileDataObject
//----------------------------------------------------------------------------
class Object_wx_FileDataObject : public Object_wx_DataObjectSimple {
public:
	Gura_DeclareObjectAccessor(wx_FileDataObject)
public:
	inline Object_wx_FileDataObject(wxFileDataObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataObjectSimple(Gura_UserClass(wx_FileDataObject), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FileDataObject(Class *pClass, wxFileDataObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataObjectSimple(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FileDataObject();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFileDataObject *GetEntity() {
		return static_cast<wxFileDataObject *>(_pEntity);
	}
	inline wxFileDataObject *ReleaseEntity() {
		wxFileDataObject *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxFileDataObject");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
