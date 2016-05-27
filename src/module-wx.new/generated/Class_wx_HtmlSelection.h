//----------------------------------------------------------------------------
// wxHtmlSelection
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLSELECTION_H__
#define __CLASS_WX_HTMLSELECTION_H__
#include <wx/html/htmlcell.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlSelection
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlSelection);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlSelection
//----------------------------------------------------------------------------
class Object_wx_HtmlSelection : public Object {
protected:
	wxHtmlSelection *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_HtmlSelection)
public:
	inline Object_wx_HtmlSelection(wxHtmlSelection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_HtmlSelection(Class *pClass, wxHtmlSelection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_HtmlSelection();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxHtmlSelection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxHtmlSelection *GetEntity() {
		return static_cast<wxHtmlSelection *>(_pEntity);
	}
	inline wxHtmlSelection *ReleaseEntity() {
		wxHtmlSelection *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxHtmlSelection");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
