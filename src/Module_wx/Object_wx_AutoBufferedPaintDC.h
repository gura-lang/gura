//----------------------------------------------------------------------------
// wxAutoBufferedPaintDC
// extracted from bufferdc.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_AUTOBUFFEREDPAINTDC_H__
#define __OBJECT_WX_AUTOBUFFEREDPAINTDC_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAutoBufferedPaintDC
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AutoBufferedPaintDC);

//----------------------------------------------------------------------------
// Object declaration for wxAutoBufferedPaintDC
//----------------------------------------------------------------------------
class Object_wx_AutoBufferedPaintDC : public Object_wx_DC {
public:
	Gura_DeclareObjectAccessor(wx_AutoBufferedPaintDC)
public:
	inline Object_wx_AutoBufferedPaintDC(wxAutoBufferedPaintDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DC(Gura_UserClass(wx_AutoBufferedPaintDC), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_AutoBufferedPaintDC(Class *pClass, wxAutoBufferedPaintDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DC(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_AutoBufferedPaintDC();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxAutoBufferedPaintDC *GetEntity() {
		return dynamic_cast<wxAutoBufferedPaintDC *>(_pEntity);
	}
	inline wxAutoBufferedPaintDC *ReleaseEntity() {
		wxAutoBufferedPaintDC *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxAutoBufferedPaintDC");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
