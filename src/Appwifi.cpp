#include "AppWifi.h"
#include <WiFiMulti.h>
#include <string.h>

extern WiFiClient client;
extern char *id_Objet;

void connexion_serveur_TCP_via_wifi(const char *SSID, const char *PWD, const char *HOST, const uint16_t PORT)
{
    WiFiMulti WifiMulti;

    WifiMulti.addAP(SSID, PWD);
  
    Serial.println();
    Serial.println();
    Serial.println("Waiting for Wifi ...");

     while(WifiMulti.run() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
     }

    Serial.println("");
    Serial.println("Wifi connected");
    Serial.println("IP adress: ");
    Serial.println(WiFi.localIP());

    Serial.print("Connecting to ");
    Serial.println(HOST);
  
    if(!client.connect(HOST, PORT))
    {
        Serial.println("Connected failed");
        Serial.println("Waiting 5 seconds befire retrying ...");
        delay(5000);
    }

    delay(500);
}

void send_data(char *ObjetApp, char *commande, char *data)
{
    char message[100];
    strcpy(message, id_Objet);
    strcat(message, ObjetApp);
    strcat(message, commande);
    Serial.println(data);
    strcat(message, data);
    Serial.print("Message envoye : ");
    Serial.println(message);
    client.print(message);
}
