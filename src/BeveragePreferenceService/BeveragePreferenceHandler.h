#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{

class BeveragePreferenceServiceHandler : public BeveragePreferenceServiceIf {
 public:
  BeveragePreferenceServiceHandler();
  ~BeveragePreferenceServiceHandler() override=default;

  string::type GetBeverage(BeverageType btype) override;
};

// Constructor
BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() {

}

// Remote Procedure "PlaceOrder"

string::type BeveragePreferenceServiceHandler::GetBeverage(BeverageType btype) {
     // Your implementation goes here
     printf("GetBeverage\n");
     string hotbev [3] = {“cappuccino”, “latte”, “espresso”};
     string coldbev[3] = {“lemonade”, “ice tea”, “soda”};
     int RandIndex = rand() % 3;

    // randomly select a weather
    if(btype == HOT){
    	return(coldbev[RandIndex])
    }
    else{
    	return(hotbev[RandIndex])
    }
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H

