/*
 * Copyright (C) 2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License")
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#include <ignition/math/Helpers.hh>
#include "gazebo/common/TemperaturePrivate.hh"
#include "gazebo/common/Temperature.hh"

using namespace gazebo;
using namespace common;

/////////////////////////////////////////////////
Temperature::Temperature()
: dataPtr(new TemperaturePrivate)
{
}

/////////////////////////////////////////////////
Temperature::Temperature(const double _temp)
: dataPtr(new TemperaturePrivate(_temp))
{
}

/////////////////////////////////////////////////
Temperature::Temperature(const Temperature &_temp)
: dataPtr(new TemperaturePrivate(_temp.Kelvin()))
{
}

/////////////////////////////////////////////////
double Temperature::KelvinToCelsius(const double _temp)
{
  return _temp - 273.15;
}

/////////////////////////////////////////////////
double Temperature::KelvinToFarenheit(const double _temp)
{
  return _temp * 1.8 - 459.67;
}

/////////////////////////////////////////////////
double Temperature::CelsiusToFarenheit(const double _temp)
{
  return _temp * 1.8 + 32.0;
}

/////////////////////////////////////////////////
double Temperature::CelsiusToKelvin(const double _temp)
{
  return std::max(_temp + 273.15, 0.0);
}

/////////////////////////////////////////////////
double Temperature::FarenheitToCelsius(const double _temp)
{
  return (_temp - 32.0) / 1.8;
}

/////////////////////////////////////////////////
double Temperature::FarenheitToKelvin(const double _temp)
{
  return std::max((_temp + 459.67) / 1.8, 0.0);
}

/////////////////////////////////////////////////
void Temperature::SetKelvin(const double _temp)
{
  this->dataPtr->kelvin = std::max(_temp, 0.0);
}

/////////////////////////////////////////////////
void Temperature::SetCelsius(const double _temp)
{
  this->SetKelvin(CelsiusToKelvin(_temp));
}

/////////////////////////////////////////////////
void Temperature::SetFarenheit(const double _temp)
{
  this->SetKelvin(FarenheitToKelvin(_temp));
}

/////////////////////////////////////////////////
double Temperature::Kelvin() const
{
  return this->dataPtr->kelvin;
}

/////////////////////////////////////////////////
double Temperature::Celsius() const
{
  return KelvinToCelsius(this->dataPtr->kelvin);
}

/////////////////////////////////////////////////
double Temperature::Farenheit() const
{
  return KelvinToFarenheit(this->dataPtr->kelvin);
}

/////////////////////////////////////////////////
double Temperature::operator()() const
{
  return this->dataPtr->kelvin;
}

/////////////////////////////////////////////////
Temperature &Temperature::operator=(const double _temp)
{
  this->SetKelvin(_temp);
  return *this;
}

/////////////////////////////////////////////////
Temperature &Temperature::operator=(const Temperature &_temp)
{
  this->SetKelvin(_temp.Kelvin());
  return *this;
}

/////////////////////////////////////////////////
Temperature Temperature::operator+(const double _temp)
{
  return Temperature(this->dataPtr->kelvin + _temp);
}

/////////////////////////////////////////////////
Temperature Temperature::operator+(const Temperature &_temp)
{
  return Temperature(this->dataPtr->kelvin + _temp.Kelvin());
}

/////////////////////////////////////////////////
Temperature &Temperature::operator+=(const double _temp)
{
  this->dataPtr->kelvin += _temp;
  return *this;
}

/////////////////////////////////////////////////
Temperature &Temperature::operator+=(const Temperature &_temp)
{
  this->dataPtr->kelvin += _temp.Kelvin();
  return *this;
}

/////////////////////////////////////////////////
Temperature Temperature::operator-(const double _temp)
{
  return Temperature(this->dataPtr->kelvin - _temp);
}

/////////////////////////////////////////////////
Temperature Temperature::operator-(const Temperature &_temp)
{
  return Temperature(this->dataPtr->kelvin - _temp.Kelvin());
}

/////////////////////////////////////////////////
Temperature &Temperature::operator-=(const double _temp)
{
  this->dataPtr->kelvin -= _temp;
  return *this;
}

/////////////////////////////////////////////////
Temperature &Temperature::operator-=(const Temperature &_temp)
{
  this->dataPtr->kelvin -= _temp.Kelvin();
  return *this;
}

/////////////////////////////////////////////////
Temperature Temperature::operator*(const double _temp)
{
  return Temperature(this->dataPtr->kelvin * _temp);
}

/////////////////////////////////////////////////
Temperature Temperature::operator*(const Temperature &_temp)
{
  return Temperature(this->dataPtr->kelvin * _temp.Kelvin());
}

/////////////////////////////////////////////////
Temperature &Temperature::operator*=(const double _temp)
{
  this->dataPtr->kelvin *= _temp;
  return *this;
}

/////////////////////////////////////////////////
Temperature &Temperature::operator*=(const Temperature &_temp)
{
  this->dataPtr->kelvin *= _temp.Kelvin();
  return *this;
}

/////////////////////////////////////////////////
Temperature Temperature::operator/(const double _temp)
{
  return Temperature(this->dataPtr->kelvin /= _temp);
}

/////////////////////////////////////////////////
Temperature Temperature::operator/(const Temperature &_temp)
{
  return Temperature(this->dataPtr->kelvin /= _temp.Kelvin());
}

/////////////////////////////////////////////////
Temperature &Temperature::operator/=(const double _temp)
{
  this->dataPtr->kelvin /= _temp;
  return *this;
}

/////////////////////////////////////////////////
Temperature &Temperature::operator/=(const Temperature &_temp)
{
  this->dataPtr->kelvin /= _temp.Kelvin();
  return *this;
}

/////////////////////////////////////////////////
bool Temperature::operator==(const Temperature &_temp) const
{
  return ignition::math::equal(this->dataPtr->kelvin, _temp.Kelvin());
}

/////////////////////////////////////////////////
bool Temperature::operator==(const double _temp) const
{
  return ignition::math::equal(this->dataPtr->kelvin, _temp);
}

/////////////////////////////////////////////////
bool Temperature::operator!=(const Temperature &_temp) const
{
  return !(*this == _temp);
}

/////////////////////////////////////////////////
bool Temperature::operator!=(const double _temp) const
{
  return !(*this == _temp);
}

/////////////////////////////////////////////////
bool Temperature::operator<(const Temperature &_temp) const
{
  return this->dataPtr->kelvin < _temp.Kelvin();
}

/////////////////////////////////////////////////
bool Temperature::operator<(const double _temp) const
{
  return this->dataPtr->kelvin < _temp;
}

/////////////////////////////////////////////////
bool Temperature::operator<=(const Temperature &_temp) const
{
  return this->dataPtr->kelvin <= _temp.Kelvin();
}

/////////////////////////////////////////////////
bool Temperature::operator<=(const double _temp) const
{
  return this->dataPtr->kelvin <= _temp;
}

/////////////////////////////////////////////////
bool Temperature::operator>(const Temperature &_temp) const
{
  return this->dataPtr->kelvin > _temp.Kelvin();
}

/////////////////////////////////////////////////
bool Temperature::operator>(const double _temp) const
{
  return this->dataPtr->kelvin > _temp;
}

/////////////////////////////////////////////////
bool Temperature::operator>=(const Temperature &_temp) const
{
  return this->dataPtr->kelvin >= _temp.Kelvin();
}

/////////////////////////////////////////////////
bool Temperature::operator>=(const double _temp) const
{
  return this->dataPtr->kelvin >= _temp;
}
