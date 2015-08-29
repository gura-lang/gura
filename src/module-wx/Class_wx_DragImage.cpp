//----------------------------------------------------------------------------
// wxDragImage
// extracted from dragimag.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(DoDrawImage);
Gura_DeclarePrivUserSymbol(GetImageRect);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DragImage: public wxDragImage, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DragImage *_pObj;
public:
	inline wx_DragImage() : wxDragImage(), _pObj(nullptr) {}
	//inline wx_DragImage(const wxBitmap& image, const wxCursor& cursor, const wxPoint& cursorHotspot) : wxDragImage(image, cursor, cursorHotspot), _pObj(nullptr) {}
	//inline wx_DragImage(const wxIcon& image, const wxCursor& cursor, const wxPoint& cursorHotspot) : wxDragImage(image, cursor, cursorHotspot), _pObj(nullptr) {}
	//inline wx_DragImage(const wxString& text, const wxCursor& cursor, const wxPoint& cursorHotspot) : wxDragImage(text, cursor, cursorHotspot), _pObj(nullptr) {}
	//inline wx_DragImage(const wxTreeCtrl& treeCtrl, wxTreeItemId& id) : wxDragImage(treeCtrl, id), _pObj(nullptr) {}
	//inline wx_DragImage(const wxListCtrl& treeCtrl, long id) : wxDragImage(treeCtrl, id), _pObj(nullptr) {}
	//inline wx_DragImage(const wxCursor& cursor, const wxPoint& cursorHotspot) : wxDragImage(cursor, cursorHotspot), _pObj(nullptr) {}
	//virtual bool DoDrawImage(wxDC& dc, const wxPoint& pos);
	//virtual wxRect GetImageRect(const wxPoint& pos);
	~wx_DragImage();
	inline void AssocWithGura(Object_wx_DragImage *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DragImage::~wx_DragImage()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DragImage::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDragImage
//----------------------------------------------------------------------------
Gura_DeclareFunction(DragImageEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DragImage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DragImageEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_DragImage *pEntity = new wx_DragImage();
	Object_wx_DragImage *pObj = Object_wx_DragImage::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_DragImage(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

#if 0
Gura_DeclareFunction(DragImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DragImage));
	DeclareArg(env, "image", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "cursor", VTYPE_wx_Cursor, OCCUR_ZeroOrOnce);
	DeclareArg(env, "cursorHotspot", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DragImage)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxBitmap *image = Object_wx_Bitmap::GetObject(arg, 0)->GetEntity();
	wxCursor *cursor = (wxCursor *)(&wxNullCursor);
	if (arg.IsValid(1)) cursor = Object_wx_Cursor::GetObject(arg, 1)->GetEntity();
	wxPoint cursorHotspot = wxPoint(0, 0);
	if (arg.IsValid(2)) cursorHotspot = *Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wx_DragImage *pEntity = new wx_DragImage(*image, *cursor, cursorHotspot);
	Object_wx_DragImage *pObj = Object_wx_DragImage::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_DragImage(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(DragImage_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DragImage));
	DeclareArg(env, "image", VTYPE_wx_Icon, OCCUR_Once);
	DeclareArg(env, "cursor", VTYPE_wx_Cursor, OCCUR_ZeroOrOnce);
	DeclareArg(env, "cursorHotspot", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DragImage_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxIcon *image = Object_wx_Icon::GetObject(arg, 0)->GetEntity();
	wxCursor *cursor = (wxCursor *)(&wxNullCursor);
	if (arg.IsValid(1)) cursor = Object_wx_Cursor::GetObject(arg, 1)->GetEntity();
	wxPoint cursorHotspot = wxPoint(0, 0);
	if (arg.IsValid(2)) cursorHotspot = *Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wx_DragImage *pEntity = new wx_DragImage(*image, *cursor, cursorHotspot);
	Object_wx_DragImage *pObj = Object_wx_DragImage::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_DragImage(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(DragImage_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DragImage));
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "cursor", VTYPE_wx_Cursor, OCCUR_ZeroOrOnce);
	DeclareArg(env, "cursorHotspot", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DragImage_2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(arg.GetString(0));
	wxCursor *cursor = (wxCursor *)(&wxNullCursor);
	if (arg.IsValid(1)) cursor = Object_wx_Cursor::GetObject(arg, 1)->GetEntity();
	wxPoint cursorHotspot = wxPoint(0, 0);
	if (arg.IsValid(2)) cursorHotspot = *Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wx_DragImage *pEntity = new wx_DragImage(text, *cursor, cursorHotspot);
	Object_wx_DragImage *pObj = Object_wx_DragImage::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_DragImage(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(DragImage_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DragImage));
	DeclareArg(env, "treeCtrl", VTYPE_wx_TreeCtrl, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DragImage_3)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxTreeCtrl *treeCtrl = Object_wx_TreeCtrl::GetObject(arg, 0)->GetEntity();
	wxTreeItemId *id = Object_wx_TreeItemId::GetObject(arg, 1)->GetEntity();
	wx_DragImage *pEntity = new wx_DragImage(*treeCtrl, *id);
	Object_wx_DragImage *pObj = Object_wx_DragImage::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_DragImage(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(DragImage_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DragImage));
	DeclareArg(env, "treeCtrl", VTYPE_wx_ListCtrl, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DragImage_4)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxListCtrl *treeCtrl = Object_wx_ListCtrl::GetObject(arg, 0)->GetEntity();
	long id = arg.GetLong(1);
	wx_DragImage *pEntity = new wx_DragImage(*treeCtrl, id);
	Object_wx_DragImage *pObj = Object_wx_DragImage::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_DragImage(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(DragImage_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DragImage));
	DeclareArg(env, "cursor", VTYPE_wx_Cursor, OCCUR_ZeroOrOnce);
	DeclareArg(env, "cursorHotspot", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(DragImage_5)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxCursor *cursor = (wxCursor *)(&wxNullCursor);
	if (arg.IsValid(0)) cursor = Object_wx_Cursor::GetObject(arg, 0)->GetEntity();
	wxPoint *cursorHotspot = (wxPoint *)(&wxPoint(0, 0));
	if (arg.IsValid(1)) cursorHotspot = Object_wx_Point::GetObject(arg, 1)->GetEntity();
	wx_DragImage *pEntity = new wx_DragImage(*cursor, *cursorHotspot);
	Object_wx_DragImage *pObj = Object_wx_DragImage::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_DragImage(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}
#endif

Gura_DeclareMethod(wx_DragImage, BeginDrag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "hotspot", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "fullScreen", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DragImage, BeginDrag)
{
	Signal &sig = env.GetSignal();
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *hotspot = Object_wx_Point::GetObject(arg, 0)->GetEntity();
	wxWindow *window = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	bool fullScreen = false;
	if (arg.IsValid(2)) fullScreen = arg.GetBoolean(2);
	wxRect *rect = (wxRect *)(nullptr);
	if (arg.IsValid(3)) rect = Object_wx_Rect::GetObject(arg, 3)->GetEntity();
	bool rtn = pThis->GetEntity()->BeginDrag(*hotspot, window, fullScreen, rect);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DragImage, BeginDrag_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "hotspot", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "boundingWindow", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DragImage, BeginDrag_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *hotspot = Object_wx_Point::GetObject(arg, 0)->GetEntity();
	wxWindow *window = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	wxWindow *boundingWindow = Object_wx_Window::GetObject(arg, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->BeginDrag(*hotspot, window, boundingWindow);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DragImage, DoDrawImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DragImage, DoDrawImage)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(arg, 0)->GetEntity();
	wxPoint *pos = Object_wx_Point::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->DoDrawImage(*dc, *pos);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DragImage, EndDrag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DragImage, EndDrag)
{
	Signal &sig = env.GetSignal();
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->EndDrag();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DragImage, GetImageRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DragImage, GetImageRect)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pos = Object_wx_Point::GetObject(arg, 0)->GetEntity();
	wxRect rtn = pThis->GetEntity()->GetImageRect(*pos);
	return ReturnValue(env, arg, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DragImage, Hide)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DragImage, Hide)
{
	Signal &sig = env.GetSignal();
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Hide();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DragImage, Move)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DragImage, Move)
{
	Signal &sig = env.GetSignal();
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pt = Object_wx_Point::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Move(*pt);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DragImage, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DragImage, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Show();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DragImage, UpdateBackingFromWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "windowDC", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "destDC", VTYPE_wx_MemoryDC, OCCUR_Once);
	DeclareArg(env, "sourceRect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "destRect", VTYPE_wx_Rect, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DragImage, UpdateBackingFromWindow)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DragImage *pThis = Object_wx_DragImage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *windowDC = Object_wx_DC::GetObject(arg, 0)->GetEntity();
	wxMemoryDC *destDC = Object_wx_MemoryDC::GetObject(arg, 1)->GetEntity();
	wxRect *sourceRect = Object_wx_Rect::GetObject(arg, 2)->GetEntity();
	wxRect *destRect = Object_wx_Rect::GetObject(arg, 3)->GetEntity();
	bool rtn = pThis->GetEntity()->UpdateBackingFromWindow(*windowDC, *destDC, *sourceRect, *destRect);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxDragImage
//----------------------------------------------------------------------------
Object_wx_DragImage::~Object_wx_DragImage()
{
}

Object *Object_wx_DragImage::Clone() const
{
	return nullptr;
}

String Object_wx_DragImage::ToString(bool exprFlag)
{
	String rtn("<wx.DragImage:");
	if (GetEntity() == nullptr) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxDragImage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DragImage)
{
	Gura_RealizeUserSymbol(DoDrawImage);
	Gura_RealizeUserSymbol(GetImageRect);
	Gura_AssignFunction(DragImageEmpty);
	//Gura_AssignFunction(DragImage);
	//Gura_AssignFunction(DragImage_1);
	//Gura_AssignFunction(DragImage_2);
	//Gura_AssignFunction(DragImage_3);
	//Gura_AssignFunction(DragImage_4);
	//Gura_AssignFunction(DragImage_5);
	Gura_AssignMethod(wx_DragImage, BeginDrag);
	Gura_AssignMethod(wx_DragImage, BeginDrag_1);
	Gura_AssignMethod(wx_DragImage, DoDrawImage);
	Gura_AssignMethod(wx_DragImage, EndDrag);
	Gura_AssignMethod(wx_DragImage, GetImageRect);
	Gura_AssignMethod(wx_DragImage, Hide);
	Gura_AssignMethod(wx_DragImage, Move);
	Gura_AssignMethod(wx_DragImage, Show);
	Gura_AssignMethod(wx_DragImage, UpdateBackingFromWindow);
}

Gura_ImplementDescendantCreator(wx_DragImage)
{
	return new Object_wx_DragImage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
