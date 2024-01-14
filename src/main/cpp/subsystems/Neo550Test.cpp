// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Neo550Test.h"
#include <frc/SmartDashboard/SmartDashboard.h>
#include "Robot.h"


Neo550Test::Neo550Test()
{
    cout << "Neo550Test Constructor" << endl;

    //Initialize 550 Motor
    m_neo550_motor.RestoreFactoryDefaults();
    m_neo550_motor.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

    m_neo550_encoder.SetPosition(0.0);
    m_neo550_pid.SetP(0.15);
    m_neo550_pid.SetOutputRange(-0.1,0.1);


    //For Local Testing
    frc::SmartDashboard::PutNumber("Neo550 SetPwr",0.0);
    frc::SmartDashboard::PutNumber("Neo550 SetPos",0.0);


}

// This method will be called once per scheduler run
void Neo550Test::Periodic() 
{
    //Outputs
    frc::SmartDashboard::PutNumber("Neo550 Encoder", GetEncoder() );
    frc::SmartDashboard::PutNumber("Neo550 Power",   GetPower()   );


    // // //Testing Power
    // // SetPower( frc::SmartDashboard::GetNumber("Neo550 SetPwr",0) );

    // //Testing Position with PID
    // //Position = NumRotataions
    // SetPosition( frc::SmartDashboard::GetNumber("Neo550 SetPos",0) );


}


  void  Neo550Test::Stop(void)
  {
    m_neo550_motor.Set(0.0);
  }
  void  Neo550Test::SetPower(float power)
  {
    m_neo550_motor.Set(power);      
  }
  float Neo550Test::GetPower(void)
  {
    return m_neo550_motor.Get();
  }
  void  Neo550Test::SetPosition(float position)
  {
    //Position = rotations
    m_neo550_pid.SetReference(position, rev::CANSparkMax::ControlType::kPosition);
  }
  float Neo550Test::GetEncoder(void)
  {
    return m_neo550_encoder.GetPosition();
  }