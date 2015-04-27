# {{ page.chapter }}. Image Operation

## {{ page.chapter }}.1. Overview

## {{ page.chapter }}.2. Image Instance

An instance of `image` class contains image data and provides functions
such as reading/writing image files, resizing and rotating.

An image instance can be created by a constructor function `image`.
Calling `image` function with an argument that specifies a stream
containing an image data would read that data.
The code below reads a JPEG file and write it in PNG format.

    import(jpeg)
    import(png)
    image('foo.jpg').write('foo.png')

Before `image` function, you have to import a module that can handle an image type.
The following table shows image types and associated module names.

<table>
<tr><th>Image Type</th><th>Module</th><th>Added Methods to <code>image</code></th></tr>
<tr><td>BMP</td><td><code>bmp</code></td><td><code>bmpread</code>, <code>bmpwrite</code></td></tr>
<tr><td>JPEG</td><td><code>jpeg</code></td><td><code>jpegread</code>, <code>jpegwrite</code></td></tr>
<tr><td>GIF</td><td><code>gif</code></td><td><code>gifread</code>, <code>gifwrite</code></td></tr>
<tr><td>PNG</td><td><code>png</code></td><td><code>pngread</code>, <code>pngwrite</code></td></tr>
<tr><td>Microsoft Icon</td><td><code>msico</code></td><td><code>msicoread</code>, <code>msicowrite</code></td></tr>
<tr><td>PPM</td><td><code>ppm</code></td><td><code>ppmread</code>, <code>ppmwrite</code></td></tr>
<tr><td>XPM</td><td><code>xpm</code></td><td><code>xpmdata</code>, <code>xpmwrite</code></td></tr>
<tr><td>TIFF</td><td><code>tiff</code></td><td><code>tiffread</code></td></tr>
</table>

Importing those modules also add methods to `image` class
like `jpeg` module adding `image#jpegread` and `image#jpegwrite`.


## {{ page.chapter }}.3. Format-specific Operations


## {{ page.chapter }}.3.1. JPEG

EXIF


## {{ page.chapter }}.3.2. GIF

Here is a JPEG image file that contains animation frames:
[cat-picture.jpg](../images/cat-picture.jpg).

![cat-picture](../images/cat-picture.jpg)

_(Any size of picture would be acceptable
if only all the frames have the same size and are aligned at regular invervals.)_

The program needs to do the following jobs.

* Reads a JPEG file as a source image.
* Reduces number of colors in the image down to 256 so that it suits GIF specification.
* Creates a GIF content.
* Divides the source image into frames and adds them to the GIF content.
* Writes the GIF content to a file.

And here is the script code:

    import(jpeg)
    import(gif)

    delayTime = 12             // interval time in 1/100 seconds
    [nx, ny] = [6, 2]          // number to divide a source image
    img = image('cat-picture.jpg').reducecolor(`win256)
    [w, h] = [img.width / nx, img.height / ny]
    i = range(nx * ny)
    xs = (i % nx) * w
    ys = int(i / nx) * h
    imgFrames = img.crop(xs, ys, w, h)
    gif.content().addimage(imgFrames, delayTime).write('cat-anim.gif')

It utilizes Implicit Mapping feature to process frame images.
If you're interested in what's running in the code, trace the variable `imgFrames`
about how it's created by `image#crop()` and how it's processed in `gif.content#addimage()`.

![cat-picture](../images/cat-anim.gif) [cat-anim.gif](../images/cat-anim.gif)


## {{ page.chapter }}.4. Cairo

### {{ page.chapter }}.4.1. Simple Example

Here is a simple example using Cairo.

    import(cairo)
    import(show)
    
    img = image(`rgba, 300, 300)
    img.cairo {|cr|
        cr.scale(img.width, img.height)
        cairo.pattern.create_linear(0, 0, 1, 1) {|pat|
            pat.add_color_stop_rgb(0, 0, 0, 0)
            pat.add_color_stop_rgb(1, 1.0, 1.0, 1.0)
            cr.set_source(pat)
        }
        cr.rectangle(0.1, 0.1, 0.8, 0.8)
        cr.fill()
    }
    img.show()


### {{ page.chapter }}.4.2. Render in Exisiting Image

The following is an example that performs reading a JPEG file,
drawing something on it with Cairo APIs and writing it out as a JPEG file.

    import(jpeg)
    import(cairo)
    I(filename:string) = path.join(sys.datadir, 'sample/resource', filename)
    img = image(I('Winter.jpg'))
    img.cairo {|cr|
        repeat (10) {|i|
            [x, y, r] = [128 + 30 * i, 128 + 30 * i, 60 - i * 4]
            pat = cairo.pattern_create_radial(
                x - r / 10, y - r / 6, r / 5, x - r / 6, y - r / 6, r * 1.2)
            pat.add_color_stop_rgba(0, 1, 1, 1, 1)
            pat.add_color_stop_rgba(1, 0, 0, 0, 1)
            cr.set_source(pat)
            cr.arc(x, y, r)
            cr.fill()
        }
    }
    img.write('result.jpg')


### {{ page.chapter }}.4.3. Output Animation GIF File Combining Multiple Image Files

You can create a GIF file that has a dynamically produced image.
The example below shows how to output an animation GIF file that contains
images created by Cairo APIs.

    import(cairo)
    import(gif)
    str = 'Hello'
    img = image(`rgba, 64, 64, `white)
    gifobj = gif.content()
    img.cairo {|cr|
        cr.select_font_face('Georgia', cairo.FONT_SLANT_NORMAL, cairo.FONT_WEIGHT_BOLD)
        cr.set_font_size(64)
        te = cr.text_extents(str)
        cr.set_source_rgb(0.0, 0.0, 0.0)
        for (x in interval(64, -te.width, 30)) {|i|
            img.fill(`white)
            cr.move_to(x, 50)
            cr.show_text(str)
            gifobj.addimage(img.clone(), 10)
        }
    }
    gifobj.write('anim2.gif')


