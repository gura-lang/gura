//----------------------------------------------------------------------------
// wxStyledTextEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StyledTextEvent: public wxStyledTextEvent, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_StyledTextEvent *_pObj;
public:
	inline wx_StyledTextEvent(WXTYPE commandType, int id) : wxStyledTextEvent(commandType, id), _pSig(nullptr), _pObj(nullptr) {}
	~wx_StyledTextEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_StyledTextEvent *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StyledTextEvent::~wx_StyledTextEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_StyledTextEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Implementation of functions
//----------------------------------------------------------------------------
Gura_DeclareFunction(StyledTextEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StyledTextEvent));
	DeclareArg(env, "commandType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StyledTextEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	WXTYPE commandType = 0;
	if (args.IsValid(0)) commandType = static_cast<WXTYPE>(args.GetInt(0));
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	wx_StyledTextEvent *pEntity = new wx_StyledTextEvent(commandType, id);
	Object_wx_StyledTextEvent *pObj = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_StyledTextEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Implementation of methods
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_StyledTextEvent, SetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pos",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetPosition)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pos = args.GetInt(0);
	pThis->GetEntity()->SetPosition(pos);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "k",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetKey)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int k = args.GetInt(0);
	pThis->GetEntity()->SetKey(k);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetModifiers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "m",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetModifiers)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int m = args.GetInt(0);
	pThis->GetEntity()->SetModifiers(m);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetModificationType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "t",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetModificationType)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int t = args.GetInt(0);
	pThis->GetEntity()->SetModificationType(t);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "t",	VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetText)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString t = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetText(t);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "len",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetLength)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int len = args.GetInt(0);
	pThis->GetEntity()->SetLength(len);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetLinesAdded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "num",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetLinesAdded)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int num = args.GetInt(0);
	pThis->GetEntity()->SetLinesAdded(num);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "val",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetLine)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int val = args.GetInt(0);
	pThis->GetEntity()->SetLine(val);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetFoldLevelNow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "val",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetFoldLevelNow)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int val = args.GetInt(0);
	pThis->GetEntity()->SetFoldLevelNow(val);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetFoldLevelPrev)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "val",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetFoldLevelPrev)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int val = args.GetInt(0);
	pThis->GetEntity()->SetFoldLevelPrev(val);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "val",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetMargin)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int val = args.GetInt(0);
	pThis->GetEntity()->SetMargin(val);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "val",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetMessage)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int val = args.GetInt(0);
	pThis->GetEntity()->SetMessage(val);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetWParam)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "val",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetWParam)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int val = args.GetInt(0);
	pThis->GetEntity()->SetWParam(val);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetLParam)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "val",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetLParam)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int val = args.GetInt(0);
	pThis->GetEntity()->SetLParam(val);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetListType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "val",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetListType)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int val = args.GetInt(0);
	pThis->GetEntity()->SetListType(val);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "val",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetX)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int val = args.GetInt(0);
	pThis->GetEntity()->SetX(val);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "val",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetY)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int val = args.GetInt(0);
	pThis->GetEntity()->SetY(val);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetToken)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "val",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetToken)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int val = args.GetInt(0);
	pThis->GetEntity()->SetToken(val);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetAnnotationLinesAdded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "val",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetAnnotationLinesAdded)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int val = args.GetInt(0);
	pThis->GetEntity()->SetAnnotationLinesAdded(val);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetUpdated)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "val",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetUpdated)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int val = args.GetInt(0);
	pThis->GetEntity()->SetUpdated(val);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetDragText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "val",	VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetDragText)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString val = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetDragText(val);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetDragFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flags",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetDragFlags)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int flags = args.GetInt(0);
	pThis->GetEntity()->SetDragFlags(flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, SetDragResult)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "val",	VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextEvent, SetDragResult)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDragResult val = static_cast<wxDragResult>(args.GetInt(0));
	pThis->GetEntity()->SetDragResult(val);
	return Value::Null;
}

Gura_DeclareMethod(wx_StyledTextEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetPosition)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetKey)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetKey();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetModifiers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetModifiers)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetModifiers();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetModificationType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetModificationType)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetModificationType();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetText)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetText();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetLength)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetLength();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetLinesAdded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetLinesAdded)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetLinesAdded();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetLine)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetLine();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetFoldLevelNow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetFoldLevelNow)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetFoldLevelNow();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetFoldLevelPrev)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetFoldLevelPrev)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetFoldLevelPrev();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetMargin)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMargin();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetMessage)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMessage();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetWParam)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetWParam)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetWParam();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetLParam)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetLParam)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetLParam();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetListType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetListType)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetListType();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetX)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetX();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetY)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetY();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetToken)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetToken)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetToken();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetAnnotationsLinesAdded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetAnnotationsLinesAdded)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetAnnotationsLinesAdded();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetUpdated)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetUpdated)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetUpdated();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetDragText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetDragText)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetDragText();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetDragFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetDragFlags)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetDragFlags();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetDragResult)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetDragResult)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDragResult rtn = pThis->GetEntity()->GetDragResult();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetShift)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetShift)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetShift();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetControl)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetControl();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetAlt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetAlt)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetAlt();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object_wx_StyledTextEvent
//----------------------------------------------------------------------------
Object_wx_StyledTextEvent::~Object_wx_StyledTextEvent()
{
}

