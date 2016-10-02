#include "ysh.hpp"

void YSH::start() {
  show_line();
  std::string cmd;
  while(true) {
    char c = getchar();
    if(c == '\n') {
      run_cmd(cmd);
      cmd = "";
      show_line();
    } else cmd += c;
  }
}

int YSH::run_cmd(std::string str_cmdline) {
  auto split = [](std::string str) -> std::vector<std::string> {
    std::string item;
    std::vector<std::string> v;
    for(auto c : str) {
      if(c == ' ') {
        v.push_back(item);
        item = "";
      } else item += c;
    }
    if(!item.empty()) v.push_back(item);
    return v;
  };
  std::cout << "running command: " << str_cmdline << std::endl;
  auto cmdline = split(str_cmdline);
  if(isalpha(cmdline[0][0])) {
    std::string cmd = cmdline[0];
    if(cmd == "cd") {
      cur_dir.push_back(cmdline[1]);
    }
  }

  return 0;
}

void YSH::show_line() {
  std::cout << default_theme << " ";
}
