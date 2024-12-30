# CMakeList.txt : CMake project for SaltnPepperEngine, include source and define
# project specific logic here.
#

# Add source to this project's executable.
#add_library (SaltnPepperEngine "SaltnPepperEngine.cpp" "SaltnPepperEngine.h")





SET (EXTERNAL_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Externals/)
SET (ENGINE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Engine/)


SET(SRC_FILES SaltnPepperEngine.cpp )
SET(INC_FILES  SaltnPepperEngine.h)

ADD_SUBDIRECTORY(${ENGINE_DIRECTORY})
ADD_SUBDIRECTORY(${EXTERNAL_DIRECTORY})




MESSAGE ([<WARNING>]"Source Files: ${SRC_FILES}")

ADD_EXECUTABLE (SaltnPepperEngine "${SRC_FILES}" "${INC_FILES}")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  SET_PROPERTY(TARGET SaltnPepperEngine PROPERTY CXX_STANDARD 20)
endif()




# TODO: Add tests and install targets if needed.

set(CMAKE_CXX_FLAGS "/utf-8")
set(CMAKE_C_FLAGS "/utf-8")




# include Paths for External Headers
TARGET_INCLUDE_DIRECTORIES(SaltnPepperEngine PUBLIC ${EXTERNAL_DIRECTORY})

# include Paths for Engine Headers
TARGET_INCLUDE_DIRECTORIES(SaltnPepperEngine PUBLIC ${ENGINE_DIRECTORY})





MESSAGE ([<WARNING>]"Binary path: ${ENGINE_DIRECTORY}")
#SUBDIRS(${CMAKE_CURRENT_SOURCE_DIR}/SaltnPepperEngine/Externals/spdlog)




