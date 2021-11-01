#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream fin("yourtxtname.txt");
    std::ofstream fout("output.txt");
    std::string line;
    if(fin){
        int16_t i = 0;
        while(std::getline(fin, line)){
            i++;
            // if(i % 2 == 0){
            //     fout << line << std::endl;
            //     std::cout << line << std::endl;
            // }
            // else continue;
            // 隔行读取

            //隔列读取
            //     bool spaceflag = false;
            //     std::string temp;
            //     for(int32_t k{0};k < line.length();k++){
            //         if(spaceflag){
            //             if(line[k] == ' '){
            //                 spaceflag = false;//再次遇到空格后转为false
            //                 temp += line[k];
            //                 continue;
            //             }
            //             else continue;
            //         }
            //         else{
            //             if(line[k] == ' '){
            //                 spaceflag = true;
            //                 continue;
            //             }
            //             else temp += line[k];
            //         }
            //     }
            //     fout << temp << std::endl;

            //隔行隔列读取
            if(i % 2 == 0){
                bool spaceflag = false;
                std::string temp;
                for(int32_t k{0};k < line.length();k++){
                    if(spaceflag){
                        if(line[k] == ' '){
                            spaceflag = false;//再次遇到空格后转为false
                            temp += line[k];
                            continue;
                        }
                        else continue;
                    }
                    else{
                        if(line[k] == ' '){
                            spaceflag = true;
                            continue;
                        }
                        else temp += line[k];
                    }
                }
                fout << temp << std::endl;
            }
        }
    }
    else{
        std::cout << "Read txt failed." << std::endl;
    }
    fout.close();
    return 0;
}