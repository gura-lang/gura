//----------------------------------------------------------------------------
// wxPaintDC
// extracted from paintdc.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_PAINTDC_H__
#define __OBJECT_WX_PAINTDC_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPaintDC
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PaintDC);

//----------------------------------------------------------------------------
// Object declaration for wxPaintDC
//----------------------------------------------------------------------------
class Object_wx_PaintDC : public Object_wx_WindowDC {
public:
	Gura_DeclareObjectAccessor(wx_PaintDC)
public:
	inline Object_wx_PaintDC(wxPaintDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_WindowDC(Gura_UserClass(wx_PaintDC), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PaintDC(Class *pClass, wxPaintDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_WindowDC(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PaintDC();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxPaintDC *GetEntity() {
		return dynamic_cast<wxPaintDC *>(_pEntity);
	}
	inline wxPaintDC *ReleaseEntity() {
		wxPaintDC *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxPaintDC");
		return true;
	}
};

}}

#endif
