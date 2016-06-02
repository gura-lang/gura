//----------------------------------------------------------------------------
// wxRichTextSelection
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTSELECTION_H__
#define __CLASS_WX_RICHTEXTSELECTION_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextSelection
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextSelection);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextSelection
//----------------------------------------------------------------------------
class Object_wx_RichTextSelection : public Object {
protected:
	wxRichTextSelection *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RichTextSelection)
public:
	inline Object_wx_RichTextSelection(wxRichTextSelection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RichTextSelection(Class *pClass, wxRichTextSelection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RichTextSelection();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRichTextSelection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxRichTextSelection *GetEntity() {
		return static_cast<wxRichTextSelection *>(_pEntity);
	}
	inline wxRichTextSelection *ReleaseEntity() {
		wxRichTextSelection *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextSelection");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
