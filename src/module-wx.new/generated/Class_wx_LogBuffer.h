//----------------------------------------------------------------------------
// wxLogBuffer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LOGBUFFER_H__
#define __CLASS_WX_LOGBUFFER_H__
#include <wx/log.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxLogBuffer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_LogBuffer);

//----------------------------------------------------------------------------
// Object declaration for wxLogBuffer
//----------------------------------------------------------------------------
class Object_wx_LogBuffer : public Object_wx_Log {
public:
	Gura_DeclareObjectAccessor(wx_LogBuffer)
public:
	inline Object_wx_LogBuffer(wxLogBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Log(Gura_UserClass(wx_LogBuffer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_LogBuffer(Class *pClass, wxLogBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Log(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_LogBuffer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxLogBuffer *GetEntity() {
		return static_cast<wxLogBuffer *>(_pEntity);
	}
	inline wxLogBuffer *ReleaseEntity() {
		wxLogBuffer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxLogBuffer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
