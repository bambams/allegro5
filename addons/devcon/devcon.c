#include "allegro5/allegro5_devcon.h"

const int DEFAULT_BUFSIZ = 8192;

static bool addon_initialized = false;
static ALLEGRO_BITMAP * bitmap = NULL;
static char * buffer = NULL;
static char * wpos = 0;
static long length = 0;

/* Function: al_init_devcon_addon
 */
bool al_init_devcon_addon(int w, int h, int bufsiz)
{
    bitmap = al_create_bitmap(w, h);

    if(bitmap == NULL) return false;

    buffer = al_calloc(
            bufsiz <= 0 ? DEFAULT_BUFSIZ : bufsiz, sizeof(char));

    if(buffer == NULL) {
        al_shutdown_devcon_addon();
        return false;
    }

    addon_initialized = true;
    _al_add_exit_func(al_shutdown_devcon_addon, "devcon_shutdown");

    return ret;
}

/* Function: al_shutdown_devcon_addon
 */
void al_shutdown_devcon_addon(void)
{
    if(buffer != NULL) {
        free(buffer);
        buffer = NULL;
    }

    if(bitmap != NULL) {
        al_destroy_bitmap(bitmap);
        bitmap = NULL;
    }

    addon_initialized = false;
}
