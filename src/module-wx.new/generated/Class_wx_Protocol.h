//----------------------------------------------------------------------------
// wxProtocol
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PROTOCOL_H__
#define __CLASS_WX_PROTOCOL_H__
#include <wx/protocol/protocol.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxProtocol
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Protocol);

//----------------------------------------------------------------------------
// Object declaration for wxProtocol
//----------------------------------------------------------------------------
class Object_wx_Protocol : public Object_wx_SocketClient {
public:
	Gura_DeclareObjectAccessor(wx_Protocol)
public:
	inline Object_wx_Protocol(wxProtocol *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SocketClient(Gura_UserClass(wx_Protocol), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Protocol(Class *pClass, wxProtocol *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SocketClient(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Protocol();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxProtocol *GetEntity() {
		return static_cast<wxProtocol *>(_pEntity);
	}
	inline wxProtocol *ReleaseEntity() {
		wxProtocol *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxProtocol");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
