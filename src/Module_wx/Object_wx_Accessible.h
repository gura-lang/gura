//----------------------------------------------------------------------------
// wxAccessible
// extracted from accessible.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_ACCESSIBLE_H__
#define __OBJECT_WX_ACCESSIBLE_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAccessible
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Accessible);

//----------------------------------------------------------------------------
// Object declaration for wxAccessible
//----------------------------------------------------------------------------
class Object_wx_Accessible : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Accessible)
public:
	inline Object_wx_Accessible(wxAccessible *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Accessible), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Accessible(Class *pClass, wxAccessible *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Accessible();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxAccessible *GetEntity() {
		return dynamic_cast<wxAccessible *>(_pEntity);
	}
	inline wxAccessible *ReleaseEntity() {
		wxAccessible *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxAccessible");
		return true;
	}
};

}}

#endif
