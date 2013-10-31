//----------------------------------------------------------------------------
// wxZlibInputStream
// hand-coded
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_ZLIBINPUTSTREAM_H__
#define __OBJECT_WX_ZLIBINPUTSTREAM_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxZlibInputStream
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ZlibInputStream);

//----------------------------------------------------------------------------
// Object declaration for wxZlibInputStream
//----------------------------------------------------------------------------
class Object_wx_ZlibInputStream : public Object_wx_FilterInputStream {
public:
	Gura_DeclareObjectAccessor(wx_ZlibInputStream)
public:
	inline Object_wx_ZlibInputStream(wxZlibInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FilterInputStream(Gura_UserClass(wx_ZlibInputStream), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ZlibInputStream(Class *pClass, wxZlibInputStream *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_FilterInputStream(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ZlibInputStream();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxZlibInputStream *GetEntity() {
		return dynamic_cast<wxZlibInputStream *>(_pEntity);
	}
	inline wxZlibInputStream *ReleaseEntity() {
		wxZlibInputStream *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxZlibInputStream");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
