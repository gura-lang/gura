//----------------------------------------------------------------------------
// wxMenuItem
// extracted from menuitem.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_MENUITEM_H__
#define __OBJECT_WX_MENUITEM_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMenuItem
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MenuItem);

//----------------------------------------------------------------------------
// Object declaration for wxMenuItem
//----------------------------------------------------------------------------
class Object_wx_MenuItem : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_MenuItem)
public:
	inline Object_wx_MenuItem(wxMenuItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_MenuItem), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MenuItem(Class *pClass, wxMenuItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MenuItem();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMenuItem *GetEntity() {
		return dynamic_cast<wxMenuItem *>(_pEntity);
	}
	inline wxMenuItem *ReleaseEntity() {
		wxMenuItem *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxMenuItem");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
