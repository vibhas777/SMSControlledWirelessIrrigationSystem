char inchar; //Will hold the incoming character from the Serial Port.

int sensorPin = 0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int sensor1 = 0;
int relay3 = 8;
int relay4 = 9;
int relay1=6;
int relay2=7;

void setup()
{
	// prepare the digital output pins
 
	Serial.begin(9600);
	pinMode(relay1, OUTPUT);
	pinMode(relay2, OUTPUT);
	pinMode(relay3, OUTPUT);
	pinMode(relay4, OUTPUT);
	digitalWrite(9,HIGH);
	digitalWrite(8,HIGH);
	digitalWrite(7,HIGH);
	digitalWrite(6,HIGH);
	Serial.print("pin state low\n");
	delay(3000); // give time for GSM module to register on network.
	Serial.println("AT+CMGF=1"); // set SMS mode to text
	delay(200);
	Serial.println("AT+CNMI=2,2,0,0,0"); // set module to send SMS data to serial out upon receipt 
	delay(200);
 }
 
 void loop() 
 {
	//If #a1b1c1d1 comes as sms, all led's should light up.
	if(Serial.available() >0)
	{
		inchar=Serial.read(); 
		if (inchar=='#')
		{
			delay(10);
            inchar=Serial.read(); 
            //first led
            if (inchar=='a')//closed
            {
               delay(10);
               inchar=Serial.read();
               if (inchar=='0')//closed
               {
					digitalWrite(relay1,HIGH);
                    Serial.print("Relay 1 LOW\n");
                    // delay(1000);
					//  Serial.println("AT+CMGD=1,4");                   //Delete all message
                    delay(500);
                    Serial.println("AT+CMGF=1");
                    delay(500);
                    Serial.println("AT+CMGS=\"+919603740090\"");//Change the receiver phone number
                    delay(500);
                    Serial.print("a1 relay OFF");    //the message you want to send
                    delay(500);
                    Serial.write(26);
                    delay(500);
				}
				else if (inchar=='1')
                {
					digitalWrite(relay1, LOW);
                    Serial.print("Relay 1 HIGH\n");
                    // delay(1000);
                    //    Serial.println("AT+CMGD=1,4");                   //Delete all message
                    delay(500);
                    Serial.println("AT+CMGF=1");
                    delay(500);
                    Serial.println("AT+CMGS=\"+919603740090\"");//Change the receiver phone number
                    delay(500);
                    Serial.print("a1 relay ON");    //the message you want to send
                    delay(500);
                    Serial.write(26);
                    delay(500);
                }
                  
				delay(10);
				inchar=Serial.read();
			}
			else if (inchar=='b')//closed
			{
				delay(10);
				inchar=Serial.read();
				if (inchar=='0')//closed
				{
					digitalWrite(relay2,HIGH);
					Serial.print("Relay 2 LOW\n");
					// delay(500);
					//  Serial.println("AT+CMGD=1,4");                   //Delete all message
					delay(500);
					Serial.println("AT+CMGF=1");
					delay(500);
					Serial.println("AT+CMGS=\"+919603740090\"");//Change the receiver phone number
					delay(500);
					Serial.print("b2 relay OFF");    //the message you want to send
					delay(500);
					Serial.write(26);
					delay(500);
                }
                else if (inchar=='1')
                {
					digitalWrite(relay2, LOW);
                    Serial.print("Relay 1 HIGH\n");
                    // delay(1000);
                    //    Serial.println("AT+CMGD=1,4");                   //Delete all message
                    delay(500);
                    Serial.println("AT+CMGF=1");
                    delay(500);
                    Serial.println("AT+CMGS=\"+919603740090\"");//Change the receiver phone number
                    delay(500);
                    Serial.print("b2 relay ON");    //the message you want to send
                    delay(500);
                    Serial.write(26);
                    delay(500);
                }
				delay(10);
				inchar=Serial.read();
            }      
			  
			else if (inchar=='c')//closed
            {
				delay(10);
				inchar=Serial.read();
				if (inchar=='0')//closed
                {
					digitalWrite(relay3,HIGH);
                    Serial.print("Relay 3 LOW\n");
                    // delay(500);
                    //  Serial.println("AT+CMGD=1,4");                   //Delete all message
                    delay(500);
                    Serial.println("AT+CMGF=1");
                    delay(500);
                    Serial.println("AT+CMGS=\"+919603740090\"");//Change the receiver phone number
                    delay(500);
                    Serial.print("c3 relay OFF");    //the message you want to send
                    delay(500);
                    Serial.write(26);
                    delay(500);
                }
                else if (inchar=='1')
                {
                    delay(1000);
                    digitalWrite(relay3, LOW);
                    Serial.print("Relay 3 HIGH\n");
                    // delay(1000);
					//    Serial.println("AT+CMGD=1,4");                   //Delete all message
                    delay(500);
                    Serial.println("AT+CMGF=1");
                    delay(500);
                    Serial.println("AT+CMGS=\"+919603740090\"");//Change the receiver phone number
                    delay(500);
                    Serial.print("c3 relay ON");    //the message you want to send
                    delay(500);
                    Serial.write(26);
                    delay(500);
                }
                delay(10);
				inchar=Serial.read();
			}
			else if (inchar=='d')//closed
            {
				delay(10);
				inchar=Serial.read();
				if (inchar=='0')//closed
				{
                    digitalWrite(relay4,HIGH);
                    Serial.print("Relay 4 LOW\n");
                    // delay(500);
					//  Serial.println("AT+CMGD=1,4");                   //Delete all message
                    delay(500);
                    Serial.println("AT+CMGF=1");
                    delay(500);
                    Serial.println("AT+CMGS=\"+919603740090\"");//Change the receiver phone number
                    delay(500);
                    Serial.print("d4 relay OFF");    //the message you want to send
                    delay(500);
                    Serial.write(26);
                    delay(500);
                }
                else if (inchar=='1')
                {
                    delay(1000);
                    digitalWrite(relay4, LOW);
                    Serial.print("Relay 4 HIGH\n");
                    // delay(1000);
                    //    Serial.println("AT+CMGD=1,4");                   //Delete all message
                    delay(500);
                    Serial.println("AT+CMGF=1");
                    delay(500);
                    Serial.println("AT+CMGS=\"+919603740090\"");//Change the receiver phone number
                    delay(500);
                    Serial.print("d4 relay ON");    //the message you want to send
                    delay(500);
                    Serial.write(26);
                    delay(500);
                }
                delay(10);
				inchar=Serial.read();  
            }
        }
		else if (inchar=='*')
		{
			delay(10);
            inchar=Serial.read(); 
            //first led
            if (inchar=='m')//closed
            {
               delay(10);
               inchar=Serial.read();
               if (inchar=='1')//closed
               {
					sensorValue = analogRead(sensorPin);    
					delay(1000);          
					Serial.print("sensor = " ); 
					sensor1 = ((1023-sensorValue)*1.8) ;  
					Serial.println(sensor1);     
					Serial.begin(9600);
					delay(5000);
					Serial.println("AT");
					delay(1000);
					Serial.println("AT+CMGF=1");
					delay(1000);
					Serial.println("AT+CMGS=\"+919603740090\""); //CHANGE TO DESTINATION NUMBER
					delay(1000);
					Serial.print("804 rocksssss! moisture value is  ");
					Serial.print(sensorValue); 
					Serial.write(26);
					delay(1000);
				}
			}
			delay(10);
            inchar=Serial.read(); 
		}     
    }
    Serial.println("AT+CMGD=1,4");
 }
 void sendsms(


                        
                      
                  
