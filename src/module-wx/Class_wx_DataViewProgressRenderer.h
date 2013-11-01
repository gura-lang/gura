//----------------------------------------------------------------------------
// wxDataViewProgressRenderer
// extracted from dataviewrenderer.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DATAVIEWPROGRESSRENDERER_H__
#define __OBJECT_WX_DATAVIEWPROGRESSRENDERER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewProgressRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewProgressRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewProgressRenderer
//----------------------------------------------------------------------------
class Object_wx_DataViewProgressRenderer : public Object_wx_DataViewRenderer {
public:
	Gura_DeclareObjectAccessor(wx_DataViewProgressRenderer)
public:
	inline Object_wx_DataViewProgressRenderer(wxDataViewProgressRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewRenderer(Gura_UserClass(wx_DataViewProgressRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewProgressRenderer(Class *pClass, wxDataViewProgressRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewProgressRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewProgressRenderer *GetEntity() {
		return dynamic_cast<wxDataViewProgressRenderer *>(_pEntity);
	}
	inline wxDataViewProgressRenderer *ReleaseEntity() {
		wxDataViewProgressRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDataViewProgressRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
