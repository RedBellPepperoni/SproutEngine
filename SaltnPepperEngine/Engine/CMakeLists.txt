# DIRECTORY : SaltnPepperEngine/Engine

SET(CURRENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

	
LIST(
	APPEND SRC_FILES
	"${CURRENT_DIR}/Utilities/Logging/Log.cpp"
	"${CURRENT_DIR}/Utilities/Math/Vector2.cpp"
)

LIST(
	APPEND INC_FILES
	"${CURRENT_DIR}/Utilities/Logging/Log.hpp"
	"${CURRENT_DIR}/Utilities/Math/Vector2.hpp"
)

SET (SRC_FILES ${SRC_FILES} PARENT_SCOPE )
SET (INC_FILES ${INC_FILES} PARENT_SCOPE )