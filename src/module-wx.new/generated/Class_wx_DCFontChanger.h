//----------------------------------------------------------------------------
// wxDCFontChanger
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DCFONTCHANGER_H__
#define __CLASS_WX_DCFONTCHANGER_H__
#include <wx/dc.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDCFontChanger
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DCFontChanger);

//----------------------------------------------------------------------------
// Object declaration for wxDCFontChanger
//----------------------------------------------------------------------------
class Object_wx_DCFontChanger : public Object {
protected:
	wxDCFontChanger *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DCFontChanger)
public:
	inline Object_wx_DCFontChanger(wxDCFontChanger *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DCFontChanger(Class *pClass, wxDCFontChanger *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DCFontChanger();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDCFontChanger *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDCFontChanger *GetEntity() {
		return static_cast<wxDCFontChanger *>(_pEntity);
	}
	inline wxDCFontChanger *ReleaseEntity() {
		wxDCFontChanger *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDCFontChanger");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
