//----------------------------------------------------------------------------
// wxChoicebook
// extracted from choicebk.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_CHOICEBOOK_H__
#define __OBJECT_WX_CHOICEBOOK_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxChoicebook
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Choicebook);

//----------------------------------------------------------------------------
// Object declaration for wxChoicebook
//----------------------------------------------------------------------------
class Object_wx_Choicebook : public Object_wx_BookCtrlBase {
public:
	Gura_DeclareObjectAccessor(wx_Choicebook)
public:
	inline Object_wx_Choicebook(wxChoicebook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(Gura_UserClass(wx_Choicebook), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Choicebook(Class *pClass, wxChoicebook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Choicebook();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxChoicebook *GetEntity() {
		return dynamic_cast<wxChoicebook *>(_pEntity);
	}
	inline wxChoicebook *ReleaseEntity() {
		wxChoicebook *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxChoicebook");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
