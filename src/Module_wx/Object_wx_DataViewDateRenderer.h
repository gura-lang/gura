//----------------------------------------------------------------------------
// wxDataViewDateRenderer
// extracted from dataviewrenderer.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DATAVIEWDATERENDERER_H__
#define __OBJECT_WX_DATAVIEWDATERENDERER_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDataViewDateRenderer *GetEntity() {
		return dynamic_cast<wxDataViewDateRenderer *>(_pEntity);
	}
	inline wxDataViewDateRenderer *ReleaseEntity() {
		wxDataViewDateRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDataViewDateRenderer");
		return true;
	}
};

}}

#endif
