#ifndef __CAIRO_OBJECT_WRITER_SURFACE_H__
#define __CAIRO_OBJECT_WRITER_SURFACE_H__

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_Writer_surface declaration
//-----------------------------------------------------------------------------
class Object_Writer_surface : public Object_surface {
private:
	Writer *_pWriter;
public:
	inline Object_Writer_surface(cairo_surface_t *surface, Writer *pWriter) :
				Object_surface(surface), _pWriter(pWriter) {}
	virtual ~Object_Writer_surface();
	inline Writer *GetWriter() { return _pWriter; }
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
};

}}

#endif
