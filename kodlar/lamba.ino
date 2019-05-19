int ses_sensoru = 4;
int role = 5;
int alkis = 0;
long algilama_araligi_baslangic = 0;
long algilama_araligi = 0;
boolean isik_durumu = false;
 int state;
void setup() {
  Serial.begin(9600);
  pinMode(ses_sensoru, INPUT);
  pinMode(role, OUTPUT);
}
 
void loop() {
 
  int sensor_durumu = digitalRead(ses_sensoru);
 
  if (sensor_durumu == 0)
  {
    if (alkis == 0)
    {
      algilama_araligi_baslangic = algilama_araligi = millis();
      alkis++;
    }
    else if (alkis > 0 && millis()-algilama_araligi >= 50)
    {
      algilama_araligi = millis();
      alkis++;
    }
  }
 
  if (millis()-algilama_araligi_baslangic >= 400)
  {
    if (alkis == 2)
    {
      if (!isik_durumu)
        {
          state=1;
          isik_durumu = true;
          digitalWrite(role, HIGH);
        }
        else if (isik_durumu)
        {
          state=0;
          isik_durumu = false;
          digitalWrite(role, LOW);
        }
    }
    alkis = 0;
  }
  if(Serial.available()>0){
    state=Serial.read();
}
  
  if((alkis==0 || alkis==1) && state=='1')
  {
    isik_durumu=true;
    digitalWrite(role,HIGH);
    }
  else if((alkis==0 || alkis==1) && state=='0')
  {
    isik_durumu=false;
    digitalWrite(role,LOW);}
  }
  

