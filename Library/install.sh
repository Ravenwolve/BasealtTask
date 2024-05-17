cd build
sudo cp -a usr /
sudo touch /etc/ld.so.conf.d/basealttask.conf
sudo sh -c "echo '/usr/lib64' > /etc/ld.so.conf.d/basealttask.conf"
sudo ldconfig