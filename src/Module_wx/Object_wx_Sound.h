//----------------------------------------------------------------------------
// wxSound
// extracted from sound.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SOUND_H__
#define __OBJECT_WX_SOUND_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxSound *GetEntity() {
		return dynamic_cast<wxSound *>(_pEntity);
	}
	inline wxSound *ReleaseEntity() {
		wxSound *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSound");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
