const socket = new WebSocket ('***');
//const mariadb = require('mariadb');

/*
const pool = mariadb.createPool({
        host: '',
        user: 'root',
        password: '',
        database: ''
})
*/

socket.onopen = function (event) {
        console.log("Socket is alive");
        // alert("Socket is alive");
}

socket.onmessage = function (event) {
        /*
        console.log(`Message from server ${event}`);
        alert(`Message from server  ${event}`);
        */
}

/** 
*       addEventListener listens to whatever is being specified in the parameter.
*       "keydown" in this case is whenever a key is being pressed.
*       event.repeat checks if the key is being held down and it is being used to prevent spamming messages.
*/
document.addEventListener("keydown", event => {
        console.log(`Key down = ${event.key}`);
        if (!event.repeat) {
                switch(event.key){
                        case "w": 
                                message("Forward");
                                printLog("Start Forward");
                                break;
                        case "a":
                                message("Left");
                                printLog("Start Left");
                                break;
                        case "s":
                                message("Back");
                                printLog("Start Back");
                                break;
                        case "d":
                                message("Right");
                                printLog("Start Right");
                                break;
                        case "q":
                                message("Break");
                                printLog("Start Break");
                                break;
                        case "-":
                                clearLog();
                                break;
                }
        } else {
                switch(event.key){
                        case "w": 
                                message("Forward");
                                break;
                        case "a":
                                message("Left");
                                break;
                        case "s":
                                message("Back");
                                break;
                        case "d":
                                message("Right");
                                break;
                        case "q":
                                message("Break");
                                break;
                        case "-":
                                clearLog();
                                break;
                }
        }
});

/** 
*       addEventListener listens to whatever is being specified in the parameter.
*       "keyup" in this case is whenever a key is being released to show when you stop sending messages.
*/
document.addEventListener("keyup", event => {
        console.log(`Key up = ${event.key}`);
        switch(event.key){
                case "w": 
                        printLog("Stop Forward");
                        break;
                case "a":
                        printLog("Stop Left");
                        break;
                case "s":
                        printLog("Stop Back");
                        break;
                case "d":
                        printLog("Stop Right");
                        break;
        }
});

function message(wsMessage) {
        socket.send(wsMessage);
        console.log(`Message send = ${wsMessage}`);
        // alert(wsMessage);
}
/**
 * printLog is a function of printing whatever is being send/pressed.
 * @param {*} value is the message that is being printed in the logging div on the index.html page.
 */
function printLog(value) {
        const elTableData = document.getElementById("event-table-data");
        const datetime = getDateTime();  
        elTableData.innerHTML += `<tr><td><b>${value} </b><br><i> ${datetime}</i></td></tr>`;
}

/**
 * clearLog is a function of clearing the entire logging div.
 */
function clearLog() {
        const elTableData = document.getElementById("event-table-data");
        elTableData.innerHTML = '';
}

/**
 * printSensorData is a function to eventually print the sensordata, it is not being used now.
 * @param {*} sensor is the sensor.
 * @param {*} sensorValue is the value of the sensor data.
 */
function printSensorData (sensor, sensorValue) {
        document.getElementById(sensor).innerHTML = sensorValue;
}

function getData() {
        /*
        socket.addEventListener("message", (event) => {
                alert("Message from server", event.data);
        });
        */
}

/**
 * getDateTime gets current date and time whenever it gets called by getting all of the data individually.
 * @returns the datetime value formatted in hh:mm:ss dd-mm-yyyy.
 */
function getDateTime() {
        const today = new Date();
        const hour = String(today.getHours()).padStart(2, '0');
        const minute = String(today.getMinutes()).padStart(2, '0');
        const second = String(today.getSeconds()).padStart(2, '0');
        const day = String(today.getDate()).padStart(2, '0');
        const month = String((today.getMonth()+1)).padStart(2, '0'); 
        const year = today.getFullYear();
        const time = hour + ":" + minute + ":" + second;
        const date = day + '-' + month + '-' + year;
        const datetime = time + ' ' + date;
        return datetime;
}

