//----------------------------------------------------------------------------
// wxListbook
// extracted from listbook.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_LISTBOOK_H__
#define __OBJECT_WX_LISTBOOK_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxListbook
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Listbook);

//----------------------------------------------------------------------------
// Object declaration for wxListbook
//----------------------------------------------------------------------------
class Object_wx_Listbook : public Object_wx_BookCtrlBase {
public:
	Gura_DeclareObjectAccessor(wx_Listbook)
public:
	inline Object_wx_Listbook(wxListbook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(Gura_UserClass(wx_Listbook), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Listbook(Class *pClass, wxListbook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Listbook();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxListbook *GetEntity() {
		return dynamic_cast<wxListbook *>(_pEntity);
	}
	inline wxListbook *ReleaseEntity() {
		wxListbook *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxListbook");
		return true;
	}
};

}}

#endif
