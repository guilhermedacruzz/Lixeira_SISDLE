#ifndef _CALCULATEPORC_
#define _CALCULATEPORC_

int convertMM(int mm);

extern Settings settings;

// Converte a leitura o sensor feita em mm
// Para a capacidade da lixeira
// Utiliza a seguinte formulá
// Capacidade = (1.0 - (<leitura> - <distancia até o topo>) / (<distancia até o fundo> - <distancia até o topo>)) * 100
int convertMM(int mm) {
    int DEAD_AREA = atoi(settings.distanceCover.c_str()) * 10;
    int MAX = atoi(settings.distanceBottom.c_str()) * 10;

    return (int)((1.0 - (mm - DEAD_AREA) / (float)(MAX - DEAD_AREA)) * 100);
}

#endif