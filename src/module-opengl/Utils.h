#ifndef __GURA_OPENGL_UTILS_H__
#define __GURA_OPENGL_UTILS_H__
#include <gura.h>

namespace Gura {

template<typename T_Elem>
ArrayT<T_Elem> *MakeMatrix(Environment &env, const Value &value)
{
	AutoPtr<ArrayT<T_Elem> > rtn(ArrayT<T_Elem>::Create1d(16));
	if (value.Is_list()) {
		const ValueList &valList = value.GetList();
		if (valList.size() != 16) {
			env.SetError(ERR_ValueError, "list must contain 16 elements");
			goto done;
		}
		T_Elem *p = rtn->GetPointer();
		foreach_const (ValueList, pValue, valList) {
			if (!pValue->Is_number()) {
				env.SetError(ERR_ValueError, "element must be a number");
				goto done;
			}
			*p++ = static_cast<T_Elem>(pValue->GetDouble());
		}
	} else {
		env.SetError(ERR_ValueError, "list or matrix must be specified");
	}
done:
	return rtn.release();
}

const void *GetArrayTPointer(Environment &env, GLenum type, const Array *pArray);
	
}

#endif
