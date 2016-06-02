//----------------------------------------------------------------------------
// wxVariantData
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_VARIANTDATA_H__
#define __CLASS_WX_VARIANTDATA_H__
#include <wx/variant.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxVariantData
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_VariantData);

//----------------------------------------------------------------------------
// Object declaration for wxVariantData
//----------------------------------------------------------------------------
class Object_wx_VariantData : public Object {
protected:
	wxVariantData *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_VariantData)
public:
	inline Object_wx_VariantData(wxVariantData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_VariantData(Class *pClass, wxVariantData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_VariantData();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxVariantData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxVariantData *GetEntity() {
		return static_cast<wxVariantData *>(_pEntity);
	}
	inline wxVariantData *ReleaseEntity() {
		wxVariantData *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxVariantData");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
