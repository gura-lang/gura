//----------------------------------------------------------------------------
// wxDragImage
// extracted from dragimag.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DRAGIMAGE_H__
#define __CLASS_WX_DRAGIMAGE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDragImage
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DragImage);

//----------------------------------------------------------------------------
// Object declaration for wxDragImage
//----------------------------------------------------------------------------
class Object_wx_DragImage : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_DragImage)
public:
	inline Object_wx_DragImage(wxDragImage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_DragImage), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DragImage(Class *pClass, wxDragImage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DragImage();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDragImage *GetEntity() {
		return dynamic_cast<wxDragImage *>(_pEntity);
	}
	inline wxDragImage *ReleaseEntity() {
		wxDragImage *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDragImage");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
