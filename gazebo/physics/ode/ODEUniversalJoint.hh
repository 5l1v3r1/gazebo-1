/*
 * Copyright (C) 2012-2015 Open Source Robotics Foundation
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
#ifndef _GAZEBO_PHYSICS_ODE_ODEUNIVERSALJOINT_HH_
#define _GAZEBO_PHYSICS_ODE_ODEUNIVERSALJOINT_HH_

#include <boost/any.hpp>
#include <string>

#include "gazebo/common/Exception.hh"
#include "gazebo/physics/UniversalJoint.hh"
#include "gazebo/physics/ode/ODEJoint.hh"
#include "gazebo/util/system.hh"

namespace gazebo
{
  namespace physics
  {
    /// \brief A universal joint.
    class GZ_PHYSICS_VISIBLE ODEUniversalJoint :
      public UniversalJoint<ODEJoint>
    {
      /// \brief Constructor.
      /// \param[in] _worldId ODE world id.
      /// \param[in] _parent Pointer to the Link that is the joint' parent
      public: ODEUniversalJoint(dWorldID _worldId, BasePtr _parent);

      /// \brief Destuctor.
      public: virtual ~ODEUniversalJoint();

      // Documentation inherited
      public: virtual ignition::math::Vector3d Anchor(
                  const unsigned int _index) const;

      // Documentation inherited
      public: virtual void SetAnchor(const unsigned int _index,
                  const ignition::math::Vector3d &_anchor);

      // Documentation inherited
      public: virtual ignition::math::Vector3d GlobalAxis(
                  const unsigned int _index) const;

      // Documentation inherited
      public: virtual void SetAxis(const unsigned int _index,
                  const ignition::math::Vector3d &_axis);

      // Documentation inherited
      public: virtual ignition::math::Angle AngleImpl(
                  const unsigned int _index) const;

      // Documentation inherited
      public: virtual double Velocity(const unsigned int _index) const;

      // Documentation inherited
      public: virtual void SetVelocity(const unsigned int _index,
                  const double _angle);

      // Documentation inherited
      public: virtual void SetParam(const unsigned int _parameter,
                  const double _value);

      // Documentation inherited.
      public: virtual bool SetHighStop(const unsigned int _index,
                  const ignition::math::Angle &_angle);

      // Documentation inherited.
      public: virtual bool SetLowStop(const unsigned int _index,
                  const ignition::math::Angle &_angle);

      // Documentation inherited.
      public: virtual bool SetParam(const std::string &_key,
                                    const unsigned int _index,
                                    const boost::any &_value);

      // Documentation inherited.
      public: virtual double Param(const std::string &_key,
                                   const unsigned int _index) const;

      // Documentation inherited
      public: virtual double Param(const unsigned int _parameter) const;

      // Documentation inherited
      protected: virtual void SetForceImpl(const unsigned int _index,
                     const double _effort);
    };
  }
}
#endif
