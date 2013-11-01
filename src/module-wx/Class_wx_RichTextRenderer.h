//----------------------------------------------------------------------------
// wxRichTextRenderer
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RICHTEXTRENDERER_H__
#define __OBJECT_WX_RICHTEXTRENDERER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextRenderer
//----------------------------------------------------------------------------
class Object_wx_RichTextRenderer : public Object {
protected:
	wxRichTextRenderer *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RichTextRenderer)
public:
	inline Object_wx_RichTextRenderer(wxRichTextRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_RichTextRenderer)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RichTextRenderer(Class *pClass, wxRichTextRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RichTextRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRichTextRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxRichTextRenderer *GetEntity() { return _pEntity; }
	inline wxRichTextRenderer *ReleaseEntity() {
		wxRichTextRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRichTextRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
