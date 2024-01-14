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
    m_neo550.RestoreFactoryDefaults();
    m_neo550.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);


    //For Local Testing
    frc::SmartDashboard::PutNumber("Neo500 SetPwr",0.0);


}

// This method will be called once per scheduler run
void Neo550Test::Periodic() 
{
    //Outputs
    frc::SmartDashboard::PutNumber("Neo500 Encoder", GetEncoder() );
    frc::SmartDashboard::PutNumber("Neo500 Power",   GetPower()   );


    //Testing Power
    SetPower( frc::SmartDashboard::GetNumber("Neo500 SetPwr",0) );


}


  void  Neo550Test::Stop(void)
  {
    m_neo550.Set(0.0);
  }
  void  Neo550Test::SetPower(float power)
  {
    m_neo550.Set(power);      
  }
  float Neo550Test::GetPower(void)
  {
    return m_neo550.Get();
  }
  void  Neo550Test::SetPosition(float position)
  {

  }
  float Neo550Test::GetEncoder(void)
  {
    return m_neo550_encoder.GetPosition();
  }