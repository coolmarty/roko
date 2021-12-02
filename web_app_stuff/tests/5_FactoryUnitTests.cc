#include "gtest/gtest.h"
#include "hospitalfactory.h"
#include "dronefactory.h"
#include "rechargestationfactory.h"
#include "robotfactory.h"
#include "compositeentityfactory.h"


class HospitalFactoryTest : public ::testing::Test {
public:
  void SetUp( ) {
    hospital_json="{\"cameras\":[1],\"command\":\"createEntity\",\"direction\":[1,0,0],\"entityId\":1,\"id\":3,\"name\":\"hospital\",\"path\":\"hospital.glb\",\"position\":[-40,0,2],\"radius\":1,\"rotation\":[0,0,0],\"scale\":[1,1,1],\"type\":\"destination\"}";
    hospitalFactory = HospitalFactory();
  }
protected:
  std::string hospital_json;
  HospitalFactory hospitalFactory;
};

class RobotFactoryTest : public ::testing::Test {
public:
  void SetUp( ) {
    robot_json ="{\"cameras\":[3],\"command\":\"createEntity\",\"direction\":[1,0,0],\"entityId\":3,\"id\":2799,\"name\":\"robot\",\"path\":\"robot.glb\",\"position\":[56.139513282630787,0,3.3961168294766111],\"radius\":1,\"rotation\":[0,0,0],\"scale\":[0.25,0.25,0.25],\"type\":\"actee\"}";
    robotFactory=RobotFactory();
  }
protected:
  std::string robot_json;
  RobotFactory robotFactory;
};

class RechargeFactoryTest : public ::testing::Test {
public:
  void SetUp( ) {
    recharge_json ="{\"cameras\":[2],\"command\":\"createEntity\",\"direction\":[1,0,0],\"entityId\":2,\"id\":3,\"name\":\"recharge station\",\"path\":\"charger.glb\",\"position\":[50,0,20],\"radius\":1,\"rotation\":[0,0,0],\"scale\":[1,1,1],\"type\":\"charger\"}";
    rechargeStationFactory=RechargeStationFactory();
  }
protected:
  std::string recharge_json;
  RechargeStationFactory rechargeStationFactory;
};

class DroneFactoryTest : public ::testing::Test {
public:
  void SetUp( ) {
    drone_json="{\"cameras\":[0],\"charge\":20,\"command\":\"createEntity\",\"direction\":[0,0,0],\"duration\":2,\"entityId\":0,\"id\":1,\"name\":\"drone\",\"offset\":[0,0.59999999999999998,0],\"path\":\"drone.glb\",\"position\":[0,2.5,0],\"radius\":1,\"rotation\":[0,0,0],\"scale\":[0.14999999999999999,0.14999999999999999,0.14999999999999999],\"speed\":4,\"start\":2,\"type\":\"actor\"}";
    droneFactory=DroneFactory();
  }
protected:
  std::string drone_json;
  DroneFactory droneFactory;
};

class CompositeFactoryTest : public ::testing::Test {
public:
  void SetUp( ) {
    compositeEntityFactory=CompositeEntityFactory();
    drone_json= "{\"cameras\":[0],\"charge\":20,\"command\":\"createEntity\",\"direction\":[0,0,0],\"duration\":2,\"entityId\":0,\"id\":1,\"name\":\"drone\",\"offset\":[0,0.59999999999999998,0],\"path\":\"drone.glb\",\"position\":[0,2.5,0],\"radius\":1,\"rotation\":[0,0,0],\"scale\":[0.14999999999999999,0.14999999999999999,0.14999999999999999],\"speed\":4,\"start\":2,\"type\":\"actor\"}";
    robot_json = "{\"cameras\":[3],\"command\":\"createEntity\",\"direction\":[1,0,0],\"entityId\":3,\"id\":2799,\"name\":\"robot\",\"path\":\"robot.glb\",\"position\":[56.139513282630787,0,3.3961168294766111],\"radius\":1,\"rotation\":[0,0,0],\"scale\":[0.25,0.25,0.25],\"type\":\"actee\"}";
    hospital_json="{\"cameras\":[1],\"command\":\"createEntity\",\"direction\":[1,0,0],\"entityId\":1,\"id\":3,\"name\":\"hospital\",\"path\":\"hospital.glb\",\"position\":[-40,0,2],\"radius\":1,\"rotation\":[0,0,0],\"scale\":[1,1,1],\"type\":\"destination\"}";
    recharge_json ="{\"cameras\":[2],\"command\":\"createEntity\",\"direction\":[1,0,0],\"entityId\":2,\"id\":3,\"name\":\"recharge station\",\"path\":\"charger.glb\",\"position\":[50,0,20],\"radius\":1,\"rotation\":[0,0,0],\"scale\":[1,1,1],\"type\":\"charger\"}";

  }
protected:
  std::string drone_json;
  std::string robot_json;
  std::string hospital_json;
  std::string recharge_json;
  CompositeEntityFactory compositeEntityFactory;
};

