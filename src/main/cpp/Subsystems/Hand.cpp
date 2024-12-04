#include "Subsystems/Hand.h"

Hand::Hand() 
{
    ctre::phoenix6::configs::TalonFXConfiguration configs{};
    configs.Slot0.kP = 60; // An error of 1 rotations results in 60 A output
    configs.Slot0.kI = 0;  // No output for integrated error
    configs.Slot0.kD = 6;  // A velocity of 1 rps results in 6 A output
    // Peak output of 120 amps
    configs.TorqueCurrent.PeakForwardTorqueCurrent = 120;
    configs.TorqueCurrent.PeakReverseTorqueCurrent = -120;

    m_wrist.SetPosition(0_tr);
}

void Hand::Periodic() 
{
    frc::SmartDashboard::PutNumber("Wrist POS", m_wrist.GetPosition().GetValueAsDouble());
}

bool Hand::is_done(units::angle::turn_t goal) 
{
    return CONSTANTS::IN_THRESHOLD<units::turn_t>(m_wrist.GetPosition().GetValue(), goal, 0.01_tr);
}

void Hand::Move(units::angle::turn_t goal) 
{
    m_wrist.SetControl(m_positionTorque.WithPosition(goal));
}

double Hand::Grabber_Direction(CONSTANTS::Grabber roller_direction) 
{
    switch (roller_direction)
    {
    case CONSTANTS::INTAKE:
        return CONSTANTS::HAND::INTAKE_THROTTLE;
    case CONSTANTS::EJECT:
        return CONSTANTS::HAND::EJECT_THROTTLE;
    case CONSTANTS::NONE:
    default:
        return CONSTANTS::HAND::NONE_THROTTLE;
    }
}

void Hand::Grabber(CONSTANTS::Grabber roller_directon) 
{
    m_dutyCycle.Output = Grabber_Direction(CONSTANTS::Grabber  roller_direction);
    m_roller.SetControl(m_dutyCycle);
}

frc2::CommandPtr Hand::Idle()
{
    return frc2::cmd::Run( [this] {
        Move(CONSTANTS::HAND::STOWED);
        }, {this} );
}

frc2::CommandPtr Hand::Move_Command(units::angle::turn_t desired, CONSTANTS::Grabber roller_direction)
{

}