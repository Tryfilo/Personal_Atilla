package com.example.databasetest

import android.content.Intent
import android.os.Bundle
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import androidx.core.content.ContextCompat.startActivity
import com.example.databasetest.databinding.ActivitySecondBinding
import com.google.firebase.database.ktx.database
import com.google.firebase.ktx.Firebase
import java.time.*
import java.time.format.DateTimeFormatter


class SecondActivity : AppCompatActivity() {
    private lateinit var binding: ActivitySecondBinding

    private var timeTest = ""

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivitySecondBinding.inflate(layoutInflater)
        setContentView(binding.root)

        val userId = intent.getStringExtra("user_id")
        val emailId = intent.getStringExtra("email_id")

        binding.btnDataSend.setOnClickListener {
            sendData()
            readData(timeTest)
        }

        binding.btnLogout.setOnClickListener {
            startActivity(Intent(this, MainActivity::class.java))
            finish()
        }
    }

    private fun sendData() {
        val dateTime = LocalDateTime.now()
        val dateTimeNow = dateTime.format((DateTimeFormatter.ofPattern("D-M-Y H:mm:ss")))
        val database = Firebase.database("https://databasetest-a7f1f-default-rtdb.europe-west1.firebasedatabase.app/")
        val myRef = database.getReference(dateTimeNow.toString())
        val humidity = "15%"
        var datetime = dateTimeNow.toString()
        this.timeTest = datetime
        val coordinates = "15.68464 16.1534354"
        val Data = Data(humidity, coordinates, datetime)

        myRef.child(datetime).setValue(Data).addOnSuccessListener {

            Toast.makeText(this, "Data Successfully Send", Toast.LENGTH_SHORT).show()

        }.addOnFailureListener{

            Toast.makeText(
                this,
                "Failed",
                Toast.LENGTH_SHORT
            ).show()

        }

    }

    private fun readData(timeTest: String) {
        val dateTime = LocalDateTime.now()
        val dateTimeNow = dateTime.format((DateTimeFormatter.ofPattern("D-M-Y H:mm:ss")))
        val database = Firebase.database("https://databasetest-a7f1f-default-rtdb.europe-west1.firebasedatabase.app/")
        val myRef = database.getReference(dateTimeNow.toString())
        myRef.child(timeTest).get().addOnSuccessListener {

            if (it.exists()){
                val coordinates = it.child("coordinates").value
                val humidity = it.child("humidity").value
                val time = it.child("dateTime").value
                Toast.makeText(this, "Successfully Read", Toast.LENGTH_SHORT).show()
                binding.tvDataTime.text = ("Date and Time: " + time.toString())
                binding.tvDataHumidity.text = ("Humidity: " + humidity.toString())
                binding.tvDataCoordinates.text = ("Coordinates: " + coordinates.toString())

            } else {

                Toast.makeText(
                    this,
                    "Failed",
                    Toast.LENGTH_SHORT
                ).show()

            }

        }.addOnFailureListener {

            Toast.makeText(
                this,
                "Also Failed but badly",
                Toast.LENGTH_SHORT
            ).show()

        }
    }
}