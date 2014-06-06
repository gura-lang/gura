#ifndef __STDAFX_H__
#define __STDAFX_H__
#include <gura.h>
#define LPCTSTR LPCWSTR
#define LPFINDREPLACE LPFINDREPLACEW
#include <wx/wx.h>
#include <wx/aui/aui.h>
#include <wx/aboutdlg.h>
#include <wx/accel.h>
#include <wx/access.h>
#include <wx/event.h>
#include <wx/animate.h>
#include <wx/app.h>
#include <wx/apptrait.h>
#include <wx/archive.h>
#include <wx/dynarray.h>
#include <wx/arrstr.h>
#include <wx/artprov.h>
#include <wx/aui/dockart.h>
#include <wx/aui/auibook.h>
#include <wx/aui/aui.h>
#include <wx/bitmap.h>
#include <wx/bmpcbox.h>
#include <wx/bmpbuttn.h>
#include <wx/dataobj.h>
#include <wx/sizer.h>
#include <wx/brush.h>
#include <wx/gdicmn.h>
#include <wx/dcbuffer.h>
#include <wx/stream.h>
#include <wx/utils.h>
#include <wx/busyinfo.h>
#include <wx/button.h>
#include <wx/laywin.h>
#include <wx/calctrl.h>
#include <wx/caret.h>
#include <wx/checkbox.h>
#include <wx/checklst.h>
#include <wx/choice.h>
#include <wx/choicebk.h>
#include <wx/object.h>
#include <wx/ipc.h>
#include <wx/dcclient.h>
#include <wx/clntdata.h>
#include <wx/clipbrd.h>
#include <wx/cmdline.h>
#include <wx/collpane.h>
#include <wx/colour.h>
#include <wx/cmndata.h>
#include <wx/colordlg.h>
#include <wx/clrpicker.h>
#include <wx/combobox.h>
#include <wx/combo.h>
#include <wx/cmdproc.h>
#include <wx/config.h>
#include <wx/cshelp.h>
#include <wx/control.h>
#include <wx/ctrlsub.h>
#include <wx/strconv.h>
#include <wx/cursor.h>
#include <wx/socket.h>
#include <wx/datstrm.h>
#include <wx/dataview.h>
#include <wx/dateevt.h>
#include <wx/datectrl.h>
#include <wx/datetime.h>
//#include <wx/db.h>
//#include <wx/dbtable.h>
//#include <wx/dbgrid.h>
#include <wx/dc.h>
#include <wx/memory.h>
#include <wx/debugrpt.h>
#include <wx/renderer.h>
#include <wx/dialog.h>
#include <wx/dialup.h>
#include <wx/dir.h>
#include <wx/dirdlg.h>
#include <wx/filepicker.h>
#include <wx/display.h>
#include <wx/dynlib.h>
#include <wx/docview.h>
#include <wx/docmdi.h>
#include <wx/dragimag.h>
#include <wx/dnd.h>
#include <wx/encconv.h>
#include <wx/ffile.h>
#include <wx/wfstream.h>
#include <wx/file.h>
#include <wx/fileconf.h>
#include <wx/filedlg.h>
#include <wx/filename.h>
#include <wx/filesys.h>
#include <wx/mimetype.h>
#include <wx/fdrepdlg.h>
#include <wx/font.h>
#include <wx/fontdlg.h>
#include <wx/fontenum.h>
#include <wx/fontmap.h>
#include <wx/fontpicker.h>
#include <wx/frame.h>
#include <wx/protocol/ftp.h>
#include <wx/gauge.h>
#include <wx/gbsizer.h>
#include <wx/gdiobj.h>
#include <wx/dirctrl.h>
#include <wx/valgen.h>
#include <wx/glcanvas.h>
#include <wx/graphics.h>
#include <wx/grid.h>
#include <wx/generic/gridctrl.h>
#include <wx/hashmap.h>
#include <wx/hashset.h>
#include <wx/hash.h>
#include <wx/help.h>
#include <wx/html/htmlcell.h>
#include <wx/html/htmprint.h>
#include <wx/html/htmlfilt.h>
#include <wx/html/helpctrl.h>
#include <wx/html/helpdata.h>
#include <wx/html/helpdlg.h>
#include <wx/html/helpfrm.h>
#include <wx/html/helpwnd.h>
#include <wx/htmllbox.h>
#include <wx/html/htmlpars.h>
#include <wx/html/htmltag.h>
#include <wx/html/winpars.h>
#include <wx/html/htmlwin.h>
#include <wx/protocol/http.h>
#include <wx/hyperlink.h>
#include <wx/icon.h>
#include <wx/iconloc.h>
#include <wx/image.h>
#include <wx/imaglist.h>
#include <wx/layout.h>
#include <wx/joystick.h>
#include <wx/list.h>
#include <wx/listbook.h>
#include <wx/listbox.h>
#include <wx/listctrl.h>
#include <wx/intl.h>
#include <wx/log.h>
#include <wx/longlong.h>
#include <wx/mdi.h>
#include <wx/mediactrl.h>
#include <wx/buffer.h>
#include <wx/dcmemory.h>
#include <wx/fs_mem.h>
#include <wx/mstream.h>
#include <wx/menu.h>
#include <wx/menuitem.h>
#include <wx/msgdlg.h>
#include <wx/metafile.h>
#include <wx/minifram.h>
#include <wx/dcmirror.h>
#include <wx/module.h>
#include <wx/choicdlg.h>
#include <wx/notebook.h>
#include <wx/odcombo.h>
#include <wx/printdlg.h>
#include <wx/palette.h>
#include <wx/panel.h>
#include <wx/textdlg.h>
#include <wx/filefn.h>
#include <wx/pen.h>
#include <wx/pickerbase.h>
#include <wx/platinfo.h>
#include <wx/dcps.h>
#include <wx/power.h>
#include <wx/print.h>
#include <wx/dcprint.h>
#include <wx/process.h>
#include <wx/progdlg.h>
#include <wx/propdlg.h>
#include <wx/protocol/protocol.h>
#include <wx/quantize.h>
#include <wx/radiobox.h>
#include <wx/radiobut.h>
#include <wx/recguard.h>
#include <wx/regex.h>
#include <wx/region.h>
#include <wx/richtext/richtextbuffer.h>
#include <wx/richtext/richtextstyles.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/richtext/richtextformatdlg.h>
#include <wx/richtext/richtextprint.h>
#include <wx/richtext/richtexthtml.h>
#include <wx/richtext/richtextstyledlg.h>
#include <wx/richtext/richtextxml.h>
#include <wx/sashwin.h>
#include <wx/ptr_scpd.h>
#include <wx/dcscreen.h>
#include <wx/scrolbar.h>
#include <wx/scrolwin.h>
#include <wx/srchctrl.h>
#include <wx/snglinst.h>
#include <wx/slider.h>
#include <wx/sckstrm.h>
#include <wx/sound.h>
#include <wx/spinbutt.h>
#include <wx/spinctrl.h>
#include <wx/splash.h>
#include <wx/splitter.h>
#include <wx/stackwalk.h>
#include <wx/stdpaths.h>
#include <wx/statbmp.h>
#include <wx/statbox.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/stopwatch.h>
#include <wx/textctrl.h>
#include <wx/stc/stc.h>
#include <wx/string.h>
#include <wx/sstream.h>
#include <wx/tokenzr.h>
#include <wx/richtext/richtextsymboldlg.h>
#include <wx/sysopt.h>
#include <wx/settings.h>
#include <wx/tarstrm.h>
#include <wx/taskbar.h>
#include <wx/sckipc.h>
#include <wx/textfile.h>
#include <wx/txtstrm.h>
#include <wx/valtext.h>
#include <wx/timer.h>
#include <wx/tipdlg.h>
#include <wx/tipwin.h>
#include <wx/tglbtn.h>
#include <wx/toolbar.h>
#include <wx/toolbook.h>
#include <wx/tooltip.h>
#include <wx/toplevel.h>
#include <wx/treebook.h>
#include <wx/treectrl.h>
#include <wx/treebase.h>
#include <wx/uri.h>
#include <wx/url.h>
#include <wx/validate.h>
#include <wx/variant.h>
#include <wx/vlbox.h>
#include <wx/vscroll.h>
#include <wx/window.h>
#include <wx/wupdlock.h>
#include <wx/wizard.h>
#include <wx/xml/xml.h>
#include <wx/xrc/xmlres.h>
#include <wx/zipstrm.h>
#if defined(__WXMSW__)
#include <wx/thread.h>
#include <wx/dde.h>
#include <wx/msw/registry.h>
#include <wx/msw/ole/activex.h>
#include <wx/msw/ole/automtn.h>
#endif
#include <wx/numdlg.h>
#include <wx/stockitem.h>
#include <wx/zstream.h>

