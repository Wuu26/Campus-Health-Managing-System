# QtTeamApp

跨平台 Qt 6 项目，使用 CMake 构建，适配 macOS 和 Windows，适合小组协作开发。

## 📦 项目结构
├── CMakeLists.txt
├── src/
│   └── main.cpp
├── .vscode/
│   └── settings.json
├── .gitignore
└── README.md
## 🛠 构建方式

### macOS：

```bash
brew install cmake
mkdir build && cd build
cmake ..
make
./QtTeamApp
