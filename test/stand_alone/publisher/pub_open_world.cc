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

#include <gazebo/gazebo_client.hh>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>

#include <iostream>

/////////////////////////////////////////////////
int main(int _argc, char **_argv)
{
  // Get world
  std::string worldFile;
  if (_argc == 2)
  {
    worldFile = _argv[1];
  }
  else
  {
    std::cout << "Specify a world file to open." << std::endl;
    return 0;
  }

  // Load gazebo
  gazebo::client::setup(1, NULL);

  // Create our node for communication
  gazebo::transport::NodePtr node(new gazebo::transport::Node());
  node->Init();

  // Publish to a Gazebo topic
  auto pub = node->Advertise<gazebo::msgs::ServerControl>(
      "/gazebo/server/control");

  // Wait for a subscriber to connect
  pub->WaitForConnection();

  gazebo::msgs::ServerControl msg;
  msg.set_open_filename(worldFile);

  pub->Publish(msg);

  // Make sure to shut everything down.
  gazebo::client::shutdown();
}
