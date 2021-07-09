#ifndef _CALCULATEPORC_
#define _CALCULATEPORC_

// Protótipos de Função 
int convertMM(int mm);

// Extensões
extern Settings settings;

// Converte a leitura o sensor feita em mm
// Para a capacidade da lixeira
// Utiliza a seguinte formulá
// Capacidade = (1.0 - (<leitura> - <distancia até o topo>) / (<distancia até o fundo> - <distancia até o topo>)) * 100
int convertMM(int mm) {
    int DEAD_AREA = atoi(settings.distanceCover.c_str()) * 10;

    if(DEAD_AREA < 5)
        DEAD_AREA = 5;
        
    int MAX = atoi(settings.distanceBottom.c_str()) * 10;

    int result = (int)((1.0 - (mm - DEAD_AREA) / (float)(MAX - DEAD_AREA)) * 100);

    if(result < 0)
        result = 0;
    else if(result > 100)
        result = 100;
        
    return result;
}

#endif