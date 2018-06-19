// for testing purpose

#include <iostream>
#include "argparse.hpp"

int main(int, const char **argv) {
  // first several steps
  ts::ArgParser parser;
  ts::ArgParser::Command &top_command = parser.top_command();

  // do stuff with top_command
  top_command.add_option("--global", "-g", "a global switch", "", 2);

  // two basic commands
  ts::ArgParser::Command &init_command =
      top_command.add_subcommand("init", "initialize traffic shit", "HOME", 1);
  ts::ArgParser::Command &remove_command = top_command.add_subcommand(
      "remove", "remove traffic shit", "REMOVE_ENV", 0);

  init_command.add_option("--initoption", "-i", "some option of init");
  init_command.add_option("--initoption2", "-j", "init2 option", "ABC", 1);
  init_command.add_subcommand("subinit", "sub initialize traffic shit");
  init_command.add_subcommand("subinit2", "sub initialize traffic shit", "", 2)
      .add_option("--abc", "-x", "some testing", "", 1);

  remove_command.add_subcommand("subremove", "sub remove traffic shit")
      .add_subcommand("subsubremove", "sub sub remove");
  remove_command.add_option("--removeswitch", "-i", "some removeswitch");

  parser.show_parser_info();
  std::cout << "=================================================="
            << std::endl;
  ts::ParsedArgs parsed_data = parser.parse(argv);
  parsed_data.show_all_configuration();
  return 0;
}