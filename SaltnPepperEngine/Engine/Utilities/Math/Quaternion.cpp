/************************************************************************|
|						    Quaternion.cpp						     |
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

#include <Utilities/Math/Quaternion.hpp>
#include <Utilities/Math/Vectors/Vector2.hpp>

namespace SaltnPepperEngine::Maths
{

	Quaternion::Quaternion(const Vector4& _vector) noexcept
		//: XMFLOAT4(_vector.x, _vector.y, _vector.z, _vector.w)
	{}

	Quaternion::Quaternion(const Vector3& _vector, float _scalar) noexcept
		//: XMFLOAT4(_vector.x, _vector.y, _vector.z, _scalar)
	{}

	inline Quaternion& Quaternion::operator+=(const Quaternion& _quaternion) noexcept
	{
		using namespace DirectX;
		const XMVECTOR quatOne = XMLoadFloat4(this);
		const XMVECTOR quatTwo = XMLoadFloat4(&_quaternion);
		XMStoreFloat4(this, XMVectorAdd(quatOne, quatTwo));
		return *this;
	}

	inline Quaternion& Quaternion::operator-=(const Quaternion& _quaternion) noexcept
	{
		using namespace DirectX;
		const XMVECTOR quatOne = XMLoadFloat4(this);
		const XMVECTOR quatTwo = XMLoadFloat4(&_quaternion);
		XMStoreFloat4(this, XMVectorSubtract(quatOne, quatTwo));
		return *this;
	}

	inline Quaternion& Quaternion::operator*=(const Quaternion& _quaternion) noexcept
	{
		using namespace DirectX;
		const XMVECTOR quatOne = XMLoadFloat4(this);
		const XMVECTOR quatTwo = XMLoadFloat4(&_quaternion);
		XMStoreFloat4(this, XMQuaternionMultiply(quatOne, quatTwo));
		return *this;
	}

	Quaternion& Quaternion::operator*=(float _scalar) noexcept
	{
		using namespace DirectX;
		const XMVECTOR quat = XMLoadFloat4(this);
		XMStoreFloat4(this, XMVectorScale(quat, _scalar));
		return *this;
	}

	Quaternion& Quaternion::operator/=(const Quaternion& _quaternion) noexcept
	{
		using namespace DirectX;
		const XMVECTOR quatOne = XMLoadFloat4(this);
		XMVECTOR quatTwo = XMLoadFloat4(&_quaternion);
		quatTwo = XMQuaternionInverse(quatTwo);
		XMStoreFloat4(this, XMQuaternionMultiply(quatOne, quatTwo));
		return *this;
	}

	bool Quaternion::operator==(const Quaternion& _quaternion) const noexcept
	{
		using namespace DirectX;
		const XMVECTOR quatOne = XMLoadFloat4(this);
		const XMVECTOR quatTwo = XMLoadFloat4(&_quaternion);
		return XMQuaternionEqual(quatOne, quatTwo);
	}

	bool Quaternion::operator!=(const Quaternion& _quaternion) const noexcept
	{
		using namespace DirectX;
		const XMVECTOR quatOne = XMLoadFloat4(this);
		const XMVECTOR quatTwo = XMLoadFloat4(&_quaternion);
		return XMQuaternionNotEqual(quatOne, quatTwo);
	}

	Quaternion Quaternion::operator-() const noexcept
	{
		using namespace DirectX;
		const XMVECTOR quaternion = XMLoadFloat4(this);

		Quaternion quatResult;
		XMStoreFloat4(&quatResult, XMVectorNegate(quaternion));
		return quatResult;
	}

	Quaternion Quaternion::operator+() const noexcept
	{
		return *this;
	}

	Quaternion operator+(const Quaternion& _quatOne, const Quaternion& _quatTwo) noexcept
	{
		using namespace DirectX;
		const XMVECTOR quatOne = XMLoadFloat4(&_quatOne);
		const XMVECTOR quatTwo = XMLoadFloat4(&_quatTwo);

		Quaternion quatResult;
		XMStoreFloat4(&quatResult, XMVectorAdd(quatOne, quatTwo));
		return quatResult;
	}

	Quaternion operator-(const Quaternion& _quatOne, const Quaternion& _quatTwo) noexcept
	{
		using namespace DirectX;
		const XMVECTOR quatOne = XMLoadFloat4(&_quatOne);
		const XMVECTOR quatTwo = XMLoadFloat4(&_quatTwo);

		Quaternion quatResult;
		XMStoreFloat4(&quatResult, XMVectorSubtract(quatOne, quatTwo));
		return quatResult;
	}

	Quaternion operator*(const Quaternion& _quatOne, const Quaternion& _quatTwo) noexcept
	{
		using namespace DirectX;
		const XMVECTOR quatOne = XMLoadFloat4(&_quatOne);
		const XMVECTOR quatTwo = XMLoadFloat4(&_quatTwo);

		Quaternion quatResult;
		XMStoreFloat4(&quatResult, XMQuaternionMultiply(quatOne, quatTwo));
		return quatResult;
	}

	Quaternion operator*(const Quaternion& _quaternion, float _scalar) noexcept
	{
		using namespace DirectX;
		const XMVECTOR quaternion = XMLoadFloat4(&_quaternion);

		Quaternion quatResult;
		XMStoreFloat4(&quatResult, XMVectorScale(quaternion, _scalar));
		return quatResult;
	}

	Quaternion operator/(const Quaternion& _quatOne, const Quaternion& _quatTwo) noexcept
	{
		using namespace DirectX;
		const XMVECTOR quatOne = XMLoadFloat4(&_quatOne);
		XMVECTOR quatTwo = XMLoadFloat4(&_quatTwo);
		quatTwo = XMQuaternionInverse(quatTwo);

		Quaternion resultQuat;
		XMStoreFloat4(&resultQuat, XMQuaternionMultiply(quatOne, quatTwo));
		return resultQuat;
	}

	Quaternion operator*(float _scalar, const Quaternion& _quaternion) noexcept
	{
		using namespace DirectX;
		const XMVECTOR quaternion = XMLoadFloat4(&_quaternion);

		Quaternion resultQuat;
		XMStoreFloat4(&resultQuat, XMVectorScale(quaternion, _scalar));
		return resultQuat;
	}

}