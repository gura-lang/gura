//----------------------------------------------------------------------------
// wxFontData
// extracted from fontdlg.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_FONTDATA_H__
#define __OBJECT_WX_FONTDATA_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxFontData *GetEntity() {
		return dynamic_cast<wxFontData *>(_pEntity);
	}
	inline wxFontData *ReleaseEntity() {
		wxFontData *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFontData");
		return true;
	}
};

}}

#endif
