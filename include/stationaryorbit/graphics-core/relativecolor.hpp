//	stationaryorbit/graphics-core/relativecolor
//	Copyright 2020-2021 zawa-ch.
//	GPLv3 (or later) license
//
//	This program is free software: you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or
//	any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//	See the GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with this program.
//	If not, see <http://www.gnu.org/licenses/>.
//
#ifndef __stationaryorbit_graphics_core_relativecolor__
#define __stationaryorbit_graphics_core_relativecolor__
#include <array>
#include <functional>
#include "stationaryorbit/core.traits.hpp"
#include "colortraits.hpp"
#include "channelvalue.hpp"
namespace zawa_ch::StationaryOrbit::Graphics
{
	///	複数のチャネルで表される色を表します。
	///	@param	Tp
	///	チャネルの表現に用いる型。
	///	@param	N
	///	チャネルの数。
	template<class Tp, size_t N>
	struct RelativeColor final
	{
	public:
		///	チャネルの表現に使用されている型。
		typedef ChannelValue<Tp> ValueType;
		///	内部でデータの保持に用いている型。
		typedef std::array<ValueType, N> DataType;
	private:
		DataType _value;
	public:
		///	既定の @a RelativeColor のオブジェクトを構築します。
		RelativeColor() = default;
		constexpr explicit RelativeColor(const DataType& list) : _value(list) {}
		///	異なる @a ValueType を持つ @a RelativeColor から変換します。
		template<class fromT>
		constexpr explicit RelativeColor(const RelativeColor<fromT, N>& from) : _value(convert(from.Data())) {}
		///	@a ZeroValue_t から変換します。
		constexpr RelativeColor(const ZeroValue_t&) : RelativeColor(Expand(ValueType(Zero))) {}

		///	内部で保持しているデータを取得します。
		[[nodiscard]] constexpr const DataType& Data() const { return _value; }
		///	このオブジェクトが正規化された値を持つかを取得します。
		[[nodiscard]] constexpr bool IsNormalized() const noexcept
		{
			for(const auto& item: _value) { if (!item.IsNormalized()) { return false; } }
			return true;
		}
		///	このオブジェクトを正規化します。
		[[nodiscard]] constexpr RelativeColor<Tp, N> Normalize() const noexcept { return Apply([](const auto& item)->ValueType { return item.Normalize(); }); }

