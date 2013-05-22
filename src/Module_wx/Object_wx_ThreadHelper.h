//----------------------------------------------------------------------------
// wxThreadHelper
// extracted from threadh.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_THREADHELPER_H__
#define __OBJECT_WX_THREADHELPER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxThreadHelper
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ThreadHelper);

//----------------------------------------------------------------------------
// Object declaration for wxThreadHelper
//----------------------------------------------------------------------------
class Object_wx_ThreadHelper : public Object {
protected:
	wxThreadHelper *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ThreadHelper)
public:
	inline Object_wx_ThreadHelper(wxThreadHelper *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_ThreadHelper)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ThreadHelper(Class *pClass, wxThreadHelper *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ThreadHelper();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxThreadHelper *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxThreadHelper *GetEntity() { return _pEntity; }
	inline wxThreadHelper *ReleaseEntity() {
		wxThreadHelper *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxThreadHelper");
		return true;
	}
};

}}

#endif
