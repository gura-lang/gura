//----------------------------------------------------------------------------
// wxStaticText
// extracted from stattext.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STATICTEXT_H__
#define __CLASS_WX_STATICTEXT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStaticText
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StaticText);

//----------------------------------------------------------------------------
// Object declaration for wxStaticText
//----------------------------------------------------------------------------
class Object_wx_StaticText : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_StaticText)
public:
	inline Object_wx_StaticText(wxStaticText *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_StaticText), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_StaticText(Class *pClass, wxStaticText *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_StaticText();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxStaticText *GetEntity() {
		return dynamic_cast<wxStaticText *>(_pEntity);
	}
	inline wxStaticText *ReleaseEntity() {
		wxStaticText *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxStaticText");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
