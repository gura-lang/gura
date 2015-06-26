//----------------------------------------------------------------------------
// wxArray
// extracted from array.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ARRAY_H__
#define __CLASS_WX_ARRAY_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxArray
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Array);

//----------------------------------------------------------------------------
// Object declaration for wxArray
//----------------------------------------------------------------------------
class Object_wx_Array : public Object {
protected:
	wxArray *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Array)
public:
	inline Object_wx_Array(wxArray *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_Array)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Array(Class *pClass, wxArray *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Array();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxArray *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxArray *GetEntity() { return _pEntity; }
	inline wxArray *ReleaseEntity() {
		wxArray *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxArray");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
