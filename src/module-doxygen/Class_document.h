//=============================================================================
// Class_document.h
//=============================================================================
#ifndef __GURA_DOXYGEN_CLASS_DOCUMENT_H__
#define __GURA_DOXYGEN_CLASS_DOCUMENT_H__

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// doxygen.document class
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(document);

class Object_document : public Object {
public:
	Gura_DeclareObjectAccessor(document)
private:
	AutoPtr<Document> _pDocument;
public:
	inline Object_document(Document *pDocument = nullptr) :
					Object(Gura_UserClass(document)), _pDocument(pDocument) {}
	virtual ~Object_document();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetDocument(Document *pDocument) { _pDocument.reset(pDocument); }
	inline Document *GetDocument() { return _pDocument.get(); }
};

Gura_EndModuleScope(doxygen)

#endif
