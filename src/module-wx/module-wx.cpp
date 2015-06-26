//-----------------------------------------------------------------------------
// Gura module: wx
//-----------------------------------------------------------------------------
#include "stdafx.h"

#if defined(__WXMSW__)

WXDLLIMPEXP_BASE void wxSetInstance(HINSTANCE hInst);

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD dwReason, LPVOID lpvReserved)
{
	// This is necessary to load resources correctly.
	::wxSetInstance(hInst);
	return TRUE;
}

#endif

#undef BLACK_PEN
#undef WHITE_PEN
#undef BLACK_BRUSH
#undef WHITE_BRUSH
#undef TRANSPARENT
#undef FR_DOWN
#undef FR_WHOLEWORD
#undef FR_MATCHCASE
#undef FR_REPLACEDIALOG
#undef FR_NOUPDOWN
#undef FR_NOMATCHCASE
#undef FR_NOWHOLEWORD

#define RealizeBaseClass(className) \
Gura_RealizeUserClassAlias(wx_##className, #className, env.LookupClass(VTYPE_object))

#define RealizeDervClass(className, classNameParent) \
Gura_RealizeUserClassAlias(wx_##className, #className, Gura_UserClass(wx_##classNameParent))

#define PrepareClass(className) \
Gura_PrepareUserClass(wx_##className)

Gura_BeginModuleBody(wx)

const bool OwnerTrue = true;
const bool OwnerFalse = false;

static bool g_wxReadyFlag = false;

void RegisterFunctions(Environment &env, Signal sig);

//-----------------------------------------------------------------------------
// Gura module functions: wx
//-----------------------------------------------------------------------------
// Module entry
Gura_ModuleEntry()
{
	RealizeBaseClass(EventFactory);
	PrepareClass(EventFactory);
	// Realize classes
	RealizeBaseClass(AboutDialogInfo);
	RealizeBaseClass(LanguageInfo);
	RealizeBaseClass(MouseState);
	RealizeBaseClass(AcceleratorEntry);
	RealizeBaseClass(AppTraits);
	RealizeBaseClass(AuiDockArt);
	RealizeBaseClass(AuiTabArt);
	RealizeBaseClass(AuiPaneInfo);
	RealizeBaseClass(List);
	RealizeBaseClass(BusyCursor);
	RealizeBaseClass(BusyInfo);
	RealizeBaseClass(CalendarDateAttr);
	RealizeBaseClass(Caret);
	RealizeBaseClass(ClassInfo);
	RealizeBaseClass(ClientData);
	//RealizeDervClass(TreeItemData,					ClientData);
	RealizeBaseClass(TreeItemData);
	RealizeBaseClass(ClientDataContainer);
	RealizeBaseClass(CmdLineParser);
	RealizeBaseClass(ColourDatabase);
	RealizeBaseClass(ComboPopup);
	RealizeBaseClass(Condition);
	RealizeBaseClass(ConfigBase);
	RealizeDervClass(FileConfig,						ConfigBase);
	RealizeBaseClass(CriticalSection);
	RealizeBaseClass(CriticalSectionLocker);
	RealizeBaseClass(DataFormat);
_MS(RealizeBaseClass(DataInputStream));
	RealizeBaseClass(DataObject);
_MS(RealizeDervClass(DataObjectComposite,				DataObject));
_MS(RealizeDervClass(URLDataObject,						DataObjectComposite));
	RealizeDervClass(DataObjectSimple,					DataObject);
	RealizeDervClass(BitmapDataObject,					DataObjectSimple);
	RealizeDervClass(CustomDataObject,					DataObjectSimple);
	RealizeDervClass(FileDataObject,					DataObjectSimple);
	RealizeDervClass(TextDataObject,					DataObjectSimple);
_MS(RealizeBaseClass(DataOutputStream));
	RealizeBaseClass(DateSpan);
	RealizeBaseClass(DateTime);
	RealizeBaseClass(DateTimeHolidayAuthority);
	RealizeBaseClass(DateTimeWorkDays);
	RealizeBaseClass(DCClipper);
	RealizeBaseClass(DebugReport);
	RealizeDervClass(DebugReportCompress,				DebugReport);
	RealizeDervClass(DebugReportUpload,					DebugReportCompress);
	RealizeBaseClass(DebugReportPreview);
	RealizeDervClass(DebugReportPreviewStd,				DebugReportPreview);
#if !defined(__WXMAC__)
	RealizeBaseClass(DialUpManager);
#endif
	RealizeBaseClass(Dir);
	RealizeBaseClass(DirTraverser);
	RealizeBaseClass(Display);
	RealizeBaseClass(DropSource);
	RealizeBaseClass(DropTarget);
	RealizeDervClass(FileDropTarget,					DropTarget);
	RealizeDervClass(TextDropTarget,					DropTarget);
	RealizeBaseClass(DynamicLibrary);
	RealizeBaseClass(DynamicLibraryDetails);
	RealizeBaseClass(FFile);
	RealizeBaseClass(File);
	RealizeBaseClass(FileName);
	RealizeBaseClass(FileType);
	RealizeBaseClass(FontEnumerator);
	RealizeBaseClass(FontMapper);
	RealizeBaseClass(GBPosition);
	RealizeBaseClass(GBSpan);
	RealizeBaseClass(GridCellAttr);
	RealizeBaseClass(GridCellWorker);
	RealizeDervClass(GridCellEditor,					GridCellWorker);
	RealizeDervClass(GridCellBoolEditor,				GridCellEditor);
	RealizeDervClass(GridCellChoiceEditor,				GridCellEditor);
	RealizeDervClass(GridCellTextEditor,				GridCellEditor);
	RealizeDervClass(GridCellFloatEditor,				GridCellTextEditor);
	RealizeDervClass(GridCellNumberEditor,				GridCellTextEditor);
	RealizeDervClass(GridCellAutoWrapStringEditor,		GridCellTextEditor);
	RealizeDervClass(GridCellRenderer,					GridCellWorker);
	RealizeDervClass(GridCellBoolRenderer,				GridCellRenderer);
	RealizeDervClass(GridCellStringRenderer,			GridCellRenderer);
	RealizeDervClass(GridCellFloatRenderer,				GridCellStringRenderer);
	RealizeDervClass(GridCellNumberRenderer,			GridCellStringRenderer);
	RealizeDervClass(GridCellAutoWrapStringRenderer,	GridCellStringRenderer);
	RealizeBaseClass(HelpProvider);
	RealizeDervClass(SimpleHelpProvider,				HelpProvider);
	RealizeDervClass(HelpControllerHelpProvider,		SimpleHelpProvider);
	RealizeBaseClass(HtmlModalHelp);
	RealizeBaseClass(IconBundle);
	RealizeBaseClass(IconLocation);
	RealizeBaseClass(ListItemAttr);
	RealizeBaseClass(Locale);
	RealizeBaseClass(Log);
	RealizeDervClass(LogChain,							Log);
	RealizeDervClass(LogPassThrough,					LogChain);
	RealizeDervClass(LogWindow,							LogPassThrough);
	RealizeDervClass(LogGui,							Log);
	RealizeDervClass(LogStderr,							Log);
	RealizeDervClass(LogTextCtrl,						Log);
	RealizeBaseClass(LongLong);
	RealizeBaseClass(MBConv);
	RealizeDervClass(CSConv,							MBConv);
	RealizeDervClass(MBConvUTF7,						MBConv);
	RealizeDervClass(MBConvUTF8,						MBConv);
	RealizeDervClass(MBConvUTF16,						MBConv);
	RealizeDervClass(MBConvUTF32,						MBConv);
	RealizeBaseClass(MemoryBuffer);
	RealizeBaseClass(MimeTypesManager);
	RealizeBaseClass(Mutex);
	RealizeBaseClass(MutexLocker);
	RealizeBaseClass(Node);
	RealizeBaseClass(Object);
	RealizeDervClass(ConnectionBase,					Object);
	RealizeDervClass(Connection,						ConnectionBase);
_MS(RealizeDervClass(DDEConnection,						ConnectionBase));
	RealizeDervClass(TCPConnection,						ConnectionBase);
	RealizeDervClass(HelpControllerBase,				Object);
	RealizeDervClass(HelpController,					HelpControllerBase);
	RealizeDervClass(HtmlHelpController,				HelpControllerBase);
	RealizeDervClass(ServerBase,						Object);
_MS(RealizeDervClass(DDEServer,							ServerBase));
	RealizeDervClass(Server,							ServerBase);
	RealizeDervClass(TCPServer,							ServerBase);
	RealizeDervClass(ClientBase,						Object);
	RealizeDervClass(Client,							ClientBase);
_MS(RealizeDervClass(DDEClient,							ClientBase));
	RealizeDervClass(TCPClient,							ClientBase);
	RealizeDervClass(AcceleratorTable,					Object);
	RealizeDervClass(ArchiveClassFactory,				Object);
	RealizeDervClass(TarClassFactory,					ArchiveClassFactory);
	RealizeDervClass(ZipClassFactory,					ArchiveClassFactory);
	RealizeDervClass(ArchiveEntry,						Object);
	RealizeDervClass(TarEntry,							ArchiveEntry);
	RealizeDervClass(ZipEntry,							ArchiveEntry);
	RealizeDervClass(ArtProvider,						Object);
_MS(RealizeDervClass(AutomationObject,					Object));
	RealizeDervClass(BitmapHandler,						Object);
	RealizeDervClass(Clipboard,							Object);
	RealizeDervClass(Colour,							Object);
	RealizeDervClass(ColourData,						Object);
	RealizeDervClass(Command,							Object);
	RealizeDervClass(CommandProcessor,					Object);
	RealizeDervClass(ContextHelp,						Object);
#if 0
_MS(RealizeDervClass(DataViewColumn,					Object));
_MS(RealizeDervClass(DataViewListModelNotifier,			Object));
_MS(RealizeDervClass(DataViewModel,						Object));
_MS(RealizeDervClass(DataViewListModel,					DataViewModel));
_MS(RealizeDervClass(DataViewSortedListModel,			DataViewListModel));
_MS(RealizeDervClass(DataViewRenderer,					Object));
_MS(RealizeDervClass(DataViewTextRenderer,				DataViewRenderer));
_MS(RealizeDervClass(DataViewProgressRenderer,			DataViewRenderer));
_MS(RealizeDervClass(DataViewToggleRenderer,			DataViewRenderer));
_MS(RealizeDervClass(DataViewBitmapRenderer,			DataViewRenderer));
_MS(RealizeDervClass(DataViewDateRenderer,				DataViewRenderer));
_MS(RealizeDervClass(DataViewCustomRenderer,			DataViewRenderer));
#endif
	RealizeDervClass(DC,								Object);
	RealizeDervClass(MemoryDC,							DC);
	RealizeDervClass(BufferedDC,						MemoryDC);
	RealizeDervClass(BufferedPaintDC,					BufferedDC);
	RealizeDervClass(AutoBufferedPaintDC,				DC);
_MS(RealizeDervClass(MetafileDC,						DC));
	RealizeDervClass(MirrorDC,							DC);
_MS(RealizeDervClass(PrinterDC,							DC));
	RealizeDervClass(ScreenDC,							DC);
	RealizeDervClass(WindowDC,							DC);
	RealizeDervClass(ClientDC,							WindowDC);
	RealizeDervClass(PaintDC,							WindowDC);
	RealizeDervClass(DocTemplate,						Object);
	RealizeDervClass(DragImage,							Object);
	RealizeDervClass(EncodingConverter,					Object);
	RealizeDervClass(Event,								Object);
	RealizeDervClass(ActivateEvent,						Event);
	RealizeDervClass(CalculateLayoutEvent,				Event);
	RealizeDervClass(CloseEvent,						Event);
	RealizeDervClass(CommandEvent,						Event);
_MS(RealizeDervClass(ActiveXEvent,						CommandEvent));
	RealizeDervClass(ClipboardTextEvent,				CommandEvent);
	RealizeDervClass(CollapsiblePaneEvent,				CommandEvent);
	RealizeDervClass(ColourPickerEvent,					CommandEvent);
	RealizeDervClass(ChildFocusEvent,					CommandEvent);
	RealizeDervClass(ContextMenuEvent,					CommandEvent);
	RealizeDervClass(DateEvent,							CommandEvent);
	RealizeDervClass(CalendarEvent,						DateEvent);
	RealizeDervClass(FileDirPickerEvent,				CommandEvent);
	RealizeDervClass(FindDialogEvent,					CommandEvent);
	RealizeDervClass(FontPickerEvent,					CommandEvent);
	RealizeDervClass(HelpEvent,							CommandEvent);
	RealizeDervClass(HtmlLinkEvent,						CommandEvent);
	RealizeDervClass(HtmlCellEvent,						CommandEvent);
	RealizeDervClass(HyperlinkEvent,					CommandEvent);
	RealizeDervClass(NotifyEvent,						CommandEvent);
	RealizeDervClass(BookCtrlBaseEvent,					NotifyEvent);
	RealizeDervClass(TreebookEvent,						BookCtrlBaseEvent);
#if 0
_MS(RealizeDervClass(DataViewEvent,						NotifyEvent));
#endif
	RealizeDervClass(GridEvent,							NotifyEvent);
	RealizeDervClass(GridRangeSelectEvent,				NotifyEvent);
	RealizeDervClass(GridSizeEvent,						NotifyEvent);
	RealizeDervClass(ListEvent,							NotifyEvent);
_MS(RealizeDervClass(MediaEvent,						NotifyEvent));
	RealizeDervClass(NotebookEvent,						BookCtrlBaseEvent);
	RealizeDervClass(ListbookEvent,						BookCtrlBaseEvent);
	RealizeDervClass(ChoicebookEvent,					BookCtrlBaseEvent);
	RealizeDervClass(ToolbookEvent,						BookCtrlBaseEvent);
	RealizeDervClass(RichTextEvent,						NotifyEvent);
	RealizeDervClass(SpinEvent,							NotifyEvent);
	RealizeDervClass(SplitterEvent,						NotifyEvent);
	RealizeDervClass(TreeEvent,							NotifyEvent);
	RealizeDervClass(WizardEvent,						NotifyEvent);
	RealizeDervClass(SashEvent,							CommandEvent);
	RealizeDervClass(ScrollEvent,						CommandEvent);
	RealizeDervClass(StyledTextEvent,					CommandEvent);
	RealizeDervClass(UpdateUIEvent,						CommandEvent);
	RealizeDervClass(WindowCreateEvent,					CommandEvent);
	RealizeDervClass(WindowDestroyEvent,				CommandEvent);
#if !defined(__WXMAC__)
	RealizeDervClass(DialUpEvent,						Event);
#endif
	RealizeDervClass(DropFilesEvent,					Event);
	RealizeDervClass(EraseEvent,						Event);
	RealizeDervClass(FocusEvent,						Event);
	RealizeDervClass(GridEditorCreatedEvent,			Event);
	RealizeDervClass(IconizeEvent,						Event);
	RealizeDervClass(IdleEvent,							Event);
	RealizeDervClass(InitDialogEvent,					Event);
	RealizeDervClass(JoystickEvent,						Event);
	RealizeDervClass(KeyEvent,							Event);
	RealizeDervClass(MaximizeEvent,						Event);
	RealizeDervClass(MenuEvent,							Event);
	RealizeDervClass(MouseCaptureChangedEvent,			Event);
	RealizeDervClass(MouseCaptureLostEvent,				Event);
	RealizeDervClass(MouseEvent,						Event);
	RealizeDervClass(MoveEvent,							Event);
	RealizeDervClass(PaintEvent,						Event);
_MS(RealizeDervClass(PowerEvent,						Event));
	RealizeDervClass(ProcessEvent,						Event);
	RealizeDervClass(QueryLayoutInfoEvent,				Event);
	RealizeDervClass(ScrollWinEvent,					Event);
	RealizeDervClass(SetCursorEvent,					Event);
	RealizeDervClass(ShowEvent,							Event);
	RealizeDervClass(SizeEvent,							Event);
	RealizeDervClass(SocketEvent,						Event);
	RealizeDervClass(SysColourChangedEvent,				Event);
	RealizeDervClass(TimerEvent,						Event);
	RealizeDervClass(EvtHandler,						Object);
	RealizeDervClass(App,								EvtHandler);
	RealizeDervClass(AuiManager,						EvtHandler);
	RealizeDervClass(DocManager,						EvtHandler);
	RealizeDervClass(Document,							EvtHandler);
	RealizeDervClass(Menu,								EvtHandler);
	RealizeDervClass(Process,							EvtHandler);
	RealizeDervClass(TaskBarIcon,						EvtHandler);
	RealizeDervClass(Timer,								EvtHandler);
	RealizeDervClass(Validator,							EvtHandler);
	RealizeDervClass(GenericValidator,					Validator);
	RealizeDervClass(TextValidator,						Validator);
	RealizeDervClass(View,								EvtHandler);
	RealizeDervClass(Window,							EvtHandler);
	RealizeDervClass(PopupWindow,						Window);
	RealizeDervClass(PopupTransientWindow,				PopupWindow);
	RealizeDervClass(TipWindow,							PopupTransientWindow);
_MS(RealizeDervClass(ActiveXContainer,					Window));
	RealizeDervClass(Control,							Window);
	RealizeDervClass(TextCtrlBase,						Control);
	RealizeDervClass(RichTextCtrl,						Control);
	RealizeDervClass(BookCtrlBase,						Control);
	RealizeDervClass(Choicebook,						BookCtrlBase);
	RealizeDervClass(Toolbook,							BookCtrlBase);
	RealizeDervClass(Treebook,							BookCtrlBase);
	RealizeDervClass(ToolBarBase,						Control);
	RealizeDervClass(ToolBar,							ToolBarBase);
	RealizeDervClass(AnimationCtrl,						Control);
	RealizeDervClass(AuiNotebook,						Control);
	RealizeDervClass(Button,							Control);
	RealizeDervClass(BitmapButton,						Button);
	RealizeDervClass(ContextHelpButton,					BitmapButton);
	RealizeDervClass(CalendarCtrl,						Control);
	RealizeDervClass(CheckBox,							Control);
	RealizeDervClass(CollapsiblePane,					Control);
	RealizeDervClass(ComboCtrl,							Control);
	RealizeDervClass(OwnerDrawnComboBox,				ComboCtrl);
	RealizeDervClass(RichTextStyleComboCtrl,			ComboCtrl);
	RealizeDervClass(ControlWithItems,					Control);
	RealizeDervClass(Choice,							ControlWithItems);
	RealizeDervClass(ComboBox,							Control);
#if !defined(__WXMAC__)
	RealizeDervClass(BitmapComboBox,					ComboBox);
#endif
	RealizeDervClass(ListBox,							ControlWithItems);
	RealizeDervClass(CheckListBox,						ListBox);
#if 0
_MS(RealizeDervClass(DataViewCtrl,						Control));
#endif
	RealizeDervClass(DatePickerCtrl,					Control);
	RealizeDervClass(Gauge,								Control);
	RealizeDervClass(GenericDirCtrl,					Control);
	RealizeDervClass(HyperlinkCtrl,						Control);
	RealizeDervClass(Listbook,							BookCtrlBase);
	RealizeDervClass(ListCtrl,							Control);
	RealizeDervClass(ListView,							ListCtrl);
_MS(RealizeDervClass(MediaCtrl,							Control));
	RealizeDervClass(Notebook,							BookCtrlBase);
	RealizeDervClass(PickerBase,						Control);
	RealizeDervClass(ColourPickerCtrl,					PickerBase);
	RealizeDervClass(DirPickerCtrl,						PickerBase);
	RealizeDervClass(FilePickerCtrl,					PickerBase);
	RealizeDervClass(FontPickerCtrl,					PickerBase);
	RealizeDervClass(RadioBox,							Control);
	RealizeDervClass(RadioButton,						Control);
	RealizeDervClass(RichTextStyleListCtrl,				Control);
	RealizeDervClass(ScrollBar,							Control);
	RealizeDervClass(Slider,							Control);
	RealizeDervClass(SpinButton,						Control);
	RealizeDervClass(SpinCtrl,							Control);
	RealizeDervClass(StaticBitmap,						Control);
	RealizeDervClass(StaticBox,							Control);
	RealizeDervClass(StaticLine,						Control);
	RealizeDervClass(StaticText,						Control);
	RealizeDervClass(TextCtrl,							Control);
	RealizeDervClass(StyledTextCtrl,					Control);
	RealizeDervClass(ToggleButton,						Control);
	RealizeDervClass(TreeCtrl,							Control);
	RealizeDervClass(GLCanvas,							Window);
	RealizeDervClass(HtmlHelpDialog,					Window);
	RealizeDervClass(HtmlHelpWindow,					Window);
	RealizeDervClass(MDIClientWindow,					Window);
	RealizeDervClass(MenuBar,							Window);
	RealizeDervClass(Panel,								Window);
	RealizeDervClass(PreviewControlBar,					Panel);
	RealizeDervClass(ScrolledWindow,					Panel);
	RealizeDervClass(Grid,								ScrolledWindow);
	RealizeDervClass(HtmlWindow,						ScrolledWindow);
	RealizeDervClass(PreviewCanvas,						ScrolledWindow);
	RealizeDervClass(VScrolledWindow,					Panel);
	RealizeDervClass(VListBox,							VScrolledWindow);
	RealizeDervClass(HtmlListBox,						VListBox);
	RealizeDervClass(SimpleHtmlListBox,					HtmlListBox);
	RealizeDervClass(RichTextStyleListBox,				HtmlListBox);
	RealizeDervClass(WizardPage,						Panel);
	RealizeDervClass(WizardPageSimple,					WizardPage);
	RealizeDervClass(SashWindow,						Window);
	RealizeDervClass(SashLayoutWindow,					SashWindow);
	RealizeDervClass(SearchCtrl,						Window);
	RealizeDervClass(SplitterWindow,					Window);
	RealizeDervClass(StatusBar,							Window);
	RealizeDervClass(TopLevelWindow,					Window);
	RealizeDervClass(Dialog,							TopLevelWindow);
	RealizeDervClass(ColourDialog,						Dialog);
	RealizeDervClass(DirDialog,							Dialog);
	RealizeDervClass(FileDialog,						Dialog);
	RealizeDervClass(FindReplaceDialog,					Dialog);
	RealizeDervClass(FontDialog,						Dialog);
	RealizeDervClass(MessageDialog,						Dialog);
	RealizeDervClass(MultiChoiceDialog,					Dialog);
	RealizeDervClass(ProgressDialog,					Dialog);
	RealizeDervClass(PropertySheetDialog,				Dialog);
	RealizeDervClass(RichTextFormattingDialog,			PropertySheetDialog);
	RealizeDervClass(RichTextStyleOrganiserDialog,		Dialog);
	RealizeDervClass(SingleChoiceDialog,				Dialog);
	RealizeDervClass(SymbolPickerDialog,				Dialog);
	RealizeDervClass(TextEntryDialog,					Dialog);
	RealizeDervClass(PasswordEntryDialog,				TextEntryDialog);
	RealizeDervClass(Wizard,							Dialog);
	RealizeDervClass(Frame,								TopLevelWindow);
	RealizeDervClass(DocChildFrame,						Frame);
	RealizeDervClass(DocParentFrame,					Frame);
	RealizeDervClass(HtmlHelpFrame,						Frame);
	RealizeDervClass(MDIChildFrame,						Frame);
	RealizeDervClass(DocMDIChildFrame,					MDIChildFrame);
	RealizeDervClass(MDIParentFrame,					Frame);
	RealizeDervClass(DocMDIParentFrame,					MDIParentFrame);
	RealizeDervClass(MiniFrame,							Frame);
	RealizeDervClass(PreviewFrame,						Frame);
	RealizeDervClass(SplashScreen,						Frame);
	RealizeDervClass(FileHistory,						Object);
	RealizeDervClass(FileSystem,						Object);
	RealizeDervClass(FileSystemHandler,					Object);
	RealizeDervClass(MemoryFSHandler,					FileSystemHandler);
	RealizeDervClass(FilterClassFactory,				Object);
	RealizeDervClass(FindReplaceData,					Object);
	RealizeDervClass(FontData,							Object);
	RealizeDervClass(FSFile,							Object);
	RealizeDervClass(GDIObject,							Object);
	RealizeDervClass(Animation,							Object);
	RealizeDervClass(Bitmap,							GDIObject);
	RealizeDervClass(Brush,								GDIObject);
	RealizeDervClass(Cursor,							GDIObject);
	RealizeDervClass(Font,								GDIObject);
	RealizeDervClass(Icon,								GDIObject);
	RealizeDervClass(Palette,							GDIObject);
	RealizeDervClass(Pen,								GDIObject);
	RealizeDervClass(Region,							GDIObject);
	RealizeDervClass(GLContext,							Object);
	RealizeDervClass(GridTableBase,						Object);
	RealizeDervClass(HashTable,							Object);
	RealizeDervClass(HtmlCell,							Object);
	RealizeDervClass(HtmlColourCell,					HtmlCell);
	RealizeDervClass(HtmlContainerCell,					HtmlCell);
	RealizeDervClass(HtmlWidgetCell,					HtmlCell);
	RealizeDervClass(HtmlDCRenderer,					Object);
	RealizeDervClass(HtmlEasyPrinting,					Object);
	RealizeDervClass(HtmlFilter,						Object);
	RealizeDervClass(HtmlHelpData,						Object);
	RealizeDervClass(HtmlLinkInfo,						Object);
	RealizeDervClass(HtmlParser,						Object);
	RealizeDervClass(HtmlWinParser,						HtmlParser);
	RealizeBaseClass(HtmlTag);
	RealizeDervClass(HtmlTagHandler,					Object);
	RealizeDervClass(HtmlWinTagHandler,					HtmlTagHandler);
	RealizeDervClass(Image,								Object);
	RealizeDervClass(ImageHandler,						Object);
	RealizeDervClass(ImageList,							Object);
	RealizeDervClass(IndividualLayoutConstraint,		Object);
	RealizeDervClass(Joystick,							Object);
	RealizeDervClass(LayoutAlgorithm,					Object);
	RealizeDervClass(LayoutConstraints,					Object);
	RealizeDervClass(ListItem,							Object);
	RealizeDervClass(Mask,								Object);
	RealizeDervClass(MenuItem,							Object);
_MS(RealizeDervClass(Metafile,							Object));
	RealizeDervClass(Module,							Object);
	RealizeDervClass(HtmlTagsModule,					Module);
	RealizeDervClass(PageSetupDialog,					Object);
	RealizeDervClass(PageSetupDialogData,				Object);
	RealizeDervClass(PrintData,							Object);
	RealizeDervClass(PrintDialog,						Object);
	RealizeDervClass(PrintDialogData,					Object);
	RealizeDervClass(Printer,							Object);
	RealizeDervClass(Printout,							Object);
	RealizeDervClass(HtmlPrintout,						Printout);
	RealizeDervClass(RichTextPrintout,					Printout);
	RealizeDervClass(PrintPreview,						Object);
	RealizeDervClass(Quantize,							Object);
	RealizeDervClass(RegionIterator,					Object);
	RealizeDervClass(RichTextFileHandler,				Object);
	RealizeDervClass(RichTextHTMLHandler,				RichTextFileHandler);
	RealizeDervClass(RichTextXMLHandler,				RichTextFileHandler);
	RealizeDervClass(RichTextFormattingDialogFactory,	Object);
	RealizeDervClass(RichTextHeaderFooterData,			Object);
	RealizeDervClass(RichTextPrinting,					Object);
	RealizeDervClass(RichTextStyleDefinition,			Object);
	RealizeDervClass(RichTextCharacterStyleDefinition,	RichTextStyleDefinition);
	RealizeDervClass(RichTextParagraphStyleDefinition,	RichTextStyleDefinition);
	RealizeDervClass(RichTextListStyleDefinition,		RichTextParagraphStyleDefinition);
	RealizeDervClass(RichTextStyleSheet,				Object);
	RealizeDervClass(Sizer,								Object);
	RealizeDervClass(BoxSizer,							Sizer);
	RealizeDervClass(StaticBoxSizer,					BoxSizer);
	RealizeDervClass(StdDialogButtonSizer,				BoxSizer);
	RealizeDervClass(GridSizer,							Sizer);
	RealizeDervClass(FlexGridSizer,						GridSizer);
	RealizeDervClass(GridBagSizer,						FlexGridSizer);
	RealizeDervClass(SizerItem,							Object);
	RealizeDervClass(GBSizerItem,						SizerItem);
	RealizeDervClass(SockAddress,						Object);
	RealizeDervClass(IPaddress,							SockAddress);
	RealizeDervClass(IPV4address,						IPaddress);
	RealizeDervClass(SocketBase,						Object);
	RealizeDervClass(DatagramSocket,					SocketBase);
	RealizeDervClass(SocketClient,						SocketBase);
	RealizeDervClass(Protocol,							SocketClient);
	RealizeDervClass(FTP,								Protocol);
	RealizeDervClass(HTTP,								Protocol);
	RealizeDervClass(SocketServer,						SocketBase);
	RealizeDervClass(Sound,								Object);
	RealizeDervClass(StringTokenizer,					Object);
	RealizeDervClass(SystemOptions,						Object);
	RealizeDervClass(ToolTip,							Object);
	RealizeDervClass(URI,								Object);
	RealizeDervClass(URL,								URI);
	RealizeDervClass(Variant,							Object);
	RealizeDervClass(XmlDocument,						Object);
	RealizeDervClass(XmlResource,						Object);
	RealizeDervClass(XmlResourceHandler,				Object);
	RealizeBaseClass(ObjectRefData);
	RealizeDervClass(VariantData,						ObjectRefData);
	RealizeBaseClass(PenList);
	RealizeBaseClass(PlatformInfo);
	RealizeBaseClass(Point);
	RealizeBaseClass(RealPoint);
	RealizeBaseClass(Rect);
	RealizeBaseClass(RecursionGuard);
	RealizeBaseClass(RegEx);
_MS(RealizeBaseClass(RegKey));
	RealizeBaseClass(RendererNative);
	RealizeDervClass(DelegateRendererNative,			RendererNative);
	RealizeBaseClass(RendererVersion);
	RealizeBaseClass(RichTextAttr);
	RealizeBaseClass(RichTextParagraphLayoutBox);
	RealizeDervClass(RichTextBuffer,					RichTextParagraphLayoutBox);
	RealizeBaseClass(RichTextRange);
	RealizeBaseClass(Semaphore);
	RealizeBaseClass(SingleInstanceChecker);
	RealizeBaseClass(Size);
	RealizeBaseClass(SizerFlags);
	RealizeBaseClass(SplitterRenderParams);
	RealizeBaseClass(StackFrame);
	RealizeBaseClass(StackWalker);
	RealizeBaseClass(StandardPaths);
	RealizeBaseClass(StopWatch);
	RealizeBaseClass(StreamBase);
	RealizeDervClass(InputStream,						StreamBase);
	RealizeDervClass(FFileInputStream,					InputStream);
	RealizeDervClass(FileInputStream,					InputStream);
	RealizeDervClass(FilterInputStream,					InputStream);
	RealizeDervClass(ArchiveInputStream,				FilterInputStream);
	RealizeDervClass(TarInputStream,					ArchiveInputStream);
	RealizeDervClass(ZipInputStream,					ArchiveInputStream);
	RealizeDervClass(BufferedInputStream,				FilterInputStream);
	RealizeDervClass(ZlibInputStream,					FilterInputStream);
	RealizeDervClass(MemoryInputStream,					InputStream);
	RealizeDervClass(SocketInputStream,					InputStream);
	RealizeDervClass(StringInputStream,					InputStream);
	RealizeDervClass(OutputStream,						StreamBase);
	RealizeDervClass(CountingOutputStream,				OutputStream);
	RealizeDervClass(FFileOutputStream,					OutputStream);
	RealizeDervClass(FFileStream,						FFileOutputStream);
	RealizeDervClass(FileOutputStream,					OutputStream);
	RealizeDervClass(FileStream,						FileOutputStream);
	RealizeDervClass(FilterOutputStream,				OutputStream);
	RealizeDervClass(ArchiveOutputStream,				FilterOutputStream);
	RealizeDervClass(TarOutputStream,					ArchiveOutputStream);
	RealizeDervClass(ZipOutputStream,					ArchiveOutputStream);
	RealizeDervClass(BufferedOutputStream,				FilterOutputStream);
	RealizeDervClass(ZlibOutputStream,					FilterOutputStream);
	RealizeDervClass(MemoryOutputStream,				OutputStream);
	RealizeDervClass(SocketOutputStream,				OutputStream);
	RealizeDervClass(StringOutputStream,				OutputStream);
	RealizeDervClass(TempFileOutputStream,				OutputStream);
	RealizeBaseClass(StreamBuffer);
	RealizeBaseClass(String);
	RealizeBaseClass(StringBuffer);
	RealizeBaseClass(StringBufferLength);
	RealizeBaseClass(SystemSettings);
	RealizeBaseClass(TempFile);
	RealizeBaseClass(TextAttr);
	RealizeDervClass(TextAttrEx,						TextAttr);
	RealizeBaseClass(TextFile);
	RealizeBaseClass(TextInputStream);
	RealizeBaseClass(TextOutputStream);
_MS(RealizeBaseClass(Thread));
_MS(RealizeBaseClass(ThreadHelper));
	RealizeBaseClass(TimeSpan);
	RealizeBaseClass(TipProvider);
	RealizeBaseClass(TreeItemId);
	RealizeBaseClass(WindowUpdateLocker);
	RealizeBaseClass(WindowDisabler);
	RealizeBaseClass(XmlNode);
	RealizeBaseClass(XmlProperty);
	RealizeBaseClass(ZipNotifier);
	RealizeBaseClass(NativeEncodingInfo);
	RealizeBaseClass(NativeFontInfo);
	RealizeBaseClass(FileTypeInfo);
	RealizeBaseClass(ArchiveNotifier);
	RealizeBaseClass(ArtClient);
	RealizeDervClass(BMPHandler,						ImageHandler);
	RealizeDervClass(GIFHandler,						ImageHandler);
	RealizeDervClass(JPEGHandler,						ImageHandler);
	RealizeDervClass(PCXHandler,						ImageHandler);
	RealizeDervClass(PNGHandler,						ImageHandler);
	RealizeDervClass(PNMHandler,						ImageHandler);
	RealizeDervClass(TGAHandler,						ImageHandler);
	RealizeDervClass(TIFFHandler,						ImageHandler);
	RealizeDervClass(XPMHandler,						ImageHandler);
	RealizeBaseClass(AppConsole);
	RealizeBaseClass(GridCellCoords);
	RealizeBaseClass(GridCellAttrProvider);
	RealizeBaseClass(PageSetupData);
	RealizeBaseClass(ToolBarToolBase);
	RealizeBaseClass(HtmlWindowInterface);
	RealizeBaseClass(HtmlTagsCache);
	RealizeBaseClass(HtmlEntitiesParser);
	RealizeBaseClass(RichTextObject);
	RealizeBaseClass(RichTextImageBlock);
	RealizeBaseClass(RichTextRenderer);
	RealizeBaseClass(RichTextAction);
	RealizeBaseClass(VersionInfo);
	// Prepare classes
	PrepareClass(AboutDialogInfo);
	PrepareClass(LanguageInfo);
	PrepareClass(MouseState);
	PrepareClass(AcceleratorEntry);
	PrepareClass(AppTraits);
	PrepareClass(AuiDockArt);
	PrepareClass(AuiTabArt);
	PrepareClass(AuiPaneInfo);
	PrepareClass(List);
	PrepareClass(BusyCursor);
	PrepareClass(BusyInfo);
	PrepareClass(CalendarDateAttr);
	PrepareClass(Caret);
	PrepareClass(ClassInfo);
	PrepareClass(ClientData);
	PrepareClass(TreeItemData);
	PrepareClass(ClientDataContainer);
	PrepareClass(CmdLineParser);
	PrepareClass(ColourDatabase);
	PrepareClass(ComboPopup);
	PrepareClass(Condition);
	PrepareClass(ConfigBase);
	PrepareClass(FileConfig);
	PrepareClass(CriticalSection);
	PrepareClass(CriticalSectionLocker);
	PrepareClass(DataFormat);
_MS(PrepareClass(DataInputStream));
	PrepareClass(DataObject);
_MS(PrepareClass(DataObjectComposite));
_MS(PrepareClass(URLDataObject));
	PrepareClass(DataObjectSimple);
	PrepareClass(BitmapDataObject);
	PrepareClass(CustomDataObject);
	PrepareClass(FileDataObject);
	PrepareClass(TextDataObject);
_MS(PrepareClass(DataOutputStream));
	PrepareClass(DateSpan);
	PrepareClass(DateTime);
	PrepareClass(DateTimeHolidayAuthority);
	PrepareClass(DateTimeWorkDays);
	PrepareClass(DCClipper);
	PrepareClass(DebugReport);
	PrepareClass(DebugReportCompress);
	PrepareClass(DebugReportUpload);
	PrepareClass(DebugReportPreview);
	PrepareClass(DebugReportPreviewStd);
#if !defined(__WXMAC__)
	PrepareClass(DialUpManager);
#endif
	PrepareClass(Dir);
	PrepareClass(DirTraverser);
	PrepareClass(Display);
	PrepareClass(DropSource);
	PrepareClass(DropTarget);
	PrepareClass(FileDropTarget);
	PrepareClass(TextDropTarget);
	PrepareClass(DynamicLibrary);
	PrepareClass(DynamicLibraryDetails);
	PrepareClass(FFile);
	PrepareClass(File);
	PrepareClass(FileName);
	PrepareClass(FileType);
	PrepareClass(FontEnumerator);
	PrepareClass(FontMapper);
	PrepareClass(GBPosition);
	PrepareClass(GBSpan);
	PrepareClass(GridCellAttr);
	PrepareClass(GridCellWorker);
	PrepareClass(GridCellEditor);
	PrepareClass(GridCellBoolEditor);
	PrepareClass(GridCellChoiceEditor);
	PrepareClass(GridCellTextEditor);
	PrepareClass(GridCellFloatEditor);
	PrepareClass(GridCellNumberEditor);
	PrepareClass(GridCellAutoWrapStringEditor);
	PrepareClass(GridCellRenderer);
	PrepareClass(GridCellBoolRenderer);
	PrepareClass(GridCellStringRenderer);
	PrepareClass(GridCellFloatRenderer);
	PrepareClass(GridCellNumberRenderer);
	PrepareClass(GridCellAutoWrapStringRenderer);
	PrepareClass(HelpProvider);
	PrepareClass(SimpleHelpProvider);
	PrepareClass(HelpControllerHelpProvider);
	PrepareClass(HtmlModalHelp);
	PrepareClass(IconBundle);
	PrepareClass(IconLocation);
	PrepareClass(ListItemAttr);
	PrepareClass(Locale);
	PrepareClass(Log);
	PrepareClass(LogChain);
	PrepareClass(LogPassThrough);
	PrepareClass(LogWindow);
	PrepareClass(LogGui);
	PrepareClass(LogStderr);
	PrepareClass(LogTextCtrl);
	PrepareClass(LongLong);
	PrepareClass(MBConv);
	PrepareClass(CSConv);
	PrepareClass(MBConvUTF7);
	PrepareClass(MBConvUTF8);
	PrepareClass(MBConvUTF16);
	PrepareClass(MBConvUTF32);
	PrepareClass(MemoryBuffer);
	PrepareClass(MimeTypesManager);
	PrepareClass(Mutex);
	PrepareClass(MutexLocker);
	PrepareClass(Node);
	PrepareClass(Object);
	PrepareClass(ConnectionBase);
	PrepareClass(Connection);
_MS(PrepareClass(DDEConnection));
	PrepareClass(TCPConnection);
	PrepareClass(HelpControllerBase);
	PrepareClass(HelpController);
	PrepareClass(HtmlHelpController);
	PrepareClass(ServerBase);
_MS(PrepareClass(DDEServer));
	PrepareClass(Server);
	PrepareClass(TCPServer);
	PrepareClass(AcceleratorTable);
	PrepareClass(ArchiveClassFactory);
	PrepareClass(TarClassFactory);
	PrepareClass(ZipClassFactory);
	PrepareClass(ArchiveEntry);
	PrepareClass(TarEntry);
	PrepareClass(ZipEntry);
	PrepareClass(ArtProvider);
_MS(PrepareClass(AutomationObject));
	PrepareClass(BitmapHandler);
	PrepareClass(Clipboard);
	PrepareClass(Colour);
	PrepareClass(ColourData);
	PrepareClass(Command);
	PrepareClass(CommandProcessor);
	PrepareClass(ContextHelp);
#if 0
_MS(PrepareClass(DataViewColumn));
_MS(PrepareClass(DataViewListModelNotifier));
_MS(PrepareClass(DataViewModel));
_MS(PrepareClass(DataViewListModel));
_MS(PrepareClass(DataViewSortedListModel));
_MS(PrepareClass(DataViewRenderer));
_MS(PrepareClass(DataViewTextRenderer));
_MS(PrepareClass(DataViewProgressRenderer));
_MS(PrepareClass(DataViewToggleRenderer));
_MS(PrepareClass(DataViewBitmapRenderer));
_MS(PrepareClass(DataViewDateRenderer));
_MS(PrepareClass(DataViewCustomRenderer));
#endif
	PrepareClass(DC);
	PrepareClass(MemoryDC);
	PrepareClass(BufferedDC);
	PrepareClass(BufferedPaintDC);
	PrepareClass(AutoBufferedPaintDC);
_MS(PrepareClass(MetafileDC));
	PrepareClass(MirrorDC);
_MS(PrepareClass(PrinterDC));
	PrepareClass(ScreenDC);
	PrepareClass(WindowDC);
	PrepareClass(ClientDC);
	PrepareClass(PaintDC);
	PrepareClass(DocTemplate);
	PrepareClass(DragImage);
	PrepareClass(EncodingConverter);
	PrepareClass(Event);
	PrepareClass(ActivateEvent);
	PrepareClass(CalculateLayoutEvent);
	PrepareClass(CloseEvent);
	PrepareClass(CommandEvent);
_MS(PrepareClass(ActiveXEvent));
	PrepareClass(ClipboardTextEvent);
	PrepareClass(CollapsiblePaneEvent);
	PrepareClass(ColourPickerEvent);
	PrepareClass(ChildFocusEvent);
	PrepareClass(ContextMenuEvent);
	PrepareClass(DateEvent);
	PrepareClass(CalendarEvent);
	PrepareClass(FileDirPickerEvent);
	PrepareClass(FindDialogEvent);
	PrepareClass(FontPickerEvent);
	PrepareClass(HelpEvent);
	PrepareClass(HtmlLinkEvent);
	PrepareClass(HtmlCellEvent);
	PrepareClass(HyperlinkEvent);
	PrepareClass(NotifyEvent);
	PrepareClass(BookCtrlBaseEvent);
	PrepareClass(TreebookEvent);
#if 0
_MS(PrepareClass(DataViewEvent));
#endif
	PrepareClass(GridEvent);
	PrepareClass(GridRangeSelectEvent);
	PrepareClass(GridSizeEvent);
	PrepareClass(ListEvent);
_MS(PrepareClass(MediaEvent));
	PrepareClass(NotebookEvent);
	PrepareClass(ListbookEvent);
	PrepareClass(ChoicebookEvent);
	PrepareClass(ToolbookEvent);
	PrepareClass(RichTextEvent);
	PrepareClass(SpinEvent);
	PrepareClass(SplitterEvent);
	PrepareClass(TreeEvent);
	PrepareClass(WizardEvent);
	PrepareClass(SashEvent);
	PrepareClass(ScrollEvent);
	PrepareClass(StyledTextEvent);
	PrepareClass(UpdateUIEvent);
	PrepareClass(WindowCreateEvent);
	PrepareClass(WindowDestroyEvent);
#if !defined(__WXMAC__)
	PrepareClass(DialUpEvent);
#endif
	PrepareClass(DropFilesEvent);
	PrepareClass(EraseEvent);
	PrepareClass(FocusEvent);
	PrepareClass(GridEditorCreatedEvent);
	PrepareClass(IconizeEvent);
	PrepareClass(IdleEvent);
	PrepareClass(InitDialogEvent);
	PrepareClass(JoystickEvent);
	PrepareClass(KeyEvent);
	PrepareClass(MaximizeEvent);
	PrepareClass(MenuEvent);
	PrepareClass(MouseCaptureChangedEvent);
	PrepareClass(MouseCaptureLostEvent);
	PrepareClass(MouseEvent);
	PrepareClass(MoveEvent);
	PrepareClass(PaintEvent);
_MS(PrepareClass(PowerEvent));
	PrepareClass(ProcessEvent);
	PrepareClass(QueryLayoutInfoEvent);
	PrepareClass(ScrollWinEvent);
	PrepareClass(SetCursorEvent);
	PrepareClass(ShowEvent);
	PrepareClass(SizeEvent);
	PrepareClass(SocketEvent);
	PrepareClass(SysColourChangedEvent);
	PrepareClass(TimerEvent);
	PrepareClass(EvtHandler);
	PrepareClass(App);
	PrepareClass(AuiManager);
	PrepareClass(DocManager);
	PrepareClass(Document);
	PrepareClass(Menu);
	PrepareClass(Process);
	PrepareClass(TaskBarIcon);
	PrepareClass(Timer);
	PrepareClass(Validator);
	PrepareClass(GenericValidator);
	PrepareClass(TextValidator);
	PrepareClass(View);
	PrepareClass(Window);
	PrepareClass(PopupWindow);
	PrepareClass(PopupTransientWindow);
	PrepareClass(TipWindow);
_MS(PrepareClass(ActiveXContainer));
	PrepareClass(Control);
	PrepareClass(TextCtrlBase);
	PrepareClass(RichTextCtrl);
	PrepareClass(BookCtrlBase);
	PrepareClass(Choicebook);
	PrepareClass(Toolbook);
	PrepareClass(Treebook);
	PrepareClass(ToolBarBase);
	PrepareClass(ToolBar);
	PrepareClass(AnimationCtrl);
	PrepareClass(AuiNotebook);
	PrepareClass(Button);
	PrepareClass(BitmapButton);
	PrepareClass(ContextHelpButton);
	PrepareClass(CalendarCtrl);
	PrepareClass(CheckBox);
	PrepareClass(CollapsiblePane);
	PrepareClass(ComboCtrl);
	PrepareClass(OwnerDrawnComboBox);
#if !defined(__WXMAC__)
	PrepareClass(BitmapComboBox);
#endif
	PrepareClass(RichTextStyleComboCtrl);
	PrepareClass(ControlWithItems);
	PrepareClass(Choice);
	PrepareClass(ComboBox);
	PrepareClass(ListBox);
	PrepareClass(CheckListBox);
#if 0
_MS(PrepareClass(DataViewCtrl));
#endif
	PrepareClass(DatePickerCtrl);
	PrepareClass(Gauge);
	PrepareClass(GenericDirCtrl);
	PrepareClass(HyperlinkCtrl);
	PrepareClass(Listbook);
	PrepareClass(ListCtrl);
	PrepareClass(ListView);
_MS(PrepareClass(MediaCtrl));
	PrepareClass(Notebook);
	PrepareClass(PickerBase);
	PrepareClass(ColourPickerCtrl);
	PrepareClass(DirPickerCtrl);
	PrepareClass(FilePickerCtrl);
	PrepareClass(FontPickerCtrl);
	PrepareClass(RadioBox);
	PrepareClass(RadioButton);
	PrepareClass(RichTextStyleListCtrl);
	PrepareClass(ScrollBar);
	PrepareClass(Slider);
	PrepareClass(SpinButton);
	PrepareClass(SpinCtrl);
	PrepareClass(StaticBitmap);
	PrepareClass(StaticBox);
	PrepareClass(StaticLine);
	PrepareClass(StaticText);
	PrepareClass(TextCtrl);
	PrepareClass(StyledTextCtrl);
	PrepareClass(ToggleButton);
	PrepareClass(TreeCtrl);
	PrepareClass(GLCanvas);
	PrepareClass(HtmlHelpDialog);
	PrepareClass(HtmlHelpWindow);
	PrepareClass(MDIClientWindow);
	PrepareClass(MenuBar);
	PrepareClass(Panel);
	PrepareClass(PreviewControlBar);
	PrepareClass(ScrolledWindow);
	PrepareClass(Grid);
	PrepareClass(HtmlWindow);
	PrepareClass(PreviewCanvas);
	PrepareClass(VScrolledWindow);
	PrepareClass(VListBox);
	PrepareClass(HtmlListBox);
	PrepareClass(SimpleHtmlListBox);
	PrepareClass(RichTextStyleListBox);
	PrepareClass(WizardPage);
	PrepareClass(WizardPageSimple);
	PrepareClass(SashWindow);
	PrepareClass(SashLayoutWindow);
	PrepareClass(SearchCtrl);
	PrepareClass(SplitterWindow);
	PrepareClass(StatusBar);
	PrepareClass(TopLevelWindow);
	PrepareClass(Dialog);
	PrepareClass(ColourDialog);
	PrepareClass(DirDialog);
	PrepareClass(FileDialog);
	PrepareClass(FindReplaceDialog);
	PrepareClass(FontDialog);
	PrepareClass(MessageDialog);
	PrepareClass(MultiChoiceDialog);
	PrepareClass(ProgressDialog);
	PrepareClass(PropertySheetDialog);
	PrepareClass(RichTextFormattingDialog);
	PrepareClass(RichTextStyleOrganiserDialog);
	PrepareClass(SingleChoiceDialog);
	PrepareClass(SymbolPickerDialog);
	PrepareClass(TextEntryDialog);
	PrepareClass(PasswordEntryDialog);
	PrepareClass(Wizard);
	PrepareClass(Frame);
	PrepareClass(DocChildFrame);
	PrepareClass(DocParentFrame);
	PrepareClass(HtmlHelpFrame);
	PrepareClass(MDIChildFrame);
	PrepareClass(DocMDIChildFrame);
	PrepareClass(MDIParentFrame);
	PrepareClass(DocMDIParentFrame);
	PrepareClass(MiniFrame);
	PrepareClass(PreviewFrame);
	PrepareClass(SplashScreen);
	PrepareClass(FileHistory);
	PrepareClass(FileSystem);
	PrepareClass(FileSystemHandler);
	PrepareClass(MemoryFSHandler);
	PrepareClass(FilterClassFactory);
	PrepareClass(FindReplaceData);
	PrepareClass(FontData);
	PrepareClass(FSFile);
	PrepareClass(GDIObject);
	PrepareClass(Animation);
	PrepareClass(Bitmap);
	PrepareClass(Brush);
	PrepareClass(Cursor);
	PrepareClass(Font);
	PrepareClass(Icon);
	PrepareClass(Palette);
	PrepareClass(Pen);
	PrepareClass(Region);
	PrepareClass(GLContext);
	PrepareClass(GridTableBase);
	PrepareClass(HashTable);
	PrepareClass(HtmlCell);
	PrepareClass(HtmlColourCell);
	PrepareClass(HtmlContainerCell);
	PrepareClass(HtmlWidgetCell);
	PrepareClass(HtmlDCRenderer);
	PrepareClass(HtmlEasyPrinting);
	PrepareClass(HtmlFilter);
	PrepareClass(HtmlHelpData);
	PrepareClass(HtmlLinkInfo);
	PrepareClass(HtmlParser);
	PrepareClass(HtmlWinParser);
	PrepareClass(HtmlTag);
	PrepareClass(HtmlTagHandler);
	PrepareClass(HtmlWinTagHandler);
	PrepareClass(Image);
	PrepareClass(ImageHandler);
	PrepareClass(ImageList);
	PrepareClass(IndividualLayoutConstraint);
	PrepareClass(Joystick);
	PrepareClass(LayoutAlgorithm);
	PrepareClass(LayoutConstraints);
	PrepareClass(ListItem);
	PrepareClass(Mask);
	PrepareClass(MenuItem);
_MS(PrepareClass(Metafile));
	PrepareClass(Module);
	PrepareClass(HtmlTagsModule);
	PrepareClass(PageSetupDialog);
	PrepareClass(PageSetupDialogData);
	PrepareClass(PrintData);
	PrepareClass(PrintDialog);
	PrepareClass(PrintDialogData);
	PrepareClass(Printer);
	PrepareClass(Printout);
	PrepareClass(HtmlPrintout);
	PrepareClass(RichTextPrintout);
	PrepareClass(PrintPreview);
	PrepareClass(Quantize);
	PrepareClass(RegionIterator);
	PrepareClass(RichTextFileHandler);
	PrepareClass(RichTextHTMLHandler);
	PrepareClass(RichTextXMLHandler);
	PrepareClass(RichTextFormattingDialogFactory);
	PrepareClass(RichTextHeaderFooterData);
	PrepareClass(RichTextPrinting);
	PrepareClass(RichTextStyleDefinition);
	PrepareClass(RichTextCharacterStyleDefinition);
	PrepareClass(RichTextParagraphStyleDefinition);
	PrepareClass(RichTextListStyleDefinition);
	PrepareClass(RichTextStyleSheet);
	PrepareClass(Sizer);
	PrepareClass(BoxSizer);
	PrepareClass(StaticBoxSizer);
	PrepareClass(StdDialogButtonSizer);
	PrepareClass(GridSizer);
	PrepareClass(FlexGridSizer);
	PrepareClass(GridBagSizer);
	PrepareClass(SizerItem);
	PrepareClass(GBSizerItem);
	PrepareClass(SockAddress);
	PrepareClass(IPaddress);
	PrepareClass(IPV4address);
	PrepareClass(SocketBase);
	PrepareClass(DatagramSocket);
	PrepareClass(SocketClient);
	PrepareClass(Protocol);
	PrepareClass(FTP);
	PrepareClass(HTTP);
	PrepareClass(SocketServer);
	PrepareClass(Sound);
	PrepareClass(StringTokenizer);
	PrepareClass(SystemOptions);
	PrepareClass(ToolTip);
	PrepareClass(URI);
	PrepareClass(URL);
	PrepareClass(Variant);
	PrepareClass(XmlDocument);
	PrepareClass(XmlResource);
	PrepareClass(XmlResourceHandler);
	PrepareClass(ObjectRefData);
	PrepareClass(VariantData);
	PrepareClass(ClientBase);
	PrepareClass(Client);
_MS(PrepareClass(DDEClient));
	PrepareClass(TCPClient);
	PrepareClass(PenList);
	PrepareClass(PlatformInfo);
	PrepareClass(Point);
	PrepareClass(RealPoint);
	PrepareClass(Rect);
	PrepareClass(RecursionGuard);
	PrepareClass(RegEx);
_MS(PrepareClass(RegKey));
	PrepareClass(RendererNative);
	PrepareClass(DelegateRendererNative);
	PrepareClass(RendererVersion);
	PrepareClass(RichTextAttr);
	PrepareClass(RichTextParagraphLayoutBox);
	PrepareClass(RichTextBuffer);
	PrepareClass(RichTextRange);
	PrepareClass(Semaphore);
	PrepareClass(SingleInstanceChecker);
	PrepareClass(Size);
	PrepareClass(SizerFlags);
	PrepareClass(SplitterRenderParams);
	PrepareClass(StackFrame);
	PrepareClass(StackWalker);
	PrepareClass(StandardPaths);
	PrepareClass(StopWatch);
	PrepareClass(StreamBase);
	PrepareClass(InputStream);
	PrepareClass(FFileInputStream);
	PrepareClass(FileInputStream);
	PrepareClass(FilterInputStream);
	PrepareClass(ArchiveInputStream);
	PrepareClass(TarInputStream);
	PrepareClass(ZipInputStream);
	PrepareClass(BufferedInputStream);
	PrepareClass(ZlibInputStream);
	PrepareClass(MemoryInputStream);
	PrepareClass(SocketInputStream);
	PrepareClass(StringInputStream);
	PrepareClass(OutputStream);
	PrepareClass(CountingOutputStream);
	PrepareClass(FFileOutputStream);
	PrepareClass(FFileStream);
	PrepareClass(FileOutputStream);
	PrepareClass(FileStream);
	PrepareClass(FilterOutputStream);
	PrepareClass(ArchiveOutputStream);
	PrepareClass(TarOutputStream);
	PrepareClass(ZipOutputStream);
	PrepareClass(BufferedOutputStream);
	PrepareClass(ZlibOutputStream);
	PrepareClass(MemoryOutputStream);
	PrepareClass(SocketOutputStream);
	PrepareClass(StringOutputStream);
	PrepareClass(TempFileOutputStream);
	PrepareClass(StreamBuffer);
	PrepareClass(String);
	PrepareClass(StringBuffer);
	PrepareClass(StringBufferLength);
	PrepareClass(SystemSettings);
	PrepareClass(TempFile);
	PrepareClass(TextAttr);
	PrepareClass(TextAttrEx);
	PrepareClass(TextFile);
	PrepareClass(TextInputStream);
	PrepareClass(TextOutputStream);
_MS(PrepareClass(Thread));
_MS(PrepareClass(ThreadHelper));
	PrepareClass(TimeSpan);
	PrepareClass(TipProvider);
	PrepareClass(TreeItemId);
	PrepareClass(WindowUpdateLocker);
	PrepareClass(WindowDisabler);
	PrepareClass(XmlNode);
	PrepareClass(XmlProperty);
	PrepareClass(ZipNotifier);
	PrepareClass(NativeEncodingInfo);
	PrepareClass(NativeFontInfo);
	PrepareClass(FileTypeInfo);
	PrepareClass(ArchiveNotifier);
	PrepareClass(ArtClient);
	PrepareClass(BMPHandler);
	PrepareClass(GIFHandler);
	PrepareClass(JPEGHandler);
	PrepareClass(PCXHandler);
	PrepareClass(PNGHandler);
	PrepareClass(PNMHandler);
	PrepareClass(TGAHandler);
	PrepareClass(TIFFHandler);
	PrepareClass(XPMHandler);
	PrepareClass(AppConsole);
	PrepareClass(GridCellCoords);
	PrepareClass(GridCellAttrProvider);
	PrepareClass(PageSetupData);
	PrepareClass(ToolBarToolBase);
	PrepareClass(HtmlWindowInterface);
	PrepareClass(HtmlTagsCache);
	PrepareClass(HtmlEntitiesParser);
	PrepareClass(RichTextObject);
	PrepareClass(RichTextImageBlock);
	PrepareClass(RichTextRenderer);
	PrepareClass(RichTextAction);
	PrepareClass(VersionInfo);
	RegisterFunctions(env, sig);
	// value assignments
	do {
		Gura_AssignWxValue(ID_ANY);
		Gura_AssignWxValue(ID_LOWEST);
		Gura_AssignWxValue(ID_OPEN);
		Gura_AssignWxValue(ID_CLOSE);
		Gura_AssignWxValue(ID_NEW);
		Gura_AssignWxValue(ID_SAVE);
		Gura_AssignWxValue(ID_SAVEAS);
		Gura_AssignWxValue(ID_REVERT);
		Gura_AssignWxValue(ID_EXIT);
		Gura_AssignWxValue(ID_UNDO);
		Gura_AssignWxValue(ID_REDO);
		Gura_AssignWxValue(ID_HELP);
		Gura_AssignWxValue(ID_PRINT);
		Gura_AssignWxValue(ID_PRINT_SETUP);
		Gura_AssignWxValue(ID_PAGE_SETUP);
		Gura_AssignWxValue(ID_PREVIEW);
		Gura_AssignWxValue(ID_ABOUT);
		Gura_AssignWxValue(ID_HELP_CONTENTS);
		Gura_AssignWxValue(ID_HELP_INDEX);
		Gura_AssignWxValue(ID_HELP_SEARCH);
		Gura_AssignWxValue(ID_HELP_COMMANDS);
		Gura_AssignWxValue(ID_HELP_PROCEDURES);
		Gura_AssignWxValue(ID_HELP_CONTEXT);
		Gura_AssignWxValue(ID_CLOSE_ALL);
		Gura_AssignWxValue(ID_PREFERENCES);
		Gura_AssignWxValue(ID_EDIT);
		Gura_AssignWxValue(ID_CUT);
		Gura_AssignWxValue(ID_COPY);
		Gura_AssignWxValue(ID_PASTE);
		Gura_AssignWxValue(ID_CLEAR);
		Gura_AssignWxValue(ID_FIND);
		Gura_AssignWxValue(ID_DUPLICATE);
		Gura_AssignWxValue(ID_SELECTALL);
		Gura_AssignWxValue(ID_DELETE);
		Gura_AssignWxValue(ID_REPLACE);
		Gura_AssignWxValue(ID_REPLACE_ALL);
		Gura_AssignWxValue(ID_PROPERTIES);
		Gura_AssignWxValue(ID_VIEW_DETAILS);
		Gura_AssignWxValue(ID_VIEW_LARGEICONS);
		Gura_AssignWxValue(ID_VIEW_SMALLICONS);
		Gura_AssignWxValue(ID_VIEW_LIST);
		Gura_AssignWxValue(ID_VIEW_SORTDATE);
		Gura_AssignWxValue(ID_VIEW_SORTNAME);
		Gura_AssignWxValue(ID_VIEW_SORTSIZE);
		Gura_AssignWxValue(ID_VIEW_SORTTYPE);
		Gura_AssignWxValue(ID_FILE);
		Gura_AssignWxValue(ID_FILE1);
		Gura_AssignWxValue(ID_FILE2);
		Gura_AssignWxValue(ID_FILE3);
		Gura_AssignWxValue(ID_FILE4);
		Gura_AssignWxValue(ID_FILE5);
		Gura_AssignWxValue(ID_FILE6);
		Gura_AssignWxValue(ID_FILE7);
		Gura_AssignWxValue(ID_FILE8);
		Gura_AssignWxValue(ID_FILE9);
		// Standard button IDs
		Gura_AssignWxValue(ID_OK);
		Gura_AssignWxValue(ID_CANCEL);
		Gura_AssignWxValue(ID_APPLY);
		Gura_AssignWxValue(ID_YES);
		Gura_AssignWxValue(ID_NO);
		Gura_AssignWxValue(ID_STATIC);
		Gura_AssignWxValue(ID_FORWARD);
		Gura_AssignWxValue(ID_BACKWARD);
		Gura_AssignWxValue(ID_DEFAULT);
		Gura_AssignWxValue(ID_MORE);
		Gura_AssignWxValue(ID_SETUP);
		Gura_AssignWxValue(ID_RESET);
		Gura_AssignWxValue(ID_CONTEXT_HELP);
		Gura_AssignWxValue(ID_YESTOALL);
		Gura_AssignWxValue(ID_NOTOALL);
		Gura_AssignWxValue(ID_ABORT);
		Gura_AssignWxValue(ID_RETRY);
		Gura_AssignWxValue(ID_IGNORE);
		Gura_AssignWxValue(ID_ADD);
		Gura_AssignWxValue(ID_REMOVE);
		Gura_AssignWxValue(ID_UP);
		Gura_AssignWxValue(ID_DOWN);
		Gura_AssignWxValue(ID_HOME);
		Gura_AssignWxValue(ID_REFRESH);
		Gura_AssignWxValue(ID_STOP);
		Gura_AssignWxValue(ID_INDEX);
		Gura_AssignWxValue(ID_BOLD);
		Gura_AssignWxValue(ID_ITALIC);
		Gura_AssignWxValue(ID_JUSTIFY_CENTER);
		Gura_AssignWxValue(ID_JUSTIFY_FILL);
		Gura_AssignWxValue(ID_JUSTIFY_RIGHT);
		Gura_AssignWxValue(ID_JUSTIFY_LEFT);
		Gura_AssignWxValue(ID_UNDERLINE);
		Gura_AssignWxValue(ID_INDENT);
		Gura_AssignWxValue(ID_UNINDENT);
		Gura_AssignWxValue(ID_ZOOM_100);
		Gura_AssignWxValue(ID_ZOOM_FIT);
		Gura_AssignWxValue(ID_ZOOM_IN);
		Gura_AssignWxValue(ID_ZOOM_OUT);
		Gura_AssignWxValue(ID_UNDELETE);
		Gura_AssignWxValue(ID_REVERT_TO_SAVED);
		// System menu IDs (used by wxUniv):
		Gura_AssignWxValue(ID_SYSTEM_MENU);
		Gura_AssignWxValue(ID_CLOSE_FRAME);
		Gura_AssignWxValue(ID_MOVE_FRAME);
		Gura_AssignWxValue(ID_RESIZE_FRAME);
		Gura_AssignWxValue(ID_MAXIMIZE_FRAME);
		Gura_AssignWxValue(ID_ICONIZE_FRAME);
		Gura_AssignWxValue(ID_RESTORE_FRAME);
		// IDs used by generic file dialog (13 consecutive starting from this value)
		Gura_AssignWxValue(ID_FILEDLGG);
		Gura_AssignWxValue(ID_HIGHEST);
	} while (0);
	do { // Key Code
		Gura_AssignMacroValue(WXK_BACK);
		Gura_AssignMacroValue(WXK_TAB);
		Gura_AssignMacroValue(WXK_RETURN);
		Gura_AssignMacroValue(WXK_ESCAPE);
		Gura_AssignMacroValue(WXK_SPACE);
		Gura_AssignMacroValue(WXK_DELETE);
		Gura_AssignMacroValue(WXK_START);
		Gura_AssignMacroValue(WXK_LBUTTON);
		Gura_AssignMacroValue(WXK_RBUTTON);
		Gura_AssignMacroValue(WXK_CANCEL);
		Gura_AssignMacroValue(WXK_MBUTTON);
		Gura_AssignMacroValue(WXK_CLEAR);
		Gura_AssignMacroValue(WXK_SHIFT);
		Gura_AssignMacroValue(WXK_ALT);
		Gura_AssignMacroValue(WXK_CONTROL);
		Gura_AssignMacroValue(WXK_MENU);
		Gura_AssignMacroValue(WXK_PAUSE);
		Gura_AssignMacroValue(WXK_CAPITAL);
		Gura_AssignMacroValue(WXK_END);
		Gura_AssignMacroValue(WXK_HOME);
		Gura_AssignMacroValue(WXK_LEFT);
		Gura_AssignMacroValue(WXK_UP);
		Gura_AssignMacroValue(WXK_RIGHT);
		Gura_AssignMacroValue(WXK_DOWN);
		Gura_AssignMacroValue(WXK_SELECT);
		Gura_AssignMacroValue(WXK_PRINT);
		Gura_AssignMacroValue(WXK_EXECUTE);
		Gura_AssignMacroValue(WXK_SNAPSHOT);
		Gura_AssignMacroValue(WXK_INSERT);
		Gura_AssignMacroValue(WXK_HELP);
		Gura_AssignMacroValue(WXK_NUMPAD0);
		Gura_AssignMacroValue(WXK_NUMPAD1);
		Gura_AssignMacroValue(WXK_NUMPAD2);
		Gura_AssignMacroValue(WXK_NUMPAD3);
		Gura_AssignMacroValue(WXK_NUMPAD4);
		Gura_AssignMacroValue(WXK_NUMPAD5);
		Gura_AssignMacroValue(WXK_NUMPAD6);
		Gura_AssignMacroValue(WXK_NUMPAD7);
		Gura_AssignMacroValue(WXK_NUMPAD8);
		Gura_AssignMacroValue(WXK_NUMPAD9);
		Gura_AssignMacroValue(WXK_MULTIPLY);
		Gura_AssignMacroValue(WXK_ADD);
		Gura_AssignMacroValue(WXK_SEPARATOR);
		Gura_AssignMacroValue(WXK_SUBTRACT);
		Gura_AssignMacroValue(WXK_DECIMAL);
		Gura_AssignMacroValue(WXK_DIVIDE);
		Gura_AssignMacroValue(WXK_F1);
		Gura_AssignMacroValue(WXK_F2);
		Gura_AssignMacroValue(WXK_F3);
		Gura_AssignMacroValue(WXK_F4);
		Gura_AssignMacroValue(WXK_F5);
		Gura_AssignMacroValue(WXK_F6);
		Gura_AssignMacroValue(WXK_F7);
		Gura_AssignMacroValue(WXK_F8);
		Gura_AssignMacroValue(WXK_F9);
		Gura_AssignMacroValue(WXK_F10);
		Gura_AssignMacroValue(WXK_F11);
		Gura_AssignMacroValue(WXK_F12);
		Gura_AssignMacroValue(WXK_F13);
		Gura_AssignMacroValue(WXK_F14);
		Gura_AssignMacroValue(WXK_F15);
		Gura_AssignMacroValue(WXK_F16);
		Gura_AssignMacroValue(WXK_F17);
		Gura_AssignMacroValue(WXK_F18);
		Gura_AssignMacroValue(WXK_F19);
		Gura_AssignMacroValue(WXK_F20);
		Gura_AssignMacroValue(WXK_F21);
		Gura_AssignMacroValue(WXK_F22);
		Gura_AssignMacroValue(WXK_F23);
		Gura_AssignMacroValue(WXK_F24);
		Gura_AssignMacroValue(WXK_NUMLOCK);
		Gura_AssignMacroValue(WXK_SCROLL);
		Gura_AssignMacroValue(WXK_PAGEUP);
		Gura_AssignMacroValue(WXK_PAGEDOWN);
		Gura_AssignMacroValue(WXK_NUMPAD_SPACE);
		Gura_AssignMacroValue(WXK_NUMPAD_TAB);
		Gura_AssignMacroValue(WXK_NUMPAD_ENTER);
		Gura_AssignMacroValue(WXK_NUMPAD_F1);
		Gura_AssignMacroValue(WXK_NUMPAD_F2);
		Gura_AssignMacroValue(WXK_NUMPAD_F3);
		Gura_AssignMacroValue(WXK_NUMPAD_F4);
		Gura_AssignMacroValue(WXK_NUMPAD_HOME);
		Gura_AssignMacroValue(WXK_NUMPAD_LEFT);
		Gura_AssignMacroValue(WXK_NUMPAD_UP);
		Gura_AssignMacroValue(WXK_NUMPAD_RIGHT);
		Gura_AssignMacroValue(WXK_NUMPAD_DOWN);
		Gura_AssignMacroValue(WXK_NUMPAD_PAGEUP);
		Gura_AssignMacroValue(WXK_NUMPAD_PAGEDOWN);
		Gura_AssignMacroValue(WXK_NUMPAD_END);
		Gura_AssignMacroValue(WXK_NUMPAD_BEGIN);
		Gura_AssignMacroValue(WXK_NUMPAD_INSERT);
		Gura_AssignMacroValue(WXK_NUMPAD_DELETE);
		Gura_AssignMacroValue(WXK_NUMPAD_EQUAL);
		Gura_AssignMacroValue(WXK_NUMPAD_MULTIPLY);
		Gura_AssignMacroValue(WXK_NUMPAD_ADD);
		Gura_AssignMacroValue(WXK_NUMPAD_SEPARATOR);
		Gura_AssignMacroValue(WXK_NUMPAD_SUBTRACT);
		Gura_AssignMacroValue(WXK_NUMPAD_DECIMAL);
		Gura_AssignMacroValue(WXK_NUMPAD_DIVIDE);
		Gura_AssignMacroValue(WXK_WINDOWS_LEFT);
		Gura_AssignMacroValue(WXK_WINDOWS_RIGHT);
		Gura_AssignMacroValue(WXK_WINDOWS_MENU);
		Gura_AssignMacroValue(WXK_COMMAND);
		Gura_AssignMacroValue(WXK_SPECIAL1);
		Gura_AssignMacroValue(WXK_SPECIAL2);
		Gura_AssignMacroValue(WXK_SPECIAL3);
		Gura_AssignMacroValue(WXK_SPECIAL4);
		Gura_AssignMacroValue(WXK_SPECIAL5);
		Gura_AssignMacroValue(WXK_SPECIAL6);
		Gura_AssignMacroValue(WXK_SPECIAL7);
		Gura_AssignMacroValue(WXK_SPECIAL8);
		Gura_AssignMacroValue(WXK_SPECIAL9);
		Gura_AssignMacroValue(WXK_SPECIAL10);
		Gura_AssignMacroValue(WXK_SPECIAL11);
		Gura_AssignMacroValue(WXK_SPECIAL12);
		Gura_AssignMacroValue(WXK_SPECIAL13);
		Gura_AssignMacroValue(WXK_SPECIAL14);
		Gura_AssignMacroValue(WXK_SPECIAL15);
		Gura_AssignMacroValue(WXK_SPECIAL16);
		Gura_AssignMacroValue(WXK_SPECIAL17);
		Gura_AssignMacroValue(WXK_SPECIAL18);
		Gura_AssignMacroValue(WXK_SPECIAL19);
		Gura_AssignMacroValue(WXK_SPECIAL20);
	} while (0);
	do { // wxAnimationType
		Gura_AssignWxValue(ANIMATION_TYPE_GIF);
		Gura_AssignWxValue(ANIMATION_TYPE_ANI);
		Gura_AssignWxValue(ANIMATION_TYPE_ANY);
	} while (0);
	do { // wxCalendarDateBorder
		Gura_AssignWxValue(CAL_BORDER_NONE);
		Gura_AssignWxValue(CAL_BORDER_SQUARE);
		Gura_AssignWxValue(CAL_BORDER_ROUND);
	} while (0);
	do {
		Gura_AssignWxValue(TOP);
		Gura_AssignWxValue(BOTTOM);
		Gura_AssignWxValue(LEFT);
		Gura_AssignWxValue(RIGHT);
		Gura_AssignWxValue(CENTRE);
		Gura_AssignWxValue(ALL);
		Gura_AssignWxValue(BOTH);
		Gura_AssignWxValue(VERTICAL);
		Gura_AssignWxValue(HORIZONTAL);
		Gura_AssignWxValue(BORDER_SIMPLE);
		Gura_AssignWxValue(BORDER_DOUBLE);
		Gura_AssignWxValue(MOUSE_BTN_LEFT);
		Gura_AssignWxValue(MOUSE_BTN_MIDDLE);
		Gura_AssignWxValue(MOUSE_BTN_RIGHT);
		Gura_AssignWxValue(MOUSE_BTN_ANY);
		Gura_AssignWxValue(NOT_FOUND);
	} while (0);
	do { // wxStreamProtocolType
		Gura_AssignWxValue(STREAM_PROTOCOL);
		Gura_AssignWxValue(STREAM_MIMETYPE);
		Gura_AssignWxValue(STREAM_ENCODING);
		Gura_AssignWxValue(STREAM_FILEEXT);
	} while (0);
	do { // wxPathFormat
		Gura_AssignWxValue(PATH_NATIVE);
		Gura_AssignWxValue(PATH_UNIX);
		Gura_AssignWxValue(PATH_BEOS);
		Gura_AssignWxValue(PATH_MAC);
		Gura_AssignWxValue(PATH_DOS);
		Gura_AssignWxValue(PATH_WIN);
		Gura_AssignWxValue(PATH_OS2);
		Gura_AssignWxValue(PATH_VMS);
	} while (0);
	do { // wxUpdateUIMode
		Gura_AssignWxValue(UPDATE_UI_PROCESS_ALL);
		Gura_AssignWxValue(UPDATE_UI_PROCESS_SPECIFIED);
	} while (0);
	do { // Styles for Pen and Brush
		Gura_AssignWxValue(SOLID);
		Gura_AssignWxValue(TRANSPARENT);
		Gura_AssignWxValue(DOT);
		Gura_AssignWxValue(LONG_DASH);
		Gura_AssignWxValue(SHORT_DASH);
		Gura_AssignWxValue(DOT_DASH);
		Gura_AssignWxValue(STIPPLE);
		Gura_AssignWxValue(USER_DASH);
		Gura_AssignWxValue(BDIAGONAL_HATCH);
		Gura_AssignWxValue(CROSSDIAG_HATCH);
		Gura_AssignWxValue(FDIAGONAL_HATCH);
		Gura_AssignWxValue(CROSS_HATCH);
		Gura_AssignWxValue(HORIZONTAL_HATCH);
		Gura_AssignWxValue(VERTICAL_HATCH);
	} while (0);
	do { // Styles for Pen
		Gura_AssignWxValue(PENSTYLE_INVALID);
		Gura_AssignWxValue(PENSTYLE_SOLID);
		Gura_AssignWxValue(PENSTYLE_DOT);
		Gura_AssignWxValue(PENSTYLE_LONG_DASH);
		Gura_AssignWxValue(PENSTYLE_SHORT_DASH);
		Gura_AssignWxValue(PENSTYLE_DOT_DASH);
		Gura_AssignWxValue(PENSTYLE_USER_DASH);
		Gura_AssignWxValue(PENSTYLE_TRANSPARENT);
		Gura_AssignWxValue(PENSTYLE_STIPPLE_MASK_OPAQUE);
		Gura_AssignWxValue(PENSTYLE_STIPPLE_MASK);
		Gura_AssignWxValue(PENSTYLE_STIPPLE);
		Gura_AssignWxValue(PENSTYLE_BDIAGONAL_HATCH);
		Gura_AssignWxValue(PENSTYLE_CROSSDIAG_HATCH);
		Gura_AssignWxValue(PENSTYLE_FDIAGONAL_HATCH);
		Gura_AssignWxValue(PENSTYLE_CROSS_HATCH);
		Gura_AssignWxValue(PENSTYLE_HORIZONTAL_HATCH);
		Gura_AssignWxValue(PENSTYLE_VERTICAL_HATCH);
		Gura_AssignWxValue(PENSTYLE_FIRST_HATCH);
		Gura_AssignWxValue(PENSTYLE_LAST_HATCH);
	} while (0);
	do { // Styles for Brush
		Gura_AssignWxValue(BRUSHSTYLE_INVALID);
		Gura_AssignWxValue(BRUSHSTYLE_SOLID);
		Gura_AssignWxValue(BRUSHSTYLE_TRANSPARENT);
		Gura_AssignWxValue(BRUSHSTYLE_STIPPLE_MASK_OPAQUE);
		Gura_AssignWxValue(BRUSHSTYLE_STIPPLE_MASK);
		Gura_AssignWxValue(BRUSHSTYLE_STIPPLE);
		Gura_AssignWxValue(BRUSHSTYLE_BDIAGONAL_HATCH);
		Gura_AssignWxValue(BRUSHSTYLE_CROSSDIAG_HATCH);
		Gura_AssignWxValue(BRUSHSTYLE_FDIAGONAL_HATCH);
		Gura_AssignWxValue(BRUSHSTYLE_CROSS_HATCH);
		Gura_AssignWxValue(BRUSHSTYLE_HORIZONTAL_HATCH);
		Gura_AssignWxValue(BRUSHSTYLE_VERTICAL_HATCH);
		Gura_AssignWxValue(BRUSHSTYLE_FIRST_HATCH);
		Gura_AssignWxValue(BRUSHSTYLE_LAST_HATCH);
	} while (0);
	do { // wxBitmapType
		Gura_AssignWxValue(BITMAP_TYPE_INVALID);
		Gura_AssignWxValue(BITMAP_TYPE_BMP);
		Gura_AssignWxValue(BITMAP_TYPE_BMP_RESOURCE);
		Gura_AssignWxValue(BITMAP_TYPE_RESOURCE);
		Gura_AssignWxValue(BITMAP_TYPE_ICO);
		Gura_AssignWxValue(BITMAP_TYPE_ICO_RESOURCE);
		Gura_AssignWxValue(BITMAP_TYPE_CUR);
		Gura_AssignWxValue(BITMAP_TYPE_CUR_RESOURCE);
		Gura_AssignWxValue(BITMAP_TYPE_XBM);
		Gura_AssignWxValue(BITMAP_TYPE_XBM_DATA);
		Gura_AssignWxValue(BITMAP_TYPE_XPM);
		Gura_AssignWxValue(BITMAP_TYPE_XPM_DATA);
		Gura_AssignWxValue(BITMAP_TYPE_TIFF);
		Gura_AssignWxValue(BITMAP_TYPE_TIF);
		Gura_AssignWxValue(BITMAP_TYPE_TIFF_RESOURCE);
		Gura_AssignWxValue(BITMAP_TYPE_TIF_RESOURCE);
		Gura_AssignWxValue(BITMAP_TYPE_GIF);
		Gura_AssignWxValue(BITMAP_TYPE_GIF_RESOURCE);
		Gura_AssignWxValue(BITMAP_TYPE_PNG);
		Gura_AssignWxValue(BITMAP_TYPE_PNG_RESOURCE);
		Gura_AssignWxValue(BITMAP_TYPE_JPEG);
		Gura_AssignWxValue(BITMAP_TYPE_JPEG_RESOURCE);
		Gura_AssignWxValue(BITMAP_TYPE_PNM);
		Gura_AssignWxValue(BITMAP_TYPE_PNM_RESOURCE);
		Gura_AssignWxValue(BITMAP_TYPE_PCX);
		Gura_AssignWxValue(BITMAP_TYPE_PCX_RESOURCE);
		Gura_AssignWxValue(BITMAP_TYPE_PICT);
		Gura_AssignWxValue(BITMAP_TYPE_PICT_RESOURCE);
		Gura_AssignWxValue(BITMAP_TYPE_ICON);
		Gura_AssignWxValue(BITMAP_TYPE_ICON_RESOURCE);
		Gura_AssignWxValue(BITMAP_TYPE_ANI);
		Gura_AssignWxValue(BITMAP_TYPE_IFF);
		Gura_AssignWxValue(BITMAP_TYPE_TGA);
		Gura_AssignWxValue(BITMAP_TYPE_MACCURSOR);
		Gura_AssignWxValue(BITMAP_TYPE_MACCURSOR_RESOURCE);
		Gura_AssignWxValue(BITMAP_TYPE_ANY);
		Gura_AssignWxValue(ICON_DEFAULT_TYPE);
	} while (0);
	do {
		Gura_AssignWxValue(HTML_URL_PAGE);
		Gura_AssignWxValue(HTML_URL_IMAGE);
		Gura_AssignWxValue(HTML_URL_OTHER);
	} while (0);
	do { // Style for wx.BufferedDC
		Gura_AssignWxValue(BUFFER_CLIENT_AREA);
		Gura_AssignWxValue(BUFFER_VIRTUAL_AREA);
	} while (0);
	do { // Fill Style
		Gura_AssignWxValue(ODDEVEN_RULE);
		Gura_AssignWxValue(WINDING_RULE);
	} while (0);
	do {
		Gura_AssignWxValue(ACCEL_ALT);
		Gura_AssignWxValue(ACCEL_SHIFT);
		Gura_AssignWxValue(ACCEL_CTRL);
		Gura_AssignWxValue(ACCEL_NORMAL);
	} while (0);
	do {
		Gura_AssignWxValue(CMD_LINE_SWITCH);
		Gura_AssignWxValue(CMD_LINE_OPTION);
		Gura_AssignWxValue(CMD_LINE_PARAM);
		Gura_AssignWxValue(CMD_LINE_NONE);
		Gura_AssignWxValue(CMD_LINE_VAL_STRING);
		Gura_AssignWxValue(CMD_LINE_VAL_NUMBER);
		Gura_AssignWxValue(CMD_LINE_VAL_DATE);
		Gura_AssignWxValue(CMD_LINE_VAL_NONE);
		Gura_AssignWxValue(CMD_LINE_OPTION_MANDATORY);
		Gura_AssignWxValue(CMD_LINE_PARAM_OPTIONAL);
		Gura_AssignWxValue(CMD_LINE_PARAM_MULTIPLE);
		Gura_AssignWxValue(CMD_LINE_OPTION_HELP);
		Gura_AssignWxValue(CMD_LINE_NEEDS_SEPARATOR);
	} while (0);
	do {
		Gura_AssignWxValue(ALPHA_TRANSPARENT);
		Gura_AssignWxValue(ALPHA_OPAQUE);
		Gura_AssignWxValue(C2S_NAME);
		Gura_AssignWxValue(C2S_CSS_SYNTAX);
		Gura_AssignWxValue(C2S_HTML_SYNTAX);
	} while (0);
	do {
		Gura_AssignWxValue(CURSOR_ARROW);
		Gura_AssignWxValue(CURSOR_RIGHT_ARROW);
		Gura_AssignWxValue(CURSOR_BLANK);
		Gura_AssignWxValue(CURSOR_BULLSEYE);
		Gura_AssignWxValue(CURSOR_CHAR);
		Gura_AssignWxValue(CURSOR_CROSS);
		Gura_AssignWxValue(CURSOR_HAND);
		Gura_AssignWxValue(CURSOR_IBEAM);
		Gura_AssignWxValue(CURSOR_LEFT_BUTTON);
		Gura_AssignWxValue(CURSOR_MAGNIFIER);
		Gura_AssignWxValue(CURSOR_MIDDLE_BUTTON);
		Gura_AssignWxValue(CURSOR_NO_ENTRY);
		Gura_AssignWxValue(CURSOR_PAINT_BRUSH);
		Gura_AssignWxValue(CURSOR_PENCIL);
		Gura_AssignWxValue(CURSOR_POINT_LEFT);
		Gura_AssignWxValue(CURSOR_POINT_RIGHT);
		Gura_AssignWxValue(CURSOR_QUESTION_ARROW);
		Gura_AssignWxValue(CURSOR_RIGHT_BUTTON);
		Gura_AssignWxValue(CURSOR_SIZENESW);
		Gura_AssignWxValue(CURSOR_SIZENS);
		Gura_AssignWxValue(CURSOR_SIZENWSE);
		Gura_AssignWxValue(CURSOR_SIZEWE);
		Gura_AssignWxValue(CURSOR_SIZING);
		Gura_AssignWxValue(CURSOR_SPRAYCAN);
		Gura_AssignWxValue(CURSOR_WAIT);
		Gura_AssignWxValue(CURSOR_WATCH);
		Gura_AssignWxValue(CURSOR_ARROWWAIT);
	} while (0);
	do {
		Gura_AssignWxValue(FD_DEFAULT_STYLE);
		Gura_AssignWxValue(FD_OPEN);
		Gura_AssignWxValue(FD_SAVE);
		Gura_AssignWxValue(FD_OVERWRITE_PROMPT);
		Gura_AssignWxValue(FD_FILE_MUST_EXIST);
		Gura_AssignWxValue(FD_MULTIPLE);
		Gura_AssignWxValue(FD_CHANGE_DIR);
		Gura_AssignWxValue(FD_PREVIEW);
	} while (0);
	do {
		Gura_AssignWxValue(FLEX_GROWMODE_NONE);
		Gura_AssignWxValue(FLEX_GROWMODE_SPECIFIED);
		Gura_AssignWxValue(FLEX_GROWMODE_ALL);
	} while (0);
	do {
		Gura_AssignWxValue(FONTFAMILY_DEFAULT);
		Gura_AssignWxValue(FONTFAMILY_DECORATIVE);
		Gura_AssignWxValue(FONTFAMILY_ROMAN);
		Gura_AssignWxValue(FONTFAMILY_SCRIPT);
		Gura_AssignWxValue(FONTFAMILY_SWISS);
		Gura_AssignWxValue(FONTFAMILY_MODERN);
		Gura_AssignWxValue(FONTFAMILY_TELETYPE);
	} while (0);
	do {
		Gura_AssignWxValue(FONTSTYLE_NORMAL);
		Gura_AssignWxValue(FONTSTYLE_SLANT);
		Gura_AssignWxValue(FONTSTYLE_ITALIC);
	} while (0);
	do {
		Gura_AssignWxValue(FONTWEIGHT_NORMAL);
		Gura_AssignWxValue(FONTWEIGHT_LIGHT);
		Gura_AssignWxValue(FONTWEIGHT_BOLD);
	} while (0);
	do {
		Gura_AssignWxValue(FONTFLAG_DEFAULT);
		Gura_AssignWxValue(FONTFLAG_ITALIC);
		Gura_AssignWxValue(FONTFLAG_SLANT);
		Gura_AssignWxValue(FONTFLAG_LIGHT);
		Gura_AssignWxValue(FONTFLAG_BOLD);
		Gura_AssignWxValue(FONTFLAG_ANTIALIASED);
		Gura_AssignWxValue(FONTFLAG_NOT_ANTIALIASED);
		Gura_AssignWxValue(FONTFLAG_UNDERLINED);
		Gura_AssignWxValue(FONTFLAG_STRIKETHROUGH);
	} while (0);
	do {
		Gura_AssignWxValue(FONTENCODING_SYSTEM);
		Gura_AssignWxValue(FONTENCODING_DEFAULT);
		Gura_AssignWxValue(FONTENCODING_ISO8859_1);
		Gura_AssignWxValue(FONTENCODING_ISO8859_2);
		Gura_AssignWxValue(FONTENCODING_ISO8859_3);
		Gura_AssignWxValue(FONTENCODING_ISO8859_4);
		Gura_AssignWxValue(FONTENCODING_ISO8859_5);
		Gura_AssignWxValue(FONTENCODING_ISO8859_6);
		Gura_AssignWxValue(FONTENCODING_ISO8859_7);
		Gura_AssignWxValue(FONTENCODING_ISO8859_8);
		Gura_AssignWxValue(FONTENCODING_ISO8859_9);
		Gura_AssignWxValue(FONTENCODING_ISO8859_10);
		Gura_AssignWxValue(FONTENCODING_ISO8859_11);
		Gura_AssignWxValue(FONTENCODING_ISO8859_12);
		Gura_AssignWxValue(FONTENCODING_ISO8859_13);
		Gura_AssignWxValue(FONTENCODING_ISO8859_14);
		Gura_AssignWxValue(FONTENCODING_ISO8859_15);
		Gura_AssignWxValue(FONTENCODING_KOI8);
		Gura_AssignWxValue(FONTENCODING_ALTERNATIVE);
		Gura_AssignWxValue(FONTENCODING_BULGARIAN);
		Gura_AssignWxValue(FONTENCODING_CP437);
		Gura_AssignWxValue(FONTENCODING_CP850);
		Gura_AssignWxValue(FONTENCODING_CP852);
		Gura_AssignWxValue(FONTENCODING_CP855);
		Gura_AssignWxValue(FONTENCODING_CP866);
		Gura_AssignWxValue(FONTENCODING_CP874);
		Gura_AssignWxValue(FONTENCODING_CP1250);
		Gura_AssignWxValue(FONTENCODING_CP1251);
		Gura_AssignWxValue(FONTENCODING_CP1252);
		Gura_AssignWxValue(FONTENCODING_CP1253);
		Gura_AssignWxValue(FONTENCODING_CP1254);
		Gura_AssignWxValue(FONTENCODING_CP1255);
		Gura_AssignWxValue(FONTENCODING_CP1256);
		Gura_AssignWxValue(FONTENCODING_CP1257);
		Gura_AssignWxValue(FONTENCODING_UTF7);
		Gura_AssignWxValue(FONTENCODING_UTF8);
		Gura_AssignWxValue(FONTENCODING_UNICODE);
	} while (0);
	do {
		Gura_AssignWxValue(IDLE_PROCESS_ALL);
		Gura_AssignWxValue(IDLE_PROCESS_SPECIFIED);
	} while (0);
	do {
		Gura_AssignWxValue(IMAGELIST_DRAW_NORMAL);
		Gura_AssignWxValue(IMAGELIST_DRAW_TRANSPARENT);
		Gura_AssignWxValue(IMAGELIST_DRAW_SELECTED);
		Gura_AssignWxValue(IMAGELIST_DRAW_FOCUSED);
	} while (0);
	do {
		Gura_AssignWxValue(JOY_BUTTON_ANY);
		Gura_AssignWxValue(JOY_BUTTON1);
		Gura_AssignWxValue(JOY_BUTTON2);
		Gura_AssignWxValue(JOY_BUTTON3);
		Gura_AssignWxValue(JOY_BUTTON4);
	} while (0);
	do {
		Gura_AssignWxValue(JOYSTICK1);
		Gura_AssignWxValue(JOYSTICK2);
	} while (0);
	do {
		Gura_AssignWxValue(LIST_ALIGN_DEFAULT);
		Gura_AssignWxValue(LIST_ALIGN_LEFT);
		Gura_AssignWxValue(LIST_ALIGN_TOP);
		Gura_AssignWxValue(LIST_ALIGN_SNAP_TO_GRID);
	} while (0);
	do {
		Gura_AssignWxValue(LIST_NEXT_ABOVE);
		Gura_AssignWxValue(LIST_NEXT_ALL);
		Gura_AssignWxValue(LIST_NEXT_BELOW);
		Gura_AssignWxValue(LIST_NEXT_LEFT);
		Gura_AssignWxValue(LIST_NEXT_RIGHT);
	} while (0);
	do {
		Gura_AssignWxValue(LIST_STATE_DONTCARE);
		Gura_AssignWxValue(LIST_STATE_DROPHILITED);
		Gura_AssignWxValue(LIST_STATE_FOCUSED);
		Gura_AssignWxValue(LIST_STATE_SELECTED);
		Gura_AssignWxValue(LIST_STATE_CUT);
	} while (0);
	do {
		Gura_AssignWxValue(LIST_MASK_STATE);
		Gura_AssignWxValue(LIST_MASK_TEXT);
		Gura_AssignWxValue(LIST_MASK_IMAGE);
		Gura_AssignWxValue(LIST_MASK_DATA);
		Gura_AssignWxValue(LIST_MASK_WIDTH);
		Gura_AssignWxValue(LIST_MASK_FORMAT);
	} while (0);
	do {
		Gura_AssignWxValue(LIST_FORMAT_LEFT);
		Gura_AssignWxValue(LIST_FORMAT_RIGHT);
		Gura_AssignWxValue(LIST_FORMAT_CENTRE);
	} while (0);
	do {
		Gura_AssignWxValue(LIST_HITTEST_ABOVE);
		Gura_AssignWxValue(LIST_HITTEST_BELOW);
		Gura_AssignWxValue(LIST_HITTEST_NOWHERE);
		Gura_AssignWxValue(LIST_HITTEST_ONITEMICON);
		Gura_AssignWxValue(LIST_HITTEST_ONITEMLABEL);
		Gura_AssignWxValue(LIST_HITTEST_ONITEMRIGHT);
		Gura_AssignWxValue(LIST_HITTEST_ONITEMSTATEICON);
		Gura_AssignWxValue(LIST_HITTEST_TOLEFT);
		Gura_AssignWxValue(LIST_HITTEST_TORIGHT);
		Gura_AssignWxValue(LIST_HITTEST_ONITEM);
	} while (0);
	do {
		Gura_AssignWxValue(LIST_AUTOSIZE);
		Gura_AssignWxValue(LIST_STATE_DONTCARE);
	} while (0);
	do {
		Gura_AssignWxValue(OK);
		Gura_AssignWxValue(CANCEL);
		Gura_AssignWxValue(YES_NO);
		Gura_AssignWxValue(HELP);
		Gura_AssignWxValue(NO_DEFAULT);
		Gura_AssignWxValue(CANCEL_DEFAULT);
		Gura_AssignWxValue(YES_DEFAULT);
		Gura_AssignWxValue(OK_DEFAULT);
		Gura_AssignWxValue(YES);
		Gura_AssignWxValue(NO);
	} while (0);
	do {
		Gura_AssignWxValue(ICON_NONE);
		Gura_AssignWxValue(ICON_EXCLAMATION);
		Gura_AssignWxValue(ICON_HAND);
		Gura_AssignWxValue(ICON_ERROR);
		Gura_AssignWxValue(ICON_QUESTION);
		Gura_AssignWxValue(ICON_INFORMATION);
		Gura_AssignWxValue(ICON_AUTH_NEEDED);
	} while (0);
	do {
		Gura_AssignWxValue(JOIN_INVALID);
		Gura_AssignWxValue(JOIN_BEVEL);
		Gura_AssignWxValue(JOIN_ROUND);
		Gura_AssignWxValue(JOIN_MITER);
	} while (0);
	do {
		Gura_AssignWxValue(TEXT_ALIGNMENT_DEFAULT);
		Gura_AssignWxValue(TEXT_ALIGNMENT_LEFT);
		Gura_AssignWxValue(TEXT_ALIGNMENT_CENTRE);
		Gura_AssignWxValue(TEXT_ALIGNMENT_CENTER);
		Gura_AssignWxValue(TEXT_ALIGNMENT_RIGHT);
		Gura_AssignWxValue(TEXT_ALIGNMENT_JUSTIFIED);
	} while (0);
	do {
		Gura_AssignWxValue(TEXT_ATTR_TEXT_COLOUR);
		Gura_AssignWxValue(TEXT_ATTR_BACKGROUND_COLOUR);
		Gura_AssignWxValue(TEXT_ATTR_FONT_FACE);
		Gura_AssignWxValue(TEXT_ATTR_FONT_SIZE);
		Gura_AssignWxValue(TEXT_ATTR_FONT_WEIGHT);
		Gura_AssignWxValue(TEXT_ATTR_FONT_ITALIC);
		Gura_AssignWxValue(TEXT_ATTR_FONT_UNDERLINE);
		Gura_AssignWxValue(TEXT_ATTR_FONT);
		Gura_AssignWxValue(TEXT_ATTR_ALIGNMENT);
		Gura_AssignWxValue(TEXT_ATTR_LEFT_INDENT);
		Gura_AssignWxValue(TEXT_ATTR_RIGHT_INDENT);
		Gura_AssignWxValue(TEXT_ATTR_TABS);
		Gura_AssignWxValue(TEXT_ATTR_PARA_SPACING_AFTER);
		Gura_AssignWxValue(TEXT_ATTR_PARA_SPACING_BEFORE);
		Gura_AssignWxValue(TEXT_ATTR_LINE_SPACING);
		Gura_AssignWxValue(TEXT_ATTR_CHARACTER_STYLE_NAME);
		Gura_AssignWxValue(TEXT_ATTR_PARAGRAPH_STYLE_NAME);
		Gura_AssignWxValue(TEXT_ATTR_LIST_STYLE_NAME);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_STYLE);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_NUMBER);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_TEXT);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_NAME);
		Gura_AssignWxValue(TEXT_ATTR_URL);
		Gura_AssignWxValue(TEXT_ATTR_PAGE_BREAK);
		Gura_AssignWxValue(TEXT_ATTR_EFFECTS);
		Gura_AssignWxValue(TEXT_ATTR_OUTLINE_LEVEL);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_STYLE_NONE);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_STYLE_ARABIC);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_STYLE_LETTERS_UPPER);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_STYLE_LETTERS_LOWER);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_STYLE_ROMAN_UPPER);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_STYLE_ROMAN_LOWER);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_STYLE_SYMBOL);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_STYLE_BITMAP);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_STYLE_PARENTHESES);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_STYLE_PERIOD);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_STYLE_STANDARD);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_STYLE_RIGHT_PARENTHESIS);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_STYLE_OUTLINE);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_STYLE_ALIGN_RIGHT);
		Gura_AssignWxValue(TEXT_ATTR_BULLET_STYLE_ALIGN_CENTRE);
		Gura_AssignWxValue(TEXT_ATTR_LINE_SPACING_NORMAL);
		Gura_AssignWxValue(TEXT_ATTR_LINE_SPACING_HALF);
		Gura_AssignWxValue(TEXT_ATTR_LINE_SPACING_TWICE);
		Gura_AssignWxValue(TEXT_ATTR_EFFECT_NONE);
		Gura_AssignWxValue(TEXT_ATTR_EFFECT_CAPITALS);
		Gura_AssignWxValue(TEXT_ATTR_EFFECT_SMALL_CAPITALS);
		Gura_AssignWxValue(TEXT_ATTR_EFFECT_STRIKETHROUGH);
		Gura_AssignWxValue(TEXT_ATTR_EFFECT_DOUBLE_STRIKETHROUGH);
		Gura_AssignWxValue(TEXT_ATTR_EFFECT_SHADOW);
		Gura_AssignWxValue(TEXT_ATTR_EFFECT_EMBOSS);
		Gura_AssignWxValue(TEXT_ATTR_EFFECT_OUTLINE);
		Gura_AssignWxValue(TEXT_ATTR_EFFECT_ENGRAVE);
		Gura_AssignWxValue(TEXT_ATTR_EFFECT_SUPERSCRIPT);
		Gura_AssignWxValue(TEXT_ATTR_EFFECT_SUBSCRIPT);
	} while (0);
	do {
		Gura_AssignWxValue(SASH_STATUS_OK);
		Gura_AssignWxValue(SASH_STATUS_OUT_OF_RANGE);
	} while (0);
	do {
		Gura_AssignWxValue(LAYOUT_TOP);
		Gura_AssignWxValue(LAYOUT_LEFT);
		Gura_AssignWxValue(LAYOUT_RIGHT);
		Gura_AssignWxValue(LAYOUT_BOTTOM);
		Gura_AssignWxValue(LAYOUT_HORIZONTAL);
		Gura_AssignWxValue(LAYOUT_VERTICAL);
	} while (0);
	do {
		Gura_AssignWxValue(SASH_TOP);
		Gura_AssignWxValue(SASH_RIGHT);
		Gura_AssignWxValue(SASH_BOTTOM);
		Gura_AssignWxValue(SASH_LEFT);
	} while (0);
	do {
		Gura_AssignWxValue(GROW);
		Gura_AssignWxValue(ALIGN_CENTER);
		Gura_AssignWxValue(ALIGN_CENTRE);
		Gura_AssignWxValue(ALIGN_LEFT);
		Gura_AssignWxValue(ALIGN_RIGHT);
		Gura_AssignWxValue(ALIGN_TOP);
		Gura_AssignWxValue(ALIGN_BOTTOM);
		Gura_AssignWxValue(ALIGN_CENTER_VERTICAL);
		Gura_AssignWxValue(ALIGN_CENTRE_VERTICAL);
		Gura_AssignWxValue(ALIGN_CENTER_HORIZONTAL);
		Gura_AssignWxValue(ALIGN_CENTRE_HORIZONTAL);
	} while (0);
	do {
		Gura_AssignWxValue(FILTER_NONE);
		Gura_AssignWxValue(FILTER_ASCII);
		Gura_AssignWxValue(FILTER_ALPHA);
		Gura_AssignWxValue(FILTER_ALPHANUMERIC);
		Gura_AssignWxValue(FILTER_NUMERIC);
		Gura_AssignWxValue(FILTER_INCLUDE_LIST);
		Gura_AssignWxValue(FILTER_EXCLUDE_LIST);
		Gura_AssignWxValue(FILTER_INCLUDE_CHAR_LIST);
		Gura_AssignWxValue(FILTER_EXCLUDE_CHAR_LIST);
	} while (0);
	do {
		Gura_AssignWxValue(TIMER_CONTINUOUS);
		Gura_AssignWxValue(TIMER_ONE_SHOT);
	} while (0);
	do {
		Gura_AssignWxValue(ITEM_NORMAL);
		Gura_AssignWxValue(ITEM_CHECK);
		Gura_AssignWxValue(ITEM_RADIO);
	} while (0);
	do { // style for wxTopLevelWindow::ShowFullScreen
		Gura_AssignWxValue(FULLSCREEN_NOMENUBAR);
		Gura_AssignWxValue(FULLSCREEN_NOTOOLBAR);
		Gura_AssignWxValue(FULLSCREEN_NOSTATUSBAR);
		Gura_AssignWxValue(FULLSCREEN_NOBORDER);
		Gura_AssignWxValue(FULLSCREEN_NOCAPTION);
		Gura_AssignWxValue(FULLSCREEN_ALL);
	} while (0);
	do {
		Gura_AssignWxValue(USER_ATTENTION_INFO);
		Gura_AssignWxValue(USER_ATTENTION_ERROR);
	} while (0);
	do {
		Gura_AssignWxValue(BK_HITTEST_NOWHERE);
		Gura_AssignWxValue(BK_HITTEST_ONICON);
		Gura_AssignWxValue(BK_HITTEST_ONLABEL);
		Gura_AssignWxValue(BK_HITTEST_ONITEM);
		Gura_AssignWxValue(BK_HITTEST_ONPAGE);
	} while (0);
	do {
		Gura_AssignWxValue(TreeItemIcon_Normal);
		Gura_AssignWxValue(TreeItemIcon_Selected);
		Gura_AssignWxValue(TreeItemIcon_Expanded);
		Gura_AssignWxValue(TreeItemIcon_SelectedExpanded);
	} while (0);
	do {
		Gura_AssignWxValue(WINDOW_VARIANT_NORMAL);
		Gura_AssignWxValue(WINDOW_VARIANT_SMALL);
		Gura_AssignWxValue(WINDOW_VARIANT_MINI);
		Gura_AssignWxValue(WINDOW_VARIANT_LARGE);
	} while (0);
	do {
		Gura_AssignWxValue(BG_STYLE_SYSTEM);
		Gura_AssignWxValue(BG_STYLE_COLOUR);
		Gura_AssignWxValue(BG_STYLE_CUSTOM);
	} while (0);
	do { // wxSystemMetric
		Gura_AssignWxValue(SYS_MOUSE_BUTTONS);
		Gura_AssignWxValue(SYS_BORDER_X);
		Gura_AssignWxValue(SYS_BORDER_Y);
		Gura_AssignWxValue(SYS_CURSOR_X);
		Gura_AssignWxValue(SYS_CURSOR_Y);
		Gura_AssignWxValue(SYS_DCLICK_X);
		Gura_AssignWxValue(SYS_DCLICK_Y);
		Gura_AssignWxValue(SYS_DRAG_X);
		Gura_AssignWxValue(SYS_DRAG_Y);
		Gura_AssignWxValue(SYS_EDGE_X);
		Gura_AssignWxValue(SYS_EDGE_Y);
		Gura_AssignWxValue(SYS_HSCROLL_ARROW_X);
		Gura_AssignWxValue(SYS_HSCROLL_ARROW_Y);
		Gura_AssignWxValue(SYS_HTHUMB_X);
		Gura_AssignWxValue(SYS_ICON_X);
		Gura_AssignWxValue(SYS_ICON_Y);
		Gura_AssignWxValue(SYS_ICONSPACING_X);
		Gura_AssignWxValue(SYS_ICONSPACING_Y);
		Gura_AssignWxValue(SYS_WINDOWMIN_X);
		Gura_AssignWxValue(SYS_WINDOWMIN_Y);
		Gura_AssignWxValue(SYS_SCREEN_X);
		Gura_AssignWxValue(SYS_SCREEN_Y);
		Gura_AssignWxValue(SYS_FRAMESIZE_X);
		Gura_AssignWxValue(SYS_FRAMESIZE_Y);
		Gura_AssignWxValue(SYS_SMALLICON_X);
		Gura_AssignWxValue(SYS_SMALLICON_Y);
		Gura_AssignWxValue(SYS_HSCROLL_Y);
		Gura_AssignWxValue(SYS_VSCROLL_X);
		Gura_AssignWxValue(SYS_VSCROLL_ARROW_X);
		Gura_AssignWxValue(SYS_VSCROLL_ARROW_Y);
		Gura_AssignWxValue(SYS_VTHUMB_Y);
		Gura_AssignWxValue(SYS_CAPTION_Y);
		Gura_AssignWxValue(SYS_MENU_Y);
		Gura_AssignWxValue(SYS_NETWORK_PRESENT);
		Gura_AssignWxValue(SYS_PENWINDOWS_PRESENT);
		Gura_AssignWxValue(SYS_SHOW_SOUNDS);
		Gura_AssignWxValue(SYS_SWAP_BUTTONS);
	} while (0);
	do { // wxSystemScreenType
		Gura_AssignWxValue(SYS_SCREEN_NONE);
		Gura_AssignWxValue(SYS_SCREEN_TINY);
		Gura_AssignWxValue(SYS_SCREEN_PDA);
		Gura_AssignWxValue(SYS_SCREEN_SMALL);
		Gura_AssignWxValue(SYS_SCREEN_DESKTOP);
	} while (0);
	do { // wxSystemColour
		Gura_AssignWxValue(SYS_COLOUR_SCROLLBAR);
		Gura_AssignWxValue(SYS_COLOUR_BACKGROUND);
		Gura_AssignWxValue(SYS_COLOUR_ACTIVECAPTION);
		Gura_AssignWxValue(SYS_COLOUR_INACTIVECAPTION);
		Gura_AssignWxValue(SYS_COLOUR_MENU);
		Gura_AssignWxValue(SYS_COLOUR_WINDOW);
		Gura_AssignWxValue(SYS_COLOUR_WINDOWFRAME);
		Gura_AssignWxValue(SYS_COLOUR_MENUTEXT);
		Gura_AssignWxValue(SYS_COLOUR_WINDOWTEXT);
		Gura_AssignWxValue(SYS_COLOUR_CAPTIONTEXT);
		Gura_AssignWxValue(SYS_COLOUR_ACTIVEBORDER);
		Gura_AssignWxValue(SYS_COLOUR_INACTIVEBORDER);
		Gura_AssignWxValue(SYS_COLOUR_APPWORKSPACE);
		Gura_AssignWxValue(SYS_COLOUR_HIGHLIGHT);
		Gura_AssignWxValue(SYS_COLOUR_HIGHLIGHTTEXT);
		_MS(Gura_AssignWxValue(SYS_COLOUR_LISTBOXHIGHLIGHTTEXT));
		Gura_AssignWxValue(SYS_COLOUR_BTNFACE);
		Gura_AssignWxValue(SYS_COLOUR_BTNSHADOW);
		Gura_AssignWxValue(SYS_COLOUR_GRAYTEXT);
		Gura_AssignWxValue(SYS_COLOUR_BTNTEXT);
		Gura_AssignWxValue(SYS_COLOUR_INACTIVECAPTIONTEXT);
		Gura_AssignWxValue(SYS_COLOUR_BTNHIGHLIGHT);
		Gura_AssignWxValue(SYS_COLOUR_3DDKSHADOW);
		Gura_AssignWxValue(SYS_COLOUR_3DLIGHT);
		Gura_AssignWxValue(SYS_COLOUR_INFOTEXT);
		Gura_AssignWxValue(SYS_COLOUR_INFOBK);
		Gura_AssignWxValue(SYS_COLOUR_DESKTOP);
		Gura_AssignWxValue(SYS_COLOUR_3DFACE);
		Gura_AssignWxValue(SYS_COLOUR_3DSHADOW);
		Gura_AssignWxValue(SYS_COLOUR_3DHIGHLIGHT);
		Gura_AssignWxValue(SYS_COLOUR_3DHILIGHT);
		Gura_AssignWxValue(SYS_COLOUR_BTNHILIGHT);
	} while (0);
	do { // wxSystemFont
		Gura_AssignWxValue(SYS_OEM_FIXED_FONT);
		Gura_AssignWxValue(SYS_ANSI_FIXED_FONT);
		Gura_AssignWxValue(SYS_ANSI_VAR_FONT);
		Gura_AssignWxValue(SYS_SYSTEM_FONT);
		Gura_AssignWxValue(SYS_DEVICE_DEFAULT_FONT);
		Gura_AssignWxValue(SYS_DEFAULT_GUI_FONT);
	} while (0);
	do { // wxIPCFormat
		Gura_AssignWxValue(IPC_INVALID);
		Gura_AssignWxValue(IPC_TEXT);
		Gura_AssignWxValue(IPC_BITMAP);
		Gura_AssignWxValue(IPC_METAFILE);
		Gura_AssignWxValue(IPC_SYLK);
		Gura_AssignWxValue(IPC_DIF);
		Gura_AssignWxValue(IPC_TIFF);
		Gura_AssignWxValue(IPC_OEMTEXT);
		Gura_AssignWxValue(IPC_DIB);
		Gura_AssignWxValue(IPC_PALETTE);
		Gura_AssignWxValue(IPC_PENDATA);
		Gura_AssignWxValue(IPC_RIFF);
		Gura_AssignWxValue(IPC_WAVE);
		Gura_AssignWxValue(IPC_UNICODETEXT);
		Gura_AssignWxValue(IPC_ENHMETAFILE);
		Gura_AssignWxValue(IPC_FILENAME);
		Gura_AssignWxValue(IPC_LOCALE);
		Gura_AssignWxValue(IPC_PRIVATE);
	} while (0);
	do { // wx.TreeCtrl#HitTest
		Gura_AssignWxValue(TREE_HITTEST_ABOVE);
		Gura_AssignWxValue(TREE_HITTEST_BELOW);
		Gura_AssignWxValue(TREE_HITTEST_NOWHERE);
		Gura_AssignWxValue(TREE_HITTEST_ONITEMBUTTON);
		Gura_AssignWxValue(TREE_HITTEST_ONITEMICON);
		Gura_AssignWxValue(TREE_HITTEST_ONITEMINDENT);
		Gura_AssignWxValue(TREE_HITTEST_ONITEMLABEL);
		Gura_AssignWxValue(TREE_HITTEST_ONITEMRIGHT);
		Gura_AssignWxValue(TREE_HITTEST_ONITEMSTATEICON);
		Gura_AssignWxValue(TREE_HITTEST_TOLEFT);
		Gura_AssignWxValue(TREE_HITTEST_TORIGHT);
	} while (0);
	do { // wxURLError
		Gura_AssignWxValue(URL_NOERR);
		Gura_AssignWxValue(URL_SNTXERR);
		Gura_AssignWxValue(URL_NOPROTO);
		Gura_AssignWxValue(URL_NOHOST);
		Gura_AssignWxValue(URL_NOPATH);
		Gura_AssignWxValue(URL_CONNERR);
		Gura_AssignWxValue(URL_PROTOERR);
	} while (0);
	do { // wxURI::HostType
		Gura_AssignWxValue(URI_REGNAME);
		Gura_AssignWxValue(URI_IPV4ADDRESS);
		Gura_AssignWxValue(URI_IPV6ADDRESS);
		Gura_AssignWxValue(URI_IPVFUTURE);
	} while (0);
	do {
		Gura_AssignWxValue(AC_DEFAULT_STYLE);
		Gura_AssignWxValue(AC_NO_AUTORESIZE);
	} while (0);
	do {
		Gura_AssignWxValue(AUI_NB_BOTTOM);
		Gura_AssignWxValue(AUI_NB_CLOSE_BUTTON);
		Gura_AssignWxValue(AUI_NB_CLOSE_ON_ACTIVE_TAB);
		Gura_AssignWxValue(AUI_NB_CLOSE_ON_ALL_TABS);
		Gura_AssignWxValue(AUI_NB_DEFAULT_STYLE);
		Gura_AssignWxValue(AUI_NB_SCROLL_BUTTONS);
		Gura_AssignWxValue(AUI_NB_TAB_EXTERNAL_MOVE);
		Gura_AssignWxValue(AUI_NB_TAB_FIXED_WIDTH);
		Gura_AssignWxValue(AUI_NB_TAB_MOVE);
		Gura_AssignWxValue(AUI_NB_TAB_SPLIT);
		Gura_AssignWxValue(AUI_NB_TOP);
		Gura_AssignWxValue(AUI_NB_WINDOWLIST_BUTTON);
	} while (0);
	do {
		Gura_AssignWxValue(BK_BOTTOM);
		Gura_AssignWxValue(BK_DEFAULT);
		Gura_AssignWxValue(BK_LEFT);
		Gura_AssignWxValue(BK_RIGHT);
		Gura_AssignWxValue(BK_TOP);
	} while (0);
	do {
		Gura_AssignWxValue(BORDER_DOUBLE);
		Gura_AssignWxValue(BORDER_NONE);
		Gura_AssignWxValue(BORDER_RAISED);
		Gura_AssignWxValue(BORDER_SIMPLE);
		Gura_AssignWxValue(BORDER_STATIC);
		Gura_AssignWxValue(BORDER_SUNKEN);
		Gura_AssignWxValue(BORDER_THEME);
	} while (0);
	do {
		Gura_AssignWxValue(SIMPLE_BORDER);
		Gura_AssignWxValue(DOUBLE_BORDER);
		Gura_AssignWxValue(SUNKEN_BORDER);
		Gura_AssignWxValue(RAISED_BORDER);
		Gura_AssignWxValue(STATIC_BORDER);
	} while (0);
	do { // Styles for wx.Button
		Gura_AssignWxValue(BU_AUTODRAW);
		Gura_AssignWxValue(BU_BOTTOM);
		Gura_AssignWxValue(BU_EXACTFIT);
		Gura_AssignWxValue(BU_LEFT);
		Gura_AssignWxValue(BU_RIGHT);
		Gura_AssignWxValue(BU_TOP);
	} while (0);
	do { // Styles for wx.CalendarCtrl
		Gura_AssignWxValue(CAL_SUNDAY_FIRST);
		Gura_AssignWxValue(CAL_MONDAY_FIRST);
		Gura_AssignWxValue(CAL_SHOW_HOLIDAYS);
		Gura_AssignWxValue(CAL_NO_YEAR_CHANGE);
		Gura_AssignWxValue(CAL_NO_MONTH_CHANGE);
		Gura_AssignWxValue(CAL_SHOW_SURROUNDING_WEEKS);
		Gura_AssignWxValue(CAL_SEQUENTIAL_MONTH_SELECTION);
	} while (0);
	do { // Styles for wx.ComboBox
		Gura_AssignWxValue(CB_DROPDOWN);
		Gura_AssignWxValue(CB_READONLY);
		Gura_AssignWxValue(CB_SIMPLE);
		Gura_AssignWxValue(CB_SORT);
	} while (0);
	do { // Styles for wx.ComboCtrl
		Gura_AssignWxValue(CC_SPECIAL_DCLICK);
		Gura_AssignWxValue(CC_STD_BUTTON);
	} while (0);
	do {
		Gura_AssignWxValue(CHB_BOTTOM);
		Gura_AssignWxValue(CHB_DEFAULT);
		Gura_AssignWxValue(CHB_LEFT);
		Gura_AssignWxValue(CHB_RIGHT);
		Gura_AssignWxValue(CHB_TOP);
	} while (0);
	do {
		Gura_AssignWxValue(CHK_2STATE);
		Gura_AssignWxValue(CHK_3STATE);
		Gura_AssignWxValue(CHK_ALLOW_3RD_STATE_FOR_USER);
	} while (0);
	do {
		Gura_AssignWxValue(CLRP_DEFAULT_STYLE);
		Gura_AssignWxValue(CLRP_SHOW_LABEL);
		Gura_AssignWxValue(CLRP_USE_TEXTCTRL);
	} while (0);
	do {
		Gura_AssignWxValue(DD_CHANGE_DIR);
		Gura_AssignWxValue(DD_DEFAULT_STYLE);
		Gura_AssignWxValue(DD_DIR_MUST_EXIST);
	} while (0);
	do {
		Gura_AssignWxValue(DIALOG_EX_CONTEXTHELP);
		Gura_AssignWxValue(DIALOG_EX_METAL);
		Gura_AssignWxValue(DIALOG_NO_PARENT);
	} while (0);
	do {
		Gura_AssignWxValue(DIRP_CHANGE_DIR);
		Gura_AssignWxValue(DIRP_DEFAULT_STYLE);
		Gura_AssignWxValue(DIRP_DIR_MUST_EXIST);
		Gura_AssignWxValue(DIRP_USE_TEXTCTRL);
	} while (0);
	do {
		Gura_AssignWxValue(DP_ALLOWNONE);
		Gura_AssignWxValue(DP_DEFAULT);
		Gura_AssignWxValue(DP_DROPDOWN);
		Gura_AssignWxValue(DP_SHOWCENTURY);
		Gura_AssignWxValue(DP_SPIN);
	} while (0);
	do {
	_MS(Gura_AssignWxValue(DV_MULTIPLE));
	_MS(Gura_AssignWxValue(DV_SINGLE));
	} while (0);
	do {
		Gura_AssignWxValue(FLP_CHANGE_DIR);
		Gura_AssignWxValue(FLP_DEFAULT_STYLE);
		Gura_AssignWxValue(FLP_FILE_MUST_EXIST);
		Gura_AssignWxValue(FLP_OPEN);
		Gura_AssignWxValue(FLP_OVERWRITE_PROMPT);
		Gura_AssignWxValue(FLP_SAVE);
		Gura_AssignWxValue(FLP_USE_TEXTCTRL);
	} while (0);
	do {
		Gura_AssignWxValue(FNTP_DEFAULT_STYLE);
		Gura_AssignWxValue(FNTP_FONTDESC_AS_LABEL);
		Gura_AssignWxValue(FNTP_USEFONT_FOR_LABEL);
		Gura_AssignWxValue(FNTP_USE_TEXTCTRL);
	} while (0);
	do {
		Gura_AssignWxValue(FRAME_EX_CONTEXTHELP);
		Gura_AssignWxValue(FRAME_EX_METAL);
		Gura_AssignWxValue(FRAME_FLOAT_ON_PARENT);
		Gura_AssignWxValue(FRAME_NO_TASKBAR);
		Gura_AssignWxValue(FRAME_NO_WINDOW_MENU);
		Gura_AssignWxValue(FRAME_SHAPED);
		Gura_AssignWxValue(FRAME_TOOL_WINDOW);
	} while (0);
	do {
		Gura_AssignWxValue(FULL_REPAINT_ON_RESIZE);
	} while (0);
	do {
		Gura_AssignWxValue(GA_HORIZONTAL);
		//Gura_AssignWxValue(GA_PROGRESSBAR);
		Gura_AssignWxValue(GA_SMOOTH);
		Gura_AssignWxValue(GA_VERTICAL);
	} while (0);
	do { // Conditions for wxHtmlCell
		Gura_AssignWxValue(HTML_COND_ISANCHOR);
		Gura_AssignWxValue(HTML_COND_USER);
	} while (0);
	do { // Flags for wxHtmlColourCell
		Gura_AssignWxValue(HTML_CLR_FOREGROUND);
		Gura_AssignWxValue(HTML_CLR_BACKGROUND);
	} while (0);
	do { // Styles for wxHtmlHelpController
		Gura_AssignWxValue(HF_BOOKMARKS);
		Gura_AssignWxValue(HF_CONTENTS);
		Gura_AssignWxValue(HF_DEFAULT_STYLE);
		Gura_AssignWxValue(HF_DIALOG);
		Gura_AssignWxValue(HF_EMBEDDED);
		Gura_AssignWxValue(HF_FLAT_TOOLBAR);
		Gura_AssignWxValue(HF_FRAME);
		Gura_AssignWxValue(HF_ICONS_BOOK);
		Gura_AssignWxValue(HF_ICONS_BOOK_CHAPTER);
		Gura_AssignWxValue(HF_ICONS_FOLDER);
		Gura_AssignWxValue(HF_INDEX);
		Gura_AssignWxValue(HF_MERGE_BOOKS);
		Gura_AssignWxValue(HF_MODAL);
		Gura_AssignWxValue(HF_OPEN_FILES);
		Gura_AssignWxValue(HF_PRINT);
		Gura_AssignWxValue(HF_SEARCH);
		Gura_AssignWxValue(HF_TOOLBAR);
	} while (0);
	do { // Window styles for wxSimpleHtmlListBox
		Gura_AssignWxValue(HLB_DEFAULT_STYLE);
		Gura_AssignWxValue(HLB_MULTIPLE);
	} while (0);
	do {
		Gura_AssignWxValue(HL_ALIGN_CENTRE);
		Gura_AssignWxValue(HL_ALIGN_LEFT);
		Gura_AssignWxValue(HL_ALIGN_RIGHT);
		Gura_AssignWxValue(HL_CONTEXTMENU);
		Gura_AssignWxValue(HL_DEFAULT_STYLE);
	} while (0);
	do { // Window styles for wxHtmlWindow
		Gura_AssignWxValue(HW_NO_SELECTION);
		Gura_AssignWxValue(HW_SCROLLBAR_AUTO);
		Gura_AssignWxValue(HW_SCROLLBAR_NEVER);
	} while (0);
	do {
		Gura_AssignWxValue(ICONIZE);
	} while (0);
	do {
		Gura_AssignWxValue(IMAGE_LIST_NORMAL);
		Gura_AssignWxValue(IMAGE_LIST_SMALL);
		Gura_AssignWxValue(IMAGE_LIST_STATE);
	} while (0);
	do {
		Gura_AssignWxValue(LB_ALWAYS_SB);
		Gura_AssignWxValue(LB_BOTTOM);
		Gura_AssignWxValue(LB_DEFAULT);
		Gura_AssignWxValue(LB_EXTENDED);
		Gura_AssignWxValue(LB_HSCROLL);
		Gura_AssignWxValue(LB_LEFT);
		Gura_AssignWxValue(LB_MULTIPLE);
		Gura_AssignWxValue(LB_NEEDED_SB);
		Gura_AssignWxValue(LB_RIGHT);
		Gura_AssignWxValue(LB_SINGLE);
		Gura_AssignWxValue(LB_SORT);
		Gura_AssignWxValue(LB_TOP);
		Gura_AssignWxValue(LB_OWNERDRAW);
	} while (0);
	do {
		Gura_AssignWxValue(LC_MASK_TYPE);
		Gura_AssignWxValue(LC_ALIGN_LEFT);
		Gura_AssignWxValue(LC_ALIGN_TOP);
		Gura_AssignWxValue(LC_AUTOARRANGE);
		Gura_AssignWxValue(LC_EDIT_LABELS);
		Gura_AssignWxValue(LC_HRULES);
		Gura_AssignWxValue(LC_ICON);
		Gura_AssignWxValue(LC_LIST);
		Gura_AssignWxValue(LC_NO_HEADER);
		Gura_AssignWxValue(LC_REPORT);
		Gura_AssignWxValue(LC_SINGLE_SEL);
		Gura_AssignWxValue(LC_SMALL_ICON);
		Gura_AssignWxValue(LC_SORT_ASCENDING);
		Gura_AssignWxValue(LC_SORT_DESCENDING);
		Gura_AssignWxValue(LC_VIRTUAL);
		Gura_AssignWxValue(LC_VRULES);
	} while (0);
	do {
		Gura_AssignWxValue(LI_HORIZONTAL);
		Gura_AssignWxValue(LI_VERTICAL);
	} while (0);
	do {
		Gura_AssignWxValue(LOCALE_CONV_ENCODING);
		Gura_AssignWxValue(LOCALE_LOAD_DEFAULT);
	} while (0);
	do {
		Gura_AssignWxValue(ADJUST_MINSIZE);
		Gura_AssignWxValue(ALL);
		Gura_AssignWxValue(ALWAYS_SHOW_SB);
		Gura_AssignWxValue(CAPTION);
		Gura_AssignWxValue(CLIP_CHILDREN);
		Gura_AssignWxValue(CLOSE_BOX);
		Gura_AssignWxValue(CP_DEFAULT_STYLE);
		Gura_AssignWxValue(DEFAULT_DIALOG_STYLE);
		Gura_AssignWxValue(DEFAULT_FRAME_STYLE);
		Gura_AssignWxValue(EXPAND);
		Gura_AssignWxValue(FIXED_MINSIZE);
		//Gura_AssignWxValue(NO_3D);
		Gura_AssignWxValue(NO_BORDER);
		Gura_AssignWxValue(NO_FULL_REPAINT_ON_RESIZE);
		Gura_AssignWxValue(MAXIMIZE);
		Gura_AssignWxValue(MAXIMIZE_BOX);
		Gura_AssignWxValue(MINIMIZE);
		Gura_AssignWxValue(MINIMIZE_BOX);
		Gura_AssignWxValue(SHAPED);
		Gura_AssignWxValue(VSCROLL);
		Gura_AssignWxValue(WANTS_CHARS);
		Gura_AssignWxValue(WIZARD_EX_HELPBUTTON);
		Gura_AssignWxValue(SYSTEM_MENU);
		Gura_AssignWxValue(TAB_TRAVERSAL);
		//Gura_AssignWxValue(THICK_FRAME);
		Gura_AssignWxValue(TINY_CAPTION_HORIZ);
		Gura_AssignWxValue(TINY_CAPTION_VERT);
		Gura_AssignWxValue(TRANSPARENT_WINDOW);
		Gura_AssignWxValue(HSCROLL);
		Gura_AssignWxValue(STAY_ON_TOP);
	} while (0);
	do {
		Gura_AssignWxValue(NB_BOTTOM);
		Gura_AssignWxValue(NB_FIXEDWIDTH);
		Gura_AssignWxValue(NB_FLAT);
		Gura_AssignWxValue(NB_LEFT);
		Gura_AssignWxValue(NB_MULTILINE);
		Gura_AssignWxValue(NB_NOPAGETHEME);
		Gura_AssignWxValue(NB_RIGHT);
		Gura_AssignWxValue(NB_TOP);
	} while (0);
	do {
		Gura_AssignWxValue(ODCB_DCLICK_CYCLES);
		Gura_AssignWxValue(ODCB_STD_CONTROL_PAINT);
	} while (0);
	do {
		Gura_AssignWxValue(PB_USE_TEXTCTRL);
	} while (0);
	do {
		Gura_AssignWxValue(PD_APP_MODAL);
		Gura_AssignWxValue(PD_AUTO_HIDE);
		Gura_AssignWxValue(PD_CAN_ABORT);
		Gura_AssignWxValue(PD_CAN_SKIP);
		Gura_AssignWxValue(PD_ELAPSED_TIME);
		Gura_AssignWxValue(PD_ESTIMATED_TIME);
		Gura_AssignWxValue(PD_REMAINING_TIME);
		Gura_AssignWxValue(PD_SMOOTH);
	} while (0);
	do {
		Gura_AssignWxValue(RA_SPECIFY_COLS);
		Gura_AssignWxValue(RA_SPECIFY_ROWS);
		//Gura_AssignWxValue(RA_USE_CHECKBOX);
	} while (0);
	do {
		Gura_AssignWxValue(RB_GROUP);
		Gura_AssignWxValue(RB_SINGLE);
		//Gura_AssignWxValue(RB_USE_CHECKBOX);
	} while (0);
	do {
		Gura_AssignWxValue(RESERVE_SPACE_EVEN_IF_HIDDEN);
		Gura_AssignWxValue(RESIZE_BORDER);
		Gura_AssignWxValue(RETAINED);
	} while (0);
	do {
		Gura_AssignWxValue(RE_CENTER_CARET);
		Gura_AssignWxValue(RE_CENTRE_CARET);
		Gura_AssignWxValue(RE_READONLY);
		Gura_AssignWxValue(RE_EXTENDED);
		Gura_AssignWxValue(RE_ADVANCED);
		Gura_AssignWxValue(RE_BASIC);
		Gura_AssignWxValue(RE_ICASE);
		Gura_AssignWxValue(RE_NOSUB);
		Gura_AssignWxValue(RE_NEWLINE);
		Gura_AssignWxValue(RE_DEFAULT);
		Gura_AssignWxValue(RE_NOTBOL);
		Gura_AssignWxValue(RE_NOTEOL);
	} while (0);
	do {
		Gura_AssignWxValue(FR_DOWN);
		Gura_AssignWxValue(FR_WHOLEWORD);
		Gura_AssignWxValue(FR_MATCHCASE);
		Gura_AssignWxValue(FR_REPLACEDIALOG);
		Gura_AssignWxValue(FR_NOUPDOWN);
		Gura_AssignWxValue(FR_NOMATCHCASE);
		Gura_AssignWxValue(FR_NOWHOLEWORD);
	} while (0);
	do {
		Gura_AssignWxValue(MB_DOCKABLE);
	} while (0);
	do {
		Gura_AssignWxValue(RICHTEXTSTYLELIST_HIDE_TYPE_SELECTOR);
		Gura_AssignWxValue(RICHTEXT_HANDLER_INCLUDE_STYLESHEET);
		Gura_AssignWxValue(RICHTEXT_HANDLER_NO_HEADER_FOOTER);
		Gura_AssignWxValue(RICHTEXT_HANDLER_SAVE_IMAGES_TO_BASE64);
		Gura_AssignWxValue(RICHTEXT_HANDLER_SAVE_IMAGES_TO_FILES);
		Gura_AssignWxValue(RICHTEXT_HANDLER_SAVE_IMAGES_TO_MEMORY);
		Gura_AssignWxValue(RICHTEXT_HANDLER_USE_CSS);
		Gura_AssignWxValue(RICHTEXT_ORGANISER_APPLY_STYLES);
		Gura_AssignWxValue(RICHTEXT_ORGANISER_BROWSE);
		Gura_AssignWxValue(RICHTEXT_ORGANISER_BROWSE_NUMBERING);
		Gura_AssignWxValue(RICHTEXT_ORGANISER_CREATE_STYLES);
		Gura_AssignWxValue(RICHTEXT_ORGANISER_DELETE_STYLES);
		Gura_AssignWxValue(RICHTEXT_ORGANISER_EDIT_STYLES);
		Gura_AssignWxValue(RICHTEXT_ORGANISER_OK_CANCEL);
		Gura_AssignWxValue(RICHTEXT_ORGANISER_ORGANISE);
		Gura_AssignWxValue(RICHTEXT_ORGANISER_RENAME_STYLES);
		Gura_AssignWxValue(RICHTEXT_ORGANISER_RENUMBER);
		Gura_AssignWxValue(RICHTEXT_ORGANISER_SHOW_ALL);
		Gura_AssignWxValue(RICHTEXT_ORGANISER_SHOW_CHARACTER);
		Gura_AssignWxValue(RICHTEXT_ORGANISER_SHOW_LIST);
		Gura_AssignWxValue(RICHTEXT_ORGANISER_SHOW_PARAGRAPH);
		Gura_AssignWxValue(RICHTEXT_HITTEST_NONE);
		Gura_AssignWxValue(RICHTEXT_HITTEST_BEFORE);
		Gura_AssignWxValue(RICHTEXT_HITTEST_AFTER);
		Gura_AssignWxValue(RICHTEXT_HITTEST_ON);
		Gura_AssignWxValue(RICHTEXT_HITTEST_OUTSIDE);
		Gura_AssignWxValue(RICHTEXT_SETSTYLE_NONE);
		Gura_AssignWxValue(RICHTEXT_SETSTYLE_WITH_UNDO);
		Gura_AssignWxValue(RICHTEXT_SETSTYLE_OPTIMIZE);
		Gura_AssignWxValue(RICHTEXT_SETSTYLE_PARAGRAPHS_ONLY);
		Gura_AssignWxValue(RICHTEXT_SETSTYLE_CHARACTERS_ONLY);
		Gura_AssignWxValue(RICHTEXT_SETSTYLE_RESET);
		Gura_AssignWxValue(RICHTEXT_SETSTYLE_REMOVE);
		Gura_AssignWxValue(RICHTEXT_SETSTYLE_RENUMBER);
		Gura_AssignWxValue(RICHTEXT_SETSTYLE_SPECIFY_LEVEL);
		// RichTextOddEvenPage
		Gura_AssignWxValue(RICHTEXT_PAGE_ODD);
		Gura_AssignWxValue(RICHTEXT_PAGE_EVEN);
		Gura_AssignWxValue(RICHTEXT_PAGE_ALL);
		// RichTextPageLocation
		Gura_AssignWxValue(RICHTEXT_PAGE_LEFT);
		Gura_AssignWxValue(RICHTEXT_PAGE_CENTRE);
		Gura_AssignWxValue(RICHTEXT_PAGE_RIGHT);
		// RichTextFormattingDialog
		Gura_AssignWxValue(RICHTEXT_FORMAT_STYLE_EDITOR);
		Gura_AssignWxValue(RICHTEXT_FORMAT_FONT);
		Gura_AssignWxValue(RICHTEXT_FORMAT_TABS);
		Gura_AssignWxValue(RICHTEXT_FORMAT_BULLETS);
		Gura_AssignWxValue(RICHTEXT_FORMAT_INDENTS_SPACING);
   	} while (0);
	do {
		Gura_AssignWxValue(SB_FLAT);
		Gura_AssignWxValue(SB_HORIZONTAL);
		Gura_AssignWxValue(SB_NORMAL);
		Gura_AssignWxValue(SB_RAISED);
		Gura_AssignWxValue(SB_VERTICAL);
	} while (0);
	do {
		Gura_AssignWxValue(SL_AUTOTICKS);
		Gura_AssignWxValue(SL_BOTTOM);
		Gura_AssignWxValue(SL_HORIZONTAL);
		Gura_AssignWxValue(SL_INVERSE);
		Gura_AssignWxValue(SL_LABELS);
		Gura_AssignWxValue(SL_LEFT);
		Gura_AssignWxValue(SL_RIGHT);
		Gura_AssignWxValue(SL_SELRANGE);
		Gura_AssignWxValue(SL_TOP);
		Gura_AssignWxValue(SL_VERTICAL);
	} while (0);
	do {
		Gura_AssignWxValue(SP_3D);
		Gura_AssignWxValue(SP_3DBORDER);
		Gura_AssignWxValue(SP_3DSASH);
		Gura_AssignWxValue(SP_ARROW_KEYS);
		Gura_AssignWxValue(SP_BORDER);
		Gura_AssignWxValue(SP_HORIZONTAL);
		Gura_AssignWxValue(SP_LIVE_UPDATE);
		Gura_AssignWxValue(SP_NOBORDER);
		Gura_AssignWxValue(SP_NO_XP_THEME);
		Gura_AssignWxValue(SP_PERMIT_UNSPLIT);
		Gura_AssignWxValue(SP_VERTICAL);
		Gura_AssignWxValue(SP_WRAP);
	} while (0);
	do {
		Gura_AssignWxValue(ST_NO_AUTORESIZE);
		Gura_AssignWxValue(ST_SIZEGRIP);
		Gura_AssignWxValue(ST_ELLIPSIZE_START);
		Gura_AssignWxValue(ST_ELLIPSIZE_MIDDLE);
		Gura_AssignWxValue(ST_ELLIPSIZE_END);
	} while (0);
	do {
		Gura_AssignWxValue(SW_3D);
		Gura_AssignWxValue(SW_3DBORDER);
		Gura_AssignWxValue(SW_3DSASH);
		Gura_AssignWxValue(SW_BORDER);
	} while (0);
	do {
		Gura_AssignWxValue(TB_BOTTOM);
		Gura_AssignWxValue(TB_DOCKABLE);
		Gura_AssignWxValue(TB_FLAT);
		Gura_AssignWxValue(TB_HORIZONTAL);
		Gura_AssignWxValue(TB_HORZ_LAYOUT);
		Gura_AssignWxValue(TB_HORZ_TEXT);
		Gura_AssignWxValue(TB_NOALIGN);
		Gura_AssignWxValue(TB_NODIVIDER);
		Gura_AssignWxValue(TB_NOICONS);
		Gura_AssignWxValue(TB_NO_TOOLTIPS);
		Gura_AssignWxValue(TB_RIGHT);
		Gura_AssignWxValue(TB_TEXT);
		Gura_AssignWxValue(TB_VERTICAL);
	} while (0);
	do {
		Gura_AssignWxValue(TE_AUTO_URL);
		Gura_AssignWxValue(TE_BESTWRAP);
		Gura_AssignWxValue(TE_CAPITALIZE);
		Gura_AssignWxValue(TE_CENTRE);
		Gura_AssignWxValue(TE_CHARWRAP);
		Gura_AssignWxValue(TE_DONTWRAP);
		Gura_AssignWxValue(TE_LEFT);
		Gura_AssignWxValue(TE_MULTILINE);
		Gura_AssignWxValue(TE_NOHIDESEL);
		Gura_AssignWxValue(TE_PASSWORD);
		Gura_AssignWxValue(TE_PROCESS_ENTER);
		Gura_AssignWxValue(TE_PROCESS_TAB);
		Gura_AssignWxValue(TE_READONLY);
		Gura_AssignWxValue(TE_RICH);
		Gura_AssignWxValue(TE_RICH2);
		Gura_AssignWxValue(TE_RIGHT);
		Gura_AssignWxValue(TE_WORDWRAP);
	} while (0);
	do {
		Gura_AssignWxValue(TE_HT_UNKNOWN);
		Gura_AssignWxValue(TE_HT_BEFORE);
		Gura_AssignWxValue(TE_HT_ON_TEXT);
		Gura_AssignWxValue(TE_HT_BELOW);
		Gura_AssignWxValue(TE_HT_BEYOND);
	} while (0);
	do {
		Gura_AssignWxValue(TR_NO_BUTTONS);
		Gura_AssignWxValue(TR_HAS_BUTTONS);
		Gura_AssignWxValue(TR_NO_LINES);
		Gura_AssignWxValue(TR_LINES_AT_ROOT);
		Gura_AssignWxValue(TR_TWIST_BUTTONS);
		Gura_AssignWxValue(TR_SINGLE);
		Gura_AssignWxValue(TR_MULTIPLE);
		Gura_AssignWxValue(TR_EXTENDED);
		Gura_AssignWxValue(TR_HAS_VARIABLE_ROW_HEIGHT);
		Gura_AssignWxValue(TR_EDIT_LABELS);
		Gura_AssignWxValue(TR_ROW_LINES);
		Gura_AssignWxValue(TR_HIDE_ROOT);
		Gura_AssignWxValue(TR_FULL_ROW_HIGHLIGHT);
		Gura_AssignWxValue(TR_DEFAULT_STYLE);
	} while (0);
	do {
		Gura_AssignWxValue(WS_EX_BLOCK_EVENTS);
		Gura_AssignWxValue(WS_EX_CONTEXTHELP);
		Gura_AssignWxValue(WS_EX_PROCESS_IDLE);
		Gura_AssignWxValue(WS_EX_PROCESS_UI_UPDATES);
		Gura_AssignWxValue(WS_EX_TRANSIENT);
		Gura_AssignWxValue(WS_EX_VALIDATE_RECURSIVELY);
	} while (0);
	do {
		Gura_AssignWxValue(MAJOR_VERSION);
		Gura_AssignWxValue(MINOR_VERSION);
		Gura_AssignWxValue(RELEASE_NUMBER);
		Gura_AssignWxValue(SUBRELEASE_NUMBER);
		Gura_AssignWxValue(VERSION_NUMBER);
		Gura_AssignValue(VERSION_STRING,			Value(wxString(wxVERSION_STRING).ToUTF8()));
		Gura_AssignValue(VERSION_NUM_DOT_STRING,	Value(wxVERSION_NUM_DOT_STRING));
		//Gura_AssignValue(VERSION_NUM_DOT_STRING,	Value(wxString(wxVERSION_NUM_DOT_STRING).ToUTF8()));
	} while (0);
	do {
	_MS(Gura_AssignValue(RegKeyRead,				Value(wxRegKey::Read)));
	_MS(Gura_AssignValue(RegKeyWrite,				Value(wxRegKey::Write)));
	} while (0);
	do {
		Gura_AssignValue(RICHTEXT_STYLE_ALL,		Value(wxRichTextStyleListBox::wxRICHTEXT_STYLE_ALL));
		Gura_AssignValue(RICHTEXT_STYLE_PARAGRAPH,	Value(wxRichTextStyleListBox::wxRICHTEXT_STYLE_PARAGRAPH));
		Gura_AssignValue(RICHTEXT_STYLE_CHARACTER,	Value(wxRichTextStyleListBox::wxRICHTEXT_STYLE_CHARACTER));
		Gura_AssignValue(RICHTEXT_STYLE_LIST,		Value(wxRichTextStyleListBox::wxRICHTEXT_STYLE_LIST));
	} while (0);
	do { // wxKeyModifier
		Gura_AssignWxValue(MOD_NONE);
		Gura_AssignWxValue(MOD_ALT);
		Gura_AssignWxValue(MOD_CONTROL);
		Gura_AssignWxValue(MOD_ALTGR);
		Gura_AssignWxValue(MOD_SHIFT);
		Gura_AssignWxValue(MOD_META);
		Gura_AssignWxValue(MOD_CMD);
		Gura_AssignWxValue(MOD_ALL);
	} while (0);
	do { // flags for wxLocale
		Gura_AssignWxValue(LOCALE_LOAD_DEFAULT);
		Gura_AssignWxValue(LOCALE_CONV_ENCODING);
	} while (0);
	do { // wxLocale
		Gura_AssignWxValue(LANGUAGE_DEFAULT);
		Gura_AssignWxValue(LANGUAGE_UNKNOWN);
		Gura_AssignWxValue(LANGUAGE_USER_DEFINED);
		Gura_AssignWxValue(LANGUAGE_ABKHAZIAN);
		Gura_AssignWxValue(LANGUAGE_AFAR);
		Gura_AssignWxValue(LANGUAGE_AFRIKAANS);
		Gura_AssignWxValue(LANGUAGE_ALBANIAN);
		Gura_AssignWxValue(LANGUAGE_AMHARIC);
		Gura_AssignWxValue(LANGUAGE_ARABIC);
		Gura_AssignWxValue(LANGUAGE_ARABIC_ALGERIA);
		Gura_AssignWxValue(LANGUAGE_ARABIC_BAHRAIN);
		Gura_AssignWxValue(LANGUAGE_ARABIC_EGYPT);
		Gura_AssignWxValue(LANGUAGE_ARABIC_IRAQ);
		Gura_AssignWxValue(LANGUAGE_ARABIC_JORDAN);
		Gura_AssignWxValue(LANGUAGE_ARABIC_KUWAIT);
		Gura_AssignWxValue(LANGUAGE_ARABIC_LEBANON);
		Gura_AssignWxValue(LANGUAGE_ARABIC_LIBYA);
		Gura_AssignWxValue(LANGUAGE_ARABIC_MOROCCO);
		Gura_AssignWxValue(LANGUAGE_ARABIC_OMAN);
		Gura_AssignWxValue(LANGUAGE_ARABIC_QATAR);
		Gura_AssignWxValue(LANGUAGE_ARABIC_SAUDI_ARABIA);
		Gura_AssignWxValue(LANGUAGE_ARABIC_SUDAN);
		Gura_AssignWxValue(LANGUAGE_ARABIC_SYRIA);
		Gura_AssignWxValue(LANGUAGE_ARABIC_TUNISIA);
		Gura_AssignWxValue(LANGUAGE_ARABIC_UAE);
		Gura_AssignWxValue(LANGUAGE_ARABIC_YEMEN);
		Gura_AssignWxValue(LANGUAGE_ARMENIAN);
		Gura_AssignWxValue(LANGUAGE_ASSAMESE);
		Gura_AssignWxValue(LANGUAGE_AYMARA);
		Gura_AssignWxValue(LANGUAGE_AZERI);
		Gura_AssignWxValue(LANGUAGE_AZERI_CYRILLIC);
		Gura_AssignWxValue(LANGUAGE_AZERI_LATIN);
		Gura_AssignWxValue(LANGUAGE_BASHKIR);
		Gura_AssignWxValue(LANGUAGE_BASQUE);
		Gura_AssignWxValue(LANGUAGE_BELARUSIAN);
		Gura_AssignWxValue(LANGUAGE_BENGALI);
		Gura_AssignWxValue(LANGUAGE_BHUTANI);
		Gura_AssignWxValue(LANGUAGE_BIHARI);
		Gura_AssignWxValue(LANGUAGE_BISLAMA);
		Gura_AssignWxValue(LANGUAGE_BRETON);
		Gura_AssignWxValue(LANGUAGE_BULGARIAN);
		Gura_AssignWxValue(LANGUAGE_BURMESE);
		Gura_AssignWxValue(LANGUAGE_CAMBODIAN);
		Gura_AssignWxValue(LANGUAGE_CATALAN);
		Gura_AssignWxValue(LANGUAGE_CHINESE);
		Gura_AssignWxValue(LANGUAGE_CHINESE_SIMPLIFIED);
		Gura_AssignWxValue(LANGUAGE_CHINESE_TRADITIONAL);
		Gura_AssignWxValue(LANGUAGE_CHINESE_HONGKONG);
		Gura_AssignWxValue(LANGUAGE_CHINESE_MACAU);
		Gura_AssignWxValue(LANGUAGE_CHINESE_SINGAPORE);
		Gura_AssignWxValue(LANGUAGE_CHINESE_TAIWAN);
		Gura_AssignWxValue(LANGUAGE_CORSICAN);
		Gura_AssignWxValue(LANGUAGE_CROATIAN);
		Gura_AssignWxValue(LANGUAGE_CZECH);
		Gura_AssignWxValue(LANGUAGE_DANISH);
		Gura_AssignWxValue(LANGUAGE_DUTCH);
		Gura_AssignWxValue(LANGUAGE_DUTCH_BELGIAN);
		Gura_AssignWxValue(LANGUAGE_ENGLISH);
		Gura_AssignWxValue(LANGUAGE_ENGLISH_UK);
		Gura_AssignWxValue(LANGUAGE_ENGLISH_US);
		Gura_AssignWxValue(LANGUAGE_ENGLISH_AUSTRALIA);
		Gura_AssignWxValue(LANGUAGE_ENGLISH_BELIZE);
		Gura_AssignWxValue(LANGUAGE_ENGLISH_BOTSWANA);
		Gura_AssignWxValue(LANGUAGE_ENGLISH_CANADA);
		Gura_AssignWxValue(LANGUAGE_ENGLISH_CARIBBEAN);
		Gura_AssignWxValue(LANGUAGE_ENGLISH_DENMARK);
		Gura_AssignWxValue(LANGUAGE_ENGLISH_EIRE);
		Gura_AssignWxValue(LANGUAGE_ENGLISH_JAMAICA);
		Gura_AssignWxValue(LANGUAGE_ENGLISH_NEW_ZEALAND);
		Gura_AssignWxValue(LANGUAGE_ENGLISH_PHILIPPINES);
		Gura_AssignWxValue(LANGUAGE_ENGLISH_SOUTH_AFRICA);
		Gura_AssignWxValue(LANGUAGE_ENGLISH_TRINIDAD);
		Gura_AssignWxValue(LANGUAGE_ENGLISH_ZIMBABWE);
		Gura_AssignWxValue(LANGUAGE_ESPERANTO);
		Gura_AssignWxValue(LANGUAGE_ESTONIAN);
		Gura_AssignWxValue(LANGUAGE_FAEROESE);
		Gura_AssignWxValue(LANGUAGE_FARSI);
		Gura_AssignWxValue(LANGUAGE_FIJI);
		Gura_AssignWxValue(LANGUAGE_FINNISH);
		Gura_AssignWxValue(LANGUAGE_FRENCH);
		Gura_AssignWxValue(LANGUAGE_FRENCH_BELGIAN);
		Gura_AssignWxValue(LANGUAGE_FRENCH_CANADIAN);
		Gura_AssignWxValue(LANGUAGE_FRENCH_LUXEMBOURG);
		Gura_AssignWxValue(LANGUAGE_FRENCH_MONACO);
		Gura_AssignWxValue(LANGUAGE_FRENCH_SWISS);
		Gura_AssignWxValue(LANGUAGE_FRISIAN);
		Gura_AssignWxValue(LANGUAGE_GALICIAN);
		Gura_AssignWxValue(LANGUAGE_GEORGIAN);
		Gura_AssignWxValue(LANGUAGE_GERMAN);
		Gura_AssignWxValue(LANGUAGE_GERMAN_AUSTRIAN);
		Gura_AssignWxValue(LANGUAGE_GERMAN_BELGIUM);
		Gura_AssignWxValue(LANGUAGE_GERMAN_LIECHTENSTEIN);
		Gura_AssignWxValue(LANGUAGE_GERMAN_LUXEMBOURG);
		Gura_AssignWxValue(LANGUAGE_GERMAN_SWISS);
		Gura_AssignWxValue(LANGUAGE_GREEK);
		Gura_AssignWxValue(LANGUAGE_GREENLANDIC);
		Gura_AssignWxValue(LANGUAGE_GUARANI);
		Gura_AssignWxValue(LANGUAGE_GUJARATI);
		Gura_AssignWxValue(LANGUAGE_HAUSA);
		Gura_AssignWxValue(LANGUAGE_HEBREW);
		Gura_AssignWxValue(LANGUAGE_HINDI);
		Gura_AssignWxValue(LANGUAGE_HUNGARIAN);
		Gura_AssignWxValue(LANGUAGE_ICELANDIC);
		Gura_AssignWxValue(LANGUAGE_INDONESIAN);
		Gura_AssignWxValue(LANGUAGE_INTERLINGUA);
		Gura_AssignWxValue(LANGUAGE_INTERLINGUE);
		Gura_AssignWxValue(LANGUAGE_INUKTITUT);
		Gura_AssignWxValue(LANGUAGE_INUPIAK);
		Gura_AssignWxValue(LANGUAGE_IRISH);
		Gura_AssignWxValue(LANGUAGE_ITALIAN);
		Gura_AssignWxValue(LANGUAGE_ITALIAN_SWISS);
		Gura_AssignWxValue(LANGUAGE_JAPANESE);
		Gura_AssignWxValue(LANGUAGE_JAVANESE);
		Gura_AssignWxValue(LANGUAGE_KANNADA);
		Gura_AssignWxValue(LANGUAGE_KASHMIRI);
		Gura_AssignWxValue(LANGUAGE_KASHMIRI_INDIA);
		Gura_AssignWxValue(LANGUAGE_KAZAKH);
		Gura_AssignWxValue(LANGUAGE_KERNEWEK);
		Gura_AssignWxValue(LANGUAGE_KINYARWANDA);
		Gura_AssignWxValue(LANGUAGE_KIRGHIZ);
		Gura_AssignWxValue(LANGUAGE_KIRUNDI);
		Gura_AssignWxValue(LANGUAGE_KONKANI);
		Gura_AssignWxValue(LANGUAGE_KOREAN);
		Gura_AssignWxValue(LANGUAGE_KURDISH);
		Gura_AssignWxValue(LANGUAGE_LAOTHIAN);
		Gura_AssignWxValue(LANGUAGE_LATIN);
		Gura_AssignWxValue(LANGUAGE_LATVIAN);
		Gura_AssignWxValue(LANGUAGE_LINGALA);
		Gura_AssignWxValue(LANGUAGE_LITHUANIAN);
		Gura_AssignWxValue(LANGUAGE_MACEDONIAN);
		Gura_AssignWxValue(LANGUAGE_MALAGASY);
		Gura_AssignWxValue(LANGUAGE_MALAY);
		Gura_AssignWxValue(LANGUAGE_MALAYALAM);
		Gura_AssignWxValue(LANGUAGE_MALAY_BRUNEI_DARUSSALAM);
		Gura_AssignWxValue(LANGUAGE_MALAY_MALAYSIA);
		Gura_AssignWxValue(LANGUAGE_MALTESE);
		Gura_AssignWxValue(LANGUAGE_MANIPURI);
		Gura_AssignWxValue(LANGUAGE_MAORI);
		Gura_AssignWxValue(LANGUAGE_MARATHI);
		Gura_AssignWxValue(LANGUAGE_MOLDAVIAN);
		Gura_AssignWxValue(LANGUAGE_MONGOLIAN);
		Gura_AssignWxValue(LANGUAGE_NAURU);
		Gura_AssignWxValue(LANGUAGE_NEPALI);
		Gura_AssignWxValue(LANGUAGE_NEPALI_INDIA);
		Gura_AssignWxValue(LANGUAGE_NORWEGIAN_BOKMAL);
		Gura_AssignWxValue(LANGUAGE_NORWEGIAN_NYNORSK);
		Gura_AssignWxValue(LANGUAGE_OCCITAN);
		Gura_AssignWxValue(LANGUAGE_ORIYA);
		Gura_AssignWxValue(LANGUAGE_OROMO);
		Gura_AssignWxValue(LANGUAGE_PASHTO);
		Gura_AssignWxValue(LANGUAGE_POLISH);
		Gura_AssignWxValue(LANGUAGE_PORTUGUESE);
		Gura_AssignWxValue(LANGUAGE_PORTUGUESE_BRAZILIAN);
		Gura_AssignWxValue(LANGUAGE_PUNJABI);
		Gura_AssignWxValue(LANGUAGE_QUECHUA);
		Gura_AssignWxValue(LANGUAGE_RHAETO_ROMANCE);
		Gura_AssignWxValue(LANGUAGE_ROMANIAN);
		Gura_AssignWxValue(LANGUAGE_RUSSIAN);
		Gura_AssignWxValue(LANGUAGE_RUSSIAN_UKRAINE);
		Gura_AssignWxValue(LANGUAGE_SAMI);
		Gura_AssignWxValue(LANGUAGE_SAMOAN);
		Gura_AssignWxValue(LANGUAGE_SANGHO);
		Gura_AssignWxValue(LANGUAGE_SANSKRIT);
		Gura_AssignWxValue(LANGUAGE_SCOTS_GAELIC);
		Gura_AssignWxValue(LANGUAGE_SERBIAN);
		Gura_AssignWxValue(LANGUAGE_SERBIAN_CYRILLIC);
		Gura_AssignWxValue(LANGUAGE_SERBIAN_LATIN);
		Gura_AssignWxValue(LANGUAGE_SERBO_CROATIAN);
		Gura_AssignWxValue(LANGUAGE_SESOTHO);
		Gura_AssignWxValue(LANGUAGE_SETSWANA);
		Gura_AssignWxValue(LANGUAGE_SHONA);
		Gura_AssignWxValue(LANGUAGE_SINDHI);
		Gura_AssignWxValue(LANGUAGE_SINHALESE);
		Gura_AssignWxValue(LANGUAGE_SISWATI);
		Gura_AssignWxValue(LANGUAGE_SLOVAK);
		Gura_AssignWxValue(LANGUAGE_SLOVENIAN);
		Gura_AssignWxValue(LANGUAGE_SOMALI);
		Gura_AssignWxValue(LANGUAGE_SPANISH);
		Gura_AssignWxValue(LANGUAGE_SPANISH_ARGENTINA);
		Gura_AssignWxValue(LANGUAGE_SPANISH_BOLIVIA);
		Gura_AssignWxValue(LANGUAGE_SPANISH_CHILE);
		Gura_AssignWxValue(LANGUAGE_SPANISH_COLOMBIA);
		Gura_AssignWxValue(LANGUAGE_SPANISH_COSTA_RICA);
		Gura_AssignWxValue(LANGUAGE_SPANISH_DOMINICAN_REPUBLIC);
		Gura_AssignWxValue(LANGUAGE_SPANISH_ECUADOR);
		Gura_AssignWxValue(LANGUAGE_SPANISH_EL_SALVADOR);
		Gura_AssignWxValue(LANGUAGE_SPANISH_GUATEMALA);
		Gura_AssignWxValue(LANGUAGE_SPANISH_HONDURAS);
		Gura_AssignWxValue(LANGUAGE_SPANISH_MEXICAN);
		Gura_AssignWxValue(LANGUAGE_SPANISH_MODERN);
		Gura_AssignWxValue(LANGUAGE_SPANISH_NICARAGUA);
		Gura_AssignWxValue(LANGUAGE_SPANISH_PANAMA);
		Gura_AssignWxValue(LANGUAGE_SPANISH_PARAGUAY);
		Gura_AssignWxValue(LANGUAGE_SPANISH_PERU);
		Gura_AssignWxValue(LANGUAGE_SPANISH_PUERTO_RICO);
		Gura_AssignWxValue(LANGUAGE_SPANISH_URUGUAY);
		Gura_AssignWxValue(LANGUAGE_SPANISH_US);
		Gura_AssignWxValue(LANGUAGE_SPANISH_VENEZUELA);
		Gura_AssignWxValue(LANGUAGE_SUNDANESE);
		Gura_AssignWxValue(LANGUAGE_SWAHILI);
		Gura_AssignWxValue(LANGUAGE_SWEDISH);
		Gura_AssignWxValue(LANGUAGE_SWEDISH_FINLAND);
		Gura_AssignWxValue(LANGUAGE_TAGALOG);
		Gura_AssignWxValue(LANGUAGE_TAJIK);
		Gura_AssignWxValue(LANGUAGE_TAMIL);
		Gura_AssignWxValue(LANGUAGE_TATAR);
		Gura_AssignWxValue(LANGUAGE_TELUGU);
		Gura_AssignWxValue(LANGUAGE_THAI);
		Gura_AssignWxValue(LANGUAGE_TIBETAN);
		Gura_AssignWxValue(LANGUAGE_TIGRINYA);
		Gura_AssignWxValue(LANGUAGE_TONGA);
		Gura_AssignWxValue(LANGUAGE_TSONGA);
		Gura_AssignWxValue(LANGUAGE_TURKISH);
		Gura_AssignWxValue(LANGUAGE_TURKMEN);
		Gura_AssignWxValue(LANGUAGE_TWI);
		Gura_AssignWxValue(LANGUAGE_UIGHUR);
		Gura_AssignWxValue(LANGUAGE_UKRAINIAN);
		Gura_AssignWxValue(LANGUAGE_URDU);
		Gura_AssignWxValue(LANGUAGE_URDU_INDIA);
		Gura_AssignWxValue(LANGUAGE_URDU_PAKISTAN);
		Gura_AssignWxValue(LANGUAGE_UZBEK);
		Gura_AssignWxValue(LANGUAGE_UZBEK_CYRILLIC);
		Gura_AssignWxValue(LANGUAGE_UZBEK_LATIN);
		Gura_AssignWxValue(LANGUAGE_VALENCIAN);
		Gura_AssignWxValue(LANGUAGE_VIETNAMESE);
		Gura_AssignWxValue(LANGUAGE_VOLAPUK);
		Gura_AssignWxValue(LANGUAGE_WELSH);
		Gura_AssignWxValue(LANGUAGE_WOLOF);
		Gura_AssignWxValue(LANGUAGE_XHOSA);
		Gura_AssignWxValue(LANGUAGE_YIDDISH);
		Gura_AssignWxValue(LANGUAGE_YORUBA);
		Gura_AssignWxValue(LANGUAGE_ZHUANG);
		Gura_AssignWxValue(LANGUAGE_ZULU);
	} while (0);
	do {
		Gura_AssignWxValue(BATTERY_NORMAL_STATE);
		Gura_AssignWxValue(BATTERY_LOW_STATE);
		Gura_AssignWxValue(BATTERY_CRITICAL_STATE);
		Gura_AssignWxValue(BATTERY_SHUTDOWN_STATE);
		Gura_AssignWxValue(BATTERY_UNKNOWN_STATE);
	} while (0);
	do {
		Gura_AssignWxValue(POWER_SOCKET);
		Gura_AssignWxValue(POWER_BATTERY);
		Gura_AssignWxValue(POWER_UNKNOWN);
	} while (0);
	do {
		Gura_AssignWxValue(STOCK_NOFLAGS);
		Gura_AssignWxValue(STOCK_WITH_MNEMONIC);
		Gura_AssignWxValue(STOCK_WITH_ACCELERATOR);
	} while (0);
	do {
		Gura_AssignWxValue(SIZE_AUTO_WIDTH);
		Gura_AssignWxValue(SIZE_AUTO_HEIGHT);
		Gura_AssignWxValue(SIZE_AUTO);
		Gura_AssignWxValue(SIZE_USE_EXISTING);
		Gura_AssignWxValue(SIZE_ALLOW_MINUS_ONE);
		Gura_AssignWxValue(SIZE_FORCE);
	} while (0);
	do {
		Gura_AssignWxValue(SPLIT_VERTICAL);
		Gura_AssignWxValue(SPLIT_HORIZONTAL);
	} while (0);
	do {
		Gura_AssignWxValue(MENU_TEAROFF);
	} while (0);
	do {
		Gura_AssignWxValue(DefaultCoord);
		Gura_AssignWxValue(ScrolledWindowStyle);
	} while (0);
	do {
		Gura_AssignWxValue(Z_DEFAULT_COMPRESSION);
		Gura_AssignWxValue(Z_NO_COMPRESSION);
		Gura_AssignWxValue(Z_BEST_SPEED);
		Gura_AssignWxValue(Z_BEST_COMPRESSION);
	} while (0);
	do {
		Gura_AssignWxValue(ZLIB_NO_HEADER);
		Gura_AssignWxValue(ZLIB_ZLIB);
		Gura_AssignWxValue(ZLIB_GZIP);
		Gura_AssignWxValue(ZLIB_AUTO);
		//Gura_AssignWxValue(ZLIB_24COMPATIBLE);
	} while (0);
	do {
		Gura_AssignWxValue(S_IRUSR);
		Gura_AssignWxValue(S_IWUSR);
		Gura_AssignWxValue(S_IXUSR);
		Gura_AssignWxValue(S_IRGRP);
		Gura_AssignWxValue(S_IWGRP);
		Gura_AssignWxValue(S_IXGRP);
		Gura_AssignWxValue(S_IROTH);
		Gura_AssignWxValue(S_IWOTH);
		Gura_AssignWxValue(S_IXOTH);
		Gura_AssignWxValue(S_DEFAULT);
	} while (0);
	do { // wxFileKind
		Gura_AssignWxValue(FILE_KIND_UNKNOWN);
		Gura_AssignWxValue(FILE_KIND_DISK);
		Gura_AssignWxValue(FILE_KIND_TERMINAL);
		Gura_AssignWxValue(FILE_KIND_PIPE);
	} while (0);
	do { // wxSeekMode
		Gura_AssignWxValue(FromStart);
		Gura_AssignWxValue(FromEnd);
		Gura_AssignWxValue(FromCurrent);
	} while (0);
