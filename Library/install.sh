cd build
cp -a usr /
touch /etc/ld.so.conf.d/basealttask.conf
sh -c "echo '/usr/lib64' > /etc/ld.so.conf.d/basealttask.conf"
ldconfig