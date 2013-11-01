//----------------------------------------------------------------------------
// wxMetafile
// extracted from metafile.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_METAFILE_H__
#define __OBJECT_WX_METAFILE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMetafile
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Metafile);

//----------------------------------------------------------------------------
// Object declaration for wxMetafile
//----------------------------------------------------------------------------
class Object_wx_Metafile : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Metafile)
public:
	inline Object_wx_Metafile(wxMetafile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Metafile), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Metafile(Class *pClass, wxMetafile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Metafile();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMetafile *GetEntity() {
		return dynamic_cast<wxMetafile *>(_pEntity);
	}
	inline wxMetafile *ReleaseEntity() {
		wxMetafile *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxMetafile");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
