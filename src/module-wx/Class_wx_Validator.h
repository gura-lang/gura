//----------------------------------------------------------------------------
// wxValidator
// extracted from validatr.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_VALIDATOR_H__
#define __OBJECT_WX_VALIDATOR_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxValidator
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Validator);

//----------------------------------------------------------------------------
// Object declaration for wxValidator
//----------------------------------------------------------------------------
class Object_wx_Validator : public Object_wx_EvtHandler {
public:
	Gura_DeclareObjectAccessor(wx_Validator)
public:
	inline Object_wx_Validator(wxValidator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(Gura_UserClass(wx_Validator), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Validator(Class *pClass, wxValidator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Validator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxValidator *GetEntity() {
		return dynamic_cast<wxValidator *>(_pEntity);
	}
	inline wxValidator *ReleaseEntity() {
		wxValidator *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxValidator");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
