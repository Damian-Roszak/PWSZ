const http = require('http');
const path = require('path');
const fs = require('fs');
const adres = require('url');
//const express = require('express');
var querystring = require('querystring');

const hostname = '127.0.0.1';
const port = 80;
let dataETagHashHtml = [];
let dataETagHashJpg = [];
let dataETagHashCss = [];
let mtime = new Date();

const server = http.createServer((req, res) => {
//console.log('start');
//if(res.headers['last-modified'] !== 'undefined' && res.headers['last-modified'] !== null)
if(req.headers['if-modified-since'] < res.headers['last-modified']){
//req.headers['if-modified-since']===res.headers['last-modified']
//req.headers['if-modified-since'] < res.headers['last-modified']
//req.method == 'POST'
//req.headers['if-none-match']=='xfdljsfld'
//req.headers['if-none-match']==dataETagHash[dataETagHash.length -1]
    res.statusCode = 304;
    res.end('Plik nie zmodyfikowany'); 
    console.log(new Date());
}
else{
//console.log('else');
//console.log(new Date().toUTCString());

res.statusCode = 200;
res.setHeader('Cache-Control', 'public, max-age=2');


if(req.method == 'GET'){
    const url = new URL('http://'+req.headers.host+req.url);
    //let urlPath = url.pathname;
    
    
let urlPath = url.pathname.split('/').pop();
//console.log('0 urlPath: ' +urlPath);
/*
console.log('req.url ' + req.url);
console.log('url.pathname ' + url.pathname);
let query = adres.parse(req.url, true).pathname;
console.log('adres.query.pathname '+query.pathname);
let query1 = path.parse(urlPath).query;
console.log('query1.query.param '+query1);
//let query2 = url.parse(req.url, true).query;
//console.log('query2.query.param '+query.param);
    //let up = path.parse(urlPath).query;
    //console.log('up ' + up);
let parsed= adres.parse(req.url);
*/


let filename = new URL(url).pathname.split('/').pop();
//console.log('filename: ' +filename);
 

    let ext='';    
        if(urlPath=='/' || urlPath==''){
            urlPath = 'index.html';
            ext='html';
        }
   
let filename2 = urlPath.split('/').pop();
//console.log('1 filename2: ' +filename2);

    //if(filename2 !='') {
      let stats = fs.statSync(filename2);
       mtime = stats.mtime;
       //var date = fs.statSync(filename2).mtime.toUTCString();
       //mtime = mtime.split();
       console.log('1 mtime '+ mtime.toUTCString());
       var q = querystring.stringify('year=2017&month=february');
console.log(q.year);

       res.setHeader('last-modified', q);  
      //console.log("filename2 res.getHeader['last-modified'] "+res.getHeader['Last-Modified']);
      console.log("filename2 res.getHeader['last-modified'] "+res.getHeader['last-modified']);    
     // }
    
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
    
    
        if(ext == '.css'){
            contentType = 'text/css';
            //res.setHeader('Cache-Control', 'public, max-age=12');
            //console.log('css in  ');
            if (mtime < new Date().toUTCString()){
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
