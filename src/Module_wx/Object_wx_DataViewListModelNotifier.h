//----------------------------------------------------------------------------
// wxDataViewListModelNotifier
// extracted from dataviewlistmodelnotifier.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DATAVIEWLISTMODELNOTIFIER_H__
#define __OBJECT_WX_DATAVIEWLISTMODELNOTIFIER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewListModelNotifier
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewListModelNotifier);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewListModelNotifier
//----------------------------------------------------------------------------
class Object_wx_DataViewListModelNotifier : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_DataViewListModelNotifier)
public:
	inline Object_wx_DataViewListModelNotifier(wxDataViewListModelNotifier *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_DataViewListModelNotifier), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewListModelNotifier(Class *pClass, wxDataViewListModelNotifier *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewListModelNotifier();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDataViewListModelNotifier *GetEntity() {
		return dynamic_cast<wxDataViewListModelNotifier *>(_pEntity);
	}
	inline wxDataViewListModelNotifier *ReleaseEntity() {
		wxDataViewListModelNotifier *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDataViewListModelNotifier");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
