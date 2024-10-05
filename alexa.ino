 String voice;

#define relay 12
#define led1 3
#define led2 5
#define led3 7

void setup() 
{                                            // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW); 
}

  int relayVal; 

void loop() {
 
  while (Serial.available())   //Check if there is an available byte to read
  {                            
  delay(10);                   //Delay added to make thing stable
  char c = Serial.read();      //Conduct a serial read
  if (c == '#') {break;}       //Exit the loop when the # is detected after the word
  voice += c;                  //Shorthand for voice = voice + c
  } 

  if (voice.length() > 0) {
    Serial.println(voice);
  //----------Control Light----------// 

       if(voice == "turn on the light")       // To tune ON the bulb                   
     {
     digitalWrite(relay, HIGH); 
     }  
  else if(voice == "turn off the light")      // To turn OFF the bulb                        
     {
    digitalWrite(relay, LOW);
     }  
     else if(voice == "red")      // To turn OFF the bulb                        
     {
    digitalWrite(led1, HIGH);
     } 
     else if(voice == "red off")      // To turn OFF the bulb                        
     {
    digitalWrite(led1, LOW);
     }   
     else if(voice == "green")      // To turn OFF the bulb                        
     {
    digitalWrite(led2, HIGH);
     } 
     else if(voice == "green off")      // To turn OFF the bulb                        
     {
    digitalWrite(led2, LOW);
     }   
     else if(voice == "yellow")      // To turn OFF the bulb                        
     {
    digitalWrite(led3, HIGH);
     } 
     else if(voice == "yellow off")      // To turn OFF the bulb                        
     {
    digitalWrite(led3, LOW);
     }
     else if(voice == "all on")      // To turn OFF the bulb                        
     {
    digitalWrite(led3, HIGH);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(relay, HIGH);
     }   
  
voice="";                            //Reset the variable after initiating
}
}
