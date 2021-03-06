#include "RobotControl.h"
#include <iostream>
using namespace std;

RobotControl::RobotControl(const std::string& name):
    TaskContext(name)
  {
    
    this->canUpPort = new InputPort<hubomsg::CanMessage>("can_up");
    this->canDownPort = new OutputPort<hubomsg::CanMessage>("can_down");
    this->orOutPort = new InputPort<hubomsg::HuboCmd>("or_out");
    this->orInPort = new OutputPort<hubomsg::HuboCmd>("or_in");

    //CAN QUEUES
    this->inputQueue = new queue<hubomsg::CanMessage>();
    this->outputQueue = new queue<hubomsg::CanMessage>();
    
    //CAN PORTS 
    this->addEventPort(*canUpPort);
    this->addPort(*canDownPort);

    //OPENRAVE PORTS
    this->addEventPort(*orOutPort);
    this->addPort(*orInPort);

    this->addOperation("setWaist", &RobotControl::setWaist, this, RTT::OwnThread)
            .doc("Set Torso Yaw")
            .arg("Value", "New ticks for torso yaw.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");
  
    this->addOperation("setNeck", &RobotControl::setNeck, this, RTT::OwnThread)
            .doc("Set Neck positions")
            .arg("Neck", "New ticks for neck.")
            .arg("One", "New ticks for one.")
            .arg("Two", "New ticks for two.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");
 
    this->addOperation("setLeftShoulderRoll", &RobotControl::setLeftShoulderRoll, this, RTT::OwnThread)
            .doc("Set Left Shoulder Roll")
            .arg("Value", "New ticks for left shoulder roll.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");
    
    this->addOperation("setLeftShoulderPitch", &RobotControl::setLeftShoulderPitch, this, RTT::OwnThread)
            .doc("Set Left Shoulder Pitch")
            .arg("Value", "New ticks for left shoulder pitch.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");
   
    this->addOperation("setLeftShoulderYaw", &RobotControl::setLeftShoulderYaw, this, RTT::OwnThread)
            .doc("Set Left Shoulder Yaw")
            .arg("Value", "New ticks for left shoulder yaw.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");
   
    this->addOperation("setLeftElbow", &RobotControl::setLeftElbow, this, RTT::OwnThread)
            .doc("Set Left Elbow")
            .arg("Value", "New ticks for left elbow.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("setLeftWristPitch", &RobotControl::setLeftWristPitch, this, RTT::OwnThread)
            .doc("Set Left Wrist Pitch")
            .arg("Value", "New ticks for left wrist pitch.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("setLeftWristYaw", &RobotControl::setLeftWristYaw, this, RTT::OwnThread)
            .doc("Set Left Wrist Yaw")
            .arg("Value", "New ticks for left Wrist Yaw.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("setRightShoulderRoll", &RobotControl::setRightShoulderRoll, this, RTT::OwnThread)
            .doc("Set Right Shoulder Roll")
            .arg("Value", "New ticks for right shoulder roll.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("setRightShoulderPitch", &RobotControl::setRightShoulderPitch, this, RTT::OwnThread)
            .doc("Set Right Shoulder Pitch")
            .arg("Value", "New ticks for right shoulder pitch.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("setRightShoulderYaw", &RobotControl::setRightShoulderYaw, this, RTT::OwnThread)
            .doc("Set Right Shoulder Yaw")
            .arg("Value", "New ticks for right shoulder yaw.")			
            .arg("Timestamp", "Timestamp delay (in milliseconds)");
			
    this->addOperation("setRightElbow", &RobotControl::setRightElbow, this, RTT::OwnThread)
            .doc("Set Right Elbow")
            .arg("Value", "New ticks for right elbow.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("setRightWristPitch", &RobotControl::setRightWristPitch, this, RTT::OwnThread)
            .doc("Set Right Wrist Pitch")
            .arg("Value", "New ticks for right wrist pitch.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("setRightWristYaw", &RobotControl::setRightWristYaw, this, RTT::OwnThread)
            .doc("Set Right Wrist Yaw")
            .arg("Value", "New ticks for right wrist yaw.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("setLeftHipYaw", &RobotControl::setLeftHipYaw, this, RTT::OwnThread)
            .doc("Set Left Hip Yaw")
            .arg("Value", "New ticks for left hip yaw.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("setLeftHipRoll", &RobotControl::setLeftHipRoll, this, RTT::OwnThread)
            .doc("Set Left Hip Roll")
            .arg("Value", "New ticks for left hip roll.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("setLeftHipPitch", &RobotControl::setLeftHipPitch, this, RTT::OwnThread)
            .doc("Set Left Hip Pitch")
            .arg("Value", "New ticks for left hip pitch.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("setLeftKnee", &RobotControl::setLeftKnee, this, RTT::OwnThread)
            .doc("Set Left Knee")
            .arg("Value", "New ticks for left knee.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("setLeftAnklePitch", &RobotControl::setLeftAnklePitch, this, RTT::OwnThread)
            .doc("Set Left Ankle Pitch")
            .arg("Value", "New ticks for left ankle pitch.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("setLeftAnkleRoll", &RobotControl::setLeftAnkleRoll, this, RTT::OwnThread)
            .doc("Set Left Ankle Roll")
            .arg("Value", "New ticks for left ankle roll.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("setRightHipYaw", &RobotControl::setRightHipYaw, this, RTT::OwnThread)
            .doc("Set Right Hip Yaw")
            .arg("Value", "New ticks for right hip yaw.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("setRightHipRoll", &RobotControl::setRightHipRoll, this, RTT::OwnThread)
            .doc("Set Right Hip Roll")
            .arg("Value", "New ticks for right hip roll.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("setRightHipPitch", &RobotControl::setRightHipPitch, this, RTT::OwnThread)
            .doc("Set Right Hip Pitch")
            .arg("Value", "New ticks for right hip pitch.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("setRightKnee", &RobotControl::setRightKnee, this, RTT::OwnThread)
            .doc("Set Right Knee")
            .arg("Value", "New ticks for right knee.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("setRightAnklePitch", &RobotControl::setRightAnklePitch, this, RTT::OwnThread)
            .doc("Set Right Ankle Pitch")
            .arg("Value", "New ticks for right ankle pitch.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("setRightAnkleRoll", &RobotControl::setRightAnkleRoll, this, RTT::OwnThread)
            .doc("Set Right Ankle Roll")
            .arg("Value", "New ticks for right ankle roll.")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("initRobot", &RobotControl::initRobot, this, RTT::OwnThread)
            .doc("Initialize a robot")
            .arg("Path", "The path to the XML robot representation");

    this->addOperation("enable", &RobotControl::enable, this, RTT::OwnThread)
            .arg("Board", "The board to enable")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("disable", &RobotControl::disable, this, RTT::OwnThread)
            .arg("Board", "The board to disable")
            .arg("Timestamp", "Timestamp delay (in milliseconds)");

    this->addOperation("runGesture", &RobotControl::runGesture, this, RTT::OwnThread)
            .arg("Path", "The path to the file that contains the gesture.")
            .arg("Board", "The board on which to run the gesture");

    this->written = 0;
    initRobot("/home/hubo/maestro/maestro/models/hubo_testrig.xml");

  }
  
  RobotControl::~RobotControl(){}

vector<float> trajectoryValues(string path){
    vector<float> val;

    float f;

    ifstream is;
    is.open(path.c_str());

    while (!is.eof()){
        is >> f;
        val.push_back(f/5.0); 
    } 

    return val;
}

  void RobotControl::updateHook(){
    
    hubomsg::HuboCmd huboCmd = hubomsg::HuboCmd();
    hubomsg::CanMessage canMessage = hubomsg::CanMessage();
    if (NewData == this->canUpPort->read(canMessage)){
        //Received update from CanGateway
        
    }
    if (NewData == this->orOutPort->read(huboCmd)){
        //Recieved update from openRAVE
    }
   
    //Write out a message if we have one

    //TODO: as per dan's suggestion, try to send all positions every time  

    MotorBoard* mb = this->state->getBoardByNumber(BNO_R_HIP_YAW_ROLL);
/*    if (mb != NULL)
        outputQueue->push(buildCanMessage(mb->sendPositionReference(mb->getMotorByChannel(0)->getTicksPosition(), mb->getMotorByChannel(1)->getTicksPosition())));
 */
    if (!outputQueue->empty()){
        this->canDownPort->write(outputQueue->front());
        //std::cout << ++written << std::endl;
        outputQueue->pop();
    }
    else{
        if (mb != NULL){
            canMsg* out = new canMsg(BNO_R_HIP_YAW_ROLL, TX_REF, (cmdType)2,
                                 mb->getMotorByChannel(0)->getTicksPosition(), 
                                 mb->getMotorByChannel(1)->getTicksPosition(), 0, 0, 0, 0, 0, 0);
 
            outputQueue->push(buildCanMessage(out));
            this->canDownPort->write(outputQueue->front());
        }
    }
  }

  hubomsg::CanMessage RobotControl::buildCanMessage(canMsg* msg){
      hubomsg::CanMessage canMessage;

      canMessage.bno = msg->getBNO();
      canMessage.mType = msg->getType();
      canMessage.cmdType = msg->getCmd();
      canMessage.r1 = msg->getR1();
      canMessage.r2 = msg->getR2();
      canMessage.r3 = msg->getR3();
      canMessage.r4 = msg->getR4();
      canMessage.r5 = msg->getR5();
      canMessage.r6 = msg->getR6();
      canMessage.r7 = msg->getR7();
      canMessage.r8 = msg->getR8();

      return canMessage;
  }

  void RobotControl::initRobot(string path){
      this->state = new HuboState();
      if (path == "")
          path == "/home/hubo/maestro/maestro/models/hubo_testrig.xml";
      
      //@TODO: Check for file existence before initializing.
      this->state->initHuboWithDefaults(path, this->outputQueue);
  }

  void RobotControl::setWaist(int ticks, int delay){
      //ros_gateway->transmit(0,ticks);
      this->state->getBoardByNumber(BNO_WAIST)->sendPositionReference(ticks, 0);
  }

  void RobotControl::setNeck(int ticks, int one, int two, int delay){
      this->state->getBoardByNumber(BNO_NECK_YAW_1_2)->sendPositionReference(ticks, one, two);
     //ros_gateway->transmit(1,ticks);
  }

  void RobotControl::setLeftShoulderRoll(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_L_SHOULDER_PITCH_ROLL);
      mb->sendPositionReference(mb->getMotorByChannel(0)->getTicksPosition(), ticks);
     //ros_gateway->transmit(3,ticks);
  }

  void RobotControl::setLeftShoulderPitch(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_L_SHOULDER_PITCH_ROLL);
      mb->sendPositionReference(ticks, mb->getMotorByChannel(1)->getTicksPosition());
     //ros_gateway->transmit(4,ticks);
  }
  
  void RobotControl::setLeftShoulderYaw(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_L_SHOULDER_YAW_ELBOW);
      mb->sendPositionReference(ticks, mb->getMotorByChannel(1)->getTicksPosition());
     //ros_gateway->transmit(6,ticks);
  }

  void RobotControl::setLeftElbow(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_L_SHOULDER_YAW_ELBOW);
      mb->sendPositionReference(mb->getMotorByChannel(0)->getTicksPosition(), ticks);
     //ros_gateway->transmit(6,ticks);
  }

  void RobotControl::setLeftWristPitch(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_L_WRIST_YAW_PITCH);
      mb->sendPositionReference(mb->getMotorByChannel(0)->getTicksPosition(), ticks);
     //ros_gateway->transmit(8,ticks);
  }

  void RobotControl::setLeftWristYaw(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_L_WRIST_YAW_PITCH);
      mb->sendPositionReference(ticks, mb->getMotorByChannel(1)->getTicksPosition());
      //ros_gateway->transmit(9,ticks);
  }

  void RobotControl::setRightShoulderRoll(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_R_SHOULDER_PITCH_ROLL);
      mb->sendPositionReference(mb->getMotorByChannel(0)->getTicksPosition(), ticks);
      //ros_gateway->transmit(11,ticks);
  }

  void RobotControl::setRightShoulderPitch(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_R_SHOULDER_PITCH_ROLL);
      mb->sendPositionReference(ticks, mb->getMotorByChannel(1)->getTicksPosition());
      //ros_gateway->transmit(12,ticks);
  }

  void RobotControl::setRightShoulderYaw(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_R_SHOULDER_YAW_ELBOW);
      mb->sendPositionReference(ticks, mb->getMotorByChannel(1)->getTicksPosition());
  }
  
  void RobotControl::setRightElbow(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_R_SHOULDER_YAW_ELBOW);
      mb->sendPositionReference(mb->getMotorByChannel(0)->getTicksPosition(), ticks);
      //ros_gateway->transmit(14,ticks);
  }

  void RobotControl::setRightWristPitch(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_R_WRIST_YAW_PITCH);
      mb->sendPositionReference(mb->getMotorByChannel(0)->getTicksPosition(), ticks);
      //ros_gateway->transmit(16,ticks);
  }

  void RobotControl::setRightWristYaw(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_R_WRIST_YAW_PITCH);
      mb->sendPositionReference(ticks, mb->getMotorByChannel(1)->getTicksPosition());
      //ros_gateway->transmit(17,ticks);
  }

  void RobotControl::setLeftHipYaw(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_L_HIP_YAW_ROLL);
      mb->sendPositionReference(ticks, mb->getMotorByChannel(1)->getTicksPosition());
      //ros_gateway->transmit(19,ticks);
  }

  void RobotControl::setLeftHipRoll(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_L_HIP_YAW_ROLL);
      mb->sendPositionReference(mb->getMotorByChannel(0)->getTicksPosition(), ticks);
      //ros_gateway->transmit(20,ticks);
  }

  void RobotControl::setLeftHipPitch(int ticks, int delay){
      this->state->getBoardByNumber(BNO_L_HIP_PITCH)->sendPositionReference(ticks, 0);
      //ros_gateway->transmit(21,ticks);
  }

  void RobotControl::setLeftKnee(int ticks, int delay){
      this->state->getBoardByNumber(BNO_L_KNEE)->sendPositionReference(ticks, 0);
      //ros_gateway->transmit(22,ticks);
  }

  void RobotControl::setLeftAnklePitch(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_L_ANKLE_PITCH_ROLL);
      mb->sendPositionReference(ticks, mb->getMotorByChannel(1)->getTicksPosition());
      //ros_gateway->transmit(23,ticks);
  }

  void RobotControl::setLeftAnkleRoll(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_L_ANKLE_PITCH_ROLL);
      mb->sendPositionReference(mb->getMotorByChannel(0)->getTicksPosition(), ticks);
      //ros_gateway->transmit(24,ticks);
  }

  void RobotControl::setRightHipYaw(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_R_HIP_YAW_ROLL);
      mb->sendPositionReference(ticks, mb->getMotorByChannel(1)->getTicksPosition());
      //ros_gateway->transmit(26,ticks);
      //this->canDownPort->write(buildCanMessage(out));
  }

  void RobotControl::setRightHipRoll(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_R_HIP_YAW_ROLL);
      mb->sendPositionReference(mb->getMotorByChannel(0)->getTicksPosition(), ticks);
      //ros_gateway->transmit(27,ticks);
  }

  void RobotControl::setRightHipPitch(int ticks, int delay){
      this->state->getBoardByNumber(BNO_R_HIP_PITCH)->sendPositionReference(ticks, 0);
      //ros_gateway->transmit(28,ticks);
  }

  void RobotControl::setRightKnee(int ticks, int delay){
      this->state->getBoardByNumber(BNO_R_KNEE)->sendPositionReference(ticks, 0); 
      //ros_gateway->transmit(29,ticks);
  }

  void RobotControl::setRightAnklePitch(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_R_ANKLE_PITCH_ROLL);
      mb->sendPositionReference(ticks, mb->getMotorByChannel(1)->getTicksPosition());
      //ros_gateway->transmit(30,ticks);
  }

  void RobotControl::setRightAnkleRoll(int ticks, int delay){
      MotorBoard* mb = this->state->getBoardByNumber(BNO_R_ANKLE_PITCH_ROLL);
      mb->sendPositionReference(mb->getMotorByChannel(0)->getTicksPosition(), ticks);
      //ros_gateway->transmit(31,ticks);
  }

  void RobotControl::setRightHand(int f0, int f1, int f2, int f3, int f4, int delay){
      this->state->getBoardByNumber(BNO_R_HAND)->sendPositionReference(f0, f1, f2, f3, f4);
  }

  void RobotControl::setLeftHand(int f0, int f1, int f2, int f3, int f4, int delay){
      this->state->getBoardByNumber(BNO_L_HAND)->sendPositionReference(f0, f1, f2, f3, f4);
  }

  void RobotControl::enable(int board, int delay){
      this->state->getBoardByNumber(board)->setHIP(1);
      this->state->getBoardByNumber(board)->enableController();
  }

  void RobotControl::disable(int board, int delay){
      this->state->getBoardByNumber(board)->setHIP(0);
      this->state->getBoardByNumber(board)->disableController();
      this->state->getBoardByNumber(board)->requestEncoderPosition(0);
  }

  void RobotControl::runGesture(string path, int board){
      int val = 0;
      vector<float> trajVal;
      if (this->gestures.find(path) != this->gestures.end())
          trajVal = this->gestures[path];
      else{
          trajVal = trajectoryValues(path);
          this->gestures[path] = trajVal;
      }
      for (int i = 0; i < (int)trajVal.size(); i++){
          val = (int)trajVal.at(i);
          this->state->getBoardByNumber(board)->sendPositionReference(val, val);     
      }
  }

ORO_CREATE_COMPONENT_LIBRARY()
ORO_LIST_COMPONENT_TYPE(RobotControl)
