/**
 * 用于保存iai-kinect2导出的图片
 *
 *
 *
 *
 *
 *
 */

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

static bool bSaveImageToFile = true;

void Cam_RGB_callback(const sensor_msgs::ImageConstPtr & msg)
{
    cv_bridge::CvImagePtr cv_ptr;
    try
    {
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception e)
    {
        /* code for Catch */
        ROS_ERROR("cv_bridage exception: %s", e.what());
        return;
    }
    if (bSaveImageToFile)
    {
        imwrite("/home/svitter/catkin_ws/pic/camera_depth1.jpg", cv_ptr->image);
        printf("save a camera frame success.\n");
        bSaveImageToFile = false;
    }
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "color_image_node");
    ros::NodeHandle nh;
    ros::Subscriber rgb_sub = nh.subscribe("/kinect2/qhd/image_color", 1, Cam_RGB_callback);
    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
