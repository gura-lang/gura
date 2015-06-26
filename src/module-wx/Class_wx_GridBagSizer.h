//----------------------------------------------------------------------------
// wxGridBagSizer
// extracted from gridbagsizer.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDBAGSIZER_H__
#define __CLASS_WX_GRIDBAGSIZER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridBagSizer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridBagSizer);

//----------------------------------------------------------------------------
// Object declaration for wxGridBagSizer
//----------------------------------------------------------------------------
class Object_wx_GridBagSizer : public Object_wx_FlexGridSizer {
public:
	Gura_DeclareObjectAccessor(wx_GridBagSizer)
public:
	inline Object_wx_GridBagSizer(wxGridBagSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FlexGridSizer(Gura_UserClass(wx_GridBagSizer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridBagSizer(Class *pClass, wxGridBagSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FlexGridSizer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridBagSizer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridBagSizer *GetEntity() {
		return dynamic_cast<wxGridBagSizer *>(_pEntity);
	}
	inline wxGridBagSizer *ReleaseEntity() {
		wxGridBagSizer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGridBagSizer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
