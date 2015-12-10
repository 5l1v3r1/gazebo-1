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
#include <gtest/gtest.h>

#include "gazebo/common/Temperature.hh"
#include "test/util.hh"

using namespace gazebo;
using namespace common;

class TemperatureTest : public gazebo::testing::AutoLogFixture{};

/////////////////////////////////////////////////
TEST_F(TemperatureTest, Constructor)
{
  Temperature temp;
  EXPECT_NEAR(temp.Kelvin(), 0.0, 1e-6);

  Temperature temp2(1.1);
  EXPECT_NEAR(temp2.Kelvin(), 1.1, 1e-6);

  Temperature temp3(temp2);
  EXPECT_NEAR(temp3.Kelvin(), 1.1, 1e-6);

  EXPECT_TRUE(temp2 == temp3);
  EXPECT_TRUE(temp2 == 1.1);
  EXPECT_TRUE(temp2 != temp);
  EXPECT_TRUE(temp2 != 1.2);

  EXPECT_TRUE(temp < temp2);
  EXPECT_TRUE(temp < 10.0);
  EXPECT_TRUE(temp <= temp2);
  EXPECT_TRUE(temp <= 0.0);
  EXPECT_TRUE(temp <= 0.1);

  EXPECT_FALSE(temp > temp2);
  EXPECT_FALSE(temp > 80.0);
  EXPECT_FALSE(temp >= temp2);
  EXPECT_FALSE(temp >= 0.1);
  EXPECT_TRUE(temp >= 0.0);
}

/////////////////////////////////////////////////
TEST_F(TemperatureTest, Conversions)
{
  EXPECT_NEAR(Temperature::KelvinToCelsius(0), -273.15, 1e-6);
  EXPECT_NEAR(Temperature::KelvinToFarenheit(300), 80.33, 1e-6);

  EXPECT_NEAR(Temperature::CelsiusToFarenheit(20.0), 68.0, 1e-6);
  EXPECT_NEAR(Temperature::CelsiusToKelvin(10.0), 283.15, 1e-6);

  EXPECT_NEAR(Temperature::FarenheitToCelsius(-40.0),
              Temperature::CelsiusToFarenheit(-40.0), 1e-6);
  EXPECT_NEAR(Temperature::FarenheitToKelvin(60.0), 288.71, 1e-6);
}

/////////////////////////////////////////////////
TEST_F(TemperatureTest, MutatorsAccessors)
{
  Temperature temp;
  EXPECT_NEAR(temp.Kelvin(), 0.0, 1e-6);

  temp.SetKelvin(10);
  EXPECT_NEAR(temp.Kelvin(), 10.0, 1e-6);

  temp.SetCelsius(20);
  EXPECT_NEAR(temp(), 293.15, 1e-6);

  temp.SetFarenheit(30);
  EXPECT_NEAR(temp.Farenheit(), 30.0, 1e-6);
  EXPECT_NEAR(temp(), 272.0388889, 1e-6);
}

/////////////////////////////////////////////////
TEST_F(TemperatureTest, Operators)
{
  Temperature temp(20);
  EXPECT_NEAR(temp(), 20, 1e-6);

  temp = 30;
  EXPECT_NEAR(temp(), 30, 1e-6);

  Temperature temp2 = temp;
  EXPECT_TRUE(temp == temp2);

  EXPECT_NEAR((temp + temp2).Kelvin(), 50, 1e-6);
  EXPECT_NEAR((temp + 40).Kelvin(), 60, 1e-6);

  EXPECT_NEAR((temp - temp2).Kelvin(), -10, 1e-6);
  EXPECT_NEAR((temp - 20).Kelvin(), 0.0, 1e-6);

  EXPECT_NEAR((temp * temp2).Kelvin(), 600, 1e-6);
  EXPECT_NEAR((temp * 2).Kelvin(), 40.0, 1e-6);

  EXPECT_NEAR((temp / temp2).Kelvin(), 2/3.0, 1e-6);
  EXPECT_NEAR((temp / 2).Kelvin(), 10.0, 1e-6);

  temp += temp2;
  EXPECT_NEAR(temp.Kelvin(), 50.0, 1e-6);
  temp -= temp2;
  EXPECT_NEAR(temp.Kelvin(), 20.0, 1e-6);

  temp += 5.0;
  EXPECT_NEAR(temp.Kelvin(), 25.0, 1e-6);
  temp -= 5.0;
  EXPECT_NEAR(temp.Kelvin(), 20.0, 1e-6);

  temp *= temp2;
  EXPECT_NEAR(temp.Kelvin(), 600, 1e-6);
  temp /= temp2;
  EXPECT_NEAR(temp.Kelvin(), 20, 1e-6);

  temp *= 4.0;
  EXPECT_NEAR(temp.Kelvin(), 80, 1e-6);
  temp /= 4.0;
  EXPECT_NEAR(temp.Kelvin(), 20, 1e-6);
}

/////////////////////////////////////////////////
TEST(TemperatureTest, OperatorStreamOut)
{
  Temperature temp(55.45);
  std::ostringstream stream;
  stream << temp;
  EXPECT_EQ(stream.str(), "55.45");
}

/////////////////////////////////////////////////
TEST(TemperatureTest, OperatorStreamIn)
{
  Temperature temp;
  std::istringstream stream("23.4");
  stream >> temp;
  EXPECT_NEAR(temp.Kelvin(), 23.4, 1e-6);
}

/////////////////////////////////////////////////
int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
