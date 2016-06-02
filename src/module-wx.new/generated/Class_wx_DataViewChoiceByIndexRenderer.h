//----------------------------------------------------------------------------
// wxDataViewChoiceByIndexRenderer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWCHOICEBYINDEXRENDERER_H__
#define __CLASS_WX_DATAVIEWCHOICEBYINDEXRENDERER_H__
#include <wx/dataview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewChoiceByIndexRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewChoiceByIndexRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewChoiceByIndexRenderer
//----------------------------------------------------------------------------
class Object_wx_DataViewChoiceByIndexRenderer : public Object_wx_DataViewChoiceRenderer {
public:
	Gura_DeclareObjectAccessor(wx_DataViewChoiceByIndexRenderer)
public:
	inline Object_wx_DataViewChoiceByIndexRenderer(wxDataViewChoiceByIndexRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewChoiceRenderer(Gura_UserClass(wx_DataViewChoiceByIndexRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewChoiceByIndexRenderer(Class *pClass, wxDataViewChoiceByIndexRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewChoiceRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewChoiceByIndexRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewChoiceByIndexRenderer *GetEntity() {
		return static_cast<wxDataViewChoiceByIndexRenderer *>(_pEntity);
	}
	inline wxDataViewChoiceByIndexRenderer *ReleaseEntity() {
		wxDataViewChoiceByIndexRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDataViewChoiceByIndexRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
