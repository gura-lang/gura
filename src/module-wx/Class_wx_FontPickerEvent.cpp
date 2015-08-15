//----------------------------------------------------------------------------
// wxFontPickerEvent
// extracted from fontpicker.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FontPickerEvent: public wxFontPickerEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_FontPickerEvent *_pObj;
public:
	inline wx_FontPickerEvent(wxObject * generator, int id, const wxFont& font) : wxFontPickerEvent(generator, id, font), _pObj(nullptr) {}
	~wx_FontPickerEvent();
	inline void AssocWithGura(Object_wx_FontPickerEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FontPickerEvent::~wx_FontPickerEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FontPickerEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFontPickerEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(FontPickerEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FontPickerEvent));
	DeclareArg(env, "generator", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FontPickerEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxObject *generator = Object_wx_Object::GetObject(args, 0)->GetEntity();
	int id = args.GetInt(1);
	wxFont *font = Object_wx_Font::GetObject(args, 2)->GetEntity();
	wx_FontPickerEvent *pEntity = new wx_FontPickerEvent(generator, id, *font);
	Object_wx_FontPickerEvent *pObj = Object_wx_FontPickerEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_FontPickerEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_FontPickerEvent, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontPickerEvent, GetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontPickerEvent *pThis = Object_wx_FontPickerEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont rtn = pThis->GetEntity()->GetFont();
	return ReturnValue(env, args, Value(new Object_wx_Font(new wxFont(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_FontPickerEvent, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "f", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontPickerEvent, SetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontPickerEvent *pThis = Object_wx_FontPickerEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont *f = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetFont(*f);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxFontPickerEvent
//----------------------------------------------------------------------------
Object_wx_FontPickerEvent::~Object_wx_FontPickerEvent()
{
}

Object *Object_wx_FontPickerEvent::Clone() const
{
	return nullptr;
}

String Object_wx_FontPickerEvent::ToString(bool exprFlag)
{
	String rtn("<wx.FontPickerEvent:");
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
// Class implementation for wxFontPickerEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontPickerEvent)
{
	Gura_AssignFunction(FontPickerEvent);
	Gura_AssignMethod(wx_FontPickerEvent, GetFont);
	Gura_AssignMethod(wx_FontPickerEvent, SetFont);
}

Gura_ImplementDescendantCreator(wx_FontPickerEvent)
{
	return new Object_wx_FontPickerEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
