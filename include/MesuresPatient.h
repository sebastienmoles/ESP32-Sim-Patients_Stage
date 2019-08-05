#ifndef MesuresPatient_h
#define MesuresPatient_h

typedef struct {
    char temperature[16] = "37.7";
    char rythme_cardiaque[10] = "";
    char frequence_respi[10] = "";
    char tension_systolique[10] = "";
    char tension_diastolique[10] = "";
}MES_MESURES_t;

void mesure_rythme_cardiaque(MES_MESURES_t *p_mesures);
void mesure_frequence_respi(MES_MESURES_t *p_mesures);
void mesure_temperature(MES_MESURES_t *p_mesures);
void mesure_tension_systolique(MES_MESURES_t *p_mesures);
void mesure_tension_diastolique(MES_MESURES_t *p_mesures);

int generation_nb_aleatoire_int(int min, int max);
float generation_nb_aleatoire_float(float min, float max);


#endif