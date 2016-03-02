//=============================================================================
// Gura class: pointer
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_pointer
//-----------------------------------------------------------------------------
Object_pointer::~Object_pointer()
{
}

Object *Object_pointer::Clone() const
{
	return new Object_pointer(*this);
}

bool Object_pointer::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(offset));
	symbols.insert(Gura_Symbol(size));
	symbols.insert(Gura_Symbol(target));
	return true;
}

Value Object_pointer::DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(offset))) {
		return Value(GetPointer()->GetOffset());
	} else if (pSymbol->IsIdentical(Gura_Symbol(size))) {
		return Value(GetPointer()->GetSize());
	} else if (pSymbol->IsIdentical(Gura_Symbol(target))) {
		return Value(GetPointer()->GetTarget()->Reference());
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_pointer::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	if (pSymbol->IsIdentical(Gura_Symbol(offset))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		evaluatedFlag = true;
		size_t offset = value.GetSizeT();
		GetPointer()->SetOffset(offset);
		return Value(offset);
	}
	return Value::Nil;
}

String Object_pointer::ToString(bool exprFlag)
{
	char buff[64];
	::sprintf(buff, "<pointer:%d>", static_cast<int>(GetPointer()->GetOffset()));
	return String(buff);
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// pointer#dump(stream?:stream:w):void:[upper]
Gura_DeclareMethod(pointer, dump)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareAttr(Gura_Symbol(upper));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Prints a hexadecimal dump from the content of the `pointer` to the standard output.\n"
		"If the argument `stream` is specified, the result would be output to the stream.\n"
		"\n"
		"In default, hexadecimal digit are printed with lower-case characters.\n"
		"Specifying an attribute `:upper` would output them with upper-case characters instead.\n"
		"\n"
		"Example:\n"
		"    >>> b'A quick brown fox jumps over the lazy dog.'.pointer().dump():upper\n"
		"    41 20 71 75 69 63 6B 20 62 72 6F 77 6E 20 66 6F  A quick brown fo\n"
		"    78 20 6A 75 6D 70 73 20 6F 76 65 72 20 74 68 65  x jumps over the\n"
		"    20 6C 61 7A 79 20 64 6F 67 2E                     lazy dog.\n");
}

Gura_ImplementMethod(pointer, dump)
{
	Signal &sig = env.GetSignal();
	Stream *pStream = arg.IsInstanceOf(0, VTYPE_stream)?
								&arg.GetStream(0) : env.GetConsole();
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	pStream->Dump(sig, pPointer->GetPointerC(), pPointer->GetSize(), arg.IsSet(Gura_Symbol(upper)));
	return Value::Nil;
}

// pointer#forward(distance:number):reduce
Gura_DeclareMethod(pointer, forward)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "distance", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Put the pointer offset forward by `distance`.\n"
		"If a negative number is specified for the argument, the offset would be put backward.\n"
		"\n"
		"An error would occur when the pointer's offset becomes a negative value\n"
		"while it would be no error when the offset exceeds the target maximum range.\n");
}

Gura_ImplementMethod(pointer, forward)
{
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	if (!pPointer->Advance(env, arg.GetInt(0))) return Value::Nil;
	return arg.GetValueThis();
}

