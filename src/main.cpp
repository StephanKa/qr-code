#include "include/version.hpp"
#include <docopt/docopt.h>
#include <functional>
#include <iostream>
#include <spdlog/spdlog.h>
#include <string>

static constexpr auto USAGE =
  R"(Naval Fate.

    Usage:
          naval_fate ship new <name>...
          naval_fate ship <name> move <x> <y> [--speed=<kn>]
          naval_fate ship shoot <x> <y>
          naval_fate mine (set|remove) <x> <y> [--moored | --drifting]
          naval_fate (-h | --help)
          naval_fate --version
 Options:
          -h --help     Show this screen.
          --version     Show version.
          --speed=<kn>  Speed in knots [default: 10].
          --moored      Moored (anchored) mine.
          --drifting    Drifting mine.
)";

int main(int argc, const char **argv)
{
    fmt::print(R"(Version
    Major {}
    Minor {}
    Patch {}
    Git Hash {}
)",
      Version::Major,
      Version::Minor,
      Version::Patch,
      Version::GitHash);

    std::map<std::string, docopt::value> args = docopt::docopt(USAGE,
      { std::next(argv), std::next(argv, argc) },
      true,// show help if requested
      "Naval Fate 2.0");// version string

    for (auto const &arg : args) {
        fmt::print(R"(
{} {}
)",
          arg.first,
          arg.second.asString());
    }

    // Use the default logger (stdout, multi-threaded, colored)
    spdlog::info("Hello, {}!", "World");

    fmt::print("Hello, from {}\n", "{fmt}");
}