Object *Object_wx_StyledTextEvent::Clone() const
{
	return nullptr;
}

String Object_wx_StyledTextEvent::ToString(bool exprFlag)
{
	String rtn("<wx.StyledTextEvent:");
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
// Class implementation for wxStyledTextEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StyledTextEvent)
{
	Gura_AssignFunction(StyledTextEvent);
	Gura_AssignMethod(wx_StyledTextEvent, SetPosition);
	Gura_AssignMethod(wx_StyledTextEvent, SetKey);
	Gura_AssignMethod(wx_StyledTextEvent, SetModifiers);
	Gura_AssignMethod(wx_StyledTextEvent, SetModificationType);
	Gura_AssignMethod(wx_StyledTextEvent, SetText);
	Gura_AssignMethod(wx_StyledTextEvent, SetLength);
	Gura_AssignMethod(wx_StyledTextEvent, SetLinesAdded);
	Gura_AssignMethod(wx_StyledTextEvent, SetLine);
	Gura_AssignMethod(wx_StyledTextEvent, SetFoldLevelNow);
	Gura_AssignMethod(wx_StyledTextEvent, SetFoldLevelPrev);
	Gura_AssignMethod(wx_StyledTextEvent, SetMargin);
	Gura_AssignMethod(wx_StyledTextEvent, SetMessage);
	Gura_AssignMethod(wx_StyledTextEvent, SetWParam);
	Gura_AssignMethod(wx_StyledTextEvent, SetLParam);
	Gura_AssignMethod(wx_StyledTextEvent, SetListType);
	Gura_AssignMethod(wx_StyledTextEvent, SetX);
	Gura_AssignMethod(wx_StyledTextEvent, SetY);
	Gura_AssignMethod(wx_StyledTextEvent, SetToken);
	Gura_AssignMethod(wx_StyledTextEvent, SetAnnotationLinesAdded);
	Gura_AssignMethod(wx_StyledTextEvent, SetUpdated);
	Gura_AssignMethod(wx_StyledTextEvent, SetDragText);
	Gura_AssignMethod(wx_StyledTextEvent, SetDragFlags);
	Gura_AssignMethod(wx_StyledTextEvent, SetDragResult);
	Gura_AssignMethod(wx_StyledTextEvent, GetPosition);
	Gura_AssignMethod(wx_StyledTextEvent, GetKey);
	Gura_AssignMethod(wx_StyledTextEvent, GetModifiers);
	Gura_AssignMethod(wx_StyledTextEvent, GetModificationType);
	Gura_AssignMethod(wx_StyledTextEvent, GetText);
	Gura_AssignMethod(wx_StyledTextEvent, GetLength);
	Gura_AssignMethod(wx_StyledTextEvent, GetLinesAdded);
	Gura_AssignMethod(wx_StyledTextEvent, GetLine);
	Gura_AssignMethod(wx_StyledTextEvent, GetFoldLevelNow);
	Gura_AssignMethod(wx_StyledTextEvent, GetFoldLevelPrev);
	Gura_AssignMethod(wx_StyledTextEvent, GetMargin);
	Gura_AssignMethod(wx_StyledTextEvent, GetMessage);
	Gura_AssignMethod(wx_StyledTextEvent, GetWParam);
	Gura_AssignMethod(wx_StyledTextEvent, GetLParam);
	Gura_AssignMethod(wx_StyledTextEvent, GetListType);
	Gura_AssignMethod(wx_StyledTextEvent, GetX);
	Gura_AssignMethod(wx_StyledTextEvent, GetY);
	Gura_AssignMethod(wx_StyledTextEvent, GetToken);
	Gura_AssignMethod(wx_StyledTextEvent, GetAnnotationsLinesAdded);
	Gura_AssignMethod(wx_StyledTextEvent, GetUpdated);
	Gura_AssignMethod(wx_StyledTextEvent, GetDragText);
	Gura_AssignMethod(wx_StyledTextEvent, GetDragFlags);
	Gura_AssignMethod(wx_StyledTextEvent, GetDragResult);
	Gura_AssignMethod(wx_StyledTextEvent, GetShift);
	Gura_AssignMethod(wx_StyledTextEvent, GetControl);
	Gura_AssignMethod(wx_StyledTextEvent, GetAlt);
}

Gura_ImplementDescendantCreator(wx_StyledTextEvent)
{
	return new Object_wx_StyledTextEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
