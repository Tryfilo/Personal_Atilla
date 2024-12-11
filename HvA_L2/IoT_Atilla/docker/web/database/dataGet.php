<?php

require('connect.php');
require('dataSend.php');

function printTable($value) {
    $delete_id = array();
    foreach ($value as $row) {
        echo '<tr>';
        echo '<td>' . $row['appt_name'] . '</td>';
        echo '<td>' . $row['appt_date'] . '</td>';
        echo '<td>' . $row['appt_time'] . '</td>';
        echo '<td>' . $row['appt_tune'] . '</td>';
        echo '<td>' . $row['appt_context'] . '</td>';
        echo '<td><input type="submit" name="action" value="Delete"/></td>';
        echo '<input type="hidden" name="id" value="' . $row['idappointments'] . '"/>';
        echo '</tr>';
    }
}

function selectAll() {
    global $db;
    $sql = "SELECT * FROM Appointments";
    // Check connection
    if ($db->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }
    //appt_name, appt_date, appt_time, appt_context, appt_tune
    $stmt = $db->prepare($sql);
    $stmt->execute();
    $result = $stmt->get_result()->fetch_all(MYSQLI_ASSOC);

    return $result;
}

function selectOnDate($date) {
    global $db;
    $sql = "SELECT * FROM Appointments WHERE appt_date=(?)";
    $stmt = $db->prepare($sql);
    $stmt->bind_param("s", $date);
    $stmt->execute();
    $result = $stmt->get_result()->fetch_all(MYSQLI_ASSOC);
    return $result;
}

?>