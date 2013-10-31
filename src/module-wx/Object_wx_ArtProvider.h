//----------------------------------------------------------------------------
// wxArtProvider
// extracted from artprov.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_ARTPROVIDER_H__
#define __OBJECT_WX_ARTPROVIDER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxArtProvider
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ArtProvider);

//----------------------------------------------------------------------------
// Object declaration for wxArtProvider
//----------------------------------------------------------------------------
class Object_wx_ArtProvider : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_ArtProvider)
public:
	inline Object_wx_ArtProvider(wxArtProvider *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_ArtProvider), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ArtProvider(Class *pClass, wxArtProvider *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ArtProvider();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxArtProvider *GetEntity() {
		return dynamic_cast<wxArtProvider *>(_pEntity);
	}
	inline wxArtProvider *ReleaseEntity() {
		wxArtProvider *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxArtProvider");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
