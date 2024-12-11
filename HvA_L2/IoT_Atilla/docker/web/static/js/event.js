setInterval(function() {
    var currentTime = new Date ();    
    var currentHours = currentTime.getHours ();   
    var currentMinutes = currentTime.getMinutes ();   
    var currentSeconds = currentTime.getSeconds ();
    var currentDay = currentTime.getDate ();
    var currentMonth = currentTime.getMonth ();
    var currentYear = currentTime.getFullYear ();
    currentMinutes = (currentMinutes < 10 ? "0" : "") + currentMinutes;   
    currentSeconds = (currentSeconds < 10 ? "0" : "") + currentSeconds;
    currentDay = (currentDay < 10 ? "0" : "") + currentDay;
    currentMonth = currentMonth + 1;
    currentMonth = (currentMonth > 12) ? currentMonth - 12 : currentMonth;
    currentMonth = (currentMonth < 10 ? "0" : "") + currentMonth;
    var currentTimeString = currentYear + "-" + currentMonth + "-" + currentDay + " " + currentHours + ":" + currentMinutes + ":" + currentSeconds;
    document.getElementById("timer").innerHTML = currentTimeString;
}, 1000);