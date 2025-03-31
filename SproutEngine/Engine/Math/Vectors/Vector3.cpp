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
 
namespace SproutEngine::Maths
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
		SPROUT_ASSERT(_scalar != 0.0f);

		const XMVECTOR thisVector = XMLoadFloat3(this);
		const XMVECTOR finalVector = XMVectorScale(thisVector, 1.0f / _scalar);

		XMStoreFloat3(this, finalVector);
		return *this;

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

	inline Vector3 Vector3::operator-() const noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat3(this);
		const XMVECTOR finalVector = XMVectorNegate(vectorOne);
		Vector3 result;
		XMStoreFloat3(&result, finalVector);
		return result;
	}

	inline Vector3 Vector3::operator+() const noexcept
	{
		return *this;
	}

	float Vector3::Length() const noexcept
	{
		using namespace DirectX;
		const XMVECTOR thisVector = XMLoadFloat3(this);
		const XMVECTOR finalVector = XMVector3LengthSq(thisVector);
		return XMVectorGetX(finalVector);
	}

	float Vector3::LengthSquared() const noexcept
	{
		using namespace DirectX;
		const XMVECTOR thisVector = XMLoadFloat3(this);
		const XMVECTOR finalVector = XMVector3LengthSq(thisVector);
		return XMVectorGetX(finalVector);
	}

	float Vector3::Distance(const Vector3& _firstVector, const Vector3& _secondVector) noexcept
	{
		using namespace DirectX;
		const XMVECTOR minVector = XMLoadFloat3(&_firstVector);
		const XMVECTOR maxVector = XMLoadFloat3(&_secondVector);
		const XMVECTOR vectorSubtract = XMVectorSubtract(maxVector, minVector);
		const XMVECTOR finalVector = XMVector3Length(vectorSubtract);
		return XMVectorGetX(finalVector);
	}

	float Vector3::DistanceSquared(const Vector3& _firstVector, const Vector3& _secondVector) noexcept
	{
		using namespace DirectX;
		const XMVECTOR minVector = XMLoadFloat3(&_firstVector);
		const XMVECTOR maxVector = XMLoadFloat3(&_secondVector);
		const XMVECTOR vectorSubtract = XMVectorSubtract(maxVector, minVector);
		const XMVECTOR finalVector = XMVector3LengthSq(vectorSubtract);
		return XMVectorGetX(finalVector);
	}

	void Vector3::Normalize() noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorThis = XMLoadFloat3(this);
		const XMVECTOR normalizedVector = XMVector3Normalize(vectorThis);
		XMStoreFloat3(this, normalizedVector);
	}

	void Vector3::Normalize(Vector3& _result) const noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorThis = XMLoadFloat3(this);
		const XMVECTOR normalizedVector = XMVector2Normalize(vectorThis);
		XMStoreFloat3(&_result, normalizedVector);
	}

	float Vector3::Dot(const Vector3& _otherVector) const noexcept
	{
		using namespace DirectX;
		const XMVECTOR thisvector = XMLoadFloat3(this);
		const XMVECTOR otherVector = XMLoadFloat3(&_otherVector);
		const XMVECTOR dotVector = XMVector3Dot(thisvector, otherVector);
		return XMVectorGetX(dotVector);
	}

	float Vector3::Cross(const Vector3& _otherVector) const noexcept
	{
		using namespace DirectX;
		const XMVECTOR thisvector = XMLoadFloat3(this);
		const XMVECTOR otherVector = XMLoadFloat3(&_otherVector);
		const XMVECTOR crossVector = XMVector3Cross(thisvector, otherVector);
		return XMVectorGetX(crossVector);
	}

	void Vector3::Lerp(const Vector3& _vectorOne, const Vector3& _vectorTwo, float _lerpFactor, Vector3& _result) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat3(&_vectorOne);
		const XMVECTOR vectorTwo = XMLoadFloat3(&_vectorTwo);
		const XMVECTOR lerpedVector = XMVectorLerp(vectorOne, vectorTwo, _lerpFactor);
		XMStoreFloat3(&_result, lerpedVector);
	}

	Vector3 Vector3::Lerp(const Vector3& _vectorOne, const Vector3& _vectorTwo, float _lerpFactor) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat3(&_vectorOne);
		const XMVECTOR vectorTwo = XMLoadFloat3(&_vectorTwo);
		const XMVECTOR lerpedVector = XMVectorLerp(vectorOne, vectorTwo, _lerpFactor);

		Vector3 result;
		XMStoreFloat3(&result, lerpedVector);
		return result;
	}

	void Vector3::Clamp(const Vector3& _vector, const Vector3& _vectorMin, const Vector3& _vectorMax, Vector3& _result) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vector = XMLoadFloat3(&_vector);
		const XMVECTOR vectorMin = XMLoadFloat3(&_vectorMin);
		const XMVECTOR vectorMax = XMLoadFloat3(&_vectorMax);
		const XMVECTOR clampedVector = XMVectorClamp(_vector, _vectorMin, _vectorMax);
		XMStoreFloat3(&_result, clampedVector);
	}

	Vector3 Vector3::Clamp(const Vector3& _vector, const Vector3& _vectorMin, const Vector3& _vectorMax) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vector = XMLoadFloat3(&_vector);
		const XMVECTOR vectorMin = XMLoadFloat3(&_vectorMin);
		const XMVECTOR vectorMax = XMLoadFloat3(&_vectorMax);
		const XMVECTOR clampedVector = XMVectorClamp(_vector, _vectorMin, _vectorMax);

		Vector3 result;
		XMStoreFloat3(&result, clampedVector);
		return result;
	}

	void Vector3::Min(const Vector3& _vectorOne, const Vector3& _vectorTwo, Vector3& _result) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat3(&_vectorOne);
		const XMVECTOR vectorTwo = XMLoadFloat3(&_vectorTwo);
		const XMVECTOR minVector = XMVectorMin(vectorOne, vectorTwo);
		XMStoreFloat3(&_result, minVector);
	}

	Vector3 Vector3::Min(const Vector3& _vectorOne, const Vector3& _vectorTwo) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat3(&_vectorOne);
		const XMVECTOR vectorTwo = XMLoadFloat3(&_vectorTwo);
		const XMVECTOR minVector = XMVectorMin(vectorOne, vectorTwo);

		Vector3 result;
		XMStoreFloat3(&result, minVector);
		return result;
	}

	void Vector3::Max(const Vector3& _vectorOne, const Vector3& _vectorTwo, Vector3& _result) noexcept
	{
	}

	Vector3 Vector3::Max(const Vector3& _vectorOne, const Vector3& _vectorTwo) noexcept
	{
		return Vector3();
	}

	void Vector3::SmoothStep(const Vector3& _vectorOne, const Vector3& _vectorTwo, float _stepFactor, Vector3& _result) noexcept
	{
	}

	Vector3 Vector3::SmoothStep(const Vector3& _vectorOne, const Vector3& _vectorTwo, float _stepFactor) noexcept
	{
		return Vector3();
	}


	Vector3 operator+(const Vector3& _firstVector, const Vector3& _secondVector) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat3(&_firstVector);
		const XMVECTOR vectorTwo = XMLoadFloat3(&_secondVector);
		const XMVECTOR addedVector = XMVectorAdd(vectorOne, vectorTwo);
		Vector3 finalVector;
		XMStoreFloat3(&finalVector, addedVector);
		return finalVector;
	}

	Vector3 operator-(const Vector3& _firstVector, const Vector3& _secondVector) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat3(&_firstVector);
		const XMVECTOR vectorTwo = XMLoadFloat3(&_secondVector);
		const XMVECTOR subtractedVector = XMVectorSubtract(vectorOne, vectorTwo);
		Vector3 finalVector;
		XMStoreFloat3(&finalVector, subtractedVector);
		return finalVector;
	}

	Vector3 operator*(const Vector3& _firstVector, const Vector3& _secondVector) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat3(&_firstVector);
		const XMVECTOR vectorTwo = XMLoadFloat3(&_secondVector);
		const XMVECTOR multipliedVector = XMVectorMultiply(vectorOne, vectorTwo);
		Vector3 finalVector;
		XMStoreFloat3(&finalVector, multipliedVector);
		return finalVector;
	}

	Vector3 operator*(const Vector3& _firstVector, const float _float) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat3(&_firstVector);
		const XMVECTOR multipliedVector = XMVectorScale(vectorOne, _float);

		Vector3 finalVector;
		XMStoreFloat3(&finalVector, multipliedVector);
		return finalVector;
	}

	Vector3 operator/(const Vector3& _firstVector, const Vector3& _secondVector) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat3(&_firstVector);
		const XMVECTOR vectorTwo = XMLoadFloat3(&_secondVector);
		const XMVECTOR dividedVector = XMVectorDivide(vectorOne, vectorTwo);
		Vector3 finalVector;
		XMStoreFloat3(&finalVector, dividedVector);
		return finalVector;
	}

	Vector3 operator/(const Vector3& _firstVector, const float _float) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat3(&_firstVector);
		const XMVECTOR multipliedVector = XMVectorScale(vectorOne, 1.0f / _float);

		Vector3 finalVector;
		XMStoreFloat3(&finalVector, multipliedVector);
		return finalVector;
	}
}