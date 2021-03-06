/*!
  \file        gtest_face_detector_pplp.cpp
  \author      Arnaud Ramey <arnaud.a.ramey@gmail.com>
                -- Robotics Lab, University Carlos III of Madrid
  \date        2013/12/24

________________________________________________________________________________

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
________________________________________________________________________________

\todo Description of the file
 */
//#define DISPLAY

#include <ros_utils/rosmaster_alive.h>
#include "vision_utils/pplp_testing.h"
// people_msgs
#include "vision_utils/test_person_histogram_set_variables.h"
#include "people_detection_vision/face_detector_pplp.h"
// opencv
#include <opencv2/highgui/highgui.hpp>

namespace testvar = test_person_histogram_set_variables;

////////////////////////////////////////////////////////////////////////////////

TEST(TestSuite, empty_lab) {
  if (!rosmaster_alive()) return;
  FaceDetectorPPLP skill;
  pplp_testing::ppl_vs_user_benchmark(skill, IMG_DIR "depth/empty_lab");
}
TEST(TestSuite, all_multi_users) {
  if (!rosmaster_alive()) return;
  FaceDetectorPPLP skill;
  pplp_testing::ppl_vs_user_benchmark(skill, testvar::all_multi_user_filename_prefixes(),
                                     false, true, true);
}
TEST(TestSuite, all_single_users) {
  if (!rosmaster_alive()) return;
  FaceDetectorPPLP skill;
  pplp_testing::ppl_vs_user_benchmark(skill, testvar::all_single_user_filename_prefixes(),
                                     false, true, true);
}

////////////////////////////////////////////////////////////////////////////////

TEST(TestSuite, start_stop) {
  if (!rosmaster_alive()) return;
  FaceDetectorPPLP skill;
  pplp_testing::start_stop(skill);
}

////////////////////////////////////////////////////////////////////////////////

TEST(TestSuite, speed_test) {
  if (!rosmaster_alive()) return;
  FaceDetectorPPLP skill;
  pplp_testing::speed_test(skill, false, 10, .3); // slow algorithm...
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv) {
  ros::init(argc, argv, "gtest_skill");
  // Run all the tests that were declared with TEST()
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
