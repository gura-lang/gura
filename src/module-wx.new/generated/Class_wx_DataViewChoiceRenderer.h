//----------------------------------------------------------------------------
// wxDataViewChoiceRenderer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWCHOICERENDERER_H__
#define __CLASS_WX_DATAVIEWCHOICERENDERER_H__
#include <wx/dataview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewChoiceRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewChoiceRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewChoiceRenderer
//----------------------------------------------------------------------------
class Object_wx_DataViewChoiceRenderer : public Object_wx_DataViewRenderer {
public:
	Gura_DeclareObjectAccessor(wx_DataViewChoiceRenderer)
public:
	inline Object_wx_DataViewChoiceRenderer(wxDataViewChoiceRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewRenderer(Gura_UserClass(wx_DataViewChoiceRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewChoiceRenderer(Class *pClass, wxDataViewChoiceRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewChoiceRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewChoiceRenderer *GetEntity() {
		return static_cast<wxDataViewChoiceRenderer *>(_pEntity);
	}
	inline wxDataViewChoiceRenderer *ReleaseEntity() {
		wxDataViewChoiceRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDataViewChoiceRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
