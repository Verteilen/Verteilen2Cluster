#/bin/bash
cd lib
git clone https://github.com/Verteilen/Verteilen2Core.git
cd Verteilen2Core
git pull
sh build.sh
sh build.sh
sh test.sh
