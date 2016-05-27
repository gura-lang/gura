//----------------------------------------------------------------------------
// wxDataViewIconTextRenderer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWICONTEXTRENDERER_H__
#define __CLASS_WX_DATAVIEWICONTEXTRENDERER_H__
#include <wx/dataview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewIconTextRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewIconTextRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewIconTextRenderer
//----------------------------------------------------------------------------
class Object_wx_DataViewIconTextRenderer : public Object_wx_DataViewRenderer {
public:
	Gura_DeclareObjectAccessor(wx_DataViewIconTextRenderer)
public:
	inline Object_wx_DataViewIconTextRenderer(wxDataViewIconTextRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewRenderer(Gura_UserClass(wx_DataViewIconTextRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewIconTextRenderer(Class *pClass, wxDataViewIconTextRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewIconTextRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewIconTextRenderer *GetEntity() {
		return static_cast<wxDataViewIconTextRenderer *>(_pEntity);
	}
	inline wxDataViewIconTextRenderer *ReleaseEntity() {
		wxDataViewIconTextRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDataViewIconTextRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
