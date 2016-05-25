//-----------------------------------------------------------------------------
// Gura module: wx
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_WX_H__
#define __GURA_MODULE_WX_H__

//-----------------------------------------------------------------------------
// Macros
//-----------------------------------------------------------------------------
#if defined(__WXMSW__)
#define _MS(x) x
#else
#define _MS(x)
#endif

#undef BLACK_PEN
#undef WHITE_PEN
#undef BLACK_BRUSH
#undef WHITE_BRUSH
#undef TRANSPARENT
#undef FR_DOWN
#undef FR_WHOLEWORD
#undef FR_MATCHCASE
#undef FR_REPLACEDIALOG
#undef FR_NOUPDOWN
#undef FR_NOMATCHCASE
#undef FR_NOWHOLEWORD

#define Gura_AssignWxValue(name) \
Gura_AssignValue(name, Value(static_cast<double>(wx##name)))

#define Gura_AssignMacroValue(name) \
Gura_AssignValue(name, Value(static_cast<double>(name)))

#define Gura_AssignWxStringValue(name) \
Gura_AssignValue(name, Value(wxString(wx##name).ToUTF8()))

#define Gura_AssignWxObject(name, className) \
Gura_AssignValue(name, Value(new Object_wx_##className(const_cast<wx##className *>(wx##name), nullptr, false)));

#define Gura_AssignWxObjectEx(name, className, value) \
Gura_AssignValue(name, Value(new Object_wx_##className(const_cast<wx##className *>(value), nullptr, false)));

#define Gura_LookupWxMethod(pObj, name) \
LookupFunctionCustom(*pObj, Gura_UserSymbol(name), ENVREF_Escalate)

#define RealizeBaseClass(className) \
Gura_RealizeUserClassAlias(wx_##className, #className, env.LookupClass(VTYPE_object))

#define RealizeDervClass(className, classNameParent) \
Gura_RealizeUserClassAlias(wx_##className, #className, Gura_UserClass(wx_##classNameParent))

#define PrepareClass(className) \
Gura_PrepareUserClass(wx_##className)

Gura_BeginModuleHeader(wx)

extern const bool OwnerFalse;
extern const bool OwnerTrue;

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------
Function *LookupFunctionCustom(Environment &env, const Symbol *pSymbol, EnvRefMode envRefMode);
void SetWxReadyFlag(bool wxReadyFlag);
bool IsWxReady();
bool CheckWxReady(Signal &sig);
void InitializeObjects(Environment &env);
void SetError_Obsolete(Signal &sig);
void SetError_NotImplemented(Signal &sig);
void SetError_MSWOnly(Signal &sig);
void SetError_InvalidWxObject(Signal &sig, const char *name);
void SetLogError(const Signal &sig);
wxArrayString *CreateArrayString(const ValueList &valList);
wxArrayInt *CreateArrayInt(const ValueList &valList);
Value ArrayIntToValue(Environment &env, const wxArrayInt &array);
Value ArrayStringToValue(Environment &env, const wxArrayString &array);
Value ArrayStringToValue(Environment &env, const wxString *array, int n);
void AddToArrayString(wxArrayString &array, const ValueList &valList);
void AddToArrayInt(wxArrayInt &array, const ValueList &valList);
void ConvertToWxImage(Image *pImageGura, wxImage *pImage);
bool CheckMethodResult(Signal &sig);
bool CheckMethodResult(Signal &sig, const Value &rtn,
					ValueType valueType, bool invalidAcceptableFlag = false);

//-----------------------------------------------------------------------------
// GuraObjectObserver
//-----------------------------------------------------------------------------
class GuraObjectObserver {
public:
	virtual void GuraObjectDeleted() = 0;
};

//-----------------------------------------------------------------------------
// ClientData
//-----------------------------------------------------------------------------
class ClientData : public wxClientData {
private:
	Value _value;
public:
	inline ClientData(const Value &value) : _value(value) {}
	inline Value &GetValue() { return _value; }
};

//-----------------------------------------------------------------------------
// ObjectWithValue
//-----------------------------------------------------------------------------
class ObjectWithValue : public wxObject {
private:
	Value _value;
public:
	inline ObjectWithValue(const Value &value) : _value(value) {}
	inline Value &GetValue() { return _value; }
};

//-----------------------------------------------------------------------------
// Iterator_NewIds
//-----------------------------------------------------------------------------
class Iterator_NewIds : public Iterator {
public:
	inline Iterator_NewIds() : Iterator(true) {}
	virtual Iterator *Clone() const;
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

Gura_EndModuleHeader(wx)

#endif
