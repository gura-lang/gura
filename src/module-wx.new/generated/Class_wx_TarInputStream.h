//----------------------------------------------------------------------------
// wxTarInputStream
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TARINPUTSTREAM_H__
#define __CLASS_WX_TARINPUTSTREAM_H__
#include <wx/tarstrm.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTarInputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TarInputStream);

//----------------------------------------------------------------------------
// Object declaration for wxTarInputStream
//----------------------------------------------------------------------------
class Object_wx_TarInputStream : public Object_wx_ArchiveInputStream {
public:
	Gura_DeclareObjectAccessor(wx_TarInputStream)
public:
	inline Object_wx_TarInputStream(wxTarInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ArchiveInputStream(Gura_UserClass(wx_TarInputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TarInputStream(Class *pClass, wxTarInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ArchiveInputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TarInputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTarInputStream *GetEntity() {
		return static_cast<wxTarInputStream *>(_pEntity);
	}
	inline wxTarInputStream *ReleaseEntity() {
		wxTarInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTarInputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
