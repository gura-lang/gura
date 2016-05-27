//----------------------------------------------------------------------------
// wxFontData
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FONTDATA_H__
#define __CLASS_WX_FONTDATA_H__
#include <wx/fontdata.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFontData
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FontData);

//----------------------------------------------------------------------------
// Object declaration for wxFontData
//----------------------------------------------------------------------------
class Object_wx_FontData : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_FontData)
public:
	inline Object_wx_FontData(wxFontData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_FontData), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FontData(Class *pClass, wxFontData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FontData();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFontData *GetEntity() {
		return static_cast<wxFontData *>(_pEntity);
	}
	inline wxFontData *ReleaseEntity() {
		wxFontData *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxFontData");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
