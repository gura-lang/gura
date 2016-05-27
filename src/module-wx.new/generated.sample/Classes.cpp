#include "stdafx.h"

Gura_BeginModuleScope(wx)

void RegisterClasses(Environment &env)
{
	RealizeBaseClass(ClassInfo);
	RealizeBaseClass(Object);
	RealizeBaseClass(ObjectRefData);
	RealizeDervClass(Event,								Object);
	PrepareClass(ClassInfo);
	PrepareClass(Object);
	PrepareClass(ObjectRefData);
	PrepareClass(Event);
}

Gura_EndModuleScope(wx)
