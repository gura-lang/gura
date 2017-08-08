#include "stdafx.h"

#define ImplementUnaryFuncPack(op, name, symbol, func)	\
Array::UnaryFuncPack g_unaryFuncPack_##op = { \
	name, \
	symbol, { \
	{ \
		nullptr, \
		&func<Boolean,	Boolean,	Operator_##op::Calc>,	\
		&func<Int8,		Int8,		Operator_##op::Calc>,	\
		&func<UInt8,	UInt8,		Operator_##op::Calc>,	\
		&func<Int16,	Int16,		Operator_##op::Calc>,	\
		&func<UInt16,	UInt16,		Operator_##op::Calc>,	\
		&func<Int32,	Int32,		Operator_##op::Calc>,	\
		&func<UInt32,	UInt32,		Operator_##op::Calc>,	\
		&func<Int64,	Int64,		Operator_##op::Calc>,	\
		&func<UInt64,	UInt64,		Operator_##op::Calc>,	\
		&func<Half,		Half,		Operator_##op::Calc>,	\
		&func<Float,	Float,		Operator_##op::Calc>,	\
		&func<Double,	Double,		Operator_##op::Calc>,	\
		&func<Complex,	Complex,	Operator_##op::Calc>,	\
		nullptr, \
	} } \
}

