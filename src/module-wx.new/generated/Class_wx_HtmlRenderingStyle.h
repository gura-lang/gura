//----------------------------------------------------------------------------
// wxHtmlRenderingStyle
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLRENDERINGSTYLE_H__
#define __CLASS_WX_HTMLRENDERINGSTYLE_H__
#include <wx/html/htmlcell.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlRenderingStyle
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlRenderingStyle);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlRenderingStyle
//----------------------------------------------------------------------------
class Object_wx_HtmlRenderingStyle : public Object {
protected:
	wxHtmlRenderingStyle *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_HtmlRenderingStyle)
public:
	inline Object_wx_HtmlRenderingStyle(wxHtmlRenderingStyle *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_HtmlRenderingStyle(Class *pClass, wxHtmlRenderingStyle *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_HtmlRenderingStyle();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxHtmlRenderingStyle *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxHtmlRenderingStyle *GetEntity() {
		return static_cast<wxHtmlRenderingStyle *>(_pEntity);
	}
	inline wxHtmlRenderingStyle *ReleaseEntity() {
		wxHtmlRenderingStyle *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxHtmlRenderingStyle");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
