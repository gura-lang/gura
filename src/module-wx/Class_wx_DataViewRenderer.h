//----------------------------------------------------------------------------
// wxDataViewRenderer
// extracted from dataviewrenderer.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWRENDERER_H__
#define __CLASS_WX_DATAVIEWRENDERER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewRenderer
//----------------------------------------------------------------------------
class Object_wx_DataViewRenderer : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_DataViewRenderer)
public:
	inline Object_wx_DataViewRenderer(wxDataViewRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_DataViewRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewRenderer(Class *pClass, wxDataViewRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewRenderer *GetEntity() {
		return dynamic_cast<wxDataViewRenderer *>(_pEntity);
	}
	inline wxDataViewRenderer *ReleaseEntity() {
		wxDataViewRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDataViewRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
