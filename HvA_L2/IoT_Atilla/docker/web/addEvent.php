<!DOCTYPE html>
<html>
<?php require('database/database.php') ?>

<head>
    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <link rel="stylesheet" href="static/css/event.css" />
    <script src="/static/js/event.js"></script>
    <title>Add Event</title>
</head>

<body>
    <h2 id="event-header">Add Event +</h2>
    <!-- <form action="database/dataSend.php" method="post"> -->
    <form method="post">
    <div class="event-container">
        <label for="appt">Appointment name:</label>
        <a class="button" id="return" href="index.php" >Return to previous page</a><br>
        <input class="inputs" type="text" id="appt_name" name="appt_name"><br><br>
        <label for="date">Date:</label><br>
        <input class="inputs" type="date" id="appt_date" name="appt_date"><br><br>
        <label for="time">Select a time:</label><br>
        <input class="inputs" type="time" id="appt_time" name="appt_time"><br><br>
        <label for="context">Extra context:</label><br>
        <input class="inputs" type="text" id="appt_context" name="appt_context"><br><br>
        <label for="tune">Tune:</label><br>
        <select name="appt_tune" id="appt_tune">
            <option value="Standard">Standard</option>
            <option value="Nokia">Nokia</option>
            <option value="Harry Potter">Harry Potter</option>
            <option value="Doom">Doom</option>
            <option value="Darth Vader">Darth Vader</option>
            <option value="Fur Elise">Fur Elise</option>
        </select><br>
        <label for="dark">Alarm turns on in the dark:</label><br>
        <select name="appt_dark" id="appt_dark">
            <option value="0">Doesn't turn on</option>
            <option value="1">Does turn on</option>
        </select><br><br>
        <input class="button" type="submit" value="Add Event +" name="add_event">
        <?php
            if(isset($_POST['add_event'])) {
                $appt_name = $_POST["appt_name"];
                $appt_date = $_POST["appt_date"];
                $appt_time = $_POST["appt_time"];
                $appt_context = $_POST["appt_context"]; 
                $appt_tune = $_POST["appt_tune"];
                $appt_dark = $_POST["appt_dark"];
                send($appt_name, $appt_date, $appt_time, $appt_context, $appt_tune, $appt_dark);
            }
        ?>
    </div><br><br>

    <div class="time-display">
        <label for="timer-display">Current time and date: <b id="timer"> </b></label>
    </div>
</body>

</html>