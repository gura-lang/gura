//----------------------------------------------------------------------------
// wxColour
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_COLOUR_H__
#define __CLASS_WX_COLOUR_H__
#include <wx/colour.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxColour
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Colour);

//----------------------------------------------------------------------------
// Object declaration for wxColour
//----------------------------------------------------------------------------
class Object_wx_Colour : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Colour)
public:
	inline Object_wx_Colour(wxColour *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Colour), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Colour(Class *pClass, wxColour *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Colour();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxColour *GetEntity() {
		return static_cast<wxColour *>(_pEntity);
	}
	inline wxColour *ReleaseEntity() {
		wxColour *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxColour");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
