// Copyright 2021 SMS
// License(Apache-2.0)

#pragma once

#include <cstddef>

template <typename T>
class Vector2T
{
public:
	/**
	 * @brief Ĭ�Ϲ��캯��.
	 */
	Vector2T() = default;

	/**
	 * @brief ���캯��.
	 *
	 * @param x x ����.
	 * @param y y ����.
	 */
	explicit Vector2T(const T& x, const T& y);

	/**
	 * @brief �������캯��.
	 */
	explicit Vector2T(const Vector2T& rhs);

	/**
	 * @brief ��ȡ����ƽ��.
	 *
	 * @see size
	 */
	T sizeSquared() const;

	/**
	 * @brief ��ȡ����.
	 *
	 * @see sizeSquared
	 */
	T size() const;

	/**
	 * @brief ��׼���ɵ�λ����.
	 */
	Vector2T& normalize();

	/**
	 * @brief ��ȡ��׼����λ����.
	 */
	Vector2T normalized() const;

    /**
	 * @brief �����������.
	 *
	 * @param v Ҫ��˵�����.
	 */
	T dot(const Vector2T& rhs) const;

    /**
	 * @brief �����������.
	 *
	 * @param v Ҫ��˵�����.
	 */
    T cross(const Vector2T& rhs) const;

    /**
	 * @brief ��ȡ�Ƕ�.
	 *
	 * @return �Ƕ�, ������. ��Χ: [2��, -2��)
	 */
    T angle() const;

    /**
	 * @brief Χ��ָ������תָ������.
	 *
	 * @param point ��.
	 * @param angle ��ת�Ƕ�, ������.
	 */
    void rotate(const Vector2T& point, float angle);

    T&       operator[](size_t index);
    const T& operator[](size_t index) const;

    bool      operator==(const Vector2T&) const;
    bool      operator!=(const Vector2T&) const;
    Vector2T& operator+=(const Vector2T&);
    Vector2T& operator-=(const Vector2T&);
    Vector2T& operator*=(const T&);
    Vector2T& operator/=(const T&);
    Vector2T  operator+(const Vector2T&) const;
    Vector2T  operator-(const Vector2T&) const;
    Vector2T  operator*(const T&) const;
    Vector2T  operator/(const T&) const;
    Vector2T  operator-() const;

	static const size_t components = 2;

    static const Vector2T unit;   // (1, 1)
    static const Vector2T unit_x; // (1, 0)
    static const Vector2T unit_y; // (0, 1)
    static const Vector2T zero;   // (0, 0)

    static const Vector2T up;    // (0, 1)
    static const Vector2T down;  // (0, -1)
    static const Vector2T right; // (1, 0)
    static const Vector2T left;  // (-1, 0)

private:
	T x, y;
};

#include "vector2.inl"

using Vector2f = Vector2T<float>;
using Vector2d = Vector2T<double>;
using Vector2i = Vector2T<int32_t>;
using Vector2  = Vector2f;