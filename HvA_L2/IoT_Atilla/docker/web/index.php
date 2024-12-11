<!DOCTYPE html>
<html>
<?php require 'database/database.php';?>

<head>
    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <link rel="stylesheet" href="static/css/event.css" />
    <script src="/static/js/event.js"></script>
    <title>Today's Events: | Atilla Ören</title>
</head>

<body>
    <h2>Today's Events:</h2>

    <form method="post">
    <div class="event-container">
        <table class="event-today">
            <thead>
                <tr>
                    <th>Appointment</th>
                    <th>Date</th>
                    <th>Time</th>
                    <th>Tune</th>
                    <th>Context</th>
                    <th>In the dark</th>
                </tr>
            </thead>
            <tbody>
                <?php
                date_default_timezone_set("Europe/Amsterdam");
                $currentDate = date("Y-m-d");
                $results = selectOnDate($currentDate);
                printTable($results);
                ?>
            </tbody>
        </table>
    </div>
    <div>
        <a id="add-event-button" class="button" href="addEvent.php">Add Event +</a>
    </div>
    <div class="time-display">
        <label for="timer-display">Current date and time: <b id="timer"> </b></label>
    </div>

    <footer class="flex flex-row-reverse p-5">
            <ul id="footer-nav" class="flex flex-wrap items-center mt-3 text-sm text-gray-500">
                <li>
                    <a href="index.html">Home Page</a>
                </li>
                <li>
                    <a href="/phpmyadmin" class="mr-4 hover:underline md:mr-6 ">PhpMyAdmin</a>
                </li>
            </ul>
    </footer>
</body>

</html>
