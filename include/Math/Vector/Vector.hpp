﻿// Copyright 2021 SMS
// License(Apache-2.0)

#pragma once

#include <cstddef>
#include <initializer_list>
#include <type_traits>
#include <iostream>

/**
 * @brief N 维向量.
 *
 * @tparam T 数据类型.
 * @tparam N 维数.
 */
template <typename T, size_t N> requires std::is_arithmetic_v<T>
class VectorT
{
public:
	/**
	 * @brief 默认构造函数.
	 */
	VectorT() = default;

	/**
	 * @brief 构造函数.
	 */
	constexpr explicit VectorT(const T& scalar);

	/**
	 * @brief 构造函数.
	 *
	 * @param list 初始化列表, 下标依次为 0 到 N-1.
	 */
	constexpr VectorT(const std::initializer_list<T>& list);

	/**
	 * @brief 获取模.
	 *
	 * @see normSquared
	 */
	T norm() const;

	/**
	 * @brief 获取模的平方.
	 *
	 * @see norm
	 */
	constexpr T normSquared() const;

	/**
	 * @brief 标准化成单位向量.
	 *
	 * @warning 当向量大小太小时, 将会不进行标准化.
	 */
	VectorT& normalize();

	/**
	 * @brief 获取标准化单位向量.
	 *
	 * @warning 当向量大小太小时, 将会不进行标准化.
	 */
	VectorT normalized() const;

	/**
	 * @brief 计算向量点积.
	 *
	 * @param rhs 要点乘的向量.
	 */
	constexpr T dot(const VectorT& rhs) const;

	/**
	 * @brief 计算向量叉积.
	 *
	 * @param rhs 要叉乘的向量.
	 */
	constexpr VectorT cross(const VectorT& rhs) const;

	/**
	 * @brief 获取所有元素之和.
	 */
	constexpr T sum() const;

	/**
	 * @brief 裁剪到指定范围内.
	 *
	 * @param min 最小值.
	 * @param max 最大值.
	 */
	void clamp(const VectorT& min, const VectorT& max);

	/**
	 * @brief 获取原始数据.
	 */
	constexpr T* data();
	constexpr const T* data() const;

	constexpr T& operator[](size_t index);
	constexpr const T& operator[](size_t index) const;

	constexpr bool     operator==(const VectorT&) const;
	constexpr VectorT& operator+=(const VectorT&);
	constexpr VectorT& operator-=(const VectorT&);
	constexpr VectorT& operator*=(const T&);
	constexpr VectorT& operator/=(const T&);
	constexpr VectorT  operator-() const;

	template <typename C>
	operator VectorT<C, N>()
	{
		VectorT<C, N> result;
		for(size_t i = 0; i < N; i++)
			result[i] = static_cast<C>(v_[i]);
		return result;
	}

	friend std::ostream& operator<<(std::ostream& stream, const VectorT& vec)
	{
		for(size_t i = 0; i < N - 1; i++)
			stream << vec[i] << ' ';
		stream << vec[N - 1];
		return stream;
	}

	static constexpr size_t components = N;

private:
	T v_[N] = {};
};

#include "Vector.inl"

template <size_t N>
using Vectorf = VectorT<float, N>;

template <size_t N>
using Vectord = VectorT<float, N>;

template <size_t N>
using Vectori = VectorT<int32_t, N>;

template <typename T, size_t N>
VectorT<T, N> constexpr operator+(const VectorT<T, N>& lhs, const VectorT<T, N>& rhs)
{
	return VectorT(lhs) += rhs;
}

template <typename T, size_t N>
VectorT<T, N> constexpr operator-(const VectorT<T, N>& lhs, const VectorT<T, N>& rhs)
{
	return VectorT(lhs) -= rhs;
}

template <typename T, size_t N>
VectorT<T, N> constexpr operator*(const VectorT<T, N>& lhs, const VectorT<T, N>& rhs)
{
	return VectorT(lhs) *= rhs;
}

template <typename T, size_t N>
VectorT<T, N> constexpr operator/(const VectorT<T, N>& lhs, const VectorT<T, N>& rhs)
{
	return VectorT(lhs) /= rhs;
}

template <typename T, size_t N>
VectorT<T, N> constexpr operator*(const VectorT<T, N>& lhs, const T& rhs)
{
	return VectorT(lhs) *= rhs;
}

template <typename T, size_t N>
VectorT<T, N> constexpr operator/(const VectorT<T, N>& lhs, const T& rhs)
{
	return VectorT(lhs) /= rhs;
}

template <typename T, size_t N>
VectorT<T, N> constexpr operator*(const T& lhs, const VectorT<T, N>& rhs)
{
	return rhs * lhs;
}

template <typename T, size_t N>
VectorT<T, N> constexpr operator/(const T& lhs, const VectorT<T, N>& rhs)
{
	return rhs / lhs;
}

/**
 * @class VectorT
 *
 * @details 大小固定的向量, 可以用于表示位置/速度/方向等.
 *
 * 例子:
 * @code{cpp}
 *
 * // 创建
 * Vector2i v(1, 2); // 创建一个 2 维向量, 类型为 int32_t, 初始值为 (1, 2)
 *
 * // 操作
 * v.x = 3;  // 设置 x 分量为 3
 * v[1] = 4; // 设置 y 分量为 4
 * std::cout << v.size() << std::endl; // 输出向量的长度, 结果为: 5
 *
 * @endcode
 */