#if 0
	do {
		_MS(Gura_AssignWxValue(DATAVIEW_COL_RESIZABLE));
		_MS(Gura_AssignWxValue(DATAVIEW_COL_SORTABLE));
		_MS(Gura_AssignWxValue(DATAVIEW_COL_HIDDEN));
	} while (0);
	do { // wxDataViewCellMode
		_MS(Gura_AssignWxValue(DATAVIEW_CELL_INERT));
		_MS(Gura_AssignWxValue(DATAVIEW_CELL_ACTIVATABLE));
		_MS(Gura_AssignWxValue(DATAVIEW_CELL_EDITABLE));
	} while (0);
	do { // wxDataViewCellRenderState
		_MS(Gura_AssignWxValue(DATAVIEW_CELL_SELECTED));
		_MS(Gura_AssignWxValue(DATAVIEW_CELL_PRELIT));
		_MS(Gura_AssignWxValue(DATAVIEW_CELL_INSENSITIVE));
		_MS(Gura_AssignWxValue(DATAVIEW_CELL_FOCUSED));
	} while (0);
#endif
	do { // wxPropertySheetDialog::SetSheetStyle
		Gura_AssignWxValue(PROPSHEET_DEFAULT);
		Gura_AssignWxValue(PROPSHEET_NOTEBOOK);
		Gura_AssignWxValue(PROPSHEET_TOOLBOOK);
		Gura_AssignWxValue(PROPSHEET_CHOICEBOOK);
		Gura_AssignWxValue(PROPSHEET_LISTBOOK);
		Gura_AssignWxValue(PROPSHEET_TREEBOOK);
		Gura_AssignWxValue(PROPSHEET_SHRINKTOFIT);
	} while (0);
	do { // wxWizard::SetBitmapPlacement
		Gura_AssignWxValue(WIZARD_VALIGN_TOP);
		Gura_AssignWxValue(WIZARD_VALIGN_CENTRE);
		Gura_AssignWxValue(WIZARD_VALIGN_BOTTOM);
		Gura_AssignWxValue(WIZARD_HALIGN_LEFT);
		Gura_AssignWxValue(WIZARD_HALIGN_CENTRE);
		Gura_AssignWxValue(WIZARD_HALIGN_RIGHT);
		Gura_AssignWxValue(WIZARD_TILE);
	} while (0);
	do { // wxDialogLayoutAdaptationMode
		Gura_AssignWxValue(DIALOG_ADAPTATION_MODE_DEFAULT);
		Gura_AssignWxValue(DIALOG_ADAPTATION_MODE_ENABLED);
		Gura_AssignWxValue(DIALOG_ADAPTATION_MODE_DISABLED);
	} while (0);
	return true;
}

