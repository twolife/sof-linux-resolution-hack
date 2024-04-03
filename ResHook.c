#define _GNU_SOURCE
#define __USE_GNU
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* str;
    int x; 
    int y;
    int mode;
} vme; 

void _init(void)
{
    char* xstr = getenv("SOF_WIDTH");
    char* ystr = getenv("SOF_HEIGHT");

    vme* videoModes;
    int x=0, y=0;

    printf("Hijacking vid_modes struct... ");
    videoModes = dlsym(RTLD_DEFAULT, "vid_modes");
    if(videoModes==NULL)
    {
        printf("ERROR:_ Could not find vid_modes.\n\n");
        return;
    }

    if(!xstr || !ystr)
    {
        printf("ERROR:_ You need to set SOF_HEIGHT and SOF_WIDTH in the enviroment before running.\n\n");
        return;
    }

    x = atoi(xstr);
    y = atoi(ystr);
    if( x > 1 && y > 1 )
    {
        printf("Using %sx%s as custom resolution.\n\n", xstr, ystr);
        // From 0 to 9 ; Modes 0 to 2 are invalid
        // 3 is the first usable mode and the default (640x480)
        // 9 is the last mode (1600x1200) and the one we override
        videoModes[9].x = x;
        videoModes[9].y = y;
    } else {
        printf("ERROR:_ Can't use SOF_HEIGHT=%s SOF_WIDTH=%s.\n\n", xstr, ystr);
    }
}
