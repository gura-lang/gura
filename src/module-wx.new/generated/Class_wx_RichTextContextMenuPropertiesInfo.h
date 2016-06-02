//----------------------------------------------------------------------------
// wxRichTextContextMenuPropertiesInfo
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTCONTEXTMENUPROPERTIESINFO_H__
#define __CLASS_WX_RICHTEXTCONTEXTMENUPROPERTIESINFO_H__
#include <wx/richtext/richtextctrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextContextMenuPropertiesInfo
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextContextMenuPropertiesInfo);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextContextMenuPropertiesInfo
//----------------------------------------------------------------------------
class Object_wx_RichTextContextMenuPropertiesInfo : public Object {
protected:
	wxRichTextContextMenuPropertiesInfo *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RichTextContextMenuPropertiesInfo)
public:
	inline Object_wx_RichTextContextMenuPropertiesInfo(wxRichTextContextMenuPropertiesInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RichTextContextMenuPropertiesInfo(Class *pClass, wxRichTextContextMenuPropertiesInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RichTextContextMenuPropertiesInfo();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRichTextContextMenuPropertiesInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxRichTextContextMenuPropertiesInfo *GetEntity() {
		return static_cast<wxRichTextContextMenuPropertiesInfo *>(_pEntity);
	}
	inline wxRichTextContextMenuPropertiesInfo *ReleaseEntity() {
		wxRichTextContextMenuPropertiesInfo *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextContextMenuPropertiesInfo");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
