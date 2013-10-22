//----------------------------------------------------------------------------
// wxImageList
// extracted from imaglist.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_IMAGELIST_H__
#define __OBJECT_WX_IMAGELIST_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxImageList
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ImageList);

//----------------------------------------------------------------------------
// Object declaration for wxImageList
//----------------------------------------------------------------------------
class Object_wx_ImageList : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_ImageList)
public:
	inline Object_wx_ImageList(wxImageList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_ImageList), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ImageList(Class *pClass, wxImageList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ImageList();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxImageList *GetEntity() {
		return dynamic_cast<wxImageList *>(_pEntity);
	}
	inline wxImageList *ReleaseEntity() {
		wxImageList *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxImageList");
		return true;
	}
};

}}

#endif
