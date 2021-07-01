#ifndef _CALCULATEPORC_
#define _CALCULATEPORC_

int convertMM(int mm);

extern Settings settings;

int convertMM(int mm) {
    int DEAD_AREA = atoi(settings.distanceCover.c_str()) * 10;
    int MAX = atoi(settings.distanceBottom.c_str()) * 10;

    return (int)((1.0 - (mm - DEAD_AREA) / (float)(MAX - DEAD_AREA)) * 100);
}

#endif