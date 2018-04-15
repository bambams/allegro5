set(DEVCON_SOURCES
    devcon.c
    )

set(DEVCON_INCLUDE_FILES allegro5/allegro_devcon.h)

set_our_header_properties(${DEVCON_INCLUDE_FILES})

add_our_addon_library(allegro_devcon
    AllegroDevcon-${ALLEGRO_SOVERSION}
    "${DEVCON_SOURCES};${DEVCON_INCLUDE_FILES}"
    "-DALLEGRO_DEVCON_SRC"
    "${ALLEGRO_LINK_WITH}"
    )

install_our_headers(${DEVCON_INCLUDE_FILES})

add_addon(devcon)

#-----------------------------------------------------------------------------#
# vi: set ts=8 sts=4 sw=4 et:
