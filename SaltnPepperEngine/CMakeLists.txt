# CMakeList.txt : CMake project for SaltnPepperEngine, include source and define
# project specific logic here.
#

# Add source to this project's executable.
#add_library (SaltnPepperEngine "SaltnPepperEngine.cpp" "SaltnPepperEngine.h")
ADD_EXECUTABLE (SaltnPepperEngine "SaltnPepperEngine.cpp" "SaltnPepperEngine.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  SET_PROPERTY(TARGET SaltnPepperEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

SET (EXTERNAL_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Externals/)
SET (ENGINE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Engine/)

# include Paths for External Headers
TARGET_INCLUDE_DIRECTORIES(SaltnPepperEngine PUBLIC ${EXTERNAL_DIRECTORY})

# include Paths for Engine Headers
TARGET_INCLUDE_DIRECTORIES(SaltnPepperEngine PUBLIC ${ENGINE_DIRECTORY})


MESSAGE ([<WARNING>]"Binary path: ${ENGINE_DIRECTORY}")
#SUBDIRS(${CMAKE_CURRENT_SOURCE_DIR}/SaltnPepperEngine/Externals/spdlog)