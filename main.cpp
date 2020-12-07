//BenjaminKramer
//12-7-2020

//An illustration of Threads
//demonstrating how file transferring
//with folders can be handled
#include <iostream>
#include <thread>
#include <chrono>

void folderTransferA(void) {
        int loop = 0;
        // Loops a 75 times
        while(loop < 75) {
            // Sleep for 0.55 seconds
            std::this_thread::sleep_for(std::chrono::milliseconds(0555));
            std::cout << "Folder 1 Transfering: " << loop << std::endl;
            loop++;
        }
        if(loop == 75){
          std::cout << "\nFolder 1 DONE\n" << std::endl;
        }
}

void folderTransferB(void) {
        int loop = 0;
        // loops a 250 times
        while(loop < 250) {
          // Sleep for 0.33 seconds
           std::this_thread::sleep_for(std::chrono::milliseconds(0333));
           std::cout << "Folder 2 Transfering: " << loop << std::endl;
           loop++;
        }
        if(loop == 250){
          std::cout << "\nFolder 2 DONE\n" << std::endl;
        }
}

void folderTransferC(void) {
        int loop = 0;
        // loops a 150 times
        while(loop < 150) {
          // Sleep for 0.44 seconds
           std::this_thread::sleep_for(std::chrono::milliseconds(0444));
           std::cout << "Folder 3 Transfering: " << loop << std::endl;
           loop++;
        }
        if(loop == 150){
          std::cout << "\nFolder 3 DONE\n" << std::endl;
        }
}

void folderTransferD(void) {
        int loop = 0;
        // loops a 700 times
        while(loop < 700) {
          // Sleep for 0.11 seconds
           std::this_thread::sleep_for(std::chrono::milliseconds(0111));
           std::cout << "Folder 4 Transfering: " << loop << std::endl;
           loop++;
        }
        if(loop == 700){
          std::cout << "\nFolder 4 DONE\n" << std::endl;
        }
}

int main() {
   char result;
   //"volatile" is to ask compiler not to optimize the loop away
   volatile int i = 0;
   //start timer
   auto start = std::chrono::steady_clock::now();
    while (i < 10000) {
        ++i;
    }
   //the threads for the folders
   std::thread folder_threadA(folderTransferA); 
   std::thread folder_threadB(folderTransferB);
   std::thread folder_threadC(folderTransferC); 
   std::thread folder_threadD(folderTransferD);  
  
   std::cout << "Folders will now start transfering files" << std::endl;
   //allowing the threads to run at the same time
   folder_threadA.join();
   folder_threadB.join();
   folder_threadC.join();
   folder_threadD.join();
   
   //end timer
   auto end = std::chrono::steady_clock::now();
   //calculate time elapsed
   auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    std::cout << "It took " << elapsed.count() << " seconds to transfer your files from their folders!" << std::endl;
   
   return 0;
}
