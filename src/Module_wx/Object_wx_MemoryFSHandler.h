//----------------------------------------------------------------------------
// wxMemoryFSHandler
// extracted from fs_mem.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_MEMORYFSHANDLER_H__
#define __OBJECT_WX_MEMORYFSHANDLER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMemoryFSHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MemoryFSHandler);

//----------------------------------------------------------------------------
// Object declaration for wxMemoryFSHandler
//----------------------------------------------------------------------------
class Object_wx_MemoryFSHandler : public Object_wx_FileSystemHandler {
public:
	Gura_DeclareObjectAccessor(wx_MemoryFSHandler)
public:
	inline Object_wx_MemoryFSHandler(wxMemoryFSHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FileSystemHandler(Gura_UserClass(wx_MemoryFSHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MemoryFSHandler(Class *pClass, wxMemoryFSHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FileSystemHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MemoryFSHandler();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxMemoryFSHandler *GetEntity() {
		return dynamic_cast<wxMemoryFSHandler *>(_pEntity);
	}
	inline wxMemoryFSHandler *ReleaseEntity() {
		wxMemoryFSHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxMemoryFSHandler");
		return true;
	}
};

}}

#endif
