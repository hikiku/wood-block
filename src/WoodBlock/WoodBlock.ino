#include "WoodData.h"
#include "WoodEvent.h"
#include "WoodBlock.h"
#include "WoodBlockContainer.h"

// For user extend data type
extern bool extend_check4ConnectDataType(unsigned int outDataType, unsigned int inDataType)
{
  return false;
}

class WebPortal : public WoodServiceInterfaceBlock
{
public:
  WebPortal(const String &name) : WoodServiceInterfaceBlock(name) {}
  ~WebPortal() {}
  void executionInEvent(WoodInEvent &inEvent)
  {
    // ......
  }
  WoodServiceInterfaceInEvent *captureServiceInterfaceInEvent()
  {
    // TODO: ......
    return nullptr;
  }
  void executionServiceInterfaceInEvent(WoodServiceInterfaceInEvent &siiEvent)
  {
    // ......
  }
};

class OccupySensor : public WoodServiceInterfaceBlock
{
public:
  OccupySensor(const String &name) : WoodServiceInterfaceBlock(name) {}
  ~OccupySensor() {}
  void executionInEvent(WoodInEvent &inEvent)
  {
    // ......
  }
  WoodServiceInterfaceInEvent *captureServiceInterfaceInEvent()
  {
    // TODO: ......
    return nullptr;
  }
  void executionServiceInterfaceInEvent(WoodServiceInterfaceInEvent &siiEvent)
  {
    // ......
  }
};

class Relay : public WoodBlock
{
public:
  Relay(const String &name) : WoodBlock(name) {}
  ~Relay() {}
  void executionInEvent(WoodInEvent &inEvent)
  {
    // ......
  }
};

Relay relay("relay");
OccupySensor occupySensor("occupySensor");
WebPortal webPortal("webPortal");

WoodBlockContainer blockContainer;

void setup()
{
  // put your setup code here, to run once:

  blockContainer.hostWoodBlock(relay);
  blockContainer.hostWoodBlock(occupySensor);
  blockContainer.hostWoodBlock(webPortal);

  // TODO: INIT!
  {
    const char *outVariableNames[] = {"occupied"};
    const char *inVariableNames[] = {"occupied"};

    blockContainer.connect("occupySensor", "status", outVariableNames, sizeof(outVariableNames) / sizeof(outVariableNames[0]),
                           "webPortal", "occupyStatus", inVariableNames, sizeof(inVariableNames) / sizeof(inVariableNames[0]));
  }
  {
    const char *outVariableNames[] = {"relayOnOff"};
    const char *inVariableNames[] = {"onOff"};
    blockContainer.connect("webPortal", "relayControl", outVariableNames, sizeof(outVariableNames) / sizeof(outVariableNames[0]),
                           "webPortal", "control", inVariableNames, sizeof(inVariableNames) / sizeof(inVariableNames[0]));
  }
}

void loop()
{
  // put your main code here, to run repeatedly:

  occupySensor.fetchExternalEvents();
  webPortal.fetchExternalEvents();
}