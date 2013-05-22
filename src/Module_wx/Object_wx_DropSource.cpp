//----------------------------------------------------------------------------
// wxDropSource
// extracted from dropsrc.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(DoDragDrop);
Gura_DeclarePrivUserSymbol(GiveFeedback);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DropSource: public wxDropSource, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DropSource *_pObj;
public:
	//inline wx_DropSource(wxWindow* win, const wxIconOrCursor& iconCopy, const wxIconOrCursor& iconMove, const wxIconOrCursor& iconNone) : wxDropSource(win, iconCopy, iconMove, iconNone), _sig(NULL), _pObj(NULL) {}
	//inline wx_DropSource(wxDataObject& data, wxWindow* win, const wxIconOrCursor& iconCopy, const wxIconOrCursor& iconMove, const wxIconOrCursor& iconNone) : wxDropSource(data, win, iconCopy, iconMove, iconNone), _sig(NULL), _pObj(NULL) {}
	//virtual wxDragResult DoDragDrop(int flags);
	//virtual bool GiveFeedback(wxDragResult effect);
	~wx_DropSource();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DropSource *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DropSource::~wx_DropSource()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DropSource::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDropSource
//----------------------------------------------------------------------------
Gura_DeclareFunction(DropSource)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DropSource));
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "iconCopy", VTYPE_wx_IconOrCursor, OCCUR_ZeroOrOnce);
	DeclareArg(env, "iconMove", VTYPE_wx_IconOrCursor, OCCUR_ZeroOrOnce);
	DeclareArg(env, "iconNone", VTYPE_wx_IconOrCursor, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(DropSource)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxWindow *win = (wxWindow *)(NULL);
	if (args.IsValid(0)) win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxIconOrCursor *iconCopy = (wxIconOrCursor *)(&wxNullIconOrCursor);
	if (args.IsValid(1)) iconCopy = Object_wx_IconOrCursor::GetObject(args, 1)->GetEntity();
	wxIconOrCursor *iconMove = (wxIconOrCursor *)(&wxNullIconOrCursor);
	if (args.IsValid(2)) iconMove = Object_wx_IconOrCursor::GetObject(args, 2)->GetEntity();
	wxIconOrCursor *iconNone = (wxIconOrCursor *)(&wxNullIconOrCursor);
	if (args.IsValid(3)) iconNone = Object_wx_IconOrCursor::GetObject(args, 3)->GetEntity();
	wx_DropSource *pEntity = new wx_DropSource(win, *iconCopy, *iconMove, *iconNone);
	Object_wx_DropSource *pObj = Object_wx_DropSource::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DropSource(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(DropSource_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DropSource));
	DeclareArg(env, "data", VTYPE_wx_DataObject, OCCUR_Once);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "iconCopy", VTYPE_wx_IconOrCursor, OCCUR_ZeroOrOnce);
	DeclareArg(env, "iconMove", VTYPE_wx_IconOrCursor, OCCUR_ZeroOrOnce);
	DeclareArg(env, "iconNone", VTYPE_wx_IconOrCursor, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(DropSource_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxDataObject *data = Object_wx_DataObject::GetObject(args, 0)->GetEntity();
	wxWindow *win = (wxWindow *)(NULL);
	if (args.IsValid(1)) win = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxIconOrCursor *iconCopy = (wxIconOrCursor *)(&wxNullIconOrCursor);
	if (args.IsValid(2)) iconCopy = Object_wx_IconOrCursor::GetObject(args, 2)->GetEntity();
	wxIconOrCursor *iconMove = (wxIconOrCursor *)(&wxNullIconOrCursor);
	if (args.IsValid(3)) iconMove = Object_wx_IconOrCursor::GetObject(args, 3)->GetEntity();
	wxIconOrCursor *iconNone = (wxIconOrCursor *)(&wxNullIconOrCursor);
	if (args.IsValid(4)) iconNone = Object_wx_IconOrCursor::GetObject(args, 4)->GetEntity();
	wx_DropSource *pEntity = new wx_DropSource(*data, win, *iconCopy, *iconMove, *iconNone);
	Object_wx_DropSource *pObj = Object_wx_DropSource::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DropSource(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DropSource, SetData)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "data", VTYPE_wx_DataObject, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_DropSource, SetData)
{
#if 0
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataObject *data = Object_wx_DataObject::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetData(*data);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DropSource, DoDragDrop)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DropSource, DoDragDrop)
{
#if 0
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int flags = wxDrag_CopyOnly;
	if (args.IsValid(0)) flags = args.GetInt(0);
	wxDragResult rtn = pThis->GetEntity()->DoDragDrop(flags);
	return ReturnValue(env, sig, args, Value(new Object_wx_DragResult(new wxDragResult(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DropSource, GetDataObject)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DropSource, GetDataObject)
{
#if 0
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataObject *rtn = (wxDataObject *)pThis->GetEntity()->GetDataObject();
	return ReturnValue(env, sig, args, Value(new Object_wx_DataObject(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DropSource, GiveFeedback)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "effect", VTYPE_wx_DragResult, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DropSource, GiveFeedback)
{
#if 0
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDragResult *effect = Object_wx_DragResult::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->GiveFeedback(*effect);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DropSource, SetCursor)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "res", VTYPE_wx_DragResult, OCCUR_Once);
	DeclareArg(env, "cursor", VTYPE_wx_Cursor, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_DropSource, SetCursor)
{
#if 0
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDragResult *res = Object_wx_DragResult::GetObject(args, 0)->GetEntity();
	wxCursor *cursor = Object_wx_Cursor::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetCursor(*res, *cursor);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDropSource
//----------------------------------------------------------------------------
Object_wx_DropSource::~Object_wx_DropSource()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_DropSource::Clone() const
{
	return NULL;
}

String Object_wx_DropSource::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DropSource:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxDropSource
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DropSource)
{
	Gura_RealizeUserSymbol(DoDragDrop);
	Gura_RealizeUserSymbol(GiveFeedback);
	Gura_AssignFunction(DropSource);
	Gura_AssignFunction(DropSource_1);
	Gura_AssignMethod(wx_DropSource, SetData);
	Gura_AssignMethod(wx_DropSource, DoDragDrop);
	Gura_AssignMethod(wx_DropSource, GetDataObject);
	Gura_AssignMethod(wx_DropSource, GiveFeedback);
	Gura_AssignMethod(wx_DropSource, SetCursor);
}

Gura_ImplementDescendantCreator(wx_DropSource)
{
	return new Object_wx_DropSource((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
