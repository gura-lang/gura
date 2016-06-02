//----------------------------------------------------------------------------
// wxSound
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SOUND_H__
#define __CLASS_WX_SOUND_H__
#include <wx/sound.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSound
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Sound);

//----------------------------------------------------------------------------
// Object declaration for wxSound
//----------------------------------------------------------------------------
class Object_wx_Sound : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Sound)
public:
	inline Object_wx_Sound(wxSound *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Sound), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Sound(Class *pClass, wxSound *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Sound();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSound *GetEntity() {
		return static_cast<wxSound *>(_pEntity);
	}
	inline wxSound *ReleaseEntity() {
		wxSound *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxSound");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