#include "module-wx.h"
#include "Class_wx_AboutDialogInfo.h"
#include "Class_wx_LanguageInfo.h"
#include "Class_wx_MouseState.h"
#include "Class_wx_AcceleratorEntry.h"
#include "Class_wx_AppTraits.h"
#include "Class_wx_AuiDockArt.h"
#include "Class_wx_AuiTabArt.h"
#include "Class_wx_AuiPaneInfo.h"
#include "Class_wx_List.h"
#include "Class_wx_BusyCursor.h"
#include "Class_wx_BusyInfo.h"
#include "Class_wx_CalendarDateAttr.h"
#include "Class_wx_Caret.h"
#include "Class_wx_ClassInfo.h"
#include "Class_wx_ClientData.h"
#include "Class_wx_TreeItemData.h"						// derived from wxClientData
#include "Class_wx_ClientDataContainer.h"
#include "Class_wx_CmdLineParser.h"
#include "Class_wx_ColourDatabase.h"
#include "Class_wx_ComboPopup.h"
#include "Class_wx_Condition.h"
#include "Class_wx_ConfigBase.h"
#include "Class_wx_FileConfig.h"						// derived from wxConfigBase
#include "Class_wx_CriticalSection.h"
#include "Class_wx_CriticalSectionLocker.h"
#include "Class_wx_DataFormat.h"
#include "Class_wx_DataObject.h"
#include "Class_wx_DataObjectSimple.h"					// derived from wxDataObject
#include "Class_wx_BitmapDataObject.h"					// derived from wxDataObjectSimple
#include "Class_wx_CustomDataObject.h"					// derived from wxDataObjectSimple
#include "Class_wx_FileDataObject.h"					// derived from wxDataObjectSimple
#include "Class_wx_TextDataObject.h"					// derived from wxDataObjectSimple
#include "Class_wx_DateSpan.h"
#include "Class_wx_DateTime.h"
#include "Class_wx_DateTimeHolidayAuthority.h"
#include "Class_wx_DateTimeWorkDays.h"
//#include "Class_wx_Db.h"
//#include "Class_wx_DbColDataPtr.h"
//#include "Class_wx_DbColDef.h"
//#include "Class_wx_DbColFor.h"
//#include "Class_wx_DbColInf.h"
//#include "Class_wx_DbConnectInf.h"
//#include "Class_wx_DbIdxDef.h"
//#include "Class_wx_DbInf.h"
//#include "Class_wx_DbTable.h"
//#include "Class_wx_DbTableInf.h"
#include "Class_wx_DCClipper.h"
#include "Class_wx_DebugReport.h"
#include "Class_wx_DebugReportCompress.h"				// derived from wxDebugReport
#include "Class_wx_DebugReportUpload.h"					// derived from wxDebugReportCompress
#include "Class_wx_DebugReportPreview.h"
#include "Class_wx_DebugReportPreviewStd.h"				// derived from wxDebugReportPreview
#include "Class_wx_DialUpManager.h"
#include "Class_wx_Dir.h"
#include "Class_wx_DirTraverser.h"
#include "Class_wx_Display.h"
#include "Class_wx_DropSource.h"
#include "Class_wx_DropTarget.h"
#include "Class_wx_FileDropTarget.h"					// derived from wxDropTarget
#include "Class_wx_TextDropTarget.h"					// derived from wxDropTarget
#include "Class_wx_DynamicLibrary.h"
#include "Class_wx_DynamicLibraryDetails.h"
#include "Class_wx_FFile.h"
#include "Class_wx_File.h"
#include "Class_wx_FileName.h"
#include "Class_wx_FileType.h"
#include "Class_wx_FontEnumerator.h"
#include "Class_wx_FontMapper.h"
#include "Class_wx_GBPosition.h"
#include "Class_wx_GBSpan.h"
#include "Class_wx_GridCellAttr.h"
#include "Class_wx_GridCellWorker.h"
#include "Class_wx_GridCellEditor.h"					// derived from wxGridCellWorker
#include "Class_wx_GridCellBoolEditor.h"				// derived from wxGridCellEditor
#include "Class_wx_GridCellChoiceEditor.h"				// derived from wxGridCellEditor
#include "Class_wx_GridCellTextEditor.h"				// derived from wxGridCellEditor
#include "Class_wx_GridCellFloatEditor.h"				// derived from wxGridCellTextEditor
#include "Class_wx_GridCellNumberEditor.h"				// derived from wxGridCellTextEditor
#include "Class_wx_GridCellAutoWrapStringEditor.h"		// derived from wxGridCellTextEditor
#include "Class_wx_GridCellRenderer.h"					// derived from wxGridCellWorker
#include "Class_wx_GridCellBoolRenderer.h"				// derived from wxGridCellRenderer
#include "Class_wx_GridCellStringRenderer.h"			// derived from wxGridCellRenderer
#include "Class_wx_GridCellFloatRenderer.h"				// derived from wxGridCellStringRenderer
#include "Class_wx_GridCellStringRenderer.h"
#include "Class_wx_GridCellNumberRenderer.h"			// derived from wxGridCellStringRenderer
#include "Class_wx_GridCellAutoWrapStringRenderer.h"	// derived from wxGridCellStringRenderer
#include "Class_wx_HelpProvider.h"
#include "Class_wx_SimpleHelpProvider.h"				// derived from wxHelpProvider
#include "Class_wx_HelpControllerHelpProvider.h"		// derived from wxSimpleHelpProvider
#include "Class_wx_HtmlModalHelp.h"
#include "Class_wx_IconBundle.h"
#include "Class_wx_IconLocation.h"
#include "Class_wx_ListItemAttr.h"
#include "Class_wx_Locale.h"
#include "Class_wx_Log.h"
#include "Class_wx_LogChain.h"							// derived from wxLog
#include "Class_wx_LogPassThrough.h"					// derived from wxLogChain
#include "Class_wx_LogWindow.h"							// derived from wxLogPassThrough
#include "Class_wx_LogGui.h"							// derived from wxLog
#include "Class_wx_LogStderr.h"							// derived from wxLog
#include "Class_wx_LogTextCtrl.h"						// derived from wxLog
#include "Class_wx_LongLong.h"
#include "Class_wx_MBConv.h"
#include "Class_wx_CSConv.h"							// derived from wxMBConv
#include "Class_wx_MBConvUTF7.h"						// derived from wxMBConv
#include "Class_wx_MBConvUTF8.h"						// derived from wxMBConv
#include "Class_wx_MBConvUTF16.h"						// derived from wxMBConv
#include "Class_wx_MBConvUTF32.h"						// derived from wxMBConv
#include "Class_wx_MemoryBuffer.h"
#include "Class_wx_MimeTypesManager.h"
#include "Class_wx_Mutex.h"
#include "Class_wx_MutexLocker.h"
#include "Class_wx_Node.h"
#include "Class_wx_Object.h"
#include "Class_wx_ConnectionBase.h"					// derived from wxObject
#include "Class_wx_Connection.h"						// derived from wxConnectionBase
#include "Class_wx_TCPConnection.h"						// derived from wxConnectionBase
#include "Class_wx_HelpControllerBase.h"				// derived from wxObject
#include "Class_wx_HelpController.h"					// derived from wxHelpControllerBase
#include "Class_wx_HtmlHelpController.h"				// derived from wxHelpControllerBase
#include "Class_wx_ServerBase.h"						// derived from wxObject
#include "Class_wx_Server.h"							// derived from wxServerBase
#include "Class_wx_TCPServer.h"							// derived from wxServerBase
#include "Class_wx_ClientBase.h"						// derived from wxObject
#include "Class_wx_Client.h"							// derived from wxClientBase
#include "Class_wx_TCPClient.h"							// derived from wxClientBase
#include "Class_wx_AcceleratorTable.h"					// derived from wxObject
#include "Class_wx_ArchiveClassFactory.h"				// derived from wxObject
#include "Class_wx_TarClassFactory.h"					// derived from wxArchiveClassFactory
#include "Class_wx_ZipClassFactory.h"					// derived from wxArchiveClassFactory
#include "Class_wx_ArchiveEntry.h"						// derived from wxObject
#include "Class_wx_TarEntry.h"							// derived from wxArchiveEntry
#include "Class_wx_ZipEntry.h"							// derived from wxArchiveEntry
#include "Class_wx_ArtProvider.h"						// derived from wxObject
#include "Class_wx_BitmapHandler.h"						// derived from wxObject
#include "Class_wx_Clipboard.h"							// derived from wxObject
#include "Class_wx_Colour.h"							// derived from wxObject
#include "Class_wx_ColourData.h"						// derived from wxObject
#include "Class_wx_Command.h"							// derived from wxObject
#include "Class_wx_CommandProcessor.h"					// derived from wxObject
#include "Class_wx_ContextHelp.h"						// derived from wxObject
#include "Class_wx_DC.h"								// derived from wxObject
#include "Class_wx_MemoryDC.h"							// derived from wxDC
#include "Class_wx_BufferedDC.h"						// derived from wxMemoryDC
#include "Class_wx_BufferedPaintDC.h"					// derived from wxBufferedDC
#include "Class_wx_AutoBufferedPaintDC.h"				// derived from wxDC (to keep compatibility between Windows and Linux)
#include "Class_wx_MirrorDC.h"							// derived from wxDC
#include "Class_wx_ScreenDC.h"							// derived from wxDC
#include "Class_wx_WindowDC.h"							// derived from wxDC
#include "Class_wx_ClientDC.h"							// derived from wxWindowDC
#include "Class_wx_PaintDC.h"							// derived from wxWindowDC
#include "Class_wx_DocTemplate.h"						// derived from wxObject
#include "Class_wx_DragImage.h"							// derived from wxObject
#include "Class_wx_EncodingConverter.h"					// derived from wxObject
#include "Class_wx_Event.h"								// derived from wxObject
#include "Class_wx_ActivateEvent.h"						// derived from wxEvent
#include "Class_wx_CalculateLayoutEvent.h"				// derived from wxEvent
#include "Class_wx_CloseEvent.h"						// derived from wxEvent
#include "Class_wx_CommandEvent.h"						// derived from wxEvent
#include "Class_wx_ClipboardTextEvent.h"				// derived from wxCommandEvent
#include "Class_wx_CollapsiblePaneEvent.h"				// derived from wxCommandEvent
#include "Class_wx_ColourPickerEvent.h"					// derived from wxCommandEvent
#include "Class_wx_ChildFocusEvent.h"					// derived from wxCommandEvent
#include "Class_wx_ContextMenuEvent.h"					// derived from wxCommandEvent
#include "Class_wx_DateEvent.h"							// derived from wxCommandEvent
#include "Class_wx_CalendarEvent.h"						// derived from wxDateEvent
#include "Class_wx_FileDirPickerEvent.h"				// derived from wxCommandEvent
#include "Class_wx_FindDialogEvent.h"					// derived from wxCommandEvent
#include "Class_wx_FontPickerEvent.h"					// derived from wxCommandEvent
#include "Class_wx_HelpEvent.h"							// derived from wxCommandEvent
#include "Class_wx_HtmlLinkEvent.h"						// derived from wxCommandEvent
#include "Class_wx_HtmlCellEvent.h"						// derived from wxCommandEvent
#include "Class_wx_HyperlinkEvent.h"					// derived from wxCommandEvent
#include "Class_wx_NotifyEvent.h"						// derived from wxCommandEvent
#include "Class_wx_BookCtrlBaseEvent.h"					// derived from wxNotifyEvent
#include "Class_wx_TreebookEvent.h"						// derived from wxBookCtrlBaseEvent
#include "Class_wx_GridEvent.h"							// derived from wxNotifyEvent
#include "Class_wx_GridRangeSelectEvent.h"				// derived from wxNotifyEvent
#include "Class_wx_GridSizeEvent.h"						// derived from wxNotifyEvent
#include "Class_wx_ListEvent.h"							// derived from wxNotifyEvent
#include "Class_wx_NotebookEvent.h"						// derived from wxBookCtrlBaseEvent
#include "Class_wx_ListbookEvent.h"						// derived from wxBookCtrlBaseEvent
#include "Class_wx_ChoicebookEvent.h"					// derived from wxBookCtrlBaseEvent
#include "Class_wx_ToolbookEvent.h"						// derived from wxBookCtrlBaseEvent
#include "Class_wx_RichTextEvent.h"						// derived from wxNotifyEvent
#include "Class_wx_SpinEvent.h"							// derived from wxNotifyEvent
#include "Class_wx_SplitterEvent.h"						// derived from wxNotifyEvent
#include "Class_wx_TreeEvent.h"							// derived from wxNotifyEvent
#include "Class_wx_WizardEvent.h"						// derived from wxNotifyEvent
#include "Class_wx_SashEvent.h"							// derived from wxCommandEvent
#include "Class_wx_ScrollEvent.h"						// derived from wxCommandEvent
#include "Class_wx_StyledTextEvent.h"					// derived from wxCommandEvent
#include "Class_wx_UpdateUIEvent.h"						// derived from wxCommandEvent
#include "Class_wx_WindowCreateEvent.h"					// derived from wxCommandEvent
#include "Class_wx_WindowDestroyEvent.h"				// derived from wxCommandEvent
#include "Class_wx_DialUpEvent.h"						// derived from wxEvent
#include "Class_wx_DropFilesEvent.h"					// derived from wxEvent
#include "Class_wx_EraseEvent.h"						// derived from wxEvent
#include "Class_wx_FocusEvent.h"						// derived from wxEvent
#include "Class_wx_GridEditorCreatedEvent.h"			// derived from wxEvent
#include "Class_wx_IconizeEvent.h"						// derived from wxEvent
#include "Class_wx_IdleEvent.h"							// derived from wxEvent
#include "Class_wx_InitDialogEvent.h"					// derived from wxEvent
#include "Class_wx_JoystickEvent.h"						// derived from wxEvent
#include "Class_wx_KeyEvent.h"							// derived from wxEvent
#include "Class_wx_MaximizeEvent.h"						// derived from wxEvent
#include "Class_wx_MenuEvent.h"							// derived from wxEvent
#include "Class_wx_MouseCaptureChangedEvent.h"			// derived from wxEvent
#include "Class_wx_MouseCaptureLostEvent.h"				// derived from wxEvent
#include "Class_wx_MouseEvent.h"						// derived from wxEvent
#include "Class_wx_MoveEvent.h"							// derived from wxEvent
#include "Class_wx_PaintEvent.h"						// derived from wxEvent
#include "Class_wx_ProcessEvent.h"						// derived from wxEvent
#include "Class_wx_QueryLayoutInfoEvent.h"				// derived from wxEvent
#include "Class_wx_ScrollWinEvent.h"					// derived from wxEvent
#include "Class_wx_SetCursorEvent.h"					// derived from wxEvent
#include "Class_wx_ShowEvent.h"							// derived from wxEvent
#include "Class_wx_SizeEvent.h"							// derived from wxEvent
#include "Class_wx_SocketEvent.h"						// derived from wxEvent
#include "Class_wx_SysColourChangedEvent.h"				// derived from wxEvent
#include "Class_wx_TimerEvent.h"						// derived from wxEvent
#include "Class_wx_EvtHandler.h"						// derived from wxObject
#include "Class_wx_App.h"								// derived from wxEvtHandler
#include "Class_wx_AuiManager.h"						// derived from wxEvtHandler
#include "Class_wx_DocManager.h"						// derived from wxEvtHandler
#include "Class_wx_Document.h"							// derived from wxEvtHandler
#include "Class_wx_Menu.h"								// derived from wxEvtHandler
#include "Class_wx_Process.h"							// derived from wxEvtHandler
#include "Class_wx_TaskBarIcon.h"						// derived from wxEvtHandler
#include "Class_wx_Timer.h"								// derived from wxEvtHandler
#include "Class_wx_Validator.h"							// derived from wxEvtHandler
#include "Class_wx_GenericValidator.h"					// derived from wxValidator
#include "Class_wx_TextValidator.h"						// derived from wxValidator
#include "Class_wx_View.h"								// derived from wxEvtHandler
#include "Class_wx_Window.h"							// derived from wxEvtHandler
#include "Class_wx_PopupWindow.h"						// derived from wxWindow
#include "Class_wx_PopupTransientWindow.h"				// derived from wxPopupWindow
#include "Class_wx_TipWindow.h"							// derived from wxPopupTransientWindow
#include "Class_wx_Control.h"							// derived from wxWindow
#include "Class_wx_TextCtrlBase.h"						// derived from wxControl
#include "Class_wx_RichTextCtrl.h"						// derived from wxControl
#include "Class_wx_BookCtrlBase.h"						// derived from wxControl
#include "Class_wx_Choicebook.h"						// derived from wxBookCtrlBase
#include "Class_wx_Toolbook.h"							// derived from wxBookCtrlBase
#include "Class_wx_Treebook.h"							// derived from wxBookCtrlBase
#include "Class_wx_ToolBarBase.h"						// derived from wxControl
#include "Class_wx_ToolBar.h"							// derived from wxToolBarBase
#include "Class_wx_AnimationCtrl.h"						// derived from wxControl
#include "Class_wx_AuiNotebook.h"						// derived from wxControl
#include "Class_wx_Button.h"							// derived from wxControl
#include "Class_wx_BitmapButton.h"						// derived from wxButton
#include "Class_wx_ContextHelpButton.h"					// derived from wxBitmapButton
#include "Class_wx_CalendarCtrl.h"						// derived from wxControl
#include "Class_wx_CheckBox.h"							// derived from wxControl
#include "Class_wx_CollapsiblePane.h"					// derived from wxControl
#include "Class_wx_ComboCtrl.h"							// derived from wxControl
#include "Class_wx_OwnerDrawnComboBox.h"				// derived from wxComboCtrl
#include "Class_wx_RichTextStyleComboCtrl.h"			// derived from wxComboCtrl
#include "Class_wx_ControlWithItems.h"					// derived from wxControl
#include "Class_wx_Choice.h"							// derived from wxControlWithItems
#include "Class_wx_ComboBox.h"							// derived from wxControlWithItems
#include "Class_wx_BitmapComboBox.h"					// derived from wxComboBox
#include "Class_wx_ListBox.h"							// derived from wxControlWithItems
#include "Class_wx_CheckListBox.h"						// derived from wxListBox
#include "Class_wx_DatePickerCtrl.h"					// derived from wxControl
#include "Class_wx_Gauge.h"								// derived from wxControl
#include "Class_wx_GenericDirCtrl.h"					// derived from wxControl
#include "Class_wx_HyperlinkCtrl.h"						// derived from wxControl
#include "Class_wx_Listbook.h"							// derived from wxControl
#include "Class_wx_ListCtrl.h"							// derived from wxControl
#include "Class_wx_ListView.h"							// derived from wxListCtrl
#include "Class_wx_Notebook.h"							// derived from wxControl
#include "Class_wx_PickerBase.h"						// derived from wxControl
#include "Class_wx_ColourPickerCtrl.h"					// derived from wxPickerBase
#include "Class_wx_DirPickerCtrl.h"						// derived from wxPickerBase
#include "Class_wx_FilePickerCtrl.h"					// derived from wxPickerBase
#include "Class_wx_FontPickerCtrl.h"					// derived from wxPickerBase
#include "Class_wx_RadioBox.h"							// derived from wxControl
#include "Class_wx_RadioButton.h"						// derived from wxControl
#include "Class_wx_RichTextStyleListCtrl.h"				// derived from wxControl
#include "Class_wx_ScrollBar.h"							// derived from wxControl
#include "Class_wx_Slider.h"							// derived from wxControl
#include "Class_wx_SpinButton.h"						// derived from wxControl
#include "Class_wx_SpinCtrl.h"							// derived from wxControl
#include "Class_wx_StaticBitmap.h"						// derived from wxControl
#include "Class_wx_StaticBox.h"							// derived from wxControl
#include "Class_wx_StaticLine.h"						// derived from wxControl
#include "Class_wx_StaticText.h"						// derived from wxControl
#include "Class_wx_TextCtrl.h"							// derived from wxControl
#include "Class_wx_StyledTextCtrl.h"					// derived from wxControl
#include "Class_wx_ToggleButton.h"						// derived from wxControl
#include "Class_wx_TreeCtrl.h"							// derived from wxControl
#include "Class_wx_GLCanvas.h"							// derived from wxWindow
#include "Class_wx_HtmlHelpDialog.h"					// derived from wxWindow
#include "Class_wx_HtmlHelpWindow.h"					// derived from wxWindow
#include "Class_wx_MDIClientWindow.h"					// derived from wxWindow
#include "Class_wx_MenuBar.h"							// derived from wxWindow
#include "Class_wx_Panel.h"								// derived from wxWindow
#include "Class_wx_PreviewControlBar.h"					// derived from wxPanel
#include "Class_wx_ScrolledWindow.h"					// derived from wxPanel
#include "Class_wx_Grid.h"								// derived from wxScrolledWindow
#include "Class_wx_HtmlWindow.h"						// derived from wxScrolledWindow
#include "Class_wx_PreviewCanvas.h"						// derived from wxScrolledWindow
#include "Class_wx_VScrolledWindow.h"					// derived from wxPanel
#include "Class_wx_VListBox.h"							// derived from wxVScrolledWindow
#include "Class_wx_HtmlListBox.h"						// derived from wxVListBox
#include "Class_wx_SimpleHtmlListBox.h"					// derived from wxHtmlListBox
#include "Class_wx_RichTextStyleListBox.h"				// derived from wxHtmlListBox
#include "Class_wx_WizardPage.h"						// derived from wxPanel
#include "Class_wx_WizardPageSimple.h"					// derived from wxWizardPage
#include "Class_wx_SashWindow.h"						// derived from wxWindow
#include "Class_wx_SashLayoutWindow.h"					// derived from wxSashWindow
#include "Class_wx_SearchCtrl.h"						// derived from wxWindow
#include "Class_wx_SplitterWindow.h"					// derived from wxWindow
#include "Class_wx_StatusBar.h"							// derived from wxWindow
#include "Class_wx_TopLevelWindow.h"					// derived from wxWindow
#include "Class_wx_Dialog.h"							// derived from wxTopLevelWindow
#include "Class_wx_ColourDialog.h"						// derived from wxDialog
#include "Class_wx_DirDialog.h"							// derived from wxDialog
#include "Class_wx_FileDialog.h"						// derived from wxDialog
#include "Class_wx_FindReplaceDialog.h"					// derived from wxDialog
#include "Class_wx_FontDialog.h"						// derived from wxDialog
#include "Class_wx_MessageDialog.h"						// derived from wxDialog
#include "Class_wx_MultiChoiceDialog.h"					// derived from wxDialog
#include "Class_wx_ProgressDialog.h"					// derived from wxDialog
#include "Class_wx_PropertySheetDialog.h"				// derived from wxDialog
#include "Class_wx_RichTextFormattingDialog.h"			// derived from wxPropertySheetDialog
#include "Class_wx_RichTextStyleOrganiserDialog.h"		// derived from wxDialog
#include "Class_wx_SingleChoiceDialog.h"				// derived from wxDialog
#include "Class_wx_SymbolPickerDialog.h"				// derived from wxDialog
#include "Class_wx_TextEntryDialog.h"					// derived from wxDialog
#include "Class_wx_PasswordEntryDialog.h"				// derived from wxTextEntryDialog
#include "Class_wx_Wizard.h"							// derived from wxDialog
#include "Class_wx_Frame.h"								// derived from wxTopLevelWindow
#include "Class_wx_DocChildFrame.h"						// derived from wxFrame
#include "Class_wx_DocParentFrame.h"					// derived from wxFrame
#include "Class_wx_HtmlHelpFrame.h"						// derived from wxFrame
#include "Class_wx_MDIChildFrame.h"						// derived from wxFrame
#include "Class_wx_DocMDIChildFrame.h"					// derived from wxMDIChildFrame
#include "Class_wx_MDIParentFrame.h"					// derived from wxFrame
#include "Class_wx_DocMDIParentFrame.h"					// derived from wxMDIParentFrame
#include "Class_wx_MiniFrame.h"							// derived from wxFrame
#include "Class_wx_PreviewFrame.h"						// derived from wxFrame
#include "Class_wx_SplashScreen.h"						// derived from wxFrame
#include "Class_wx_FileHistory.h"						// derived from wxObject
#include "Class_wx_FileSystem.h"						// derived from wxObject
#include "Class_wx_FileSystemHandler.h"					// derived from wxObject
#include "Class_wx_MemoryFSHandler.h"					// derived from wxFileSystemHandler
#include "Class_wx_FilterClassFactory.h"				// derived from wxObject
#include "Class_wx_FindReplaceData.h"					// derived from wxObject
#include "Class_wx_FontData.h"							// derived from wxObject
#include "Class_wx_FSFile.h"							// derived from wxObject
#include "Class_wx_GDIObject.h"							// derived from wxObject
#include "Class_wx_Animation.h"							// derived from wxObject
#include "Class_wx_Bitmap.h"							// derived from wxGDIObject
#include "Class_wx_Brush.h"								// derived from wxGDIObject
#include "Class_wx_Cursor.h"							// derived from wxGDIObject
#include "Class_wx_Font.h"								// derived from wxGDIObject
#include "Class_wx_Icon.h"								// derived from wxGDIObject
#include "Class_wx_Palette.h"							// derived from wxGDIObject
#include "Class_wx_Pen.h"								// derived from wxGDIObject
#include "Class_wx_Region.h"							// derived from wxGDIObject
#include "Class_wx_GLContext.h"							// derived from wxObject
#include "Class_wx_GridTableBase.h"						// derived from wxObject
#include "Class_wx_HashTable.h"							// derived from wxObject
#include "Class_wx_HtmlCell.h"							// derived from wxObject
#include "Class_wx_HtmlColourCell.h"					// derived from wxHtmlCell
#include "Class_wx_HtmlContainerCell.h"					// derived from wxHtmlCell
#include "Class_wx_HtmlWidgetCell.h"					// derived from wxHtmlCell
#include "Class_wx_HtmlDCRenderer.h"					// derived from wxObject
#include "Class_wx_HtmlEasyPrinting.h"					// derived from wxObject
#include "Class_wx_HtmlFilter.h"						// derived from wxObject
#include "Class_wx_HtmlHelpData.h"						// derived from wxObject
#include "Class_wx_HtmlLinkInfo.h"						// derived from wxObject
#include "Class_wx_HtmlParser.h"						// derived from wxObject
#include "Class_wx_HtmlWinParser.h"						// derived from wxHtmlParser
#include "Class_wx_HtmlTag.h"							// derived from wxObject
#include "Class_wx_HtmlTagHandler.h"					// derived from wxObject
#include "Class_wx_HtmlWinTagHandler.h"					// derived from wxHtmlTagHandler
#include "Class_wx_Image.h"								// derived from wxObject
#include "Class_wx_ImageHandler.h"						// derived from wxObject
#include "Class_wx_ImageList.h"							// derived from wxObject
#include "Class_wx_IndividualLayoutConstraint.h"		// derived from wxObject
#include "Class_wx_Joystick.h"							// derived from wxObject
#include "Class_wx_LayoutAlgorithm.h"					// derived from wxObject
#include "Class_wx_LayoutConstraints.h"					// derived from wxObject
#include "Class_wx_ListItem.h"							// derived from wxObject
#include "Class_wx_Mask.h"								// derived from wxObject
#include "Class_wx_MenuItem.h"							// derived from wxObject
#include "Class_wx_Module.h"							// derived from wxObject
#include "Class_wx_HtmlTagsModule.h"					// derived from wxModule
#include "Class_wx_PageSetupDialog.h"					// derived from wxObject
#include "Class_wx_PageSetupDialogData.h"				// derived from wxObject
#include "Class_wx_PrintData.h"							// derived from wxObject
#include "Class_wx_PrintDialog.h"						// derived from wxObject
#include "Class_wx_PrintDialogData.h"					// derived from wxObject
#include "Class_wx_Printer.h"							// derived from wxObject
#include "Class_wx_Printout.h"							// derived from wxObject
#include "Class_wx_HtmlPrintout.h"						// derived from wxPrintout
#include "Class_wx_RichTextPrintout.h"					// derived from wxPrintout
#include "Class_wx_PrintPreview.h"						// derived from wxObject
#include "Class_wx_Quantize.h"							// derived from wxObject
#include "Class_wx_RegionIterator.h"					// derived from wxObject
#include "Class_wx_RichTextFileHandler.h"				// derived from wxObject
#include "Class_wx_RichTextHTMLHandler.h"				// derived from wxRichTextFileHandler
#include "Class_wx_RichTextXMLHandler.h"				// derived from wxRichTextFileHandler
#include "Class_wx_RichTextFormattingDialogFactory.h"	// derived from wxObject
#include "Class_wx_RichTextHeaderFooterData.h"			// derived from wxObject
#include "Class_wx_RichTextPrinting.h"					// derived from wxObject
#include "Class_wx_RichTextStyleDefinition.h"			// derived from wxObject
#include "Class_wx_RichTextCharacterStyleDefinition.h"	// derived from wxRichTextStyleDefinition
#include "Class_wx_RichTextParagraphStyleDefinition.h"	// derived from wxRichTextStyleDefinition
#include "Class_wx_RichTextListStyleDefinition.h"		// derived from wxRichTextParagraphStyleDefinition
#include "Class_wx_RichTextStyleSheet.h"				// derived from wxObject
#include "Class_wx_Sizer.h"								// derived from wxObject
#include "Class_wx_BoxSizer.h"							// derived from wxSizer
#include "Class_wx_StaticBoxSizer.h"					// derived from wxBoxSizer
#include "Class_wx_StdDialogButtonSizer.h"				// derived from wxBoxSizer
#include "Class_wx_GridSizer.h"							// derived from wxSizer
#include "Class_wx_FlexGridSizer.h"						// derived from wxGridSizer
#include "Class_wx_GridBagSizer.h"						// derived from wxFlexGridSizer
#include "Class_wx_SizerItem.h"							// derived from wxObject
#include "Class_wx_GBSizerItem.h"						// derived from wxSizerItem
#include "Class_wx_SockAddress.h"						// derived from wxObject
#include "Class_wx_IPaddress.h"							// derived from wxSockAddress
#include "Class_wx_IPV4address.h"						// derived from wxIPaddress
#include "Class_wx_SocketBase.h"						// derived from wxObject
#include "Class_wx_DatagramSocket.h"					// derived from wxSocketBase
#include "Class_wx_SocketClient.h"						// derived from wxSocketBase
#include "Class_wx_Protocol.h"							// derived from wxSocketClient
#include "Class_wx_FTP.h"								// derived from wxProtocol
#include "Class_wx_HTTP.h"								// derived from wxProtocol
#include "Class_wx_SocketServer.h"						// derived from wxSocketBase
#include "Class_wx_Sound.h"								// derived from wxObject
#include "Class_wx_StringTokenizer.h"					// derived from wxObject
#include "Class_wx_SystemOptions.h"						// derived from wxObject
#include "Class_wx_ToolTip.h"							// derived from wxObject
#include "Class_wx_URI.h"								// derived from wxObject
#include "Class_wx_URL.h"								// derived from wxURI
#include "Class_wx_Variant.h"							// derived from wxObject
#include "Class_wx_XmlDocument.h"						// derived from wxObject
#include "Class_wx_XmlResource.h"						// derived from wxObject
#include "Class_wx_XmlResourceHandler.h"				// derived from wxObject
#include "Class_wx_ObjectRefData.h"
#include "Class_wx_VariantData.h"						// derived from wxObjectRefData
#include "Class_wx_PenList.h"
#include "Class_wx_PlatformInfo.h"
#include "Class_wx_Point.h"
#include "Class_wx_RealPoint.h"
#include "Class_wx_Rect.h"
#include "Class_wx_RecursionGuard.h"
#include "Class_wx_RegEx.h"
#include "Class_wx_RendererNative.h"
#include "Class_wx_DelegateRendererNative.h"			// derived from wxRendererNative
#include "Class_wx_RendererVersion.h"
#include "Class_wx_RichTextAttr.h"
#include "Class_wx_RichTextParagraphLayoutBox.h"
#include "Class_wx_RichTextBuffer.h"					// derived from wxRichTextParagraphLayoutBox
#include "Class_wx_RichTextRange.h"
#include "Class_wx_Semaphore.h"
#include "Class_wx_SingleInstanceChecker.h"
#include "Class_wx_Size.h"
#include "Class_wx_SizerFlags.h"
#include "Class_wx_SplitterRenderParams.h"
#include "Class_wx_StackFrame.h"
#include "Class_wx_StackWalker.h"
#include "Class_wx_StandardPaths.h"
#include "Class_wx_StopWatch.h"
#include "Class_wx_StreamBase.h"
#include "Class_wx_InputStream.h"						// derived from wxStreamBase
#include "Class_wx_FFileInputStream.h"					// derived from wxInputStream
#include "Class_wx_FileInputStream.h"					// derived from wxInputStream
#include "Class_wx_FilterInputStream.h"					// derived from wxInputStream
#include "Class_wx_ArchiveInputStream.h"				// derived from wxFilterInputStream
#include "Class_wx_TarInputStream.h"					// derived from wxArchiveInputStream
#include "Class_wx_ZipInputStream.h"					// derived from wxArchiveInputStream
#include "Class_wx_BufferedInputStream.h"				// derived from wxFilterInputStream
#include "Class_wx_ZlibInputStream.h"					// derived from wxFilterInputStream
#include "Class_wx_MemoryInputStream.h"					// derived from wxInputStream
#include "Class_wx_SocketInputStream.h"					// derived from wxInputStream
#include "Class_wx_StringInputStream.h"					// derived from wxInputStream
#include "Class_wx_OutputStream.h"						// derived from wxStreamBase
#include "Class_wx_CountingOutputStream.h"				// derived from wxOutputStream
#include "Class_wx_FFileOutputStream.h"					// derived from wxOutputStream
#include "Class_wx_FFileStream.h"						// derived from wxFFileOutputStream
#include "Class_wx_FileOutputStream.h"					// derived from wxOutputStream
#include "Class_wx_FileStream.h"						// derived from wxFileOutputStream
#include "Class_wx_FilterOutputStream.h"				// derived from wxOutputStream
#include "Class_wx_ArchiveOutputStream.h"				// derived from wxFilterOutputStream
#include "Class_wx_TarOutputStream.h"					// derived from wxArchiveOutputStream
#include "Class_wx_ZipOutputStream.h"					// derived from wxArchiveOutputStream
#include "Class_wx_BufferedOutputStream.h"				// derived from wxFilterOutputStream
#include "Class_wx_ZlibOutputStream.h"					// derived from wxFilterOutputStream
#include "Class_wx_MemoryOutputStream.h"				// derived from wxOutputStream
#include "Class_wx_SocketOutputStream.h"				// derived from wxOutputStream
#include "Class_wx_StringOutputStream.h"				// derived from wxOutputStream
#include "Class_wx_TempFileOutputStream.h"				// derived from wxOutputStream
#include "Class_wx_StreamBuffer.h"
#include "Class_wx_String.h"
#include "Class_wx_StringBuffer.h"
#include "Class_wx_StringBufferLength.h"
#include "Class_wx_SystemSettings.h"
#include "Class_wx_TempFile.h"
#include "Class_wx_TextAttr.h"
#include "Class_wx_TextAttrEx.h"						// derived from wxTextAttr
#include "Class_wx_TextFile.h"
#include "Class_wx_TextInputStream.h"
#include "Class_wx_TextOutputStream.h"
#include "Class_wx_TimeSpan.h"
#include "Class_wx_TipProvider.h"
#include "Class_wx_TreeItemId.h"
#include "Class_wx_WindowUpdateLocker.h"
#include "Class_wx_WindowDisabler.h"
#include "Class_wx_XmlNode.h"
#include "Class_wx_XmlProperty.h"
#include "Class_wx_ZipNotifier.h"
#include "Class_wx_NativeEncodingInfo.h"
#include "Class_wx_NativeFontInfo.h"
#include "Class_wx_FileTypeInfo.h"
#include "Class_wx_ArchiveNotifier.h"
#include "Class_wx_ArtClient.h"
#include "Class_wx_BMPHandler.h"
#include "Class_wx_GIFHandler.h"
#include "Class_wx_JPEGHandler.h"
#include "Class_wx_PCXHandler.h"
#include "Class_wx_PNGHandler.h"
#include "Class_wx_PNMHandler.h"
#include "Class_wx_TGAHandler.h"
#include "Class_wx_TIFFHandler.h"
#include "Class_wx_XPMHandler.h"
#include "Class_wx_AppConsole.h"
#include "Class_wx_GridCellCoords.h"
#include "Class_wx_GridCellAttrProvider.h"
#include "Class_wx_PageSetupData.h"
#include "Class_wx_ToolBarToolBase.h"
#include "Class_wx_HtmlWindowInterface.h"
#include "Class_wx_HtmlTagsCache.h"
#include "Class_wx_HtmlEntitiesParser.h"
#include "Class_wx_RichTextObject.h"
#include "Class_wx_RichTextImageBlock.h"
#include "Class_wx_RichTextRenderer.h"
#include "Class_wx_RichTextAction.h"
#include "Class_wx_VersionInfo.h"
#include "Class_wx_EventFactory.h"
#if defined(__WXMSW__)
#include "Class_wx_Thread.h"
#include "Class_wx_ThreadHelper.h"

