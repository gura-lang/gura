//----------------------------------------------------------------------------
// wxHtmlRenderingInfo
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLRENDERINGINFO_H__
#define __CLASS_WX_HTMLRENDERINGINFO_H__
#include <wx/html/htmlcell.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlRenderingInfo
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlRenderingInfo);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlRenderingInfo
//----------------------------------------------------------------------------
class Object_wx_HtmlRenderingInfo : public Object {
protected:
	wxHtmlRenderingInfo *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_HtmlRenderingInfo)
public:
	inline Object_wx_HtmlRenderingInfo(wxHtmlRenderingInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_HtmlRenderingInfo(Class *pClass, wxHtmlRenderingInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_HtmlRenderingInfo();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxHtmlRenderingInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxHtmlRenderingInfo *GetEntity() {
		return static_cast<wxHtmlRenderingInfo *>(_pEntity);
	}
	inline wxHtmlRenderingInfo *ReleaseEntity() {
		wxHtmlRenderingInfo *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHtmlRenderingInfo");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
