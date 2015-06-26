//----------------------------------------------------------------------------
// wxDataViewBitmapRenderer
// extracted from dataviewrenderer.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWBITMAPRENDERER_H__
#define __CLASS_WX_DATAVIEWBITMAPRENDERER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewBitmapRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewBitmapRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewBitmapRenderer
//----------------------------------------------------------------------------
class Object_wx_DataViewBitmapRenderer : public Object_wx_DataViewRenderer {
public:
	Gura_DeclareObjectAccessor(wx_DataViewBitmapRenderer)
public:
	inline Object_wx_DataViewBitmapRenderer(wxDataViewBitmapRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewRenderer(Gura_UserClass(wx_DataViewBitmapRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewBitmapRenderer(Class *pClass, wxDataViewBitmapRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewBitmapRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewBitmapRenderer *GetEntity() {
		return dynamic_cast<wxDataViewBitmapRenderer *>(_pEntity);
	}
	inline wxDataViewBitmapRenderer *ReleaseEntity() {
		wxDataViewBitmapRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDataViewBitmapRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
