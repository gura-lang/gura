//----------------------------------------------------------------------------
// wxStaticBitmap
// extracted from statbmp.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_STATICBITMAP_H__
#define __OBJECT_WX_STATICBITMAP_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStaticBitmap
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StaticBitmap);

//----------------------------------------------------------------------------
// Object declaration for wxStaticBitmap
//----------------------------------------------------------------------------
class Object_wx_StaticBitmap : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_StaticBitmap)
public:
	inline Object_wx_StaticBitmap(wxStaticBitmap *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_StaticBitmap), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_StaticBitmap(Class *pClass, wxStaticBitmap *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_StaticBitmap();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxStaticBitmap *GetEntity() {
		return dynamic_cast<wxStaticBitmap *>(_pEntity);
	}
	inline wxStaticBitmap *ReleaseEntity() {
		wxStaticBitmap *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxStaticBitmap");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
