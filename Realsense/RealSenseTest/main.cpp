#include <librealsense2/rs.hpp>
#include <opencv2/opencv.hpp>

int main()
{
    rs2::pipeline pipe;

    rs2::config config;
    //下面这种自定义配置的方式，彩色图片出来是1920*1080的，非常大
    config.enable_stream(RS2_STREAM_COLOR,RS2_FORMAT_BGR8,30);
    config.enable_stream(RS2_STREAM_DEPTH,RS2_FORMAT_Z16,30);

    pipe.start(config);

    while(true)
    {
        rs2::frameset frameset=pipe.wait_for_frames();

        rs2::colorizer color_map;
        rs2::frame depth=frameset.get_depth_frame().apply_filter(color_map);
        rs2::frame color=frameset.get_color_frame();

        const int color_w=color.as<rs2::video_frame>().get_width();
        const int color_h=color.as<rs2::video_frame>().get_height();
        const int depth_w=depth.as<rs2::video_frame>().get_width();
        const int depth_h=depth.as<rs2::video_frame>().get_height();

        std::cout<<color_w<<"\t"<<color_h<<std::endl;
        std::cout<<depth_w<<"\t"<<depth_h<<std::endl;

        cv::Mat colorimage(cv::Size(color_w,color_h),CV_8UC3,(void*)color.get_data());
        cv::Mat depthimage(cv::Size(depth_w,depth_h),CV_8UC3,(void*)depth.get_data());

        cv::imshow("colorimage",colorimage);
        cv::imshow("depthimage",depthimage);

        cv::waitKey(30);
   }
    return 0;
}


