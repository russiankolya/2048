#include "AppGame.h"

#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 400

AppGame::AppGame() {
    ///
    /// Create our main App instance.
    ///
    app_ = App::Create();

    ///
    /// Create a resizable window by passing by OR'ing our window flags with
    /// kWindowFlags_Resizable.
    ///
    window_ = Window::Create(app_->main_monitor(), WINDOW_WIDTH, WINDOW_HEIGHT,
                             false, kWindowFlags_Titled | kWindowFlags_Resizable);

    ///
    /// Create our HTML overlay-- we don't care about its initial size and
    /// position because it'll be calculated when we call OnResize() below.
    ///
    overlay_ = Overlay::Create(window_, window_->width(), window_->height(), 0, 0);

    ///
    /// Load a page into our overlay's View
    ///
    overlay_->view()->LoadURL("file:///app.html");

    ///
    /// Register our AppGame instance as an AppListener so we can handle the
    /// App's OnUpdate event below.
    ///
    app_->set_listener(this);

    ///
    /// Register our AppGame instance as a WindowListener so we can handle the
    /// Window's OnResize event below.
    ///
    window_->set_listener(this);

    ///
    /// Register our AppGame instance as a LoadListener so we can handle the
    /// View's OnFinishLoading and OnDOMReady events below.
    ///
    overlay_->view()->set_load_listener(this);

    ///
    /// Register our AppGame instance as a ViewListener so we can handle the
    /// View's OnChangeCursor and OnChangeTitle events below.
    ///
    overlay_->view()->set_view_listener(this);
}

AppGame::~AppGame() = default;

void AppGame::Run() {
    app_->Run();
}

void AppGame::OnUpdate() {
    ///
    /// This is called repeatedly from the application's update loop.
    ///
    /// You should update any app logic here.
    ///
}

void AppGame::OnClose(ultralight::Window *window) {
    app_->Quit();
}

void AppGame::OnResize(ultralight::Window *window, uint32_t width, uint32_t height) {
    ///
    /// This is called whenever the window changes size (values in pixels).
    ///
    /// We resize our overlay here to take up the entire window.
    ///
    overlay_->Resize(width, height);
}

void AppGame::OnFinishLoading(ultralight::View *caller,
                              uint64_t frame_id,
                              bool is_main_frame,
                              const String &url) {
    ///
    /// This is called when a frame finishes loading on the page.
    ///
}

void AppGame::OnDOMReady(ultralight::View *caller,
                         uint64_t frame_id,
                         bool is_main_frame,
                         const String &url) {
    ///
    /// This is called when a frame's DOM has finished loading on the page.
    ///
    /// This is the best time to setup any JavaScript bindings.
    ///
}

void AppGame::OnChangeCursor(ultralight::View *caller,
                             Cursor cursor) {
    ///
    /// This is called whenever the page requests to change the cursor.
    ///
    /// We update the main window's cursor here.
    ///
    window_->SetCursor(cursor);
}

void AppGame::OnChangeTitle(ultralight::View *caller,
                            const String &title) {
    ///
    /// This is called whenever the page requests to change the title.
    ///
    /// We update the main window's title here.
    ///
    window_->SetTitle(title.utf8().data());
}
