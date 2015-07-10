//----------------------------------------------------------------------------
// wxFileSystemHandler
// extracted from filesysh.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FILESYSTEMHANDLER_H__
#define __CLASS_WX_FILESYSTEMHANDLER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFileSystemHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FileSystemHandler);

//----------------------------------------------------------------------------
// Object declaration for wxFileSystemHandler
//----------------------------------------------------------------------------
class Object_wx_FileSystemHandler : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_FileSystemHandler)
public:
	inline Object_wx_FileSystemHandler(wxFileSystemHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_FileSystemHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FileSystemHandler(Class *pClass, wxFileSystemHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FileSystemHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFileSystemHandler *GetEntity() {
		return dynamic_cast<wxFileSystemHandler *>(_pEntity);
	}
	inline wxFileSystemHandler *ReleaseEntity() {
		wxFileSystemHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxFileSystemHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
