#include "RobotFunctions.hpp"

class Robot : public frc::TimedRobot {

 public:
 void AutonomousPeriodic() override {
    TeleopPeriodic();
     }

  void TeleopPeriodic() override {
    //Put Robot Driving Function Here
    DriveControll DriveOBJ;
    DriveOBJ.SetDeadbandDrive(false,.1,.1);//(Use Tank Drive, deadband for left joy, deadband for right joy)
  }
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif