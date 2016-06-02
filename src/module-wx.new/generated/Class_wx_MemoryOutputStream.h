//----------------------------------------------------------------------------
// wxMemoryOutputStream
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MEMORYOUTPUTSTREAM_H__
#define __CLASS_WX_MEMORYOUTPUTSTREAM_H__
#include <wx/mstream.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMemoryOutputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MemoryOutputStream);

//----------------------------------------------------------------------------
// Object declaration for wxMemoryOutputStream
//----------------------------------------------------------------------------
class Object_wx_MemoryOutputStream : public Object_wx_OutputStream {
public:
	Gura_DeclareObjectAccessor(wx_MemoryOutputStream)
public:
	inline Object_wx_MemoryOutputStream(wxMemoryOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_OutputStream(Gura_UserClass(wx_MemoryOutputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MemoryOutputStream(Class *pClass, wxMemoryOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_OutputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MemoryOutputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMemoryOutputStream *GetEntity() {
		return static_cast<wxMemoryOutputStream *>(_pEntity);
	}
	inline wxMemoryOutputStream *ReleaseEntity() {
		wxMemoryOutputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxMemoryOutputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
