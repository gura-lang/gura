//----------------------------------------------------------------------------
// wxTextDropTarget
// extracted from txtdrptg.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTDROPTARGET_H__
#define __CLASS_WX_TEXTDROPTARGET_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextDropTarget
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextDropTarget);

//----------------------------------------------------------------------------
// Object declaration for wxTextDropTarget
//----------------------------------------------------------------------------
class Object_wx_TextDropTarget : public Object_wx_DropTarget {
public:
	Gura_DeclareObjectAccessor(wx_TextDropTarget)
public:
	inline Object_wx_TextDropTarget(wxTextDropTarget *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DropTarget(Gura_UserClass(wx_TextDropTarget), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TextDropTarget(Class *pClass, wxTextDropTarget *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DropTarget(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TextDropTarget();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTextDropTarget *GetEntity() {
		return dynamic_cast<wxTextDropTarget *>(_pEntity);
	}
	inline wxTextDropTarget *ReleaseEntity() {
		wxTextDropTarget *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTextDropTarget");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
