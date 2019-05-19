# Gumulu_sist_ikinci_proje
<b>Burada Gömülü Sistemler dersi için yapılan ikinci proje yer almaktadır.</b><br><br>
Bu proje hareket etmekte zorlanan yaşlı insanların yerlerinden kalkmadan bir telefon aracılığı ile yanan masa lambasını kapatıp,<br>
açabilmeleri için tasarlanmıştır. <br><br>

Video Linki için <a href="https://youtu.be/9uipk3ih6PM">buraya</a> tıklayınız.<br>

Proje Kodlarını yukardan direk indirebileceğiniz gibi, aşağıdanda ulaşabilirsiniz.<br>

<br>---Değişken Tanımlamaları---
<br>int ses_sensoru = 4;
<br>int role = 5;
<br>int alkis = 0;
<br>long algilama_araligi_baslangic = 0;
<br>long algilama_araligi = 0;
<br>boolean isik_durumu = false;
<br>int state;
<br>--Ayarlar--
<br>void setup() {
<br> Serial.begin(9600);
<br>pinMode(ses_sensoru, INPUT);
<br>pinMode(role, OUTPUT);
<br>}
 
<br> void loop() {
 
 <br> int sensor_durumu = digitalRead(ses_sensoru);
 
<br>  if (sensor_durumu == 0)
  <br>{
    <br>if (alkis == 0)
    <br>{
      <br>algilama_araligi_baslangic = algilama_araligi = millis();
      <br>alkis++;
    <br>}
    <br>else if (alkis > 0 && millis()-algilama_araligi >= 50)
    <br>{
      <br>algilama_araligi = millis();
      <br>alkis++;
    <br>}
  <br>}
<br>if (millis()-algilama_araligi_baslangic >= 400)
<br>  {
 <br>   if (alkis == 2)
  <br>  {
   <br>   if (!isik_durumu)
       <br> {
         <br> state=1;
         <br> isik_durumu = true;
         <br> digitalWrite(role, HIGH);
        }
       <br> else if (isik_durumu)
       <br> {
        <br>  state=0;
        <br>  isik_durumu = false;
         <br> digitalWrite(role, LOW);
       <br> }
   <br> }
   <br> alkis = 0;
<br>  }
<br>   if(Serial.available()>0){
   <br>  state=Serial.read();
<br> }
 <br>if((alkis==0 || alkis==1) && state=='1')
 <br> {
  <br>  isik_durumu=true;
 <br>   digitalWrite(role,HIGH);
   <br> }
<br>  else if((alkis==0 || alkis==1) && state=='0')
<br>  {
 <br>   isik_durumu=false;
 <br>   digitalWrite(role,LOW);}
  <br>}