#define ImplementBinaryFuncPack(op, name, symbol, funcPrefix)	\
Array::BinaryFuncPack g_binaryFuncPack_##op = { \
	name, \
	symbol, { \
	{ \
		{ \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int8,		Boolean,	Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int8,		Boolean,	Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt8,	Boolean,	UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	Boolean,	Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	Boolean,	UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Boolean,	Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	Boolean,	UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Boolean,	Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	Boolean,	UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Boolean,	Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Boolean,	Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Boolean,	Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Boolean,	Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int8,		Int8,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int8,		Int8,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt8,	Int8,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	Int8,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	Int8,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int8,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	Int8,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int8,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	Int8,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Int8,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Int8,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Int8,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Int8,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt8,	UInt8,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt8,	UInt8,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt8,	UInt8,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	UInt8,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	UInt8,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	UInt8,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt8,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	UInt8,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt8,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		UInt8,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	UInt8,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	UInt8,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	UInt8,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int16,	Int16,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	Int16,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	Int16,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	Int16,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	Int16,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int16,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	Int16,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int16,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	Int16,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Int16,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Int16,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Int16,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Int16,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt16,	UInt16,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	UInt16,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt16,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	UInt16,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt16,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		UInt16,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	UInt16,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	UInt16,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	UInt16,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int32,	Int32,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int32,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int32,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int32,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int32,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int32,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	Int32,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int32,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	Int32,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Int32,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Int32,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Int32,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Int32,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	UInt32,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt32,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		UInt32,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	UInt32,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	UInt32,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	UInt32,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int64,	Int64,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	Int64,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Int64,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Int64,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Int64,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Int64,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		UInt64,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	UInt64,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	UInt64,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	UInt64,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Half,		Half,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Half,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Half,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Half,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Float,	Float,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Float,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Float,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Double,	Double,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Double,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Complex,	Complex,	Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
		}, \
	}, { \
		nullptr, \
		&funcPrefix##_array_number<Int8,		Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_array_number<Int8,		Int8,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<UInt8,		UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Int16,		Int16,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<UInt16,		UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Int32,		Int32,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<UInt32,		UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Int64,		Int64,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<UInt64,		UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Half,		Half,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Float,		Float,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Double,		Double,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Complex,		Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_number_array<Int8,		Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_number_array<Int8,		Int8,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<UInt8,		UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Int16,		Int16,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<UInt16,		UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Int32,		Int32,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<UInt32,		UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Int64,		Int64,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<UInt64,		UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Half,		Half,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Float,		Float,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Double,		Double,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Complex,		Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_array_complex<Complex,	Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Int8,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Int16,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Int32,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Int64,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Half,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Float,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Double,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_complex_array<Complex,	Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Int8,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Int16,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Int32,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Int64,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Half,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Float,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Double,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, \
	&funcPrefix##_number_number<Operator_##op::Calc>, \
	&funcPrefix##_complex_complex<Operator_##op::Calc> } \
}

#define ImplementBinaryFuncPack_Cmp(op, name, symbol, funcPrefix)	\
Array::BinaryFuncPack g_binaryFuncPack_##op = { \
	name, \
	symbol, { \
	{ \
		{ \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Int8,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Int16,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Int32,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Int64,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Half,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Float,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Double,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Complex,	Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
		}, \
	}, { \
		nullptr, \
		&funcPrefix##_array_number<Boolean,		Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Int8,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Int16,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Int32,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Int64,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Half,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Float,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Double,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_number_array<Boolean,		Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Int8,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Int16,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Int32,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Int64,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Half,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Float,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Double,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_array_complex<Boolean,	Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Int8,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Int16,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Int32,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Int64,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Half,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Float,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Double,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_complex_array<Boolean,	Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Int8,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Int16,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Int32,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Int64,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Half,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Float,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Double,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, \
	&funcPrefix##_number_number<Operator_##op::Calc>, \
	&funcPrefix##_complex_complex<Operator_##op::Calc> } \
}

#define ImplementBinaryFuncPack_BitOp(op, name, symbol)	 \
Array::BinaryFuncPack g_binaryFuncPack_##op = { \
	name, \
	symbol, { \
	{ \
		{ \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Boolean,	Boolean,	Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int8,		Boolean,	Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt8,		Boolean,	UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		Boolean,	Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		Boolean,	UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Boolean,	Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Boolean,	UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Boolean,	Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Boolean,	UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Int8,		Int8,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int8,		Int8,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt8,		Int8,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		Int8,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		Int8,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int8,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int8,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int8,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int8,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt8,		UInt8,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt8,		UInt8,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt8,		UInt8,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		UInt8,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt8,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		UInt8,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt8,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		UInt8,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt8,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Int16,		Int16,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		Int16,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		Int16,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		Int16,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		Int16,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int16,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		Int16,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int16,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		Int16,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		UInt16,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt16,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		UInt16,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt16,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		Int32,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int32,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		Int32,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		UInt32,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt32,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		Int64,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		}, \
	}, { \
		nullptr, \
		&BinaryFuncTmpl_array_number<Int8,		Boolean,	Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<Int8,		Int8,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<UInt8,		UInt8,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<Int16,		Int16,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<UInt16,	UInt16,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<Int32,		Int32,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<UInt32,	UInt32,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<Int64,		Int64,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<UInt64,	UInt64,		Operator_##op::Calc>,	\
		nullptr, \
		nullptr, \
		nullptr, \
		nullptr, \
		nullptr, \
	}, { \
		nullptr, \
		&BinaryFuncTmpl_number_array<Int8,		Boolean,	Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<Int8,		Int8,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<UInt8,		UInt8,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<Int16,		Int16,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<UInt16,	UInt16,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<Int32,		Int32,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<UInt32,	UInt32,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<Int64,		Int64,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<UInt64,	UInt64,		Operator_##op::Calc>,	\
		nullptr, \
		nullptr, \
		nullptr, \
		nullptr, \
		nullptr, \
	}, { \
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
	}, { \
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
	}, \
	nullptr, \
	nullptr } \
}

Gura_BeginModuleScope(arrayutil)

//------------------------------------------------------------------------------
// DotFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
void DotFuncTmpl_1d_2d(T_ElemResult *pElemResult,
					   const T_ElemL *pElemL, const T_ElemR *pElemR,
					   size_t nRowR, size_t nColR)
{
	const T_ElemR *pElemBaseR = pElemR;
	for (size_t iColR = 0; iColR < nColR; iColR++, pElemBaseR++) {
		const T_ElemL *pElemWorkL = pElemL;
		const T_ElemR *pElemWorkR = pElemBaseR;
		T_ElemResult elemResult = 0;
		for (size_t iRowR = 0; iRowR < nRowR; iRowR++, pElemWorkL++, pElemWorkR += nColR) {
			elemResult +=
				static_cast<T_ElemResult>(*pElemWorkL) *
				static_cast<T_ElemResult>(*pElemWorkR);
		}
		*pElemResult++ = elemResult;
	}
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
void DotFuncTmpl_2d_1d(T_ElemResult *pElemResult,
					   const T_ElemL *pElemL, const T_ElemR *pElemR,
					   size_t nRowL, size_t nColL)
{
	const T_ElemL *pElemBaseL = pElemL;
	for (size_t iRowL = 0; iRowL < nRowL; iRowL++, pElemBaseL += nColL) {
		const T_ElemL *pElemWorkL = pElemBaseL;
		const T_ElemR *pElemWorkR = pElemR;
		T_ElemResult elemResult = 0;
		for (size_t iColL = 0; iColL < nColL; iColL++, pElemWorkL++, pElemWorkR++) {
			elemResult +=
				static_cast<T_ElemResult>(*pElemWorkL) *
				static_cast<T_ElemResult>(*pElemWorkR);
		}
		*pElemResult++ = elemResult;
	}
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
void DotFuncTmpl_2d_2d(T_ElemResult *pElemResult,
					   const T_ElemL *pElemL, const T_ElemR *pElemR,
					   size_t nRowL, size_t nColL_nRowR, size_t nColR)
{
	const T_ElemL *pElemBaseL = pElemL;
	for (size_t iRow = 0; iRow < nRowL; iRow++, pElemBaseL += nColL_nRowR) {
		const T_ElemR *pElemBaseR = pElemR;
		for (size_t iCol = 0; iCol < nColR; iCol++, pElemBaseR++) {
			const T_ElemL *pElemWorkL = pElemBaseL;
			const T_ElemR *pElemWorkR = pElemBaseR;
			T_ElemResult elemResult = 0;
			for (size_t i = 0; i < nColL_nRowR; i++, pElemWorkL++, pElemWorkR += nColR) {
				elemResult +=
					static_cast<T_ElemResult>(*pElemWorkL) *
					static_cast<T_ElemResult>(*pElemWorkR);
			}
			*pElemResult++ = elemResult;
		}
	}
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
void DotFuncTmpl_1d_1d(T_ElemResult &elemResult,
					   const T_ElemL *pElemL, const T_ElemR *pElemR, size_t nColL)
{
	elemResult = 0;
	for (size_t iColL = 0; iColL < nColL; iColL++, pElemL++, pElemR++) {
		elemResult +=
			static_cast<T_ElemResult>(*pElemL) *
			static_cast<T_ElemResult>(*pElemR);
	}
}

void SetError_CantCalcuateDotProduct(Environment &env, const Array *pArrayL, const Array *pArrayR)
{
	env.SetError(ERR_ValueError,
				 "failed in array calculation: (%s) |.| (%s)",
				 pArrayL->GetDimensions().ToString().c_str(),
				 pArrayR->GetDimensions().ToString().c_str());
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
Value DotFuncTmpl(Environment &env, Array *pArrayResult, const Array *pArrayL, const Array *pArrayR)
{
	const Array::Dimensions &dimsL = pArrayL->GetDimensions();
	const Array::Dimensions &dimsR = pArrayR->GetDimensions();
	if (dimsL.size() == 1 && dimsR.size() == 1) {
		T_ElemResult elemResult = 0;
		size_t nColL = dimsL[0].GetSize();
		size_t nRowR = dimsR[0].GetSize();
		if (nColL != nRowR) {
			SetError_CantCalcuateDotProduct(env, pArrayL, pArrayR);
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		DotFuncTmpl_1d_1d(elemResult, pElemL, pElemR, nColL);
		return Value(elemResult);
	}
	AutoPtr<ArrayT<T_ElemResult> > pArrayTResult;
	if (dimsL.size() == 1 && dimsR.size() == 2) {
		size_t nColL = dimsL[0].GetSize();
		size_t nRowR = dimsR[0].GetSize();
		size_t nColR = dimsR[1].GetSize();
		if (nColL != nRowR) {
			SetError_CantCalcuateDotProduct(env, pArrayL, pArrayR);
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		pArrayTResult.reset((pArrayResult == nullptr)? new ArrayT<T_ElemResult>(nColR) :
							dynamic_cast<ArrayT<T_ElemResult> *>(pArrayResult));
		T_ElemResult *pElemResult = pArrayTResult->GetPointer();
		DotFuncTmpl_1d_2d(pElemResult, pElemL, pElemR, nRowR, nColR);
	} else if (dimsL.size() == 2 && dimsR.size() == 1) {
		size_t nRowL = dimsL[0].GetSize();
		size_t nColL = dimsL[1].GetSize();
		size_t nRowR = dimsR[0].GetSize();
		if (nColL != nRowR) {
			SetError_CantCalcuateDotProduct(env, pArrayL, pArrayR);
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		pArrayTResult.reset((pArrayResult == nullptr)? new ArrayT<T_ElemResult>(nRowL) :
							dynamic_cast<ArrayT<T_ElemResult> *>(pArrayResult));
		T_ElemResult *pElemResult = pArrayTResult->GetPointer();
		DotFuncTmpl_2d_1d(pElemResult, pElemL, pElemR, nRowL, nColL);
	} else if (dimsL.size() == 2 && dimsR.size() == 2) {
		size_t nRowL = dimsL[0].GetSize();
		size_t nColL = dimsL[1].GetSize();
		size_t nRowR = dimsR[0].GetSize();
		size_t nColR = dimsR[1].GetSize();
		if (nColL != nRowR) {
			SetError_CantCalcuateDotProduct(env, pArrayL, pArrayR);
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		pArrayTResult.reset((pArrayResult == nullptr)? new ArrayT<T_ElemResult>(nRowL, nColR) :
							dynamic_cast<ArrayT<T_ElemResult> *>(pArrayResult));
		T_ElemResult *pElemResult = pArrayTResult->GetPointer();
		DotFuncTmpl_2d_2d(pElemResult, pElemL, pElemR, nRowL, nColL, nColR);
	} else if (dimsL.size() >= 2 && dimsR.size() >= 2) {
		size_t nRowL = (dimsL.rbegin() + 1)->GetSize();
		size_t nColL = dimsL.rbegin()->GetSize();
		size_t nRowR = (dimsR.rbegin() + 1)->GetSize();
		size_t nColR = dimsR.rbegin()->GetSize();
		if (nColL != nRowR) {
			SetError_CantCalcuateDotProduct(env, pArrayL, pArrayR);
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		size_t elemNumL = pArrayL->GetElemNum();
		size_t elemNumR = pArrayR->GetElemNum();
		size_t elemNumMatResult = nRowL * nColR;
		size_t elemNumMatL = nRowL * nColL;
		size_t elemNumMatR = nRowR * nColR;
		size_t offsetL = 0, offsetR = 0;
		if (dimsL.size() < dimsR.size()) {
			if (pArrayResult == nullptr) {
				pArrayTResult.reset(new ArrayT<T_ElemResult>());
				pArrayTResult->SetDimensions(dimsR.begin(), dimsR.begin() + dimsR.size() - 2,
											 Array::Dimension(nRowL), Array::Dimension(nColR));
				pArrayTResult->AllocMemory();
			} else {
				pArrayTResult.reset(dynamic_cast<ArrayT<T_ElemResult> *>(pArrayResult));
			}
			T_ElemResult *pElemResult = pArrayTResult->GetPointer();
			while (offsetR < elemNumR) {
				DotFuncTmpl_2d_2d(pElemResult, pElemL + offsetL, pElemR + offsetR,
								  nRowL, nColL, nColR);
				pElemResult += elemNumMatResult;
				offsetL += elemNumMatL;
				offsetR += elemNumMatR;
				if (offsetL >= elemNumL) offsetL = 0;
			}
		} else { // dimsL.size() >= dimsR.size()
			if (pArrayResult == nullptr) {
				pArrayTResult.reset(new ArrayT<T_ElemResult>());
				pArrayTResult->SetDimensions(dimsL.begin(), dimsL.begin() + dimsL.size() - 2,
											 Array::Dimension(nRowL), Array::Dimension(nColR));
				pArrayTResult->AllocMemory();
			} else {
				pArrayTResult.reset(dynamic_cast<ArrayT<T_ElemResult> *>(pArrayResult));
			}
			T_ElemResult *pElemResult = pArrayTResult->GetPointer();
			while (offsetL < elemNumL) {
				DotFuncTmpl_2d_2d(pElemResult, pElemL + offsetL, pElemR + offsetR,
								  nRowL, nColL, nColR);
				pElemResult += elemNumMatResult;
				offsetL += elemNumMatL;
				offsetR += elemNumMatR;
				if (offsetR >= elemNumR) offsetR = 0;
			}
		}
	} else if (dimsL.size() == 1 && dimsR.size() >= 2) {
		size_t nColL = dimsL[0].GetSize();
		size_t nRowR = (dimsR.rbegin() + 1)->GetSize();
		size_t nColR = dimsR.rbegin()->GetSize();
		if (nColL != nRowR) {
			SetError_CantCalcuateDotProduct(env, pArrayL, pArrayR);
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		size_t elemNumR = pArrayR->GetElemNum();
		size_t elemNumMatR = nRowR * nColR;
		size_t offsetR = 0;
		if (pArrayResult == nullptr) {
			pArrayTResult.reset(new ArrayT<T_ElemResult>());
			pArrayTResult->SetDimensions(dimsR.begin(), dimsR.begin() + dimsR.size() - 2,
										 Array::Dimension(nColR));
			pArrayTResult->AllocMemory();
		} else {
			pArrayTResult.reset(dynamic_cast<ArrayT<T_ElemResult> *>(pArrayResult));
		}
		T_ElemResult *pElemResult = pArrayTResult->GetPointer();
		while (offsetR < elemNumR) {
			DotFuncTmpl_1d_2d(pElemResult, pElemL, pElemR + offsetR, nRowR, nColR);
			pElemResult += nColR;
			offsetR += elemNumMatR;
		}
	} else if (dimsL.size() >= 2 && dimsR.size() == 1) {
		size_t nRowL = (dimsL.rbegin() + 1)->GetSize();
		size_t nColL = dimsL.rbegin()->GetSize();
		size_t nRowR = dimsR[0].GetSize();
		if (nColL != nRowR) {
			SetError_CantCalcuateDotProduct(env, pArrayL, pArrayR);
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		size_t elemNumL = pArrayL->GetElemNum();
		size_t elemNumMatL = nRowL * nColL;
		size_t offsetL = 0;
		if (pArrayResult == nullptr) {
			pArrayTResult.reset(new ArrayT<T_ElemResult>());
			pArrayTResult->SetDimensions(dimsL.begin(), dimsL.begin() + dimsL.size() - 2,
										 Array::Dimension(nRowL));
			pArrayTResult->AllocMemory();
		} else {
			pArrayTResult.reset(dynamic_cast<ArrayT<T_ElemResult> *>(pArrayResult));
		}
		T_ElemResult *pElemResult = pArrayTResult->GetPointer();
		while (offsetL < elemNumL) {
			DotFuncTmpl_2d_1d(pElemResult, pElemL + offsetL, pElemR, nRowL, nColL);
			pElemResult += nRowR;
			offsetL += elemNumMatL;
		}
	}
	return Value(new Object_array(env, pArrayTResult.release()));
}

//------------------------------------------------------------------------------
// UnaryFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemResult, typename T_Elem, void (*op)(T_ElemResult &, const T_Elem &)>
Array *UnaryFuncTmpl(Signal &sig, Array *pArrayResult, const Array *pArray)
{
	AutoPtr<ArrayT<T_ElemResult> > pArrayTResult(
		(pArrayResult == nullptr)?
		ArrayT<T_ElemResult>::Create(pArray->GetDimensions()) :
		dynamic_cast<ArrayT<T_ElemResult> *>(pArrayResult));
	T_ElemResult *pResult = pArrayTResult->GetPointer();
	const T_Elem *pElem = dynamic_cast<const ArrayT<T_Elem> *>(pArray)->GetPointer();
	size_t nElems = pArray->GetElemNum();
	for (size_t i = 0; i < nElems; i++, pResult++, pElem++) {
		op(*pResult, *pElem);
	}
	return pArrayTResult.release();
}

template<typename T_ElemResult, typename T_Elem, void (*op)(T_ElemResult &, const T_Elem &)>
Array *UnaryFuncTmpl_ExcludeZero(Signal &sig, Array *pArrayResult, const Array *pArray)
{
	if (pArray->DoesContainZero()) {
		sig.SetError(ERR_MathError, "the array contains zero as its element");
		return nullptr;
	}
	return UnaryFuncTmpl<T_ElemResult, T_Elem, op>(sig, pArrayResult, pArray);
}

//------------------------------------------------------------------------------
// BinaryFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemResult, typename T_ElemL, typename T_ElemR,
		 void (*op)(T_ElemResult &, const T_ElemL &, const T_ElemR &)>
Array *BinaryFuncTmpl_array_array(Signal &sig, Array *pArrayResult,
								  const Array *pArrayL, const Array *pArrayR)
{
	const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
	const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
	size_t nElemsL = pArrayL->GetElemNum();
	size_t nElemsR = pArrayR->GetElemNum();
	AutoPtr<ArrayT<T_ElemResult> > pArrayTResult;
	if (nElemsL == nElemsR) {
		pArrayTResult.reset(
			(pArrayResult == nullptr)?
			ArrayT<T_ElemResult>::Create(pArrayL->GetDimensions()) :
			dynamic_cast<ArrayT<T_ElemResult> *>(pArrayResult));
		T_ElemResult *pElemResult = pArrayTResult->GetPointer();
		for (size_t offset = 0; offset < nElemsL; offset++, pElemResult++) {
			op(*pElemResult, *(pElemL + offset), *(pElemR + offset));
		}
	} else if (nElemsL < nElemsR) {
		pArrayTResult.reset(
			(pArrayResult == nullptr)?
			ArrayT<T_ElemResult>::Create(pArrayR->GetDimensions()) :
			dynamic_cast<ArrayT<T_ElemResult> *>(pArrayResult));
		T_ElemResult *pElemResult = pArrayTResult->GetPointer();
		size_t offsetL = 0;
		for (size_t offsetR = 0; offsetR < nElemsR; offsetR++, pElemResult++) {
			op(*pElemResult, *(pElemL + offsetL), *(pElemR + offsetR));
			offsetL++;
			if (offsetL >= nElemsL) offsetL = 0;
		}
	} else { // nElemsL > nElemsR
		pArrayTResult.reset(
			(pArrayResult == nullptr)?
			ArrayT<T_ElemResult>::Create(pArrayL->GetDimensions()) :
			dynamic_cast<ArrayT<T_ElemResult> *>(pArrayResult));
		T_ElemResult *pElemResult = pArrayTResult->GetPointer();
		size_t offsetR = 0;
		for (size_t offsetL = 0; offsetL < nElemsL; offsetL++, pElemResult++) {
			op(*pElemResult, *(pElemL + offsetL), *(pElemR + offsetR));
			offsetR++;
			if (offsetR >= nElemsR) offsetR = 0;
		}
	}
	return pArrayTResult.release();
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR,
		 void (*op)(T_ElemResult &, const T_ElemL &, const T_ElemR &)>
Array *BinaryFuncTmpl_Div_array_array(Signal &sig, Array *pArrayResult,
									  const Array *pArrayL, const Array *pArrayR)
{
	if (pArrayR->DoesContainZero()) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_array_array<T_ElemResult, T_ElemL, T_ElemR, op>(sig, pArrayResult, pArrayL, pArrayR);
}

template<typename T_ElemResult, typename T_ElemL,
		 void (*op)(T_ElemResult &, const T_ElemL &, const Double &)>
Array *BinaryFuncTmpl_array_number(Signal &sig, Array *pArrayResult,
								   const Array *pArrayL, Double numberR)
{
	const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
	size_t nElemsL = pArrayL->GetElemNum();
	AutoPtr<ArrayT<T_ElemResult> > pArrayTResult(
		(pArrayResult == nullptr)?
		ArrayT<T_ElemResult>::Create(pArrayL->GetDimensions()) :
		dynamic_cast<ArrayT<T_ElemResult> *>(pArrayResult));
	T_ElemResult *pElemResult = pArrayTResult->GetPointer();
	for (size_t i = 0; i < nElemsL; i++, pElemResult++, pElemL++) {
		op(*pElemResult, *pElemL, numberR);
	}
	return pArrayTResult.release();
}

template<typename T_ElemResult, typename T_ElemL,
		 void (*op)(T_ElemResult &, const T_ElemL &, const Double &)>
Array *BinaryFuncTmpl_Div_array_number(Signal &sig, Array *pArrayResult,
									   const Array *pArrayL, Double numberR)
{
	if (numberR == 0) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_array_number<T_ElemResult, T_ElemL, op>(sig, pArrayResult, pArrayL, numberR);
}

template<typename T_ElemResult, typename T_ElemR,
		 void (*op)(T_ElemResult &, const Double &, const T_ElemR &)>
Array *BinaryFuncTmpl_number_array(Signal &sig, Array *pArrayResult,
								   Double numberL, const Array *pArrayR)
{
	const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
	size_t nElemsR = pArrayR->GetElemNum();
	AutoPtr<ArrayT<T_ElemResult> > pArrayTResult(
		(pArrayResult == nullptr)?
		ArrayT<T_ElemResult>::Create(pArrayR->GetDimensions()) :
		dynamic_cast<ArrayT<T_ElemResult> *>(pArrayResult));
	T_ElemResult *pElemResult = pArrayTResult->GetPointer();
	for (size_t i = 0; i < nElemsR; i++, pElemResult++, pElemR++) {
		op(*pElemResult, numberL, *pElemR);
	}
	return pArrayTResult.release();
}

template<typename T_ElemResult, typename T_ElemR,
		 void (*op)(T_ElemResult &, const Double &, const T_ElemR &)>
Array *BinaryFuncTmpl_Div_number_array(Signal &sig, Array *pArrayResult,
									   Double numberL, const Array *pArrayR)
{
	if (pArrayR->DoesContainZero()) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_number_array<T_ElemResult, T_ElemR, op>(sig, pArrayResult, numberL, pArrayR);
}

template<typename T_ElemResult, typename T_ElemL,
		 void (*op)(T_ElemResult &, const T_ElemL &, const Complex &)>
Array *BinaryFuncTmpl_array_complex(Signal &sig, Array *pArrayResult,
									const Array *pArrayL, const Complex &complexR)
{
	const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
	size_t nElemsL = pArrayL->GetElemNum();
	AutoPtr<ArrayT<T_ElemResult> > pArrayTResult(
		(pArrayResult == nullptr)?
		ArrayT<T_ElemResult>::Create(pArrayL->GetDimensions()) :
		dynamic_cast<ArrayT<T_ElemResult> *>(pArrayResult));
	T_ElemResult *pElemResult = pArrayTResult->GetPointer();
	for (size_t i = 0; i < nElemsL; i++, pElemResult++, pElemL++) {
		op(*pElemResult, *pElemL, complexR);
	}
	return pArrayTResult.release();
}

template<typename T_ElemResult, typename T_ElemL,
		 void (*op)(T_ElemResult &, const T_ElemL &, const Complex &)>
Array *BinaryFuncTmpl_Div_array_complex(Signal &sig, Array *pArrayResult,
										const Array *pArrayL, const Complex &complexR)
{
	if (complexR == Complex::Zero) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_array_complex<T_ElemResult, T_ElemL, op>(sig, pArrayResult, pArrayL, complexR);
}

template<typename T_ElemResult, typename T_ElemR,
		 void (*op)(T_ElemResult &, const Complex &, const T_ElemR &)>
Array *BinaryFuncTmpl_complex_array(Signal &sig, Array *pArrayResult,
									const Complex &complexL, const Array *pArrayR)
{
	const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
	size_t nElemsR = pArrayR->GetElemNum();
	AutoPtr<ArrayT<T_ElemResult> > pArrayTResult(
		(pArrayResult == nullptr)?
		ArrayT<T_ElemResult>::Create(pArrayR->GetDimensions()) :
		dynamic_cast<ArrayT<T_ElemResult> *>(pArrayResult));
	T_ElemResult *pElemResult = pArrayTResult->GetPointer();
	for (size_t i = 0; i < nElemsR; i++, pElemResult++, pElemR++) {
		op(*pElemResult, complexL, *pElemR);
	}
	return pArrayTResult.release();
}

template<typename T_ElemResult, typename T_ElemR,
		 void (*op)(T_ElemResult &, const Complex &, const T_ElemR &)>
Array *BinaryFuncTmpl_Div_complex_array(Signal &sig, Array *pArrayResult,
										const Complex &complexL, const Array *pArrayR)
{
	if (pArrayR->DoesContainZero()) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_complex_array<T_ElemResult, T_ElemR, op>(sig, pArrayResult, complexL, pArrayR);
}

template<void (*op)(Double &, const Double &, const Double &)>
Array *BinaryFuncTmpl_number_number(Signal &sig, Array *pArrayResult, Double numberL, Double numberR)
{
	AutoPtr<ArrayT<Double> > pArrayTResult;
	pArrayTResult.reset(
		(pArrayResult == nullptr)?
		ArrayT<Double>::CreateScalar(0) :
		dynamic_cast<ArrayT<Double> *>(pArrayResult));
	op(*pArrayTResult->GetPointer(), numberL, numberR);
	return pArrayTResult.release();
}

template<void (*op)(Double &, const Double &, const Double &)>
Array *BinaryFuncTmpl_Div_number_number(Signal &sig, Array *pArrayResult, Double numberL, Double numberR)
{
	if (numberR == 0) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_number_number<op>(sig, pArrayResult, numberL, numberR);
}

template<void (*op)(Complex &, const Complex &, const Complex &)>
Array *BinaryFuncTmpl_complex_complex(Signal &sig, Array *pArrayResult, const Complex &complexL, const Complex &complexR)
{
	AutoPtr<ArrayT<Complex> > pArrayTResult;
	pArrayTResult.reset(
		(pArrayResult == nullptr)?
		ArrayT<Complex>::CreateScalar(0) :
		dynamic_cast<ArrayT<Complex> *>(pArrayResult));
	op(*pArrayTResult->GetPointer(), complexL, complexR);
	return pArrayTResult.release();
}

template<void (*op)(Complex &, const Complex &, const Complex &)>
Array *BinaryFuncTmpl_Div_complex_complex(Signal &sig, Array *pArrayResult, const Complex &complexL, const Complex &complexR)
{
	if (complexR.IsZero()) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_complex_complex<op>(sig, pArrayResult, complexL, complexR);
}

//------------------------------------------------------------------------------
// Function tables
//------------------------------------------------------------------------------
ImplementUnaryFuncPack(Pos,				"pos",				"+",	UnaryFuncTmpl);
ImplementUnaryFuncPack(Neg,				"neg",				"-",	UnaryFuncTmpl);

ImplementBinaryFuncPack(Add,			"add",				"+",	BinaryFuncTmpl);
ImplementBinaryFuncPack(Sub,			"sub",				"-",	BinaryFuncTmpl);
ImplementBinaryFuncPack(Mul,			"mul",				"*",	BinaryFuncTmpl);
ImplementBinaryFuncPack(Div,			"div",				"/",	BinaryFuncTmpl_Div);
ImplementBinaryFuncPack(Mod,			"mod",				"%",	BinaryFuncTmpl_Div);
ImplementBinaryFuncPack(Pow,			"pow",				"**",	BinaryFuncTmpl);

ImplementBinaryFuncPack_Cmp(Eq,			"eq",				"==",	BinaryFuncTmpl);
ImplementBinaryFuncPack_Cmp(Ne,			"ne",				"!=",	BinaryFuncTmpl);
ImplementBinaryFuncPack_Cmp(Gt,			"gt",				">",	BinaryFuncTmpl);
ImplementBinaryFuncPack_Cmp(Lt,			"lt",				"<",	BinaryFuncTmpl);
ImplementBinaryFuncPack_Cmp(Ge,			"ge",				">=",	BinaryFuncTmpl);
ImplementBinaryFuncPack_Cmp(Le,			"le",				"<=",	BinaryFuncTmpl);

ImplementBinaryFuncPack_BitOp(And,		"and",				"&");
ImplementBinaryFuncPack_BitOp(Or,		"or",				"|");
ImplementBinaryFuncPack_BitOp(Xor,		"xor",				"^");
ImplementBinaryFuncPack_BitOp(Shl,		"shl",				"<<");
ImplementBinaryFuncPack_BitOp(Shr,		"shr",				">>");

ImplementUnaryFuncPack(Math_abs,		"math.abs",			"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_acos,		"math.acos",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_arg,		"math.arg",			"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_asin,		"math.asin",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_atan,		"math.atan",		"",		UnaryFuncTmpl);
ImplementBinaryFuncPack(Math_atan2,		"math.atan2",		"",		BinaryFuncTmpl);
ImplementUnaryFuncPack(Math_ceil,		"math.ceil",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_conj,		"math.conj",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_cos,		"math.cos",			"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_cosh,		"math.cosh",		"",		UnaryFuncTmpl);
//ImplementBinaryFuncPack(Math_covariance,"math.covariance","",		BinaryFuncTmpl);
//ImplementBinaryFuncPack(Math_cross,	"math.cross",		"",		BinaryFuncTmpl);
ImplementUnaryFuncPack(Math_delta,		"math.delta",		"",		UnaryFuncTmpl);
//ImplementBinaryFuncPack(Math_dot,		"math.dot",			"",		BinaryFuncTmpl);
ImplementUnaryFuncPack(Math_exp,		"math.exp",			"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_floor,		"math.floor",		"",		UnaryFuncTmpl);
ImplementBinaryFuncPack(Math_hypot,		"math.hypot",		"",		BinaryFuncTmpl);
ImplementUnaryFuncPack(Math_imag,		"math.imag",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_log,		"math.log",			"",		UnaryFuncTmpl_ExcludeZero);
ImplementUnaryFuncPack(Math_log10,		"math.log10",		"",		UnaryFuncTmpl_ExcludeZero);
ImplementUnaryFuncPack(Math_norm,		"math.norm",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_ramp,		"math.ramp",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_real,		"math.real",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_sigmoid,	"math.sigmoid",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_sin,		"math.sin",			"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_sinh,		"math.sinh",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_sqrt,		"math.sqrt",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_tan,		"math.tan",			"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_tanh,		"math.tanh",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_unitstep,	"math.unitstep",	"",		UnaryFuncTmpl);

Array::DotFunc g_dotFuncs[Array::ETYPE_Max][Array::ETYPE_Max] = {
	{
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<Int8,		Boolean,	Boolean	>,
		&DotFuncTmpl<Int8,		Boolean,	Int8	>,
		&DotFuncTmpl<UInt8,		Boolean,	UInt8	>,
		&DotFuncTmpl<Int16,		Boolean,	Int16	>,
		&DotFuncTmpl<UInt16,	Boolean,	UInt16	>,
		&DotFuncTmpl<Int32,		Boolean,	Int32	>,
		&DotFuncTmpl<UInt32,	Boolean,	UInt32	>,
		&DotFuncTmpl<Int64,		Boolean,	Int64	>,
		&DotFuncTmpl<UInt64,	Boolean,	UInt64	>,
		&DotFuncTmpl<Half,		Boolean,	Half	>,
		&DotFuncTmpl<Float,		Boolean,	Float	>,
		&DotFuncTmpl<Double,	Boolean,	Double	>,
		&DotFuncTmpl<Complex,	Boolean,	Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<Int8,		Int8,		Boolean	>,
		&DotFuncTmpl<Int8,		Int8,		Int8	>,
		&DotFuncTmpl<UInt8,		Int8,		UInt8	>,
		&DotFuncTmpl<Int16,		Int8,		Int16	>,
		&DotFuncTmpl<UInt16,	Int8,		UInt16	>,
		&DotFuncTmpl<Int32,		Int8,		Int32	>,
		&DotFuncTmpl<UInt32,	Int8,		UInt32	>,
		&DotFuncTmpl<Int64,		Int8,		Int64	>,
		&DotFuncTmpl<UInt64,	Int8,		UInt64	>,
		&DotFuncTmpl<Half,		Int8,		Half	>,
		&DotFuncTmpl<Float,		Int8,		Float	>,
		&DotFuncTmpl<Double,	Int8,		Double	>,
		&DotFuncTmpl<Complex,	Int8,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<UInt8,		UInt8,		Boolean	>,
		&DotFuncTmpl<UInt8,		UInt8,		Int8	>,
		&DotFuncTmpl<UInt8,		UInt8,		UInt8	>,
		&DotFuncTmpl<Int16,		UInt8,		Int16	>,
		&DotFuncTmpl<UInt16,	UInt8,		UInt16	>,
		&DotFuncTmpl<Int32,		UInt8,		Int32	>,
		&DotFuncTmpl<UInt32,	UInt8,		UInt32	>,
		&DotFuncTmpl<Int64,		UInt8,		Int64	>,
		&DotFuncTmpl<UInt64,	UInt8,		UInt64	>,
		&DotFuncTmpl<Half,		UInt8,		Half	>,
		&DotFuncTmpl<Float,		UInt8,		Float	>,
		&DotFuncTmpl<Double,	UInt8,		Double	>,
		&DotFuncTmpl<Complex,	UInt8,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<Int16,		Int16,		Boolean	>,
		&DotFuncTmpl<Int16,		Int16,		Int8	>,
		&DotFuncTmpl<Int16,		Int16,		UInt8	>,
		&DotFuncTmpl<Int16,		Int16,		Int16	>,
		&DotFuncTmpl<UInt16,	Int16,		UInt16	>,
		&DotFuncTmpl<Int32,		Int16,		Int32	>,
		&DotFuncTmpl<UInt32,	Int16,		UInt32	>,
		&DotFuncTmpl<Int64,		Int16,		Int64	>,
		&DotFuncTmpl<UInt64,	Int16,		UInt64	>,
		&DotFuncTmpl<Half,		Int16,		Half	>,
		&DotFuncTmpl<Float,		Int16,		Float	>,
		&DotFuncTmpl<Double,	Int16,		Double	>,
		&DotFuncTmpl<Complex,	Int16,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<UInt16,	UInt16,		Boolean	>,
		&DotFuncTmpl<UInt16,	UInt16,		Int8	>,
		&DotFuncTmpl<UInt16,	UInt16,		UInt8	>,
		&DotFuncTmpl<UInt16,	UInt16,		Int16	>,
		&DotFuncTmpl<UInt16,	UInt16,		UInt16	>,
		&DotFuncTmpl<Int32,		UInt16,		Int32	>,
		&DotFuncTmpl<UInt32,	UInt16,		UInt32	>,
		&DotFuncTmpl<Int64,		UInt16,		Int64	>,
		&DotFuncTmpl<UInt64,	UInt16,		UInt64	>,
		&DotFuncTmpl<Half,		UInt16,		Half	>,
		&DotFuncTmpl<Float,		UInt16,		Float	>,
		&DotFuncTmpl<Double,	UInt16,		Double	>,
		&DotFuncTmpl<Complex,	UInt16,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<Int32,		Int32,		Boolean	>,
		&DotFuncTmpl<Int32,		Int32,		Int8	>,
		&DotFuncTmpl<Int32,		Int32,		UInt8	>,
		&DotFuncTmpl<Int32,		Int32,		Int16	>,
		&DotFuncTmpl<Int32,		Int32,		UInt16	>,
		&DotFuncTmpl<Int32,		Int32,		Int32	>,
		&DotFuncTmpl<UInt32,	Int32,		UInt32	>,
		&DotFuncTmpl<Int64,		Int32,		Int64	>,
		&DotFuncTmpl<UInt64,	Int32,		UInt64	>,
		&DotFuncTmpl<Half,		Int32,		Half	>,
		&DotFuncTmpl<Float,		Int32,		Float	>,
		&DotFuncTmpl<Double,	Int32,		Double	>,
		&DotFuncTmpl<Complex,	Int32,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<UInt32,	UInt32,		Boolean	>,
		&DotFuncTmpl<UInt32,	UInt32,		Int8	>,
		&DotFuncTmpl<UInt32,	UInt32,		UInt8	>,
		&DotFuncTmpl<UInt32,	UInt32,		Int16	>,
		&DotFuncTmpl<UInt32,	UInt32,		UInt16	>,
		&DotFuncTmpl<UInt32,	UInt32,		Int32	>,
		&DotFuncTmpl<UInt32,	UInt32,		UInt32	>,
		&DotFuncTmpl<Int64,		UInt32,		Int64	>,
		&DotFuncTmpl<UInt64,	UInt32,		UInt64	>,
		&DotFuncTmpl<Half,		UInt32,		Half	>,
		&DotFuncTmpl<Float,		UInt32,		Float	>,
		&DotFuncTmpl<Double,	UInt32,		Double	>,
		&DotFuncTmpl<Complex,	UInt32,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<Int64,		Int64,		Boolean	>,
		&DotFuncTmpl<Int64,		Int64,		Int8	>,
		&DotFuncTmpl<Int64,		Int64,		UInt8	>,
		&DotFuncTmpl<Int64,		Int64,		Int16	>,
		&DotFuncTmpl<Int64,		Int64,		UInt16	>,
		&DotFuncTmpl<Int64,		Int64,		Int32	>,
		&DotFuncTmpl<Int64,		Int64,		UInt32	>,
		&DotFuncTmpl<Int64,		Int64,		Int64	>,
		&DotFuncTmpl<UInt64,	Int64,		UInt64	>,
		&DotFuncTmpl<Half,		Int64,		Half	>,
		&DotFuncTmpl<Float,		Int64,		Float	>,
		&DotFuncTmpl<Double,	Int64,		Double	>,
		&DotFuncTmpl<Complex,	Int64,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<UInt64,	UInt64,		Boolean	>,
		&DotFuncTmpl<UInt64,	UInt64,		Int8	>,
		&DotFuncTmpl<UInt64,	UInt64,		UInt8	>,
		&DotFuncTmpl<UInt64,	UInt64,		Int16	>,
		&DotFuncTmpl<UInt64,	UInt64,		UInt16	>,
		&DotFuncTmpl<UInt64,	UInt64,		Int32	>,
		&DotFuncTmpl<UInt64,	UInt64,		UInt32	>,
		&DotFuncTmpl<UInt64,	UInt64,		Int64	>,
		&DotFuncTmpl<UInt64,	UInt64,		UInt64	>,
		&DotFuncTmpl<Half,		UInt64,		Half	>,
		&DotFuncTmpl<Float,		UInt64,		Float	>,
		&DotFuncTmpl<Double,	UInt64,		Double	>,
		&DotFuncTmpl<Complex,	UInt64,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<Half,		Half,		Boolean	>,
		&DotFuncTmpl<Half,		Half,		Int8	>,
		&DotFuncTmpl<Half,		Half,		UInt8	>,
		&DotFuncTmpl<Half,		Half,		Int16	>,
		&DotFuncTmpl<Half,		Half,		UInt16	>,
		&DotFuncTmpl<Half,		Half,		Int32	>,
		&DotFuncTmpl<Half,		Half,		UInt32	>,
		&DotFuncTmpl<Half,		Half,		Int64	>,
		&DotFuncTmpl<Half,		Half,		UInt64	>,
		&DotFuncTmpl<Half,		Half,		Half	>,
		&DotFuncTmpl<Half,		Half,		Float	>,
		&DotFuncTmpl<Double,	Half,		Double	>,
		&DotFuncTmpl<Complex,	Half,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<Float,		Float,		Boolean	>,
		&DotFuncTmpl<Float,		Float,		Int8	>,
		&DotFuncTmpl<Float,		Float,		UInt8	>,
		&DotFuncTmpl<Float,		Float,		Int16	>,
		&DotFuncTmpl<Float,		Float,		UInt16	>,
		&DotFuncTmpl<Float,		Float,		Int32	>,
		&DotFuncTmpl<Float,		Float,		UInt32	>,
		&DotFuncTmpl<Float,		Float,		Int64	>,
		&DotFuncTmpl<Float,		Float,		UInt64	>,
		&DotFuncTmpl<Float,		Float,		Half	>,
		&DotFuncTmpl<Float,		Float,		Float	>,
		&DotFuncTmpl<Double,	Float,		Double	>,
		&DotFuncTmpl<Complex,	Float,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<Double,	Double,		Boolean	>,
		&DotFuncTmpl<Double,	Double,		Int8	>,
		&DotFuncTmpl<Double,	Double,		UInt8	>,
		&DotFuncTmpl<Double,	Double,		Int16	>,
		&DotFuncTmpl<Double,	Double,		UInt16	>,
		&DotFuncTmpl<Double,	Double,		Int32	>,
		&DotFuncTmpl<Double,	Double,		UInt32	>,
		&DotFuncTmpl<Double,	Double,		Int64	>,
		&DotFuncTmpl<Double,	Double,		UInt64	>,
		&DotFuncTmpl<Half,		Double,		Half	>,
		&DotFuncTmpl<Double,	Double,		Float	>,
		&DotFuncTmpl<Double,	Double,		Double	>,
		&DotFuncTmpl<Complex,	Double,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<Complex,	Complex,	Boolean	>,
		&DotFuncTmpl<Complex,	Complex,	Int8	>,
		&DotFuncTmpl<Complex,	Complex,	UInt8	>,
		&DotFuncTmpl<Complex,	Complex,	Int16	>,
		&DotFuncTmpl<Complex,	Complex,	UInt16	>,
		&DotFuncTmpl<Complex,	Complex,	Int32	>,
		&DotFuncTmpl<Complex,	Complex,	UInt32	>,
		&DotFuncTmpl<Complex,	Complex,	Int64	>,
		&DotFuncTmpl<Complex,	Complex,	UInt64	>,
		&DotFuncTmpl<Complex,	Complex,	Half	>,
		&DotFuncTmpl<Complex,	Complex,	Float	>,
		&DotFuncTmpl<Complex,	Complex,	Double	>,
		&DotFuncTmpl<Complex,	Complex,	Complex	>,
		nullptr,
	}, {
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
	},
};

//-----------------------------------------------------------------------------
// [+A] ... UnaryOperator(Pos, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Pos, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Pos, value);
}

//-----------------------------------------------------------------------------
// [-A] ... UnaryOperator(Neg, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Neg, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Neg, value);
}

//-----------------------------------------------------------------------------
// [~A] ... UnaryOperator(Invert, A)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [!A] ... UnaryOperator(Not, A)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A..] ... UnaryOperator(SeqInf, A)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A?] ... UnaryOperator(Question, A)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A*] ... UnaryOperator(Each, A)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A+] ... UnaryOperator(PostPos, A)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A%] ... UnaryOperator(PostMod, A)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A + B] ... BinaryOperator(Add, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Add, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, g_binaryFuncPack_Add, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Add, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, g_binaryFuncPack_Add, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Add, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, g_binaryFuncPack_Add, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Add, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, g_binaryFuncPack_Add, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Add, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, g_binaryFuncPack_Add, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A - B] ... BinaryOperator(Sub, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Sub, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, g_binaryFuncPack_Sub, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Sub, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, g_binaryFuncPack_Sub, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Sub, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, g_binaryFuncPack_Sub, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Sub, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, g_binaryFuncPack_Sub, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Sub, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, g_binaryFuncPack_Sub, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A * B] ... BinaryOperator(Mul, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Mul, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, g_binaryFuncPack_Mul, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Mul, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, g_binaryFuncPack_Mul, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Mul, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, g_binaryFuncPack_Mul, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Mul, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, g_binaryFuncPack_Mul, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Mul, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, g_binaryFuncPack_Mul, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A / B] ... BinaryOperator(Div, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Div, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, g_binaryFuncPack_Div, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Div, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, g_binaryFuncPack_Div, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Div, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, g_binaryFuncPack_Div, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Div, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, g_binaryFuncPack_Div, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Div, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, g_binaryFuncPack_Div, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A % B] ... BinaryOperator(Mod, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Mod, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, g_binaryFuncPack_Mod, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Mod, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, g_binaryFuncPack_Mod, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Mod, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, g_binaryFuncPack_Mod, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A %% B] ... BinaryOperator(ModMod, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A |.| B] ... BinaryOperator(DotProd, A, B)
//-----------------------------------------------------------------------------
Value CalcDot(Environment &env, const Array *pArrayL, const Array *pArrayR)
{
	Array::DotFunc dotFunc = g_dotFuncs[pArrayL->GetElemType()][pArrayR->GetElemType()];
	if (dotFunc == nullptr) {
		env.SetError(ERR_TypeError, "can't apply dot function on these arrays");
		return Value::Nil;
	}
	return (*dotFunc)(env, nullptr, pArrayL, pArrayR);
}

Gura_ImplementBinaryOperator(DotProd, array, array)
{
	const Array *pArrayL = Object_array::GetObject(valueLeft)->GetArray();
	const Array *pArrayR = Object_array::GetObject(valueRight)->GetArray();
	return CalcDot(env, pArrayL, pArrayR);
}

//-----------------------------------------------------------------------------
// [A |*| B] ... BinaryOperator(CrossProd, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A |+| B] ... BinaryOperator(Join, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A |-| B] ... BinaryOperator(Difference, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A |&| B] ... BinaryOperator(Intersection, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A ||| B] ... BinaryOperator(Union, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A ** B] ... BinaryOperator(Pow, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Pow, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, g_binaryFuncPack_Pow, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Pow, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, g_binaryFuncPack_Pow, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Pow, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, g_binaryFuncPack_Pow, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Pow, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, g_binaryFuncPack_Pow, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Pow, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, g_binaryFuncPack_Pow, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A == B] ... BinaryOperator(Eq, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Eq, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, g_binaryFuncPack_Eq, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Eq, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, g_binaryFuncPack_Eq, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Eq, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, g_binaryFuncPack_Eq, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Eq, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, g_binaryFuncPack_Eq, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Eq, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, g_binaryFuncPack_Eq, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A != B] ... BinaryOperator(Ne, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Ne, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, g_binaryFuncPack_Ne, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Ne, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, g_binaryFuncPack_Ne, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Ne, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, g_binaryFuncPack_Ne, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Ne, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, g_binaryFuncPack_Ne, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Ne, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, g_binaryFuncPack_Ne, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A > B] ... BinaryOperator(Gt, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Gt, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, g_binaryFuncPack_Gt, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Gt, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, g_binaryFuncPack_Gt, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Gt, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, g_binaryFuncPack_Gt, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Gt, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, g_binaryFuncPack_Gt, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Gt, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, g_binaryFuncPack_Gt, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A < B] ... BinaryOperator(Lt, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Lt, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, g_binaryFuncPack_Lt, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Lt, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, g_binaryFuncPack_Lt, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Lt, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, g_binaryFuncPack_Lt, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Lt, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, g_binaryFuncPack_Lt, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Lt, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, g_binaryFuncPack_Lt, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A >= B] ... BinaryOperator(Ge, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Ge, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, g_binaryFuncPack_Ge, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Ge, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, g_binaryFuncPack_Ge, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Ge, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, g_binaryFuncPack_Ge, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Ge, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, g_binaryFuncPack_Ge, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Ge, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, g_binaryFuncPack_Ge, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A <= B] ... BinaryOperator(Le, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Le, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, g_binaryFuncPack_Le, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Le, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, g_binaryFuncPack_Le, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Le, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, g_binaryFuncPack_Le, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Le, array, complex)
{
	return Array::ApplyBinaryFuncOnValue_array_complex(
		env, g_binaryFuncPack_Le, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Le, complex, array)
{
	return Array::ApplyBinaryFuncOnValue_complex_array(
		env, g_binaryFuncPack_Le, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A <=> B] BinaryOperator(Cmp, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A in B] ... BinaryOperator(Contains, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A & B] ... BinaryOperator(And, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(And, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, g_binaryFuncPack_And, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(And, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, g_binaryFuncPack_And, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(And, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, g_binaryFuncPack_And, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A | B] ... BinaryOperator(Or, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Or, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, g_binaryFuncPack_Or, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Or, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, g_binaryFuncPack_Or, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Or, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, g_binaryFuncPack_Or, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A ^ B] ... BinaryOperator(Xor, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Xor, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, g_binaryFuncPack_Xor, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Xor, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, g_binaryFuncPack_Xor, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Xor, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, g_binaryFuncPack_Xor, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A << B] ... BinaryOperator(Shl, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Shl, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, g_binaryFuncPack_Shl, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Shl, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, g_binaryFuncPack_Shl, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Shl, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, g_binaryFuncPack_Shl, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A >> B] ... BinaryOperator(Shr, A, B)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Shr, array, array)
{
	return Array::ApplyBinaryFuncOnValue_array_array(
		env, g_binaryFuncPack_Shr, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Shr, array, number)
{
	return Array::ApplyBinaryFuncOnValue_array_number(
		env, g_binaryFuncPack_Shr, valueLeft, valueRight);
}

Gura_ImplementBinaryOperator(Shr, number, array)
{
	return Array::ApplyBinaryFuncOnValue_number_array(
		env, g_binaryFuncPack_Shr, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// [A || B] ... BinaryOperator(OrOr, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A && B] ... BinaryOperator(AndAnd, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A .. B] ... BinaryOperator(Seq, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [A => B] ... BinaryOperator(Pair, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// math.abs(A) ... UnaryOperator(Math_abs, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_abs, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_abs, value);
}

//-----------------------------------------------------------------------------
// math.acos(A) ... UnaryOperator(Math_acos, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_acos, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_acos, value);
}

//-----------------------------------------------------------------------------
// math.arg(A) ... UnaryOperator(Math_arg, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_arg, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_arg, value);
}

//-----------------------------------------------------------------------------
// math.asin(A) ... UnaryOperator(Math_asin, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_asin, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_asin, value);
}

//-----------------------------------------------------------------------------
// math.atan(A) ... UnaryOperator(Math_atan, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_atan, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_atan, value);
}

//-----------------------------------------------------------------------------
// math.atan2(A, B) ... UnaryOperator(Math_atan2, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// math.ceil(A) ... UnaryOperator(Math_ceil, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_ceil, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_ceil, value);
}

//-----------------------------------------------------------------------------
// math.conj(A) ... UnaryOperator(Math_conj, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_conj, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_conj, value);
}

//-----------------------------------------------------------------------------
// math.cos(A) ... UnaryOperator(Math_cos, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_cos, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_cos, value);
}

//-----------------------------------------------------------------------------
// math.cosh(A) ... UnaryOperator(Math_cosh, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_cosh, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_cosh, value);
}

//-----------------------------------------------------------------------------
// math.covariance(A, B) ... BinaryOperator(Math_covariance, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// math.cross(A, B) ... BinaryOperator(Math_cross, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// math.delta(A) ... UnaryOperator(Math_delta, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_delta, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_delta, value);
}

//-----------------------------------------------------------------------------
// math.dot(A, B) ... BinaryOperator(Math_dot, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// math.exp(A) ... UnaryOperator(Math_exp, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_exp, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_exp, value);
}

//-----------------------------------------------------------------------------
// math.floor(A) ... UnaryOperator(Math_floor, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_floor, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_floor, value);
}

//-----------------------------------------------------------------------------
// math.hypot(A, B) ... BinaryOperator(Math_hypot, A, B)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// math.imag(A) ... UnaryOperator(Math_imag, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_imag, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_imag, value);
}

//-----------------------------------------------------------------------------
// math.log(A) ... UnaryOperator(Math_log, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_log, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_log, value);
}

//-----------------------------------------------------------------------------
// math.log10(A) ... UnaryOperator(Math_log10, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_log10, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_log10, value);
}

//-----------------------------------------------------------------------------
// math.norm(A) ... UnaryOperator(Math_norm, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_norm, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_norm, value);
}

//-----------------------------------------------------------------------------
// math.ramp(A) ... UnaryOperator(Math_ramp, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_ramp, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_ramp, value);
}

//-----------------------------------------------------------------------------
// math.real(A) ... UnaryOperator(Math_real, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_real, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_real, value);
}

//-----------------------------------------------------------------------------
// math.sigmoid(A) ... UnaryOperator(Math_sigmoid, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_sigmoid, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_sigmoid, value);
}

//-----------------------------------------------------------------------------
// math.sin(A) ... UnaryOperator(Math_sin, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_sin, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_sin, value);
}

