#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> listTxtFiles() {
    std::vector<std::string> txtFiles;
    for (const auto& entry : std::filesystem::directory_iterator("data/")) {
      if (entry.is_regular_file() && entry.path().extension() == ".txt") {
        txtFiles.push_back(entry.path().filename().string());
      }
    }
    return txtFiles;
}

int main(){
    std::vector<std::string> files = listTxtFiles();
    std::vector<float> data;
    for (int i = 0; i < files.size(); i++) {
        std::ifstream in (files[i]);
        for (int j = 0; j < 5; j++) {
            for (int z = 0; z < 4; z++) {
                in.ignore()

            }
        }
    }

}

