//----------------------------------------------------------------------------
// wxHTTP
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTTP_H__
#define __CLASS_WX_HTTP_H__
#include <wx/protocol/http.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHTTP
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HTTP);

//----------------------------------------------------------------------------
// Object declaration for wxHTTP
//----------------------------------------------------------------------------
class Object_wx_HTTP : public Object_wx_Protocol {
public:
	Gura_DeclareObjectAccessor(wx_HTTP)
public:
	inline Object_wx_HTTP(wxHTTP *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Protocol(Gura_UserClass(wx_HTTP), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HTTP(Class *pClass, wxHTTP *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Protocol(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HTTP();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHTTP *GetEntity() {
		return static_cast<wxHTTP *>(_pEntity);
	}
	inline wxHTTP *ReleaseEntity() {
		wxHTTP *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHTTP");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
