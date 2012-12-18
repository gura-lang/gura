//----------------------------------------------------------------------------
// wxBrushList
// extracted from brush.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_BRUSHLIST_H__
#define __OBJECT_WX_BRUSHLIST_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBrushList
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_BrushList);

//----------------------------------------------------------------------------
// Object declaration for wxBrushList
//----------------------------------------------------------------------------
class Object_wx_BrushList : public Object_wx_List {
public:
	Gura_DeclareObjectAccessor(wx_BrushList)
public:
	inline Object_wx_BrushList(wxBrushList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_List(Gura_UserClass(wx_BrushList), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_BrushList(Class *pClass, wxBrushList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_List(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_BrushList();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxBrushList *GetEntity() {
		return dynamic_cast<wxBrushList *>(_pEntity);
	}
	inline wxBrushList *ReleaseEntity() {
		wxBrushList *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxBrushList");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
