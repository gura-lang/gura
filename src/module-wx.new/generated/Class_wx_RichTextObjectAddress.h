//----------------------------------------------------------------------------
// wxRichTextObjectAddress
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTOBJECTADDRESS_H__
#define __CLASS_WX_RICHTEXTOBJECTADDRESS_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextObjectAddress
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextObjectAddress);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextObjectAddress
//----------------------------------------------------------------------------
class Object_wx_RichTextObjectAddress : public Object {
protected:
	wxRichTextObjectAddress *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RichTextObjectAddress)
public:
	inline Object_wx_RichTextObjectAddress(wxRichTextObjectAddress *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RichTextObjectAddress(Class *pClass, wxRichTextObjectAddress *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RichTextObjectAddress();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRichTextObjectAddress *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxRichTextObjectAddress *GetEntity() {
		return static_cast<wxRichTextObjectAddress *>(_pEntity);
	}
	inline wxRichTextObjectAddress *ReleaseEntity() {
		wxRichTextObjectAddress *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextObjectAddress");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
