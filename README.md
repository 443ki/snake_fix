# snake_fix
ダイナミクセルを２個使用して、ヘビ型ロボットを固定するためのパッケージ

## 必要なパッケージのインストール
```
$ sudo apt install ros-melodic-dynamixel-sdk ros-melodic-dynamixel-workbench dynamixel_workbench_msgs
```

## 使用方法
ジョイスティックとDYNAMIXELをPCに接続し、以下のコマンドを実行する
```
$ roscore
$ rosrun joy joynode
$ roslaunch snake_fix snake_fix.launch
```
START + ◯ で開閉する

DYNAMIXELの設定や詳しい説明等は[こちら](https://emanual.robotis.com/docs/en/software/dynamixel/dynamixel_workbench_jp/)を参照

## 参考資料
- [Dynamixel Workbenchを触ってみた #01](http://dream-drive.net/2019/07/14/9402/)
- [ROBOTIS e-Manual for Dynamixel Workbench](https://emanual.robotis.com/docs/en/software/dynamixel/dynamixel_workbench/)
- [日本語版ROBOTIS e-Manual for Dynamixel Workbench](https://emanual.robotis.com/docs/en/software/dynamixel/dynamixel_workbench_jp/)
