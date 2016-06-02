//----------------------------------------------------------------------------
// wxBufferedDC
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_BUFFEREDDC_H__
#define __CLASS_WX_BUFFEREDDC_H__
#include <wx/dcbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBufferedDC
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_BufferedDC);

//----------------------------------------------------------------------------
// Object declaration for wxBufferedDC
//----------------------------------------------------------------------------
class Object_wx_BufferedDC : public Object_wx_MemoryDC {
public:
	Gura_DeclareObjectAccessor(wx_BufferedDC)
public:
	inline Object_wx_BufferedDC(wxBufferedDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MemoryDC(Gura_UserClass(wx_BufferedDC), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_BufferedDC(Class *pClass, wxBufferedDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MemoryDC(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_BufferedDC();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxBufferedDC *GetEntity() {
		return static_cast<wxBufferedDC *>(_pEntity);
	}
	inline wxBufferedDC *ReleaseEntity() {
		wxBufferedDC *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxBufferedDC");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
