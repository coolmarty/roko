#include "gtest/gtest.h"
#include "compositeentityfactory.h"


class CompositeEntityFactoryTest : public ::testing::Test {
public:
  void SetUp( ) {
    entityJsons.push_back("{\"cameras\":[1],\"command\":\"createEntity\",\"direction\":[1,0,0],\"entityId\":1,\"id\":3,\"name\":\"hospital\",\"path\":\"hospital.glb\",\"position\":[-40,0,2],\"radius\":1,\"rotation\":[0,0,0],\"scale\":[1,1,1],\"type\":\"destination\"}");
    entityJsons.push_back("{\"cameras\":[3],\"command\":\"createEntity\",\"direction\":[1,0,0],\"entityId\":3,\"id\":2799,\"name\":\"robot\",\"path\":\"robot.glb\",\"position\":[56.139513282630787,0,3.3961168294766111],\"radius\":1,\"rotation\":[0,0,0],\"scale\":[0.25,0.25,0.25],\"type\":\"actee\"}");
    entityJsons.push_back("{\"cameras\":[2],\"command\":\"createEntity\",\"direction\":[1,0,0],\"entityId\":2,\"id\":3,\"name\":\"recharge station\",\"path\":\"charger.glb\",\"position\":[50,0,20],\"radius\":1,\"rotation\":[0,0,0],\"scale\":[1,1,1],\"type\":\"charger\"}");
    entityJsons.push_back("{\"cameras\":[0],\"charge\":20,\"command\":\"createEntity\",\"direction\":[0,0,0],\"duration\":2,\"entityId\":0,\"id\":1,\"name\":\"drone\",\"offset\":[0,0.59999999999999998,0],\"path\":\"drone.glb\",\"position\":[0,2.5,0],\"radius\":1,\"rotation\":[0,0,0],\"scale\":[0.14999999999999999,0.14999999999999999,0.14999999999999999],\"speed\":4,\"start\":2,\"type\":\"actor\"}");
    }
protected:
  std::vector<std::string> entityJsons;
};

TEST_F(CompositeEntityFactoryTest, GoodJson) {
  CompositeEntityFactory factory=CompositeEntityFactory();

  for(int i=0;i<entityJsons.size();i++){
    picojson::value v;
    picojson::object o;
    std::string err = picojson::parse(v, entityJsons[i]);

    if (! err.empty()) {
      std::cerr << err << std::endl;
      EXPECT_TRUE(false);
      return;
    }

    if (v.is<picojson::object>()) {
       o = v.get<picojson::object>();
    }
    else{
      std::cerr<<"not an object"<<std::endl;
      EXPECT_TRUE(false);
      return;
    }
    Entity *ent = factory.create(o);
    EXPECT_TRUE(ent);//just testing that it actually makes an entity
    delete ent;
  }
}

// these are jsons that either don't make sense or shouldn't make anything
TEST_F(CompositeEntityFactoryTest, BadJson) {
  CompositeEntityFactory factory=CompositeEntityFactory();
  std::vector<std::string> badjson;
  //empty string
  badjson.push_back("");
  //not even json
  badjson.push_back("Hello yes I am an object");
  //not the object we're looking for
  badjson.push_back("{\"name\":\"Whole sale chinese vegetable prices\",\"veggie_prices\":77.8625,\"region\":\"ur mom's house\"}");
  //an array not an object
  badjson.push_back("[{\"cameras\":[1],\"command\":\"createEntity\",\"direction\":[1,0,0],\"entityId\":1,\"id\":3,\"name\":\"hospital\",\"path\":\"hospital.glb\",\"position\":[-40,0,2],\"radius\":1,\"rotation\":[0,0,0],\"scale\":[1,1,1],\"type\":\"destination\"}]");
  //an object but no name matches
  badjson.push_back("{\"cameras\":[1],\"command\":\"createEntity\",\"direction\":[1,0,0],\"entityId\":1,\"id\":3,\"name\":\"jeffryTheHospital\",\"path\":\"hospital.glb\",\"position\":[-40,0,2],\"radius\":1,\"rotation\":[0,0,0],\"scale\":[1,1,1],\"type\":\"destination\"}");

  picojson::value v;
  picojson::object o;
  for(int i=0;i<badjson.size();i++){
    std::string err = picojson::parse(v, badjson[i]);

    if (! err.empty()) {
      std::cerr << err << std::endl;
      continue;
    }

    if (v.is<picojson::object>()) {
       o = v.get<picojson::object>();
    }
    else{
      std::cerr<<"Not an object"<<std::endl;
      continue;
    }
    Entity *ent = factory.create(o);
    EXPECT_FALSE(ent);//just testing that it doesnt actually makes an entity
    delete ent;
  }
}
