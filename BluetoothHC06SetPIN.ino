 /*This sketch Configures the name and baud rate of an HC 06 Bluetooth module */
char message1[10];//need length of chars being read +1 for null character

void setup() {
  // set baud rate then delay to give user time to open serial monitor
  Serial.begin(9600);
  delay(1000);
  //Send command to set name of HC06 module, with the below command name will change to "forcetronics"
  Serial.print("AT+PIN1234");
  delay(1000); //HC06 requires 500 msec for reply
  int count = 0; //declare and intialize count 
  while(1) { //loop until OKsetname is read and cleared from buffer
    if(Serial.available()) {
        message1[count] = Serial.read(); //read in char
        count++; 
        if(count == 9) break; //after we get all 9 char break out of loop
    }
    delay(10);
  }

  //print out each message to make sure it worked
  Serial.println("");
  Serial.println(message1);

}

void loop() {
 //do nothing
  delay(50);
}
