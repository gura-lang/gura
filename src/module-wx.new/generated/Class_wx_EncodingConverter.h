//----------------------------------------------------------------------------
// wxEncodingConverter
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ENCODINGCONVERTER_H__
#define __CLASS_WX_ENCODINGCONVERTER_H__
#include <wx/encconv.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxEncodingConverter
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_EncodingConverter);

//----------------------------------------------------------------------------
// Object declaration for wxEncodingConverter
//----------------------------------------------------------------------------
class Object_wx_EncodingConverter : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_EncodingConverter)
public:
	inline Object_wx_EncodingConverter(wxEncodingConverter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_EncodingConverter), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_EncodingConverter(Class *pClass, wxEncodingConverter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_EncodingConverter();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxEncodingConverter *GetEntity() {
		return static_cast<wxEncodingConverter *>(_pEntity);
	}
	inline wxEncodingConverter *ReleaseEntity() {
		wxEncodingConverter *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxEncodingConverter");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
