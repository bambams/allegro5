#ifndef __al_included_allegro5_allegro_devcon_h
#define __al_included_allegro5_allegro_devcon_h

#if (defined ALLEGRO_MINGW32) || (defined ALLEGRO_MSVC) || (defined ALLEGRO_BCC32)
#ifndef ALLEGRO_STATICLINK
#ifdef ALLEGRO_DEVCON_SRC
#define _ALLEGRO_DEVCON_DLL __declspec(dllexport)
#else
#define _ALLEGRO_DEVCON_DLL __declspec(dllimport)
#endif
#else
#define _ALLEGRO_DEVCON_DLL
#endif
#endif

#if defined ALLEGRO_MSVC
#define ALLEGRO_DEVCON_FUNC(type, name, args)      _ALLEGRO_DEVCON_DLL type __cdecl name args
#elif defined ALLEGRO_MINGW32
#define ALLEGRO_DEVCON_FUNC(type, name, args)      extern type name args
#elif defined ALLEGRO_BCC32
#define ALLEGRO_DEVCON_FUNC(type, name, args)      extern _ALLEGRO_DEVCON_DLL type name args
#else
#define ALLEGRO_DEVCON_FUNC      AL_FUNC
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#include "allegro.h"

ALLEGRO_DEVCON_FUNC(bool, al_init_devcon_addon, (int w, int h, int bufsiz))
ALLEGRO_DEVCON_FUNC(void, al_init_devcon_addon, (void))

#ifdef __cplusplus
}
#endif

#endif
