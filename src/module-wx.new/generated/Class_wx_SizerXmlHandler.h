//----------------------------------------------------------------------------
// wxSizerXmlHandler
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SIZERXMLHANDLER_H__
#define __CLASS_WX_SIZERXMLHANDLER_H__
#include <wx/xrc/xh_sizer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSizerXmlHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SizerXmlHandler);

//----------------------------------------------------------------------------
// Object declaration for wxSizerXmlHandler
//----------------------------------------------------------------------------
class Object_wx_SizerXmlHandler : public Object_wx_XmlResourceHandler {
public:
	Gura_DeclareObjectAccessor(wx_SizerXmlHandler)
public:
	inline Object_wx_SizerXmlHandler(wxSizerXmlHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_XmlResourceHandler(Gura_UserClass(wx_SizerXmlHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SizerXmlHandler(Class *pClass, wxSizerXmlHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_XmlResourceHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SizerXmlHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSizerXmlHandler *GetEntity() {
		return static_cast<wxSizerXmlHandler *>(_pEntity);
	}
	inline wxSizerXmlHandler *ReleaseEntity() {
		wxSizerXmlHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxSizerXmlHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
