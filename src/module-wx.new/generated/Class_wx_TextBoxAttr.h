//----------------------------------------------------------------------------
// wxTextBoxAttr
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTBOXATTR_H__
#define __CLASS_WX_TEXTBOXATTR_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextBoxAttr
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextBoxAttr);

//----------------------------------------------------------------------------
// Object declaration for wxTextBoxAttr
//----------------------------------------------------------------------------
class Object_wx_TextBoxAttr : public Object {
protected:
	wxTextBoxAttr *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TextBoxAttr)
public:
	inline Object_wx_TextBoxAttr(wxTextBoxAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TextBoxAttr(Class *pClass, wxTextBoxAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TextBoxAttr();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTextBoxAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTextBoxAttr *GetEntity() {
		return static_cast<wxTextBoxAttr *>(_pEntity);
	}
	inline wxTextBoxAttr *ReleaseEntity() {
		wxTextBoxAttr *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTextBoxAttr");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
