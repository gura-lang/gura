//----------------------------------------------------------------------------
// wxTextValidator
// extracted from valtext.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTVALIDATOR_H__
#define __CLASS_WX_TEXTVALIDATOR_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextValidator
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextValidator);

//----------------------------------------------------------------------------
// Object declaration for wxTextValidator
//----------------------------------------------------------------------------
class Object_wx_TextValidator : public Object_wx_Validator {
public:
	Gura_DeclareObjectAccessor(wx_TextValidator)
public:
	inline Object_wx_TextValidator(wxTextValidator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Validator(Gura_UserClass(wx_TextValidator), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TextValidator(Class *pClass, wxTextValidator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Validator(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TextValidator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTextValidator *GetEntity() {
		return dynamic_cast<wxTextValidator *>(_pEntity);
	}
	inline wxTextValidator *ReleaseEntity() {
		wxTextValidator *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTextValidator");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
