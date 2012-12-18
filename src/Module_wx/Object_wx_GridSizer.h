//----------------------------------------------------------------------------
// wxGridSizer
// extracted from gridsizr.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GRIDSIZER_H__
#define __OBJECT_WX_GRIDSIZER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridSizer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridSizer);

//----------------------------------------------------------------------------
// Object declaration for wxGridSizer
//----------------------------------------------------------------------------
class Object_wx_GridSizer : public Object_wx_Sizer {
public:
	Gura_DeclareObjectAccessor(wx_GridSizer)
public:
	inline Object_wx_GridSizer(wxGridSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Sizer(Gura_UserClass(wx_GridSizer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridSizer(Class *pClass, wxGridSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Sizer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridSizer();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxGridSizer *GetEntity() {
		return dynamic_cast<wxGridSizer *>(_pEntity);
	}
	inline wxGridSizer *ReleaseEntity() {
		wxGridSizer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGridSizer");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
