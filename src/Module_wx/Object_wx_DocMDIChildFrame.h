//----------------------------------------------------------------------------
// wxDocMDIChildFrame
// extracted from docmdich.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DOCMDICHILDFRAME_H__
#define __OBJECT_WX_DOCMDICHILDFRAME_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDocMDIChildFrame
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DocMDIChildFrame);

//----------------------------------------------------------------------------
// Object declaration for wxDocMDIChildFrame
//----------------------------------------------------------------------------
class Object_wx_DocMDIChildFrame : public Object_wx_MDIChildFrame {
public:
	Gura_DeclareObjectAccessor(wx_DocMDIChildFrame)
public:
	inline Object_wx_DocMDIChildFrame(wxDocMDIChildFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MDIChildFrame(Gura_UserClass(wx_DocMDIChildFrame), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DocMDIChildFrame(Class *pClass, wxDocMDIChildFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_MDIChildFrame(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DocMDIChildFrame();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDocMDIChildFrame *GetEntity() {
		return dynamic_cast<wxDocMDIChildFrame *>(_pEntity);
	}
	inline wxDocMDIChildFrame *ReleaseEntity() {
		wxDocMDIChildFrame *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDocMDIChildFrame");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
