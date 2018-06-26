#include <stdio.h>
#include <stdlib.h>

#include "buttons.h"

typedef struct {
    TaskData task;
    PioState pioState;
} APP_T;

APP_T app;

static void app_handler(Task task, MessageId id, Message message)
{
    switch (id) {
    case PLAY:
        printf("PLAY\n");
        break;

    case VOL_DOWN:
        printf("VOL_DOWN\n");
        break;

    case VOL_UP:
        printf("VOL_UP\n");
        break;

    case MUTE_ON:
        printf("MUTE_ON\n");
        break;

    case MUTE_OFF:
        printf("MUTE_OFF\n");
        break;
 
    case PLAY_PREV:
        printf("PLAY_PREV\n");
        break;

    case PLAY_NEXT:
        printf("PLAY_NEXT\n");
        break;

    default:
        printf("Unhandled message: %u\n", id);
        break;
    }
}

static void app_init(void)
{
    app.task.handler = app_handler;  
    pioInit(&app.pioState, &app.task);
}

int main(void)
{   
    printf("CSR8675 Buttons\n");

    app_init();
    
    MessageLoop();    
    
    return 0;
}
