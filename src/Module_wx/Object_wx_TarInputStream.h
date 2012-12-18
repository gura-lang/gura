//----------------------------------------------------------------------------
// wxTarInputStream
// extracted from tarstrm.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TARINPUTSTREAM_H__
#define __OBJECT_WX_TARINPUTSTREAM_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxTarInputStream *GetEntity() {
		return dynamic_cast<wxTarInputStream *>(_pEntity);
	}
	inline wxTarInputStream *ReleaseEntity() {
		wxTarInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTarInputStream");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
