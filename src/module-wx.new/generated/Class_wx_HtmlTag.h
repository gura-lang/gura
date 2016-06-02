//----------------------------------------------------------------------------
// wxHtmlTag
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLTAG_H__
#define __CLASS_WX_HTMLTAG_H__
#include <wx/html/htmltag.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlTag
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlTag);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlTag
//----------------------------------------------------------------------------
class Object_wx_HtmlTag : public Object {
protected:
	wxHtmlTag *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_HtmlTag)
public:
	inline Object_wx_HtmlTag(wxHtmlTag *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_HtmlTag(Class *pClass, wxHtmlTag *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_HtmlTag();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxHtmlTag *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxHtmlTag *GetEntity() {
		return static_cast<wxHtmlTag *>(_pEntity);
	}
	inline wxHtmlTag *ReleaseEntity() {
		wxHtmlTag *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHtmlTag");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
