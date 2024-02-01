#include "subsystems/ShooterAngleTest.h"
#include <frc/SmartDashboard/SmartDashboard.h>
#include "Robot.h"

ShooterAngleTest::ShooterAngleTest()
{
    cout << "ShooterAngleTest Constructor" << endl;

    //Initialize 550 Motor
    m_brushedMotor.RestoreFactoryDefaults();
    m_brushedMotor.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    //m_brushedMotor.SetInverted(true);       
    

    m_forwardLimit.EnableLimitSwitch(true);
    m_reverseLimit.EnableLimitSwitch(true);


    //PID Setup
    m_pidController.SetFeedbackDevice(m_analogSensor);


    // set PID coefficients
    m_pidController.SetP(  5.0 );   //0.1v * kp = 1V
    // m_pidController.SetI(kI);
    // m_pidController.SetD(kD);
    // m_pidController.SetIZone(kIz);
    // m_pidController.SetFF(kFF);
    m_pidController.SetOutputRange(-0.2, 0.15);
    //Forward - releasing into the spring, less power
    //Reverse - pulling against the spring, more power

    // 6"  = 2.8
    // 16" = 1.75

    //For Local Testing
    frc::SmartDashboard::PutNumber("BrushedMotor SetPwr",0.0);
    frc::SmartDashboard::PutNumber("BrushedMotor SetAnalogVoltage", 2.8);
    frc::SmartDashboard::PutNumber("BrushedMotor SetTapePosition", 6.0);

}

void ShooterAngleTest::Periodic() 
{
    frc::SmartDashboard::PutNumber("BrushedMotor Analog", m_analogSensor.GetVoltage());
    frc::SmartDashboard::PutNumber("BrushedMotor Power", GetPower());
    //frc::SmartDashboard::PutNumber("BrushedMotor encoder",m_brushed_encoder.GetPosition());

   frc::SmartDashboard::PutBoolean("BrushedMotor FwdLimit",m_forwardLimit.Get() );
   frc::SmartDashboard::PutBoolean("BrushedMotor RevLimit",m_reverseLimit.Get() );

    //Testing Power
    //SetPower( frc::SmartDashboard::GetNumber("BrushedMotor SetPwr",0) );

    float goal_voltage = frc::SmartDashboard::GetNumber("BrushedMotor SetAnalogVoltage", 2.8);
    float goal_pos     = frc::SmartDashboard::GetNumber("BrushedMotor SetTapePosition", 6.0);


    //m_pidController.SetReference(goal_voltage, rev::CANSparkMax::ControlType::kPosition);
    SetAngle(goal_pos);

    frc::SmartDashboard::PutNumber("ProcessVariable", m_analogSensor.GetPosition());

}


void ShooterAngleTest::Stop(void)
{
    m_brushedMotor.Set(0.0);
}

void ShooterAngleTest::SetPower(double power)
{
    m_brushedMotor.Set(power);
}

double ShooterAngleTest::GetPower(void)
{
    return m_brushedMotor.Get();
}

void ShooterAngleTest::SetEncoderPosition(float position)
{
    // looking for solution
}


void ShooterAngleTest::SetAngle(float angle )
{
    //Calculate angle based on known values using y=mx+b calibrations
    // X1 = 6.0,  Y1 = 2.8 
    // X2 = 16.0, Y2 = 1.75
    //

    //  m = (y2-y1)/(x2-x1) = -0.105
    //  b = y - mx  = 2.17 = 3.43

    const float m = -0.105;
    const float b =  3.43;

    float y = (m * angle) + b;

    m_pidController.SetReference(y, rev::CANSparkMax::ControlType::kPosition);

}