// pointer#pack(format:string, value+):reduce:[stay]
Gura_DeclareMethod(pointer, pack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "values", VTYPE_any, OCCUR_OnceOrMore);
	DeclareAttr(Gura_Symbol(stay));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Packs `values` in the argument list according to specifiers in the `format`\n"
		"into a binary and adds it to where the pointer points.\n"
		"The pointer offset is automatically incremented by the added length\n"
		"unless `:stay` attribute is specified.\n"
		"\n"
		"This method returns a reference to the pointer instance itself.\n"
		"\n"
		"A specifier has a format of \"`nX`\" where `X` is a format character\n"
		"that represents a packing format and `n` is a number of packing size.\n"
		"The number can be omitted, and it would be treated as `1` in that case.\n"
		"\n"
		"Following format characters would take a `number` value from the argument list\n"
		"and pack them into a binary sequence.\n"
		"\n"
		"- `b` .. One-byte signed number.\n"
		"- `B` .. One-byte unsigned number.\n"
		"- `h` .. Two-byte signed number.\n"
		"- `H` .. Two-byte unsigned number.\n"
		"- `i` .. Four-byte signed number.\n"
		"- `I` .. Four-byte unsigned number.\n"
		"- `l` .. Four-byte signed number.\n"
		"- `L` .. Four-byte unsigned number.\n"
		"- `q` .. Eight-byte signed number.\n"
		"- `Q` .. Eight-byte unsigned number.\n"
		"- `f` .. Float-typed number occupying four bytes.\n"
		"- `d` .. Double-typed number occupying eight bytes.\n"
		"\n"
		"As for them, the packing size `n` means the number of values to be packed.\n"
		"\n"
		"Following format characters would take a `string` value from the argument list\n"
		"and pack them into a binary sequence.\n"
		"\n"
		"- `s` .. Packs a sequence of UTF-8 codes in the string.\n"
		"         The packing size `n` means the size of the room in bytes\n"
		"         where the character codes are to be packed.\n"
		"         Only the sequence within the allocated room would be packed.\n"
		"         If the string length is smaller than the room,\n"
		"         the lacking part would be filled with zero.\n"
		"- `c` .. Picks the first byte of the string and packs it as a one-byte unsigned number.\n"
		"         The packing size `n` means the number of values to be packed.\n"
		"\n"
		"Following format character would take no value from the argument list.\n"
		"\n"
		"- `x` .. Fills the binary with zero.\n"
		"         The packing size `n` means the size of the room in bytes\n"
		"         to be filled with zero.\n"
		"\n"
		"The default byte-order for numbers of two-byte, four-byte and eight-byte\n"
		"depends on the system the interpreter is currently running.\n"
		"You can change it by the following specifiers:\n"
		"\n"
		"- `@` .. System-dependent order.\n"
		"- `=` .. System-dependent order.\n"
		"- `<` .. Little endian\n"
		"- `>` .. Big endian\n"
		"- `!` .. Big endian\n"
		"\n"
		"You can specify an asterisk character \"`*`\" for the number of packing size\n"
		"that picks that number from the argument list.\n"
		"\n"
		"You can specify encoding name embraced with \"`{`\" and \"`}`\" in the format\n"
		"to change coding character set from UTF-8\n"
		"while packing a string with format character \"`s`\".\n");
}

Gura_ImplementMethod(pointer, pack)
{
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	if (!pPointer->IsWritable()) {
		env.SetError(ERR_ValueError, "not a writable binary");
		return Value::Nil;
	}
	bool forwardFlag = !arg.IsSet(Gura_Symbol(stay));
	pPointer->Pack(env, forwardFlag, arg.GetString(0), arg.GetList(1));
	return arg.GetValueThis();
}

