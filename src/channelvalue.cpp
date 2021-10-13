//	stationaryorbit.graphics-core:/channelvalue
//	Copyright 2020 zawa-ch.
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
#include "stationaryorbit/graphics-core/channelvalue.hpp"

template struct
zawa_ch::StationaryOrbit::Graphics::ChannelValue<zawa_ch::StationaryOrbit::Proportion8_t>;
template struct
zawa_ch::StationaryOrbit::Graphics::ChannelValue<zawa_ch::StationaryOrbit::Proportion16_t>;
template struct
zawa_ch::StationaryOrbit::Graphics::ChannelValue<zawa_ch::StationaryOrbit::Proportion32_t>;
template struct
zawa_ch::StationaryOrbit::Graphics::ChannelValue<zawa_ch::StationaryOrbit::Proportion64_t>;
template struct
zawa_ch::StationaryOrbit::Graphics::ChannelValue<zawa_ch::StationaryOrbit::FixedPoint16q15_t>;
template struct
zawa_ch::StationaryOrbit::Graphics::ChannelValue<zawa_ch::StationaryOrbit::FixedPoint32q31_t>;
template struct
zawa_ch::StationaryOrbit::Graphics::ChannelValue<zawa_ch::StationaryOrbit::FixedPoint64q63_t>;
template struct
zawa_ch::StationaryOrbit::Graphics::ChannelValue<float>;
template struct
zawa_ch::StationaryOrbit::Graphics::ChannelValue<double>;

// ChannelValueの型要件
// 値型である
// - デフォルトコンストラクタを持つ
// - デフォルトコンストラクタがnoexceptである
// - デフォルトコンストラクタがtrivialである
// - コピーコンストラクタを持つ
// - コピーコンストラクタがnoexceptである
// - コピーコンストラクタがtrivialである
// - ムーブコンストラクタを持つ
// - ムーブコンストラクタがnoexceptである
// - ムーブコンストラクタがtrivialである
// - コピー代入演算子を持つ
// - コピー代入演算子がnoexceptである
// - コピー代入演算子がtrivialである
// - ムーブ代入演算子を持つ
// - ムーブ代入演算子がnoexceptである
// - ムーブ代入演算子がtrivialである
// - デストラクタを持つ
// - デストラクタがnoexceptである
// - デストラクタがtrivialである
static_assert(zawa_ch::StationaryOrbit::ValueTypeTraits::is_valuetype<zawa_ch::StationaryOrbit::Graphics::Channel8_t>);
static_assert(zawa_ch::StationaryOrbit::ValueTypeTraits::is_valuetype<zawa_ch::StationaryOrbit::Graphics::Channel16_t>);
static_assert(zawa_ch::StationaryOrbit::ValueTypeTraits::is_valuetype<zawa_ch::StationaryOrbit::Graphics::Channel32_t>);
static_assert(zawa_ch::StationaryOrbit::ValueTypeTraits::is_valuetype<zawa_ch::StationaryOrbit::Graphics::Channel64_t>);
static_assert(zawa_ch::StationaryOrbit::ValueTypeTraits::is_valuetype<zawa_ch::StationaryOrbit::Graphics::ChannelI16_t>);
static_assert(zawa_ch::StationaryOrbit::ValueTypeTraits::is_valuetype<zawa_ch::StationaryOrbit::Graphics::ChannelI32_t>);
static_assert(zawa_ch::StationaryOrbit::ValueTypeTraits::is_valuetype<zawa_ch::StationaryOrbit::Graphics::ChannelI64_t>);
static_assert(zawa_ch::StationaryOrbit::ValueTypeTraits::is_valuetype<zawa_ch::StationaryOrbit::Graphics::ChannelF32_t>);
static_assert(zawa_ch::StationaryOrbit::ValueTypeTraits::is_valuetype<zawa_ch::StationaryOrbit::Graphics::ChannelF64_t>);
