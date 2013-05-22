//----------------------------------------------------------------------------
// wxTarOutputStream
// extracted from tarstrm.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TAROUTPUTSTREAM_H__
#define __OBJECT_WX_TAROUTPUTSTREAM_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTarOutputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TarOutputStream);

//----------------------------------------------------------------------------
// Object declaration for wxTarOutputStream
//----------------------------------------------------------------------------
class Object_wx_TarOutputStream : public Object_wx_ArchiveOutputStream {
public:
	Gura_DeclareObjectAccessor(wx_TarOutputStream)
public:
	inline Object_wx_TarOutputStream(wxTarOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ArchiveOutputStream(Gura_UserClass(wx_TarOutputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TarOutputStream(Class *pClass, wxTarOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ArchiveOutputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TarOutputStream();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxTarOutputStream *GetEntity() {
		return dynamic_cast<wxTarOutputStream *>(_pEntity);
	}
	inline wxTarOutputStream *ReleaseEntity() {
		wxTarOutputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTarOutputStream");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
