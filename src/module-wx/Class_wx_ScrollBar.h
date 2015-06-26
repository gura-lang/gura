//----------------------------------------------------------------------------
// wxScrollBar
// extracted from scrolbar.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SCROLLBAR_H__
#define __CLASS_WX_SCROLLBAR_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxScrollBar
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ScrollBar);

//----------------------------------------------------------------------------
// Object declaration for wxScrollBar
//----------------------------------------------------------------------------
class Object_wx_ScrollBar : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_ScrollBar)
public:
	inline Object_wx_ScrollBar(wxScrollBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_ScrollBar), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ScrollBar(Class *pClass, wxScrollBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ScrollBar();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxScrollBar *GetEntity() {
		return dynamic_cast<wxScrollBar *>(_pEntity);
	}
	inline wxScrollBar *ReleaseEntity() {
		wxScrollBar *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxScrollBar");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
