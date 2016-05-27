//----------------------------------------------------------------------------
// wxURLDataObject
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_URLDATAOBJECT_H__
#define __CLASS_WX_URLDATAOBJECT_H__
#include <wx/dataobj.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxURLDataObject
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_URLDataObject);

//----------------------------------------------------------------------------
// Object declaration for wxURLDataObject
//----------------------------------------------------------------------------
class Object_wx_URLDataObject : public Object_wx_TextDataObject {
public:
	Gura_DeclareObjectAccessor(wx_URLDataObject)
public:
	inline Object_wx_URLDataObject(wxURLDataObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TextDataObject(Gura_UserClass(wx_URLDataObject), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_URLDataObject(Class *pClass, wxURLDataObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TextDataObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_URLDataObject();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxURLDataObject *GetEntity() {
		return static_cast<wxURLDataObject *>(_pEntity);
	}
	inline wxURLDataObject *ReleaseEntity() {
		wxURLDataObject *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxURLDataObject");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
