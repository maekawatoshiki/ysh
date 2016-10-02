#pragma once

#include "common.hpp"

class YSH {
  private:
    std::string default_theme = "$";
    std::map<std::string, std::string> env; // environment variable
    std::vector<std::string> cur_dir;

  public:
    YSH() {};
    ~YSH() {};
    void start();

    int run_cmd(std::string);
    void show_line();
};
