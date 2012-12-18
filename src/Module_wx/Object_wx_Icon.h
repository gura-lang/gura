//----------------------------------------------------------------------------
// wxIcon
// extracted from icon.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_ICON_H__
#define __OBJECT_WX_ICON_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxIcon
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Icon);

//----------------------------------------------------------------------------
// Object declaration for wxIcon
//----------------------------------------------------------------------------
class Object_wx_Icon : public Object_wx_GDIObject {
public:
	Gura_DeclareObjectAccessor(wx_Icon)
public:
	inline Object_wx_Icon(wxIcon *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(Gura_UserClass(wx_Icon), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Icon(Class *pClass, wxIcon *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Icon();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxIcon *GetEntity() {
		return dynamic_cast<wxIcon *>(_pEntity);
	}
	inline wxIcon *ReleaseEntity() {
		wxIcon *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxIcon");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
