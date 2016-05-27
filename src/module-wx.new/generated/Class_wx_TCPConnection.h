//----------------------------------------------------------------------------
// wxTCPConnection
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TCPCONNECTION_H__
#define __CLASS_WX_TCPCONNECTION_H__
#include <wx/sckipc.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTCPConnection
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TCPConnection);

//----------------------------------------------------------------------------
// Object declaration for wxTCPConnection
//----------------------------------------------------------------------------
class Object_wx_TCPConnection : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_TCPConnection)
public:
	inline Object_wx_TCPConnection(wxTCPConnection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_TCPConnection), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TCPConnection(Class *pClass, wxTCPConnection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TCPConnection();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTCPConnection *GetEntity() {
		return static_cast<wxTCPConnection *>(_pEntity);
	}
	inline wxTCPConnection *ReleaseEntity() {
		wxTCPConnection *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTCPConnection");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
