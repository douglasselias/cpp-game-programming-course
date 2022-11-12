cxx := "clang++"
flags := "src/*.cpp -std=c++17 -Isrc -Os -Wall -Werror -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -o"
version := "0.0.0"
build-path := "build"
build-file := build-path / "game-v" + version
main := "main.cpp"

run:
  just build
  ./{{build-file}}

build:
  mkdir -p {{build-path}}
  {{cxx}} {{flags}} {{build-file}} {{main}}

clean:
  rm build/** && rm build