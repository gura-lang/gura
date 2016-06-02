//----------------------------------------------------------------------------
// wxXmlDocument
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_XMLDOCUMENT_H__
#define __CLASS_WX_XMLDOCUMENT_H__
#include <wx/xml/xml.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxXmlDocument
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_XmlDocument);

//----------------------------------------------------------------------------
// Object declaration for wxXmlDocument
//----------------------------------------------------------------------------
class Object_wx_XmlDocument : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_XmlDocument)
public:
	inline Object_wx_XmlDocument(wxXmlDocument *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_XmlDocument), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_XmlDocument(Class *pClass, wxXmlDocument *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_XmlDocument();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxXmlDocument *GetEntity() {
		return static_cast<wxXmlDocument *>(_pEntity);
	}
	inline wxXmlDocument *ReleaseEntity() {
		wxXmlDocument *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxXmlDocument");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
