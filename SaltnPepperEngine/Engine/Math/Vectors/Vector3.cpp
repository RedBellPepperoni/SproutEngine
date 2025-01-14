/************************************************************************|
|						    Vector3.cpp						     |
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

#include "Math/Vectors/Vector3.hpp"
#include <Math/Quaternion.hpp>
#include <Core/EngineDefines.hpp>
 
namespace SaltnPepperEngine::Maths
{

	

	inline Vector3& Vector3::operator+=(const Vector3& _vector) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat3(this);
		const XMVECTOR vectorTwo = XMLoadFloat3(&_vector);
		const XMVECTOR finalVector = XMVectorAdd(vectorOne, vectorTwo);
		XMStoreFloat3(this, finalVector);
		return *this;
	}

	inline Vector3& Vector3::operator-=(const Vector3& _vector) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat3(this);
		const XMVECTOR vectorTwo = XMLoadFloat3(&_vector);
		const XMVECTOR finalVector = XMVectorSubtract(vectorOne, vectorTwo);
		XMStoreFloat3(this, finalVector);
		return *this;
	}

	inline Vector3& Vector3::operator*=(const Vector3& _vector) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat3(this);
		const XMVECTOR vectorTwo = XMLoadFloat3(&_vector);
		const XMVECTOR finalVector = XMVectorMultiply(vectorOne, vectorTwo);
		XMStoreFloat3(this, finalVector);
		return *this;
	}

	inline Vector3& Vector3::operator/=(const Vector3& _vector) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat3(this);
		const XMVECTOR vectorTwo = XMLoadFloat3(&_vector);
		const XMVECTOR finalVector = XMVectorDivide(vectorOne, vectorTwo);
		XMStoreFloat3(this, finalVector);
		return *this;
	}


	inline Vector3& Vector3::operator*=(float _scalar) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat3(this);
		const XMVECTOR finalVector = XMVectorScale(vectorOne, _scalar);
		XMStoreFloat3(this, finalVector);
		return *this;
	}

	inline Vector3& Vector3::operator/=(float _scalar) noexcept
	{
		using namespace DirectX;
		// Check Divide by Zero Edge Case
		SNP_ASSERT(_scalar != 0.0f);

	}

	inline bool Vector3::operator==(const Vector3& _vector) const noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat3(this);
		const XMVECTOR vectorTwo = XMLoadFloat3(&_vector);
		return XMVector3Equal(vectorOne, vectorTwo);
	}

	inline bool Vector3::operator!=(const Vector3& _vector) const noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat3(this);
		const XMVECTOR vectorTwo = XMLoadFloat3(&_vector);
		return XMVector3NotEqual(vectorOne, vectorTwo);
	}
	Vector3 Vector3::operator-() const noexcept
	{
		return Vector3();
	}
	Vector3 Vector3::operator+() const noexcept
	{
		return Vector3();
	}
	Vector3 operator+(const Vector3& _firstVector, const Vector3& _secondVector) noexcept
	{
		return Vector3();
	}
	Vector3 operator-(const Vector3& _firstVector, const Vector3& _secondVector) noexcept
	{
		return Vector3();
	}
	Vector3 operator*(const Vector3& _firstVector, const Vector3& _secondVector) noexcept
	{
		return Vector3();
	}
	Vector3 operator*(const Vector3& _firstVector, const float _float) noexcept
	{
		return Vector3();
	}
	Vector3 operator/(const Vector3& _firstVector, const Vector3& _secondVector) noexcept
	{
		return Vector3();
	}
	Vector3 operator/(const Vector3& _firstVector, const float _float) noexcept
	{
		return Vector3();
	}
}