//----------------------------------------------------------------------------
// wxHtmlRenderingState
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLRENDERINGSTATE_H__
#define __CLASS_WX_HTMLRENDERINGSTATE_H__
#include <wx/html/htmlcell.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlRenderingState
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlRenderingState);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlRenderingState
//----------------------------------------------------------------------------
class Object_wx_HtmlRenderingState : public Object {
protected:
	wxHtmlRenderingState *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_HtmlRenderingState)
public:
	inline Object_wx_HtmlRenderingState(wxHtmlRenderingState *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_HtmlRenderingState(Class *pClass, wxHtmlRenderingState *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_HtmlRenderingState();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxHtmlRenderingState *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxHtmlRenderingState *GetEntity() {
		return static_cast<wxHtmlRenderingState *>(_pEntity);
	}
	inline wxHtmlRenderingState *ReleaseEntity() {
		wxHtmlRenderingState *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHtmlRenderingState");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
