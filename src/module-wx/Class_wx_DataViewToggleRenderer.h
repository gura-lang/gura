//----------------------------------------------------------------------------
// wxDataViewToggleRenderer
// extracted from dataviewrenderer.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWTOGGLERENDERER_H__
#define __CLASS_WX_DATAVIEWTOGGLERENDERER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewToggleRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewToggleRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewToggleRenderer
//----------------------------------------------------------------------------
class Object_wx_DataViewToggleRenderer : public Object_wx_DataViewRenderer {
public:
	Gura_DeclareObjectAccessor(wx_DataViewToggleRenderer)
public:
	inline Object_wx_DataViewToggleRenderer(wxDataViewToggleRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewRenderer(Gura_UserClass(wx_DataViewToggleRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewToggleRenderer(Class *pClass, wxDataViewToggleRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewToggleRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewToggleRenderer *GetEntity() {
		return dynamic_cast<wxDataViewToggleRenderer *>(_pEntity);
	}
	inline wxDataViewToggleRenderer *ReleaseEntity() {
		wxDataViewToggleRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDataViewToggleRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
