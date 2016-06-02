//----------------------------------------------------------------------------
// wxTextAttrDimensionConverter
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTATTRDIMENSIONCONVERTER_H__
#define __CLASS_WX_TEXTATTRDIMENSIONCONVERTER_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextAttrDimensionConverter
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextAttrDimensionConverter);

//----------------------------------------------------------------------------
// Object declaration for wxTextAttrDimensionConverter
//----------------------------------------------------------------------------
class Object_wx_TextAttrDimensionConverter : public Object {
protected:
	wxTextAttrDimensionConverter *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TextAttrDimensionConverter)
public:
	inline Object_wx_TextAttrDimensionConverter(wxTextAttrDimensionConverter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TextAttrDimensionConverter(Class *pClass, wxTextAttrDimensionConverter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TextAttrDimensionConverter();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTextAttrDimensionConverter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTextAttrDimensionConverter *GetEntity() {
		return static_cast<wxTextAttrDimensionConverter *>(_pEntity);
	}
	inline wxTextAttrDimensionConverter *ReleaseEntity() {
		wxTextAttrDimensionConverter *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTextAttrDimensionConverter");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
