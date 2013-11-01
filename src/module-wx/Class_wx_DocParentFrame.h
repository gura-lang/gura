//----------------------------------------------------------------------------
// wxDocParentFrame
// extracted from docprfrm.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DOCPARENTFRAME_H__
#define __OBJECT_WX_DOCPARENTFRAME_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDocParentFrame
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DocParentFrame);

//----------------------------------------------------------------------------
// Object declaration for wxDocParentFrame
//----------------------------------------------------------------------------
class Object_wx_DocParentFrame : public Object_wx_Frame {
public:
	Gura_DeclareObjectAccessor(wx_DocParentFrame)
public:
	inline Object_wx_DocParentFrame(wxDocParentFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(Gura_UserClass(wx_DocParentFrame), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DocParentFrame(Class *pClass, wxDocParentFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DocParentFrame();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDocParentFrame *GetEntity() {
		return dynamic_cast<wxDocParentFrame *>(_pEntity);
	}
	inline wxDocParentFrame *ReleaseEntity() {
		wxDocParentFrame *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDocParentFrame");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
