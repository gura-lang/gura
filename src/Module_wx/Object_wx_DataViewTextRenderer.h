//----------------------------------------------------------------------------
// wxDataViewTextRenderer
// extracted from dataviewrenderer.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DATAVIEWTEXTRENDERER_H__
#define __OBJECT_WX_DATAVIEWTEXTRENDERER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewTextRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewTextRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewTextRenderer
//----------------------------------------------------------------------------
class Object_wx_DataViewTextRenderer : public Object_wx_DataViewRenderer {
public:
	Gura_DeclareObjectAccessor(wx_DataViewTextRenderer)
public:
	inline Object_wx_DataViewTextRenderer(wxDataViewTextRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewRenderer(Gura_UserClass(wx_DataViewTextRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewTextRenderer(Class *pClass, wxDataViewTextRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewTextRenderer();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDataViewTextRenderer *GetEntity() {
		return dynamic_cast<wxDataViewTextRenderer *>(_pEntity);
	}
	inline wxDataViewTextRenderer *ReleaseEntity() {
		wxDataViewTextRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDataViewTextRenderer");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
