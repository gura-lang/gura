# {{ page.chapter }}. Network Operation

## {{ page.chapter }}.1. Overview

`curl` module

`http` module

client-side and server-side


## {{ page.chapter }}.2. Client-side Operation

You can download files via HTTP protocol using a generic stream-copy function copy.
Below is the example.

    import(http)
    copy('http://sourceforge.jp/', 'sf.html')

If you want to use a proxy server, you need to specify a server setting
using http.addproxy like follows.

    import(http)
    http.addproxy('xx.xx.xx.xx', 8080, 'username', 'password')
    copy('http://sourceforge.jp/', 'sf.html')


## {{ page.chapter }}.3. Server-side Operation

Simple Example:

    import(http)
    
    text = R'''
    <html>
    <body>
    Welcome to Gura server
    </body>
    </html>
    '''
    
    http.server(port => 8000).wait {|req|
        println(req.uri)
        req.response('200', nil, text.encode('utf-8'),
            'Cache-Control' => 'private'
            'Server'        => 'Gura_HTTP_Server'
            'Connection'    => 'Keep-Alive'
            'Content-Type'  => 'text/html')
    }

The following example works as a HTTP server, which generates a graph
that shows values in SQLite3 database
[temperature.sqlite3](https://github.com/gura-lang/gura/blob/master/sample/resource/temperature.sqlite3?raw=true).

    import(re)
    import(cairo)
    import(http)
    import(png)
    import(sqlite3)
    
    makeGraph(iSites[]:number) = {
        Item = struct(day:number, temps*:number)
        tbl = Item * sqlite3.db('temperature.sqlite3').query('select * from sites')
        img = image(`rgba, 320, 320, `white)
        [wdAxis, htAxis] = [img.width * 0.9, img.height * 0.9]
        [xAxis, yAxis] = [(img.width - wdAxis) / 2, (img.height - htAxis) / 2]
        [dayMax, dayMin] = [tbl:*day.max(), tbl:*day.min()]
        dayRange = dayMax - dayMin
        [tempMax, tempMin] = [tbl:*temps:*max().max(), tbl:*temps:*min().min()]
        tempRange = tempMax - tempMin
        calcX(day) = xAxis + (day - dayMin) * wdAxis / dayRange
        calcY(temp) = yAxis + htAxis - (temp - tempMin) * htAxis / tempRange
        img.cairo {|cr|
            cr.set_line_width(img.height / 300)
            cr.rectangle(xAxis, yAxis, wdAxis, htAxis).stroke()
            cr.save {
                cr.set_dash([img.height / 200, img.height / 200], 0)
                cr.move_to(xAxis, calcY(0)).line_to(xAxis + wdAxis, calcY(0))
                cr.stroke()
            }
            for (iSite in iSites) {
                func = cr.move_to
                for (item in tbl) {
                    func(calcX(item.day), calcY(item.temps[iSite]))
                    func = cr.line_to
                }
                cr.stroke()
            }
        }
        img
    }
    http.server(port => 80).wait {|req|
        iSites = [0]
    	query = req.query
        if (query.haskey('site')) {
            iSites = tonumber(query['site'].split(','):list)
        }
        buff = binary()
        makeGraph(iSites).pngwrite(buff)
        req.response('200', nil, buff,
            'Server' => 'Gura_HTTP_Server' 'Connection' => 'close')
    }

After the script runs, it waits for HTTP requests.
Launch a Web browser and access to it as like http://localhost/?site=0,1.
If you try it on Linux, you have to run the script as a root user or
replace the port number with one larger than or equal to 1024.
