# Graphical User Interface

## Overview

wxWidgets

Tk

SDL

## wxWidgets


### About wxWidgets

Gura's `wx` module uses libraries of [wxWidgets](https://www.wxwidgets.org/) 3.0.0.


### Simple Example

The code below is the simplest example that shows an empty window.

    import(wx)
    
    MyApp = class(wx.App) {
        OnInit() = {
            frame = MyFrame('Button Test', size => wx.Size(200, 100))
            frame.Show()
            true
        }
    }
    
    MyFrame = class(wx.Frame) {
        __init__(title:string, pos:wx.Point => wx.DefaultPosition,
                size:wx.Size => wx.DefaultSize) = {|nil, wx.ID_ANY, title, pos, size|
            wx.Button(this, wx.ID_ANY, 'Push Me')
        }
    }
    
    wx.IMPLEMENT_APP(MyApp)

An application using wx module must create a class that derives from `wx.App`
and implement `OnInit()` method in it. The method is responsible of
initializing GUI-related resource and creating a main frame.
It should return `true` at the end if no error occurs.

In the above example, the main frame is declared by a class `MyFrame`
that derives from `wx.Frame`, which has a constructor function
including an instance creation of  `wx.Button` contol.
You can create any necessary controls within the constructor.

An application class is realized by calling `wx.IMPLEMENT_APP`,
which runs a main loop in it.


### Event Handling

There are several ways to address event handling.
The first one is to call `wx.Window#Bind` method to the control instance like below.

    import(wx)
    
    MyApp = class(wx.App) {
        OnInit() = {
            frame = MyFrame('Button Test', size => wx.Size(200, 100))
            frame.Show()
            true
        }
    }
    
    MyFrame = class(wx.Frame) {
        __init__(title:string, pos:wx.Point => wx.DefaultPosition,
                size:wx.Size => wx.DefaultSize) = {|nil, wx.ID_ANY, title, pos, size|
            ctrl = wx.Button(this, wx.ID_ANY, 'Push Me')
            ctrl.Bind(wx.EVT_BUTTON) {|event|
                wx.MessageBox('Button was pushed', 'Button Test', wx.OK, this)
            }
        }
    }
    
    wx.IMPLEMENT_APP(MyApp)

You need to specify an event type like `wx.EVT_BUTTON` as an argument
for `wx.Window#Bind` method and also describe a procedure that will be
evaluated when the event occurs as its block.
You may specify a block parameter `event`,
which will take an instance of `wx.CommandEvent` class at the block's evaluation.
Even though the button controls doesn't offer much information with the event instance,
more complicated controls could include more data in it.

Another approach is to assign unique identifiers to controls
and let the parent window to handle events that are sent from them.
The example comes like this:

    import(wx)
    
    MyApp = class(wx.App) {
        OnInit() = {
            frame = MyFrame('Button Test', size => wx.Size(200, 100))
            frame.Show()
            true
        }
    }
    
    MyFrame = class(wx.Frame) {
        [
            ID_BTN_PushMe
        ] = wx.NewIds()
        __init__(title:string, pos:wx.Point => wx.DefaultPosition,
                size:wx.Size => wx.DefaultSize) = {|nil, wx.ID_ANY, title, pos, size|
            ctrl = wx.Button(this, ID_BTN_PushMe, 'Push Me')
            this.Bind(wx.EVT_BUTTON, ID_BTN_PushMe) {|event|
                wx.MessageBox('Button was pushed', 'Button Test', wx.OK, this)
            }
        }
    }
    
    wx.IMPLEMENT_APP(MyApp)

The function `wx.NewIds` generates as many unique identifers as you want.
You can specify one of them to the second argument of a control constructor
and also the second argument of `window#Bind` method.
The identifier is necessary because the parent window must determine
what control has issued the event.


### Layout Management

