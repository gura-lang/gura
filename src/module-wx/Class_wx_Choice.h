//----------------------------------------------------------------------------
// wxChoice
// extracted from choice.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CHOICE_H__
#define __CLASS_WX_CHOICE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxChoice
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Choice);

//----------------------------------------------------------------------------
// Object declaration for wxChoice
//----------------------------------------------------------------------------
class Object_wx_Choice : public Object_wx_ControlWithItems {
public:
	Gura_DeclareObjectAccessor(wx_Choice)
public:
	inline Object_wx_Choice(wxChoice *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ControlWithItems(Gura_UserClass(wx_Choice), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Choice(Class *pClass, wxChoice *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ControlWithItems(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Choice();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxChoice *GetEntity() {
		return dynamic_cast<wxChoice *>(_pEntity);
	}
	inline wxChoice *ReleaseEntity() {
		wxChoice *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxChoice");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