TEST_F(HospitalFactoryTest, CreateHospital) {
  picojson::value v;

  std::string err = picojson::parse(v, hospital_json);
  picojson::object o;
  if (! err.empty()) {
    std::cerr << err << std::endl;
    EXPECT_TRUE(false);
    return;
  }

  if (v.is<picojson::object>()) {
     o = v.get<picojson::object>();
  }
  else{
    std::cerr<<"Not an object"<<std::endl;
    EXPECT_TRUE(false);
    return;
  }


  Entity *hosp = hospitalFactory.create(o);

  Point3 expectedPos = Point3(-40,0,2);
  Point3 actualPos = hosp->GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedDir = Vector3(1,0,0);
  Vector3 actualDir = hosp->GetDirection();
  EXPECT_EQ(actualDir.GetX(),expectedDir.GetX());
  EXPECT_EQ(actualDir.GetY(),expectedDir.GetY());
  EXPECT_EQ(actualDir.GetZ(),expectedDir.GetZ());

  EXPECT_EQ(hosp->GetId(),1);
}

TEST_F(RobotFactoryTest, CreateRobot) {
  picojson::value v;

  std::string err = picojson::parse(v, robot_json);
  picojson::object o;
  if (! err.empty()) {
    std::cerr << err << std::endl;
    EXPECT_TRUE(false);
    return;
  }

  if (v.is<picojson::object>()) {
     o = v.get<picojson::object>();
  }
  else{
    std::cerr<<"Not an object"<<std::endl;
    EXPECT_TRUE(false);
    return;
  }



  Entity *robot = robotFactory.create(o);

  Point3 expectedPos = Point3(56.139513282630787,0,3.3961168294766111);
  Point3 actualPos = robot->GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedDir = Vector3(1,0,0);
  Vector3 actualDir = robot->GetDirection();
  EXPECT_EQ(actualDir.GetX(),expectedDir.GetX());
  EXPECT_EQ(actualDir.GetY(),expectedDir.GetY());
  EXPECT_EQ(actualDir.GetZ(),expectedDir.GetZ());

  EXPECT_EQ(robot->GetId(),3);
}

TEST_F(RechargeFactoryTest, CreateRechargeStation) {
  picojson::value v;

  std::string err = picojson::parse(v, recharge_json);
  picojson::object o;
  if (! err.empty()) {
    std::cerr << err << std::endl;
    EXPECT_TRUE(false);
    return;
  }

  if (v.is<picojson::object>()) {
     o = v.get<picojson::object>();
  }
  else{
    std::cerr<<"Not an object"<<std::endl;
    EXPECT_TRUE(false);
    return;
  }

  Entity *station = rechargeStationFactory.create(o);

  Point3 expectedPos = Point3(50,0,20);
  Point3 actualPos = station->GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedDir = Vector3(1,0,0);
  Vector3 actualDir = station->GetDirection();
  EXPECT_EQ(actualDir.GetX(),expectedDir.GetX());
  EXPECT_EQ(actualDir.GetY(),expectedDir.GetY());
  EXPECT_EQ(actualDir.GetZ(),expectedDir.GetZ());

  EXPECT_EQ(station->GetId(),2);
}
