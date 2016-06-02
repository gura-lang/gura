//----------------------------------------------------------------------------
// wxPixelData
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PIXELDATA_H__
#define __CLASS_WX_PIXELDATA_H__
#include <wx/rawbmp.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPixelData
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PixelData);

//----------------------------------------------------------------------------
// Object declaration for wxPixelData
//----------------------------------------------------------------------------
class Object_wx_PixelData : public Object {
protected:
	wxPixelData *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_PixelData)
public:
	inline Object_wx_PixelData(wxPixelData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_PixelData(Class *pClass, wxPixelData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_PixelData();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPixelData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPixelData *GetEntity() {
		return static_cast<wxPixelData *>(_pEntity);
	}
	inline wxPixelData *ReleaseEntity() {
		wxPixelData *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPixelData");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
