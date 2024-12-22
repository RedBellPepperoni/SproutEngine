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

	/*Maths::Vector2 vecOne = Maths::Vector2(1.0f);
	Maths::Vector2 vecTwo = Maths::Vector2(2.0f,0.0f);
	Maths::Vector2 result = vecOne + vecTwo;*/

	//printf("The Result is : [%f , %f]", vecOne.x, vecOne.y);



	return 0;
}
