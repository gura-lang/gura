//----------------------------------------------------------------------------
// wxZlibOutputStream
// hand-coded
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ZLIBOUTPUTSTREAM_H__
#define __CLASS_WX_ZLIBOUTPUTSTREAM_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxZlibOutputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ZlibOutputStream);

//----------------------------------------------------------------------------
// Object declaration for wxZlibOutputStream
//----------------------------------------------------------------------------
class Object_wx_ZlibOutputStream : public Object_wx_FilterOutputStream {
public:
	Gura_DeclareObjectAccessor(wx_ZlibOutputStream)
public:
	inline Object_wx_ZlibOutputStream(wxZlibOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FilterOutputStream(Gura_UserClass(wx_ZlibOutputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ZlibOutputStream(Class *pClass, wxZlibOutputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FilterOutputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ZlibOutputStream();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxZlibOutputStream *GetEntity() {
		return dynamic_cast<wxZlibOutputStream *>(_pEntity);
	}
	inline wxZlibOutputStream *ReleaseEntity() {
		wxZlibOutputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxZlibOutputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
