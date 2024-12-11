<?php

require 'database.php';
date_default_timezone_set("Europe/Amsterdam");
$currentDate = date("Y-m-d");
$currentTime = date("H:i:00");
$results = selectOnDateTime($currentDate, $currentTime);
$json = json_encode($results);

echo "<pre>" . print_r($json) . "</pre>";

?>