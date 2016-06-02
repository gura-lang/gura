//----------------------------------------------------------------------------
// wxHtmlBookRecord
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLBOOKRECORD_H__
#define __CLASS_WX_HTMLBOOKRECORD_H__
#include <wx/html/helpdata.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlBookRecord
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlBookRecord);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlBookRecord
//----------------------------------------------------------------------------
class Object_wx_HtmlBookRecord : public Object {
protected:
	wxHtmlBookRecord *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_HtmlBookRecord)
public:
	inline Object_wx_HtmlBookRecord(wxHtmlBookRecord *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_HtmlBookRecord(Class *pClass, wxHtmlBookRecord *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_HtmlBookRecord();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxHtmlBookRecord *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxHtmlBookRecord *GetEntity() {
		return static_cast<wxHtmlBookRecord *>(_pEntity);
	}
	inline wxHtmlBookRecord *ReleaseEntity() {
		wxHtmlBookRecord *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHtmlBookRecord");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
