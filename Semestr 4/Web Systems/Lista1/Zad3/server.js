const http = require('http');
const path = require('path');
const fs = require('fs');
const hostname = '127.0.0.1';
const port = 80;
//const data = ``;

const server = http.createServer((req, res) => {
res.statusCode = 200;

if(req.method == 'GET'){
    const url = new URL('http://'+req.headers.host+'/'+req.url);
    let urlPath = '.'+url.pathname;
    //let urlPath = url.pathname;
    //let urlPath;
    let ext='';
    
        if(urlPath=='.//'){
            urlPath = 'index.html';
            ext='html';
        }

    
    try{
        
        ext = path.parse(urlPath).ext;
        //res.end("'"+ext+"'");''
        
        /*if(ext==''){
            urlPath = "index.html";
            ext='html';
        }*/
        //res.end("'"+ext+"'");
    }
    catch(err){
        res.statusCode = '404';
        res.end('Plik not exists');
        //res.end(ext+' lol ' +urlPath + ' MMM '+url.pathname); 
        return;
    }
    
    let contentType = 'text/plain';
    
    
        if(ext == '.html'){
            contentType = 'text/html';
        }else if(ext == '.css'){
            contentType = 'text/css';
            res.setHeader('Cache-Control', 'public, max-age=60');
        }else if(ext == '.js'){
            contentType = 'text/javascript';
            res.setHeader('Cache-Control', 'public, max-age=60');
        }else if(ext == '.jpg'){
            contentType = 'image/jpeg';
            res.setHeader('Cache-Control', 'public, max-age=60');
        }else if(ext == '.png'){
            contentType = 'image/png';
            res.setHeader('Cache-Control', 'public, max-age=60');
        }else if(ext == '.bmp'){
            contentType = 'image/bmp';
            res.setHeader('Cache-Control', 'public, max-age=60');
        }

        fs.readFile(urlPath, (err, data)=>{        
            if(err){
                res.statusCode = '404';
                res.end('File nie istnieje'); //'File not exists'
                return;
            }else{
                res.setHeader('Content-type', contentType);
                res.end(data);
            }
        })
    }
//res.end(data);
})


server.listen(port, hostname, () => {
console.log(`Serwer dzia??a zad3 - adres:${hostname} port:${port}`);
})
