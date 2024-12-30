// SaltnPepperEngine.cpp : Defines the entry point for the application.
//

#include "SaltnPepperEngine.h"

using namespace std;

int main()
{
	//cout << "Hello CMake." << endl;
	Debug::Log::OnInit();

	LOG_TRACE("TRACE Log");
	LOG_INFO("INFO Log");
	LOG_WARN("WARNING Log");
	LOG_ERROR("ERROR Log");

	/*;
	
	;*/

	//printf("The Result is : [%f , %f]", vecOne.x, vecOne.y);

	Maths::Vector2 vecOne = Maths::Vector2{ 1.0f };
	Maths::Vector2 vecTwo = Maths::Vector2(2.0f, 0.0f);
	
	Maths::Vector2 newVec = vecOne * 2.0f;
	Maths::Vector2 newVec2 = ( - vecOne * (vecTwo) * 0 ) + vecOne;


	float x = 1.00f;
	float lerpedFlaot = Maths::Lerp(x, 10.0f, 0.5f);

	Maths::Quaternion quat = Maths::Quaternion{};
	


	LOG_ERROR("Lerped Float value : [{0}]", lerpedFlaot);
	
	LOG_WARN("VECTOR MUL : [{0} , {1}]", newVec2.x, newVec2.y);
	LOG_WARN("Quaternion : [{0} , {1} , {2} , {3}]", quat.x, quat.y, quat.z, quat.w);




	return 0;
}
