#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_Writer_surface implementation
//-----------------------------------------------------------------------------
Object_Writer_surface::~Object_Writer_surface()
{
	if (_surface != nullptr) {
		::cairo_surface_destroy(_surface);
		_surface = nullptr;
	}
	delete _pWriter; // this must be deleted after surface is destroyed
	_pWriter = nullptr;
}

bool Object_Writer_surface::DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object_surface::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(stream));
	symbols.insert(Gura_UserSymbol(width));
	symbols.insert(Gura_UserSymbol(height));
	return true;
}

Value Object_Writer_surface::DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(stream))) {
		Stream *pStream = _pWriter->GetStream();
		if (pStream == nullptr) return Value::Null;
		Object_stream *pObjStream = new Object_stream(env, Stream::Reference(pStream));
		return Value(pObjStream);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(width))) {
		return Value(_pWriter->GetWidth());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(height))) {
		return Value(_pWriter->GetHeight());
	}
	evaluatedFlag = false;
	return Object_surface::DoGetProp(env, sig, pSymbol, attrs, evaluatedFlag);
}

Gura_EndModuleScope(cairo)
