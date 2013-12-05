#ifndef __SERIALIZATION_TEMPLATES_H_
#define __SERIALIZATION_TEMPLATES_H_

#include <limits>
#include <cstdint>
#include <cstddef>
#include <cstring>

#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif

namespace openpal
{

template <class T>
class Bit16LE
{
public:
	static T Read(const uint8_t* apStart) {
		T ret = *(apStart);
		ret |= *(++apStart) << 8;
		return ret;
	}

	static void Write(uint8_t* apStart, T aValue) {
		*(apStart) = static_cast<uint8_t>(aValue & 0xFF);
		*(++apStart) = static_cast<uint8_t>((aValue >> 8) & 0xFF);
	}

	typedef T Type;

	const static size_t Size = sizeof(T);
	const static T Max;
	const static T Min;
};

template <class T>
const T Bit16LE<T>::Max = std::numeric_limits<T>::max();

template <class T>
const T Bit16LE<T>::Min = std::numeric_limits<T>::min();

template <class T>
class Bit32LE
{
public:
	static T Read(const uint8_t* apStart) {
		T  ret = *(apStart);
		ret |= *(++apStart) << 8;
		ret |= *(++apStart) << 16;
		ret |= *(++apStart) << 24;
		return ret;
	}
	static void Write(uint8_t* apStart, T aValue) {
		*(apStart) = static_cast<uint8_t>(aValue & 0xFF);
		*(++apStart) = static_cast<uint8_t>((aValue >> 8) & 0xFF);
		*(++apStart) = static_cast<uint8_t>((aValue >> 16) & 0xFF);
		*(++apStart) = static_cast<uint8_t>((aValue >> 24) & 0xFF);
	}

	typedef T Type;

	const static size_t Size = sizeof(T);
	const static T Max;
	const static T Min;
};

template <class T>
const T Bit32LE<T>::Max = std::numeric_limits<T>::max();

template <class T>
const T Bit32LE<T>::Min = std::numeric_limits<T>::min();

template <class T>
class Float
{
public:
	typedef T Type;

	const static size_t Size = sizeof(T);
	const static T Max;
	const static T Min;

protected:

	// Some platforms like ARM have WORD alignment issue when using reinterpret cast. 
	// The float/double read routines use intermediate buffer that the compiler word aligns
	inline static T SafeRead(const uint8_t* apStart) {
		T d;
		memcpy(&d, apStart, Size);
		return d;
	}

	inline static void SafeWrite(uint8_t* apStart, T aValue) {
		memcpy(apStart, &aValue, Size);
	}
};

template <class T>
const T Float<T>::Max = std::numeric_limits<T>::max();

template <class T>
const T Float<T>::Min = -std::numeric_limits<T>::max();

}

#endif