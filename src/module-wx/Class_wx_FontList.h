//----------------------------------------------------------------------------
// wxFontList
// extracted from fontlist.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FONTLIST_H__
#define __CLASS_WX_FONTLIST_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFontList
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FontList);

//----------------------------------------------------------------------------
// Object declaration for wxFontList
//----------------------------------------------------------------------------
class Object_wx_FontList : public Object_wx_List {
public:
	Gura_DeclareObjectAccessor(wx_FontList)
public:
	inline Object_wx_FontList(wxFontList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_List(Gura_UserClass(wx_FontList), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FontList(Class *pClass, wxFontList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_List(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FontList();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFontList *GetEntity() {
		return dynamic_cast<wxFontList *>(_pEntity);
	}
	inline wxFontList *ReleaseEntity() {
		wxFontList *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFontList");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
