//----------------------------------------------------------------------------
// wxTextAttrBorders
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTATTRBORDERS_H__
#define __CLASS_WX_TEXTATTRBORDERS_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextAttrBorders
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextAttrBorders);

//----------------------------------------------------------------------------
// Object declaration for wxTextAttrBorders
//----------------------------------------------------------------------------
class Object_wx_TextAttrBorders : public Object {
protected:
	wxTextAttrBorders *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TextAttrBorders)
public:
	inline Object_wx_TextAttrBorders(wxTextAttrBorders *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TextAttrBorders(Class *pClass, wxTextAttrBorders *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TextAttrBorders();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTextAttrBorders *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTextAttrBorders *GetEntity() {
		return static_cast<wxTextAttrBorders *>(_pEntity);
	}
	inline wxTextAttrBorders *ReleaseEntity() {
		wxTextAttrBorders *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTextAttrBorders");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
