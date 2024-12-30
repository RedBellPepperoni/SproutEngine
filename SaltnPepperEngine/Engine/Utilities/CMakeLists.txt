# DIRECTORY : SaltnPepperEngine/Engine/Utilities

SET(CURRENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

	
LIST(
	APPEND SRC_FILES
	"${CURRENT_DIR}/Logging/Log.cpp"
	"${CURRENT_DIR}/Math/Vectors/Vector2.cpp"
	"${CURRENT_DIR}/Math/Quaternion.cpp"
)

LIST(
	APPEND INC_FILES
	"${CURRENT_DIR}/Logging/Log.hpp"
	"${CURRENT_DIR}/Math/Vectors/Vector2.hpp"
	"${CURRENT_DIR}/Math/Quaternion.hpp"
	"${CURRENT_DIR}/Math/MathFunctions.hpp"
	"${CURRENT_DIR}/Math/MathDefinitions.hpp"
)

SET (SRC_FILES ${SRC_FILES} PARENT_SCOPE )
SET (INC_FILES ${INC_FILES} PARENT_SCOPE )