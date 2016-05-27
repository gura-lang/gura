//----------------------------------------------------------------------------
// wxConvAuto
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CONVAUTO_H__
#define __CLASS_WX_CONVAUTO_H__
#include <wx/convauto.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxConvAuto
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ConvAuto);

//----------------------------------------------------------------------------
// Object declaration for wxConvAuto
//----------------------------------------------------------------------------
class Object_wx_ConvAuto : public Object_wx_MBConv {
public:
	Gura_DeclareObjectAccessor(wx_ConvAuto)
public:
	inline Object_wx_ConvAuto(wxConvAuto *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MBConv(Gura_UserClass(wx_ConvAuto), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ConvAuto(Class *pClass, wxConvAuto *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MBConv(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ConvAuto();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxConvAuto *GetEntity() {
		return static_cast<wxConvAuto *>(_pEntity);
	}
	inline wxConvAuto *ReleaseEntity() {
		wxConvAuto *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxConvAuto");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