You can use classes derived from `wx.Sizer` to arrange controls' size and position.

    import(wx)
    
    MyApp = class(wx.App) {
        OnInit() = {
            frame = MyFrame('Button Test', size => wx.Size(200, 200))
            frame.Show()
            true
        }
    }
    
    MyFrame = class(wx.Frame) {
        __init__(title:string, pos:wx.Point => wx.DefaultPosition,
                size:wx.Size => wx.DefaultSize) = {|nil, wx.ID_ANY, title, pos, size|
            vbox = wx.BoxSizer(wx.VERTICAL)
            this.SetSizer(vbox)
            ctrl = wx.Button(this, wx.ID_ANY, 'First')
            vbox.Add(ctrl, wx.SizerFlags(1).Expand())
            ctrl = wx.Button(this, wx.ID_ANY, 'Second')
            vbox.Add(ctrl, wx.SizerFlags(1).Expand())
            ctrl = wx.Button(this, wx.ID_ANY, 'Third')
            vbox.Add(ctrl, wx.SizerFlags(1).Expand())
        }
    }
    
    wx.IMPLEMENT_APP(MyApp)

`wx.BoxSizer` is one the sizer classes that layouts controls in a direction,
either vertical or horizontal.
A top-level sizer must be associated to the window by `window#SetSizer` method.
And then, you can put each control under the sizer's management by calling `wx.Sizer#Add` method.
The method takes a `wx.SizerFlags` instance as its second argument,
with which you can specify how the control's size is arranged.


### More Sample Scripts

You can find sample scripts using wxWidgets on
[GitHub repository](https://github.com/gura-lang/gura/tree/master/sample/wx/).

## Tk

### About Tk

Gura provides modules named `tcl` and `tk` that use [Tcl/Tk](http://www.tcl.tk/) library for GUI programming.


### Simple Example

The following example creates a window that has one Button widget.

    import(tk)
    
    tk.mainwindow() {|mw|
        mw.Button(text => 'Push me') {|w|
            w.pack()
            w.bind(`command) {
                w.tk$MessageBox(title => 'event', message => 'hello')
            }
        }
    }
    tk.mainloop()


### Sample Script

The code below is a drawing program. I have ported it from a sample in
[TkDocs](http://www.tkdocs.com/).

    import(tk)
    
    tk.mainwindow() {|mw|
        mw.Canvas(bg => 'white') {|c|
            c.pack(fill => 'both', expand => true)
            [lastx, lasty] = [0, 0]
            color = 'black'
            c.bind('<1>') {|x:number, y:number|
                [lastx, lasty] = [x, y]
            }
            c.bind('<B1-Motion>') {|x:number, y:number|
                addLine(x, y)
            }
            addLine(x:number, y:number) = {
                extern(lastx, lasty)
                c.Line(lastx, lasty, x, y, fill => color, width => 3)
                [lastx, lasty] = [x, y]
            }
            setColor(colorNew:string) = {
                color:extern = colorNew
            }
            function(color:string, y:number):map {
                c.Rectangle(10, y, 30, y + 20, fill => color) {|item|
                    item.bind('<1>') { setColor(color) }
                }
            }(['red', 'blue', 'black'], 10 + (0..) * 25)
        }
    }
    tk.mainloop()

Sample result.

![tk-demo](../images/tk-demo.png)


### More Sample Scripts

You can find sample scripts using Tk on
[GitHub repository](https://github.com/gura-lang/gura/tree/master/sample/tk/).


## SDL


### About SDL

Gura provides a module named `sdl` that uses [SDL](http://www.libsdl.org/) library.

SDL, Simple DirectMedia Layer, is a cross-platform development library
designed to provide low level access to audio, keyboard, mouse, joystick,
and graphics hardware via OpenGL and Direct3D.


### Simple Example

The following script only shows a blank window by using SDL.

    import(sdl)
    
    sdl.Init(sdl.INIT_EVERYTHING)
    screen = sdl.SetVideoMode(640, 480, 16, sdl.SWSURFACE)
    repeat {
        event = sdl.WaitEvent()
        (event.type == sdl.QUIT) && break
    }

At first, you have to initialize SDL's status by calling `sdl.Init`.
Then, calling `sdl.SetVideoMode` with screen size and depth in its arguments
will show a window.

Unlike other GUI platform, SDL requires you to implement an event handling loop explicitly.
The function `sdl.WaitEvent` would wait until some events come in
and returns an instance of `sdl.Event` class that contains event type and related information.


### More Sample Scripts

You can find sample scripts using SDL on
[GitHub repository](https://github.com/gura-lang/gura/tree/master/sample/sdl/).

