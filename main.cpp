#include <vector>
#include "interface.h"
#include <gtest/gtest.h>
int main(int argc, char**argv) {
   std::vector<interface::interface*> interfaces(4);
    interface::onlineInterface onlineInterface;
    interfaces.at(0) = &onlineInterface;
    interface::onlineInterfaceWithoutInputFile onlineInterfaceWithoutInputFile;
    interfaces.at(1) = &onlineInterfaceWithoutInputFile;
    interface::offlineInterfaceV1 offlineInterfaceV1;
    interfaces.at(2) = &offlineInterfaceV1;
    interface::offlineInterfaceV2 offlineInterfaceV2;
    interfaces.at(3) = &offlineInterfaceV2;
    for (int i = 0; i < 3; ++i){
        if ((interfaces.at(i)->toHhandle(argc))){
            interfaces.at(i)->handel(argv);
        }
    }
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}
