#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <stdlib.h>
#include "mbedtls/aes.h"
#include "AES1.h"
#include "AppWifi.h"
#include "MesuresPatient.h"

char s[10] = "";
char *id_Objet = "000001";
char *Objet_App0 = "00";
char *Objet_App1 = "01";

char *commande_add_key = "00";
char *commande_verif_key = "01";
char *commande_temp = "02";
char *commande_frequence_respi = "03";
char *commande_rythme_cardiaque = "04";
char *commande_tension_systolique = "05";
char *commande_tension_diastolique = "06";

char key_objetApp0[] = "\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01\x01";
char key_objetApp1[] = "\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02";
char *plainText = "Test AES Orange ";
char *empty_data = "";
unsigned char cipherTextOutput[16];
unsigned char decipheredTextOutput[16];
char data_chiffree[33];
WiFiClient client;

MES_MESURES_t mesures;

void mesures_lits();

void applicationTemperature(char* Objet_App, char* key_objetApp);
void applicationFrequenceRespiratoire(char* Objet_App, char* key_objetApp);
void applicationRythmeCardiaque(char* Objet_App, char* key_objetApp);
void applicationTensionDiastolique(char* Objet_App, char* key_objetApp);
void applicationTensionSystolique(char* Objet_App, char* key_objetApp);
void setup()
{
  Serial.begin(9600);
  connexion_serveur_TCP_via_wifi("iot_orange","orange_2019", "192.168.50.1", 12800);
}


void loop() 
{
  mesures_lits();
}

void mesures_lits()
{
  applicationTemperature(Objet_App0, key_objetApp0);
  delay(30000);
  applicationTemperature(Objet_App1, key_objetApp1);
  delay(60000);
  applicationFrequenceRespiratoire(Objet_App0, key_objetApp0);
  delay(30000);
  applicationFrequenceRespiratoire(Objet_App1, key_objetApp1);
  delay(60000);
  applicationRythmeCardiaque(Objet_App0, key_objetApp0),
  delay(30000);
  applicationRythmeCardiaque(Objet_App1, key_objetApp1);
  delay(60000);
  applicationTensionSystolique(Objet_App0, key_objetApp0);
  delay(30000);
  applicationTensionSystolique(Objet_App1, key_objetApp1);
  delay(60000);
  applicationTensionDiastolique(Objet_App0, key_objetApp0);
  delay(30000);
  applicationTensionDiastolique(Objet_App1, key_objetApp1);
  delay(60000);
}

void applicationTemperature(char* Objet_App, char* key_objetApp)
{
  mesure_temperature(&mesures);
  encrypt(mesures.temperature, key_objetApp, cipherTextOutput);
  conversion_hexa_to_send(cipherTextOutput);
  send_data(Objet_App,commande_temp, data_chiffree);
}

void applicationFrequenceRespiratoire(char* Objet_App, char* key_objetApp)
{
  mesure_frequence_respi(&mesures);
  encrypt(mesures.frequence_respi, key_objetApp, cipherTextOutput);
  conversion_hexa_to_send(cipherTextOutput);
  send_data(Objet_App, commande_frequence_respi, data_chiffree);
}

void applicationRythmeCardiaque(char* Objet_App, char* key_objetApp)
{
  mesure_rythme_cardiaque(&mesures);
  encrypt(mesures.rythme_cardiaque, key_objetApp, cipherTextOutput);
  conversion_hexa_to_send(cipherTextOutput);
  send_data(Objet_App,commande_rythme_cardiaque, data_chiffree);
}

void applicationTensionDiastolique(char* Objet_App, char* key_objetApp)
{
  mesure_tension_systolique(&mesures);
  encrypt(mesures.tension_systolique, key_objetApp, cipherTextOutput);
  conversion_hexa_to_send(cipherTextOutput);
  send_data(Objet_App,commande_tension_systolique, data_chiffree);
}

void applicationTensionSystolique(char* Objet_App, char* key_objetApp)
{
  mesure_tension_diastolique(&mesures);
  encrypt(mesures.tension_diastolique, key_objetApp, cipherTextOutput);
  conversion_hexa_to_send(cipherTextOutput);
  send_data(Objet_App,commande_tension_diastolique, data_chiffree);
}
