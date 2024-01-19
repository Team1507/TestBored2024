#include "subsystems/BrushedMotor.h"
#include <frc/SmartDashboard/SmartDashboard.h>
#include "Robot.h"


BrushedMotor::BrushedMotor()
{
    cout << "BrushedMotor Constructor" << endl;

    //Initialize 550 Motor
    m_brushedMotor.RestoreFactoryDefaults();
    m_brushedMotor.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

    // m_neo550_encoder.SetPosition(0.0);
    // m_neo550_pid.SetP(0.15);
    // m_neo550_pid.SetOutputRange(-0.1,0.1);


    //For Local Testing
    frc::SmartDashboard::PutNumber("BrushedMotor SetPwr",0.0);
    // frc::SmartDashboard::PutNumber("Neo550 SetPos",0.0);


}

// This method will be called once per scheduler run
void BrushedMotor::Periodic() 
{
    //Outputs
    // frc::SmartDashboard::PutNumber("Neo550 Encoder", GetEncoder() );
    frc::SmartDashboard::PutNumber("BrushedMotor Power",   GetPower()   );


    // // //Testing Power
    SetPower( frc::SmartDashboard::GetNumber("BrushedMotor SetPwr",0) );

    // //Testing Position with PID
    // //Position = NumRotataions
    // SetPosition( frc::SmartDashboard::GetNumber("Neo550 SetPos",0) );


}


  void  BrushedMotor::Stop(void)
  {
    m_brushedMotor.Set(0.0);
  }
  void  BrushedMotor::SetPower(float power)
  {
    m_brushedMotor.Set(power);      
  }
  float BrushedMotor::GetPower(void)
  {
    return m_brushedMotor.Get();
  }
//   void  brushedMotor::SetPosition(float position)
//   {
//     //Position = rotations
//     m_neo550_pid.SetReference(position, rev::CANSparkMax::ControlType::kPosition);
//   }
//   float brushedMotor::GetEncoder(void)
//   {
//     return m_neo550_encoder.GetPosition();
//   }