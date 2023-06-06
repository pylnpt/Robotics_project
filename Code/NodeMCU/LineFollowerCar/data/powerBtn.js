const sendValue = (value) =>  {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/setAnalogValue?value=" + value, true);
    xhttp.send();
}

function sendValueB(value) {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/setAnalogValue?value=" + value, true);
    xhttp.send();
}