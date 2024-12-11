<?php 
require('connect.php');

function send($appt_name, $appt_date, $appt_time, $appt_context, $appt_tune){
    global $db;

    if ($db->connect_error) {
        exit();
    } 

    $stmt = $db->prepare("INSERT INTO Appointments (appt_name, appt_date, appt_time, appt_context, appt_tune) VALUES (?, ?, ?, ?, ?)");
    $stmt->bind_param("sssss", $appt_name, $appt_date, $appt_time, $appt_context, $appt_tune);
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