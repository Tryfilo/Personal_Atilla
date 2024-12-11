<?php

require('connect.php');

function printTable($value) {
    foreach ($value as $row) {
        echo '<tr>';
        echo '<td>' . $row['appt_name'] . '</td>';
        echo '<td>' . $row['appt_date'] . '</td>';
        echo '<td>' . $row['appt_time'] . '</td>';
        echo '<td>' . $row['appt_tune'] . '</td>';
        echo '<td>' . $row['appt_context'] . '</td>';
        echo '<td>' . $row['appt_dark'] . '</td>';
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
    $sql = "SELECT * FROM Appointments WHERE appt_date=(?) ORDER BY appt_time ASC";
    $stmt = $db->prepare($sql);
    $stmt->bind_param("s", $date);
    $stmt->execute();
    $result = $stmt->get_result()->fetch_all(MYSQLI_ASSOC);
    return $result;
}

function selectOnDateTime($date, $time) {
    global $db;
    $sql = "SELECT * FROM Appointments WHERE appt_date=(?) AND appt_time=(?)";
    $stmt = $db->prepare($sql);
    $stmt->bind_param("ss", $date, $time);
    $stmt->execute();
    $result = $stmt->get_result()->fetch_all(MYSQLI_ASSOC);
    return $result;
}

function send($appt_name, $appt_date, $appt_time, $appt_context, $appt_tune, $appt_dark){
    global $db;

    if ($db->connect_error) {
        exit();
    } 

    $stmt = $db->prepare("INSERT INTO Appointments (appt_name, appt_date, appt_time, appt_context, appt_tune, appt_dark) VALUES (?, ?, ?, ?, ?, ?)");
    $stmt->bind_param("sssssi", $appt_name, $appt_date, $appt_time, $appt_context, $appt_tune, $appt_dark);
    $stmt->execute();

    $stmt->close();
    $db->close(); 
}

function delete($appt_id) {
    global $db;

    if ($db->connect_error) {
        exit();
    } 

    $stmt = $db->prepare("DELETE FROM Appointments WHERE idappointments VALUES (?)");
    $stmt->bind_param("i", $appt_id);
    $stmt->execute();

    $stmt->close();
    $db->close(); 
}
?>