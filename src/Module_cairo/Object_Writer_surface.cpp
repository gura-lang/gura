#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_Writer_surface implementation
//-----------------------------------------------------------------------------
Object_Writer_surface::~Object_Writer_surface()
{
	if (_surface != NULL) {
		::cairo_surface_destroy(_surface);
		_surface = NULL;
	}
	delete _pWriter; // this must be deleted after surface is destroyed
	_pWriter = NULL;
}

bool Object_Writer_surface::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object_surface::DoDirProp(sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(stream));
	symbols.insert(Gura_UserSymbol(width));
	symbols.insert(Gura_UserSymbol(height));
	return true;
}

Value Object_Writer_surface::DoGetProp(Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	Environment &env = *this;
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(stream))) {
		Stream *pStream = _pWriter->GetStream();
		if (pStream == NULL) return Value::Null;
		Object_stream *pObjStream = new Object_stream(env, Stream::Reference(pStream));
		return Value(pObjStream);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(width))) {
		return Value(_pWriter->GetWidth());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(height))) {
		return Value(_pWriter->GetHeight());
	}
	evaluatedFlag = false;
	return Object_surface::DoGetProp(sig, pSymbol, attrs, evaluatedFlag);
}

}}
