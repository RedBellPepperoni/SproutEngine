/************************************************************************|
|							     MathFunctions.hpp						     |
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

#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H

/// <summary>
/// General purpose wrapper over Direct X math 
/// </summary>
/// 

#include <DirectXMath.h>
#include <cstdlib>
#include <cmath>
#include <limits>

using namespace DirectX;

namespace SaltnPepperEngine
{

	namespace Math
	{
		/// Pi values
		static constexpr float PI = XM_PI;
		static constexpr float TwoPI = XM_2PI;
		static constexpr float OnebyPI = XM_1DIVPI;
		static constexpr float OnebyTwoPI = XM_1DIV2PI;
		static constexpr float PIbyTwo = XM_PIDIV2;
		static constexpr float PIbyFour = XM_PIDIV4;

		/// Int Values
		static constexpr int MaxInt = 0x7fffffff;
		static constexpr int MinInt = 0x80000000;
		static constexpr int MaxIntUnsigned = 0xffffffff;
		static constexpr int MinIntUnsigned = 0x00000000;

		/// LArge and Small Values
		static constexpr float Epsilon = 0.000001f;
		static constexpr float LargeEpsilon = 0.00005f;
		static constexpr float Infinity = std::numeric_limits<float>::infinity();



		/// Unit Conversions : Angle
		static inline constexpr float ToRadians(const float _degrees) noexcept
		{
			return _degrees * (PI / 180.0f);
		}

		static inline constexpr float ToDegrees(const float _radians) noexcept
		{
			return _radians * (180.0f / PI);
		}

		/// Trignometry Functions : Single Precision
		static inline  float Sin   (float _value) { return	 XMScalarSin(_value); }
		static inline  float Cos   (float _value) { return	 XMScalarCos(_value); }
		static inline  float Tan   (float _value) { return ::tanf(_value); }

		static inline  float SinH  (float _value) { return ::sinhf(_value); }
		static inline  float CosH  (float _value) { return ::tanhf(_value); }
		static inline  float TanH  (float _value) { return ::coshf(_value); }

		static inline  float ASin  (float _value) { return	 XMScalarASin(_value); }
		static inline  float ACos  (float _value) { return	 XMScalarACos(_value); }

		static inline  float ATan  (float _value) { return ::atanf(_value); }
		static inline  float ATan2 (float _valueY, float _valueX) { return ::atan2f(_valueY,_valueX); }


		/// Trignometry Functions : Double Precision
		static inline  double Sin	(double _value) { return ::sin(_value); }
		static inline  double Cos	(double _value) { return ::cos(_value); }
		static inline  double Tan	(double _value) { return ::tan(_value); }

		static inline  double SinH	(double _value) { return ::sinh(_value); }
		static inline  double CosH	(double _value) { return ::tanh(_value); }
		static inline  double TanH	(double _value) { return ::cosh(_value); }
		
		// Clamping the value 
		static inline  double ASin	(double _value) { return (_value < -1) ? (-PI / 2) : ((_value > 1) ? (PI / 2) : ::asin(_value));}
		static inline  double ACos	(double _value) { return (_value < -1) ? PI : ((_value > 1) ? 0 : ::acos(_value)); }

		static inline  double ATan	(double _value) { return ::atanf(_value); }
		static inline  double ATan2 (double _valueY, double _valueX) { return ::atan2f(_valueY, _valueX); }

	}
}

#endif // !MATHFUNCTIONS_H
