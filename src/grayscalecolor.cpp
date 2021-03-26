//	stationaryorbit.graphics-core:/grayscalecolor
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
#include "stationaryorbit/graphics-core/grayscalecolor.hpp"

template struct
zawa_ch::StationaryOrbit::Graphics::GrayScaleColor<zawa_ch::StationaryOrbit::Proportion1_t>;
template struct
zawa_ch::StationaryOrbit::Graphics::GrayScaleColor<zawa_ch::StationaryOrbit::Proportion8_t>;
template struct
zawa_ch::StationaryOrbit::Graphics::GrayScaleColor<zawa_ch::StationaryOrbit::Proportion16_t>;
template struct
zawa_ch::StationaryOrbit::Graphics::GrayScaleColor<zawa_ch::StationaryOrbit::Proportion32_t>;
template struct
zawa_ch::StationaryOrbit::Graphics::GrayScaleColor<zawa_ch::StationaryOrbit::Proportion64_t>;
template struct
zawa_ch::StationaryOrbit::Graphics::GrayScaleColor<zawa_ch::StationaryOrbit::FixedPoint16q15_t>;
template struct
zawa_ch::StationaryOrbit::Graphics::GrayScaleColor<zawa_ch::StationaryOrbit::FixedPoint32q31_t>;
template struct
zawa_ch::StationaryOrbit::Graphics::GrayScaleColor<zawa_ch::StationaryOrbit::FixedPoint64q63_t>;
template struct
zawa_ch::StationaryOrbit::Graphics::GrayScaleColor<float>;
template struct
zawa_ch::StationaryOrbit::Graphics::GrayScaleColor<double>;

// GrayScaleColorの型要件
static_assert(zawa_ch::StationaryOrbit::Graphics::ColorTraits::IsGrayScaleColorType<zawa_ch::StationaryOrbit::Graphics::GrayScale1_t>);
static_assert(zawa_ch::StationaryOrbit::Graphics::ColorTraits::IsGrayScaleColorType<zawa_ch::StationaryOrbit::Graphics::GrayScale8_t>);
static_assert(zawa_ch::StationaryOrbit::Graphics::ColorTraits::IsGrayScaleColorType<zawa_ch::StationaryOrbit::Graphics::GrayScale16_t>);
static_assert(zawa_ch::StationaryOrbit::Graphics::ColorTraits::IsGrayScaleColorType<zawa_ch::StationaryOrbit::Graphics::GrayScale32_t>);
static_assert(zawa_ch::StationaryOrbit::Graphics::ColorTraits::IsGrayScaleColorType<zawa_ch::StationaryOrbit::Graphics::GrayScale64_t>);
static_assert(zawa_ch::StationaryOrbit::Graphics::ColorTraits::IsGrayScaleColorType<zawa_ch::StationaryOrbit::Graphics::GrayScaleI16_t>);
static_assert(zawa_ch::StationaryOrbit::Graphics::ColorTraits::IsGrayScaleColorType<zawa_ch::StationaryOrbit::Graphics::GrayScaleI32_t>);
static_assert(zawa_ch::StationaryOrbit::Graphics::ColorTraits::IsGrayScaleColorType<zawa_ch::StationaryOrbit::Graphics::GrayScaleI64_t>);
static_assert(zawa_ch::StationaryOrbit::Graphics::ColorTraits::IsGrayScaleColorType<zawa_ch::StationaryOrbit::Graphics::GrayScaleF32_t>);
static_assert(zawa_ch::StationaryOrbit::Graphics::ColorTraits::IsGrayScaleColorType<zawa_ch::StationaryOrbit::Graphics::GrayScaleF64_t>);
