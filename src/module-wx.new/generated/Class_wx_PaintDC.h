//----------------------------------------------------------------------------
// wxPaintDC
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PAINTDC_H__
#define __CLASS_WX_PAINTDC_H__
#include <wx/dcclient.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPaintDC
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PaintDC);

//----------------------------------------------------------------------------
// Object declaration for wxPaintDC
//----------------------------------------------------------------------------
class Object_wx_PaintDC : public Object_wx_ClientDC {
public:
	Gura_DeclareObjectAccessor(wx_PaintDC)
public:
	inline Object_wx_PaintDC(wxPaintDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientDC(Gura_UserClass(wx_PaintDC), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PaintDC(Class *pClass, wxPaintDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientDC(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PaintDC();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPaintDC *GetEntity() {
		return static_cast<wxPaintDC *>(_pEntity);
	}
	inline wxPaintDC *ReleaseEntity() {
		wxPaintDC *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPaintDC");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
