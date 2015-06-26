//----------------------------------------------------------------------------
// wxBitmapComboBox
// extracted from bitmapcombobox.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_BitmapComboBox: public wxBitmapComboBox, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_BitmapComboBox *_pObj;
public:
	inline wx_BitmapComboBox() : wxBitmapComboBox(), _sig(nullptr), _pObj(nullptr) {}
	//inline wx_BitmapComboBox(wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos, const wxSize& size, int n, const wxString choices[], long style, const wxValidator& validator, const wxString& name) : wxBitmapComboBox(parent, id, value, pos, size, n, choices[], style, validator, name), _sig(nullptr), _pObj(nullptr) {}
	inline wx_BitmapComboBox(wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos, const wxSize& size, const wxArrayString& choices, long style, const wxValidator& validator, const wxString& name) : wxBitmapComboBox(parent, id, value, pos, size, choices, style, validator, name), _sig(nullptr), _pObj(nullptr) {}
	~wx_BitmapComboBox();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_BitmapComboBox *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BitmapComboBox::~wx_BitmapComboBox()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_BitmapComboBox::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBitmapComboBox
//----------------------------------------------------------------------------
Gura_DeclareFunction(BitmapComboBoxEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_BitmapComboBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BitmapComboBoxEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_BitmapComboBox *pEntity = new wx_BitmapComboBox();
	Object_wx_BitmapComboBox *pObj = Object_wx_BitmapComboBox::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_BitmapComboBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(BitmapComboBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_BitmapComboBox));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "choices", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BitmapComboBox)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString value = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	std::unique_ptr<wxArrayString> choices(CreateArrayString(args.GetList(5)));
	long style = 0;
	if (args.IsValid(6)) style = args.GetLong(6);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(7)) validator = Object_wx_Validator::GetObject(args, 7)->GetEntity();
	wxString name = wxT("comboBox");
	if (args.IsValid(8)) name = wxString::FromUTF8(args.GetString(8));
	wx_BitmapComboBox *pEntity = new wx_BitmapComboBox(parent, id, value, *pos, *size, *choices, style, *validator, name);
	Object_wx_BitmapComboBox *pObj = Object_wx_BitmapComboBox::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_BitmapComboBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_BitmapComboBox, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "choices", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapComboBox, Create)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString value = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	std::unique_ptr<wxArrayString> choices(CreateArrayString(args.GetList(5)));
	long style = 0;
	if (args.IsValid(6)) style = args.GetLong(6);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(7)) validator = Object_wx_Validator::GetObject(args, 7)->GetEntity();
	wxString name = wxT("comboBox");
	if (args.IsValid(8)) name = wxString::FromUTF8(args.GetString(8));
	bool rtn = pThis->GetEntity()->Create(parent, id, value, *pos, *size, *choices, style, *validator, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_BitmapComboBox, Append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapComboBox, Append)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString item = wxString::FromUTF8(args.GetString(0));
	wxBitmap *bitmap = (wxBitmap *)(&wxNullBitmap);
	if (args.IsValid(1)) bitmap = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	int rtn = pThis->GetEntity()->Append(item, *bitmap);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_BitmapComboBox, Append_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapComboBox, Append_1)
{
#if 0
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString item = wxString::FromUTF8(args.GetString(0));
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	int clientData = args.GetInt(2);
	int rtn = pThis->GetEntity()->Append(item, *bitmap, clientData);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_BitmapComboBox, Append_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "clientData", VTYPE_wx_ClientData, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapComboBox, Append_2)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString item = wxString::FromUTF8(args.GetString(0));
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	wxClientData *clientData = Object_wx_ClientData::GetObject(args, 2)->GetEntity();
	int rtn = pThis->GetEntity()->Append(item, *bitmap, clientData);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_BitmapComboBox, GetBitmapSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapComboBox, GetBitmapSize)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetBitmapSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_BitmapComboBox, GetItemBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapComboBox, GetItemBitmap)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned n = args.GetInt(0);
	wxBitmap rtn = pThis->GetEntity()->GetItemBitmap(n);
	return ReturnValue(env, sig, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_BitmapComboBox, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapComboBox, Insert)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString item = wxString::FromUTF8(args.GetString(0));
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	unsigned pos = args.GetInt(2);
	int rtn = pThis->GetEntity()->Insert(item, *bitmap, pos);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_BitmapComboBox, Insert_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapComboBox, Insert_1)
{
#if 0
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString item = wxString::FromUTF8(args.GetString(0));
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	unsigned pos = args.GetInt(2);
	int clientData = args.GetInt(3);
	int rtn = pThis->GetEntity()->Insert(item, *bitmap, pos, clientData);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_BitmapComboBox, Insert_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "clientData", VTYPE_wx_ClientData, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BitmapComboBox, Insert_2)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString item = wxString::FromUTF8(args.GetString(0));
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	unsigned pos = args.GetInt(2);
	wxClientData *clientData = Object_wx_ClientData::GetObject(args, 3)->GetEntity();
	int rtn = pThis->GetEntity()->Insert(item, *bitmap, pos, clientData);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_BitmapComboBox, SetItemBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapComboBox, SetItemBitmap)
{
	Object_wx_BitmapComboBox *pThis = Object_wx_BitmapComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned n = args.GetInt(0);
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetItemBitmap(n, *bitmap);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxBitmapComboBox
//----------------------------------------------------------------------------
Object_wx_BitmapComboBox::~Object_wx_BitmapComboBox()
{
}

Object *Object_wx_BitmapComboBox::Clone() const
{
	return nullptr;
}

String Object_wx_BitmapComboBox::ToString(bool exprFlag)
{
	String rtn("<wx.BitmapComboBox:");
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
// Class implementation for wxBitmapComboBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BitmapComboBox)
{
	Gura_AssignFunction(BitmapComboBoxEmpty);
	Gura_AssignFunction(BitmapComboBox);
	Gura_AssignMethod(wx_BitmapComboBox, Create);
	Gura_AssignMethod(wx_BitmapComboBox, Append);
	Gura_AssignMethod(wx_BitmapComboBox, Append_1);
	Gura_AssignMethod(wx_BitmapComboBox, Append_2);
	Gura_AssignMethod(wx_BitmapComboBox, GetBitmapSize);
	Gura_AssignMethod(wx_BitmapComboBox, GetItemBitmap);
	Gura_AssignMethod(wx_BitmapComboBox, Insert);
	Gura_AssignMethod(wx_BitmapComboBox, Insert_1);
	Gura_AssignMethod(wx_BitmapComboBox, Insert_2);
	Gura_AssignMethod(wx_BitmapComboBox, SetItemBitmap);
}

Gura_ImplementDescendantCreator(wx_BitmapComboBox)
{
	return new Object_wx_BitmapComboBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
