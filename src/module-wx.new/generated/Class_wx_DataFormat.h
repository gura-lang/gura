//----------------------------------------------------------------------------
// wxDataFormat
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAFORMAT_H__
#define __CLASS_WX_DATAFORMAT_H__
#include <wx/dataobj.h>

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
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DataFormat(Class *pClass, wxDataFormat *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DataFormat();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDataFormat *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDataFormat *GetEntity() {
		return static_cast<wxDataFormat *>(_pEntity);
	}
	inline wxDataFormat *ReleaseEntity() {
		wxDataFormat *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDataFormat");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
