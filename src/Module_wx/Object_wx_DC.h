//----------------------------------------------------------------------------
// wxDC
// extracted from dc.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DC_H__
#define __OBJECT_WX_DC_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDC
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DC);

//----------------------------------------------------------------------------
// Object declaration for wxDC
//----------------------------------------------------------------------------
class Object_wx_DC : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_DC)
public:
	inline Object_wx_DC(wxDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_DC), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DC(Class *pClass, wxDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DC();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDC *GetEntity() {
		return dynamic_cast<wxDC *>(_pEntity);
	}
	inline wxDC *ReleaseEntity() {
		wxDC *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDC");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
