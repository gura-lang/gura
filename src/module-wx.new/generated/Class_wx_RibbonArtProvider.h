//----------------------------------------------------------------------------
// wxRibbonArtProvider
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RIBBONARTPROVIDER_H__
#define __CLASS_WX_RIBBONARTPROVIDER_H__
#include <wx/ribbon/art.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRibbonArtProvider
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RibbonArtProvider);

//----------------------------------------------------------------------------
// Object declaration for wxRibbonArtProvider
//----------------------------------------------------------------------------
class Object_wx_RibbonArtProvider : public Object {
protected:
	wxRibbonArtProvider *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RibbonArtProvider)
public:
	inline Object_wx_RibbonArtProvider(wxRibbonArtProvider *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RibbonArtProvider(Class *pClass, wxRibbonArtProvider *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RibbonArtProvider();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRibbonArtProvider *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxRibbonArtProvider *GetEntity() {
		return static_cast<wxRibbonArtProvider *>(_pEntity);
	}
	inline wxRibbonArtProvider *ReleaseEntity() {
		wxRibbonArtProvider *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRibbonArtProvider");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
