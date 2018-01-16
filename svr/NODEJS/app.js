var express = require('express');
var path = require('path');
var bodyParser = require('body-parser');

var index = require('./routes/index');
var users = require('./routes/users');

var app = express();


// uncomment after placing your favicon in /public
//app.use(favicon(path.join(__dirname, 'public', 'favicon.ico')));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));



app.post('/Login', function(req, res) {
    var msg = req.body || {};
    console.log('Login incomming msg = ', msg);
    res.send({
        name: 'hello',
        nikeName: 'word'
    });
});

app.post('/initSession', function(req, res) {
    var msg = req.body || {};
    console.log('initSession incomming msg = ', msg);
    res.send({
        name: 'this',
        nikeName: 'test'
    });
});
module.exports = app;