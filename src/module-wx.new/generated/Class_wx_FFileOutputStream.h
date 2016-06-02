//----------------------------------------------------------------------------
// wxFFileOutputStream
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FFILEOUTPUTSTREAM_H__
#define __CLASS_WX_FFILEOUTPUTSTREAM_H__
#include <wx/wfstream.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFFileOutputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FFileOutputStream);

//----------------------------------------------------------------------------
// Object declaration for wxFFileOutputStream
//----------------------------------------------------------------------------
class Object_wx_FFileOutputStream : public Object_wx_OutputStream {
public:
	Gura_DeclareObjectAccessor(wx_FFileOutputStream)
public:
	inline Object_wx_FFileOutputStream(wxFFileOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_OutputStream(Gura_UserClass(wx_FFileOutputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FFileOutputStream(Class *pClass, wxFFileOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_OutputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FFileOutputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFFileOutputStream *GetEntity() {
		return static_cast<wxFFileOutputStream *>(_pEntity);
	}
	inline wxFFileOutputStream *ReleaseEntity() {
		wxFFileOutputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxFFileOutputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
