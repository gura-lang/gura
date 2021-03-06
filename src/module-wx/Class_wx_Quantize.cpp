//----------------------------------------------------------------------------
// wxQuantize
// extracted from quantize.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Quantize: public wxQuantize, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Quantize *_pObj;
public:
	inline wx_Quantize() : wxQuantize(), _pObj(nullptr) {}
	~wx_Quantize();
	inline void AssocWithGura(Object_wx_Quantize *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Quantize::~wx_Quantize()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Quantize::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxQuantize
//----------------------------------------------------------------------------
Gura_DeclareFunction(QuantizeEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Quantize));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(QuantizeEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Quantize *pEntity = new wx_Quantize();
	Object_wx_Quantize *pObj = Object_wx_Quantize::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Quantize(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_Quantize, Quantize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "src", VTYPE_wx_Image, OCCUR_Once);
	DeclareArg(env, "dest", VTYPE_wx_Image, OCCUR_Once);
	DeclareArg(env, "pPalette", VTYPE_wx_Palette, OCCUR_Once);
	DeclareArg(env, "desiredNoColours", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "eightBitData", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Quantize, Quantize)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Quantize *pThis = Object_wx_Quantize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxImage *src = Object_wx_Image::GetObject(arg, 0)->GetEntity();
	wxImage *dest = Object_wx_Image::GetObject(arg, 1)->GetEntity();
	wxPalette *pPalette = Object_wx_Palette::GetObject(arg, 2)->GetEntity();
	int desiredNoColours = 236;
	if (arg.IsValid(3)) desiredNoColours = arg.GetInt(3);
	unsigned char eightBitData = 0;
	if (arg.IsValid(4)) eightBitData = arg.GetUChar(4);
	int flags = wxQUANTIZE_INCLUDE_WINDOWS_COLOURS|wxQUANTIZE_FILL_DESTINATION_IMAGE|wxQUANTIZE_RETURN_8BIT_DATA;
	if (arg.IsValid(5)) flags = arg.GetInt(5);
	bool rtn = pThis->GetEntity()->Quantize(*src, *dest, *pPalette, desiredNoColours, eightBitData, flags);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Quantize, Quantize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "src", VTYPE_wx_Image, OCCUR_Once);
	DeclareArg(env, "dest", VTYPE_wx_Image, OCCUR_Once);
	DeclareArg(env, "desiredNoColours", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "eightBitData", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Quantize, Quantize_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Quantize *pThis = Object_wx_Quantize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxImage *src = Object_wx_Image::GetObject(arg, 0)->GetEntity();
	wxImage *dest = Object_wx_Image::GetObject(arg, 1)->GetEntity();
	int desiredNoColours = 236;
	if (arg.IsValid(2)) desiredNoColours = arg.GetInt(2);
	unsigned char eightBitData = 0;
	if (arg.IsValid(3)) eightBitData = arg.GetUChar(3);
	int flags = wxQUANTIZE_INCLUDE_WINDOWS_COLOURS|wxQUANTIZE_FILL_DESTINATION_IMAGE|wxQUANTIZE_RETURN_8BIT_DATA;
	if (arg.IsValid(4)) flags = arg.GetInt(4);
	bool rtn = pThis->GetEntity()->Quantize(*src, *dest, desiredNoColours, eightBitData, flags);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Quantize, DoQuantize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "in_rows", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "out_rows", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "palette", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "desiredNoColours", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Quantize, DoQuantize)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Quantize *pThis = Object_wx_Quantize::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned w = arg.GetInt(0);
	unsigned h = arg.GetInt(1);
	unsigned char in_rows = arg.GetUChar(2);
	unsigned char out_rows = arg.GetUChar(3);
	unsigned char palette = arg.GetUChar(4);
	int desiredNoColours = arg.GetInt(5);
	pThis->GetEntity()->DoQuantize(w, h, in_rows, out_rows, palette, desiredNoColours);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxQuantize
//----------------------------------------------------------------------------
Object_wx_Quantize::~Object_wx_Quantize()
{
}

Object *Object_wx_Quantize::Clone() const
{
	return nullptr;
}

String Object_wx_Quantize::ToString(bool exprFlag)
{
	String rtn("<wx.Quantize:");
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
// Class implementation for wxQuantize
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Quantize)
{
	Gura_AssignFunction(QuantizeEmpty);
	Gura_AssignMethod(wx_Quantize, Quantize);
	Gura_AssignMethod(wx_Quantize, Quantize_1);
	Gura_AssignMethod(wx_Quantize, DoQuantize);
}

Gura_ImplementDescendantCreator(wx_Quantize)
{
	return new Object_wx_Quantize((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
