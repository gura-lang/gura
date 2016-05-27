//----------------------------------------------------------------------------
// wxWrapperInputStream
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WRAPPERINPUTSTREAM_H__
#define __CLASS_WX_WRAPPERINPUTSTREAM_H__
#include <wx/stream.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWrapperInputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WrapperInputStream);

//----------------------------------------------------------------------------
// Object declaration for wxWrapperInputStream
//----------------------------------------------------------------------------
class Object_wx_WrapperInputStream : public Object_wx_FilterInputStream {
public:
	Gura_DeclareObjectAccessor(wx_WrapperInputStream)
public:
	inline Object_wx_WrapperInputStream(wxWrapperInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FilterInputStream(Gura_UserClass(wx_WrapperInputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_WrapperInputStream(Class *pClass, wxWrapperInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FilterInputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_WrapperInputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWrapperInputStream *GetEntity() {
		return static_cast<wxWrapperInputStream *>(_pEntity);
	}
	inline wxWrapperInputStream *ReleaseEntity() {
		wxWrapperInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxWrapperInputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
