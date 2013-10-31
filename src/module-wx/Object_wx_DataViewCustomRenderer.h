//----------------------------------------------------------------------------
// wxDataViewCustomRenderer
// extracted from dataviewrenderer.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DATAVIEWCUSTOMRENDERER_H__
#define __OBJECT_WX_DATAVIEWCUSTOMRENDERER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewCustomRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewCustomRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewCustomRenderer
//----------------------------------------------------------------------------
class Object_wx_DataViewCustomRenderer : public Object_wx_DataViewRenderer {
public:
	Gura_DeclareObjectAccessor(wx_DataViewCustomRenderer)
public:
	inline Object_wx_DataViewCustomRenderer(wxDataViewCustomRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewRenderer(Gura_UserClass(wx_DataViewCustomRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewCustomRenderer(Class *pClass, wxDataViewCustomRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewCustomRenderer();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDataViewCustomRenderer *GetEntity() {
		return dynamic_cast<wxDataViewCustomRenderer *>(_pEntity);
	}
	inline wxDataViewCustomRenderer *ReleaseEntity() {
		wxDataViewCustomRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDataViewCustomRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
