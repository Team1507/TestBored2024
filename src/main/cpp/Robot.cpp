// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc2/command/CommandScheduler.h>


RobotContainer robotContainer;  //Global Variable


void Robot::RobotInit() 
{
  //*************************** INIT ******************************
  std::cout<<"RobotInit"<<std::endl;
  std::cout<<"FRC2024: TestBored"<<std::endl;
  std::cout<<"Version: " << __DATE__ <<"  "<<__TIME__<<std::endl<<std::endl; 


}

void Robot::RobotPeriodic() 
{
  frc2::CommandScheduler::GetInstance().Run();
}

void Robot::DisabledInit() 
{
  std::cout<<"Disabled Init"<<std::endl;
}

void Robot::DisabledPeriodic() {}

void Robot::DisabledExit() {}

void Robot::AutonomousInit()
{
  std::cout<<" **** Auto Init ******"<<std::endl;
  m_autonomousCommand = robotContainer.GetAutonomousCommand();

  if (m_autonomousCommand) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::AutonomousExit() {}

void Robot::TeleopInit() 
{
  //Clean up any leftovers from Autonomous
  if (m_autonomousCommand) {
    m_autonomousCommand->Cancel();
  }
  std::cout<<"Teleop Init"<<std::endl;


}

void Robot::TeleopPeriodic() {}

void Robot::TeleopExit() {}

void Robot::TestInit() {
  frc2::CommandScheduler::GetInstance().CancelAll();
}

void Robot::TestPeriodic() {}

void Robot::TestExit() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
