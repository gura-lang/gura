//----------------------------------------------------------------------------
// wxDataFormat
// extracted from dataform.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAFORMAT_H__
#define __CLASS_WX_DATAFORMAT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataFormat
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataFormat);

//----------------------------------------------------------------------------
// Object declaration for wxDataFormat
//----------------------------------------------------------------------------
class Object_wx_DataFormat : public Object {
protected:
	wxDataFormat *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DataFormat)
public:
	inline Object_wx_DataFormat(wxDataFormat *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_DataFormat)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DataFormat(Class *pClass, wxDataFormat *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DataFormat();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDataFormat *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxDataFormat *GetEntity() { return _pEntity; }
	inline wxDataFormat *ReleaseEntity() {
		wxDataFormat *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDataFormat");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
