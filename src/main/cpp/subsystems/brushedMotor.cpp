#include "subsystems/BrushedMotor.h"
#include <frc/SmartDashboard/SmartDashboard.h>
#include "Robot.h"


BrushedMotor::BrushedMotor()
{
    cout << "BrushedMotor Constructor" << endl;

    //Initialize 550 Motor
    m_brushedMotor.RestoreFactoryDefaults();
    m_brushedMotor.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    

    m_forwardLimit.EnableLimitSwitch(true);
    m_reverseLimit.EnableLimitSwitch(true);


    //For Local Testing
    frc::SmartDashboard::PutNumber("BrushedMotor SetPwr",0.0);
    // frc::SmartDashboard::PutNumber("Neo550 SetPos",0.0);
   
}

// This method will be called once per scheduler run
void BrushedMotor::Periodic() 
{
    //Outputs
    frc::SmartDashboard::PutNumber("BrushedMotor Power",   GetPower()   );

   frc::SmartDashboard::PutNumber("BrushedMotor encoder",m_brushed_encoder.GetPosition());

   frc::SmartDashboard::PutBoolean("BrushedMotor FwdLimit",m_forwardLimit.Get() );
   frc::SmartDashboard::PutBoolean("BrushedMotor RevLimit",m_reverseLimit.Get() );

   frc::SmartDashboard::PutNumber("BrushedMotor Analog",m_analogSensor.GetVoltage() );

    //Testing Power
    SetPower( frc::SmartDashboard::GetNumber("BrushedMotor SetPwr",0) );

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


  void BrushedMotor::SetEncoderPosition( float position )
  {
    //THIS DOES NOT WORK and causes the SparkMax to hang.
    //m_brushed_encoder.SetPosition(position);
    
  }