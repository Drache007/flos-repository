import express from 'express';
import fs from'node:fs';
import https from 'node:https';

const app = express()

app.use(express.static('/home/florian/flos-repository/web-entwicklung/mtg-mini-website'));

app.get('/', (req, res) => {
  res.sendFile('/home/florian/flos-repository/web-entwicklung/mtg-mini-website/index.html');
})

const options = {
	cert: fs.readFileSync('flo.crt'),
	key: fs.readFileSync('flo.pem'),
	ciphers: "TLS_AES_128_GCM_SHA256"
}

const server = https.createServer(options, app).listen(4000);
console.log('Web-Server gestartet: https://localhost:4000');