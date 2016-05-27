//----------------------------------------------------------------------------
// wxFilterInputStream
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FILTERINPUTSTREAM_H__
#define __CLASS_WX_FILTERINPUTSTREAM_H__
#include <wx/stream.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFilterInputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FilterInputStream);

//----------------------------------------------------------------------------
// Object declaration for wxFilterInputStream
//----------------------------------------------------------------------------
class Object_wx_FilterInputStream : public Object_wx_InputStream {
public:
	Gura_DeclareObjectAccessor(wx_FilterInputStream)
public:
	inline Object_wx_FilterInputStream(wxFilterInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_InputStream(Gura_UserClass(wx_FilterInputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FilterInputStream(Class *pClass, wxFilterInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_InputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FilterInputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFilterInputStream *GetEntity() {
		return static_cast<wxFilterInputStream *>(_pEntity);
	}
	inline wxFilterInputStream *ReleaseEntity() {
		wxFilterInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxFilterInputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
