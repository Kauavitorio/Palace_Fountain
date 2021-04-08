    SoftwareSerial mySerial(10, 11); // RX, TX  
    String command = ""; // Stores response of bluetooth device  
            // which simply allows \n between each  
            // response.  
    
    //  Commands for config bluetooth
    //  Read device output if available.  
    if (mySerial.available()) {  
        while(mySerial.available()) 
        { // While there is more to be read, keep reading.  
            command += (char)mySerial.read();  
        }  
        Serial.println(command);  
        command = ""; // No repeats  
    }  

  // Read user input if available.  
    if (Serial.available())
    {  
        delay(10); // The DELAY!  
        mySerial.write(Serial.read());  
    }

/*
* AT
* AT+NAME:****
* AT+PSWD:""
*/