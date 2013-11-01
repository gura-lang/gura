//----------------------------------------------------------------------------
// wxFileDropTarget
// extracted from fildrptg.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FILEDROPTARGET_H__
#define __CLASS_WX_FILEDROPTARGET_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFileDropTarget
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FileDropTarget);

//----------------------------------------------------------------------------
// Object declaration for wxFileDropTarget
//----------------------------------------------------------------------------
class Object_wx_FileDropTarget : public Object_wx_DropTarget {
public:
	Gura_DeclareObjectAccessor(wx_FileDropTarget)
public:
	inline Object_wx_FileDropTarget(wxFileDropTarget *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DropTarget(Gura_UserClass(wx_FileDropTarget), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FileDropTarget(Class *pClass, wxFileDropTarget *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DropTarget(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FileDropTarget();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFileDropTarget *GetEntity() {
		return dynamic_cast<wxFileDropTarget *>(_pEntity);
	}
	inline wxFileDropTarget *ReleaseEntity() {
		wxFileDropTarget *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFileDropTarget");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
