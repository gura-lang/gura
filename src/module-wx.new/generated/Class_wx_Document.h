//----------------------------------------------------------------------------
// wxDocument
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DOCUMENT_H__
#define __CLASS_WX_DOCUMENT_H__
#include <wx/docview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDocument
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Document);

//----------------------------------------------------------------------------
// Object declaration for wxDocument
//----------------------------------------------------------------------------
class Object_wx_Document : public Object_wx_EvtHandler {
public:
	Gura_DeclareObjectAccessor(wx_Document)
public:
	inline Object_wx_Document(wxDocument *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(Gura_UserClass(wx_Document), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Document(Class *pClass, wxDocument *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Document();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDocument *GetEntity() {
		return static_cast<wxDocument *>(_pEntity);
	}
	inline wxDocument *ReleaseEntity() {
		wxDocument *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDocument");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
