/************************************************************************|
|						      Matrix.hpp						          |
|************************************************************************|
|                                                                        |
|========================================================================|
|				Copyright (c) 2024 - present Abhishek Dalvi.             |
|																		 |
|                                                                        |
|  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       |
|  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    |
|  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.|
|  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  |
|  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  |
|  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     |
|  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                |
**************************************************************************/


#ifndef MATRIX_4_H
#define MATRIX_4_H

#include <DirectXMath.h>

using namespace DirectX;

namespace SaltnPepperEngine
{
	namespace Maths
	{

		struct Matrix4 : public XMFLOAT4
		{
			Matrix() noexcept : XMFLOAT4X4(1.f, 0, 0, 0,
										   0, 1.f, 0, 0,
										   0, 0, 1.f, 0,
										   0, 0, 0, 1.f)
			{
			}
		};

	}
}


#endif // !MATRIX_4_H
