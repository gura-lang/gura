//----------------------------------------------------------------------------
// wxRichTextImageBlock
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTIMAGEBLOCK_H__
#define __CLASS_WX_RICHTEXTIMAGEBLOCK_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextImageBlock
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextImageBlock);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextImageBlock
//----------------------------------------------------------------------------
class Object_wx_RichTextImageBlock : public Object {
protected:
	wxRichTextImageBlock *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RichTextImageBlock)
public:
	inline Object_wx_RichTextImageBlock(wxRichTextImageBlock *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_RichTextImageBlock)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RichTextImageBlock(Class *pClass, wxRichTextImageBlock *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RichTextImageBlock();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRichTextImageBlock *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxRichTextImageBlock *GetEntity() { return _pEntity; }
	inline wxRichTextImageBlock *ReleaseEntity() {
		wxRichTextImageBlock *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRichTextImageBlock");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
