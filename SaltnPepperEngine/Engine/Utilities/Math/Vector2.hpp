/************************************************************************|
|						    Vector2.hpp						     |
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

#ifndef VECTOR_2_H
#define VECTTOR_2_H


#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <DirectXCollision.h>

using namespace DirectX;

namespace SaltnPepperEngine
{
	namespace Maths
	{

		struct Vector2Int;
		

		/// <summary>
		///  Structure defining a 2 dimentional floating point vector (a Vector 2)
		/// </summary>
		struct Vector2 : public XMFLOAT2
		{
			
			static const Vector2 Zero;
			static const Vector2 One;
			static const Vector2 UnitX;
			static const Vector2 UnitY;




			/// Declarations for Vector2
			Vector2() noexcept : XMFLOAT2(0.0f, 0.0f) {}
			constexpr explicit Vector2(float _singleValue) noexcept : XMFLOAT2(_singleValue, _singleValue) {}
			constexpr explicit Vector2(float _xValue, float _yValue) noexcept : XMFLOAT2(_xValue, _yValue) {}

			Vector2(const Vector2&) = default;
			Vector2& operator=(const Vector2&) = default;

			Vector2(Vector2&&) = default;
			Vector2& operator=(Vector2&&) = default;

			operator XMVECTOR() const noexcept { return XMLoadFloat2(this); }

			Vector2(const XMFLOAT2& _xmFloat) noexcept 
			{ 
				this->x = _xmFloat.x;  
				this->y = _xmFloat.y;
			}

			Vector2(const XMVECTORF32& _xmVector32) noexcept
			{
				this->x = _xmVector32.f[0];
				this->y = _xmVector32.f[1];
			}

			Vector2(FXMVECTOR _xmVector) noexcept
			{
				XMStoreFloat2(this, _xmVector);
			}

			
			/// Arithmatic
			Vector2& operator+= (const Vector2& _vector) noexcept;
			Vector2& operator-= (const Vector2& _vector) noexcept;
			Vector2& operator*= (const Vector2& _vector) noexcept;
			Vector2& operator/= (const Vector2& _vector) noexcept;
			

			Vector2& operator*= (const float _float) noexcept;
			Vector2& operator/= (const float _float) noexcept;

			/// Comparisons
			bool operator== (const Vector2& _vector) const noexcept;
			bool operator!= (const Vector2& _vector) const noexcept;

			/// Negative Value
			Vector2 operator- () const noexcept;
			Vector2 operator+ () const noexcept;

	
			/// Free-Standing Operators for Left Handeded Operations
			friend Vector2 operator+ (const Vector2& _firstVector, const Vector2& _secondVector) noexcept;
			friend Vector2 operator- (const Vector2& _firstVector, const Vector2& _secondVector) noexcept;
			friend Vector2 operator* (const Vector2& _firstVector, const Vector2& _secondVector) noexcept;
			friend Vector2 operator* (const Vector2& _firstVector, const float _float) noexcept;
			friend Vector2 operator/ (const Vector2& _firstVector, const Vector2& _secondVector) noexcept;
			friend Vector2 operator/ (const Vector2& _firstVector, const float _float) noexcept;
			/// End of Free Standing Fucntions

			float Length() const noexcept;
			float LengthSquared() const noexcept;

			static float Distance(const Vector2& _firstVector, const Vector2& _secondVector) noexcept;
			static float DistanceSquared(const Vector2& _firstVector, const Vector2& _secondVector) noexcept;



			
		};


		

	}
}



#endif //!VECTOR_2_H

