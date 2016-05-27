//----------------------------------------------------------------------------
// wxHTMLDataObject
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLDATAOBJECT_H__
#define __CLASS_WX_HTMLDATAOBJECT_H__
#include <wx/dataobj.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHTMLDataObject
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HTMLDataObject);

//----------------------------------------------------------------------------
// Object declaration for wxHTMLDataObject
//----------------------------------------------------------------------------
class Object_wx_HTMLDataObject : public Object_wx_DataObjectSimple {
public:
	Gura_DeclareObjectAccessor(wx_HTMLDataObject)
public:
	inline Object_wx_HTMLDataObject(wxHTMLDataObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataObjectSimple(Gura_UserClass(wx_HTMLDataObject), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HTMLDataObject(Class *pClass, wxHTMLDataObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataObjectSimple(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HTMLDataObject();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHTMLDataObject *GetEntity() {
		return static_cast<wxHTMLDataObject *>(_pEntity);
	}
	inline wxHTMLDataObject *ReleaseEntity() {
		wxHTMLDataObject *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxHTMLDataObject");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
