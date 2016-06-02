//----------------------------------------------------------------------------
// wxDataViewDateRenderer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWDATERENDERER_H__
#define __CLASS_WX_DATAVIEWDATERENDERER_H__
#include <wx/dataview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewDateRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewDateRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewDateRenderer
//----------------------------------------------------------------------------
class Object_wx_DataViewDateRenderer : public Object_wx_DataViewRenderer {
public:
	Gura_DeclareObjectAccessor(wx_DataViewDateRenderer)
public:
	inline Object_wx_DataViewDateRenderer(wxDataViewDateRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewRenderer(Gura_UserClass(wx_DataViewDateRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewDateRenderer(Class *pClass, wxDataViewDateRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewDateRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewDateRenderer *GetEntity() {
		return static_cast<wxDataViewDateRenderer *>(_pEntity);
	}
	inline wxDataViewDateRenderer *ReleaseEntity() {
		wxDataViewDateRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDataViewDateRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
