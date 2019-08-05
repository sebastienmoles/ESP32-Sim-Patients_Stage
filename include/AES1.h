#ifndef AES1_h
#define AES1_h

#include "mbedtls/aes.h"

void encrypt(char * plainText, char * key, unsigned char * outpuBuffer);

void decrypt(unsigned char * cipherText, char * key, unsigned char * outputBuffer);

void afficher_texte_chiffre(unsigned char texte_chiffre[16]);

void afficher_texte_dechiffre(unsigned char texte_dechiffre[16]);

void conversion_hexa_to_send(unsigned char texte_chiffre[16]);

#endif