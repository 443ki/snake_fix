/**
 * @file joy_snake_fix_cmd.h
 * @brief ヘビ型ロボット固定のためのコマンドをJoystickから送信するためのクラス
 * @author Yusuke Yoshizaki
 * @date 2020/04/21
 * @detail
 */

 #ifndef SNAKE_FIX_SRC_JOY_SNAKE_FIX_CMD_H_
 #define SNAKE_FIX_SRC_JOY_SNAKE_FIX_CMD_H_

 #include <ros/ros.h>
 #include <std_srvs/Trigger.h>
 #include <sensor_msgs/Joy.h>

 class JoySnakeFixCmd{
  public:
    JoySnakeFixCmd();
    ~JoySnakeFixCmd();

  private:
    // CallBack関数
    void JoyCallback(const sensor_msgs::Joy& joy_msg);

    // NodeHandle
    ros::NodeHandle nh_;

    // Subscriber
    ros::Subscriber joy_sub_;

    // ServiceClient
    ros::ServiceClient open_cmd_cli_;
    ros::ServiceClient close_cmd_cli_;

    bool snake_fix_is_opened_;
 };

 #endif /* SNAKE_FIX_SRC_JOY_SNAKE_FIX_CMD_H_ */
