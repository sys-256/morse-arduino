const int buttonPin = 2;

long lastTimeChanged = 0;
String dataToMorse = ""

void setup() {
  pinMode(buttonPin, INPUT);	
  Serial.begin(9600);
}

void loop() {

  if(digitalRead(buttonPin) == 1){
    lastTimeChanged = millis();

    while(digitalRead(buttonPin) == 1){};

    if(millis() - lastTimeChanged < 15){
      Serial.println("False Registery");
    }else if(millis() - lastTimeChanged < 250){
      Serial.println("Short");
      dataToMorse = dataToMorse + ".";
    }else if(millis() - lastTimeChanged < 1000){
      Serial.println("Long");
      dataToMorse = dataToMorse + "-";
    }else if(millis() - lastTimeChanged < 4000){
      Serial.println("nieuwe letter");
      dataToMorse = dataToMorse + " ";
    }else{
      Serial.println("Space");     
      dataToMorse = dataToMorse + "/";   
    };


    
  };


}
