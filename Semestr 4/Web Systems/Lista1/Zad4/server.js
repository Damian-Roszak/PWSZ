const http = require('http');
const path = require('path');
const fs = require('fs');
const adres = require('url');
const hostname = '127.0.0.1';
const port = 80;
let dataETagHashHtml = [];
let dataETagHashJpg = [];
let dataETagHashCss = [];

const server = http.createServer((req, res) => {


if(req.headers['if-none-match']==dataETagHashHtml[dataETagHashHtml.length -1]){
//req.method == 'POST'
//req.headers['if-none-match']=='xfdljsfld'
//req.headers['if-none-match']==dataETagHash[dataETagHash.length -1]
    res.statusCode = 304;
    res.end('Plik nie zmodyfikowany');
    
}else if(req.headers['if-none-match']==dataETagHashCss[dataETagHashCss.length -1]){
    res.statusCode = 304;
    res.end('Plik nie zmodyfikowany');
    
}else if(req.headers['if-none-match']==dataETagHashJpg[dataETagHashJpg.length -1]){
    res.statusCode = 304;
    res.end('Plik nie zmodyfikowany');
}

else{
res.statusCode = 200;
res.setHeader('Cache-Control', 'public, max-age=2');


if(req.method == 'GET'){
    const url = new URL('http://'+req.headers.host+'/'+req.url);
    let urlPath = '.'+url.pathname;

    let ext='';    
        if(urlPath=='.//'){
            urlPath = 'index.html';
            ext='html';
        }

    try{        
        ext = path.parse(urlPath).ext;
    }
    catch(err){
        res.statusCode = '404';
        res.end('Plik not exists');
        return;
    }
    
    let contentType = 'text/plain';
    
    
        if(ext == '.css'){
            contentType = 'text/css';
            //res.setHeader('Cache-Control', 'public, max-age=12');
            
            fs.readFile(urlPath, (err, hash)=>{        
                if(err){
                    res.statusCode = '404';
                    res.end('File nie istnieje'); //'File not exists'
                    return;
                }else{
                    var string = hash;
                    var crypto = require('crypto');
                    var hash = crypto.createHash('md5').update(string).digest('hex');
                    console.log('css hash: '+hash);
                    res.setHeader('ETag', hash);
                    dataETagHashCss.push(hash);
                }
            })
          
            let query = adres.parse(req.url, true).query;
            console.log('css');
            console.log('css: '+query.param);
  
            if (query.param === dataETagHashCss[dataETagHashCss.length -1]){
                res.setHeader('ETag', Math.random()*12345%10000);
            }else{
                res.setHeader('ETag', 'xfdljsfld');
            }

        }else if(ext == '.js'){
            contentType = 'text/javascript';
            //res.setHeader('Cache-Control', 'public, max-age=13');
            
        }else if(ext == '.jpg'){
            contentType = 'image/jpeg';
            //res.setHeader('Cache-Control', 'public, max-age=14');
            
            fs.readFile(urlPath, (err, hash)=>{        
                if(err){
                    res.statusCode = '404';
                    res.end('File nie istnieje'); //'File not exists'
                    return;
                }else{
                    var string = hash;
                    var crypto = require('crypto');
                    var hash = crypto.createHash('md5').update(string).digest('hex');
                    console.log('jpg hash: '+hash);
                    res.setHeader('ETag', hash);
                    dataETagHashJpg.push(hash);
                }
            })
            //let query = adres.parse(req.url, true).query;
            let query = path.parse(urlPath, true).query;
            console.log('jpeg');
            console.log('jpg: '+ query);
            
            if (query === dataETagHashJpg[dataETagHashJpg.length -1]){
                res.setHeader('ETag', Math.random()*12345%10000);
            }else{
                res.setHeader('ETag', 'xfdljsfld');
            }
        }else if(ext == '.png'){
            contentType = 'image/png';
            //res.setHeader('Cache-Control', 'public, max-age=15');
            
        }else if(ext == '.html'){//*
            
            fs.readFile(urlPath, (err, hash)=>{        
                if(err){
                    res.statusCode = '404';
                    res.end('File nie istnieje'); //'File not exists'
                    return;
                }else{
                    var string = hash;
                    var crypto = require('crypto');
                    var hash = crypto.createHash('md5').update(string).digest('hex');
                    console.log('html hash: '+hash);
                    res.setHeader('ETag', hash);
                    dataETagHashHtml.push(hash);
                }
            })
                //*/
        
            contentType = 'text/html, charset=UTF-8';
            //res.setHeader('Cache-Control', 'public, max-age=2');
            
            let query = adres.parse(req.url, true).query;
            console.log('html: '+query.param);
            
            if (query.param === dataETagHashHtml[dataETagHashHtml.length -1]){
                res.setHeader('ETag', Math.random()*12345%10000);
            }else{
                res.setHeader('ETag', 'xfdljsfld');
            }
            

        }else  if(ext == '.bmp'){
            contentType = 'image/bmp';
            //res.setHeader('Cache-Control', 'public, max-age=1');
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
//res.end (odp);
}
})


server.listen(port, hostname, () => {
const time = new Date();
console.log(`Serwer dzia??a Z4 ${time.getHours()}:${time.getMinutes()}:${time.getSeconds()} - adres:${hostname} port:${port}`);
})
