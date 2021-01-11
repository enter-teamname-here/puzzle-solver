#include "puzzle_parser.h"

#include <rapidjson/document.h>

#include <stdexcept>
#include <string>
#include <vector>

namespace puzzlelib {
Puzzle PuzzleParser::ParsePuzzleJSON(std::string json) {
  rapidjson::Document doc;
  doc.Parse(json.c_str());
  int height = doc["dimension"]["height"].GetInt(),
      width = doc["dimension"]["width"].GetInt();
  std::vector<int> cell_contents;
  for (auto& val : doc["cell_contents"].GetArray())
    cell_contents.push_back(val.GetInt());
}
}  // namespace puzzlelib
