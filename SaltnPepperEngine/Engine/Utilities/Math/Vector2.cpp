/************************************************************************|
|							     Vector2.cpp						     |
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


#include <Utilities/Math/Vector2.hpp>


namespace SaltnPepperEngine::Maths
{
	/// Vector 2 Stuff

	inline Vector2& Vector2::operator+=(const Vector2& _vector) noexcept
	{
		using namespace DirectX;

		const XMVECTOR thisVector = XMLoadFloat2(this);
		const XMVECTOR inVector = XMLoadFloat2(&_vector);
		const XMVECTOR finalVector = XMVectorAdd(thisVector, inVector);

		XMStoreFloat2(this, finalVector);
		return *this;
	}

	inline Vector2& Vector2::operator-=(const Vector2& _vector) noexcept
	{
		using namespace DirectX;

		const XMVECTOR thisVector = XMLoadFloat2(this);
		const XMVECTOR inVector = XMLoadFloat2(&_vector);
		const XMVECTOR finalVector = XMVectorSubtract(thisVector, inVector);

		XMStoreFloat2(this, finalVector);
		return *this;
	}

	inline Vector2& Vector2::operator*=(const Vector2& _vector) noexcept
	{
		using namespace DirectX;

		const XMVECTOR thisVector = XMLoadFloat2(this);
		const XMVECTOR inVector = XMLoadFloat2(&_vector);
		const XMVECTOR finalVector = XMVectorMultiply(thisVector, inVector);

		XMStoreFloat2(this, finalVector);
		return *this;
	}

	// Questionable if vector division is gonna be used 
	// But using an operator overload anyway
	inline Vector2& Vector2::operator/=(const Vector2& _vector) noexcept
	{
		using namespace DirectX;

		const XMVECTOR thisVector = XMLoadFloat2(this);
		const XMVECTOR inVector = XMLoadFloat2(&_vector);
		const XMVECTOR finalVector = XMVectorDivide(thisVector, inVector);

		XMStoreFloat2(this, finalVector);
		return *this;
	}

	

	inline Vector2& Vector2::operator*=(const float _float) noexcept
	{
		using namespace DirectX;

		const XMVECTOR thisVector = XMLoadFloat2(this);
		const XMVECTOR finalVector = XMVectorScale(thisVector, _float);

		XMStoreFloat2(this, finalVector);
		return *this;
	}

	inline Vector2& Vector2::operator/=(const float _float) noexcept
	{
		using namespace DirectX;

		const XMVECTOR thisVector = XMLoadFloat2(this);
		const XMVECTOR finalVector = XMVectorScale(thisVector, 1.0f / _float);

		XMStoreFloat2(this, finalVector);
		return *this;
	}


	
	inline bool Vector2::operator==(const Vector2& _vector) const noexcept
	{
		using namespace DirectX;

		const XMVECTOR thisVector = XMLoadFloat2(this);
		const XMVECTOR inVector = XMLoadFloat2(&_vector);
		return XMVector2Equal(thisVector, inVector);
	}

	inline bool Vector2::operator!=(const Vector2& _vector) const noexcept
	{
		using namespace DirectX;

		const XMVECTOR thisVector = XMLoadFloat2(this);
		const XMVECTOR inVector = XMLoadFloat2(&_vector);
		return XMVector2NotEqual(thisVector, inVector);
	}

	Vector2 Vector2::operator-() const noexcept
	{
		return Vector2{ -this->x,-this->y };
	}

	Vector2 Vector2::operator+() const noexcept
	{
		return *this;
	}

	
	float Vector2::Length() const noexcept
	{
		using namespace DirectX;
		const XMVECTOR thisVector = XMLoadFloat2(this);
		const XMVECTOR finalVector = XMVector2LengthSq(thisVector);
		return XMVectorGetX(finalVector);
	}

	float  Vector2::LengthSquared() const noexcept
	{
		using namespace DirectX;
		const XMVECTOR thisVector = XMLoadFloat2(this);
		const XMVECTOR finalVector = XMVector2LengthSq(thisVector);
		return XMVectorGetX(finalVector);
	}

	float Vector2::Distance(const Vector2& _firstVector, const Vector2& _secondVector) noexcept
	{
		using namespace DirectX;
		const XMVECTOR minVector = XMLoadFloat2(&_firstVector);
		const XMVECTOR maxVector = XMLoadFloat2(&_secondVector);
		const XMVECTOR vectorSubtract = XMVectorSubtract(maxVector, minVector);
		const XMVECTOR finalVector = XMVector2Length(vectorSubtract);
		return XMVectorGetX(finalVector);
	}

	float Vector2::DistanceSquared(const Vector2& _firstVector, const Vector2& _secondVector) noexcept
	{
		using namespace DirectX;
		const XMVECTOR minVector = XMLoadFloat2(&_firstVector);
		const XMVECTOR maxVector = XMLoadFloat2(&_secondVector);
		const XMVECTOR vectorSubtract = XMVectorSubtract(maxVector, minVector);
		const XMVECTOR finalVector = XMVector2LengthSq(vectorSubtract);
		return XMVectorGetX(finalVector);
		
	}

	// Cannot Inline this for some weird reason
	

	Vector2 operator+(const Vector2& _firstVector, const Vector2& _secondVector) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat2(&_firstVector);
		const XMVECTOR vectorTwo = XMLoadFloat2(&_secondVector);
		const XMVECTOR addedVector = XMVectorAdd(vectorOne, vectorTwo);
		Vector2 finalVector;
		XMStoreFloat2(&finalVector, addedVector);
		return finalVector;
	}

	// Cannot Inline this for some weird reason
	Vector2 operator-(const Vector2& _firstVector, const Vector2& _secondVector) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat2(&_firstVector);
		const XMVECTOR vectorTwo = XMLoadFloat2(&_secondVector);
		const XMVECTOR subtractedVector = XMVectorSubtract(vectorOne, vectorTwo);
		Vector2 finalVector;
		XMStoreFloat2(&finalVector, subtractedVector);
		return finalVector;
	}

	Vector2 operator*(const Vector2& _firstVector, const Vector2& _secondVector) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat2(&_firstVector);
		const XMVECTOR vectorTwo = XMLoadFloat2(&_secondVector);
		const XMVECTOR multipliedVector = XMVectorMultiply(vectorOne, vectorTwo);
		Vector2 finalVector;
		XMStoreFloat2(&finalVector, multipliedVector);
		return finalVector;
	}

	Vector2 operator*(const Vector2& _firstVector, const float _float) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat2(&_firstVector);
		const XMVECTOR multipliedVector = XMVectorScale(vectorOne,_float);
		
		Vector2 finalVector;
		XMStoreFloat2(&finalVector, multipliedVector);
		return finalVector;
	}

	Vector2 operator/(const Vector2& _firstVector, const Vector2& _secondVector) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat2(&_firstVector);
		const XMVECTOR vectorTwo = XMLoadFloat2(&_secondVector);
		const XMVECTOR dividedVector = XMVectorDivide(vectorOne, vectorTwo);
		Vector2 finalVector;
		XMStoreFloat2(&finalVector, dividedVector);
		return finalVector;
	}

	Vector2 operator/(const Vector2& _firstVector, const float _float) noexcept
	{
		using namespace DirectX;
		const XMVECTOR vectorOne = XMLoadFloat2(&_firstVector);
		const XMVECTOR multipliedVector = XMVectorScale(vectorOne, 1.0f / _float);

		Vector2 finalVector;
		XMStoreFloat2(&finalVector, multipliedVector);
		return finalVector;
	}

	/// !End of Vector 2 Stuff
}