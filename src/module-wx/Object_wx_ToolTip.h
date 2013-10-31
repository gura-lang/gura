//----------------------------------------------------------------------------
// wxToolTip
// extracted from tooltip.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TOOLTIP_H__
#define __OBJECT_WX_TOOLTIP_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxToolTip
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ToolTip);

//----------------------------------------------------------------------------
// Object declaration for wxToolTip
//----------------------------------------------------------------------------
class Object_wx_ToolTip : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_ToolTip)
public:
	inline Object_wx_ToolTip(wxToolTip *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_ToolTip), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ToolTip(Class *pClass, wxToolTip *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ToolTip();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxToolTip *GetEntity() {
		return dynamic_cast<wxToolTip *>(_pEntity);
	}
	inline wxToolTip *ReleaseEntity() {
		wxToolTip *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxToolTip");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
