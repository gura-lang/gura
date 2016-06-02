//----------------------------------------------------------------------------
// wxMBConv
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MBCONV_H__
#define __CLASS_WX_MBCONV_H__
#include <wx/strconv.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMBConv
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MBConv);

//----------------------------------------------------------------------------
// Object declaration for wxMBConv
//----------------------------------------------------------------------------
class Object_wx_MBConv : public Object {
protected:
	wxMBConv *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_MBConv)
public:
	inline Object_wx_MBConv(wxMBConv *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_MBConv(Class *pClass, wxMBConv *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_MBConv();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxMBConv *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxMBConv *GetEntity() {
		return static_cast<wxMBConv *>(_pEntity);
	}
	inline wxMBConv *ReleaseEntity() {
		wxMBConv *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxMBConv");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
