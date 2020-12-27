# Gale

A syntheizer plugin.

__Under development__


## Development environment

### Setting up dependencies

__wxWidgets__

wxWidgets version 3.1.4 needs to be built from sources. Maybe a distribution from package manager works well too, but it might not have some features - for example, static libraries.

Build wxWidgets in a separate direcotry:
```bash
git clone --depth 1 --branch v3.1.4  git@github.com:wxWidgets/wxWidgets.git
cd wxWidgets
git submodule init
git submodule update
cmake -DwxBUILD_SHARED=ON -DwxBUILD_MONOLITHIC=OFF .
cmake --build . --config Release
cmake --install . --config Release # for Linux. Windows will need configuration of paths in CMakeLists.txt instead of looking up the library from system path
```




### Native app

```bash
cmake . -Dtype=native -DwxWidgets_USE_STATIC=OFF

cmake --build .
```

## Roadmap

Just some ideas:

- Outputs
  - LV2
  - VST
- Wave generators
  - Sine, square, triangle, saw
  - Wavetables (?)
- Effects
  - Reverb
  - Delay
- Routing
  - Feedback