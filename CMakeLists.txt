cmake_minimum_required(VERSION 3.10)

project(Enigma C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(PROJECT_VERSION 1.1)

# Sources
set(ENIGMA_SOURCES
        src/main.c
        src/core.c
        src/export.c
        src/globals.c
        src/imports.c
        src/utils.c
)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Executable
add_executable(enigma ${ENIGMA_SOURCES})

# Install the executable to /usr/local/bin (default prefix is /usr/local)
install(TARGETS enigma
        RUNTIME DESTINATION bin
)

# Install data files (currently under project bin/) to the user's data dir
# This uses an absolute path into the user's home: ~/.local/share/enigma
set(ENIGMA_USER_DATA_DIR "$ENV{HOME}/.local/share/enigma")

# Ensure the per-user data directory exists during install
install(CODE "execute_process(COMMAND \"${CMAKE_COMMAND}\" -E make_directory \"${ENIGMA_USER_DATA_DIR}\")")

install(FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/bin/barrels_BIN
        ${CMAKE_CURRENT_SOURCE_DIR}/bin/modifiers_BIN
        DESTINATION ${ENIGMA_USER_DATA_DIR}
        PERMISSIONS
        OWNER_READ OWNER_WRITE
        GROUP_READ GROUP_WRITE
        WORLD_READ WORLD_WRITE
)

# Optional: print a message to clarify installation destinations
message(STATUS "Executable will be installed to: ${CMAKE_INSTALL_PREFIX}/bin (default /usr/local/bin)")
message(STATUS "Data files will be installed to: ${ENIGMA_USER_DATA_DIR}")
