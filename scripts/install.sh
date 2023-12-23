sudo apt-get install -y libx11-dev
sudo apt install -y libgl1-mesa-dev
sudo apt install -y libglu1-mesa-dev
# Install support tool
sudo apt install -y git cmake g++ curl
# Boost (1.71.0.0.ubuntu2)
sudo apt install -y libboost-all-dev
# Doxygen (1.8.17)
sudo apt install -y doxygen
# QT 5
sudo apt install -y qt5-default
sudo apt-get install -y qtdeclarative5-dev qml-module-qtquick-controls
cd ~
# Coin3D/Coin
git clone --recurse-submodules https://github.com/coin3d/coin coin
cmake -Hcoin -Bcoin_build -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=/usr/local -DCMAKE_BUILD_TYPE=Release -DCOIN_BUILD_DOCUMENTATION=OFF
sudo cmake --build coin_build --target all --config Release -- -j4
sudo cmake --build coin_build --target install --config Release -- -j4
# SoQT
git clone --recurse-submodules https://github.com/coin3d/soqt soqt
cmake -Hsoqt -Bsoqt_build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local -DCMAKE_PREFIX_PATH="/usr/local" -DSOQT_BUILD_DOCUMENTATION=OFF
sudo cmake --build soqt_build --target all --config Release -- -j4
sudo cmake --build soqt_build --target install --config Release -- -j4