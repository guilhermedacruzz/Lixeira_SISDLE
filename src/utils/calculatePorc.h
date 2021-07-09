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
    //Distância que vai ser considerada do cálculo devido as limitações física do sensor
    int DEAD_AREA = atoi(settings.distanceCover.c_str()) * 10; // Calcula a zona morta do sensor, ou seja, a distância a ser desconsiderada

    if(DEAD_AREA < 5) // Garante que a distância mínima vai ser desconsiderada
        DEAD_AREA = 5;
        
    int MAX = atoi(settings.distanceBottom.c_str()) * 10; // cálcula a distância até o fundo

    int result = (int)((1.0 - (mm - DEAD_AREA) / (float)(MAX - DEAD_AREA)) * 100); // Cálcula a porcentagem da capacidade da lixeira

    // Garante que os valores serão exatos
    if(result < 0)
        result = 0;
    else if(result > 100)
        result = 100;
        
    return result;
}

#endif