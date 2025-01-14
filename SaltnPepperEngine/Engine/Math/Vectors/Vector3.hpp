/************************************************************************|
|						    Vector3.hpp						     |
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

#ifndef VECTOR3_H
#define VECTOR3_H

#include <DirectXMath.h>

using namespace DirectX;

struct Matrix4;

namespace SaltnPepperEngine
{
	namespace Maths
	{
		struct Vector3 : public XMFLOAT3
		{


			/// Declarations for Vector3
			Vector3() noexcept : XMFLOAT3(0.0f, 0.0f, 0.0f) {}
			constexpr explicit Vector3(float _singleValue) noexcept : XMFLOAT3(_singleValue, _singleValue, _singleValue) {}
			constexpr Vector3(float _valueX, float _valueY, float _valueZ) noexcept : XMFLOAT3(_valueX, _valueY, _valueZ) {}


			Vector3(FXMVECTOR _vector) noexcept { XMStoreFloat3(this, _vector); }
			Vector3(const XMFLOAT3&  ) noexcept { this->x = _vector.x; this->y = _vector.y; this->z = _vector.z; }
			explicit Vector3(const XMVECTORF32& _vector) noexcept { this->x = _vector.f[0]; this->y = _vector.f[1]; this->z = _vector.f[2]; }

			Vector3(const Vector3&) = default;
			Vector3& operator=(const Vector3&) = default;

			Vector3(Vector3&&) = default;
			Vector3& operator=(Vector3&&) = default;

			operator XMVECTOR() const noexcept { return XMLoadFloat3(this); }

			Vector3(const XMFLOAT3& _xmFloat) noexcept
			{
				this->x = _xmFloat.x;
				this->y = _xmFloat.y;
			}

			Vector3(const XMVECTORF32& _xmVector32) noexcept
			{
				this->x = _xmVector32.f[0];
				this->y = _xmVector32.f[1];
				this->z = _xmVector32.f[2];		
			}

			Vector3(FXMVECTOR _xmVector) noexcept
			{
				XMStoreFloat3(this, _xmVector);
			}
		

			
			Vector3& operator= (const XMVECTORF32& _vector) noexcept { x = _vector.f[0]; y = _vector.f[1]; z = _vector.f[2]; return *this; }
			
			/// Arithmatic
			Vector3& operator+= (const Vector3& _vector) noexcept;
			Vector3& operator-= (const Vector3& _vector) noexcept;
			Vector3& operator*= (const Vector3& _vector) noexcept;
			Vector3& operator/= (const Vector3& _vector) noexcept;

			Vector3& operator*= (float _scalar) noexcept;
			Vector3& operator/= (float _scalar) noexcept;

			/// Comparisons
			bool operator == (const Vector3& _vector) const noexcept;
			bool operator != (const Vector3& _vector) const noexcept;
	

			/// Negative Value
			Vector3 operator- () const noexcept;
			Vector3 operator+ () const noexcept;


			/// Free-Standing Operators for Left Handeded Operations
			friend Vector3 operator+ (const Vector3& _firstVector, const Vector3& _secondVector) noexcept;
			friend Vector3 operator- (const Vector3& _firstVector, const Vector3& _secondVector) noexcept;
			friend Vector3 operator* (const Vector3& _firstVector, const Vector3& _secondVector) noexcept;
			friend Vector3 operator* (const Vector3& _firstVector, const float _float) noexcept;
			friend Vector3 operator/ (const Vector3& _firstVector, const Vector3& _secondVector) noexcept;
			friend Vector3 operator/ (const Vector3& _firstVector, const float _float) noexcept;
		}
	}
}

#endif // !VECTOR3_H
