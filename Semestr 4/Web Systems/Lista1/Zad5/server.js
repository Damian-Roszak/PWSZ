const http = require('http');
const path = require('path');
const fs = require('fs');
const adres = require('url');
//const express = require('express');
const hostname = '127.0.0.1';
const port = 80;
let dataETagHashHtml = [];
let dataETagHashJpg = [];
let dataETagHashCss = [];
let mtime = '2022';
let stats = 'plik';

const server = http.createServer((req, res) => {

if(req.method == 'GET'){
    const url = new URL('http://'+req.headers.host+req.url);
   
    let urlPath = url.pathname.split('/').pop();
    let filename = new URL(url).pathname.split('/').pop();

    let ext='';    
        if(urlPath=='/' || urlPath==''){
            urlPath = 'index.html';
            ext='html';
        }
   
       let filename2 = urlPath.split('/').pop();
       stats = fs.statSync(filename2);
       mtime = stats.mtime.toUTCString();
       
       let since = new Date(req.headers['if-modified-since']);
       let last = stats.mtime;
      // console.log('CZAS: '+since.getTime()+' < '+last.getTime());
       
       
    var a = new Date(req.headers['if-modified-since']);
    var b = new Date(mtime);

    var mdSince = Date.UTC(since.getFullYear(), since.getMonth()+1, since.getDate());
    var mdLast = Date.UTC(last.getFullYear(), last.getMonth()+1, last.getDate());

    if (parseFloat(mdSince) <= parseFloat(mdLast)){
      console.log('pCZAS: '+since.toUTCString()+' < '+mtime);  // lt
      console.log('pwiększe jest: '+mtime);
      res.setHeader('last-modified', mtime);
    res.statusCode = 304; res.end();
      
   
	//console.log(JSON.stringify(req.headers)); .getTime()
    //var host = req.headers['last-modified']; 
    //console.log('11111111 host: '+host);
    //console.log('1 mtime '+ mtime);
    
}else{
    //console.log(JSON.stringify(req.headers));
    //console.log(req);
    //console.log(req.headers);
    var host = req.headers['last-modified']; 
    //console.log('22222 host: '+host);
    //console.log('2 since.toUTCString() '+since.toUTCString());


    
    
  //if(req.headers['if-modified-since'] < res.headers['last-modified'])
    try{        
        ext = path.parse(urlPath).ext;
        //console.log('ext ' + ext);
    }
    catch(err){
        res.statusCode = '404';
        res.end('Plik not exists');
        return;
    }
    
    let contentType = 'text/plain';
    
     //mtime = mtime.split();
    //console.log('1 mtime '+ mtime);
    //res.setHeader('last-modified', mtime);  
    //console.log("filename2 res.getHeader['last-modified'] "+res.getHeader['Last-Modified']);
    //console.log("filename2-2 res.getHeader['last-modified'] "+res.getHeader['last-modified']);  
    
    const query = adres.parse(req.url, true).query;
      
        if(query.param === 'random_date'){
            //res.setHeader('last-modified', new Date().toUTCString());
            res.setHeader('last-modified', mtime);
            console.log('1 mtime '+ mtime);
            //res.setHeader('last-modified', new Date('2022-01-01').toUTCString());
        } else{
            res.setHeader('last-modified', new Date('2022-01-01').toUTCString());
            //res.setHeader('last-modified', mtime);
        }
    
        if(ext == '.css'){
            contentType = 'text/css';
            //res.setHeader('Cache-Control', 'public, max-age=12');
            //console.log('css in  ');
            
            if (mtime){
           //     console.log('css in IF ');
           //     console.log(mtime +'==='+ new Date().toUTCString());
            }else{
            //    console.log('css in else ');
            //    console.log(mtime +'!='+ new Date().toUTCString());
            }
           /* fs.readFile(filename2, (err, hash)=>{        
                if(err){
                    res.statusCode = '404';
                    res.end('File nie istnieje'); //'File not exists'
                    return;
                }else{
                            
                    let filename2 = urlPath.split('/').pop();
                    console.log('filename2: ' +filename2);

                    if(filename2 !='') {
                       let stats = fs.statSync(filename2);
                       let mtime = stats.mtime;
                       console.log('mtime '+mtime);
                    }
                }
            })*/
          
            //let query = adres.parse(req.url, true).query;
            //console.log('css');
          // console.log('css: '+query.param);
  
           /* if (mtime === mtime){
                //res.setHeader('last-modified', mtime);
            } else{
               // res.setHeader('last-modified', new Date('2022-01-01').toUTCString());
            }*/

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
                }
            })
            //let query = adres.parse(req.url, true).query;
            //let query = path.parse(urlPath, true).query;
           // console.log('jpeg');
            //console.log('jpg: '+ query);
            
          /*  if (query === dataETagHashJpg[dataETagHashJpg.length -1]){
                res.setHeader('last-modified', new Date().toUTCString());
            } else{
                res.setHeader('last-modified', new Date('2022-01-01').toUTCString());
            }*/
            
            
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
                }
            })
        
            
                //*/
        
            contentType = 'text/html, charset=UTF-8';
            //res.setHeader('Cache-Control', 'public, max-age=2');
            
            //let query = adres.parse(req.url, true).query;
            //console.log('html '+query.param);
            
          /*  if (query.param === dataETagHashHtml[dataETagHashHtml.length -1]){
                res.setHeader('last-modified', new Date().toUTCString());
            } else{
                res.setHeader('last-modified', new Date('2022-01-01').toUTCString());
            }*/

        }else  if(ext == '.bmp'){
            contentType = 'image/bmp';
            //res.setHeader('Cache-Control', 'public, max-age=1');
        }
        
        
        fs.readFile(urlPath, (err, data)=>{        
            if(err){
                console.log('ERRRORR: '+err);
                res.statusCode = '404';
                res.end('File nie istnieje'); //'File not exists'
                return;
            }else{
                res.setHeader('Content-type', contentType);
                res.statusCode = 200;
		res.setHeader('Cache-Control', 'public, max-age=2');
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
console.log(`Serwer działa Z5 ${time.getHours()}:${time.getMinutes()}:${time.getSeconds()} - adres:${hostname} port:${port}`);
})