		[[nodiscard]] constexpr RelativeColor<Tp, N> SaturateAdd(const RelativeColor<Tp, N>& other) const noexcept { return Merge(other, [](const auto& item, const auto& value)->ValueType { return ArithmeticOperation::add_saturate(item, value); }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> SaturateSubtract(const RelativeColor<Tp, N>& other) const noexcept { return Merge(other, [](const auto& item, const auto& value)->ValueType { return ArithmeticOperation::subtract_saturate(item, value); }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> SaturateMultiply(const RelativeColor<Tp, N>& other) const noexcept { return Merge(other, [](const auto& item, const auto& value)->ValueType { return ArithmeticOperation::multiply_saturate(item, value); }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> SaturateMultiply(const ValueType& other) const noexcept { return Merge(other, [](const auto& item, const auto& value)->ValueType { return ArithmeticOperation::multiply_saturate(item, value); }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> SaturateDivide(const RelativeColor<Tp, N>& other) const noexcept { return Merge(other, [](const auto& item, const auto& value)->ValueType { return ArithmeticOperation::divide_saturate(item, value); }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> SaturateDivide(const ValueType& other) const noexcept { return Merge(other, [](const auto& item, const auto& value)->ValueType { return ArithmeticOperation::divide_saturate(item, value); }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> CheckedAdd(const RelativeColor<Tp, N>& other) const { return Merge(other, [](const auto& item, const auto& value)->ValueType { return ArithmeticOperation::add_checked(item, value); }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> CheckedSubtract(const RelativeColor<Tp, N>& other) const { return Merge(other, [](const auto& item, const auto& value)->ValueType { return ArithmeticOperation::subtract_checked(item, value); }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> CheckedMultiply(const RelativeColor<Tp, N>& other) const { return Merge(other, [](const auto& item, const auto& value)->ValueType { return ArithmeticOperation::multiply_checked(item, value); }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> CheckedMultiply(const ValueType& other) const { return Merge(other, [](const auto& item, const auto& value)->ValueType { return ArithmeticOperation::multiply_checked(item, value); }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> CheckedDivide(const RelativeColor<Tp, N>& other) const { return Merge(other, [](const auto& item, const auto& value)->ValueType { return ArithmeticOperation::divide_checked(item, value); }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> CheckedDivide(const ValueType& other) const { return Merge(other, [](const auto& item, const auto& value)->ValueType { return ArithmeticOperation::divide_checked(item, value); }); }
		[[nodiscard]] constexpr bool Equals(const RelativeColor<Tp, N>& other) const noexcept
		{
			auto ti = _value.cbegin();
			auto oi = other._value.cbegin();
			auto te = _value.cend();
			auto oe = other._value.cend();
			while((ti != te) && (oi != oe))
			{
				if (!ti->Equals(*oi)) { return false; }
				++ti;
				++oi;
			}
			return true;
		}

		[[nodiscard]] constexpr RelativeColor<Tp, N> operator+() const noexcept { return Apply([](const auto& item)->ValueType { return +item; }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> operator-() const noexcept { return Apply([](const auto& item)->ValueType { return -item; }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> operator+(const RelativeColor<Tp, N>& other) const noexcept { return Merge(other, [](const auto& item, const auto& value)->ValueType { return item + value; }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> operator-(const RelativeColor<Tp, N>& other) const noexcept { return Merge(other, [](const auto& item, const auto& value)->ValueType { return item - value; }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> operator*(const RelativeColor<Tp, N>& other) const noexcept { return Merge(other, [](const auto& item, const auto& value)->ValueType { return item * value; }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> operator*(const ValueType& other) const noexcept { return Merge(other, [](const auto& item, const auto& value)->ValueType { return item * value; }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> operator/(const RelativeColor<Tp, N>& other) const noexcept { return Merge(other, [](const auto& item, const auto& value)->ValueType { return item / value; }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> operator/(const ValueType& other) const noexcept { return Merge(other, [](const auto& item, const auto& value)->ValueType { return item / value; }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> operator&(const RelativeColor<Tp, N>& other) const noexcept { return Merge(other, [](const auto& item, const auto& value)->ValueType { return item & value; }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> operator|(const RelativeColor<Tp, N>& other) const noexcept { return Merge(other, [](const auto& item, const auto& value)->ValueType { return item | value; }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> operator~() const noexcept { return Apply([](const auto& item)->ValueType { return ~item; }); }
		[[nodiscard]] constexpr RelativeColor<Tp, N> operator^(const RelativeColor<Tp, N>& other) const noexcept { return Merge(other, [](const auto& item, const auto& value)->ValueType { return item ^ value; }); }
		constexpr RelativeColor<Tp, N>& operator+=(const RelativeColor<Tp, N>& other) noexcept { return *this = (*this) + (other); }
		constexpr RelativeColor<Tp, N>& operator-=(const RelativeColor<Tp, N>& other) noexcept { return *this = (*this) - (other); }
		constexpr RelativeColor<Tp, N>& operator*=(const RelativeColor<Tp, N>& other) noexcept { return *this = (*this) * (other); }
		constexpr RelativeColor<Tp, N>& operator*=(const ValueType& other) noexcept { return *this = (*this) * (other); }
		constexpr RelativeColor<Tp, N>& operator/=(const RelativeColor<Tp, N>& other) noexcept { return *this = (*this) / (other); }
		constexpr RelativeColor<Tp, N>& operator/=(const ValueType& other) noexcept { return *this = (*this) / (other); }
		constexpr RelativeColor<Tp, N>& operator&=(const RelativeColor<Tp, N>& other) noexcept { return *this = (*this) & (other); }
		constexpr RelativeColor<Tp, N>& operator|=(const RelativeColor<Tp, N>& other) noexcept { return *this = (*this) | (other); }
		constexpr RelativeColor<Tp, N>& operator^=(const RelativeColor<Tp, N>& other) noexcept { return *this = (*this) ^ (other); }
		[[nodiscard]] constexpr bool operator==(const RelativeColor<Tp, N>& other) const noexcept { return Equals(other); }
		[[nodiscard]] constexpr bool operator!=(const RelativeColor<Tp, N>& other) const noexcept { return !Equals(other); }

		///	このオブジェクトに指定された述語を適用します。
		///	@param	pred
		///	適用する述語。
		[[nodiscard]] constexpr RelativeColor<Tp, N> Apply(const std::function<ValueType(const ValueType&)>& pred) const
		{
			auto result = RelativeColor<Tp, N>();
			auto si = _value.cbegin();
			auto di = result._value.begin();
			auto se = _value.cend();
			auto de = result._value.end();
			while((si != se) && (di != de))
			{
				*di = pred(*si);
				++di;
				++si;
			}
			return result;
		}
		///	指定した述語を適用してふたつのオブジェクトをマージします。
		///	@param	other
		///	マージするオブジェクト。
		///	@param	pred
		///	適用する述語。
		[[nodiscard]] constexpr RelativeColor<Tp, N> Merge(const RelativeColor<Tp, N>& other, const std::function<ValueType(const ValueType&, const ValueType&)>& pred) const
		{
			auto result = RelativeColor<Tp, N>();
			auto s1i = _value.cbegin();
			auto s2i = other._value.cbegin();
			auto di = result._value.begin();
			auto s1e = _value.cend();
			auto s2e = other._value.cend();
			auto de = result._value.end();
			while((s1i != s1e) && (s2i != s2e) && (di != de))
			{
				*di = pred(*s1i, *s2i);
				++di;
				++s1i;
				++s2i;
			}
			return result;
		}
		///	指定した述語を適用してふたつのオブジェクトをマージします。
		///	@param	value
		///	マージするオブジェクト。
		///	@param	pred
		///	適用する述語。
		[[nodiscard]] constexpr RelativeColor<Tp, N> Merge(const ValueType& value, const std::function<ValueType(const ValueType&, const ValueType&)>& pred) const
		{
			auto result = RelativeColor<Tp, N>();
			auto si = _value.cbegin();
			auto di = result._value.begin();
			auto se = _value.cend();
			auto de = result._value.end();
			while((si != se) && (di != de))
			{
				*di = pred(*si, value);
				++di;
				++si;
			}
			return result;
		}

		///	すべてのチャネルが指定された値をもつ @a RelativeColor オブジェクトを生成します。
		///	@param	value
		///	構築する値。
		[[nodiscard]] static constexpr RelativeColor<Tp, N> Expand(const ValueType& value)
		{
			auto result = RelativeColor<Tp, N>();
			for(auto& item: result._value)
			{
				item = value;
			}
			return result;
		}
	private:
		template<class fromT>
		static constexpr std::array<ValueType, N> convert(const std::array<fromT, N>& valuelist)
		{
			auto result = std::array<ValueType, N>();
			auto si = valuelist.cbegin();
			auto di = result.begin();
			auto se = valuelist.cend();
			auto de = result.end();
			while((si != se) && (di != de))
			{
				*di = ValueType(*si);
				++di;
				++si;
			}
			return result;
		}
	};
}
#endif // __stationaryorbit_graphics_core_relativecolor__
