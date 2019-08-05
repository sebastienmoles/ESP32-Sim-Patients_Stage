#include <MesuresPatient.h>
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "Arduino.h"
#include "WiFi.h"

extern MES_MESURES_t mesures;

void mesure_rythme_cardiaque(MES_MESURES_t *p_mesures)
{
    float nb_float = 0;
    int nb_int = 0;
    nb_int = generation_nb_aleatoire_int(0, 40);
    if(nb_int < 30)
    {
        nb_float = generation_nb_aleatoire_float(68, 72);
    }else
    {
        nb_float = generation_nb_aleatoire_float(73, 150);
    }
    
    sprintf(p_mesures->rythme_cardiaque, "%.0f", nb_float);
}

void mesure_frequence_respi(MES_MESURES_t *p_mesures)
{
    float nb_float = 0;
    int nb_int = 0;
    nb_int = generation_nb_aleatoire_int(0, 40);
    if(nb_int <30)
    {
        nb_float = generation_nb_aleatoire_float(18, 21);
    }else
    {
        nb_float = generation_nb_aleatoire_int(22, 48);
    }
    sprintf(p_mesures->frequence_respi, "%.0f", nb_float);
}

void mesure_temperature(MES_MESURES_t *p_mesures)
{
    float nb_float = 0;
    int nb_int = 0;
    nb_int = generation_nb_aleatoire_int(0, 40);
    if(nb_int < 30)
    {
        nb_float = generation_nb_aleatoire_float(36.6, 37.8);
    }else
    {
        nb_float = generation_nb_aleatoire_float(37.9, 40);
    }
    
    sprintf(p_mesures->temperature, "%.2f", nb_float);
}

void mesure_tension_systolique(MES_MESURES_t *p_mesures)
{
    float nb_float = 0;
    int nb_int = 0;
    nb_int = generation_nb_aleatoire_int(0, 40);
    if(nb_int < 30)
    {
        nb_float = generation_nb_aleatoire_float(120, 129);
    }else
    {
        nb_float = generation_nb_aleatoire_float(130, 180);
    }
    
    sprintf(p_mesures->tension_systolique, "%.0f", nb_float);
}

void mesure_tension_diastolique(MES_MESURES_t *p_mesures)
{
    float nb_float = 0;
    int nb_int = 0;
    nb_int = generation_nb_aleatoire_int(0,40);
    if(nb_int < 30)
    {
        nb_float = generation_nb_aleatoire_float(80, 84);
    }else
    {
        nb_float = generation_nb_aleatoire_float(85, 110);
    }
   
    sprintf(p_mesures->tension_diastolique, "%.2f", nb_float);
}

int generation_nb_aleatoire_int(int min, int max)
{
    static int rand_is_seeded = 0;
    if(!rand_is_seeded)
    {
        srand(time(NULL));
        rand_is_seeded = 1;
    }
    return (rand()%(max-min+1) + min);
}

float generation_nb_aleatoire_float(float min, float max)
{
    return  (max - min) * ((((float) rand()) / (float) RAND_MAX)) + min ;
}
