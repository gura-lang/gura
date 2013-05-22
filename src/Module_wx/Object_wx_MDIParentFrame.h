//----------------------------------------------------------------------------
// wxMDIParentFrame
// extracted from mdi.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_MDIPARENTFRAME_H__
#define __OBJECT_WX_MDIPARENTFRAME_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMDIParentFrame
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MDIParentFrame);

//----------------------------------------------------------------------------
// Object declaration for wxMDIParentFrame
//----------------------------------------------------------------------------
class Object_wx_MDIParentFrame : public Object_wx_Frame {
public:
	Gura_DeclareObjectAccessor(wx_MDIParentFrame)
public:
	inline Object_wx_MDIParentFrame(wxMDIParentFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(Gura_UserClass(wx_MDIParentFrame), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MDIParentFrame(Class *pClass, wxMDIParentFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MDIParentFrame();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxMDIParentFrame *GetEntity() {
		return dynamic_cast<wxMDIParentFrame *>(_pEntity);
	}
	inline wxMDIParentFrame *ReleaseEntity() {
		wxMDIParentFrame *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxMDIParentFrame");
		return true;
	}
};

}}

#endif
