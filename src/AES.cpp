#include "AES1.h"
#include "mbedtls/aes.h"
#include <string.h>
#include <Arduino.h>

extern char data_chiffree[33];

void encrypt(char * plainText, char * key, unsigned char * outpuBuffer)
{
    mbedtls_aes_context aes;

    mbedtls_aes_init(&aes);
    mbedtls_aes_setkey_enc(&aes, (const unsigned char*) key, strlen(key) * 8);
    mbedtls_aes_crypt_ecb( &aes, MBEDTLS_AES_ENCRYPT, (const unsigned char*)plainText, outpuBuffer);
    mbedtls_aes_free( &aes );
}

void decrypt(unsigned char * cipherText, char * key, unsigned char * outputBuffer)
{
    mbedtls_aes_context aes;

    mbedtls_aes_init( &aes );
    mbedtls_aes_setkey_dec( &aes, (const unsigned char*) key, strlen(key) * 8 );
    mbedtls_aes_crypt_ecb(&aes, MBEDTLS_AES_DECRYPT, (const unsigned char*)cipherText, outputBuffer);
    mbedtls_aes_free( &aes );
}

void afficher_texte_chiffre(unsigned char texte_chiffre[16])
{
      Serial.print("Texte chiffre : ");
     for (int i = 0; i < 16; i++) 
     {
        char str[3];
        sprintf(str, "%02x", (int)texte_chiffre[i]); 
        Serial.print(str);
    }
     
     Serial.println("");

}

void afficher_texte_dechiffre(unsigned char texte_dechiffre[16])
{
    Serial.print("Texte dechiffre : ");
    for (int i = 0; i < 16; i++) 
    {
     Serial.print((char)texte_dechiffre[i]);
     }
}

void conversion_hexa_to_send(unsigned char texte_chiffre[16])
{
    char str[3];
    for (int i = 0; i < 16; i++) 
    {
        sprintf(str, "%02x", texte_chiffre[i]);
        if(i == 0)
        {
            strcpy(data_chiffree, str);
        }else
        {
            strcat(data_chiffree, str);
        }
    }


}