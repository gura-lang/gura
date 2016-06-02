//----------------------------------------------------------------------------
// wxXmlResourceHandler
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_XMLRESOURCEHANDLER_H__
#define __CLASS_WX_XMLRESOURCEHANDLER_H__
#include <wx/xrc/xmlres.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxXmlResourceHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_XmlResourceHandler);

//----------------------------------------------------------------------------
// Object declaration for wxXmlResourceHandler
//----------------------------------------------------------------------------
class Object_wx_XmlResourceHandler : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_XmlResourceHandler)
public:
	inline Object_wx_XmlResourceHandler(wxXmlResourceHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_XmlResourceHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_XmlResourceHandler(Class *pClass, wxXmlResourceHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_XmlResourceHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxXmlResourceHandler *GetEntity() {
		return static_cast<wxXmlResourceHandler *>(_pEntity);
	}
	inline wxXmlResourceHandler *ReleaseEntity() {
		wxXmlResourceHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxXmlResourceHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
