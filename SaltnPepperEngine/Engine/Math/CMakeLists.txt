# DIRECTORY : SaltnPepperEngine/Engine/Math

SET(CURRENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

	
LIST(
	APPEND SRC_FILES
	"${CURRENT_DIR}/Vectors/Vector2.cpp"
	"${CURRENT_DIR}/Quaternion.cpp"
	"${CURRENT_DIR}/Matrix4.cpp"
)

LIST(
	APPEND INC_FILES
	"${CURRENT_DIR}/Vectors/Vector2.hpp"
	"${CURRENT_DIR}/Quaternion.hpp"
	"${CURRENT_DIR}/Matrix4.hpp"
	"${CURRENT_DIR}/MathFunctions.hpp"
	"${CURRENT_DIR}/MathDefinitions.hpp"
)

SET (SRC_FILES ${SRC_FILES} PARENT_SCOPE )
SET (INC_FILES ${INC_FILES} PARENT_SCOPE )