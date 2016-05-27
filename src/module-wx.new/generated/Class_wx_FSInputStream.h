//----------------------------------------------------------------------------
// wxFSInputStream
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FSINPUTSTREAM_H__
#define __CLASS_WX_FSINPUTSTREAM_H__
#include <wx/filesys.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFSInputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FSInputStream);

//----------------------------------------------------------------------------
// Object declaration for wxFSInputStream
//----------------------------------------------------------------------------
class Object_wx_FSInputStream : public Object_wx_WrapperInputStream {
public:
	Gura_DeclareObjectAccessor(wx_FSInputStream)
public:
	inline Object_wx_FSInputStream(wxFSInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_WrapperInputStream(Gura_UserClass(wx_FSInputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FSInputStream(Class *pClass, wxFSInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_WrapperInputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FSInputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFSInputStream *GetEntity() {
		return static_cast<wxFSInputStream *>(_pEntity);
	}
	inline wxFSInputStream *ReleaseEntity() {
		wxFSInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxFSInputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
