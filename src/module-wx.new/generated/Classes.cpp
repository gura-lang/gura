#include "stdafx.h"

Gura_BeginModuleScope(wx)

void RegisterClasses(Environment &env)
{
	RealizeBaseClass(AboutDialogInfo);
	RealizeBaseClass(AcceleratorEntry);
	RealizeBaseClass(AddRemoveAdaptor);
	RealizeBaseClass(AffineMatrix2DBase);
	  RealizeDervClass(AffineMatrix2D, AffineMatrix2DBase);
	RealizeBaseClass(Any);
	RealizeBaseClass(AnyValueType);
	PrepareClass(AboutDialogInfo);
	PrepareClass(AcceleratorEntry);
	PrepareClass(AddRemoveAdaptor);
	PrepareClass(AffineMatrix2DBase);
	  PrepareClass(AffineMatrix2D);
	PrepareClass(Any);
	PrepareClass(AnyValueType);
}

Gura_EndModuleScope(wx)