### {{ page.chapter }}.4.4. More Sample Scripts

You can find sample scripts using Cairo on
[GitHub repository](https://github.com/gura-lang/gura/tree/master/sample/cairo/).


## {{ page.chapter }}.5. OpenGL


### {{ page.chapter }}.5.1. Sample Script

Gura supports APIs of OpenGL 1.1.

The following example has been ported from one of the samples in
[http://www.wakayama-u.ac.jp/~tokoi/opengl/libglut.html](http://www.wakayama-u.ac.jp/~tokoi/opengl/libglut.html).

    import(glu) {*}
    import(opengl) {*}
    import(gltester)
    
    vertex = [
        [0, 0, 0], [1, 0, 0], [1, 1, 0], [0, 1, 0]
        [0, 0, 1], [1, 0, 1], [1, 1, 1], [0, 1, 1]
    ]
    
    init(w:number, h:number) = {
        glClearColor(1, 1, 1, 1)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        glEnable(GL_DEPTH_TEST, GL_CULL_FACE)
        glEnable(GL_LIGHTING, GL_LIGHT0, GL_LIGHT1)
        glCullFace(GL_FRONT)
        glViewport(0, 0, w, h)
        glMatrixMode(GL_PROJECTION)
        glLoadIdentity()
        gluPerspective(30, w / h, 1, 100)
    }
    
    display(degree:number) = {
        glMatrixMode(GL_MODELVIEW)
        glLoadIdentity()
        gluLookAt(3, 4, 5, 0, 0, 0, 0, 1, 0)
        glRotated(degree, 1, 1, 0)
        glMaterialfv(GL_FRONT_AND_BACK,
                GL_AMBIENT_AND_DIFFUSE, [0.8, 0.2, 0.2, 1])
        glBegin(GL_QUADS) {
            glNormal3dv([ 0,  0, -1]), glVertex3dv(vertex[0, 1, 2, 3])
            glNormal3dv([ 1,  0,  0]), glVertex3dv(vertex[1, 5, 6, 2])
            glNormal3dv([ 0,  0,  1]), glVertex3dv(vertex[5, 4, 7, 6])
            glNormal3dv([-1,  0,  0]), glVertex3dv(vertex[4, 0, 3, 7])
            glNormal3dv([ 0, -1,  0]), glVertex3dv(vertex[4, 5, 1, 0])
            glNormal3dv([ 0,  1,  0]), glVertex3dv(vertex[3, 2, 6, 7])
        }
    }
    
    degree = 0
    [width, height] = [300, 300]
    gltester.mainloop(width, height, 0, `idle) {
        `onDraw => function {
            init(width, height)
            display(degree)
        }
        `onKeyPoll => %{
            `left => function { degree += 1 }
            `right => function { degree -= 1 }
        }
    }

Execution result.

![gl-cube](../images/gl-cube.png)


### {{ page.chapter }}.5.2. More Sample Scripts

You can find sample scripts using OpenGL on
[GitHub repository](https://github.com/gura-lang/gura/tree/master/sample/opengl/),
which have been ported from
[SGI](http://www.sgi.com/products/software/opengl/examples/samples/).
