#pragma once

#include <signal.h>
#include <chrono>
#include <thread>

#include <ros/ros.h>
#include <nodelet/nodelet.h>
#include <pluginlib/class_list_macros.h>



namespace nodelet_mt_test_namespace {

class MtTestNodelet : public nodelet::Nodelet
{
public:
    explicit                                            MtTestNodelet();

private:
    virtual void                                        onInit();
    void                                                timerOneCb(const ros::TimerEvent& event);
    void                                                timerTwoCb(const ros::TimerEvent& event);
    void                                                timerThreeCb(const ros::TimerEvent& event);
    void                                                timerFourCb(const ros::TimerEvent& event);

    ros::NodeHandle                                     nh_;
    int32_t                                             publish_rate_;
    std::string                                         node_name_;
    std::chrono::high_resolution_clock::time_point      start_;

    ros::Timer                                          timer_one_;
    ros::Timer                                          timer_two_;
    ros::Timer                                          timer_three_;
    ros::Timer                                          timer_four_;

};

} // namespace nodelet_mt_test_namespace