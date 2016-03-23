/*
 * Copyright (C) 2012-2016 Open Source Robotics Foundation
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

#ifndef _GAZEBO_COMMON_SEMANTIC_VERSION_HH_
#define _GAZEBO_COMMON_SEMANTIC_VERSION_HH_

#include <string>
#include "gazebo/util/system.hh"

namespace gazebo
{
  namespace common
  {
    /// \addtogroup gazebo_common
    /// \{

    /// \class  SemanticVersion.hh
    /// \brief Version class based on Semantic Versioning 2.0.0
    /// http://semver.org/
    /// compares versions and converts them from string.
    class GZ_COMMON_VISIBLE SemanticVersion
    {
      /// \brief Constructor
      /// \param[in] _v the string version. ex: "0.3.2"
      public: SemanticVersion(const std::string &_v);

      /// \brief Constructor
      /// \param[in] _maj The major number
      /// \param[in] _min The minor number
      /// \param[in] _patch The pathch number
      public: SemanticVersion(const unsigned int _maj,
                              const unsigned int _min,
                              const unsigned int _patch);

      /// \brief Returns the version as a string
      /// \return The semantic version string
      public: std::string Version() const;

      /// \brief Comparison operator
      /// \param[in] _other The other version to compare to
      /// returns true if _other version is older
      public: bool operator<(const SemanticVersion &_other) const;

      /// \brief Comparison operator
      /// \param[in] _other The other version to compare to
      /// returns true if _other version is older or equal
      public: bool operator<=(const SemanticVersion &_other) const;

      /// \brief Comparison operator
      /// \param[in] _other The other version to compare to
      /// returns true if _other version is newer
      public: bool operator>(const SemanticVersion &_other) const;

      /// \brief Comparison operator
      /// \param[in] _other The other version to compare to
      /// returns true if _other version is newer or equal
      public: bool operator>=(const SemanticVersion &_other) const;

      /// \brief Comparison operator
      /// \param[in] _other The other version to compare to
      /// returns true if _other version is the same
      public: bool operator==(const SemanticVersion &_other) const;

      /// \brief Comparison operator
      /// \param[in] _other The other version to compare to
      /// returns true if _other version is different
      public: bool operator!=(const SemanticVersion &_other) const;

      /// \brief major revision (incompatible api changes)
      private: unsigned int maj;

      /// \brief minor revision (backwards compatible new functionality)
      private: unsigned int min;

      /// \brief patch (bug fixes)
      private: unsigned int patch;
    };
  }
}

#endif