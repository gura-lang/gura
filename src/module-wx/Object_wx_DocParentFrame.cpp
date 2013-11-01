//----------------------------------------------------------------------------
// wxDocParentFrame
// extracted from docprfrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DocParentFrame: public wxDocParentFrame, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DocParentFrame *_pObj;
public:
	inline wx_DocParentFrame() : wxDocParentFrame(), _sig(NULL), _pObj(NULL) {}
	inline wx_DocParentFrame(wxDocManager* manager, wxFrame * parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxDocParentFrame(manager, parent, id, title, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	~wx_DocParentFrame();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DocParentFrame *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DocParentFrame::~wx_DocParentFrame()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DocParentFrame::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDocParentFrame
//----------------------------------------------------------------------------
Gura_DeclareFunction(DocParentFrameEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DocParentFrame));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DocParentFrameEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_DocParentFrame *pEntity = new wx_DocParentFrame();
	Object_wx_DocParentFrame *pObj = Object_wx_DocParentFrame::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DocParentFrame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(DocParentFrame)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DocParentFrame));
	DeclareArg(env, "manager", VTYPE_wx_DocManager, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Frame, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DocParentFrame)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDocManager *manager = Object_wx_DocManager::GetObject(args, 0)->GetEntity();
	wxFrame *parent = Object_wx_Frame::GetObject(args, 1)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(2));
	wxString title = wxString::FromUTF8(args.GetString(3));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(4)) pos = Object_wx_Point::GetObject(args, 4)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(5)) size = Object_wx_Size::GetObject(args, 5)->GetEntity();
	long style = wxDEFAULT_FRAME_STYLE;
	if (args.IsValid(6)) style = args.GetLong(6);
	wxString name = wxT("frame");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	wx_DocParentFrame *pEntity = new wx_DocParentFrame(manager, parent, id, title, *pos, *size, style, name);
	Object_wx_DocParentFrame *pObj = Object_wx_DocParentFrame::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DocParentFrame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_DocParentFrame, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "manager", VTYPE_wx_DocManager, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Frame, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocParentFrame, Create)
{
	Object_wx_DocParentFrame *pThis = Object_wx_DocParentFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocManager *manager = Object_wx_DocManager::GetObject(args, 0)->GetEntity();
	wxFrame *parent = Object_wx_Frame::GetObject(args, 1)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(2));
	wxString title = wxString::FromUTF8(args.GetString(3));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(4)) pos = Object_wx_Point::GetObject(args, 4)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(5)) size = Object_wx_Size::GetObject(args, 5)->GetEntity();
	long style = wxDEFAULT_FRAME_STYLE;
	if (args.IsValid(6)) style = args.GetLong(6);
	wxString name = wxT("frame");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	bool rtn = pThis->GetEntity()->Create(manager, parent, id, title, *pos, *size, style, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DocParentFrame, GetDocumentManager)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocParentFrame, GetDocumentManager)
{
	Object_wx_DocParentFrame *pThis = Object_wx_DocParentFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocManager *rtn = (wxDocManager *)pThis->GetEntity()->GetDocumentManager();
	return ReturnValue(env, sig, args, Value(new Object_wx_DocManager(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_DocParentFrame, OnCloseWindow)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CloseEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocParentFrame, OnCloseWindow)
{
	Object_wx_DocParentFrame *pThis = Object_wx_DocParentFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCloseEvent *event = Object_wx_CloseEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnCloseWindow(*event);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDocParentFrame
//----------------------------------------------------------------------------
Object_wx_DocParentFrame::~Object_wx_DocParentFrame()
{
}

Object *Object_wx_DocParentFrame::Clone() const
{
	return NULL;
}

String Object_wx_DocParentFrame::ToString(bool exprFlag)
{
	String rtn("<wx.DocParentFrame:");
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
// Class implementation for wxDocParentFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DocParentFrame)
{
	Gura_AssignFunction(DocParentFrameEmpty);
	Gura_AssignFunction(DocParentFrame);
	Gura_AssignMethod(wx_DocParentFrame, Create);
	Gura_AssignMethod(wx_DocParentFrame, GetDocumentManager);
	Gura_AssignMethod(wx_DocParentFrame, OnCloseWindow);
}

Gura_ImplementDescendantCreator(wx_DocParentFrame)
{
	return new Object_wx_DocParentFrame((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
