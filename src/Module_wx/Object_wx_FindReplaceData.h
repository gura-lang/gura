//----------------------------------------------------------------------------
// wxFindReplaceData
// extracted from fdrepdlg.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_FINDREPLACEDATA_H__
#define __OBJECT_WX_FINDREPLACEDATA_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFindReplaceData
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FindReplaceData);

//----------------------------------------------------------------------------
// Object declaration for wxFindReplaceData
//----------------------------------------------------------------------------
class Object_wx_FindReplaceData : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_FindReplaceData)
public:
	inline Object_wx_FindReplaceData(wxFindReplaceData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_FindReplaceData), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FindReplaceData(Class *pClass, wxFindReplaceData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FindReplaceData();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxFindReplaceData *GetEntity() {
		return dynamic_cast<wxFindReplaceData *>(_pEntity);
	}
	inline wxFindReplaceData *ReleaseEntity() {
		wxFindReplaceData *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFindReplaceData");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
