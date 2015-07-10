//----------------------------------------------------------------------------
// wxDataOutputStream
// extracted from datostrm.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAOUTPUTSTREAM_H__
#define __CLASS_WX_DATAOUTPUTSTREAM_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataOutputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataOutputStream);

//----------------------------------------------------------------------------
// Object declaration for wxDataOutputStream
//----------------------------------------------------------------------------
class Object_wx_DataOutputStream : public Object {
protected:
	wxDataOutputStream *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DataOutputStream)
public:
	inline Object_wx_DataOutputStream(wxDataOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_DataOutputStream)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DataOutputStream(Class *pClass, wxDataOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DataOutputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDataOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDataOutputStream *GetEntity() { return _pEntity; }
	inline wxDataOutputStream *ReleaseEntity() {
		wxDataOutputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDataOutputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
