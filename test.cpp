#include <wx/wx.h>

class App : public wxApp {
public:
	virtual bool OnInit();
};

class Frame : public wxFrame {
private:
	enum {
		ID_BTN_HelloWorld = 1000,
	};
public:
	Frame();
private:
	DECLARE_EVENT_TABLE()
	void OnButton_HelloWorld(wxCommandEvent &event);
};

IMPLEMENT_APP(App)

bool App::OnInit()
{
	Frame *pFrame = new Frame();
	pFrame->Show();
	SetTopWindow(pFrame);
	return true;
}

Frame::Frame() : wxFrame(NULL, wxID_ANY, wxT("HelloWorld"))
{
	new wxButton(this, ID_BTN_HelloWorld, wxT("Hello World"));
}

BEGIN_EVENT_TABLE(Frame, wxFrame)
	EVT_BUTTON(ID_BTN_HelloWorld, Frame::OnButton_HelloWorld)
END_EVENT_TABLE()

void Frame::OnButton_HelloWorld(wxCommandEvent &event)
{
	::wxMessageBox(wxT("Button was pushed"), wxT("HelloWorld"));
}
