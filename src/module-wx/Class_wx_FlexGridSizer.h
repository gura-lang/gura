//----------------------------------------------------------------------------
// wxFlexGridSizer
// extracted from flexsizr.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FLEXGRIDSIZER_H__
#define __CLASS_WX_FLEXGRIDSIZER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFlexGridSizer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FlexGridSizer);

//----------------------------------------------------------------------------
// Object declaration for wxFlexGridSizer
//----------------------------------------------------------------------------
class Object_wx_FlexGridSizer : public Object_wx_GridSizer {
public:
	Gura_DeclareObjectAccessor(wx_FlexGridSizer)
public:
	inline Object_wx_FlexGridSizer(wxFlexGridSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridSizer(Gura_UserClass(wx_FlexGridSizer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FlexGridSizer(Class *pClass, wxFlexGridSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridSizer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FlexGridSizer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFlexGridSizer *GetEntity() {
		return dynamic_cast<wxFlexGridSizer *>(_pEntity);
	}
	inline wxFlexGridSizer *ReleaseEntity() {
		wxFlexGridSizer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxFlexGridSizer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
