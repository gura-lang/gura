//----------------------------------------------------------------------------
// wxGridellStringRenderer
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GRIDELLSTRINGRENDERER_H__
#define __OBJECT_WX_GRIDELLSTRINGRENDERER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridellStringRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridellStringRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxGridellStringRenderer
//----------------------------------------------------------------------------
class Object_wx_GridellStringRenderer : public Object {
protected:
	wxGridellStringRenderer *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_GridellStringRenderer)
public:
	inline Object_wx_GridellStringRenderer(wxGridellStringRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_GridellStringRenderer)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_GridellStringRenderer(Class *pClass, wxGridellStringRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_GridellStringRenderer();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxGridellStringRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxGridellStringRenderer *GetEntity() { return _pEntity; }
	inline wxGridellStringRenderer *ReleaseEntity() {
		wxGridellStringRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGridellStringRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
