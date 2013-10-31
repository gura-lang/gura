//----------------------------------------------------------------------------
// wxSplitterRenderParams
// extracted from splitpar.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SPLITTERRENDERPARAMS_H__
#define __OBJECT_WX_SPLITTERRENDERPARAMS_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSplitterRenderParams
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SplitterRenderParams);

//----------------------------------------------------------------------------
// Object declaration for wxSplitterRenderParams
//----------------------------------------------------------------------------
class Object_wx_SplitterRenderParams : public Object {
protected:
	wxSplitterRenderParams *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_SplitterRenderParams)
public:
	inline Object_wx_SplitterRenderParams(wxSplitterRenderParams *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_SplitterRenderParams)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_SplitterRenderParams(Class *pClass, wxSplitterRenderParams *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_SplitterRenderParams();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxSplitterRenderParams *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxSplitterRenderParams *GetEntity() { return _pEntity; }
	inline wxSplitterRenderParams *ReleaseEntity() {
		wxSplitterRenderParams *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSplitterRenderParams");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
