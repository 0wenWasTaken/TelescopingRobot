#pragma once
#include <units/angle.h>

namespace CONSTANTS {

    template <typename T>
    static bool IN_THRESHOLD(T source, T target, T range)
    {
        return (source >= target - range && source <= target + range);
    }

    namespace ARM
    {
        constexpr int CAN_ID_MOTOR           = 41;
        constexpr units::turn_t STOWED       = 0.0_tr;
        constexpr units::turn_t PICKUP_FLOOR = 1.0_tr;
        constexpr units::turn_t PICKUP_SUBST = 1.0_tr;
        constexpr units::turn_t SCORE_FLOOR  = 1.0_tr;
        constexpr units::turn_t SCORE_MID    = 1.0_tr;
        constexpr units::turn_t SCORE_HIGH   = 1.0_tr;
    }

    namespace SHOULDER
    {
        constexpr int CAN_ID_MOTOR           = 21;
        constexpr units::turn_t STOWED       = 0.0_tr;
        constexpr units::turn_t PICKUP_FLOOR = 1.0_tr;
        constexpr units::turn_t PICKUP_SUBST = 1.0_tr;
        constexpr units::turn_t SCORE_FLOOR  = 1.0_tr;
        constexpr units::turn_t SCORE_MID    = 1.0_tr;
        constexpr units::turn_t SCORE_HIGH   = 1.0_tr;
    }

    namespace HAND
    {
        constexpr int CAN_ID_WRIST_MOTOR     = 5;
        constexpr int CAN_ID_ROLLER_MOTOR    = 31;
        constexpr int CAN_ID_SENSOR          = 11;
        constexpr units::turn_t STOWED       = 0.0_tr;
        constexpr units::turn_t PICKUP_FLOOR = 1.0_tr;
        constexpr units::turn_t PICKUP_SUBST = 1.0_tr;
        constexpr units::turn_t SCORE_FLOOR  = 1.0_tr;
        constexpr units::turn_t SCORE_MID    = 1.0_tr;
        constexpr units::turn_t SCORE_HIGH   = 1.0_tr;

        constexpr double NONE_THROTTLE       = 0.0;
        constexpr double INTAKE_THROTTLE     = 0.2;
        constexpr double EJECT_THROTTLE      = -0.4;
    }
}