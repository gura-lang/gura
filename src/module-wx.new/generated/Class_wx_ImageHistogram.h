//----------------------------------------------------------------------------
// wxImageHistogram
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_IMAGEHISTOGRAM_H__
#define __CLASS_WX_IMAGEHISTOGRAM_H__
#include <wx/image.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxImageHistogram
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ImageHistogram);

//----------------------------------------------------------------------------
// Object declaration for wxImageHistogram
//----------------------------------------------------------------------------
class Object_wx_ImageHistogram : public Object {
protected:
	wxImageHistogram *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ImageHistogram)
public:
	inline Object_wx_ImageHistogram(wxImageHistogram *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ImageHistogram(Class *pClass, wxImageHistogram *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ImageHistogram();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxImageHistogram *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxImageHistogram *GetEntity() {
		return static_cast<wxImageHistogram *>(_pEntity);
	}
	inline wxImageHistogram *ReleaseEntity() {
		wxImageHistogram *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxImageHistogram");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
