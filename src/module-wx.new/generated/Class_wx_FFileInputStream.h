//----------------------------------------------------------------------------
// wxFFileInputStream
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FFILEINPUTSTREAM_H__
#define __CLASS_WX_FFILEINPUTSTREAM_H__
#include <wx/wfstream.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFFileInputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FFileInputStream);

//----------------------------------------------------------------------------
// Object declaration for wxFFileInputStream
//----------------------------------------------------------------------------
class Object_wx_FFileInputStream : public Object_wx_InputStream {
public:
	Gura_DeclareObjectAccessor(wx_FFileInputStream)
public:
	inline Object_wx_FFileInputStream(wxFFileInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_InputStream(Gura_UserClass(wx_FFileInputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FFileInputStream(Class *pClass, wxFFileInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_InputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FFileInputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFFileInputStream *GetEntity() {
		return static_cast<wxFFileInputStream *>(_pEntity);
	}
	inline wxFFileInputStream *ReleaseEntity() {
		wxFFileInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxFFileInputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
