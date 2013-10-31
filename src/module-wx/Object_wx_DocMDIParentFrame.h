//----------------------------------------------------------------------------
// wxDocMDIParentFrame
// extracted from docmdipr.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DOCMDIPARENTFRAME_H__
#define __OBJECT_WX_DOCMDIPARENTFRAME_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDocMDIParentFrame
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DocMDIParentFrame);

//----------------------------------------------------------------------------
// Object declaration for wxDocMDIParentFrame
//----------------------------------------------------------------------------
class Object_wx_DocMDIParentFrame : public Object_wx_MDIParentFrame {
public:
	Gura_DeclareObjectAccessor(wx_DocMDIParentFrame)
public:
	inline Object_wx_DocMDIParentFrame(wxDocMDIParentFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MDIParentFrame(Gura_UserClass(wx_DocMDIParentFrame), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DocMDIParentFrame(Class *pClass, wxDocMDIParentFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MDIParentFrame(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DocMDIParentFrame();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDocMDIParentFrame *GetEntity() {
		return dynamic_cast<wxDocMDIParentFrame *>(_pEntity);
	}
	inline wxDocMDIParentFrame *ReleaseEntity() {
		wxDocMDIParentFrame *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDocMDIParentFrame");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
