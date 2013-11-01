//----------------------------------------------------------------------------
// wxEncodingConverter
// extracted from encconv.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ENCODINGCONVERTER_H__
#define __CLASS_WX_ENCODINGCONVERTER_H__

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
		return dynamic_cast<wxEncodingConverter *>(_pEntity);
	}
	inline wxEncodingConverter *ReleaseEntity() {
		wxEncodingConverter *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxEncodingConverter");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
