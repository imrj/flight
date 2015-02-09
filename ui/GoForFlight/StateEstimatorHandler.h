#ifndef STATE_ESTIMATOR_HANDLER_HPP
#define STATE_ESTIMATOR_HANDLER_HPP

#include "StatusHandler.h"
#include "../../LCM/mav/pose_t.hpp"

class StateEsimatorHandler : public StatusHandler
{
    public:
        StateEsimatorHandler() : StatusHandler("State Esimator: ") {
        }
        ~StateEsimatorHandler() {}

        void handleMessage(const lcm::ReceiveBuffer* rbuf,
                           const std::string& chan,
                           const mav::pose_t* msg) {

            if (msg->utime > last_utime_) {
                status_ = true;
            } else {
                status_ = false;
            }

            last_utime_ = msg->utime;

        }

    private:
        long last_utime_ = -1;


};

#endif // LOG_SIZE_HANDLER_HPP