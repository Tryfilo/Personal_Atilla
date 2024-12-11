<?php

$servername = "mariadb";
$username = "root";
$password = "***";
$dbname = "mydb";

$db = new mysqli($servername, $username, $password, $dbname);

if ($db->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

?>