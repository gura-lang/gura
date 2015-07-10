//----------------------------------------------------------------------------
// wxDocTemplate
// extracted from doctempl.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DOCTEMPLATE_H__
#define __CLASS_WX_DOCTEMPLATE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDocTemplate
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DocTemplate);

//----------------------------------------------------------------------------
// Object declaration for wxDocTemplate
//----------------------------------------------------------------------------
class Object_wx_DocTemplate : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_DocTemplate)
public:
	inline Object_wx_DocTemplate(wxDocTemplate *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_DocTemplate), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DocTemplate(Class *pClass, wxDocTemplate *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DocTemplate();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDocTemplate *GetEntity() {
		return dynamic_cast<wxDocTemplate *>(_pEntity);
	}
	inline wxDocTemplate *ReleaseEntity() {
		wxDocTemplate *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDocTemplate");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
