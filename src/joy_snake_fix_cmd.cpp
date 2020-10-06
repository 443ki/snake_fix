/**
 * @file joy_snake_fix_cmd.h
 * @brief ヘビ型ロボット固定のためのコマンドをJoystickから送信するためのプログラム
 * @author Yusuke Yoshizaki
 * @date 2020/04/21
 * @detail
 */

 #include "joy_snake_fix_cmd.h"

 //===== constructor & destrucor ==================================================//
 /** @fn
  * @brief コンストラクタ
  * @param なし
  */
  JoySnakeFixCmd::JoySnakeFixCmd(){

    // Subscriber
    joy_sub_ = nh_.subscribe("/joy", 1, &JoySnakeFixCmd::JoyCallback,this);

    // ServiceClient
    open_cmd_cli_ = nh_.serviceClient<std_srvs::Trigger>("/snake_fix/snake_fix_open/execution");
    close_cmd_cli_= nh_.serviceClient<std_srvs::Trigger>("/snake_fix/snake_fix_close/execution");

    bool snake_fix_is_opened_ = false; // open:ture, close:false

  }

  /** @fn
   * @brief デストラクタ
   * @param なし
   */
JoySnakeFixCmd::~JoySnakeFixCmd(){}

//===== Callback ==================================================//
/** @fn
 * @brief Joyコールバック
 * @param const sensor_msgs::Joy& joy_msg
 * @return なし
 * @detail
 *  サンプリングタイム毎にtfとオドメトリを計算して送信
 */
void JoySnakeFixCmd::JoyCallback(const sensor_msgs::Joy& joy_msg){

  std_srvs::Trigger srv;

  // buttons[2]+buttons[9]（◯+START）で開閉
  if(joy_msg.buttons[2]==1 && joy_msg.buttons[9]==1){

    if(snake_fix_is_opened_ == false){
      if(open_cmd_cli_.call(srv)){
        if(srv.response.success == true){
          ROS_INFO("Successed to open snake fix!");
          snake_fix_is_opened_ = true;
        }else{
          ROS_ERROR("Faild to open snake fix!");
        }
      }else{
        ROS_ERROR("Faild to call open snake fix service!");
      }
    }else if(snake_fix_is_opened_ == true){
      if(close_cmd_cli_.call(srv)){
        if(srv.response.success == true){
          ROS_INFO("Successed to close snake fix!");
          snake_fix_is_opened_ = false;
        }else{
          ROS_ERROR("Faild to close snake fix!");
        }
      }else{
        ROS_ERROR("Faild to call close snake fix service!");
      }
    }
  }

}

//===== main ==================================================//
/** @fnatoll
 * @brief main関数
 * @param なし
 */

 int main(int argc, char **argv)
 {
   ros::init(argc, argv, "joy_snake_fix_cmd");
   JoySnakeFixCmd joy_snake_fix_cmd;
   ROS_INFO("JoySnakeFixCmd was initialized!");

   ros::spin();
   return 0;
 }