//-----------------------------------------------------------------------------
// math.sinh(A) ... UnaryOperator(Math_sinh, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_sinh, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_sinh, value);
}

//-----------------------------------------------------------------------------
// math.sqrt(A) ... UnaryOperator(Math_sqrt, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_sqrt, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_sqrt, value);
}

//-----------------------------------------------------------------------------
// math.tan(A) ... UnaryOperator(Math_tan, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_tan, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_tan, value);
}

//-----------------------------------------------------------------------------
// math.tanh(A) ... UnaryOperator(Math_tanh, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_tanh, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_tanh, value);
}

//-----------------------------------------------------------------------------
// math.unitstep(A) ... UnaryOperator(Math_unitstep, A)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Math_unitstep, array)
{
	return Array::ApplyUnaryFuncOnValue(env, g_unaryFuncPack_Math_unitstep, value);
}

void AssignOperators(Environment &env)
{
#if 0
	Array::unaryFuncPack_Pos.table =			g_unaryFuncTable_Pos;
	Array::unaryFuncPack_Neg.table = 			g_unaryFuncTable_Neg;
	Array::binaryFuncPack_Add.table =			g_unaryFuncTable_Add;
	Array::binaryFuncPack_Sub.table =			g_binaryFuncTable_Sub;
	Array::binaryFuncPack_Mul.table =			g_binaryFuncTable_Mul;
	Array::binaryFuncPack_Div.table =			g_binaryFuncTable_Div;
	Array::binaryFuncPack_Mod.table =			g_binaryFuncTable_Mod;
	Array::binaryFuncPack_Pow.table =			g_binaryFuncTable_Pow;
	Array::binaryFuncPack_Eq.table =			g_binaryFuncTable_Eq;
	Array::binaryFuncPack_Ne.table =			g_binaryFuncTable_Ne;
	Array::binaryFuncPack_Gt.table =			g_binaryFuncTable_Gt;
	Array::binaryFuncPack_Lt.table =			g_binaryFuncTable_Lt;
	Array::binaryFuncPack_Ge.table =			g_binaryFuncTable_Ge;
	Array::binaryFuncPack_Le.table =			g_binaryFuncTable_Le;
	Array::binaryFuncPack_And.table =			g_binaryFuncTable_And;
	Array::binaryFuncPack_Or.table =			g_binaryFuncTable_Or;
	Array::binaryFuncPack_Xor.table =			g_binaryFuncTable_Xor;
	Array::binaryFuncPack_Shl.table =			g_binaryFuncTable_Shl;
	Array::binaryFuncPack_Shr.table =			g_binaryFuncTable_Shr;
	Array::unaryFuncPack_Math_abs.table =		g_unaryFuncTable_Math_abs;
	Array::unaryFuncPack_Math_acos.table =		g_unaryFuncTable_Math_acos;
	Array::unaryFuncPack_Math_arg.table =		g_unaryFuncTable_Math_arg;
	Array::unaryFuncPack_Math_asin.table =		g_unaryFuncTable_Math_asin;
	Array::unaryFuncPack_Math_atan.table =		g_unaryFuncTable_Math_atan;
	Array::unaryFuncPack_Math_ceil.table =		g_unaryFuncTable_Math_ceil;
	Array::unaryFuncPack_Math_conj.table =		g_unaryFuncTable_Math_conj;
	Array::unaryFuncPack_Math_cos.table =		g_unaryFuncTable_Math_cos;
	Array::unaryFuncPack_Math_cosh.table =		g_unaryFuncTable_Math_cosh;
	Array::unaryFuncPack_Math_delta.table =		g_unaryFuncTable_Math_delta;
	Array::unaryFuncPack_Math_exp.table =		g_unaryFuncTable_Math_exp;
	Array::unaryFuncPack_Math_floor.table =		g_unaryFuncTable_Math_floor;
	Array::unaryFuncPack_Math_imag.table =		g_unaryFuncTable_Math_imag;
	Array::unaryFuncPack_Math_log.table =		g_unaryFuncTable_Math_log;
	Array::unaryFuncPack_Math_log10.table =		g_unaryFuncTable_Math_log10;
	Array::unaryFuncPack_Math_norm.table =		g_unaryFuncTable_Math_norm;
	Array::unaryFuncPack_Math_ramp.table =		g_unaryFuncTable_Math_ramp;
	Array::unaryFuncPack_Math_real.table =		g_unaryFuncTable_Math_real;
	Array::unaryFuncPack_Math_sigmoid.table =	g_unaryFuncTable_Math_sigmoid;
	Array::unaryFuncPack_Math_sin.table =		g_unaryFuncTable_Math_sin;
	Array::unaryFuncPack_Math_sinh.table =		g_unaryFuncTable_Math_sinh;
	Array::unaryFuncPack_Math_sqrt.table =		g_unaryFuncTable_Math_sqrt;
	Array::unaryFuncPack_Math_tan.table =		g_unaryFuncTable_Math_tan;
	Array::unaryFuncPack_Math_tanh.table =		g_unaryFuncTable_Math_tanh;
	Array::unaryFuncPack_Math_unitstep.table =	g_unaryFuncTable_Math_unitstep;
#endif
	// unary operators
	Gura_AssignUnaryOperator(Pos, array);
	Gura_AssignUnaryOperator(Neg, array);
	// binary operators
	Gura_AssignBinaryOperator(Add, array, array);
	Gura_AssignBinaryOperator(Add, array, number);
	Gura_AssignBinaryOperator(Add, number, array);
	Gura_AssignBinaryOperator(Add, array, complex);
	Gura_AssignBinaryOperator(Add, complex, array);
	Gura_AssignBinaryOperator(Sub, array, array);
	Gura_AssignBinaryOperator(Sub, array, number);
	Gura_AssignBinaryOperator(Sub, number, array);
	Gura_AssignBinaryOperator(Sub, array, complex);
	Gura_AssignBinaryOperator(Sub, complex, array);
	Gura_AssignBinaryOperator(Mul, array, array);
	Gura_AssignBinaryOperator(Mul, array, number);
	Gura_AssignBinaryOperator(Mul, number, array);
	Gura_AssignBinaryOperator(Mul, array, complex);
	Gura_AssignBinaryOperator(Mul, complex, array);
	Gura_AssignBinaryOperator(Div, array, array);
	Gura_AssignBinaryOperator(Div, array, number);
	Gura_AssignBinaryOperator(Div, number, array);
	Gura_AssignBinaryOperator(Div, array, complex);
	Gura_AssignBinaryOperator(Div, complex, array);
	Gura_AssignBinaryOperator(Mod, array, array);
	Gura_AssignBinaryOperator(Mod, array, number);
	Gura_AssignBinaryOperator(Mod, number, array);
	Gura_AssignBinaryOperator(DotProd, array, array);
	Gura_AssignBinaryOperator(Pow, array, array);
	Gura_AssignBinaryOperator(Pow, array, number);
	Gura_AssignBinaryOperator(Pow, number, array);
	Gura_AssignBinaryOperator(Pow, array, complex);
	Gura_AssignBinaryOperator(Pow, complex, array);
	Gura_AssignBinaryOperator(Eq, array, array);
	Gura_AssignBinaryOperator(Eq, array, number);
	Gura_AssignBinaryOperator(Eq, number, array);
	Gura_AssignBinaryOperator(Eq, array, complex);
	Gura_AssignBinaryOperator(Eq, complex, array);
	Gura_AssignBinaryOperator(Ne, array, array);
	Gura_AssignBinaryOperator(Ne, array, number);
	Gura_AssignBinaryOperator(Ne, number, array);
	Gura_AssignBinaryOperator(Ne, array, complex);
	Gura_AssignBinaryOperator(Ne, complex, array);
	Gura_AssignBinaryOperator(Gt, array, array);
	Gura_AssignBinaryOperator(Gt, array, number);
	Gura_AssignBinaryOperator(Gt, number, array);
	Gura_AssignBinaryOperator(Gt, array, complex);
	Gura_AssignBinaryOperator(Gt, complex, array);
	Gura_AssignBinaryOperator(Lt, array, array);
	Gura_AssignBinaryOperator(Lt, array, number);
	Gura_AssignBinaryOperator(Lt, number, array);
	Gura_AssignBinaryOperator(Lt, array, complex);
	Gura_AssignBinaryOperator(Lt, complex, array);
	Gura_AssignBinaryOperator(Ge, array, array);
	Gura_AssignBinaryOperator(Ge, array, number);
	Gura_AssignBinaryOperator(Ge, number, array);
	Gura_AssignBinaryOperator(Ge, array, complex);
	Gura_AssignBinaryOperator(Ge, complex, array);
	Gura_AssignBinaryOperator(Le, array, array);
	Gura_AssignBinaryOperator(Le, array, number);
	Gura_AssignBinaryOperator(Le, number, array);
	Gura_AssignBinaryOperator(Le, array, complex);
	Gura_AssignBinaryOperator(Le, complex, array);
	Gura_AssignBinaryOperator(And, array, array);
	Gura_AssignBinaryOperator(And, array, number);
	Gura_AssignBinaryOperator(And, number, array);
	Gura_AssignBinaryOperator(Or, array, array);
	Gura_AssignBinaryOperator(Or, array, number);
	Gura_AssignBinaryOperator(Or, number, array);
	Gura_AssignBinaryOperator(Xor, array, array);
	Gura_AssignBinaryOperator(Xor, array, number);
	Gura_AssignBinaryOperator(Xor, number, array);
	Gura_AssignBinaryOperator(Shl, array, array);
	Gura_AssignBinaryOperator(Shl, array, number);
	Gura_AssignBinaryOperator(Shl, number, array);
	Gura_AssignBinaryOperator(Shr, array, array);
	Gura_AssignBinaryOperator(Shr, array, number);
	Gura_AssignBinaryOperator(Shr, number, array);
	// mathematical functions
	Gura_AssignUnaryOperator(Math_abs, array);
	Gura_AssignUnaryOperator(Math_acos, array);
	Gura_AssignUnaryOperator(Math_arg, array);
	Gura_AssignUnaryOperator(Math_asin, array);
	Gura_AssignUnaryOperator(Math_atan, array);
	Gura_AssignUnaryOperator(Math_ceil, array);
	Gura_AssignUnaryOperator(Math_conj, array);
	Gura_AssignUnaryOperator(Math_cos, array);
	Gura_AssignUnaryOperator(Math_cosh, array);
	Gura_AssignUnaryOperator(Math_delta, array);
	Gura_AssignUnaryOperator(Math_exp, array);
	Gura_AssignUnaryOperator(Math_floor, array);
	Gura_AssignUnaryOperator(Math_imag, array);
	Gura_AssignUnaryOperator(Math_log, array);
	Gura_AssignUnaryOperator(Math_log10, array);
	Gura_AssignUnaryOperator(Math_norm, array);
	Gura_AssignUnaryOperator(Math_ramp, array);
	Gura_AssignUnaryOperator(Math_real, array);
	Gura_AssignUnaryOperator(Math_sigmoid, array);
	Gura_AssignUnaryOperator(Math_sin, array);
	Gura_AssignUnaryOperator(Math_sinh, array);
	Gura_AssignUnaryOperator(Math_sqrt, array);
	Gura_AssignUnaryOperator(Math_tan, array);
	Gura_AssignUnaryOperator(Math_tanh, array);
	Gura_AssignUnaryOperator(Math_unitstep, array);
}

Gura_EndModuleScope(arrayutil)
