#ifndef __MODULE_WX_H__
#define __MODULE_WX_H__

//-----------------------------------------------------------------------------
// Macros
//-----------------------------------------------------------------------------
#define Gura_AssignWxValue(name) \
Gura_AssignValue(name, Value(wx##name))

#define Gura_AssignWxObject(name, className) \
Gura_AssignValue(name, Value(new Object_wx_##className(const_cast<wx##className *>(wx##name), NULL, false)));

#define Gura_AssignWxObjectEx(name, value, className) \
Gura_AssignValue(name, Value(new Object_wx_##className(const_cast<wx##className *>(value), NULL, false)));

#define Gura_AssignMacroValue(name) \
Gura_AssignValue(name, Value(name))

Gura_BeginModule(wx)

extern bool OwnerFalse;
extern bool OwnerTrue;

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------
void SetError_NotImplemented(Signal sig);
void SetError_InvalidWxObject(Signal sig, const char *name);
int *CreateListOfInt(const ValueList &valList);
wxString *CreateListOfString(const ValueList &valList);
wxDash *CreateListOfDash(const ValueList &valList);
wxPoint *CreateListOfPoint(const ValueList &valList);
wxArrayString *CreateArrayString(const ValueList &valList);
wxArrayInt *CreateArrayInt(const ValueList &valList);
Value ArrayIntToValue(Environment &env, const wxArrayInt &array);
Value ArrayStringToValue(Environment &env, const wxArrayString &array);
Value ArrayStringToValue(Environment &env, const wxString *array, int n);
void AddToArrayString(wxArrayString &array, const ValueList &valList);
void AddToArrayInt(wxArrayInt &array, const ValueList &valList);

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

}}

#endif
