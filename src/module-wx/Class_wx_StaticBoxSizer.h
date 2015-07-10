//----------------------------------------------------------------------------
// wxStaticBoxSizer
// extracted from sbsizer.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STATICBOXSIZER_H__
#define __CLASS_WX_STATICBOXSIZER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStaticBoxSizer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StaticBoxSizer);

//----------------------------------------------------------------------------
// Object declaration for wxStaticBoxSizer
//----------------------------------------------------------------------------
class Object_wx_StaticBoxSizer : public Object_wx_BoxSizer {
public:
	Gura_DeclareObjectAccessor(wx_StaticBoxSizer)
public:
	inline Object_wx_StaticBoxSizer(wxStaticBoxSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BoxSizer(Gura_UserClass(wx_StaticBoxSizer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_StaticBoxSizer(Class *pClass, wxStaticBoxSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BoxSizer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_StaticBoxSizer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxStaticBoxSizer *GetEntity() {
		return dynamic_cast<wxStaticBoxSizer *>(_pEntity);
	}
	inline wxStaticBoxSizer *ReleaseEntity() {
		wxStaticBoxSizer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxStaticBoxSizer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
