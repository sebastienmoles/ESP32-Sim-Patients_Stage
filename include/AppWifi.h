#ifndef AppWifi_h
#define AppWifi_h

#include <WiFi.h>
#include <WiFiMulti.h>

void connexion_serveur_TCP_via_wifi(const char *SSID, const char *PWD, const char *HOST, const uint16_t PORT);

void send_data(char *ObjetApp, char *commande, char *data);


#endif