//----------------------------------------------------------------------------
// wxRichTextLine
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTLINE_H__
#define __CLASS_WX_RICHTEXTLINE_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextLine
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextLine);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextLine
//----------------------------------------------------------------------------
class Object_wx_RichTextLine : public Object {
protected:
	wxRichTextLine *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RichTextLine)
public:
	inline Object_wx_RichTextLine(wxRichTextLine *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RichTextLine(Class *pClass, wxRichTextLine *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RichTextLine();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRichTextLine *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxRichTextLine *GetEntity() {
		return static_cast<wxRichTextLine *>(_pEntity);
	}
	inline wxRichTextLine *ReleaseEntity() {
		wxRichTextLine *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRichTextLine");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
