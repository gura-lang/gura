//----------------------------------------------------------------------------
// wxRichTextTableBlock
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTTABLEBLOCK_H__
#define __CLASS_WX_RICHTEXTTABLEBLOCK_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextTableBlock
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextTableBlock);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextTableBlock
//----------------------------------------------------------------------------
class Object_wx_RichTextTableBlock : public Object {
protected:
	wxRichTextTableBlock *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RichTextTableBlock)
public:
	inline Object_wx_RichTextTableBlock(wxRichTextTableBlock *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RichTextTableBlock(Class *pClass, wxRichTextTableBlock *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RichTextTableBlock();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRichTextTableBlock *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxRichTextTableBlock *GetEntity() {
		return static_cast<wxRichTextTableBlock *>(_pEntity);
	}
	inline wxRichTextTableBlock *ReleaseEntity() {
		wxRichTextTableBlock *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRichTextTableBlock");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
