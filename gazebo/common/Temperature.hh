/*
 * Copyright (C) 2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
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
#ifndef _GAZEBO_COMMON_TEMPERATURE_HH_
#define _GAZEBO_COMMON_TEMPERATURE_HH_

#include <iostream>
#include <memory>

#include "gazebo/util/system.hh"

namespace gazebo
{
  namespace common
  {
    // Forward declare private data class.
    class TemperaturePrivate;

    /// \brief A class that store temperature information, and allows
    /// conversion between different units.
    class GZ_COMMON_VISIBLE Temperature
    {
      /// \brief Default constructor
      public: Temperature();

      /// \brief Kelvin value constructor
      /// \param[in] _temp Temperature in Kelvin
      public: Temperature(const double _temp);

      /// \brief Copy constructor
      /// \param[in] _temp Temperature object to copy.
      public: Temperature(const Temperature &_temp);

      /// \brief Destructor
      public: virtual ~Temperature();

      /// \brief Convert Kelvin to Celsius
      /// \param[in] _temp Temperature in Kelvin
      /// \return Temperature in Celsius
      public: static double KelvinToCelsius(const double _temp);

      /// \brief Convert Kelvin to Farenheit
      /// \param[in] _temp Temperature in Kelvin
      /// \return Temperature in Farenheit
      public: static double KelvinToFarenheit(const double _temp);

      /// \brief Convert Celsius to Farenheit
      /// \param[in] _temp Temperature in Celsius
      /// \return Temperature in Farenheit
      public: static double CelsiusToFarenheit(const double _temp);

      /// \brief Convert Celsius to Kelvin
      /// \param[in] _temp Temperature in Celsius
      /// \return Temperature in Kelvin
      public: static double CelsiusToKelvin(const double _temp);

      /// \brief Convert Farenheit to Celsius
      /// \param[in] _temp Temperature in Farenheit
      /// \return Temperature in Celsius
      public: static double FarenheitToCelsius(const double _temp);

      /// \brief Convert Farenheit to Kelvin
      /// \param[in] _temp Temperature in Farenheit
      /// \return Temperature in Kelvin
      public: static double FarenheitToKelvin(const double _temp);

      /// \brief Set the temperature from a Kelvin value
      /// \param[in] _temp Temperature in Kelvin
      public: void SetKelvin(const double _temp);

      /// \brief Set the temperature from a Celsius value
      /// \param[in] _temp Temperature in Celsius
      public: void SetCelsius(const double _temp);

      /// \brief Set the temperature from a Farenheit value
      /// \param[in] _temp Temperature in Farenheit
      public: void SetFarenheit(const double _temp);

      /// \brief Get the temperature in Kelvin
      /// \return Temperature in Kelvin
      public: double Kelvin() const;

      /// \brief Get the temperature in Celsius
      /// \return Temperature in Celsius
      public: double Celsius() const;

      /// \brief Get the temperature in Farenheit
      /// \return Temperature in Farenheit
      public: double Farenheit() const;

      /// \brief Accessor operator
      /// \return Temperature in Kelvin
      /// \sa Kelvin()
      public: double operator()() const;

      /// \brief Assignment operator
      /// \param[in] _temp Temperature in Kelvin
      /// \return Reference to this instance
      public: Temperature &operator=(const double _temp);

      /// \brief Assignment operator
      /// \param[in] _temp Temperature object
      /// \return Reference to this instance
      public: Temperature &operator=(const Temperature &_temp);

      /// \brief Addition operator
      /// \param[in] _temp Temperature in Kelvin
      /// \return Reference to this instance
      public: Temperature operator+(const double _temp);

      /// \brief Addition operator
      /// \param[in] _temp Temperature object
      /// \return Reference to this instance
      public: Temperature operator+(const Temperature &_temp);

      /// \brief Addition assignment operator
      /// \param[in] _temp Temperature in Kelvin
      /// \return Reference to this instance
      public: Temperature &operator+=(const double _temp);

      /// \brief Addition assignment operator
      /// \param[in] _temp Temperature object
      /// \return Reference to this instance
      public: Temperature &operator+=(const Temperature &_temp);

      /// \brief Subtraction operator
      /// \param[in] _temp Temperature in Kelvin
      /// \return Reference to this instance
      public: Temperature operator-(const double _temp);

      /// \brief Subtraction operator
      /// \param[in] _temp Temperature object
      /// \return Reference to this instance
      public: Temperature operator-(const Temperature &_temp);

      /// \brief Subtraction assignment operator
      /// \param[in] _temp Temperature in Kelvin
      /// \return Reference to this instance
      public: Temperature &operator-=(const double _temp);

      /// \brief Subtraction assignment operator
      /// \param[in] _temp Temperature object
      /// \return Reference to this instance
      public: Temperature &operator-=(const Temperature &_temp);

      /// \brief Multiplication operator
      /// \param[in] _temp Temperature in Kelvin
      /// \return Reference to this instance
      public: Temperature operator*(const double _temp);

      /// \brief Multiplication operator
      /// \param[in] _temp Temperature object
      /// \return Reference to this instance
      public: Temperature operator*(const Temperature &_temp);

      /// \brief Multiplication assignment operator
      /// \param[in] _temp Temperature in Kelvin
      /// \return Reference to this instance
      public: Temperature &operator*=(const double _temp);

      /// \brief Multiplication assignment operator
      /// \param[in] _temp Temperature object
      /// \return Reference to this instance
      public: Temperature &operator*=(const Temperature &_temp);

      /// \brief Division operator
      /// \param[in] _temp Temperature in Kelvin
      /// \return Reference to this instance
      public: Temperature operator/(const double _temp);

      /// \brief Division operator
      /// \param[in] _temp Temperature object
      /// \return Reference to this instance
      public: Temperature operator/(const Temperature &_temp);

      /// \brief Division assignment operator
      /// \param[in] _temp Temperature in Kelvin
      /// \return Reference to this instance
      public: Temperature &operator/=(const double _temp);

      /// \brief Division assignment operator
      /// \param[in] _temp Temperature object
      /// \return Reference to this instance
      public: Temperature &operator/=(const Temperature &_temp);

      /// \brief Equal to operator
      /// \param[in] _temp The temperature to compare
      /// \return true if the temperatures are the same, false otherwise
      public: bool operator==(const Temperature &_temp) const;

      /// \brief Equal to operator, where the value of _temp is assumed to
      /// be in Kelvin
      /// \param[in] _temp The temperature (in Kelvin) to compare
      /// \return true if the temperatures are the same, false otherwise
      public: bool operator==(const double _temp) const;

      /// \brief Inequality to operator
      /// \param[in] _temp The temperature to compare
      /// \return false if the temperatures are the same, true otherwise
      public: bool operator!=(const Temperature &_temp) const;

      /// \brief Inequality to operator, where the value of _temp is assumed to
      /// be in Kelvin
      /// \param[in] _temp The temperature (in Kelvin) to compare
      /// \return false if the temperatures are the same, true otherwise
      public: bool operator!=(const double _temp) const;

      /// \brief Less than to operator
      /// \param[in] _temp The temperature to compare
      /// \return True if _temp is less than this.
      public: bool operator<(const Temperature &_temp) const;

      /// \brief Less than operator, where the value of _temp is assumed to
      /// be in Kelvin
      /// \param[in] _temp The temperature (in Kelvin) to compare
      /// \return True if _temp is less than this.
      public: bool operator<(const double _temp) const;

      /// \brief Less than or equal to operator
      /// \param[in] _temp The temperature to compare
      /// \return True if _temp is less than or equal to this.
      public: bool operator<=(const Temperature &_temp) const;

      /// \brief Less than equal operator,
      /// where the value of _temp is assumed to be in Kelvin
      /// \param[in] _temp The temperature (in Kelvin) to compare
      /// \return True if _temp is less than or equal to this.
      public: bool operator<=(const double _temp) const;

      /// \brief Greater than to operator
      /// \param[in] _temp The temperature to compare
      /// \return True if _temp is greater than this.
      public: bool operator>(const Temperature &_temp) const;

      /// \brief Greater than operator, where the value of _temp is assumed to
      /// be in Kelvin
      /// \param[in] _temp The temperature (in Kelvin) to compare
      /// \return True if _temp is greater than this.
      public: bool operator>(const double _temp) const;

      /// \brief Greater than or equal to operator
      /// \param[in] _temp The temperature to compare
      /// \return True if _temp is greater than or equal to this.
      public: bool operator>=(const Temperature &_temp) const;

      /// \brief Greater than equal operator,
      /// where the value of _temp is assumed to be in Kelvin
      /// \param[in] _temp The temperature (in Kelvin) to compare
      /// \return True if _temp is greater than or equal to this.
      public: bool operator>=(const double _temp) const;

      /// \brief Stream insertion operator
      /// \param[in] _out the output stream
      /// \param[in] _temp Temperature to write to the stream
      /// \return the output stream
      public: friend std::ostream &operator<<(std::ostream &_out,
                  const gazebo::common::Temperature &_temp)
              {
                _out << _temp.Kelvin();
                return _out;
              }

      /// \brief Stream extraction operator
      /// \param[in] _in the input stream
      /// \param[in] _temp Temperature to read from to the stream. Assumes
      /// temperature value is in Kelvin.
      /// \return the input stream
      public: friend std::istream &operator>>(std::istream &_in,
                  gazebo::common::Temperature &_temp)
              {
                // Skip white spaces
                _in.setf(std::ios_base::skipws);

                double kelvin;
                _in >> kelvin;

                _temp.SetKelvin(kelvin);
                return _in;
              }

      /// \internal
      /// \brief Private data pointer.
      private: std::unique_ptr<TemperaturePrivate> dataPtr;
    };
  }
}
#endif
