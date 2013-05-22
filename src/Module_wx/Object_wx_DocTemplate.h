//----------------------------------------------------------------------------
// wxDocTemplate
// extracted from doctempl.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DOCTEMPLATE_H__
#define __OBJECT_WX_DOCTEMPLATE_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDocTemplate *GetEntity() {
		return dynamic_cast<wxDocTemplate *>(_pEntity);
	}
	inline wxDocTemplate *ReleaseEntity() {
		wxDocTemplate *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDocTemplate");
		return true;
	}
};

}}

#endif
