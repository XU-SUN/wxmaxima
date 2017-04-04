configure_file(${CMAKE_CURRENT_SOURCE_DIR}/wxmathml.lisp.in ${CMAKE_CURRENT_BINARY_DIR}/wxmathml.lisp)

if (APPLE)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Info.plist.in ${CMAKE_CURRENT_BINARY_DIR}/Info.plist)
endif()

set(DATAFILES
        ${CMAKE_CURRENT_BINARY_DIR}/wxmathml.lisp
        ${CMAKE_CURRENT_SOURCE_DIR}/tips.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/wxmaxima.png
        ${CMAKE_CURRENT_SOURCE_DIR}/wxmaxima.svg
        ${CMAKE_CURRENT_SOURCE_DIR}/autocomplete.txt)

set(PIXMAPS
        ${CMAKE_CURRENT_SOURCE_DIR}/text-x-wxmathml.svg
        ${CMAKE_CURRENT_SOURCE_DIR}/text-x-wxmaxima-batch.svg
        ${CMAKE_CURRENT_SOURCE_DIR}/wxmaxima-16.xpm
        ${CMAKE_CURRENT_SOURCE_DIR}/wxmaxima.png
        ${CMAKE_CURRENT_SOURCE_DIR}/wxmaxima.svg
        ${CMAKE_CURRENT_SOURCE_DIR}/wxmaxima-32.xpm)

install(FILES ${DATAFILES}                                     DESTINATION share/wxMaxima)
install(FILES ${PIXMAPS}                                       DESTINATION share/pixmaps)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/wxmaxima             DESTINATION share/bash-completion/completions)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/wxmaxima.1           DESTINATION share/man/man1)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/wxMaxima.appdata.xml DESTINATION share/appdata)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/wxMaxima.desktop     DESTINATION share/applications)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/x-wxmathml.xml       DESTINATION share/mime/packages)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/x-wxmaxima-batch.xml DESTINATION share/mime/packages)