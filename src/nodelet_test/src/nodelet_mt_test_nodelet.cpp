#include "nodelet_mt_test_nodelet.h"



namespace nodelet_mt_test_namespace {

MtTestNodelet::MtTestNodelet()
 :  rate_(10.0)
{
}


void MtTestNodelet::onInit() {
    // ros::NodeHandle &nh_ = getNodeHandle();
    ros::NodeHandle &nh_ = getMTNodeHandle();
    node_name_ = getName();
    timer_one_   = nh_.createTimer(ros::Duration(1.0 / rate_), &MtTestNodelet::timerOneCb, this);
    timer_two_   = nh_.createTimer(ros::Duration(1.0 / rate_), &MtTestNodelet::timerTwoCb, this);
    timer_three_ = nh_.createTimer(ros::Duration(1.0 / rate_), &MtTestNodelet::timerThreeCb, this);
    timer_four_  = nh_.createTimer(ros::Duration(1.0 / rate_), &MtTestNodelet::timerFourCb, this);
    start_ = std::chrono::high_resolution_clock::now();
    NODELET_INFO_STREAM(node_name_ << ": Nodelet initialised");
}


void MtTestNodelet::timerOneCb(const ros::TimerEvent& event){
    auto timerCbStart = std::chrono::high_resolution_clock::now();
    NODELET_INFO_STREAM(node_name_ << ": timerOneCbStart-start_: " << std::chrono::duration_cast<std::chrono::microseconds>(timerCbStart-start_).count() << " us");

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // auto timerCbEnd = std::chrono::high_resolution_clock::now();
    // NODELET_INFO_STREAM(node_name_ << ": timerCbEnd-timerCbStart: " << std::chrono::duration_cast<std::chrono::microseconds>(timerCbEnd-timerCbStart).count() << " us");
}


void MtTestNodelet::timerTwoCb(const ros::TimerEvent& event){
    auto timerCbStart = std::chrono::high_resolution_clock::now();
    NODELET_INFO_STREAM(node_name_ << ": timerTwoCbStart-start_: " << std::chrono::duration_cast<std::chrono::microseconds>(timerCbStart-start_).count() << " us");

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // auto timerCbEnd = std::chrono::high_resolution_clock::now();
    // NODELET_INFO_STREAM(node_name_ << ": timerCbEnd-timerCbStart: " << std::chrono::duration_cast<std::chrono::microseconds>(timerCbEnd-timerCbStart).count() << " us");
}


void MtTestNodelet::timerThreeCb(const ros::TimerEvent& event){
    auto timerCbStart = std::chrono::high_resolution_clock::now();
    NODELET_INFO_STREAM(node_name_ << ": timerThreeCbStart-start_: " << std::chrono::duration_cast<std::chrono::microseconds>(timerCbStart-start_).count() << " us");

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // auto timerCbEnd = std::chrono::high_resolution_clock::now();
    // NODELET_INFO_STREAM(node_name_ << ": timerCbEnd-timerCbStart: " << std::chrono::duration_cast<std::chrono::microseconds>(timerCbEnd-timerCbStart).count() << " us");
}


void MtTestNodelet::timerFourCb(const ros::TimerEvent& event){
    auto timerCbStart = std::chrono::high_resolution_clock::now();
    NODELET_INFO_STREAM(node_name_ << ": timerFourCbStart-start_: " << std::chrono::duration_cast<std::chrono::microseconds>(timerCbStart-start_).count() << " us");

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // auto timerCbEnd = std::chrono::high_resolution_clock::now();
    // NODELET_INFO_STREAM(node_name_ << ": timerCbEnd-timerCbStart: " << std::chrono::duration_cast<std::chrono::microseconds>(timerCbEnd-timerCbStart).count() << " us");
}


} // namespace nodelet_mt_test_namespace

PLUGINLIB_EXPORT_CLASS(nodelet_mt_test_namespace::MtTestNodelet, nodelet::Nodelet);