//----------------------------------------------------------------------------
// wxPathList
// extracted from pathlist.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PATHLIST_H__
#define __CLASS_WX_PATHLIST_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPathList
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PathList);

//----------------------------------------------------------------------------
// Object declaration for wxPathList
//----------------------------------------------------------------------------
class Object_wx_PathList : public Object_wx_ArrayString {
public:
	Gura_DeclareObjectAccessor(wx_PathList)
public:
	inline Object_wx_PathList(wxPathList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ArrayString(Gura_UserClass(wx_PathList), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PathList(Class *pClass, wxPathList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ArrayString(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PathList();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPathList *GetEntity() {
		return dynamic_cast<wxPathList *>(_pEntity);
	}
	inline wxPathList *ReleaseEntity() {
		wxPathList *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPathList");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
