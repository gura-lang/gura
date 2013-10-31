//----------------------------------------------------------------------------
// wxStringBuffer
// extracted from wxstring.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StringBuffer: public wxStringBuffer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_StringBuffer *_pObj;
public:
	inline wx_StringBuffer(wxString& str, size_t len) : wxStringBuffer(str, len), _sig(NULL), _pObj(NULL) {}
	~wx_StringBuffer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_StringBuffer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StringBuffer::~wx_StringBuffer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_StringBuffer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStringBuffer
//----------------------------------------------------------------------------
Gura_DeclareFunction(StringBuffer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StringBuffer));
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StringBuffer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	size_t len = args.GetSizeT(1);
	wx_StringBuffer *pEntity = new wx_StringBuffer(str, len);
	Object_wx_StringBuffer *pObj = Object_wx_StringBuffer::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StringBuffer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxStringBuffer
//----------------------------------------------------------------------------
Object_wx_StringBuffer::~Object_wx_StringBuffer()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_StringBuffer::Clone() const
{
	return NULL;
}

String Object_wx_StringBuffer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.StringBuffer:");
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
// Class implementation for wxStringBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringBuffer)
{
	Gura_AssignFunction(StringBuffer);
}

Gura_ImplementDescendantCreator(wx_StringBuffer)
{
	return new Object_wx_StringBuffer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
