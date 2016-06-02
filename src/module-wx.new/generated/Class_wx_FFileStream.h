//----------------------------------------------------------------------------
// wxFFileStream
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FFILESTREAM_H__
#define __CLASS_WX_FFILESTREAM_H__
#include <wx/wfstream.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFFileStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FFileStream);

//----------------------------------------------------------------------------
// Object declaration for wxFFileStream
//----------------------------------------------------------------------------
class Object_wx_FFileStream : public Object_wx_FFileInputStream {
public:
	Gura_DeclareObjectAccessor(wx_FFileStream)
public:
	inline Object_wx_FFileStream(wxFFileStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FFileInputStream(Gura_UserClass(wx_FFileStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FFileStream(Class *pClass, wxFFileStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FFileInputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FFileStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFFileStream *GetEntity() {
		return static_cast<wxFFileStream *>(_pEntity);
	}
	inline wxFFileStream *ReleaseEntity() {
		wxFFileStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxFFileStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