void InitializeObjects(Environment &env)
{
	do { // wxArtID
		Gura_AssignWxStringValue(ART_ADD_BOOKMARK);
		Gura_AssignWxStringValue(ART_DEL_BOOKMARK);
		Gura_AssignWxStringValue(ART_HELP_SIDE_PANEL);
		Gura_AssignWxStringValue(ART_HELP_SETTINGS);
		Gura_AssignWxStringValue(ART_HELP_BOOK);
		Gura_AssignWxStringValue(ART_HELP_FOLDER);
		Gura_AssignWxStringValue(ART_HELP_PAGE);
		Gura_AssignWxStringValue(ART_GO_BACK);
		Gura_AssignWxStringValue(ART_GO_FORWARD);
		Gura_AssignWxStringValue(ART_GO_UP);
		Gura_AssignWxStringValue(ART_GO_DOWN);
		Gura_AssignWxStringValue(ART_GO_TO_PARENT);
		Gura_AssignWxStringValue(ART_GO_HOME);
		Gura_AssignWxStringValue(ART_FILE_OPEN);
		Gura_AssignWxStringValue(ART_PRINT);
		Gura_AssignWxStringValue(ART_HELP);
		Gura_AssignWxStringValue(ART_TIP);
		Gura_AssignWxStringValue(ART_REPORT_VIEW);
		Gura_AssignWxStringValue(ART_LIST_VIEW);
		Gura_AssignWxStringValue(ART_NEW_DIR);
		Gura_AssignWxStringValue(ART_FOLDER);
		Gura_AssignWxStringValue(ART_GO_DIR_UP);
		Gura_AssignWxStringValue(ART_EXECUTABLE_FILE);
		Gura_AssignWxStringValue(ART_NORMAL_FILE);
		Gura_AssignWxStringValue(ART_TICK_MARK);
		Gura_AssignWxStringValue(ART_CROSS_MARK);
		Gura_AssignWxStringValue(ART_ERROR);
		Gura_AssignWxStringValue(ART_QUESTION);
		Gura_AssignWxStringValue(ART_WARNING);
		Gura_AssignWxStringValue(ART_INFORMATION);
		Gura_AssignWxStringValue(ART_MISSING_IMAGE);
	} while (0);
	do {
		Gura_AssignWxStringValue(ART_TOOLBAR);
		Gura_AssignWxStringValue(ART_MENU);
		Gura_AssignWxStringValue(ART_BUTTON);
		Gura_AssignWxStringValue(ART_FRAME_ICON);
		Gura_AssignWxStringValue(ART_CMN_DIALOG);
		Gura_AssignWxStringValue(ART_HELP_BROWSER);
		Gura_AssignWxStringValue(ART_MESSAGE_BOX);
		Gura_AssignWxStringValue(ART_OTHER);
	} while (0);
	do {
		Gura_AssignWxStringValue(GRID_VALUE_STRING);
		Gura_AssignWxStringValue(GRID_VALUE_BOOL);
		Gura_AssignWxStringValue(GRID_VALUE_NUMBER);
		Gura_AssignWxStringValue(GRID_VALUE_FLOAT);
		Gura_AssignWxStringValue(GRID_VALUE_CHOICE);
		Gura_AssignWxStringValue(GRID_VALUE_TEXT);
		Gura_AssignWxStringValue(GRID_VALUE_LONG);
		Gura_AssignWxStringValue(GRID_VALUE_CHOICEINT);
		Gura_AssignWxStringValue(GRID_VALUE_DATETIME);
	} while (0);
	do {
		Gura_AssignWxStringValue(FileDialogNameStr);
		Gura_AssignWxStringValue(FileSelectorPromptStr);
		Gura_AssignWxStringValue(FileSelectorDefaultWildcardStr);
	} while (0);
	do {
		Gura_AssignValue(EmptyString,			Value(""));
		Gura_AssignWxStringValue(GetTextFromUserPromptStr);
	} while (0);
	do { // Event Types
		Gura_AssignWxEvent(EVT_UPDATE_UI,							EVT_UPDATE_UI,					UpdateUIEvent);
		Gura_AssignWxEvent(EVT_UPDATE_UI,							EVT_UPDATE_UI_RANGE,			UpdateUIEvent);
		Gura_AssignWxEvent(EVT_CALENDAR_DOUBLECLICKED,				EVT_CALENDAR,					CalendarEvent);
		Gura_AssignWxEvent(EVT_CALENDAR_SEL_CHANGED,				EVT_CALENDAR_SEL_CHANGED,		CalendarEvent);
		Gura_AssignWxEvent(EVT_CALENDAR_DAY_CHANGED,				EVT_CALENDAR_DAY,				CalendarEvent);
		Gura_AssignWxEvent(EVT_CALENDAR_MONTH_CHANGED,				EVT_CALENDAR_MONTH,				CalendarEvent);
		Gura_AssignWxEvent(EVT_CALENDAR_YEAR_CHANGED,				EVT_CALENDAR_YEAR,				CalendarEvent);
		Gura_AssignWxEvent(EVT_CALENDAR_WEEKDAY_CLICKED,			EVT_CALENDAR_WEEKDAY_CLICKED,	CalendarEvent);
		Gura_AssignWxEvent(EVT_DATE_CHANGED,						EVT_DATE_CHANGED,				DateEvent);
		Gura_AssignWxEvent(EVT_CONTEXT_MENU,						EVT_CONTEXT_MENU,				ContextMenuEvent);
		Gura_AssignWxEvent(EVT_DROP_FILES,							EVT_DROP_FILES,					DropFilesEvent);
		Gura_AssignWxEvent(EVT_ERASE_BACKGROUND,					EVT_ERASE_BACKGROUND,			EraseEvent);
		Gura_AssignWxEvent(EVT_SET_CURSOR,							EVT_SET_CURSOR,					SetCursorEvent);
		Gura_AssignWxEvent(EVT_IDLE,								EVT_IDLE,						IdleEvent);
		Gura_AssignWxEvent(EVT_MAXIMIZE,							EVT_MAXIMIZE,					MaximizeEvent);
		Gura_AssignWxEvent(EVT_ICONIZE,								EVT_ICONIZE,					IconizeEvent);
		Gura_AssignWxEvent(EVT_MOVE,								EVT_MOVE,						MoveEvent);
		Gura_AssignWxEvent(EVT_PAINT,								EVT_PAINT,						PaintEvent);
		Gura_AssignWxEvent(EVT_QUERY_LAYOUT_INFO,					EVT_QUERY_LAYOUT_INFO,			QueryLayoutInfoEvent);
		Gura_AssignWxEvent(EVT_INIT_DIALOG,							EVT_INIT_DIALOG,				InitDialogEvent);
		Gura_AssignWxEvent(EVT_SHOW,								EVT_SHOW,						ShowEvent);
		Gura_AssignWxEvent(EVT_SIZE,								EVT_SIZE,						SizeEvent);
		Gura_AssignWxEvent(EVT_TIMER,								EVT_TIMER,						TimerEvent);
		Gura_AssignWxEvent(EVT_HELP,								EVT_HELP,						HelpEvent);
		Gura_AssignWxEvent(EVT_CREATE,								EVT_WINDOW_CREATE,				WindowCreateEvent);
		Gura_AssignWxEvent(EVT_DESTROY,								EVT_WINDOW_DESTROY,				WindowDestroyEvent);
		Gura_AssignWxEvent(EVT_SYS_COLOUR_CHANGED,					EVT_SYS_COLOUR_CHANGED,			SysColourChangedEvent);
		Gura_AssignWxEvent(EVT_ACTIVATE,							EVT_ACTIVATE,					ActivateEvent);
		Gura_AssignWxEvent(EVT_ACTIVATE_APP,						EVT_ACTIVATE_APP,				ActivateEvent);
		Gura_AssignWxEvent(EVT_HIBERNATE,							EVT_HIBERNATE,					ActivateEvent);
		Gura_AssignWxEvent(EVT_COMMAND_BUTTON_CLICKED,				EVT_BUTTON,						CommandEvent);
		Gura_AssignWxEvent(EVT_CALCULATE_LAYOUT,					EVT_CALCULATE_LAYOUT,			CalculateLayoutEvent);
		Gura_AssignWxEvent(EVT_COMMAND_CHECKBOX_CLICKED,			EVT_CHECKBOX,					CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_CHECKLISTBOX_TOGGLED,		EVT_CHECKLISTBOX,				CommandEvent);
		Gura_AssignWxEvent(EVT_CHILD_FOCUS,							EVT_CHILD_FOCUS,				ChildFocusEvent);
		Gura_AssignWxEvent(EVT_COMMAND_CHOICE_SELECTED,				EVT_CHOICE,						CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TEXT_COPY,					EVT_TEXT_COPY,					ClipboardTextEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TEXT_CUT,					EVT_TEXT_CUT,					ClipboardTextEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TEXT_PASTE,					EVT_TEXT_PASTE,					ClipboardTextEvent);
		Gura_AssignWxEvent(EVT_CLOSE_WINDOW,						EVT_CLOSE,						CloseEvent);
		Gura_AssignWxEvent(EVT_QUERY_END_SESSION,					EVT_QUERY_END_SESSION,			CloseEvent);
		Gura_AssignWxEvent(EVT_END_SESSION,							EVT_END_SESSION,				CloseEvent);
		Gura_AssignWxEvent(EVT_COMMAND_COLOURPICKER_CHANGED,		EVT_COLOURPICKER_CHANGED,		ColourPickerEvent);
		Gura_AssignWxEvent(EVT_COMMAND_COMBOBOX_SELECTED,			EVT_COMBOBOX,					CommandEvent);
	_MS(Gura_AssignWxEvent(EVT_COMMAND_COMBOBOX_DROPDOWN,			EVT_COMBOBOX_DROPDOWN,			CommandEvent));
	_MS(Gura_AssignWxEvent(EVT_COMMAND_COMBOBOX_CLOSEUP,			EVT_COMBOBOX_CLOSEUP,			CommandEvent));
		Gura_AssignWxEvent(EVT_COMMAND_MENU_SELECTED,				EVT_MENU,						CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_MENU_SELECTED,				EVT_MENU_RANGE,					CommandEvent);
		//Gura_AssignWxEvent(EVT_COMMAND_CONTEXT_MENU,				EVT_CONTEXT_MENU,				CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TOGGLEBUTTON_CLICKED,		EVT_TOGGLEBUTTON,				CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TOOL_CLICKED,				EVT_TOOL,						CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TOOL_CLICKED,				EVT_TOOL_RANGE,					CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TOOL_RCLICKED,				EVT_TOOL_RCLICKED,				CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TOOL_RCLICKED,				EVT_TOOL_RCLICKED_RANGE,		CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TOOL_ENTER,					EVT_TOOL_ENTER,					CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LEFT_CLICK,					EVT_COMMAND_LEFT_CLICK,			CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LEFT_DCLICK,					EVT_COMMAND_LEFT_DCLICK,		CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_RIGHT_CLICK,					EVT_COMMAND_RIGHT_CLICK,		CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_RIGHT_DCLICK,				EVT_COMMAND_RIGHT_DCLICK,		CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_SET_FOCUS,					EVT_COMMAND_SET_FOCUS,			CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_KILL_FOCUS,					EVT_COMMAND_KILL_FOCUS,			CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_ENTER,						EVT_COMMAND_ENTER,				CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_FILEPICKER_CHANGED,			EVT_FILEPICKER_CHANGED,			FileDirPickerEvent);
		Gura_AssignWxEvent(EVT_COMMAND_DIRPICKER_CHANGED,			EVT_DIRPICKER_CHANGED,			FileDirPickerEvent);
		Gura_AssignWxEvent(EVT_SET_FOCUS,							EVT_SET_FOCUS,					FocusEvent);
		Gura_AssignWxEvent(EVT_KILL_FOCUS,							EVT_KILL_FOCUS,					FocusEvent);
		Gura_AssignWxEvent(EVT_COMMAND_FONTPICKER_CHANGED,			EVT_FONTPICKER_CHANGED,			FontPickerEvent);
		Gura_AssignWxEvent(EVT_GRID_EDITOR_CREATED,					EVT_GRID_EDITOR_CREATED,		GridEditorCreatedEvent);
		Gura_AssignWxEvent(EVT_GRID_CELL_LEFT_CLICK,				EVT_GRID_CELL_LEFT_CLICK,		GridEvent);
		Gura_AssignWxEvent(EVT_GRID_CELL_RIGHT_CLICK,				EVT_GRID_CELL_RIGHT_CLICK,		GridEvent);
		Gura_AssignWxEvent(EVT_GRID_CELL_LEFT_DCLICK,				EVT_GRID_CELL_LEFT_DCLICK,		GridEvent);
		Gura_AssignWxEvent(EVT_GRID_CELL_RIGHT_DCLICK,				EVT_GRID_CELL_RIGHT_DCLICK,		GridEvent);
		Gura_AssignWxEvent(EVT_GRID_LABEL_LEFT_CLICK,				EVT_GRID_LABEL_LEFT_CLICK,		GridEvent);
		Gura_AssignWxEvent(EVT_GRID_LABEL_RIGHT_CLICK,				EVT_GRID_LABEL_RIGHT_CLICK,		GridEvent);
		Gura_AssignWxEvent(EVT_GRID_LABEL_LEFT_DCLICK,				EVT_GRID_LABEL_LEFT_DCLICK,		GridEvent);
		Gura_AssignWxEvent(EVT_GRID_LABEL_RIGHT_DCLICK,				EVT_GRID_LABEL_RIGHT_DCLICK,	GridEvent);
		Gura_AssignWxEvent(EVT_GRID_CELL_CHANGE,					EVT_GRID_CELL_CHANGE,			GridEvent);
		Gura_AssignWxEvent(EVT_GRID_SELECT_CELL,					EVT_GRID_SELECT_CELL,			GridEvent);
		Gura_AssignWxEvent(EVT_GRID_EDITOR_HIDDEN,					EVT_GRID_EDITOR_HIDDEN,			GridEvent);
		Gura_AssignWxEvent(EVT_GRID_EDITOR_SHOWN,					EVT_GRID_EDITOR_SHOWN,			GridEvent);
		Gura_AssignWxEvent(EVT_GRID_RANGE_SELECT,					EVT_GRID_RANGE_SELECT,			GridRangeSelectEvent);
		Gura_AssignWxEvent(EVT_GRID_COL_SIZE,						EVT_GRID_COL_SIZE,				GridSizeEvent);
		Gura_AssignWxEvent(EVT_GRID_ROW_SIZE,						EVT_GRID_ROW_SIZE,				GridSizeEvent);
		Gura_AssignWxEvent(EVT_COMMAND_HTML_CELL_HOVER,				EVT_HTML_CELL_HOVER,			HtmlCellEvent);
		Gura_AssignWxEvent(EVT_COMMAND_HTML_CELL_CLICKED,			EVT_HTML_CELL_CLICKED,			HtmlCellEvent);
		Gura_AssignWxEvent(EVT_COMMAND_HTML_LINK_CLICKED,			EVT_HTML_LINK_CLICKED,			HtmlLinkEvent);
		Gura_AssignWxEvent(EVT_COMMAND_HYPERLINK,					EVT_HYPERLINK,					HyperlinkEvent);
		Gura_AssignWxEvent(EVT_JOY_BUTTON_DOWN,						EVT_JOY_BUTTON_DOWN,			JoystickEvent);
		Gura_AssignWxEvent(EVT_JOY_BUTTON_UP,						EVT_JOY_BUTTON_UP,				JoystickEvent);
		Gura_AssignWxEvent(EVT_JOY_MOVE,							EVT_JOY_MOVE,					JoystickEvent);
		Gura_AssignWxEvent(EVT_JOY_ZMOVE,							EVT_JOY_ZMOVE,					JoystickEvent);
		Gura_AssignWxEvent(EVT_KEY_DOWN,							EVT_KEY_DOWN,					KeyEvent);
		Gura_AssignWxEvent(EVT_KEY_UP,								EVT_KEY_UP,						KeyEvent);
		Gura_AssignWxEvent(EVT_CHAR,								EVT_CHAR,						KeyEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LISTBOX_SELECTED,			EVT_LISTBOX,					CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LISTBOX_DOUBLECLICKED,		EVT_LISTBOX_DCLICK,				CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_BEGIN_DRAG,				EVT_LIST_BEGIN_DRAG,			ListEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_BEGIN_RDRAG,			EVT_LIST_BEGIN_RDRAG,			ListEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_BEGIN_LABEL_EDIT,		EVT_LIST_BEGIN_LABEL_EDIT,		ListEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_END_LABEL_EDIT,			EVT_LIST_END_LABEL_EDIT,		ListEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_DELETE_ITEM,			EVT_LIST_DELETE_ITEM,			ListEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_DELETE_ALL_ITEMS,		EVT_LIST_DELETE_ALL_ITEMS,		ListEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_ITEM_SELECTED,			EVT_LIST_ITEM_SELECTED,			ListEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_ITEM_DESELECTED,		EVT_LIST_ITEM_DESELECTED,		ListEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_ITEM_ACTIVATED,			EVT_LIST_ITEM_ACTIVATED,		ListEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_ITEM_FOCUSED,			EVT_LIST_ITEM_FOCUSED,			ListEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_ITEM_MIDDLE_CLICK,		EVT_LIST_ITEM_MIDDLE_CLICK,		ListEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_ITEM_RIGHT_CLICK,		EVT_LIST_ITEM_RIGHT_CLICK,		ListEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_KEY_DOWN,				EVT_LIST_KEY_DOWN,				ListEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_INSERT_ITEM,			EVT_LIST_INSERT_ITEM,			ListEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_COL_CLICK,				EVT_LIST_COL_CLICK,				ListEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_COL_RIGHT_CLICK,		EVT_LIST_COL_RIGHT_CLICK,		ListEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_COL_BEGIN_DRAG,			EVT_LIST_COL_BEGIN_DRAG,		ListEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_COL_DRAGGING,			EVT_LIST_COL_DRAGGING,			ListEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_COL_END_DRAG,			EVT_LIST_COL_END_DRAG,			ListEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LIST_CACHE_HINT,				EVT_LIST_CACHE_HINT,			ListEvent);
		Gura_AssignWxEvent(EVT_MENU_OPEN,							EVT_MENU_OPEN,					MenuEvent);
		Gura_AssignWxEvent(EVT_MENU_CLOSE,							EVT_MENU_CLOSE,					MenuEvent);
		Gura_AssignWxEvent(EVT_MENU_HIGHLIGHT,						EVT_MENU_HIGHLIGHT,				MenuEvent);
		Gura_AssignWxEvent(EVT_ENTER_WINDOW,						EVT_ENTER_WINDOW,				MouseEvent);
		Gura_AssignWxEvent(EVT_LEAVE_WINDOW,						EVT_LEAVE_WINDOW,				MouseEvent);
		Gura_AssignWxEvent(EVT_LEFT_DOWN,							EVT_LEFT_DOWN,					MouseEvent);
		Gura_AssignWxEvent(EVT_LEFT_UP,								EVT_LEFT_UP,					MouseEvent);
		Gura_AssignWxEvent(EVT_LEFT_DCLICK,							EVT_LEFT_DCLICK,				MouseEvent);
		Gura_AssignWxEvent(EVT_MIDDLE_DOWN,							EVT_MIDDLE_DOWN,				MouseEvent);
		Gura_AssignWxEvent(EVT_MIDDLE_UP,							EVT_MIDDLE_UP,					MouseEvent);
		Gura_AssignWxEvent(EVT_MIDDLE_DCLICK,						EVT_MIDDLE_DCLICK,				MouseEvent);
		Gura_AssignWxEvent(EVT_RIGHT_DOWN,							EVT_RIGHT_DOWN,					MouseEvent);
		Gura_AssignWxEvent(EVT_RIGHT_UP,							EVT_RIGHT_UP,					MouseEvent);
		Gura_AssignWxEvent(EVT_RIGHT_DCLICK,						EVT_RIGHT_DCLICK,				MouseEvent);
		Gura_AssignWxEvent(EVT_MOTION,								EVT_MOTION,						MouseEvent);
		Gura_AssignWxEvent(EVT_MOUSEWHEEL,							EVT_MOUSEWHEEL,					MouseEvent);
		Gura_AssignWxEvent(EVT_COMMAND_NOTEBOOK_PAGE_CHANGED,		EVT_NOTEBOOK_PAGE_CHANGED,		NotebookEvent);
		Gura_AssignWxEvent(EVT_COMMAND_NOTEBOOK_PAGE_CHANGING,		EVT_NOTEBOOK_PAGE_CHANGING,		NotebookEvent);
		Gura_AssignWxEvent(EVT_COMMAND_NOTEBOOK_PAGE_CHANGED,		EVT_BOOKCTRL_PAGE_CHANGED,		NotebookEvent);
		Gura_AssignWxEvent(EVT_COMMAND_NOTEBOOK_PAGE_CHANGING,		EVT_BOOKCTRL_PAGE_CHANGING,		NotebookEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LISTBOOK_PAGE_CHANGED,		EVT_LISTBOOK_PAGE_CHANGED,		ListbookEvent);
		Gura_AssignWxEvent(EVT_COMMAND_LISTBOOK_PAGE_CHANGING,		EVT_LISTBOOK_PAGE_CHANGING,		ListbookEvent);
		Gura_AssignWxEvent(EVT_COMMAND_CHOICEBOOK_PAGE_CHANGED,		EVT_CHOICEBOOK_PAGE_CHANGED,	ChoicebookEvent);
		Gura_AssignWxEvent(EVT_COMMAND_CHOICEBOOK_PAGE_CHANGING,	EVT_CHOICEBOOK_PAGE_CHANGING,	ChoicebookEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TOOLBOOK_PAGE_CHANGED,		EVT_TOOLBOOK_PAGE_CHANGED,		ToolbookEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TOOLBOOK_PAGE_CHANGING,		EVT_TOOLBOOK_PAGE_CHANGING,		ToolbookEvent);
		Gura_AssignWxEvent(EVT_COMMAND_RADIOBOX_SELECTED,			EVT_RADIOBOX,					CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_RADIOBUTTON_SELECTED,		EVT_RADIOBUTTON,				CommandEvent);
		Gura_AssignWxEvent(EVT_SASH_DRAGGED,						EVT_SASH_DRAGGED,				SashEvent);
		Gura_AssignWxEvent(EVT_SASH_DRAGGED,						EVT_SASH_DRAGGED_RANGE,			SashEvent);
		Gura_AssignWxEvent(EVT_COMMAND_SCROLLBAR_UPDATED,			EVT_SCROLLBAR,					CommandEvent);
		Gura_AssignWxEvent(EVT_SCROLL_TOP,							EVT_SCROLL_TOP,					ScrollEvent);
		Gura_AssignWxEvent(EVT_SCROLL_BOTTOM,						EVT_SCROLL_BOTTOM,				ScrollEvent);
		Gura_AssignWxEvent(EVT_SCROLL_LINEUP,						EVT_SCROLL_LINEUP,				ScrollEvent);
		Gura_AssignWxEvent(EVT_SCROLL_LINEDOWN,						EVT_SCROLL_LINEDOWN,			ScrollEvent);
		Gura_AssignWxEvent(EVT_SCROLL_PAGEUP,						EVT_SCROLL_PAGEUP,				ScrollEvent);
		Gura_AssignWxEvent(EVT_SCROLL_PAGEDOWN,						EVT_SCROLL_PAGEDOWN,			ScrollEvent);
		Gura_AssignWxEvent(EVT_SCROLL_THUMBTRACK,					EVT_SCROLL_THUMBTRACK,			ScrollEvent);
		Gura_AssignWxEvent(EVT_SCROLL_THUMBRELEASE,					EVT_SCROLL_THUMBRELEASE,		ScrollEvent);
		Gura_AssignWxEvent(EVT_SCROLL_CHANGED,						EVT_SCROLL_CHANGED,				ScrollEvent);
		Gura_AssignWxEvent(EVT_SCROLLWIN_TOP,						EVT_SCROLLWIN_TOP,				ScrollWinEvent);
		Gura_AssignWxEvent(EVT_SCROLLWIN_BOTTOM,					EVT_SCROLLWIN_BOTTOM,			ScrollWinEvent);
		Gura_AssignWxEvent(EVT_SCROLLWIN_LINEUP,					EVT_SCROLLWIN_LINEUP,			ScrollWinEvent);
		Gura_AssignWxEvent(EVT_SCROLLWIN_LINEDOWN,					EVT_SCROLLWIN_LINEDOWN,			ScrollWinEvent);
		Gura_AssignWxEvent(EVT_SCROLLWIN_PAGEUP,					EVT_SCROLLWIN_PAGEUP,			ScrollWinEvent);
		Gura_AssignWxEvent(EVT_SCROLLWIN_PAGEDOWN,					EVT_SCROLLWIN_PAGEDOWN,			ScrollWinEvent);
		Gura_AssignWxEvent(EVT_SCROLLWIN_THUMBTRACK,				EVT_SCROLLWIN_THUMBTRACK,		ScrollWinEvent);
		Gura_AssignWxEvent(EVT_SCROLLWIN_THUMBRELEASE,				EVT_SCROLLWIN_THUMBRELEASE,		ScrollWinEvent);
		//Gura_AssignWxEvent(EVT_SCROLLWIN_CHANGED,					EVT_SCROLLWIN_CHANGED,			ScrollWinEvent);
		Gura_AssignWxEvent(EVT_COMMAND_SEARCHCTRL_SEARCH_BTN,		EVT_SEARCHCTRL_SEARCH_BTN,		CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_SEARCHCTRL_CANCEL_BTN,		EVT_SEARCHCTRL_CANCEL_BTN,		CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_SLIDER_UPDATED,				EVT_SLIDER,						CommandEvent);
		Gura_AssignWxEvent(EVT_SCROLL_THUMBTRACK,					EVT_SPIN,						SpinEvent);
		Gura_AssignWxEvent(EVT_SCROLL_LINEUP,						EVT_SPIN_UP,					SpinEvent);
		Gura_AssignWxEvent(EVT_SCROLL_LINEDOWN,						EVT_SPIN_DOWN,					SpinEvent);
		Gura_AssignWxEvent(EVT_COMMAND_SPINCTRL_UPDATED,			EVT_SPINCTRL,					SpinEvent);
		Gura_AssignWxEvent(EVT_COMMAND_SPLITTER_SASH_POS_CHANGING,	EVT_SPLITTER_SASH_POS_CHANGING,	SplitterEvent);
		Gura_AssignWxEvent(EVT_COMMAND_SPLITTER_SASH_POS_CHANGED,	EVT_SPLITTER_SASH_POS_CHANGED,	SplitterEvent);
		Gura_AssignWxEvent(EVT_COMMAND_SPLITTER_UNSPLIT,			EVT_SPLITTER_UNSPLIT,			SplitterEvent);
		Gura_AssignWxEvent(EVT_COMMAND_SPLITTER_DOUBLECLICKED,		EVT_SPLITTER_DCLICK,			SplitterEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TEXT_UPDATED,				EVT_TEXT,						CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TEXT_ENTER,					EVT_TEXT_ENTER,					CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TEXT_URL,					EVT_TEXT_URL,					CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TEXT_MAXLEN,					EVT_TEXT_MAXLEN,				CommandEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREEBOOK_PAGE_CHANGED,		EVT_TREEBOOK_PAGE_CHANGED,		TreebookEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREEBOOK_PAGE_CHANGING,		EVT_TREEBOOK_PAGE_CHANGING,		TreebookEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREEBOOK_NODE_COLLAPSED,		EVT_TREEBOOK_NODE_COLLAPSED,	TreebookEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREEBOOK_NODE_EXPANDED,		EVT_TREEBOOK_NODE_EXPANDED,		TreebookEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREE_BEGIN_DRAG,				EVT_TREE_BEGIN_DRAG,			TreeEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREE_BEGIN_RDRAG,			EVT_TREE_BEGIN_RDRAG,			TreeEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREE_BEGIN_LABEL_EDIT,		EVT_TREE_BEGIN_LABEL_EDIT,		TreeEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREE_END_DRAG,				EVT_TREE_END_DRAG,				TreeEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREE_END_LABEL_EDIT,			EVT_TREE_END_LABEL_EDIT,		TreeEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREE_DELETE_ITEM,			EVT_TREE_DELETE_ITEM,			TreeEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREE_ITEM_ACTIVATED,			EVT_TREE_ITEM_ACTIVATED,		TreeEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREE_ITEM_COLLAPSED,			EVT_TREE_ITEM_COLLAPSED,		TreeEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREE_ITEM_COLLAPSING,		EVT_TREE_ITEM_COLLAPSING,		TreeEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREE_ITEM_EXPANDED,			EVT_TREE_ITEM_EXPANDED,			TreeEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREE_ITEM_EXPANDING,			EVT_TREE_ITEM_EXPANDING,		TreeEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREE_ITEM_RIGHT_CLICK,		EVT_TREE_ITEM_RIGHT_CLICK,		TreeEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREE_ITEM_MIDDLE_CLICK,		EVT_TREE_ITEM_MIDDLE_CLICK,		TreeEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREE_KEY_DOWN,				EVT_TREE_KEY_DOWN,				TreeEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREE_SEL_CHANGED,			EVT_TREE_SEL_CHANGED,			TreeEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREE_SEL_CHANGING,			EVT_TREE_SEL_CHANGING,			TreeEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREE_ITEM_GETTOOLTIP,		EVT_TREE_ITEM_GETTOOLTIP,		TreeEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREE_ITEM_MENU,				EVT_TREE_ITEM_MENU,				TreeEvent);
		Gura_AssignWxEvent(EVT_COMMAND_TREE_STATE_IMAGE_CLICK,		EVT_TREE_STATE_IMAGE_CLICK,		TreeEvent);
		Gura_AssignWxEvent(EVT_WIZARD_PAGE_CHANGED,					EVT_WIZARD_PAGE_CHANGED,		WizardEvent);
		Gura_AssignWxEvent(EVT_WIZARD_PAGE_CHANGING,				EVT_WIZARD_PAGE_CHANGING,		WizardEvent);
		Gura_AssignWxEvent(EVT_WIZARD_PAGE_SHOWN,					EVT_WIZARD_PAGE_SHOWN,			WizardEvent);
		Gura_AssignWxEvent(EVT_WIZARD_CANCEL,						EVT_WIZARD_CANCEL,				WizardEvent);
		Gura_AssignWxEvent(EVT_WIZARD_HELP,							EVT_WIZARD_HELP,				WizardEvent);
		Gura_AssignWxEvent(EVT_WIZARD_FINISHED,						EVT_WIZARD_FINISHED,			WizardEvent);
		Gura_AssignWxEvent(EVT_COMMAND_HTML_CELL_CLICKED,			EVT_HTML_CELL_CLICKED,			HtmlCellEvent);
		Gura_AssignWxEvent(EVT_COMMAND_HTML_CELL_HOVER,				EVT_HTML_CELL_HOVER,			HtmlCellEvent);
		Gura_AssignWxEvent(EVT_COMMAND_HTML_LINK_CLICKED,			EVT_HTML_LINK_CLICKED,			HtmlLinkEvent);
		Gura_AssignWxEvent(EVT_COMMAND_RICHTEXT_CHARACTER,			EVT_RICHTEXT_CHARACTER,			RichTextEvent);
		Gura_AssignWxEvent(EVT_COMMAND_RICHTEXT_DELETE,				EVT_RICHTEXT_DELETE,			RichTextEvent);
		Gura_AssignWxEvent(EVT_COMMAND_RICHTEXT_RETURN,				EVT_RICHTEXT_RETURN,			RichTextEvent);
		Gura_AssignWxEvent(EVT_COMMAND_RICHTEXT_STYLE_CHANGED,		EVT_RICHTEXT_STYLE_CHANGED,		RichTextEvent);
		Gura_AssignWxEvent(EVT_COMMAND_RICHTEXT_STYLESHEET_CHANGED,	EVT_RICHTEXT_STYLESHEET_CHANGED,RichTextEvent);
		Gura_AssignWxEvent(EVT_COMMAND_RICHTEXT_STYLESHEET_CHANGING,EVT_RICHTEXT_STYLESHEET_CHANGING,RichTextEvent);
		Gura_AssignWxEvent(EVT_COMMAND_RICHTEXT_STYLESHEET_REPLACING,EVT_RICHTEXT_STYLESHEET_REPLACING,RichTextEvent);
		Gura_AssignWxEvent(EVT_COMMAND_RICHTEXT_STYLESHEET_REPLACED,EVT_RICHTEXT_STYLESHEET_REPLACED,RichTextEvent);
		Gura_AssignWxEvent(EVT_COMMAND_RICHTEXT_CONTENT_INSERTED,	EVT_RICHTEXT_CONTENT_INSERTED,	RichTextEvent);
		Gura_AssignWxEvent(EVT_COMMAND_RICHTEXT_CONTENT_DELETED,	EVT_RICHTEXT_CONTENT_DELETED,	RichTextEvent);
		Gura_AssignWxEvent(EVT_COMMAND_RICHTEXT_BUFFER_RESET,		EVT_RICHTEXT_BUFFER_RESET,		RichTextEvent);
		Gura_AssignWxEvent(EVT_COMMAND_COLLPANE_CHANGED,			EVT_COLLAPSIBLEPANE_CHANGED,	CollapsiblePaneEvent);
#if 0
	_MS(Gura_AssignWxEvent(EVT_COMMAND_DATAVIEW_ROW_SELECTED,		EVT_DATAVIEW_ROW_SELECTED,		DataViewEvent));
	_MS(Gura_AssignWxEvent(EVT_COMMAND_DATAVIEW_ROW_ACTIVATED,		EVT_DATAVIEW_ROW_ACTIVATED,		DataViewEvent));
	_MS(Gura_AssignWxEvent(EVT_COMMAND_DATAVIEW_COLUMN_HEADER_CLICK, EVT_DATAVIEW_COLUMN_HEADER_CLICK, DataViewEvent));
	_MS(Gura_AssignWxEvent(EVT_COMMAND_DATAVIEW_COLUMN_HEADER_RIGHT_CLICK, EVT_DATAVIEW_COLUMN_HEADER_RIGHT_CLICK, DataViewEvent));
#endif
		Gura_AssignWxEvent(EVT_COMMAND_FIND,						EVT_FIND,						FindDialogEvent);
		Gura_AssignWxEvent(EVT_COMMAND_FIND_NEXT,					EVT_FIND_NEXT,					FindDialogEvent);
		Gura_AssignWxEvent(EVT_COMMAND_FIND_REPLACE,				EVT_FIND_REPLACE,				FindDialogEvent);
		Gura_AssignWxEvent(EVT_COMMAND_FIND_REPLACE_ALL,			EVT_FIND_REPLACE_ALL,			FindDialogEvent);
		Gura_AssignWxEvent(EVT_COMMAND_FIND_CLOSE,					EVT_FIND_CLOSE,					FindDialogEvent);
	_MS(Gura_AssignWxEvent(EVT_MOUSE_CAPTURE_LOST,					EVT_MOUSE_CAPTURE_LOST,			MouseCaptureLostEvent));
	_MS(Gura_AssignWxEvent(EVT_MOUSE_CAPTURE_CHANGED,				EVT_MOUSE_CAPTURE_CHANGED,		MouseCaptureChangedEvent));
		Gura_AssignWxEventComplex(									EVT_JOYSTICK_EVENTS,			JoystickEvent);
		Gura_AssignWxEventComplex(									EVT_SCROLL,						ScrollEvent);
		Gura_AssignWxEventComplex(									EVT_SCROLLWIN,					ScrollWinEvent);
		Gura_AssignWxEventComplex(									EVT_MOUSE_EVENTS,				MouseEvent);
	} while (0);
	do { // Predefined Objects of wxPoint
		Gura_AssignWxObjectEx(DefaultPosition,	Point, &wxDefaultPosition);
	} while (0);
	do { // Predefined Objects of wxSize
		Gura_AssignWxObjectEx(DefaultSize,		Size, &wxDefaultSize);
	} while (0);
	do { // Predefined Objects of wxDateTime
		Gura_AssignWxObjectEx(DefaultDateTime,	DateTime, &wxDefaultDateTime);
		Gura_AssignWxObjectEx(InvalidDateTime,	DateTime, &wxInvalidDateTime);
	} while (0);
	do { // Predefined Objects of wxColour
		Gura_AssignWxObjectEx(NullColour,		Colour, &wxNullColour);
		Gura_AssignWxObject(BLACK,				Colour);
		Gura_AssignWxObject(WHITE,				Colour);
		Gura_AssignWxObject(RED,				Colour);
		Gura_AssignWxObject(BLUE,				Colour);
		Gura_AssignWxObject(GREEN,				Colour);
		Gura_AssignWxObject(CYAN,				Colour);
		Gura_AssignWxObject(LIGHT_GREY,			Colour);
	} while (0);
	do { // Predefined Objects of wxPen
		Gura_AssignWxObjectEx(NullPen,			Pen, &wxNullPen);
		Gura_AssignWxObject(BLACK_DASHED_PEN,	Pen);
		Gura_AssignWxObject(RED_PEN,			Pen);
		Gura_AssignWxObject(CYAN_PEN,			Pen);
		Gura_AssignWxObject(GREEN_PEN,			Pen);
		Gura_AssignWxObject(BLACK_PEN,			Pen);
		Gura_AssignWxObject(WHITE_PEN,			Pen);
		Gura_AssignWxObject(TRANSPARENT_PEN,	Pen);
		Gura_AssignWxObject(BLACK_DASHED_PEN,	Pen);
		Gura_AssignWxObject(GREY_PEN,			Pen);
		Gura_AssignWxObject(MEDIUM_GREY_PEN,	Pen);
		Gura_AssignWxObject(LIGHT_GREY_PEN,		Pen);
	} while (0);
	do { // Predefined Objects of wxBrush
		Gura_AssignWxObjectEx(NullBrush,		Brush, &wxNullBrush);
		Gura_AssignWxObject(BLUE_BRUSH,			Brush);
		Gura_AssignWxObject(GREEN_BRUSH,		Brush);
		Gura_AssignWxObject(WHITE_BRUSH,		Brush);
		Gura_AssignWxObject(BLACK_BRUSH,		Brush);
		Gura_AssignWxObject(GREY_BRUSH,			Brush);
		Gura_AssignWxObject(MEDIUM_GREY_BRUSH,	Brush);
		Gura_AssignWxObject(LIGHT_GREY_BRUSH,	Brush);
		Gura_AssignWxObject(TRANSPARENT_BRUSH,	Brush);
		Gura_AssignWxObject(CYAN_BRUSH,			Brush);
		Gura_AssignWxObject(RED_BRUSH,			Brush);
	} while (0);
	do { // Predefined Objects of wxFont
		Gura_AssignWxObjectEx(NullFont,			Font, &wxNullFont);
		Gura_AssignWxObject(NORMAL_FONT,		Font);
		Gura_AssignWxObject(SMALL_FONT,			Font);
		Gura_AssignWxObject(ITALIC_FONT,		Font);
		Gura_AssignWxObject(SWISS_FONT,			Font);
	} while (0);
	do { // Predefined Objects of wxBitmap
		Gura_AssignWxObjectEx(NullBitmap,		Bitmap, &wxNullBitmap);
	} while (0);
	do { // Predefined Objects of wxImage
		Gura_AssignWxObjectEx(NullImage,		Image, &wxNullImage);
	} while (0);
	do { // Predefined Objects of wxIcon
		Gura_AssignWxObjectEx(NullIcon,			Icon, &wxNullIcon);
	} while (0);
	do { // Predefined Objects of wxPalette
		Gura_AssignWxObjectEx(NullPalette,		Palette, &wxNullPalette);
	} while (0);
	do { // Predefined Objects of wxCursor
		Gura_AssignWxObjectEx(NullCursor,		Cursor, &wxNullCursor);
		Gura_AssignWxObject(STANDARD_CURSOR,	Cursor);
		Gura_AssignWxObject(HOURGLASS_CURSOR,	Cursor);
		Gura_AssignWxObject(CROSS_CURSOR,		Cursor);
	} while (0);
	do { // Predefined Objects of wxValidator
		Gura_AssignWxObjectEx(DefaultValidator,	Validator, &wxDefaultValidator);
	} while (0);
	do { // Predefined Objects of wxSpan
		Gura_AssignWxObjectEx(DefaultSpan,		GBSpan, &wxDefaultSpan);
	} while (0);
	do { // Predefined Objects of wxClipboard
		Gura_AssignWxObject(TheClipboard,		Clipboard);
	} while (0);
	do { // Predefined Objects of wxDataFormat
		//Gura_AssignWxObjectEx(DF_INVALID,		DataFormat, new wxDataFormat(wxDF_INVALID));
		Gura_AssignWxObjectEx(DF_TEXT,			DataFormat, new wxDataFormat(wxDF_TEXT));
		Gura_AssignWxObjectEx(DF_BITMAP,		DataFormat, new wxDataFormat(wxDF_BITMAP));
	_MS(Gura_AssignWxObjectEx(DF_METAFILE,		DataFormat, new wxDataFormat(wxDF_METAFILE)));
		Gura_AssignWxObjectEx(DF_FILENAME,		DataFormat, new wxDataFormat(wxDF_FILENAME));
	_MS(Gura_AssignWxObjectEx(DF_HTML,			DataFormat, new wxDataFormat(wxDF_HTML)));
	} while (0);
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utility functions
//-----------------------------------------------------------------------------
void SetWxReadyFlag(bool wxReadyFlag)
{
	g_wxReadyFlag = wxReadyFlag;
}

bool IsWxReady()
{
	return g_wxReadyFlag;
}

bool CheckWxReady(Signal sig)
{
	if (g_wxReadyFlag) return true;
	sig.SetError(ERR_RuntimeError, "wxWidgets functions must be called after wxApp::OnInit");
	return false;
}

void SetError_NotImplemented(Signal sig)
{
	sig.SetError(ERR_NotImplementedError, "sorry, not implemented yet");
}

void SetError_MSWOnly(Signal sig)
{
	sig.SetError(ERR_NotImplementedError, "this function is only implemented in MSW");
}

void SetError_InvalidWxObject(Signal sig, const char *name)
{
	sig.SetError(ERR_ValueError, "invalid wx object of %s", name);
}

void SetLogError(const Signal &sig)
{
	//::wxLogError(wxString::FromUTF8(sig.GetError().MakeText(true).c_str()));
}

wxArrayString *CreateArrayString(const ValueList &valList)
{
	wxArrayString *pArray = new wxArrayString();
	AddToArrayString(*pArray, valList);
	return pArray;
}

wxArrayInt *CreateArrayInt(const ValueList &valList)
{
	wxArrayInt *pArray = new wxArrayInt();
	AddToArrayInt(*pArray, valList);
	return pArray;
}

Value ArrayIntToValue(Environment &env, const wxArrayInt &array)
{
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	valList.reserve(array.GetCount());
	for (size_t i = 0; i < array.GetCount(); i++) {
		valList.push_back(Value(array.Item(i)));
	}
	return rtn;
}

Value ArrayStringToValue(Environment &env, const wxArrayString &array)
{
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	valList.reserve(array.GetCount());
	for (size_t i = 0; i < array.GetCount(); i++) {
		valList.push_back(Value(array.Item(i).ToUTF8()));
	}
	return rtn;
}

Value ArrayStringToValue(Environment &env, const wxString *array, int n)
{
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	valList.reserve(n);
	for (int i = 0; i < n; i++) {
		valList.push_back(Value(array[i].ToUTF8()));
	}
	return rtn;
}

void AddToArrayString(wxArrayString &array, const ValueList &valList)
{
	foreach_const (ValueList, pValue, valList) {
		array.Add(wxString::FromUTF8(pValue->GetString()));
	}
}

void AddToArrayInt(wxArrayInt &array, const ValueList &valList)
{
	foreach_const (ValueList, pValue, valList) {
		array.Add(pValue->GetInt());
	}
}

void ConvertToWxImage(Image *pImageGura, wxImage *pImage)
{
	do {
		std::unique_ptr<Image::Scanner> pScanner(pImageGura->CreateScanner());
		unsigned char *pBuffDst = pImage->GetData();
		do {
			unsigned char *pPixel = pScanner->GetPointer();
			*(pBuffDst + 0) = *(pPixel + Image::OffsetR);
			*(pBuffDst + 1) = *(pPixel + Image::OffsetG);
			*(pBuffDst + 2) = *(pPixel + Image::OffsetB);
			pBuffDst += 3;
		} while (pScanner->Next());
	} while (0);
	if (pImageGura->GetFormat() == Image::FORMAT_RGBA) {
		pImage->SetAlpha();
		std::unique_ptr<Image::Scanner> pScanner(pImageGura->CreateScanner());
		unsigned char *pBuffDst = pImage->GetAlpha();
		do {
			unsigned char *pPixel = pScanner->GetPointer();
			*pBuffDst = *(pPixel + Image::OffsetA);
			pBuffDst++;
		} while (pScanner->Next());
	}
}

bool CheckMethodResult(Signal sig)
{
	if (sig.IsSignalled()) {
		SetLogError(sig);
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
		return false;
	}
	return true;
}

bool CheckMethodResult(Signal sig, const Value &rtn,
						ValueType valueType, bool invalidAcceptableFlag)
{
	if (sig.IsSignalled()) {
		SetLogError(sig);
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
		return false;
	}
	if (invalidAcceptableFlag && rtn.IsInvalid()) return true;
	if (!rtn.IsInstanceOf(valueType)) {
		sig.SetError(ERR_ValueError, "unexpected result type");
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
		return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Iterator_NewIds
//-----------------------------------------------------------------------------
Iterator *Iterator_NewIds::Clone() const
{
	return Iterator::Reference(this);
}

Iterator *Iterator_NewIds::GetSource()
{
	return nullptr;
}

bool Iterator_NewIds::DoNext(Environment &env, Signal sig, Value &value)
{
	value = Value(::wxNewId());
	return true;
}

String Iterator_NewIds::ToString() const
{
	String rtn = "<iterator:wx.newids>";
	return rtn;
}

void Iterator_NewIds::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

Gura_EndModuleBody(wx, wx)

Gura_RegisterModule(wx)
