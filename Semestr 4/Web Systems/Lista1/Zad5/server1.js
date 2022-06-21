const http = require('http');
const path = require('path');
const fs = require('fs');
const url = require('url');
const hostname = '127.0.0.1';
const port = 80;


const server = http.createServer((req, res) => {
if(req.headers['if-none-match']=='xfdljsfld'){
res.statusCode = 304;
res.end();
} else{
res.statusCode = 200;
res.setHeader('Content-Type', 'text/plain');
res.setHeader('Cache-Control', 'public, max-age=1');
const time = new Date();
const query = url.parse(req.url, true).query;
const odp = `Kiedy to sie przeterminuje?
${time.getMinutes()}:${time.getSeconds()}
parametr: ${query.lol}
`;
console.log(query);
if(query.param === 'random_etag'){
res.setHeader('ETag', Math.random()*100000%10000);
} else{
res.setHeader('ETag', 'xfdljsfld3');
}
res.end(odp);
}
})


server.listen(port, hostname, () => {
console.log(`Serwer działa Z4v1 - adres:${hostname} port:${port}`);
})
