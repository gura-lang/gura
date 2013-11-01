//----------------------------------------------------------------------------
// wxRegionIterator
// extracted from region.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_REGIONITERATOR_H__
#define __OBJECT_WX_REGIONITERATOR_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRegionIterator
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RegionIterator);

//----------------------------------------------------------------------------
// Object declaration for wxRegionIterator
//----------------------------------------------------------------------------
class Object_wx_RegionIterator : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_RegionIterator)
public:
	inline Object_wx_RegionIterator(wxRegionIterator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_RegionIterator), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RegionIterator(Class *pClass, wxRegionIterator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RegionIterator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRegionIterator *GetEntity() {
		return dynamic_cast<wxRegionIterator *>(_pEntity);
	}
	inline wxRegionIterator *ReleaseEntity() {
		wxRegionIterator *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRegionIterator");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
