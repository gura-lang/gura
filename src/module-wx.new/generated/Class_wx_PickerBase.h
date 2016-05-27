//----------------------------------------------------------------------------
// wxPickerBase
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PICKERBASE_H__
#define __CLASS_WX_PICKERBASE_H__
#include <wx/pickerbase.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPickerBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PickerBase);

//----------------------------------------------------------------------------
// Object declaration for wxPickerBase
//----------------------------------------------------------------------------
class Object_wx_PickerBase : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_PickerBase)
public:
	inline Object_wx_PickerBase(wxPickerBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_PickerBase), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PickerBase(Class *pClass, wxPickerBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PickerBase();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPickerBase *GetEntity() {
		return static_cast<wxPickerBase *>(_pEntity);
	}
	inline wxPickerBase *ReleaseEntity() {
		wxPickerBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPickerBase");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
