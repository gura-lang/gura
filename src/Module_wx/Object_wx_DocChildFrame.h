//----------------------------------------------------------------------------
// wxDocChildFrame
// extracted from docchfrm.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DOCCHILDFRAME_H__
#define __OBJECT_WX_DOCCHILDFRAME_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDocChildFrame
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DocChildFrame);

//----------------------------------------------------------------------------
// Object declaration for wxDocChildFrame
//----------------------------------------------------------------------------
class Object_wx_DocChildFrame : public Object_wx_Frame {
public:
	Gura_DeclareObjectAccessor(wx_DocChildFrame)
public:
	inline Object_wx_DocChildFrame(wxDocChildFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(Gura_UserClass(wx_DocChildFrame), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DocChildFrame(Class *pClass, wxDocChildFrame *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DocChildFrame();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDocChildFrame *GetEntity() {
		return dynamic_cast<wxDocChildFrame *>(_pEntity);
	}
	inline wxDocChildFrame *ReleaseEntity() {
		wxDocChildFrame *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDocChildFrame");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
