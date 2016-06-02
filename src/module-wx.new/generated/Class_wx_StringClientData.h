//----------------------------------------------------------------------------
// wxStringClientData
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STRINGCLIENTDATA_H__
#define __CLASS_WX_STRINGCLIENTDATA_H__
#include <wx/clntdata.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStringClientData
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StringClientData);

//----------------------------------------------------------------------------
// Object declaration for wxStringClientData
//----------------------------------------------------------------------------
class Object_wx_StringClientData : public Object_wx_ClientData {
public:
	Gura_DeclareObjectAccessor(wx_StringClientData)
public:
	inline Object_wx_StringClientData(wxStringClientData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientData(Gura_UserClass(wx_StringClientData), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_StringClientData(Class *pClass, wxStringClientData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientData(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_StringClientData();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxStringClientData *GetEntity() {
		return static_cast<wxStringClientData *>(_pEntity);
	}
	inline wxStringClientData *ReleaseEntity() {
		wxStringClientData *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxStringClientData");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