#include "Class_wx_AutomationObject.h"					// derived from wxObject
#include "Class_wx_PowerEvent.h"						// derived from wxEvent
#include "Class_wx_DataInputStream.h"
#include "Class_wx_DataObjectComposite.h"				// derived from wxDataObject
#include "Class_wx_URLDataObject.h"						// derived from wxDataObjectComposite
#include "Class_wx_DataOutputStream.h"
#if 0
#include "Class_wx_DataViewColumn.h"					// derived from wxObject
#include "Class_wx_DataViewListModelNotifier.h"			// derived from wxObject
#include "Class_wx_DataViewModel.h"						// derived from wxObject
#include "Class_wx_DataViewListModel.h"					// derived from wxDataViewModel
#include "Class_wx_DataViewSortedListModel.h"			// derived from wxDataViewListModel
#include "Class_wx_DataViewRenderer.h"					// derived from wxObject
#include "Class_wx_DataViewTextRenderer.h"				// derived from wxDataViewRenderer
#include "Class_wx_DataViewProgressRenderer.h"			// derived from wxDataViewRenderer
#include "Class_wx_DataViewToggleRenderer.h"			// derived from wxDataViewRenderer
#include "Class_wx_DataViewBitmapRenderer.h"			// derived from wxDataViewRenderer
#include "Class_wx_DataViewDateRenderer.h"				// derived from wxDataViewRenderer
#include "Class_wx_DataViewCustomRenderer.h"			// derived from wxDataViewRenderer
#include "Class_wx_DataViewEvent.h"						// derived from wxNotifyEvent
#include "Class_wx_DataViewCtrl.h"						// derived from wxControl
#endif
#include "Class_wx_DDEConnection.h"						// derived from wxConnectionBase
#include "Class_wx_DDEServer.h"							// derived from wxServerBase
#include "Class_wx_DDEClient.h"							// derived from wxClientBase
#include "Class_wx_ActiveXEvent.h"						// derived from wxCommandEvent
#include "Class_wx_MediaEvent.h"						// derived from wxNotifyEvent
#include "Class_wx_ActiveXContainer.h"					// derived from wxWindow
#include "Class_wx_MediaCtrl.h"							// derived from wxControl
#include "Class_wx_RegKey.h"
#include "Class_wx_Metafile.h"							// derived from wxObject
#include "Class_wx_PrinterDC.h"							// derived from wxDC
#include "Class_wx_MetafileDC.h"						// derived from wxDC
#endif
#include "CArray.h"

#endif
