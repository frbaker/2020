#ifndef ROBOTFUNCTIONS_HPP_INCLUDED
#define ROBOTFUNCTIONS_HPP_INCLUDED
//Libraries
//
#include "frc/WPILib.h"
#include <frc/TimedRobot.h>
#include <frc/XboxController.h>
#include <frc/SpeedControllerGroup.h>
#include "ctre/phoenix.h"
#include <frc/drive/DifferentialDrive.h>
//
//
class RobotDriveTrain{
public:
 WPI_TalonSRX  *rightMotor1=new WPI_TalonSRX(1);
  WPI_TalonSRX  *rightMotor2=new WPI_TalonSRX(2);
  WPI_TalonSRX  *leftMotor1=new WPI_TalonSRX(3);
  WPI_TalonSRX  *leftMotor2=new WPI_TalonSRX(4);
  frc::SpeedControllerGroup leftMotors{*leftMotor1, *leftMotor2};
  frc::SpeedControllerGroup rightMotors{*rightMotor1, *rightMotor2};

 frc::DifferentialDrive robotDifferentialDrive= {leftMotors,rightMotors};


};

class DriveControll{
public: 
frc::XboxController Controller0{0};
frc::XboxController Controller1{1};

void SetDeadbandDrive(bool useTank, double lDB, double rDB){
    RobotDriveTrain DriveRobot;
    double leftYval =Controller0.GetY(frc::GenericHID::JoystickHand::kLeftHand);

if(useTank==true)
{
double rightYval =Controller0.GetY(frc::GenericHID::JoystickHand::kRightHand);
    if (leftYval<lDB&&leftYval>-lDB){leftYval=0;}
    if(rightYval<rDB&&rightYval>-rDB){rightYval=0;}
    DriveRobot.robotDifferentialDrive.TankDrive(leftYval,rightYval);
}
else
{       
double rightXval =Controller0.GetX(frc::GenericHID::JoystickHand::kRightHand);
    if (leftYval<lDB&&leftYval>-lDB){leftYval=0;}
    if(rightXval<rDB&&rightXval>-rDB){rightXval=0;}
    DriveRobot.robotDifferentialDrive.ArcadeDrive(leftYval,rightXval);
        }
    }
};







#endif//RobotFunctions header included




/*class DriveControll{
public: 
frc::XboxController Controller0{0};
frc::XboxController Controller1{1};

void SetDeadbandDrive(bool useTank, double lDB, double rDB){
    RobotDriveTrain DriveRobot;
    double leftYval =Controller0.GetY(frc::GenericHID::JoystickHand::kLeftHand);
    if(useTank==true)
{
double rightYval =Controller0.GetY(frc::GenericHID::JoystickHand::kRightHand);
    if (leftYval<lDB&&leftYval>-lDB){
        leftYval=0;
    }
    else{DriveRobot.leftMotors.Set(leftYval);}
    if(rightYval<rDB&&rightYval>-rDB){
        rightYval=0;
    }
    else{DriveRobot.rightMotors.Set(rightYval);}
}


else
{
            
double rightXval =Controller0.GetX(frc::GenericHID::JoystickHand::kRightHand);
    if (leftYval<lDB&&leftYval>-lDB){
        leftYval=0;
    }
    else{DriveRobot.leftMotors.Set(leftYval);
    DriveRobot.rightMotors.Set(leftYval);
    }
    if(rightXval<rDB&&rightXval>-rDB){rightXval=0;}
    else{DriveRobot.rightMotors.Set(rightXval);
    DriveRobot.leftMotors.Set(-rightXval);}
}

    }

};
*/