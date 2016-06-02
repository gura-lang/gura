//----------------------------------------------------------------------------
// wxXmlResource
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_XMLRESOURCE_H__
#define __CLASS_WX_XMLRESOURCE_H__
#include <wx/xrc/xmlres.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxXmlResource
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_XmlResource);

//----------------------------------------------------------------------------
// Object declaration for wxXmlResource
//----------------------------------------------------------------------------
class Object_wx_XmlResource : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_XmlResource)
public:
	inline Object_wx_XmlResource(wxXmlResource *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_XmlResource), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_XmlResource(Class *pClass, wxXmlResource *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_XmlResource();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxXmlResource *GetEntity() {
		return static_cast<wxXmlResource *>(_pEntity);
	}
	inline wxXmlResource *ReleaseEntity() {
		wxXmlResource *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxXmlResource");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
