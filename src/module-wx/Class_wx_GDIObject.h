//----------------------------------------------------------------------------
// wxGDIObject
// extracted from gdiobj.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GDIOBJECT_H__
#define __CLASS_WX_GDIOBJECT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGDIObject
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GDIObject);

//----------------------------------------------------------------------------
// Object declaration for wxGDIObject
//----------------------------------------------------------------------------
class Object_wx_GDIObject : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_GDIObject)
public:
	inline Object_wx_GDIObject(wxGDIObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_GDIObject), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GDIObject(Class *pClass, wxGDIObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GDIObject();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGDIObject *GetEntity() {
		return dynamic_cast<wxGDIObject *>(_pEntity);
	}
	inline wxGDIObject *ReleaseEntity() {
		wxGDIObject *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGDIObject");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
