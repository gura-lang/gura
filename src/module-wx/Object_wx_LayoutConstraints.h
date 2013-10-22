//----------------------------------------------------------------------------
// wxLayoutConstraints
// extracted from layout.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_LAYOUTCONSTRAINTS_H__
#define __OBJECT_WX_LAYOUTCONSTRAINTS_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxLayoutConstraints
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_LayoutConstraints);

//----------------------------------------------------------------------------
// Object declaration for wxLayoutConstraints
//----------------------------------------------------------------------------
class Object_wx_LayoutConstraints : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_LayoutConstraints)
public:
	inline Object_wx_LayoutConstraints(wxLayoutConstraints *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_LayoutConstraints), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_LayoutConstraints(Class *pClass, wxLayoutConstraints *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_LayoutConstraints();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxLayoutConstraints *GetEntity() {
		return dynamic_cast<wxLayoutConstraints *>(_pEntity);
	}
	inline wxLayoutConstraints *ReleaseEntity() {
		wxLayoutConstraints *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxLayoutConstraints");
		return true;
	}
};

}}

#endif
