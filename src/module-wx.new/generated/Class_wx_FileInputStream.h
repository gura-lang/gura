//----------------------------------------------------------------------------
// wxFileInputStream
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FILEINPUTSTREAM_H__
#define __CLASS_WX_FILEINPUTSTREAM_H__
#include <wx/wfstream.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFileInputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FileInputStream);

//----------------------------------------------------------------------------
// Object declaration for wxFileInputStream
//----------------------------------------------------------------------------
class Object_wx_FileInputStream : public Object_wx_InputStream {
public:
	Gura_DeclareObjectAccessor(wx_FileInputStream)
public:
	inline Object_wx_FileInputStream(wxFileInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_InputStream(Gura_UserClass(wx_FileInputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FileInputStream(Class *pClass, wxFileInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_InputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FileInputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFileInputStream *GetEntity() {
		return static_cast<wxFileInputStream *>(_pEntity);
	}
	inline wxFileInputStream *ReleaseEntity() {
		wxFileInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxFileInputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
