//----------------------------------------------------------------------------
// wxXmlResourceHandler
// extracted from xmlresh.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_XMLRESOURCEHANDLER_H__
#define __OBJECT_WX_XMLRESOURCEHANDLER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxXmlResourceHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_XmlResourceHandler);

//----------------------------------------------------------------------------
// Object declaration for wxXmlResourceHandler
//----------------------------------------------------------------------------
class Object_wx_XmlResourceHandler : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_XmlResourceHandler)
public:
	inline Object_wx_XmlResourceHandler(wxXmlResourceHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_XmlResourceHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_XmlResourceHandler(Class *pClass, wxXmlResourceHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_XmlResourceHandler();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxXmlResourceHandler *GetEntity() {
		return dynamic_cast<wxXmlResourceHandler *>(_pEntity);
	}
	inline wxXmlResourceHandler *ReleaseEntity() {
		wxXmlResourceHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxXmlResourceHandler");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
