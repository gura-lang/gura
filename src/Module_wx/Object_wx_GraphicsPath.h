//----------------------------------------------------------------------------
// wxGraphicsPath
// extracted from graphicspath.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GRAPHICSPATH_H__
#define __OBJECT_WX_GRAPHICSPATH_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGraphicsPath
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GraphicsPath);

//----------------------------------------------------------------------------
// Object declaration for wxGraphicsPath
//----------------------------------------------------------------------------
class Object_wx_GraphicsPath : public Object_wx_GraphicsObject {
public:
	Gura_DeclareObjectAccessor(wx_GraphicsPath)
public:
	inline Object_wx_GraphicsPath(wxGraphicsPath *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GraphicsObject(Gura_UserClass(wx_GraphicsPath), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GraphicsPath(Class *pClass, wxGraphicsPath *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GraphicsObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GraphicsPath();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxGraphicsPath *GetEntity() {
		return dynamic_cast<wxGraphicsPath *>(_pEntity);
	}
	inline wxGraphicsPath *ReleaseEntity() {
		wxGraphicsPath *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGraphicsPath");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
