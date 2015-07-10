//----------------------------------------------------------------------------
// wxPen
// extracted from pen.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PEN_H__
#define __CLASS_WX_PEN_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPen
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Pen);

//----------------------------------------------------------------------------
// Object declaration for wxPen
//----------------------------------------------------------------------------
class Object_wx_Pen : public Object_wx_GDIObject {
public:
	Gura_DeclareObjectAccessor(wx_Pen)
public:
	inline Object_wx_Pen(wxPen *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(Gura_UserClass(wx_Pen), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Pen(Class *pClass, wxPen *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Pen();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPen *GetEntity() {
		return dynamic_cast<wxPen *>(_pEntity);
	}
	inline wxPen *ReleaseEntity() {
		wxPen *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPen");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
