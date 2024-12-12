package com.example.databasetest

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.content.Intent
import android.text.TextUtils
import android.widget.Toast
import com.example.databasetest.databinding.ActivityRegisterBinding

import com.google.android.gms.tasks.OnCompleteListener

import com.google.firebase.auth.AuthResult
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.auth.FirebaseUser
import com.google.firebase.database.ktx.database
import com.google.firebase.ktx.Firebase


class RegisterActivity : AppCompatActivity() {

    private lateinit var binding: ActivityRegisterBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        val database =
            Firebase.database("https://databasetest-a7f1f-default-rtdb.europe-west1.firebasedatabase.app/")

        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_register)
        binding = ActivityRegisterBinding.inflate(layoutInflater)

        binding.btnRegister.setOnClickListener {

            val username = binding.etUsername.text.toString()
            val password = binding.etPassword.text.toString()

            val myRef = database.getReference("Users")
            val user = User(username, password)

            myRef.child(username).get().addOnSuccessListener {

                if (it.exists()) {

                    Toast.makeText(
                        this,
                        "This username is already being used.",
                        Toast.LENGTH_SHORT
                    ).show()

                } else {

                    myRef.child(username).setValue(user).addOnSuccessListener {
                        binding.etUsername.text.clear()
                        binding.etPassword.text.clear()

                        Toast.makeText(
                            this,
                            "Successfully registered.",
                            Toast.LENGTH_SHORT
                        ).show()

                        val intent = Intent(this, SecondActivity::class.java)
                        startActivity(intent)

                    }.addOnFailureListener {

                        Toast.makeText(
                            this,
                            "Register failed",
                            Toast.LENGTH_SHORT
                        ).show()

                    }
                }
            }
        }
    }
}