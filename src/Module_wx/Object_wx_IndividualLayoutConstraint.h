//----------------------------------------------------------------------------
// wxIndividualLayoutConstraint
// extracted from ilayout.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_INDIVIDUALLAYOUTCONSTRAINT_H__
#define __OBJECT_WX_INDIVIDUALLAYOUTCONSTRAINT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxIndividualLayoutConstraint
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_IndividualLayoutConstraint);

//----------------------------------------------------------------------------
// Object declaration for wxIndividualLayoutConstraint
//----------------------------------------------------------------------------
class Object_wx_IndividualLayoutConstraint : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_IndividualLayoutConstraint)
public:
	inline Object_wx_IndividualLayoutConstraint(wxIndividualLayoutConstraint *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_IndividualLayoutConstraint), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_IndividualLayoutConstraint(Class *pClass, wxIndividualLayoutConstraint *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_IndividualLayoutConstraint();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxIndividualLayoutConstraint *GetEntity() {
		return dynamic_cast<wxIndividualLayoutConstraint *>(_pEntity);
	}
	inline wxIndividualLayoutConstraint *ReleaseEntity() {
		wxIndividualLayoutConstraint *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxIndividualLayoutConstraint");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
