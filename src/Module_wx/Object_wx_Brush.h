//----------------------------------------------------------------------------
// wxBrush
// extracted from brush.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_BRUSH_H__
#define __OBJECT_WX_BRUSH_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBrush
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Brush);

//----------------------------------------------------------------------------
// Object declaration for wxBrush
//----------------------------------------------------------------------------
class Object_wx_Brush : public Object_wx_GDIObject {
public:
	Gura_DeclareObjectAccessor(wx_Brush)
public:
	inline Object_wx_Brush(wxBrush *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(Gura_UserClass(wx_Brush), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Brush(Class *pClass, wxBrush *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Brush();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxBrush *GetEntity() {
		return dynamic_cast<wxBrush *>(_pEntity);
	}
	inline wxBrush *ReleaseEntity() {
		wxBrush *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxBrush");
		return true;
	}
};

}}

#endif
