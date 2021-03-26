# stationaryorbit.graphics-core

[stationaryorbit](https://github.com/zawa-ch/stationaryorbit) » graphics-core

![Lisence](https://img.shields.io/github/license/zawa-ch/stationaryorbit.graphics-core)
![Lines of code](https://img.shields.io/tokei/lines/github/zawa-ch/stationaryorbit.graphics-core)

簡単なことを簡単に行うためのライブラリ

## 概要

stationaryorbit.graphics-core は画像の操作を行うための基本的なライブラリです。  
このソースのビルドにはC++17に準拠したコンパイラが必要になります。  

## このライブラリでできること

- 色の表現  
  グレースケール/RGB/CMY/CMYK/YUV/XYZ  
  8/16/32/64bit 整数  
  1.15/1.31/1.63bit 固定小数点数  
  32/64bit 浮動小数点数  
- 色の合成(`ColorBlender`/`ColorCompositer`)
- 画像の表現(`Pixmap`/`PixArray`)
- 画像の反転(`ImageHorizonalFlip`/`ImageVerticalFlip`)
- 画像のスケーリング(`ImageScaling`)

## 依存

- stationaryorbit.core

## ライセンス

このライブラリは、GNU一般公衆ライセンス v3.0(GPLv3)、またはそれ以降のライセンスで提供されます。  
ライセンスに関する詳細は[LISENCE](./LICENSE)ファイル、または[ライセンス - GNUプロジェクト](http://www.gnu.org/licenses/)のページをご確認ください。  

## 注意: 開発中のリポジトリ

現在このリポジトリは開発中です。そのため、オブジェクトの名前および配置が大きく変化する可能性があります。  
同様の理由で、ドキュメント等も不十分な可能性があります。  
