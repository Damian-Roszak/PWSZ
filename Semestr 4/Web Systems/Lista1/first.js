const http = require('http');
const hostname = '127.0.0.1';
const port = 80;

const server = http.createServer((req, res) => {
res.statusCode = 200;
res.setHeader('Content-Type', 'text/plain');
res.end('Wyklad PWSZ - przyklad');
})


server.listen(port, hostname, () => {
console.log(`Serwer działa - adres:${hostname} port:${port}`);
})
