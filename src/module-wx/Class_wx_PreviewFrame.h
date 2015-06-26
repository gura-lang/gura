//----------------------------------------------------------------------------
// wxPreviewFrame
// extracted from prevwin.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PREVIEWFRAME_H__
#define __CLASS_WX_PREVIEWFRAME_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPreviewFrame
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PreviewFrame);

//----------------------------------------------------------------------------
// Object declaration for wxPreviewFrame
//----------------------------------------------------------------------------
class Object_wx_PreviewFrame : public Object_wx_Frame {
public:
	Gura_DeclareObjectAccessor(wx_PreviewFrame)
public:
	inline Object_wx_PreviewFrame(wxPreviewFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(Gura_UserClass(wx_PreviewFrame), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PreviewFrame(Class *pClass, wxPreviewFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PreviewFrame();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPreviewFrame *GetEntity() {
		return dynamic_cast<wxPreviewFrame *>(_pEntity);
	}
	inline wxPreviewFrame *ReleaseEntity() {
		wxPreviewFrame *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPreviewFrame");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
