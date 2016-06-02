//----------------------------------------------------------------------------
// wxPGProperty
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PGPROPERTY_H__
#define __CLASS_WX_PGPROPERTY_H__
#include <wx/propgrid/property.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPGProperty
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PGProperty);

//----------------------------------------------------------------------------
// Object declaration for wxPGProperty
//----------------------------------------------------------------------------
class Object_wx_PGProperty : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_PGProperty)
public:
	inline Object_wx_PGProperty(wxPGProperty *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_PGProperty), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PGProperty(Class *pClass, wxPGProperty *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PGProperty();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPGProperty *GetEntity() {
		return static_cast<wxPGProperty *>(_pEntity);
	}
	inline wxPGProperty *ReleaseEntity() {
		wxPGProperty *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPGProperty");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
