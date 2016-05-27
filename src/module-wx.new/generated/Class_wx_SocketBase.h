//----------------------------------------------------------------------------
// wxSocketBase
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SOCKETBASE_H__
#define __CLASS_WX_SOCKETBASE_H__
#include <wx/socket.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSocketBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SocketBase);

//----------------------------------------------------------------------------
// Object declaration for wxSocketBase
//----------------------------------------------------------------------------
class Object_wx_SocketBase : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_SocketBase)
public:
	inline Object_wx_SocketBase(wxSocketBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_SocketBase), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SocketBase(Class *pClass, wxSocketBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SocketBase();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSocketBase *GetEntity() {
		return static_cast<wxSocketBase *>(_pEntity);
	}
	inline wxSocketBase *ReleaseEntity() {
		wxSocketBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxSocketBase");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
