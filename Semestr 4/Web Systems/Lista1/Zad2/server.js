const http = require('http');
const path = require('path');
const fs = require('fs');
const hostname = '127.0.0.1';
const port = 80;

const server = http.createServer((req, res) => {

const url = new URL('http://'+req.headers.host+'/'+req.url);
//const urlPath = '.'+url.pathname+'a';
let urlPath = req.url;
let ext='';

//ext = path.parse(urlPath).ext;



res.statusCode = 302;
res.setHeader('Content-Type', 'text/plain');
if(urlPath == '/a'){
res.setHeader('Location', 'https://www.google.pl');
}
if(urlPath == '/b'){
res.setHeader('Location', 'https://www.youtube.pl');
}
res.end("Zadanie 2");
})


server.listen(port, hostname, () => {
console.log(`Serwer działa - adres:${hostname} port:${port}`);
})
