//----------------------------------------------------------------------------
// wxPrintPreview
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PRINTPREVIEW_H__
#define __CLASS_WX_PRINTPREVIEW_H__
#include <wx/print.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPrintPreview
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PrintPreview);

//----------------------------------------------------------------------------
// Object declaration for wxPrintPreview
//----------------------------------------------------------------------------
class Object_wx_PrintPreview : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_PrintPreview)
public:
	inline Object_wx_PrintPreview(wxPrintPreview *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_PrintPreview), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PrintPreview(Class *pClass, wxPrintPreview *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PrintPreview();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPrintPreview *GetEntity() {
		return static_cast<wxPrintPreview *>(_pEntity);
	}
	inline wxPrintPreview *ReleaseEntity() {
		wxPrintPreview *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPrintPreview");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
