#include "subsystems/ShooterAngleTest.h"
#include <frc/SmartDashboard/SmartDashboard.h>
#include "Robot.h"

ShooterAngleTest::ShooterAngleTest() = default;

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

void ShooterAngleTest::Periodic() 
{
    frc::SmartDashboard::PutNumber("BrushedMotor Analog", m_analogSensor.GetVoltage());
    frc::SmartDashboard::PutNumber("BrushedMotor Power", GetPower());
    frc::SmartDashboard::PutNumber("BrushedMotor encoder",m_brushed_encoder.GetPosition());
}
