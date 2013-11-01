//----------------------------------------------------------------------------
// wxQuantize
// extracted from quantize.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_QUANTIZE_H__
#define __OBJECT_WX_QUANTIZE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxQuantize
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Quantize);

//----------------------------------------------------------------------------
// Object declaration for wxQuantize
//----------------------------------------------------------------------------
class Object_wx_Quantize : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Quantize)
public:
	inline Object_wx_Quantize(wxQuantize *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Quantize), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Quantize(Class *pClass, wxQuantize *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Quantize();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxQuantize *GetEntity() {
		return dynamic_cast<wxQuantize *>(_pEntity);
	}
	inline wxQuantize *ReleaseEntity() {
		wxQuantize *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxQuantize");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
