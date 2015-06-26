//----------------------------------------------------------------------------
// wxColourData
// extracted from colour.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_COLOURDATA_H__
#define __CLASS_WX_COLOURDATA_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxColourData
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ColourData);

//----------------------------------------------------------------------------
// Object declaration for wxColourData
//----------------------------------------------------------------------------
class Object_wx_ColourData : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_ColourData)
public:
	inline Object_wx_ColourData(wxColourData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_ColourData), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ColourData(Class *pClass, wxColourData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ColourData();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxColourData *GetEntity() {
		return dynamic_cast<wxColourData *>(_pEntity);
	}
	inline wxColourData *ReleaseEntity() {
		wxColourData *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxColourData");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
