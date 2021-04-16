/*var mysql = require('mysql');
var http = require('http');
var url = require('url');
var nodemailer = require('nodemailer');



var con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "root",
    database: "mydb"
});

http.createServer(function (req, res) {
    res.writeHead(200, { 'Content-Type': 'text/html' });
    var q = url.parse(req.url, true).query;
    con.connect(function (err) {
        if (err) throw err;
        console.log("Connected!");
        var sql = "INSERT INTO player (playeroneun,playertwoun,playeroneemail,playertwoemail) VALUES ('" + q.playeroneun + "', '" + q.playertwoun + "','" + q.playeroneemail + "','" + q.playertwoemail + "')";
        con.query(sql, function (err, result) {
            if (err) throw err;
            console.log("1 record inserted");
        });
    });
    var client = nodemailer.createClient({
        service: 'gmail',
        auth: {
            user: 'arpit@gmail.com',
            pass: '12345678'
        }
    });

    var mailInfos = {
        from: 'arpit@gmail.com',
        to: q.email,
        subject: 'Email by Car Rental',
        text: 'Your lpgin is confirmed'
    };

    client.sendMail(mailInfos, function (error, info) {
        if (error) {
            console.log(error);
        } else {
            console.log('Email sent: ' + info.response);
        }
    });
}).listen(8080);*/

var express = require('express');
var app = express();
var bodyParser = require('body-parser');
// Create application/x-www-form-urlencoded parser  
var urlencodedParser = bodyParser.urlencoded({ extended: false })
app.use(express.static('public'));
app.get('/', function (req, res) {
    res.sendFile("C:/Users/apatel4/Downloads/tic-tac-toe/index.html");
})
app.post('/controller.js', urlencodedParser, function (req, res) {
    // Prepare output in JSON format  
    response = {
        first_name: req.body.playeroneun,
        last_name: req.body.playertwoun
    };
    console.log(response);
    res.end(JSON.stringify(response));
})
var server = app.listen(8080, function () {
    var host = server.address().address
    var port = server.address().port
    console.log("Example app listening at http://%s:%s", host, port)
})