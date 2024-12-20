# CMakeList.txt : CMake project for SaltnPepperEngine, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_library (SaltnPepperEngine "SaltnPepperEngine.cpp" "SaltnPepperEngine.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SaltnPepperEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.


# include Paths for External Headers
TARGET_INCLUDE_DIRECTORIES(SaltnPepperEngine PUBLIC ${EXTERNAL_DIRECTORY})
TARGET_INCLUDE_DIRECTORIES(SaltnPepperEngine PUBLIC ${ENGINE_DIRECTORY})

INCLUDE_DIRECTORIES(${EXTERNAL_DIRECTORY}/spdlog)

#SUBDIRS(${CMAKE_CURRENT_SOURCE_DIR}/SaltnPepperEngine/Externals/spdlog)