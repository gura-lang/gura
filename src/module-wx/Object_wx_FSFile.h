//----------------------------------------------------------------------------
// wxFSFile
// extracted from fsfile.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_FSFILE_H__
#define __OBJECT_WX_FSFILE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFSFile
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FSFile);

//----------------------------------------------------------------------------
// Object declaration for wxFSFile
//----------------------------------------------------------------------------
class Object_wx_FSFile : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_FSFile)
public:
	inline Object_wx_FSFile(wxFSFile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_FSFile), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FSFile(Class *pClass, wxFSFile *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FSFile();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxFSFile *GetEntity() {
		return dynamic_cast<wxFSFile *>(_pEntity);
	}
	inline wxFSFile *ReleaseEntity() {
		wxFSFile *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFSFile");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
