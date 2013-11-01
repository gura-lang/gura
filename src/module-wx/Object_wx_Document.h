//----------------------------------------------------------------------------
// wxDocument
// extracted from document.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DOCUMENT_H__
#define __OBJECT_WX_DOCUMENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDocument
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Document);

//----------------------------------------------------------------------------
// Object declaration for wxDocument
//----------------------------------------------------------------------------
class Object_wx_Document : public Object_wx_EvtHandler {
public:
	Gura_DeclareObjectAccessor(wx_Document)
public:
	inline Object_wx_Document(wxDocument *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(Gura_UserClass(wx_Document), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Document(Class *pClass, wxDocument *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Document();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDocument *GetEntity() {
		return dynamic_cast<wxDocument *>(_pEntity);
	}
	inline wxDocument *ReleaseEntity() {
		wxDocument *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDocument");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
