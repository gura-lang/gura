//----------------------------------------------------------------------------
// wxTextAttrBorder
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTATTRBORDER_H__
#define __CLASS_WX_TEXTATTRBORDER_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextAttrBorder
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextAttrBorder);

//----------------------------------------------------------------------------
// Object declaration for wxTextAttrBorder
//----------------------------------------------------------------------------
class Object_wx_TextAttrBorder : public Object {
protected:
	wxTextAttrBorder *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TextAttrBorder)
public:
	inline Object_wx_TextAttrBorder(wxTextAttrBorder *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TextAttrBorder(Class *pClass, wxTextAttrBorder *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TextAttrBorder();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTextAttrBorder *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTextAttrBorder *GetEntity() {
		return static_cast<wxTextAttrBorder *>(_pEntity);
	}
	inline wxTextAttrBorder *ReleaseEntity() {
		wxTextAttrBorder *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTextAttrBorder");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
