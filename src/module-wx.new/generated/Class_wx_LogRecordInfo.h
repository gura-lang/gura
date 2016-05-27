//----------------------------------------------------------------------------
// wxLogRecordInfo
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LOGRECORDINFO_H__
#define __CLASS_WX_LOGRECORDINFO_H__
#include <wx/log.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxLogRecordInfo
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_LogRecordInfo);

//----------------------------------------------------------------------------
// Object declaration for wxLogRecordInfo
//----------------------------------------------------------------------------
class Object_wx_LogRecordInfo : public Object {
protected:
	wxLogRecordInfo *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_LogRecordInfo)
public:
	inline Object_wx_LogRecordInfo(wxLogRecordInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_LogRecordInfo(Class *pClass, wxLogRecordInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_LogRecordInfo();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxLogRecordInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxLogRecordInfo *GetEntity() {
		return static_cast<wxLogRecordInfo *>(_pEntity);
	}
	inline wxLogRecordInfo *ReleaseEntity() {
		wxLogRecordInfo *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxLogRecordInfo");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