// pointer#reset()
Gura_DeclareMethod(pointer, reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(pointer, reset)
{
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	pPointer->Reset();
	return Value::Nil;
}

// pointer#unpack(format:string, values*:number):[nil,stay]
Gura_DeclareMethod(pointer, unpack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "values", VTYPE_number, OCCUR_ZeroOrMore);
	DeclareAttr(Gura_Symbol(nil));
	DeclareAttr(Gura_Symbol(stay));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Extracts values from data sequence pointed by the `pointer` instance according to specifiers in the `format`\n"
		"and returns a list containing the values.\n"
		"\n"
		"A specifier has a format of \"`nX`\" where `X` is a format character\n"
		"that represents a packing format and `n` is a number of packing size.\n"
		"The number can be omitted, and it would be treated as `1` in that case.\n"
		"\n"
		"Following format characters would extract an integer or float value of specified size\n"
		"from the binary and returns a `number` value.\n"
		"\n"
		"- `b` .. One-byte signed number.\n"
		"- `B` .. One-byte unsigned number.\n"
		"- `h` .. Two-byte signed number.\n"
		"- `H` .. Two-byte unsigned number.\n"
		"- `i` .. Four-byte signed number.\n"
		"- `I` .. Four-byte unsigned number.\n"
		"- `l` .. Four-byte signed number.\n"
		"- `L` .. Four-byte unsigned number.\n"
		"- `q` .. Eight-byte signed number.\n"
		"- `Q` .. Eight-byte unsigned number.\n"
		"- `f` .. Float-typed number occupying four bytes.\n"
		"- `d` .. Double-typed number occupying eight bytes.\n"
		"\n"
		"As for them, the packing size `n` means the number of values to be extracted.\n"
		"\n"
		"Following format characters would extract a string sequence from the binary\n"
		"and returns a `string` value.\n"
		"\n"
		"- `s` .. Extracts a sequence of UTF-8 codes and returns `string` instance containing it.\n"
		"         The unpacking size `n` means the size of the room in bytes\n"
		"         where the character codes are to be unpacked.\n"
		"- `c` .. Extracts a one-byte unsigned number and returns a `string` instance containing it.\n"
		"         The unpacking size `n` means the number of values to be extracted.\n"
		"\n"
		"Following format character would not return any value.\n"
		"\n"
		"- `x` .. Advances the address by one byte.\n"
		"         If the unpacking size `n` is specifies,\n"
		"         it would advance the address by `n` bytes.\n"
		"\n"
		"The default byte-order for numbers of two-byte, four-byte and eight-byte\n"
		"depends on the system the interpreter is currently running.\n"
		"You can change it by the following specifiers:\n"
		"\n"
		"- `@` .. System-dependent order.\n"
		"- `=` .. System-dependent order.\n"
		"- `<` .. Little endian\n"
		"- `>` .. Big endian\n"
		"- `!` .. Big endian\n"
		"\n"
		"You can specify an asterisk character \"`*`\" for the number of unpacking size\n"
		"that picks that number from the argument list.\n"
		"\n"
		"You can specify encoding name embraced with \"`{`\" and \"`}`\" in the format\n"
		"to change coding character set from UTF-8\n"
		"while extracting a string with format character \"`s`\".\n"
		"\n"
		"An error occurs if the binary size is smaller than the format reqeusts.\n"
		"If the attribute `:nil` is specified, `nil` value would be returned for such a case.\n");
}

Gura_ImplementMethod(pointer, unpack)
{
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	bool forwardFlag = !arg.IsSet(Gura_Symbol(stay));
	bool exceedErrorFlag = !arg.IsSet(Gura_Symbol(nil));
	return pPointer->Unpack(env, forwardFlag,
							arg.GetString(0), arg.GetList(1), exceedErrorFlag);
}

// pointer#unpacks(format:string, values*:number) {block?}
Gura_DeclareMethod(pointer, unpacks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "values", VTYPE_number, OCCUR_ZeroOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an iterator that extracts values from data pointed by the `pointer` instance\n"
		"according to specifiers in `format`.\n"
		"\n"
		"For detailed information about specifiers, see the help of `pointer#unpack()`.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("iter", "iterator"));
}

Gura_ImplementMethod(pointer, unpacks)
{
	Pointer *pPointer = Object_pointer::GetObjectThis(arg)->GetPointer();
	Iterator *pIterator = pPointer->CreateUnpackIterator(arg.GetString(0), arg.GetList(1));
	return ReturnIterator(env, arg, pIterator);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_pointer::Class_pointer(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_pointer)
{
}

void Class_pointer::Prepare(Environment &env)
{
	//Gura_AssignFunction(pointer);
	Gura_AssignValue(pointer, Value(Reference()));
	Gura_AssignMethod(pointer, dump);
	Gura_AssignMethod(pointer, forward);
	Gura_AssignMethod(pointer, pack);
	Gura_AssignMethod(pointer, reset);
	Gura_AssignMethod(pointer, unpack);
	Gura_AssignMethod(pointer, unpacks);
}

bool Class_pointer::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	if (value.Is_binary()) {
		Object_binary *pObj = Object_binary::GetObject(value);
		Pointer *pPointer = new Object_binary::PointerEx(0, pObj->Reference());
		value = Value(new Object_pointer(env, pPointer));
		return true;
	} else if (value.Is_memory()) {
		Object_memory *pObj = Object_memory::GetObject(value);
		Pointer *pPointer = new Object_memory::PointerEx(0, pObj->Reference());
		value = Value(new Object_pointer(env, pPointer));
		return true;
	}
	return false;
}

Object *Class_pointer::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
