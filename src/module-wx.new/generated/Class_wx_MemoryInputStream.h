//----------------------------------------------------------------------------
// wxMemoryInputStream
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MEMORYINPUTSTREAM_H__
#define __CLASS_WX_MEMORYINPUTSTREAM_H__
#include <wx/mstream.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMemoryInputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MemoryInputStream);

//----------------------------------------------------------------------------
// Object declaration for wxMemoryInputStream
//----------------------------------------------------------------------------
class Object_wx_MemoryInputStream : public Object_wx_InputStream {
public:
	Gura_DeclareObjectAccessor(wx_MemoryInputStream)
public:
	inline Object_wx_MemoryInputStream(wxMemoryInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_InputStream(Gura_UserClass(wx_MemoryInputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MemoryInputStream(Class *pClass, wxMemoryInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_InputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MemoryInputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMemoryInputStream *GetEntity() {
		return static_cast<wxMemoryInputStream *>(_pEntity);
	}
	inline wxMemoryInputStream *ReleaseEntity() {
		wxMemoryInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxMemoryInputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
