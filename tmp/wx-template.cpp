#include <wx/wx.h>

class MyFrame : public wxFrame {
public:
	MyFrame(const wxString &title, wxPoint pos = wxDefaultPosition, wxSize size = wxDefaultSize) : wxFrame(NULL, wxID_ANY, title, pos, size) {
	}
};

class MyApp : public wxApp {
public:
	virtual bool OnInit() {
		MyFrame *frame = new MyFrame(wxT("Simple"));
		frame->Show();
		return true;
	}
};

IMPLEMENT_APP(MyApp)
