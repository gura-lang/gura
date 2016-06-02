//----------------------------------------------------------------------------
// wxDataViewSpinRenderer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWSPINRENDERER_H__
#define __CLASS_WX_DATAVIEWSPINRENDERER_H__
#include <wx/dataview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewSpinRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewSpinRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewSpinRenderer
//----------------------------------------------------------------------------
class Object_wx_DataViewSpinRenderer : public Object_wx_DataViewCustomRenderer {
public:
	Gura_DeclareObjectAccessor(wx_DataViewSpinRenderer)
public:
	inline Object_wx_DataViewSpinRenderer(wxDataViewSpinRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewCustomRenderer(Gura_UserClass(wx_DataViewSpinRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewSpinRenderer(Class *pClass, wxDataViewSpinRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewCustomRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewSpinRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewSpinRenderer *GetEntity() {
		return static_cast<wxDataViewSpinRenderer *>(_pEntity);
	}
	inline wxDataViewSpinRenderer *ReleaseEntity() {
		wxDataViewSpinRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDataViewSpinRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
