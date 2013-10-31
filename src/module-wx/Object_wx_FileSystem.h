//----------------------------------------------------------------------------
// wxFileSystem
// extracted from filesys.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_FILESYSTEM_H__
#define __OBJECT_WX_FILESYSTEM_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFileSystem
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FileSystem);

//----------------------------------------------------------------------------
// Object declaration for wxFileSystem
//----------------------------------------------------------------------------
class Object_wx_FileSystem : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_FileSystem)
public:
	inline Object_wx_FileSystem(wxFileSystem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_FileSystem), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FileSystem(Class *pClass, wxFileSystem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FileSystem();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxFileSystem *GetEntity() {
		return dynamic_cast<wxFileSystem *>(_pEntity);
	}
	inline wxFileSystem *ReleaseEntity() {
		wxFileSystem *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFileSystem");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
