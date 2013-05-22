//----------------------------------------------------------------------------
// wxListView
// extracted from listview.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_LISTVIEW_H__
#define __OBJECT_WX_LISTVIEW_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxListView
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ListView);

//----------------------------------------------------------------------------
// Object declaration for wxListView
//----------------------------------------------------------------------------
class Object_wx_ListView : public Object_wx_ListCtrl {
public:
	Gura_DeclareObjectAccessor(wx_ListView)
public:
	inline Object_wx_ListView(wxListView *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ListCtrl(Gura_UserClass(wx_ListView), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ListView(Class *pClass, wxListView *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ListCtrl(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ListView();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxListView *GetEntity() {
		return dynamic_cast<wxListView *>(_pEntity);
	}
	inline wxListView *ReleaseEntity() {
		wxListView *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxListView");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
