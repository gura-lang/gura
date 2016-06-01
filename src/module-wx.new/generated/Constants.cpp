#include "stdafx.h"

Gura_BeginModuleScope(wx)

void AssignConstants(Environment &env)
{
	// no-name enum
	Gura_AssignMacroValue(WX_ANY_VALUE_BUFFER_SIZE);
	// wxAccObject
	#if 0
	Gura_AssignWxValue(OBJID_WINDOW);
	Gura_AssignWxValue(OBJID_SYSMENU);
	Gura_AssignWxValue(OBJID_TITLEBAR);
	Gura_AssignWxValue(OBJID_MENU);
	Gura_AssignWxValue(OBJID_CLIENT);
	Gura_AssignWxValue(OBJID_VSCROLL);
	Gura_AssignWxValue(OBJID_HSCROLL);
	Gura_AssignWxValue(OBJID_SIZEGRIP);
	Gura_AssignWxValue(OBJID_CARET);
	Gura_AssignWxValue(OBJID_CURSOR);
	Gura_AssignWxValue(OBJID_ALERT);
	Gura_AssignWxValue(OBJID_SOUND);
	#endif
	// wxAccRole
	#if 0
	Gura_AssignWxValue(ROLE_NONE);
	Gura_AssignWxValue(ROLE_SYSTEM_ALERT);
	Gura_AssignWxValue(ROLE_SYSTEM_ANIMATION);
	Gura_AssignWxValue(ROLE_SYSTEM_APPLICATION);
	Gura_AssignWxValue(ROLE_SYSTEM_BORDER);
	Gura_AssignWxValue(ROLE_SYSTEM_BUTTONDROPDOWN);
	Gura_AssignWxValue(ROLE_SYSTEM_BUTTONDROPDOWNGRID);
	Gura_AssignWxValue(ROLE_SYSTEM_BUTTONMENU);
	Gura_AssignWxValue(ROLE_SYSTEM_CARET);
	Gura_AssignWxValue(ROLE_SYSTEM_CELL);
	Gura_AssignWxValue(ROLE_SYSTEM_CHARACTER);
	Gura_AssignWxValue(ROLE_SYSTEM_CHART);
	Gura_AssignWxValue(ROLE_SYSTEM_CHECKBUTTON);
	Gura_AssignWxValue(ROLE_SYSTEM_CLIENT);
	Gura_AssignWxValue(ROLE_SYSTEM_CLOCK);
	Gura_AssignWxValue(ROLE_SYSTEM_COLUMN);
	Gura_AssignWxValue(ROLE_SYSTEM_COLUMNHEADER);
	Gura_AssignWxValue(ROLE_SYSTEM_COMBOBOX);
	Gura_AssignWxValue(ROLE_SYSTEM_CURSOR);
	Gura_AssignWxValue(ROLE_SYSTEM_DIAGRAM);
	Gura_AssignWxValue(ROLE_SYSTEM_DIAL);
	Gura_AssignWxValue(ROLE_SYSTEM_DIALOG);
	Gura_AssignWxValue(ROLE_SYSTEM_DOCUMENT);
	Gura_AssignWxValue(ROLE_SYSTEM_DROPLIST);
	Gura_AssignWxValue(ROLE_SYSTEM_EQUATION);
	Gura_AssignWxValue(ROLE_SYSTEM_GRAPHIC);
	Gura_AssignWxValue(ROLE_SYSTEM_GRIP);
	Gura_AssignWxValue(ROLE_SYSTEM_GROUPING);
	Gura_AssignWxValue(ROLE_SYSTEM_HELPBALLOON);
	Gura_AssignWxValue(ROLE_SYSTEM_HOTKEYFIELD);
	Gura_AssignWxValue(ROLE_SYSTEM_INDICATOR);
	Gura_AssignWxValue(ROLE_SYSTEM_LINK);
	Gura_AssignWxValue(ROLE_SYSTEM_LIST);
	Gura_AssignWxValue(ROLE_SYSTEM_LISTITEM);
	Gura_AssignWxValue(ROLE_SYSTEM_MENUBAR);
	Gura_AssignWxValue(ROLE_SYSTEM_MENUITEM);
	Gura_AssignWxValue(ROLE_SYSTEM_MENUPOPUP);
	Gura_AssignWxValue(ROLE_SYSTEM_OUTLINE);
	Gura_AssignWxValue(ROLE_SYSTEM_OUTLINEITEM);
	Gura_AssignWxValue(ROLE_SYSTEM_PAGETAB);
	Gura_AssignWxValue(ROLE_SYSTEM_PAGETABLIST);
	Gura_AssignWxValue(ROLE_SYSTEM_PANE);
	Gura_AssignWxValue(ROLE_SYSTEM_PROGRESSBAR);
	Gura_AssignWxValue(ROLE_SYSTEM_PROPERTYPAGE);
	Gura_AssignWxValue(ROLE_SYSTEM_PUSHBUTTON);
	Gura_AssignWxValue(ROLE_SYSTEM_RADIOBUTTON);
	Gura_AssignWxValue(ROLE_SYSTEM_ROW);
	Gura_AssignWxValue(ROLE_SYSTEM_ROWHEADER);
	Gura_AssignWxValue(ROLE_SYSTEM_SCROLLBAR);
	Gura_AssignWxValue(ROLE_SYSTEM_SEPARATOR);
	Gura_AssignWxValue(ROLE_SYSTEM_SLIDER);
	Gura_AssignWxValue(ROLE_SYSTEM_SOUND);
	Gura_AssignWxValue(ROLE_SYSTEM_SPINBUTTON);
	Gura_AssignWxValue(ROLE_SYSTEM_STATICTEXT);
	Gura_AssignWxValue(ROLE_SYSTEM_STATUSBAR);
	Gura_AssignWxValue(ROLE_SYSTEM_TABLE);
	Gura_AssignWxValue(ROLE_SYSTEM_TEXT);
	Gura_AssignWxValue(ROLE_SYSTEM_TITLEBAR);
	Gura_AssignWxValue(ROLE_SYSTEM_TOOLBAR);
	Gura_AssignWxValue(ROLE_SYSTEM_TOOLTIP);
	Gura_AssignWxValue(ROLE_SYSTEM_WHITESPACE);
	Gura_AssignWxValue(ROLE_SYSTEM_WINDOW);
	#endif
	// wxAccSelectionFlags
	#if 0
	Gura_AssignWxValue(ACC_SEL_NONE);
	Gura_AssignWxValue(ACC_SEL_TAKEFOCUS);
	Gura_AssignWxValue(ACC_SEL_TAKESELECTION);
	Gura_AssignWxValue(ACC_SEL_EXTENDSELECTION);
	Gura_AssignWxValue(ACC_SEL_ADDSELECTION);
	Gura_AssignWxValue(ACC_SEL_REMOVESELECTION);
	#endif
	// wxAccStatus
	#if 0
	Gura_AssignWxValue(ACC_FAIL);
	Gura_AssignWxValue(ACC_FALSE);
	Gura_AssignWxValue(ACC_OK);
	Gura_AssignWxValue(ACC_NOT_IMPLEMENTED);
	Gura_AssignWxValue(ACC_NOT_SUPPORTED);
	#endif
	// wxAcceleratorEntryFlags
	Gura_AssignWxValue(ACCEL_NORMAL);
	Gura_AssignWxValue(ACCEL_ALT);
	Gura_AssignWxValue(ACCEL_CTRL);
	Gura_AssignWxValue(ACCEL_SHIFT);
	Gura_AssignWxValue(ACCEL_RAW_CTRL);
	Gura_AssignWxValue(ACCEL_CMD);
	// wxAnimationType
	#if 0
	Gura_AssignWxValue(ANIMATION_TYPE_INVALID);
	Gura_AssignWxValue(ANIMATION_TYPE_GIF);
	Gura_AssignWxValue(ANIMATION_TYPE_ANI);
	Gura_AssignWxValue(ANIMATION_TYPE_ANY);
	#endif
	// wxNavDir
	#if 0
	Gura_AssignWxValue(NAVDIR_DOWN);
	Gura_AssignWxValue(NAVDIR_FIRSTCHILD);
	Gura_AssignWxValue(NAVDIR_LASTCHILD);
	Gura_AssignWxValue(NAVDIR_LEFT);
	Gura_AssignWxValue(NAVDIR_NEXT);
	Gura_AssignWxValue(NAVDIR_PREVIOUS);
	Gura_AssignWxValue(NAVDIR_RIGHT);
	Gura_AssignWxValue(NAVDIR_UP);
	#endif
}

Gura_EndModuleScope(wx)
