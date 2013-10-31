//----------------------------------------------------------------------------
// wxBufferedPaintDC
// extracted from bufferdc.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_BUFFEREDPAINTDC_H__
#define __OBJECT_WX_BUFFEREDPAINTDC_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBufferedPaintDC
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_BufferedPaintDC);

//----------------------------------------------------------------------------
// Object declaration for wxBufferedPaintDC
//----------------------------------------------------------------------------
class Object_wx_BufferedPaintDC : public Object_wx_BufferedDC {
public:
	Gura_DeclareObjectAccessor(wx_BufferedPaintDC)
public:
	inline Object_wx_BufferedPaintDC(wxBufferedPaintDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BufferedDC(Gura_UserClass(wx_BufferedPaintDC), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_BufferedPaintDC(Class *pClass, wxBufferedPaintDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BufferedDC(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_BufferedPaintDC();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxBufferedPaintDC *GetEntity() {
		return dynamic_cast<wxBufferedPaintDC *>(_pEntity);
	}
	inline wxBufferedPaintDC *ReleaseEntity() {
		wxBufferedPaintDC *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxBufferedPaintDC");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
