const http = require('http');
const path = require('path');
const fs = require('fs');
const url = require('url');
const hostname = '127.0.0.1';
const port = 80;

const server = http.createServer((req, res) => {
if(req.headers['if-modified-since']== res.getHeader['last-modified']){ //new Date('2022-01-01').toUTCString()){
console.log('1 res.getHeader[last-modified] ' +res.getHeader['last-modified']);
console.log('1 res.getHeader[if-modified-since] ' +res.getHeader['if-modified-since']);
    res.statusCode = 304; res.end();
} else{
    res.statusCode = 200;
    res.setHeader('Content-Type', 'text/plain');
    res.setHeader('Cache-Control', 'public, max-age=1');
    
    const time = new Date();
    const query = url.parse(req.url, true).query;
    const odp = `Kiedy to sie przeterminuje? ${time.getMinutes()}:${time.getSeconds()} parametr: ${query.param}`;
    
    //res.setHeader('last-modified', new Date().toUTCString());
    if(query.param === 'random_date'){
        res.setHeader('last-modified', new Date().toUTCString());
        let data = res.getHeader['last-modified'];
        console.log("if data " +data);
        console.log("if res.header['last-modified'] " +res.getHeader['last-modified']);

    } else{
        res.setHeader('last-modified', new Date('2022-01-01').toUTCString());
        
        console.log("else res.header['last-modified'] " +res.getHeader['last-modified']);

    }
    console.log("res.header['last-modified'] " +res.getHeader['last-modified']);
res.end(odp);
}
})

server.listen(port, hostname, () => {
const time = new Date();
console.log(`Serwer działa LastMod.js ${time.getHours()}:${time.getMinutes()}:${time.getSeconds()} - adres:${hostname} port:${port}`);
})
